#include "../../Smurf/Core/SmurfTree.h"
#include "TH2D.h"
#include "TH1D.h"

const double lumi8 = 19.467;
const double lumi7 = 4.924;

const double mz = 91.1876;


void chain(int nsel = 0, int cem = 8){
  
  char plotName[300];
  sprintf(plotName,"test");
  
  if (nsel == 0) {sprintf(plotName,"SM");}
  else if (nsel == 1) {sprintf(plotName,"0PM");}
  else if (nsel == 2) {sprintf(plotName,"0M");}
  else if (nsel == 3) {sprintf(plotName,"Mix");}
  
  char myRootFile[300];
  double lumi = lumi8;
  if (cem == 8){
    if (nsel == 0) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_hww125.root");
    else if (nsel == 1) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
    else if (nsel == 2) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mt-v19.root");
    else if (nsel == 3) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mf05ph0-v19.root");
   
 } else {
    lumi = lumi7;
    cout << endl;
    cout << "PLEASE UPDATE THE TUPLES" << endl;
    cout << endl;
    if (nsel == 0) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_hww125.root");
    else if (nsel == 1) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
    else if (nsel == 2) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mt-v19.root");
    else if (nsel == 3) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mf05ph0-v19.root");
 }
  
  //Load datasets
  
  SmurfTree sample;
  cout << myRootFile << endl;
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
  
  //distributions  
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
  for (int i=0; i<nSample; ++i) {
    //   for (int i=0; i<10; ++i) {
    sample.tree_->GetEntry(i); 
    double weight = 1;
    if (sample.dstype_ != SmurfTree::data) weight = lumi*sample.scale1fb_*sample.sfWeightPU_*sample.sfWeightEff_*sample.sfWeightTrig_;
    
    histo_lep1pt->Fill(sample.lep1_.Pt(), weight);
    histo_lep2pt->Fill(sample.lep2_.Pt(), weight);
    histo_lep1eta->Fill(sample.lep1_.Eta(), weight);
    histo_lep2eta->Fill(sample.lep2_.Eta(), weight);
    histo_mll->Fill(sample.dilep_.M(), weight);
    histo_mt->Fill(sample.mt_, weight);
    histo_ptll->Fill(sample.dilep_.Pt(), weight);
    histo_met->Fill(sample.met_, weight);
    histo_phill->Fill(fabs(sample.dPhi_*180/3.1415), weight);

    
    //HWW slection mock-off
    if (sample.njets_ !=1) continue;
    if (sample.jet1_.Pt() < 30) continue;
    
    if (sample.lep1_.Pt() < 20) continue;
    if (sample.lep2_.Pt() < 10) continue;
    
    if (sample.dilep_.M() < 12) continue;
    if (sample.pmet_ < 20 || sample.pTrackMet_ < 20) continue;
    if (sample.mt_ < 30) continue;
    if (sample.dilep_.Pt() < 30) continue;
    
    if ((fabs(sample.lep1McId_) == fabs(sample.lep2McId_)) && fabs(sample.dilep_.M() - mz) < 15) continue;
  
    
    histo->Fill(sample.mt_, sample.dilep_.M(), weight);
    
  }
  
 
  
  f_root.Write();
  f_root.Close();
  
}
