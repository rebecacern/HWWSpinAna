#include "../../Smurf/Core/SmurfTree.h"
#include "TH2D.h"
#include "TH1D.h"
#include "inputs.h"


void trees(int nsel = 1, int cem = 8, int jetbin = 0){
  
  char plotName[300], Message[300], jetName[300], folderName[300];
  sprintf(plotName,"test");
  sprintf(Message,"test");
  sprintf(jetName,"0jets");
  if (jetbin == 1) sprintf(jetName,"1jets");
  
  sprintf(folderName,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva");
  

  if (nsel == 1) {sprintf(plotName,"0PM"); sprintf(Message,"Standard Model JHU Gen");}
  else if (nsel == 2) {sprintf(plotName,"0M"); sprintf(Message,"Pseudoscalar JHU Gen");}
  else if (nsel == 3) {sprintf(plotName,"Mixfa3"); sprintf(Message,"Mix fa3");}
  else if (nsel == 4) {sprintf(plotName,"0PH"); sprintf(Message,"Scalar with Higher order corrections");}
  else if (nsel == 5) {sprintf(plotName,"Mixfa2"); sprintf(Message,"Mix fa2");}
  else if (nsel == 6) {sprintf(plotName,"Mixfa2fa3"); sprintf(Message,"Mix fa2, fa3");}
  else if (nsel == 7) {sprintf(plotName,"L1"); sprintf(Message,"Lambda 1");}
  else if (nsel == 8) {sprintf(plotName,"MixL1"); sprintf(Message,"Lambda 1 Mix");}
  
  
  char myRootFile[300];
  double lumi = lumi8;
  if (cem == 8){
    if (nsel == 1) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0pm-v19.root", folderName,jetName);
    else if (nsel == 2) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0mt-v19.root", folderName, jetName);
    else if (nsel == 3) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0mf05ph0-v19.root", folderName, jetName);
    else if (nsel == 4) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0ph-v19.root", folderName, jetName);
    else if (nsel == 5) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0phf05ph0-v19.root", folderName, jetName); 
    else if (nsel == 6) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0phf05-v19.root", folderName, jetName); 
    else if (nsel == 7) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0l1-v19.root", folderName, jetName); 
    else if (nsel == 8) sprintf(myRootFile,"%s/ntuples2012_MultiClass_125train_%s_xww125p6_x125ww4l-0l1f05ph180-v19.root", folderName, jetName); 
     
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
  
  // Create rootfiles with final-level trees
  char rootFile[300];
  sprintf(rootFile,"trees/final_tree_%s_%s.root", plotName, jetName);
  
  TFile f_root(rootFile, "RECREATE");
 
  
  // Branches of the output Tree
  double event_weight;
  double event_number;
  double event_lumi;
  
  double gen_l1_pt;
  double gen_l1_eta;
  double gen_l1_px;
  double gen_l1_py;
  double gen_l1_pz;
  double gen_l1_id;
  
  double gen_l2_pt;
  double gen_l2_eta;
  double gen_l2_px;
  double gen_l2_py;
  double gen_l2_pz;
  double gen_l2_id;
  
  double gen_met_pt;
  double gen_met_px;
  double gen_met_py;
  
  double l1_pt;
  double l1_eta;
  double l1_px;
  double l1_py;
  double l1_pz;
  double l1_id;
  
  double l2_pt;
  double l2_eta;
  double l2_px;
  double l2_py;
  double l2_pz;
  double l2_id;
  
  double met_pt;
    
  
  
  // Output Tree
  TTree* myTree = new TTree("tree", " ");
  
  myTree->Branch("event_weight", &event_weight, "event_weight/D");
  myTree->Branch("event_number", &event_number, "event_number/D");
  myTree->Branch("event_lumi", &event_lumi, "event_lumi/D");
  
  myTree->Branch("gen_l1_pt", &gen_l1_pt, "gen_l1_pt/D");
  myTree->Branch("gen_l1_eta", &gen_l1_eta, "gen_l1_eta/D");
  myTree->Branch("gen_l1_px", &gen_l1_px, "gen_l1_px/D");
  myTree->Branch("gen_l1_py", &gen_l1_py, "gen_l1_py/D");
  myTree->Branch("gen_l1_pz", &gen_l1_pz, "gen_l1_pz/D");
  myTree->Branch("gen_l1_id", &gen_l1_id, "gen_l1_id/D");
  
  myTree->Branch("gen_l2_pt", &gen_l2_pt, "gen_l2_pt/D");
  myTree->Branch("gen_l2_eta", &gen_l2_eta, "gen_l2_eta/D");
  myTree->Branch("gen_l2_px", &gen_l2_px, "gen_l2_px/D");
  myTree->Branch("gen_l2_py", &gen_l2_py, "gen_l2_py/D");
  myTree->Branch("gen_l2_pz", &gen_l2_pz, "gen_l2_pz/D");
  myTree->Branch("gen_l2_id", &gen_l2_id, "gen_l2_id/D");
  
  myTree->Branch("gen_met_pt", &gen_met_pt, "gen_met_pt/D");
  myTree->Branch("gen_met_px", &gen_met_px, "gen_met_px/D");
  myTree->Branch("gen_met_py", &gen_met_py, "gen_met_py/D");
  
  myTree->Branch("l1_pt", &l1_pt, "l1_pt/D");
  myTree->Branch("l1_eta", &l1_eta, "l1_eta/D");
  myTree->Branch("l1_px", &l1_px, "l1_px/D");
  myTree->Branch("l1_py", &l1_py, "l1_py/D");
  myTree->Branch("l1_pz", &l1_pz, "l1_pz/D");
  myTree->Branch("l1_id", &l1_id, "l1_id/D");
  
  myTree->Branch("l2_pt", &l2_pt, "l2_pt/D");
  myTree->Branch("l2_eta", &l2_eta, "l2_eta/D");
  myTree->Branch("l2_px", &l2_px, "l2_px/D");
  myTree->Branch("l2_py", &l2_py, "l2_py/D");
  myTree->Branch("l2_pz", &l2_pz, "l2_pz/D");
  myTree->Branch("l2_id", &l2_id, "l2_id/D");
  
  myTree->Branch("met_pt", &met_pt, "met_pt/D");
  
  
  int nSample=sample.tree_->GetEntries();
  
 
  cout << nSample << " events in the ntuple" << endl;
  int events = 0;
  double events_norm = 0;
  for (int i=0; i<nSample; ++i) {
    //   for (int i=0; i<10; ++i) {
    sample.tree_->GetEntry(i); 
    
    if(sample.processId_ != 10010) continue;
    if ((fabs(sample.lep1McId_) == fabs(sample.lep2McId_))) continue;
    if (sample.type_ != 1 && sample.type_ != 2 ) continue;
    if ((sample.cuts_ & SmurfTree::Lep1FullSelection) != SmurfTree::Lep1FullSelection || 
	(sample.cuts_ & SmurfTree::Lep2FullSelection) != SmurfTree::Lep2FullSelection) continue;  
    events++;
    
    double weight = 1;
  
    if (sample.dstype_ != SmurfTree::data) weight = lumi*sample.scale1fb_*sample.sfWeightPU_*sample.sfWeightEff_*sample.sfWeightTrig_;
    
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
    
    event_weight = weight;
    event_number = sample.event_;
    event_lumi = sample.lumi_;
    
    gen_l1_pt = sample.lep1_.Pt();
    gen_l1_eta = sample.lep1_.Eta();
    gen_l1_px = sample.lep1_.Px();
    gen_l1_py = sample.lep1_.Py();
    gen_l1_pz = sample.lep1_.Pz();
    gen_l1_id = sample.lep1McId_ ;
    
    gen_l2_pt = sample.lep2_.Pt();
    gen_l2_eta = sample.lep2_.Eta();
    gen_l2_px = sample.lep2_.Px();
    gen_l2_py = sample.lep2_.Py();
    gen_l2_pz = sample.lep2_.Pz();
    gen_l2_id = sample.lep2McId_;
    
    gen_met_pt = sample.genmet_.Pt();
    gen_met_px = sample.genmet_.Px();
    gen_met_py = sample.genmet_.Py();
    
    l1_pt = sample.lep1_.Pt();
    l1_eta = sample.lep1_.Eta();
    l1_px = sample.lep1_.Px();
    l1_py = sample.lep1_.Py();
    l1_pz = sample.lep1_.Pz();
    l1_id = sample.lep1McId_ ;
    
    l2_pt = sample.lep2_.Pt();
    l2_eta = sample.lep2_.Eta();
    l2_px = sample.lep2_.Px();
    l2_py = sample.lep2_.Py();
    l2_pz = sample.lep2_.Pz();
    l2_id = sample.lep2McId_;
    
    met_pt = sample.met_;
    
    myTree->Fill();
    
  
    
  }
  
  cout << "Events used: " << events << endl;
  cout << "Final yield: " << events_norm << endl;
  
  f_root.Write();
  f_root.Close();
  
}



