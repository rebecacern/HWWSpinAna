#include "../../Smurf/Core/SmurfTree.h"
#include "TH2D.h"
#include "TH1D.h"
#include "inputs.h"


void chain(int nsel = 0, int cem = 8){
  
  int jetbin =0;
   
  char plotName[300], Message[300], jetName[300], folderName[300];
  sprintf(plotName,"test");
  sprintf(Message,"test");
  sprintf(jetName,"0jets");
  if (jetbin == 1) sprintf(jetName,"1jets");
  
  sprintf(folderName,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva");
  
  if (nsel == 0) {sprintf(plotName,"SM"); sprintf(Message,"Standard Model 125GeV official legacy sample");}
  else if (nsel == 1) {sprintf(plotName,"0PM"); sprintf(Message,"Standard Model JHU Gen");}
  else if (nsel == 2) {sprintf(plotName,"0M"); sprintf(Message,"Pseudoscalar JHU Gen");}
  else if (nsel == 3) {sprintf(plotName,"Mixfa3"); sprintf(Message,"Mix fa3");}
  else if (nsel == 4) {sprintf(plotName,"0PH"); sprintf(Message,"Scalar with Higher order corrections");}
  else if (nsel == 5) {sprintf(plotName,"Mixfa2"); sprintf(Message,"Mix fa2");}
  else if (nsel == 6) {sprintf(plotName,"Mixfa2fa3"); sprintf(Message,"Mix fa2, fa3");}
  else if (nsel == 7) {sprintf(plotName,"L1"); sprintf(Message,"Lambda 1");}
  else if (nsel == 8) {sprintf(plotName,"MixL1"); sprintf(Message,"Lambda 1 Mix");}
  else if (nsel == 9) {sprintf(plotName,"Old"); sprintf(Message,"Standard Model 125GeV JHU Gen old sample");}
  else if (nsel == 10) {sprintf(plotName,"2BP"); sprintf(Message,"2+b");}
  else if (nsel == 11) {sprintf(plotName,"2HP"); sprintf(Message,"tensor with higher dimension operators");}
  else if (nsel == 12) {sprintf(plotName,"2HM"); sprintf(Message,"pseudo-tensor");}
  else if (nsel == 13) {sprintf(plotName,"2PM"); sprintf(Message,"2+min");}
  else if (nsel == 14) {sprintf(plotName,"2PH2"); sprintf(Message,"2+h2");}
  else if (nsel == 15) {sprintf(plotName,"2PH6"); sprintf(Message,"2+h6");}
  else if (nsel == 16) {sprintf(plotName,"2MH9"); sprintf(Message,"2-h9");}
  else if (nsel == 17) {sprintf(plotName,"2MH10"); sprintf(Message,"2-h10");}
  else if (nsel == 18) {sprintf(plotName,"2PH3"); sprintf(Message,"2+h3");}
  else if (nsel == 19) {sprintf(plotName,"2PH7"); sprintf(Message,"2+h7");}
  else if (nsel == 20) {sprintf(plotName,"1P"); sprintf(Message,"1+");}
  else if (nsel == 21) {sprintf(plotName,"1M"); sprintf(Message,"1-");}
  else if (nsel == 22) {sprintf(plotName, "0PM_VBF"); sprintf(Message, "SM, VBF");}
  else if (nsel == 23) {sprintf(plotName, "0PM_WH"); sprintf(Message, "SM, WH");}
  else if (nsel == 24) {sprintf(plotName, "0PM_ZH"); sprintf(Message, "SM, ZH");}
  else if (nsel == 25) {sprintf(plotName, "0PM_TTH"); sprintf(Message, "SM, ttH");}
  else if (nsel == 26) {sprintf(plotName, "0M_VBF"); sprintf(Message, "0M, VBF");}
  else if (nsel == 27) {sprintf(plotName, "0M_WH"); sprintf(Message, "0M, WH");}
  else if (nsel == 28) {sprintf(plotName, "0M_ZH"); sprintf(Message, "0M, ZH");}
  else if (nsel == 29) {sprintf(plotName, "0M_TTH"); sprintf(Message, "0M, ttH");}
  else if (nsel == 30) {sprintf(plotName, "0PH_VBF"); sprintf(Message, "0PH, VBF");}
  else if (nsel == 31) {sprintf(plotName, "0PH_WH"); sprintf(Message, "0PH, WH");}
  else if (nsel == 32) {sprintf(plotName, "0PH_ZH"); sprintf(Message, "0PH, ZH");}
  else if (nsel == 33) {sprintf(plotName, "0PH_TTH"); sprintf(Message, "0PH, ttH");}

  
  char myRootFile[300];
  double lumi = lumi8;
  if (cem == 8){
    if (nsel == 0) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_hww125.root", folderName,jetName);
    else if (nsel == 1) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0pm-v19.root", folderName,jetName);
    else if (nsel == 2) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0mt-v19.root", folderName, jetName);
    else if (nsel == 3) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0mf05ph0-v19.root", folderName, jetName);
    else if (nsel == 4) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0ph-v19.root", folderName, jetName);
    else if (nsel == 5) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0phf05ph0-v19.root", folderName, jetName); 
    else if (nsel == 6) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0phf05-v19.root", folderName, jetName); 
    else if (nsel == 7) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0l1-v19.root", folderName, jetName); 
    else if (nsel == 8) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0l1f05ph180-v19.root", folderName, jetName); 
    else if (nsel == 9) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww0p125.root", folderName, jetName);
    else if (nsel == 10) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2bp-v19.root", folderName, jetName); 
    else if (nsel == 11) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2hp-v19.root", folderName, jetName); 
    else if (nsel == 12) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2hm-v19.root", folderName, jetName); 
    else if (nsel == 13) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww2p125.root", folderName, jetName);
    else if (nsel == 14) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2ph2-v19.root", folderName, jetName); 
    else if (nsel == 15) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2ph6-v19.root", folderName, jetName); 
    else if (nsel == 16) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2mh9-v19.root", folderName, jetName); 
    else if (nsel == 17) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2mh10-v19.root", folderName, jetName); 
    else if (nsel == 18) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2ph3-v19.root", folderName, jetName); 
    else if (nsel == 19) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-g125ww4l-2ph7-v19.root", folderName, jetName); 
    else if (nsel == 20) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-v125ww4l-1p-v19.root", folderName, jetName); 
    else if (nsel == 21) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-v125ww4l-1m-v19.root", folderName, jetName); 
    else if (nsel == 22 || nsel == 23 || nsel == 24 || nsel ==25) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_0jets_xww125p6_s12-0p.root", folderName);
    else if (nsel == 26 || nsel == 27 || nsel == 28 || nsel ==29) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_0jets_xww125p6_s12-0m.root", folderName);
    else if (nsel == 30 || nsel == 31 || nsel == 32 || nsel ==33) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_0jets_xww125p6_s12-0ph.root", folderName);
    
 } else {
    lumi = lumi7;
    cout << endl;
    cout << "PLEASE UPDATE THE TUPLES" << endl;
    cout << endl;
   
  }
  
  //Load datasets
  
  SmurfTree sample;
  cout << myRootFile << endl;
  cout << "You are running " << Message << endl;
  sample.LoadTree(myRootFile,-1);
  sample.InitTree(0);
  
  char rootFile[300];
  sprintf(rootFile,"rootfiles/test.root");
  
  TFile f_root(rootFile, "UPDATE");
  
  // Prepare histograms
  char title[300];
  
  sprintf(title,"histo_%s_%dTeV",plotName, cem);
  TH2F* histo = new TH2F( title, " ", 6, 60, 120, 6, 12, 100);
  histo->Sumw2();
  
  //Template!  
  sprintf(title,"template_%s_%dTeV",plotName, cem);
  TH1F* histo_template = new TH1F( title, " ",126, -1, 1);
  histo_template->Sumw2();
  
  //distributions  
  sprintf(title,"histo_before_lep1pt_%s_%dTeV",plotName, cem);
  TH1F* histo_before_lep1pt = new TH1F( title, " ", 10, 0, 100);
  histo_before_lep1pt->Sumw2();
  
  sprintf(title,"histo_before_lep2pt_%s_%dTeV",plotName, cem);
  TH1F* histo_before_lep2pt = new TH1F( title, " ", 10, 0, 100);
  histo_before_lep2pt->Sumw2();
  
  sprintf(title,"histo_before_lep1eta_%s_%dTeV",plotName, cem);
  TH1F* histo_before_lep1eta = new TH1F( title, " ", 10, -2.5, 2.5);
  histo_before_lep1eta->Sumw2();
  
  sprintf(title,"histo_before_lep2eta_%s_%dTeV",plotName, cem);
  TH1F* histo_before_lep2eta = new TH1F( title, " ", 10, -2.5, 2.5);
  histo_before_lep2eta->Sumw2();
  
  sprintf(title,"histo_before_mll_%s_%dTeV",plotName, cem);
  TH1F* histo_before_mll = new TH1F( title, " ", 10, 0, 200);
  histo_before_mll->Sumw2();
  
  sprintf(title,"histo_before_mt_%s_%dTeV",plotName, cem);
  TH1F* histo_before_mt = new TH1F( title, " ", 15, 0, 300);
  histo_before_mt->Sumw2();
  
  sprintf(title,"histo_before_ptll_%s_%dTeV",plotName, cem);
  TH1F* histo_before_ptll = new TH1F( title, " ", 10, 0, 100);
  histo_before_ptll->Sumw2();
  
  sprintf(title,"histo_before_met_%s_%dTeV",plotName, cem);
  TH1F* histo_before_met = new TH1F( title, " ", 10, 0, 100);
  histo_before_met->Sumw2();
  
  sprintf(title,"histo_before_phill_%s_%dTeV",plotName, cem);
  TH1F* histo_before_phill = new TH1F( title, " ", 10, 0, 180);
  histo_before_phill->Sumw2();
  
  sprintf(title,"histo_lep1pt_%s_%dTeV",plotName, cem);
  TH1F* histo_lep1pt = new TH1F( title, " ", 10, 0, 100);
  histo_lep1pt->Sumw2();
  
  sprintf(title,"histo_lep2pt_%s_%dTeV",plotName, cem);
  TH1F* histo_lep2pt = new TH1F( title, " ", 10, 0, 100);
  histo_lep2pt->Sumw2();
  
  sprintf(title,"histo_lep1eta_%s_%dTeV",plotName, cem);
  TH1F* histo_lep1eta = new TH1F( title, " ", 10, -2.5, 2.5);
  histo_lep1eta->Sumw2();
  
  sprintf(title,"histo_lep2eta_%s_%dTeV",plotName, cem);
  TH1F* histo_lep2eta = new TH1F( title, " ", 10, -2.5, 2.5);
  histo_lep2eta->Sumw2();
  
  sprintf(title,"histo_mll_%s_%dTeV",plotName, cem);
  TH1F* histo_mll = new TH1F( title, " ", 10, 0, 200);
  histo_mll->Sumw2();
  
  sprintf(title,"histo_mt_%s_%dTeV",plotName, cem);
  TH1F* histo_mt = new TH1F( title, " ", 15, 0, 300);
  histo_mt->Sumw2();
  
  sprintf(title,"histo_ptll_%s_%dTeV",plotName, cem);
  TH1F* histo_ptll = new TH1F( title, " ", 10, 0, 100);
  histo_ptll->Sumw2();
  
  sprintf(title,"histo_met_%s_%dTeV",plotName, cem);
  TH1F* histo_met = new TH1F( title, " ", 10, 0, 100);
  histo_met->Sumw2();
  
  sprintf(title,"histo_phill_%s_%dTeV",plotName, cem);
  TH1F* histo_phill = new TH1F( title, " ", 10, 0, 180);
  histo_phill->Sumw2();
  //To business
  int nSample=sample.tree_->GetEntries();
  
  cout << nSample << endl;
  int events = 0;
  double events_norm = 0;
  for (int i=0; i<nSample; ++i) {
    //   for (int i=0; i<10; ++i) {
    sample.tree_->GetEntry(i); 
  
    if(sample.processId_ != 10010 && (nsel < 20)) continue;
    if (sample.processId_ != 10001 && (nsel == 22 || nsel == 26 || nsel == 30)) continue;
    if (sample.processId_ != 26 && (nsel == 23 || nsel == 27 || nsel == 31)) continue;
    if (sample.processId_ != 24 && (nsel == 24 || nsel == 28 || nsel == 32)) continue;
    if ((sample.processId_ != 121 || sample.processId_ !=122) && (nsel == 25 || nsel == 29 || nsel == 33)) continue;
    if ((fabs(sample.lep1McId_) == fabs(sample.lep2McId_))) continue;
    if (sample.type_ != 1 && sample.type_ != 2 ) continue;
    if ((sample.cuts_ & SmurfTree::Lep1FullSelection) != SmurfTree::Lep1FullSelection || 
    (sample.cuts_ & SmurfTree::Lep2FullSelection) != SmurfTree::Lep2FullSelection) continue;  
    events++;
    
    double weight = 1;
    double factor = 1;
    if (nsel == 0) factor = 1.028;
    if (sample.dstype_ != SmurfTree::data) weight = lumi*sample.scale1fb_*sample.sfWeightPU_*sample.sfWeightEff_*sample.sfWeightTrig_*factor;
    
    histo_before_lep1pt->Fill(sample.lep1_.Pt(), weight);
    histo_before_lep2pt->Fill(sample.lep2_.Pt(), weight);
    histo_before_lep1eta->Fill(sample.lep1_.Eta(), weight);
    histo_before_lep2eta->Fill(sample.lep2_.Eta(), weight);
    histo_before_mll->Fill(sample.dilep_.M(), weight);
    histo_before_mt->Fill(sample.mt_, weight);
    histo_before_ptll->Fill(sample.dilep_.Pt(), weight);
    histo_before_met->Fill(sample.met_, weight);
    histo_before_phill->Fill(fabs(sample.dPhi_*180/3.1415), weight);
    
    //HWW slection mock-off
    int nJetsType = 0;
    if (sample.dilep_.M() <= 12 || sample.dilep_.M() >= 200) continue;
    if ((sample.cuts_ & SmurfTree::ExtraLeptonVeto) != SmurfTree::ExtraLeptonVeto) continue;
    if (sample.lq1_*sample.lq2_ > 0) continue;
    if (sample.njets_ != nJetsType) continue; 
    if (sample.lep1_.Pt() <= 20) continue;
    if (sample.lep2_.Pt() <= 10) continue;
    if (TMath::Min(sample.pmet_,sample.pTrackMet_) <= 20) continue;
    if (sample.dilep_.Pt() <= 30) continue;
    if ((sample.cuts_ & SmurfTree::TopVeto) != SmurfTree::TopVeto) continue; 
    if (sample.mt_ <=30 || sample.mt_ >=280) continue;
    if (sample.mt_ <= 60 || sample.mt_ >= 280 || sample.dilep_.M() >= 200) continue;
  
    
    events_norm +=weight;
    histo_template->Fill(Unroll2VarTo1VarVersion2(sample.dilep_.M(), sample.mt_), weight);
    histo->Fill(sample.mt_, sample.dilep_.M(), weight);
    histo_lep1pt->Fill(sample.lep1_.Pt(), weight);
    histo_lep2pt->Fill(sample.lep2_.Pt(), weight);
    histo_lep1eta->Fill(sample.lep1_.Eta(), weight);
    histo_lep2eta->Fill(sample.lep2_.Eta(), weight);
    histo_mll->Fill(sample.dilep_.M(), weight);
    histo_mt->Fill(sample.mt_, weight);
    histo_ptll->Fill(sample.dilep_.Pt(), weight);
    histo_met->Fill(sample.met_, weight);
    histo_phill->Fill(fabs(sample.dPhi_*180/3.1415), weight);
    //cout << sample.event_ << "\t" << sample.run_ << "\t" << sample.lumi_ << endl;

  }
  
 cout << "Events used: " << events << endl;
 cout << "Final yield: " << events_norm << endl;
  
  f_root.Write();
  f_root.Close();
  
}



