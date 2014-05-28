#include "SmurfTree.h"
#include "TH2D.h"
#include "TH1D.h"
#include "inputs.h"


void trees(int nsel = 0, int cem = 8, int jetbin = 0){
  
  char plotName[300], Message[300], jetName[300], folderName[300];
  sprintf(plotName,"test");
  sprintf(Message,"test");
  sprintf(jetName,"0jets");
 // if (jetbin == 1) sprintf(jetName,"1jets");
  
  sprintf(folderName,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva");
  

  if (nsel == 0) {sprintf(plotName,"Test"); sprintf(Message,"Test sample");}
  if (nsel == 1) {sprintf(plotName,"0PM"); sprintf(Message,"Standard Model JHU Gen");}
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
  
  
  
  char myRootFile[300];
  double lumi = lumi8;
  if (cem == 8){
    if (nsel == 0) 
    sprintf(myRootFile,"/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_%s_hww125.root",jetName);
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
  if (jetbin == 1) sprintf(jetName,"1jets");
  char rootFile[300];
  sprintf(rootFile,"trees/final_tree_%s_%s.root", plotName, jetName);
  
  TFile f_root(rootFile, "RECREATE");
 
  
  // Branches of the output Tree
  double event_weight;
  double event_number;
  double event_lumi;
  double event_type;
  
  double gen_lp_pt;
  double gen_lp_eta;
  double gen_lp_px;
  double gen_lp_py;
  double gen_lp_pz;
  double gen_lp_e;
  
  double gen_ln_pt;
  double gen_ln_eta;
  double gen_ln_px;
  double gen_ln_py;
  double gen_ln_pz;
  double gen_ln_e;
  
  double gen_nu_pt;
  double gen_nu_eta;
  double gen_nu_px;
  double gen_nu_py;
  double gen_nu_pz;
  double gen_nu_e;
  
  double gen_nub_pt;
  double gen_nub_eta;
  double gen_nub_px;
  double gen_nub_py;
  double gen_nub_pz;
  double gen_nub_e;
  
  double gen_met_pt;
  double gen_met_px;
  double gen_met_py;
  
  double l1_pt;
  double l1_eta;
  double l1_px;
  double l1_py;
  double l1_pz;
  double l1_e;
  double l1_id;
  
  double l2_pt;
  double l2_eta;
  double l2_px;
  double l2_py;
  double l2_pz;
  double l2_e;
  double l2_id;
  
  double met_pt;
  double event_mll;
  double event_mt;
    
  
  
  // Output Tree
  TTree* myTree = new TTree("tree", " ");
  
  myTree->Branch("event_weight", &event_weight, "event_weight/D");
  myTree->Branch("event_number", &event_number, "event_number/D");
  myTree->Branch("event_lumi", &event_lumi, "event_lumi/D");
  myTree->Branch("event_type", &event_type, "event_type/D");
  
  myTree->Branch("gen_lp_pt", &gen_lp_pt, "gen_lp_pt/D");
  myTree->Branch("gen_lp_eta", &gen_lp_eta, "gen_lp_eta/D");
  myTree->Branch("gen_lp_px", &gen_lp_px, "gen_lp_px/D");
  myTree->Branch("gen_lp_py", &gen_lp_py, "gen_lp_py/D");
  myTree->Branch("gen_lp_pz", &gen_lp_pz, "gen_lp_pz/D");
  myTree->Branch("gen_lp_e", &gen_lp_e, "gen_lp_e/D");
  
  myTree->Branch("gen_ln_pt", &gen_ln_pt, "gen_ln_pt/D");
  myTree->Branch("gen_ln_eta", &gen_ln_eta, "gen_ln_eta/D");
  myTree->Branch("gen_ln_px", &gen_ln_px, "gen_ln_px/D");
  myTree->Branch("gen_ln_py", &gen_ln_py, "gen_ln_py/D");
  myTree->Branch("gen_ln_pz", &gen_ln_pz, "gen_ln_pz/D");
  myTree->Branch("gen_ln_e", &gen_ln_e, "gen_ln_e/D");
  
  myTree->Branch("gen_nu_pt", &gen_nu_pt, "gen_nu_pt/D");
  myTree->Branch("gen_nu_eta", &gen_nu_eta, "gen_nu_eta/D");
  myTree->Branch("gen_nu_px", &gen_nu_px, "gen_nu_px/D");
  myTree->Branch("gen_nu_py", &gen_nu_py, "gen_nu_py/D");
  myTree->Branch("gen_nu_pz", &gen_nu_pz, "gen_nu_pz/D");
  myTree->Branch("gen_nu_e", &gen_nu_e, "gen_nu_e/D");
  
  myTree->Branch("gen_nub_pt", &gen_nub_pt, "gen_nub_pt/D");
  myTree->Branch("gen_nub_eta", &gen_nub_eta, "gen_nub_eta/D");
  myTree->Branch("gen_nub_px", &gen_nub_px, "gen_nub_px/D");
  myTree->Branch("gen_nub_py", &gen_nub_py, "gen_nub_py/D");
  myTree->Branch("gen_nub_pz", &gen_nub_pz, "gen_nub_pz/D");
  myTree->Branch("gen_nub_e", &gen_nub_e, "gen_nub_e/D");
  
  
  myTree->Branch("gen_met_pt", &gen_met_pt, "gen_met_pt/D");
  myTree->Branch("gen_met_px", &gen_met_px, "gen_met_px/D");
  myTree->Branch("gen_met_py", &gen_met_py, "gen_met_py/D");
  
  myTree->Branch("l1_pt", &l1_pt, "l1_pt/D");
  myTree->Branch("l1_eta", &l1_eta, "l1_eta/D");
  myTree->Branch("l1_px", &l1_px, "l1_px/D");
  myTree->Branch("l1_py", &l1_py, "l1_py/D");
  myTree->Branch("l1_pz", &l1_pz, "l1_pz/D");
  myTree->Branch("l1_id", &l1_id, "l1_id/D");
  myTree->Branch("l1_e", &l1_e, "l1_e/D");
  
  myTree->Branch("l2_pt", &l2_pt, "l2_pt/D");
  myTree->Branch("l2_eta", &l2_eta, "l2_eta/D");
  myTree->Branch("l2_px", &l2_px, "l2_px/D");
  myTree->Branch("l2_py", &l2_py, "l2_py/D");
  myTree->Branch("l2_pz", &l2_pz, "l2_pz/D");
  myTree->Branch("l2_id", &l2_id, "l2_id/D");
  myTree->Branch("l2_e", &l2_e, "l2_e/D");
  
  myTree->Branch("met_pt", &met_pt, "met_pt/D");
  myTree->Branch("events_mll", &event_mll, "event_mll/D");
  myTree->Branch("event_mt", &event_mt, "event_mt/D");
  
  
  int nSample=sample.tree_->GetEntries();
  
 
  cout << nSample << " events in the ntuple" << endl;
  int events = 0;
  double events_norm = 0;
  for (int i=0; i<nSample; ++i) {
    //   for (int i=0; i<10; ++i) {
    sample.tree_->GetEntry(i); 
    
  //  if(sample.processId_ != 10010) continue;
    if ((fabs(sample.lep1McId_) == fabs(sample.lep2McId_))) continue;
    if (sample.type_ != 1 && sample.type_ != 2 ) continue;
    if ((sample.cuts_ & SmurfTree::Lep1FullSelection) != SmurfTree::Lep1FullSelection || 
	(sample.cuts_ & SmurfTree::Lep2FullSelection) != SmurfTree::Lep2FullSelection) continue;  
    events++;
    
    double weight = 1;
  
    if (sample.dstype_ != SmurfTree::data) weight = lumi*sample.scale1fb_*sample.sfWeightPU_*sample.sfWeightEff_*sample.sfWeightTrig_;
    
    //HWW slection mock-off
    int nJetsType = 0;
    nJetsType = jetbin;
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
    event_type = sample.processId_ ;
    
    gen_lp_pt = sample.genPart1_.Pt();
    gen_lp_eta = sample.genPart1_.Eta();
    gen_lp_px = sample.genPart1_.Px();
    gen_lp_py = sample.genPart1_.Py();
    gen_lp_pz = sample.genPart1_.Pz();
    gen_lp_e = sample.genPart1_.E();
    
    gen_ln_pt = sample.genPart3_.Pt();
    gen_ln_eta = sample.genPart3_.Eta();
    gen_ln_px = sample.genPart3_.Px();
    gen_ln_py = sample.genPart3_.Py();
    gen_ln_pz = sample.genPart3_.Pz();
    gen_ln_e = sample.genPart3_.E();
    
    gen_nu_pt = sample.genPart4_.Pt();
    gen_nu_eta = sample.genPart4_.Eta();
    gen_nu_px = sample.genPart4_.Px();
    gen_nu_py = sample.genPart4_.Py();
    gen_nu_pz = sample.genPart4_.Pz();
    gen_nu_e = sample.genPart4_.E();
    
    gen_nub_pt = sample.genPart2_.Pt();
    gen_nub_eta = sample.genPart2_.Eta();
    gen_nub_px = sample.genPart2_.Px();
    gen_nub_py = sample.genPart2_.Py();
    gen_nub_pz = sample.genPart2_.Pz();
    gen_nub_e = sample.genPart2_.E();
    
    gen_met_pt = sample.genmet_.Pt();
    gen_met_px = sample.genmet_.Px();
    gen_met_py = sample.genmet_.Py();
    
    l1_pt = sample.lep1_.Pt();
    l1_eta = sample.lep1_.Eta();
    l1_px = sample.lep1_.Px();
    l1_py = sample.lep1_.Py();
    l1_pz = sample.lep1_.Pz();
    l1_id = sample.lep1McId_ ;
    l1_e = sample.lep1_.E();
    
    l2_pt = sample.lep2_.Pt();
    l2_eta = sample.lep2_.Eta();
    l2_px = sample.lep2_.Px();
    l2_py = sample.lep2_.Py();
    l2_pz = sample.lep2_.Pz();
    l2_id = sample.lep2McId_;
    l2_e = sample.lep2_.E();
    
    met_pt = sample.met_;
    event_mll = sample.dilep_.M();
    event_mt = sample.mt_;
   
    
    myTree->Fill();
    
  
    
  }
  
  cout << "Events used: " << events << endl;
  cout << "Final yield: " << events_norm << endl;
  
  f_root.Write();
  f_root.Close();
  
}



