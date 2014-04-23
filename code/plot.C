 
#include "setTDRStyle.C"
 
void plot(int nsel = 0, int cem = 8){
  
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

  char myRootFile[300];
  sprintf(myRootFile,"rootfiles/test.root");
  
  TFile *_file0 = TFile::Open(myRootFile);
 
  char plotName[300];
  sprintf(plotName,"test");
  
  if (nsel == 0) {sprintf(plotName,"0PM");}
  else if (nsel == 1) {sprintf(plotName,"0M");}
  else if (nsel == 2) {sprintf(plotName,"Mix");}
  else if (nsel == 3) {sprintf(plotName,"BCK");}
  
  TString cutLabel[4] =     { "0Pm", "0m", "0Mix", "bck"};

  
  char title[300];
  TH2D* histo;
  
  sprintf(title,"histo_%s_%dTeV",plotName, cem);
  histo = (TH2D*) _file0->Get(title);
   
  labelcms  = new TPaveText(0.15,0.8,0.75,0.85,"NDCBR");
  labelcms->SetTextAlign(12);
  labelcms->SetTextSize(0.0435);
  labelcms->SetFillColor(kWhite);
  labelcms->AddText("H #rightarrow WW #rightarrow 2l, 0 jets, "+  cutLabel[nsel]);
  labelcms->SetBorderSize(1);
         
 
     
  TCanvas *c1 = new TCanvas();
  histo->SetContour(28);
  histo->Draw("Colz");
  histo->GetYaxis()->SetTitle("m_{ll} [GeV]");
  histo->GetXaxis()->SetTitle("m_{T} [GeV]");
  labelcms->Draw();
  if (cem == 8)  c1->SaveAs("plots/"+ cutLabel[nsel]+ "_8TeV.png");
  else  c1->SaveAs("plots/"+ cutLabel[nsel]+ "_7TeV.png");
   
}
