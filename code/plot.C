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
  else if (nsel == 22) {sprintf(plotName, "0PM_VBF");}
  else if (nsel == 23) {sprintf(plotName, "0PM_WH");}
  else if (nsel == 24) {sprintf(plotName, "0PM_ZH");}
  else if (nsel == 25) {sprintf(plotName, "0PM_TTH");}

  	
  TString cutLabel[26] ={"SM 0^{+}_{m} Official", "0^{+}_{m}", "0^{-}", "f_{a3} = 0.5","0^{+}_{h}", "f_{a2} = 0.5",
  				"fa_{a3} = f_{a2}=0.5", "0_{#Lambda1}", "f_{#Lambda1}=0.5", "Old JHU", "2^{+}_{b}", "2^{+}_{h}",
				"2^{-}_{h}", "2^{+}_{min}", "2^{+}_{h2}", "2^{+}_{h6}", "2^{-}_{h9}", "2^{-}_{h10}",
				"2^{+}_{h3}", "2^{+}_{h7}", "1^{+}", "1^{-}", "VBF 0^{+}_{m}", "WH 0^{+}_{m}", "ZH 0^{+}_{m}", "ttH 0^{+}_{-}" };
  
  TString cutName[26] = { "SM", "0PM", "0M", "Mixfa3","0PH", "Mixfa2", "Mixfa2fa3", "L1", "MixL1", "Old", "2BP", "2HP",
  			"2HM", "2PM", "2PH2","2PH6", "2MH9","2MH10", "2PH3", "2PH7", "1P", "1M", "0PM_VBF", "0PM_WH", "0PM_ZH", "0PM_TTH"};
  
  char title[300];
  TH2D* histo;
  
  sprintf(title,"histo_%s_%dTeV",plotName, cem);
  histo = (TH2D*) _file0->Get(title);
   
  labelcms  = new TPaveText(0.15,0.8,0.85,0.88,"NDCBR");
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
  if (cem == 8)  c1->SaveAs("plots/"+cutName[nsel]+ "_8TeV.png");
  else  c1->SaveAs("plots/"+ cutName[nsel]+ "_7TeV.png");
  if (cem == 8)  c1->SaveAs("plots/"+cutName[nsel]+ "_8TeV.pdf");
  else  c1->SaveAs("plots/"+ cutName[nsel]+ "_7TeV.pdf");
 
}
