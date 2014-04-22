//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 22 14:47:49 2014 by ROOT version 5.34/03
// from TTree tree/Smurf ntuples
// found on file: /data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root
//////////////////////////////////////////////////////////

#ifndef myclass_h
#define myclass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <Math/GenVector/LorentzVector.h>
#include <Math/GenVector/PxPyPzE4D.h>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class myclass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          event;
   UInt_t          run;
   UInt_t          lumi;
   UInt_t          nvtx;
   UInt_t          cuts;
   Float_t         scale1fb;
   Float_t         met;
   Float_t         metPhi;
   Float_t         metMVA;
   Float_t         metMVAPhi;
   Float_t         pmetMVA;
   Float_t         sumet;
   Float_t         metSig;
   Int_t           type;
   Int_t           dstype;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *lep1;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Int_t           lq1;
   Int_t           lid1;
   Float_t         lmva1;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *lep2;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Int_t           lq2;
   Int_t           lid2;
   Float_t         lmva2;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *jet1;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Float_t         jet1Btag;
   Float_t         jet1ProbBtag;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *jet2;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Float_t         jet2Btag;
   Float_t         jet2ProbBtag;
   UInt_t          njets;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *dilep;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *quadlep;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Float_t         trackMet;
   Float_t         trackMetPhi;
   Float_t         pmet;
   Float_t         pTrackMet;
   Float_t         mt;
   Float_t         mt1;
   Float_t         mt2;
   Float_t         dPhi;
   Float_t         dR;
   Float_t         dPhiDiLepMET;
   Float_t         dPhiLep1MET;
   Float_t         dPhiLep2MET;
   Float_t         dPhiDiLepJet1;
   Float_t         lep1DetEta;
   Float_t         lep2DetEta;
   Int_t           lep1McId;
   Int_t           lep2McId;
   Int_t           lep1MotherMcId;
   Int_t           lep2MotherMcId;
   Int_t           jet1McId;
   Int_t           jet2McId;
   Int_t           processId;
   Float_t         higgsPt;
   Float_t         sfWeightFR;
   Float_t         sfWeightPU;
   Float_t         sfWeightTrig;
   Float_t         sfWeightEff;
   Float_t         sfWeightHPt;
   Float_t         dymva;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *lep3;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Int_t           lq3;
   Int_t           lid3;
   Float_t         lmva3;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *jet3;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Float_t         jet3Btag;
   Float_t         jet3ProbBtag;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *jet4;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Float_t         jet4Btag;
   Float_t         jet4ProbBtag;
   Float_t         lep3DetEta;
   Int_t           lep3McId;
   Int_t           lep3MotherMcId;
   Int_t           jet3McId;
   Int_t           jet4McId;
   Float_t         dPhiLep3MET;
   Float_t         mt3;
   Float_t         jetLowBtag;
   UInt_t          nSoftMuons;
   Float_t         Q;
   Float_t         id1;
   Float_t         x1;
   Float_t         pdf1;
   Float_t         id2;
   Float_t         x2;
   Float_t         pdf2;
   Float_t         npu;
   Float_t         npuPlusOne;
   Float_t         npuMinusOne;
   vector<double>  *lheWeights;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *genlep1;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *genlep2;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *genlep3;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *genjet1;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *genjet2;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *genjet3;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
 //ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<double> > *genmet;
   Double_t        fCoordinates_fX;
   Double_t        fCoordinates_fY;
   Double_t        fCoordinates_fZ;
   Double_t        fCoordinates_fT;
   Int_t           genlep1McId;
   Int_t           genlep2McId;
   Int_t           genlep3McId;
   Float_t         auxVar0;
   Float_t         dymvaMET;
   Float_t         dymvaJESU;
   Float_t         dymvaJESD;
   Float_t         recoil;
   Float_t         dPhiJet1MET;
   Float_t         ewkMVA;
   Float_t         bdtg_hww125_0jet_ww;
   Float_t         bdtg_hww125_0jet_ww_aux0;
   Float_t         bdtg_hww125_0jet_ww_aux1;
   Float_t         bdtg_hww125_0jet_ww_aux2;
   Float_t         bdtg_hww125_0jet_ww_aux3;
   Float_t         bdtg_hww125_0jet_ww_aux4;
   Float_t         mll_lepup;
   Float_t         mt_lepup;
   Float_t         mll_lepdown;
   Float_t         mt_lepdown;
   Float_t         mll_metup;
   Float_t         mt_metup;
   Float_t         bdtgV0;
   Float_t         bdtgV1;
   Float_t         bdtgV2;
   Float_t         bdtgV0_aux0;
   Float_t         bdtgV1_aux0;
   Float_t         bdtgV2_aux0;
   Float_t         bdtgV0_aux1;
   Float_t         bdtgV1_aux1;
   Float_t         bdtgV2_aux1;
   Float_t         bdtgV0_aux2;
   Float_t         bdtgV1_aux2;
   Float_t         bdtgV2_aux2;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_nvtx;   //!
   TBranch        *b_cuts;   //!
   TBranch        *b_scale1fb;   //!
   TBranch        *b_met;   //!
   TBranch        *b_metPhi;   //!
   TBranch        *b_metMVA;   //!
   TBranch        *b_metMVAPhi;   //!
   TBranch        *b_pmetMVA;   //!
   TBranch        *b_sumet;   //!
   TBranch        *b_metSig;   //!
   TBranch        *b_type;   //!
   TBranch        *b_dstype;   //!
   TBranch        *b_lep1_fCoordinates_fX;   //!
   TBranch        *b_lep1_fCoordinates_fY;   //!
   TBranch        *b_lep1_fCoordinates_fZ;   //!
   TBranch        *b_lep1_fCoordinates_fT;   //!
   TBranch        *b_lq1;   //!
   TBranch        *b_lid1;   //!
   TBranch        *b_lmva1;   //!
   TBranch        *b_lep2_fCoordinates_fX;   //!
   TBranch        *b_lep2_fCoordinates_fY;   //!
   TBranch        *b_lep2_fCoordinates_fZ;   //!
   TBranch        *b_lep2_fCoordinates_fT;   //!
   TBranch        *b_lq2;   //!
   TBranch        *b_lid2;   //!
   TBranch        *b_lmva2;   //!
   TBranch        *b_jet1_fCoordinates_fX;   //!
   TBranch        *b_jet1_fCoordinates_fY;   //!
   TBranch        *b_jet1_fCoordinates_fZ;   //!
   TBranch        *b_jet1_fCoordinates_fT;   //!
   TBranch        *b_jet1Btag;   //!
   TBranch        *b_jet1ProbBtag;   //!
   TBranch        *b_jet2_fCoordinates_fX;   //!
   TBranch        *b_jet2_fCoordinates_fY;   //!
   TBranch        *b_jet2_fCoordinates_fZ;   //!
   TBranch        *b_jet2_fCoordinates_fT;   //!
   TBranch        *b_jet2Btag;   //!
   TBranch        *b_jet2ProbBtag;   //!
   TBranch        *b_njets;   //!
   TBranch        *b_dilep_fCoordinates_fX;   //!
   TBranch        *b_dilep_fCoordinates_fY;   //!
   TBranch        *b_dilep_fCoordinates_fZ;   //!
   TBranch        *b_dilep_fCoordinates_fT;   //!
   TBranch        *b_quadlep_fCoordinates_fX;   //!
   TBranch        *b_quadlep_fCoordinates_fY;   //!
   TBranch        *b_quadlep_fCoordinates_fZ;   //!
   TBranch        *b_quadlep_fCoordinates_fT;   //!
   TBranch        *b_trackMet;   //!
   TBranch        *b_trackMetPhi;   //!
   TBranch        *b_pmet;   //!
   TBranch        *b_pTrackMet;   //!
   TBranch        *b_mt;   //!
   TBranch        *b_mt1;   //!
   TBranch        *b_mt2;   //!
   TBranch        *b_dPhi;   //!
   TBranch        *b_dR;   //!
   TBranch        *b_dPhiDiLepMET;   //!
   TBranch        *b_dPhiLep1MET;   //!
   TBranch        *b_dPhiLep2MET;   //!
   TBranch        *b_dPhiDiLepJet1;   //!
   TBranch        *b_lep1DetEta;   //!
   TBranch        *b_lep2DetEta;   //!
   TBranch        *b_lep1McId;   //!
   TBranch        *b_lep2McId;   //!
   TBranch        *b_lep1MotherMcId;   //!
   TBranch        *b_lep2MotherMcId;   //!
   TBranch        *b_jet1McId;   //!
   TBranch        *b_jet2McId;   //!
   TBranch        *b_processId;   //!
   TBranch        *b_higgsPt;   //!
   TBranch        *b_sfWeightFR;   //!
   TBranch        *b_sfWeightPU;   //!
   TBranch        *b_sfWeightTrig;   //!
   TBranch        *b_sfWeightEff;   //!
   TBranch        *b_sfWeightHPt;   //!
   TBranch        *b_dymva;   //!
   TBranch        *b_lep3_fCoordinates_fX;   //!
   TBranch        *b_lep3_fCoordinates_fY;   //!
   TBranch        *b_lep3_fCoordinates_fZ;   //!
   TBranch        *b_lep3_fCoordinates_fT;   //!
   TBranch        *b_lq3;   //!
   TBranch        *b_lid3;   //!
   TBranch        *b_lmva3;   //!
   TBranch        *b_jet3_fCoordinates_fX;   //!
   TBranch        *b_jet3_fCoordinates_fY;   //!
   TBranch        *b_jet3_fCoordinates_fZ;   //!
   TBranch        *b_jet3_fCoordinates_fT;   //!
   TBranch        *b_jet3Btag;   //!
   TBranch        *b_jet3ProbBtag;   //!
   TBranch        *b_jet4_fCoordinates_fX;   //!
   TBranch        *b_jet4_fCoordinates_fY;   //!
   TBranch        *b_jet4_fCoordinates_fZ;   //!
   TBranch        *b_jet4_fCoordinates_fT;   //!
   TBranch        *b_jet4Btag;   //!
   TBranch        *b_jet4ProbBtag;   //!
   TBranch        *b_lep3DetEta;   //!
   TBranch        *b_lep3McId;   //!
   TBranch        *b_lep3MotherMcId;   //!
   TBranch        *b_jet3McId;   //!
   TBranch        *b_jet4McId;   //!
   TBranch        *b_dPhiLep3MET;   //!
   TBranch        *b_mt3;   //!
   TBranch        *b_jetLowBtag;   //!
   TBranch        *b_nSoftMuons;   //!
   TBranch        *b_Q;   //!
   TBranch        *b_id1;   //!
   TBranch        *b_x1;   //!
   TBranch        *b_pdf1;   //!
   TBranch        *b_id2;   //!
   TBranch        *b_x2;   //!
   TBranch        *b_pdf2;   //!
   TBranch        *b_npu;   //!
   TBranch        *b_npuPlusOne;   //!
   TBranch        *b_npuMinusOne;   //!
   TBranch        *b_lheWeights;   //!
   TBranch        *b_genlep1_fCoordinates_fX;   //!
   TBranch        *b_genlep1_fCoordinates_fY;   //!
   TBranch        *b_genlep1_fCoordinates_fZ;   //!
   TBranch        *b_genlep1_fCoordinates_fT;   //!
   TBranch        *b_genlep2_fCoordinates_fX;   //!
   TBranch        *b_genlep2_fCoordinates_fY;   //!
   TBranch        *b_genlep2_fCoordinates_fZ;   //!
   TBranch        *b_genlep2_fCoordinates_fT;   //!
   TBranch        *b_genlep3_fCoordinates_fX;   //!
   TBranch        *b_genlep3_fCoordinates_fY;   //!
   TBranch        *b_genlep3_fCoordinates_fZ;   //!
   TBranch        *b_genlep3_fCoordinates_fT;   //!
   TBranch        *b_genjet1_fCoordinates_fX;   //!
   TBranch        *b_genjet1_fCoordinates_fY;   //!
   TBranch        *b_genjet1_fCoordinates_fZ;   //!
   TBranch        *b_genjet1_fCoordinates_fT;   //!
   TBranch        *b_genjet2_fCoordinates_fX;   //!
   TBranch        *b_genjet2_fCoordinates_fY;   //!
   TBranch        *b_genjet2_fCoordinates_fZ;   //!
   TBranch        *b_genjet2_fCoordinates_fT;   //!
   TBranch        *b_genjet3_fCoordinates_fX;   //!
   TBranch        *b_genjet3_fCoordinates_fY;   //!
   TBranch        *b_genjet3_fCoordinates_fZ;   //!
   TBranch        *b_genjet3_fCoordinates_fT;   //!
   TBranch        *b_genmet_fCoordinates_fX;   //!
   TBranch        *b_genmet_fCoordinates_fY;   //!
   TBranch        *b_genmet_fCoordinates_fZ;   //!
   TBranch        *b_genmet_fCoordinates_fT;   //!
   TBranch        *b_genlep1McId;   //!
   TBranch        *b_genlep2McId;   //!
   TBranch        *b_genlep3McId;   //!
   TBranch        *b_auxVar0;   //!
   TBranch        *b_dymvaMET;   //!
   TBranch        *b_dymvaJESU;   //!
   TBranch        *b_dymvaJESD;   //!
   TBranch        *b_recoil;   //!
   TBranch        *b_dPhiJet1MET;   //!
   TBranch        *b_ewkMVA;   //!
   TBranch        *b_bdtg_hww125_0jet_ww;   //!
   TBranch        *b_bdtg_hww125_0jet_ww_aux0;   //!
   TBranch        *b_bdtg_hww125_0jet_ww_aux1;   //!
   TBranch        *b_bdtg_hww125_0jet_ww_aux2;   //!
   TBranch        *b_bdtg_hww125_0jet_ww_aux3;   //!
   TBranch        *b_bdtg_hww125_0jet_ww_aux4;   //!
   TBranch        *b_mll_lepup;   //!
   TBranch        *b_mt_lepup;   //!
   TBranch        *b_mll_lepdown;   //!
   TBranch        *b_mt_lepdown;   //!
   TBranch        *b_mll_metup;   //!
   TBranch        *b_mt_metup;   //!
   TBranch        *b_bdtgV0;   //!
   TBranch        *b_bdtgV1;   //!
   TBranch        *b_bdtgV2;   //!
   TBranch        *b_bdtgV0_aux0;   //!
   TBranch        *b_bdtgV1_aux0;   //!
   TBranch        *b_bdtgV2_aux0;   //!
   TBranch        *b_bdtgV0_aux1;   //!
   TBranch        *b_bdtgV1_aux1;   //!
   TBranch        *b_bdtgV2_aux1;   //!
   TBranch        *b_bdtgV0_aux2;   //!
   TBranch        *b_bdtgV1_aux2;   //!
   TBranch        *b_bdtgV2_aux2;   //!

   myclass(TTree *tree=0);
   virtual ~myclass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef myclass_cxx
