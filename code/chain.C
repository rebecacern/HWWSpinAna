#include "../../Smurf/Core/SmurfTree.h"
#include "TH2D.h"
#include "TH1D.h"
#include "inputs.h"


void chain(int nsel = 0, int cem = 8){
  
  char plotName[300], Message[300];
  sprintf(plotName,"test");
  sprintf(Message,"test");
  
  if (nsel == 0) {sprintf(plotName,"SM"); sprintf(Message,"Standard Model 125GeV official legacy sample");}
  else if (nsel == 1) {sprintf(plotName,"0PM"); sprintf(Message,"Standard Model JHU Gen");}
  else if (nsel == 2) {sprintf(plotName,"0M"); sprintf(Message,"Pseudoscalar JHU Gen");}
  else if (nsel == 3) {sprintf(plotName,"Mix"); sprintf(Message,"Mix JHU Gen");}
  else if (nsel == 4) {sprintf(plotName,"Old"); sprintf(Message,"Standard Model 125GeV JHU Gen old sample");}
  
  char myRootFile[300];
  double lumi = lumi8;
  if (cem == 8){
    if (nsel == 0) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_hww125.root");
    else if (nsel == 1) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
    else if (nsel == 2) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mt-v19.root");
    else if (nsel == 3) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mf05ph0-v19.root");
    else if (nsel == 4) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets/xww0p125.root");
 } else {
    lumi = lumi7;
    cout << endl;
    cout << "PLEASE UPDATE THE TUPLES" << endl;
    cout << endl;
    if (nsel == 0) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_hww125.root");
    else if (nsel == 1) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
    else if (nsel == 2) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mt-v19.root");
    else if (nsel == 3) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mf05ph0-v19.root");
    else if (nsel == 4) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets/xww0p125.root");
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
    if(sample.processId_ != 10010) continue;
    if ((fabs(sample.lep1McId_) == fabs(sample.lep2McId_))) continue;
    if ((sample.cuts_ & SmurfTree::Lep1FullSelection) != SmurfTree::Lep1FullSelection || 
    (sample.cuts_ & SmurfTree::Lep2FullSelection) != SmurfTree::Lep2FullSelection) continue;  
    events++;
    
    double weight = 1;
    if (sample.dstype_ != SmurfTree::data) weight = lumi*sample.scale1fb_*sample.sfWeightPU_*sample.sfWeightEff_*sample.sfWeightTrig_;
    
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
    if (sample.dilep_.M() <= 12 && sample.dilep_.M() >= 200) continue;
    if ((sample.cuts_ & SmurfTree::ExtraLeptonVeto) != SmurfTree::ExtraLeptonVeto) continue;
    if (sample.lq1_*sample.lq2_ > 0) continue;
    if (sample.njets_ != nJetsType) continue; 
    if (sample.lep1_.Pt() <= 20) continue;
    if (sample.lep2_.Pt() <= 10) continue;
    if (TMath::Min(sample.pmet_,sample.pTrackMet_) <= 20) continue;
    if (sample.dilep_.Pt() <= 30) continue;
    if ((sample.cuts_ & SmurfTree::TopVeto) != SmurfTree::TopVeto) continue; 
    if (sample.mt_ <=30 || sample.mt_ >=280) continue;
    if (sample.mt_ <= 60 || sample.mt_ >= 120 || sample.dilep_.M() >= 100) continue;

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

  }
  
 cout << "Events used: " << events << endl;
 cout << "Final yield: " << events_norm << endl;
  
  f_root.Write();
  f_root.Close();
  
}



