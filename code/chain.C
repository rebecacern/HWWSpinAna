#include "../../Smurf/Core/SmurfTree.h"
#include "TH2D.h"
#include "TH1D.h"

const double lumi8 = 19.467;
const double lumi7 = 4.924;

const double mz = 91.1876;


void chain(int nsel = 0, int cem = 8){
  
  char plotName[300];
  sprintf(plotName,"test");
  
  if (nsel == 0) {sprintf(plotName,"0PM");}
  else if (nsel == 1) {sprintf(plotName,"0M");}
  else if (nsel == 2) {sprintf(plotName,"Mix");}
  else if (nsel == 3) {sprintf(plotName,"BCK");}
  
  char myRootFile[300];
  double lumi = lumi8;
  if (cem == 8){
    if (nsel == 0) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
    else if (nsel == 1) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mt-v19.root");
    else if (nsel == 2) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mf05ph0-v19.root");
    else if (nsel == 3) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_backgroundA_skim6.root");
  } else {
    lumi = lumi7;
    cout << endl;
    cout << "PLEASE UPDATE THE TUPLES" << endl;
    cout << endl;
    if (nsel == 0) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
    else if (nsel == 1) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mt-v19.root");
    else if (nsel == 2) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0mf05ph0-v19.root");
    else if (nsel == 3) sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_backgroundA_skim6.root");
  }
  
  //Load datasets
  
  SmurfTree sample;
  cout << myRootFile << endl;
  sample.LoadTree(myRootFile,-1);
  sample.InitTree(0);
  
  char rootFile[300];
  sprintf(rootFile,"test.root");
  
  TFile f_root(rootFile, "UPDATE");
  
  // Prepare histograms
  char title[300];
  
  sprintf(title,"histo_%s_%dTeV",plotName, cem);
  TH2F* histo = new TH2F( title, " ", 6, 60, 120, 6, 10, 100);
  histo->Sumw2();
  
  
  int nSample=sample.tree_->GetEntries();
  
  cout << nSample << endl;
  for (int i=0; i<nSample; ++i) {
    //   for (int i=0; i<10; ++i) {
    sample.tree_->GetEntry(i); 
    double weight = 1;
    if (sample.dstype_ != SmurfTree::data) weight = lumi*sample.scale1fb_*sample.sfWeightPU_*sample.sfWeightEff_*sample.sfWeightTrig_;
    
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