myclass::myclass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/data/smurf/data/Run2012_Summer12_SmurfV9_53X/mitf-alljets_mva/ntuples2012_MultiClass_125train_0jets_xww125p6_x125ww4l-0pm-v19.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

myclass::~myclass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myclass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myclass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myclass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   lheWeights = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("nvtx", &nvtx, &b_nvtx);
   fChain->SetBranchAddress("cuts", &cuts, &b_cuts);
   fChain->SetBranchAddress("scale1fb", &scale1fb, &b_scale1fb);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("metPhi", &metPhi, &b_metPhi);
   fChain->SetBranchAddress("metMVA", &metMVA, &b_metMVA);
   fChain->SetBranchAddress("metMVAPhi", &metMVAPhi, &b_metMVAPhi);
   fChain->SetBranchAddress("pmetMVA", &pmetMVA, &b_pmetMVA);
   fChain->SetBranchAddress("sumet", &sumet, &b_sumet);
   fChain->SetBranchAddress("metSig", &metSig, &b_metSig);
   fChain->SetBranchAddress("type", &type, &b_type);
   fChain->SetBranchAddress("dstype", &dstype, &b_dstype);
   fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_lep1_fCoordinates_fX);
   fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_lep1_fCoordinates_fY);
   fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_lep1_fCoordinates_fZ);
   fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_lep1_fCoordinates_fT);
   fChain->SetBranchAddress("lq1", &lq1, &b_lq1);
   fChain->SetBranchAddress("lid1", &lid1, &b_lid1);
   fChain->SetBranchAddress("lmva1", &lmva1, &b_lmva1);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_lep2_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_lep2_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_lep2_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_lep2_fCoordinates_fT);
   fChain->SetBranchAddress("lq2", &lq2, &b_lq2);
   fChain->SetBranchAddress("lid2", &lid2, &b_lid2);
   fChain->SetBranchAddress("lmva2", &lmva2, &b_lmva2);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_jet1_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_jet1_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_jet1_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_jet1_fCoordinates_fT);
   fChain->SetBranchAddress("jet1Btag", &jet1Btag, &b_jet1Btag);
   fChain->SetBranchAddress("jet1ProbBtag", &jet1ProbBtag, &b_jet1ProbBtag);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_jet2_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_jet2_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_jet2_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_jet2_fCoordinates_fT);
   fChain->SetBranchAddress("jet2Btag", &jet2Btag, &b_jet2Btag);
   fChain->SetBranchAddress("jet2ProbBtag", &jet2ProbBtag, &b_jet2ProbBtag);
   fChain->SetBranchAddress("njets", &njets, &b_njets);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_dilep_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_dilep_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_dilep_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_dilep_fCoordinates_fT);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_quadlep_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_quadlep_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_quadlep_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_quadlep_fCoordinates_fT);
   fChain->SetBranchAddress("trackMet", &trackMet, &b_trackMet);
   fChain->SetBranchAddress("trackMetPhi", &trackMetPhi, &b_trackMetPhi);
   fChain->SetBranchAddress("pmet", &pmet, &b_pmet);
   fChain->SetBranchAddress("pTrackMet", &pTrackMet, &b_pTrackMet);
   fChain->SetBranchAddress("mt", &mt, &b_mt);
   fChain->SetBranchAddress("mt1", &mt1, &b_mt1);
   fChain->SetBranchAddress("mt2", &mt2, &b_mt2);
   fChain->SetBranchAddress("dPhi", &dPhi, &b_dPhi);
   fChain->SetBranchAddress("dR", &dR, &b_dR);
   fChain->SetBranchAddress("dPhiDiLepMET", &dPhiDiLepMET, &b_dPhiDiLepMET);
   fChain->SetBranchAddress("dPhiLep1MET", &dPhiLep1MET, &b_dPhiLep1MET);
   fChain->SetBranchAddress("dPhiLep2MET", &dPhiLep2MET, &b_dPhiLep2MET);
   fChain->SetBranchAddress("dPhiDiLepJet1", &dPhiDiLepJet1, &b_dPhiDiLepJet1);
   fChain->SetBranchAddress("lep1DetEta", &lep1DetEta, &b_lep1DetEta);
   fChain->SetBranchAddress("lep2DetEta", &lep2DetEta, &b_lep2DetEta);
   fChain->SetBranchAddress("lep1McId", &lep1McId, &b_lep1McId);
   fChain->SetBranchAddress("lep2McId", &lep2McId, &b_lep2McId);
   fChain->SetBranchAddress("lep1MotherMcId", &lep1MotherMcId, &b_lep1MotherMcId);
   fChain->SetBranchAddress("lep2MotherMcId", &lep2MotherMcId, &b_lep2MotherMcId);
   fChain->SetBranchAddress("jet1McId", &jet1McId, &b_jet1McId);
   fChain->SetBranchAddress("jet2McId", &jet2McId, &b_jet2McId);
   fChain->SetBranchAddress("processId", &processId, &b_processId);
   fChain->SetBranchAddress("higgsPt", &higgsPt, &b_higgsPt);
   fChain->SetBranchAddress("sfWeightFR", &sfWeightFR, &b_sfWeightFR);
   fChain->SetBranchAddress("sfWeightPU", &sfWeightPU, &b_sfWeightPU);
   fChain->SetBranchAddress("sfWeightTrig", &sfWeightTrig, &b_sfWeightTrig);
   fChain->SetBranchAddress("sfWeightEff", &sfWeightEff, &b_sfWeightEff);
   fChain->SetBranchAddress("sfWeightHPt", &sfWeightHPt, &b_sfWeightHPt);
   fChain->SetBranchAddress("dymva", &dymva, &b_dymva);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_lep3_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_lep3_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_lep3_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_lep3_fCoordinates_fT);
   fChain->SetBranchAddress("lq3", &lq3, &b_lq3);
   fChain->SetBranchAddress("lid3", &lid3, &b_lid3);
   fChain->SetBranchAddress("lmva3", &lmva3, &b_lmva3);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_jet3_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_jet3_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_jet3_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_jet3_fCoordinates_fT);
   fChain->SetBranchAddress("jet3Btag", &jet3Btag, &b_jet3Btag);
   fChain->SetBranchAddress("jet3ProbBtag", &jet3ProbBtag, &b_jet3ProbBtag);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_jet4_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_jet4_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_jet4_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_jet4_fCoordinates_fT);
   fChain->SetBranchAddress("jet4Btag", &jet4Btag, &b_jet4Btag);
   fChain->SetBranchAddress("jet4ProbBtag", &jet4ProbBtag, &b_jet4ProbBtag);
   fChain->SetBranchAddress("lep3DetEta", &lep3DetEta, &b_lep3DetEta);
   fChain->SetBranchAddress("lep3McId", &lep3McId, &b_lep3McId);
   fChain->SetBranchAddress("lep3MotherMcId", &lep3MotherMcId, &b_lep3MotherMcId);
   fChain->SetBranchAddress("jet3McId", &jet3McId, &b_jet3McId);
   fChain->SetBranchAddress("jet4McId", &jet4McId, &b_jet4McId);
   fChain->SetBranchAddress("dPhiLep3MET", &dPhiLep3MET, &b_dPhiLep3MET);
   fChain->SetBranchAddress("mt3", &mt3, &b_mt3);
   fChain->SetBranchAddress("jetLowBtag", &jetLowBtag, &b_jetLowBtag);
   fChain->SetBranchAddress("nSoftMuons", &nSoftMuons, &b_nSoftMuons);
   fChain->SetBranchAddress("Q", &Q, &b_Q);
   fChain->SetBranchAddress("id1", &id1, &b_id1);
   fChain->SetBranchAddress("x1", &x1, &b_x1);
   fChain->SetBranchAddress("pdf1", &pdf1, &b_pdf1);
   fChain->SetBranchAddress("id2", &id2, &b_id2);
   fChain->SetBranchAddress("x2", &x2, &b_x2);
   fChain->SetBranchAddress("pdf2", &pdf2, &b_pdf2);
   fChain->SetBranchAddress("npu", &npu, &b_npu);
   fChain->SetBranchAddress("npuPlusOne", &npuPlusOne, &b_npuPlusOne);
   fChain->SetBranchAddress("npuMinusOne", &npuMinusOne, &b_npuMinusOne);
   fChain->SetBranchAddress("lheWeights", &lheWeights, &b_lheWeights);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_genlep1_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_genlep1_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_genlep1_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_genlep1_fCoordinates_fT);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_genlep2_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_genlep2_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_genlep2_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_genlep2_fCoordinates_fT);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_genlep3_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_genlep3_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_genlep3_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_genlep3_fCoordinates_fT);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_genjet1_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_genjet1_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_genjet1_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_genjet1_fCoordinates_fT);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_genjet2_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_genjet2_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_genjet2_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_genjet2_fCoordinates_fT);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_genjet3_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_genjet3_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_genjet3_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_genjet3_fCoordinates_fT);
