#include <Riostream.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "TROOT.h"
#include "TArrow.h"
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TF1.h"
#include "TPaveText.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TArrow.h"
#include "Math/DistFunc.h"

int extractSignificanceStats( TString fInName = "rootfile_1.root",  int iModel = 2 , bool unblind=false){

  gStyle->SetPalette(1);
  gStyle->SetOptStat(0);

  const float lumi7TeV=4.9 ;
  const float lumi8TeV=19.5 ;

  //char fileName[128];
  //sprintf(fileName,"qmu.root");
  TFile *fq=new TFile(fInName,"READ");
  TTree *t=(TTree*)fq->Get("q");

  float q,m,w;
  int type;
  t->SetBranchAddress("q",&q);
  t->SetBranchAddress("mh",&m);
  t->SetBranchAddress("weight",&w);
  t->SetBranchAddress("type",&type);


  TH1F *hSM=new TH1F("hSM;S = -2 #times ln(L_{Gr}/L_{SM});Number of Toys","",10000,-40,40);
  TH1F *hPS=new TH1F("hPS;S = -2 #times ln(L_{Gr}/L_{SM});Number of Toys","",10000,-40,40);
  TH1F *hObs=new TH1F("hObserved","",4000,-40,40);

  cout<<"Start to lopp on tree in file "<<fInName<<endl;

  std::vector<float> v_SM, v_PS,v_Obs;

  for(int i=0;i<t->GetEntries();i++){
    t->GetEntry(i);

    if(i==0)cout<<"MASS in the TREE = "<<m<<endl<<endl;

    q*=2.0;
    if(type<0){ //SM hypothesis 
      hSM->Fill(-q);
      v_SM.push_back(-q);
    }
    else if(type>0){//ALT hypothesis
      hPS->Fill(-q);
      v_PS.push_back(-q);
    }
    else{
      hObs->Fill(-q);
      v_Obs.push_back(-q);
    }
  }//end loop on tree entries
  cout<<"Finished to loop, sorting vectors "<<v_SM.size()<<" "<<v_PS.size()<<" "<<v_Obs.size()<<endl;
  sort(v_SM.begin(),v_SM.end());//sort in ascending order
  sort(v_PS.begin(),v_PS.end()); 
  sort(v_Obs.begin(),v_Obs.end());
  int ntoysSM= hSM->GetEntries();
  int ntoysPS= hPS->GetEntries();

  //we assume that SM is on the right and PS on the left of zero
  if(v_PS.at(0)>v_SM.at(ntoysSM-1)){
    cout<<"Swapped distributions !!! The alternative model shouldstay on the negative side of the significance."<<endl;
    cout<<"Please edit the code and change the sign of q when filling histos and vectors in the loop on tree entries"<<endl;
    return 1;
  }

  if((int(v_SM.size())!= ntoysSM)||(int(v_PS.size())!= ntoysPS)){
    cout<<"Mismatch in size of vectors and #entries of historgams ! v_SM.size()="<< v_SM.size() <<"  ntoysSM="<<ntoysSM<<endl;
    return 1;
  }

  float medianSM=v_SM.at(int(ntoysSM/2));
  float qSM68p=v_SM.at(floor(ntoysSM * 0.5*(1-0.68)+0.5));
  float qSM95p=v_SM.at(floor(ntoysSM * 0.5*(1-0.95)+0.5));
  float qSM68m=v_SM.at(std::min(int(floor(ntoysSM * 0.5*(1+0.68)+0.5)), ntoysSM-1));
  float qSM95m=v_SM.at(std::min(int(floor(ntoysSM * 0.5*(1+0.95)+0.5)), ntoysSM-1));

  float medianPS=v_PS.at(int(ntoysPS/2));
  float qPS68p=v_PS.at(floor(ntoysPS * 0.5*(1-0.68)+0.5));
  float qPS95p=v_PS.at(floor(ntoysPS * 0.5*(1-0.95)+0.5));
  float qPS68m=v_PS.at(std::min(int(floor(ntoysPS * 0.5*(1+0.68)+0.5)), ntoysPS-1));
  float qPS95m=v_PS.at(std::min(int(floor(ntoysPS * 0.5*(1+0.95)+0.5)), ntoysPS-1));  

  cout<<"Toys generated "<<ntoysSM<<"\t"<<ntoysPS<<endl;
  cout<<"Mean of SM/Gr hypothesis: "<<hSM->GetMean()<<"\t"<<hPS->GetMean()<<endl;
  cout<<"RMS  of SM/Gr hypothesis: "<<hSM->GetRMS()<<"\t"<<hPS->GetRMS()<<endl;
  cout<<"Median of SM/Gr hypothesis: "<<medianSM<<"\t"<<medianPS<<endl;

  const float step=0.05;
  float coverage=0.0;
  float diff=10.0;
  float cut=v_PS.at(0)-step;
  float crosspoint=-99.0;
  int startSM=ntoysSM-1, startPS=0;
  cout<<"Starting to loop with cut at "<<cut<<endl;

  //apply a cut on the vectors with the results of toys,
  //for each cut check the area in the tail for PS and SM
  //and calculate the difference.
  //Find the value of cut that minimizes the difference.
 

  while(cut<=v_SM.at(ntoysSM-1)+step){
    //    if(int(cut*100)%100==0)
    // cout<<"Cutting at "<<cut<<endl;
    float cutSM=-1.0,cutPS=-1.0;

    for(int iSM=startSM;iSM>=0;iSM--){      
      //entries in v_SM and v_PS are sorted
      if(v_SM.at(iSM)<cut){//gotcha
	cutSM=ntoysSM-iSM;
	break;
      }
      //      //      else cout<<"SM "<<v_SM.at(iSM)<<" > "<<cut<<endl;
    }

    for(int iPS=startPS;iPS<ntoysPS;iPS++){
      if(v_PS.at(iPS)>cut){//gotcha
	cutPS=iPS;
	break;
      }
      ////      else cout<<v_PS.at(iPS)<<" < "<<cut<<endl;
  
    }

    if(cutSM>=0&&cutPS>=0){
      float fracSM=(ntoysSM-cutSM)/ntoysSM;
      float fracPS=(ntoysPS-cutPS)/ntoysPS;
      // //   cout<<"FracSM: "<<fracSM<<"   FracPS: "<<fracPS<<endl;
      if(fabs(fracSM-fracPS)<diff){
	diff=fabs(fracSM-fracPS);
	coverage=fabs(fracSM+fracPS)/2.0;
	crosspoint=cut;
	//cout<<"New coverage="<<coverage<<" at xpoint="<<crosspoint<<" with diff "<<diff<<"  FracSM="<<fracSM<<"  FracPS="<<fracPS<<endl;
      }
      ////      else cout<<"Diff is too high: "<<fabs(fracSM-fracPS)<<"   fracSM="<<fracSM<<"  fracPS="<<fracPS<<endl;
    }//end if both cuutSM and cutPS are >=0
    //// else cout<<"For cut="<<cut <<" Negative cutSM/cutPS: "<<cutSM<<"  "<<cutPS<<endl;

    cut+=step;
  }//end while loop
 
  cout<<"Finished loop on vector elements, min diff is "<<diff<<", looped until cut_fin="<<cut<<endl;
  cout<<"q value where SM and ALT distributions have same area on opposite sides: "<<crosspoint<<"  Coverage="<<coverage<<endl;
  float separation=2*ROOT::Math::normal_quantile_c(1.0 - coverage, 1.0);
  cout<<"Separation from tail prob: "<<separation<<endl<<endl<<endl;
  

  float integralSM=hSM->Integral();
  float integralPS=hPS->Integral();
 
  float tailSM=hSM->Integral(1,hSM->FindBin(medianPS))/integralSM;
  float tailPS=hPS->Integral(hPS->FindBin(medianSM),hPS->GetNbinsX())/integralPS;
  float sigExpSM    = ROOT::Math::normal_quantile_c(tailSM,1.0);
  float sigExpALT   = ROOT::Math::normal_quantile_c(tailPS,1.0);
  cout<<"Median point prob SM: "<<tailSM<<"  ("<<ROOT::Math::normal_quantile_c(tailSM,1.0) <<" sigma)"<<endl;
  cout<<"Median point prob Gr: "<<tailPS<<"  ("<<ROOT::Math::normal_quantile_c(tailPS,1.0) <<" sigma)"<<endl;

  diff=10.0;
  coverage=0.0;
  for(int i=1;i<hSM->GetNbinsX();i++){
    
    float fracSM=hSM->Integral(1,i) / integralSM;
    float fracPS=hPS->Integral(i,hPS->GetNbinsX()) / integralPS;
    if(fabs(fracSM-fracPS)<diff){
      diff=fabs(fracSM-fracPS);
      coverage=(fracSM+fracPS)/2.0;
    }

  }

  float sepH= 2*ROOT::Math::normal_quantile_c(1.0 - coverage, 1.0);
  cout<<"Separation from histograms = "<<sepH<<" with coverage "<<coverage<<endl;

  float qObs        = 99.;
  float obsCLsRatio = 99.;
  float sigObsSM    = 99.;
  float sigObsALT   = 99.;

  if(unblind){
    //if(v_Obs.size()!=1){
      //cout<<"Ooops ! The size of the vector with the observed separation is not 1 but "<<v_Obs.size()<<" ! I am not going to plot the observed results."<<endl;
      //unblind=false;
    //}
    //else{
      qObs = v_Obs.at(0);
      float obsTailSM=hSM->Integral(1,hSM->FindBin(v_Obs.at(0)))/integralSM;
      float obsTailPS=hPS->Integral(hPS->FindBin(v_Obs.at(0)),hPS->GetNbinsX())/integralPS;
      sigObsSM  = ROOT::Math::normal_quantile_c(obsTailSM,1.0);
      sigObsALT = ROOT::Math::normal_quantile_c(obsTailPS,1.0);
      cout<<"P(SM < Obs): "<<obsTailSM<<"  ("<<ROOT::Math::normal_quantile_c(obsTailSM,1.0) <<" sigma)"<<endl;
      cout<<"P(Gr > Obs): "<<obsTailPS<<"  ("<<ROOT::Math::normal_quantile_c(obsTailPS,1.0) <<" sigma)"<<endl;

      obsCLsRatio = obsTailPS / (1.0 - obsTailSM);
      cout<<"CLs criterion P(Gr > Obs) / P(Gr > Obs) : "<<obsCLsRatio<<"  ("<<ROOT::Math::normal_quantile_c(obsCLsRatio,1.0) <<" sigma)"<<endl;
    //}
  

    /*
    cout << "\n\nOBSERVED SIGNIFICANCE" << endl;
    cout << "observation: " << v_Obs[0] << endl;
    cout << "bin: " << hObs->GetMaximumBin() << endl;
    cout << " --------------- " << endl;
    double obsPval_SM = 1-hSM->Integral(0,hObs->GetMaximumBin())/integralSM;
    cout << "pvalue SM: " << obsPval_SM << endl;
    cout << "signif SM: " << ROOT::Math::normal_quantile_c(obsPval_SM,1.0) << endl;
    double obsPval_PS =  hPS->Integral(0,hObs->GetMaximumBin())/integralPS;
    cout << "pvalue PS: " << obsPval_PS << endl;
    cout << "signif PS: " << ROOT::Math::normal_quantile_c(obsPval_PS,1.0) << endl<<endl<<endl;
    */

  }//end if unblinding

  // COUT ALL VALUES

  cout << "               "
       << setw(11) << "sObsSM"
       << setw(11) << "sExpSM"
       << setw(11) << "sObsALT"
       << setw(11) << "sExpALT"
       << setw(11) << "CLsRatio"
       << setw(11) << "qObs"
       << setw(11) << "MeanSM"
       << setw(11) << "medianSM"
       << setw(11) << "qSM68m"
       << setw(11) << "qSM68p"
       << setw(11) << "qSM95m"
       << setw(11) << "qSM95p"
       << setw(11) << "MeanALT"
       << setw(11) << "medianALT"
       << setw(11) << "qALT68m"
       << setw(11) << "qALT68p"
       << setw(11) << "qALT95m"
       << setw(11) << "qALT115p"
       << endl;

  cout << "RESULTS_SUMMARY"
       << setprecision(3)
       << setw(11) << sigObsSM
       << setw(11) << sigExpSM
       << setw(11) << sigObsALT
       << setw(11) << sigExpALT
       << setw(11) << obsCLsRatio
       << setw(11) << qObs 
       << setw(11) << hSM->GetMean()
       << setw(11) << medianSM
       << setw(11) << qSM68p
       << setw(11) << qSM68m
       << setw(11) << qSM95p
       << setw(11) << qSM95m
       << setw(11) << hPS->GetMean()
       << setw(11) << medianPS
       << setw(11) << qPS68p
       << setw(11) << qPS68m
       << setw(11) << qPS95p
       << setw(11) << qPS95m
       << endl ; 



  //Plotting
  //gROOT->SetStyle("plain");
  gROOT->ForceStyle();
  gStyle->SetOptStat(0);
  gStyle->SetCanvasColor(0);
  gStyle->SetTitleOffset(2.0,"X");
  gStyle->SetTitleOffset(2.5,"Y");
  gStyle->SetPadLeftMargin(0.20);
  gStyle->SetPadBottomMargin(0.15);
  TCanvas *c1=new TCanvas("c1","c1",500,500);
  c1->cd();
  gPad->SetLeftMargin(0.18);
  hSM->Rebin(50);
  hPS->Rebin(50);
  float maxhSM=hSM->GetBinContent(hSM->GetMaximumBin());
  float maxhPS=hPS->GetBinContent(hPS->GetMaximumBin());
  if(maxhPS>maxhSM){
    hSM->SetMaximum(maxhPS*1.15);
    hPS->SetMaximum(maxhPS*1.15);
  }
  else{
    hSM->SetMaximum(maxhSM*1.15);
    hPS->SetMaximum(maxhSM*1.15);
  }
  hSM->SetYTitle("Generated experiments");
  hPS->SetYTitle("Generated experiments");
  if ( iModel == 1 ) {
    hPS->SetXTitle(" -2 ln(L_{0-}/L_{0+})");
    hSM->SetXTitle(" -2 ln(L_{0-}/L_{0+})");
  } else { 
    hPS->SetXTitle(" -2 ln(L_{2+,h}/L_{0+})");
    hSM->SetXTitle(" -2 ln(L_{2+,h}/L_{0+})");
  }
  hSM->SetLineColor(kMagenta-3);
  hSM->SetFillColor(kMagenta-3);
  hSM->SetLineWidth(2);
  hSM->SetFillStyle(3605);
  hPS->SetLineColor(kBlue+1);
  hPS->SetFillColor(kBlue+1);
  hPS->SetLineWidth(2);
  hPS->SetFillStyle(3695);

  hObs->SetLineColor(kGreen+3);
  hObs->SetLineWidth(5);

  TGraph *grObs=new TGraph();//dummy, just for the legend
  grObs->SetLineColor(kGreen+3);
  grObs->SetLineWidth(5);

  hSM->GetXaxis()->SetLabelFont (   42);
  hSM->GetYaxis()->SetLabelFont (   42);
  hSM->GetXaxis()->SetTitleFont (   42);
  hSM->GetYaxis()->SetTitleFont (   42);
  hSM->GetXaxis()->SetTitleSize (0.050);
  hSM->GetYaxis()->SetTitleSize (0.050);
  hSM->GetXaxis()->SetLabelSize (0.045);
  hSM->GetYaxis()->SetLabelSize (0.055);
  hSM->GetXaxis()->SetLabelOffset(0.02); 
 
  hSM->GetXaxis()->SetTitleOffset(1.3);
  hSM->GetYaxis()->SetTitleOffset(1.9);
  hSM->GetXaxis()->SetRangeUser(-30.0,30.0);
  hPS->GetXaxis()->SetRangeUser(-30.0,30.0);

  

  hSM->Draw();
  hPS->Draw("sames");
  gPad->SetLogy(); 

  TArrow *obsArrow=0;
  if(unblind)obsArrow=new TArrow(v_Obs.at(0),hSM->GetMaximum()/5.0,v_Obs.at(0),0.0,0.05,"|->");
  else obsArrow=new TArrow(0.0,hSM->GetMaximum()/5.0,0.0,0.0,0.05,"|->");
  obsArrow->SetLineColor(kGreen+3);
  obsArrow->SetLineWidth(5.0);
  if(unblind)  obsArrow->Draw();

  TLegend *leg = new TLegend(0.20,0.7,0.35,0.85);
  leg->SetFillColor(0);
  //  leg->SetTextFont(42);
  leg->SetTextSize(0.035);
  leg->SetBorderSize(0);
  leg->AddEntry(hSM, "   SM, 0+","f");
  if ( iModel == 1 ) {
    leg->AddEntry(hPS, "   0-","f");
  } else {
    leg->AddEntry(hPS, "   2+,min","f");
  }
  if(unblind) leg->AddEntry(hObs,"  CMS data","L");
  //  if(unblind) leg->AddEntry(hObs,"  Simulated data","L");
  leg->Draw();


  TPaveText pt(0.18,0.88,0.40,0.99,"NDC");
  pt.SetFillColor(0);
  pt.SetFillStyle(0);
  pt.SetTextAlign(12);
  pt.SetTextSize(0.035);
  pt.SetTextFont(42);
  //pt.AddText("CMS Preliminary");
  pt.AddText("#bf{CMS}");
  pt.SetBorderSize(0);
  TPaveText pt2(0.53,0.88,0.90,0.99,"NDC");
  pt2.SetFillColor(0);
  pt2.SetFillStyle(0);
  pt2.SetTextAlign(32);
  pt2.SetTextSize(0.035);
  pt2.SetTextFont(42);
  pt2.AddText("4.9 fb^{-1} (7 TeV) + 19.4 fb^{-1} (8 TeV)");
  //pt2.AddText(Form(" #sqrt{s} = 7 TeV, L = %.1f fb^{-1}; #sqrt{s} = 8 TeV, L = %.1f fb^{-1}",lumi7TeV,lumi8TeV));
  //pt2.AddText(Form("#sqrt{s} = 7 TeV, L = %.1f fb^{-1}",lumi7TeV));
  //pt2.AddText(Form("#sqrt{s} = 8 TeV, L = %.1f fb^{-1}",lumi8TeV));
  pt2.SetBorderSize(0);
  pt.Draw();
  pt2.Draw();
  c1->SaveAs("sigsep_combine.eps");
  c1->SaveAs("sigsep_combine.pdf");
  c1->SaveAs("sigsep_combine.png");
  c1->SaveAs("sigsep_combine.root");

  return 0;
}//end main
