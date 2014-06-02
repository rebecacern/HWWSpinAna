 
#include "setTDRStyle.C"
 
void compareplot(int nsel = 1, int cem = 8){
  
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetErrorX(0);
  
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  gROOT->SetBatch(1);
    
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetCanvasDefH(600);
  gStyle->SetCanvasDefW(600);
  gStyle->SetLabelFont(18,"");
  
  char plotName[300];
  sprintf(plotName,"test");
  
  if (nsel == 0) {sprintf(plotName,"SM");}
  else if (nsel == 1) {sprintf(plotName,"0PM");}
  else if (nsel == 2) {sprintf(plotName,"0M");}
  else if (nsel == 3) {sprintf(plotName,"Mixfa3");}
  else if (nsel == 4) {sprintf(plotName,"0PH");}
  else if (nsel == 5) {sprintf(plotName,"Mixfa2");}
  else if (nsel == 6) {sprintf(plotName,"Mixfa2fa3");}
  else if (nsel == 7) {sprintf(plotName,"L1");}
  else if (nsel == 8) {sprintf(plotName,"MixL1");}
  else if (nsel == 9) {sprintf(plotName,"Old");}
  else if (nsel == 10) {sprintf(plotName,"2BP");}
  else if (nsel == 11) {sprintf(plotName,"2HP");}
  else if (nsel == 12) {sprintf(plotName,"2HM");}
  else if (nsel == 13) {sprintf(plotName,"2PM");}
  else if (nsel == 14) {sprintf(plotName,"2PH2");}
  else if (nsel == 15) {sprintf(plotName,"2PH6");}
  else if (nsel == 16) {sprintf(plotName,"2MH9");}
  else if (nsel == 17) {sprintf(plotName,"2MH10");}
  else if (nsel == 18) {sprintf(plotName,"2PH3");}
  else if (nsel == 19) {sprintf(plotName,"2PH7");}
  else if (nsel == 20) {sprintf(plotName,"1P");}
  else if (nsel == 21) {sprintf(plotName,"1M");}

  	
  TString properLabel[22] ={"SM 0^{+}_{m} Official", "0^{+}_{m}", "0^{-}", "f_{a3} = 0.5","0^{+}_{h}", "f_{a2} = 0.5",
  				"fa_{a3} = f_{a2}=0.5", "0_{#Lambda1}", "f_{#Lambda1}=0.5", "Old JHU", "2^{+}_{b}", "2^{+}_{h}",
				"2^{-}_{h}", "2^{+}_{min}", "2^{+}_{h2}", "2^{+}_{h6}", "2^{-}_{h9}", "2^{-}_{h10}",
				"2^{+}_{h3}", "2^{+}_{h7}", "1^{+}", "1^{-}"};
  
  TString sampleLabel[22] = { "SM", "0PM", "0M", "Mixfa3","0PH", "Mixfa2", "Mixfa2fa3", "L1", "MixL1", "Old", "2BP", "2HP",
  			"2HM", "2PM", "2PH2","2PH6", "2MH9","2MH10", "2PH3", "2PH7", "1P", "1M"};
  
  char myRootFile[300];
  sprintf(myRootFile,"rootfiles/test.root");
  
  TFile *_file0 = TFile::Open(myRootFile);
 
 

  const int nPlots = 9;
  TString cutLabel[nPlots] = { "lep1pt", "lep2pt", "lep1eta", "lep2eta", "mll", "mt", "ptll", "met", "phill"};
  TString cutTitle[nPlots] = { "lepton 1, p_{T}[GeV]", "lepton 2, p_{T}[GeV]", "lepton 1, #eta", "lepton 2, #eta", "m_{ll} [GeV]", "m_{T} [GeV]", "p_{T} (ll)[GeV]", "MET [GeV]", "#Delta#Phi_{ll} [Deg.]"}; 
 

  TH1D*  h0[2][nPlots];
  TH1D*  h1[2][nPlots];
  TH1D*  h2[2][nPlots];
  
  for (const int iPlot = 0; iPlot < nPlots; iPlot++){
    cout << cutLabel[iPlot] << endl;
    h0[0][iPlot] = (TH1D*) _file0->Get("histo_before_" + cutLabel[iPlot]+"_"+sampleLabel[1]+"_8TeV");
    h0[1][iPlot] = (TH1D*) _file0->Get("histo_before_" + cutLabel[iPlot]+"_"+sampleLabel[nsel]+"_8TeV");

          
    h1[0][iPlot] = (TH1D*) _file0->Get("histo_" + cutLabel[iPlot]+"_"+sampleLabel[1]+"_8TeV");
    h1[1][iPlot] = (TH1D*) _file0->Get("histo_" + cutLabel[iPlot]+"_"+sampleLabel[nsel]+"_8TeV");
  

     
        
    TCanvas *c1 = new TCanvas();
    h0[0][iPlot]->SetLineColor(kRed);
    h0[0][iPlot]->SetMarkerColor(kRed);
    h0[0][iPlot]->SetMarkerStyle(20);
    h0[0][iPlot]->SetMarkerSize(1);
    h0[1][iPlot]->SetMarkerStyle(20);
    h0[1][iPlot]->SetMarkerSize(1);
    h0[0][iPlot]->SetNormFactor(1);
    h0[1][iPlot]->SetNormFactor(1);
    double max = 1.3*(TMath::Max(h0[0][iPlot]->GetMaximum(), h0[1][iPlot]->GetMaximum()));
    h0[0][iPlot]->Draw("ehisto");
    h0[1][iPlot]->Draw("ehisto, sames");

    h0[0][iPlot]->GetYaxis()->SetRangeUser(0.01, max);
    h0[0][iPlot]->GetXaxis()->SetTitle(cutTitle[iPlot]);
    leg = new TLegend(0.60,0.80,0.99,0.99);
    leg->SetFillStyle(1001);
    leg->SetFillColor(kWhite);
    leg->SetBorderSize(1);
    leg->AddEntry(h0[0][iPlot],  properLabel[1], "l");
    leg->AddEntry(h0[1][iPlot],  properLabel[nsel], "l");
  
    leg->Draw();
    c1->SaveAs("plots/before_"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV.png");
    c1->SaveAs("plots/before_"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV.pdf");
    gPad->SetLogy();
//    c1->SetLogy();
    c1->SaveAs("plots/before_"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV_log.png");
    c1->SaveAs("plots/before_"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV_log.pdf");
       
    TCanvas *c1 = new TCanvas();
    h1[0][iPlot]->SetLineColor(kRed);
    h1[0][iPlot]->SetMarkerColor(kRed);
    h1[0][iPlot]->SetMarkerStyle(20);
    h1[0][iPlot]->SetMarkerSize(1);
    h1[1][iPlot]->SetMarkerStyle(20);
    h1[1][iPlot]->SetMarkerSize(1);
    h1[0][iPlot]->SetNormFactor(1);
    h1[1][iPlot]->SetNormFactor(1);
    double max = 1.3*(TMath::Max(h1[0][iPlot]->GetMaximum(), h1[1][iPlot]->GetMaximum()));
    h1[0][iPlot]->Draw("ehisto");
    h1[1][iPlot]->Draw("ehisto, sames");

    h1[0][iPlot]->GetYaxis()->SetRangeUser(0.01, max);
    h1[0][iPlot]->GetXaxis()->SetTitle(cutTitle[iPlot]);
    leg = new TLegend(0.60,0.80,0.99,0.99);
    leg->SetFillStyle(1001);
    leg->SetFillColor(kWhite);
    leg->SetBorderSize(1);
    leg->AddEntry(h1[0][iPlot],  properLabel[1], "l");
    leg->AddEntry(h1[1][iPlot],  properLabel[nsel], "l");
  
    leg->Draw();
    c1->SaveAs("plots/"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV.png");
    c1->SaveAs("plots/"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV.pdf");
    gPad->SetLogy();
//    c1->SetLogy();
    c1->SaveAs("plots/"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV_log.png");
    c1->SaveAs("plots/"+ cutLabel[iPlot]+ "_"+ sampleLabel[nsel] + "_8TeV_log.pdf");
   
  }


  
}
