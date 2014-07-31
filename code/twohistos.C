#include "../../Smurf/Core/SmurfTree.h"
#include "TH2D.h"
#include "TH1D.h"
#include "inputs.h"


void twohistos(int nsel = 1, int cem = 7, int var = 0, int jetbin =0){
  
   
  char plotName[300], Message[300], jetName[300], folderName[300];
  sprintf(plotName,"test");
  sprintf(Message,"test");
  sprintf(jetName,"0jets");
 // if (jetbin == 1) sprintf(jetName,"1jets");  
  
  sprintf(folderName,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva");
  
  if (nsel == 1) {sprintf(plotName,"Higgs_SM"); sprintf(Message,"Standard Model JHU Gen");}
  else if (nsel == 2) {sprintf(plotName,"Higgs_0M"); sprintf(Message,"Pseudoscalar JHU Gen");}
  else if (nsel == 3) {sprintf(plotName,"Higgs_fa305"); sprintf(Message,"Mix fa3");}
  else if (nsel == 4) {sprintf(plotName,"Higgs_0PH"); sprintf(Message,"Scalar with Higher order corrections");}
  else if (nsel == 5) {sprintf(plotName,"Higgs_fa205"); sprintf(Message,"Mix fa2");}
  else if (nsel == 6) {sprintf(plotName,"Higgs_L1"); sprintf(Message,"Lambda 1");}
  else if (nsel == 7) {sprintf(plotName,"Higgs_mixL1"); sprintf(Message,"Lambda 1 Mix");}
  
  char myRootFile[300];
  double lumi = lumi8;
  if (cem == 8){
    if (nsel == 1) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0pm-v19.root", folderName,jetName);
    else if (nsel == 2) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0mt-v19.root", folderName, jetName);
    else if (nsel == 3) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0mf05ph0-v19.root", folderName, jetName);
    else if (nsel == 4) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0ph-v19.root", folderName, jetName);
    else if (nsel == 5) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0phf05ph0-v19.root", folderName, jetName); 
    else if (nsel == 6) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0l1-v19.root", folderName, jetName); 
    else if (nsel == 7) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_s12-x125ww4l-0l1f05ph180-v19.root", folderName, jetName);     
  } else {
    lumi = lumi7;
    sprintf(folderName,"/data/smurf/data/Run2011_Fall11_SmurfV9_42X/mitf-alljets_mva");
    if (nsel == 1) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6_x125ww4l-0pm.root", folderName,jetName);
    else if (nsel == 2) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6-0m.root", folderName, jetName);
    else if (nsel == 3) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6-0mf05ph0.root", folderName, jetName);
    else if (nsel == 4) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6_x125ww4l-0ph.root", folderName, jetName);
    else if (nsel == 5) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6_x125ww4l-0phf05ph0.root", folderName, jetName); 
    else if (nsel == 6) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6_x125ww4l-0phf05.root", folderName, jetName); 
    else if (nsel == 7) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6_x125ww4l-0l1.root", folderName, jetName); 
    else if (nsel == 8) sprintf(myRootFile,"%s/ntuples_126train_%s_xww125p6_x125ww4l-0l1f05ph180.root", folderName, jetName); 
  }
  
  //Load datasets
  
  SmurfTree sample;
  cout << myRootFile << endl;
  cout << "You are running " << Message << endl;
  sample.LoadTree(myRootFile,-1);
  sample.InitTree(0);
  
  char rootFile[300];
  sprintf(rootFile,"rootfiles_var/test_mll_%dj.root", jetbin);
  if (var !=0) sprintf(rootFile,"rootfiles_var/test_mt_%dj.root", jetbin);
  
  TFile f_root(rootFile, "UPDATE");
  
  // Prepare histograms
  char title[300];
  
  sprintf(title,"%s",plotName);
  int n_bins = 25;
  int binfirst = 0;
  int binlast = 200;
  if (var !=0 ){
    n_bins = 30;
    binfirst = 60;
    binlast = 280;
  }
  TH1F* histo = new TH1F( title, "histos", n_bins, binfirst, binlast);
  histo->Sumw2();
  
   
  // 25, 0-200 mll called like the process, first one caps, title "histos"
  // 30, 60-280 mts
  
  //To business
  int nSample=sample.tree_->GetEntries();
  
  cout << nSample << endl;
  int events = 0;
  double events_norm = 0;
  
  for (int i=0; i<nSample; ++i) {
    //   for (int i=0; i<10; ++i) {
    sample.tree_->GetEntry(i); 
  
    if ((fabs(sample.lep1McId_) == fabs(sample.lep2McId_))) continue;
    if (sample.type_ != 1 && sample.type_ != 2 ) continue;
    if ((sample.cuts_ & SmurfTree::Lep1FullSelection) != SmurfTree::Lep1FullSelection || 
    (sample.cuts_ & SmurfTree::Lep2FullSelection) != SmurfTree::Lep2FullSelection) continue;  
    events++;
    
    double weight = 1;
    if (sample.dstype_ != SmurfTree::data) weight = lumi*sample.scale1fb_*sample.sfWeightPU_*sample.sfWeightEff_*sample.sfWeightTrig_;
    
    //HWW slection mock-off
    int nJetsType = jetbin;
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
    if (var ==0) histo->Fill(sample.dilep_.M(), weight);
    else histo->Fill(sample.mt_, weight);
  

  }
  
 cout << "Events used: " << events << endl;
 cout << "Final yield: " << events_norm << endl;
  
  f_root.Write();
  f_root.Close();
  
}