//    fChain->SetBranchAddress("fCoordinates.fX", &fCoordinates_fX, &b_genmet_fCoordinates_fX);
//    fChain->SetBranchAddress("fCoordinates.fY", &fCoordinates_fY, &b_genmet_fCoordinates_fY);
//    fChain->SetBranchAddress("fCoordinates.fZ", &fCoordinates_fZ, &b_genmet_fCoordinates_fZ);
//    fChain->SetBranchAddress("fCoordinates.fT", &fCoordinates_fT, &b_genmet_fCoordinates_fT);
   fChain->SetBranchAddress("genlep1McId", &genlep1McId, &b_genlep1McId);
   fChain->SetBranchAddress("genlep2McId", &genlep2McId, &b_genlep2McId);
   fChain->SetBranchAddress("genlep3McId", &genlep3McId, &b_genlep3McId);
   fChain->SetBranchAddress("auxVar0", &auxVar0, &b_auxVar0);
   fChain->SetBranchAddress("dymvaMET", &dymvaMET, &b_dymvaMET);
   fChain->SetBranchAddress("dymvaJESU", &dymvaJESU, &b_dymvaJESU);
   fChain->SetBranchAddress("dymvaJESD", &dymvaJESD, &b_dymvaJESD);
   fChain->SetBranchAddress("recoil", &recoil, &b_recoil);
   fChain->SetBranchAddress("dPhiJet1MET", &dPhiJet1MET, &b_dPhiJet1MET);
   fChain->SetBranchAddress("ewkMVA", &ewkMVA, &b_ewkMVA);
   fChain->SetBranchAddress("bdtg_hww125_0jet_ww", &bdtg_hww125_0jet_ww, &b_bdtg_hww125_0jet_ww);
   fChain->SetBranchAddress("bdtg_hww125_0jet_ww_aux0", &bdtg_hww125_0jet_ww_aux0, &b_bdtg_hww125_0jet_ww_aux0);
   fChain->SetBranchAddress("bdtg_hww125_0jet_ww_aux1", &bdtg_hww125_0jet_ww_aux1, &b_bdtg_hww125_0jet_ww_aux1);
   fChain->SetBranchAddress("bdtg_hww125_0jet_ww_aux2", &bdtg_hww125_0jet_ww_aux2, &b_bdtg_hww125_0jet_ww_aux2);
   fChain->SetBranchAddress("bdtg_hww125_0jet_ww_aux3", &bdtg_hww125_0jet_ww_aux3, &b_bdtg_hww125_0jet_ww_aux3);
   fChain->SetBranchAddress("bdtg_hww125_0jet_ww_aux4", &bdtg_hww125_0jet_ww_aux4, &b_bdtg_hww125_0jet_ww_aux4);
   fChain->SetBranchAddress("mll_lepup", &mll_lepup, &b_mll_lepup);
   fChain->SetBranchAddress("mt_lepup", &mt_lepup, &b_mt_lepup);
   fChain->SetBranchAddress("mll_lepdown", &mll_lepdown, &b_mll_lepdown);
   fChain->SetBranchAddress("mt_lepdown", &mt_lepdown, &b_mt_lepdown);
   fChain->SetBranchAddress("mll_metup", &mll_metup, &b_mll_metup);
   fChain->SetBranchAddress("mt_metup", &mt_metup, &b_mt_metup);
   fChain->SetBranchAddress("bdtgV0", &bdtgV0, &b_bdtgV0);
   fChain->SetBranchAddress("bdtgV1", &bdtgV1, &b_bdtgV1);
   fChain->SetBranchAddress("bdtgV2", &bdtgV2, &b_bdtgV2);
   fChain->SetBranchAddress("bdtgV0_aux0", &bdtgV0_aux0, &b_bdtgV0_aux0);
   fChain->SetBranchAddress("bdtgV1_aux0", &bdtgV1_aux0, &b_bdtgV1_aux0);
   fChain->SetBranchAddress("bdtgV2_aux0", &bdtgV2_aux0, &b_bdtgV2_aux0);
   fChain->SetBranchAddress("bdtgV0_aux1", &bdtgV0_aux1, &b_bdtgV0_aux1);
   fChain->SetBranchAddress("bdtgV1_aux1", &bdtgV1_aux1, &b_bdtgV1_aux1);
   fChain->SetBranchAddress("bdtgV2_aux1", &bdtgV2_aux1, &b_bdtgV2_aux1);
   fChain->SetBranchAddress("bdtgV0_aux2", &bdtgV0_aux2, &b_bdtgV0_aux2);
   fChain->SetBranchAddress("bdtgV1_aux2", &bdtgV1_aux2, &b_bdtgV1_aux2);
   fChain->SetBranchAddress("bdtgV2_aux2", &bdtgV2_aux2, &b_bdtgV2_aux2);
   Notify();
}

Bool_t myclass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myclass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myclass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myclass_cxx
