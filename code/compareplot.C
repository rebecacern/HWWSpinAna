 
#include "setTDRStyle.C"
 
void compareplot(){
  
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
 
  TString sampleLabel[5] =     {"SM", "0PM", "0M", "Mix", "Old"};


  const int nPlots = 9;
  TString cutLabel[nPlots] = { "lep1pt", "lep2pt", "lep1eta", "lep2eta", "mll", "mt", "ptll", "met", "phill"};
  TString cutTitle[nPlots] = { "lepton 1, p_{T}[GeV]", "lepton 2, p_{T}[GeV]", "lepton 1, #eta", "lepton 2, #eta", "m_{ll} [GeV]", "m_{T} [GeV]", "p_{T} (ll)[GeV]", "MET [GeV]", "#Delta#Phi_{ll} [Deg.]"}; 
 

  TH1D*  h0[2][nPlots];
  TH1D*  h1[2][nPlots];
  TH1D*  h2[5][nPlots];
  
  for (const int iPlot = 0; iPlot < nPlots; iPlot++){
    cout << cutLabel[iPlot] << endl;
    h0[0][iPlot] = (TH1D*) _file0->Get("histo_before_" + cutLabel[iPlot]+"_"+sampleLabel[0]+"_8TeV");
    h0[1][iPlot] = (TH1D*) _file0->Get("histo_before_" + cutLabel[iPlot]+"_"+sampleLabel[1]+"_8TeV");
          
    h1[0][iPlot] = (TH1D*) _file0->Get("histo_" + cutLabel[iPlot]+"_"+sampleLabel[0]+"_8TeV");
    h1[1][iPlot] = (TH1D*) _file0->Get("histo_" + cutLabel[iPlot]+"_"+sampleLabel[1]+"_8TeV");
    
    for (int i =0; i<5; i++){
      h2[i][iPlot] = (TH1D*) _file0->Get("histo_" + cutLabel[iPlot]+"_"+sampleLabel[i]+"_8TeV");
    }
     
        
    TCanvas *c1 = new TCanvas();
    h0[0][iPlot]->SetLineColor(kRed);
    h0[0][iPlot]->SetMarkerColor(kRed);
    h0[0][iPlot]->SetMarkerStyle(20);
    h0[0][iPlot]->SetMarkerSize(1);
    h0[1][iPlot]->SetMarkerStyle(20);
    h0[1][iPlot]->SetMarkerSize(1);
    h0[0][iPlot]->SetNormFactor(1);
    h0[1][iPlot]->SetNormFactor(1);
    double max = 1.3*(TMath::Max(h0[0][iPlot]->GetMaximum(), h0[1][iPlot]->GetMaximum()));
    h0[0][iPlot]->Draw("ehisto");
    h0[1][iPlot]->Draw("ehisto, sames");
    h0[0][iPlot]->GetYaxis()->SetRangeUser(0, max);
    h0[0][iPlot]->GetXaxis()->SetTitle(cutTitle[iPlot]);
    leg = new TLegend(0.60,0.80,0.99,0.99);
    leg->SetFillStyle(1001);
    leg->SetFillColor(kWhite);
    leg->SetBorderSize(1);
    leg->AddEntry(h0[0][iPlot], "Official SM sample", "l");
    leg->AddEntry(h0[1][iPlot], "JHU Gen SM sample", "l");
    leg->Draw();
    c1->SaveAs("plots/before_"+ cutLabel[iPlot]+ "_8TeV.png");
    
    TCanvas *c1 = new TCanvas();
    h1[0][iPlot]->SetLineColor(kRed);
    h1[0][iPlot]->SetMarkerColor(kRed);
    h1[0][iPlot]->SetMarkerStyle(20);
    h1[0][iPlot]->SetMarkerSize(1);
    h1[1][iPlot]->SetMarkerStyle(20);
    h1[1][iPlot]->SetMarkerSize(1);
    h1[0][iPlot]->SetNormFactor(1);
    h1[1][iPlot]->SetNormFactor(1);
    double max = 1.3*(TMath::Max(h1[0][iPlot]->GetMaximum(), h1[1][iPlot]->GetMaximum()));
    h1[0][iPlot]->Draw("ehisto");
    h1[1][iPlot]->Draw("ehisto, sames");
    h1[0][iPlot]->GetYaxis()->SetRangeUser(0, max);
    h1[0][iPlot]->GetXaxis()->SetTitle(cutTitle[iPlot]);
    leg = new TLegend(0.60,0.80,0.99,0.99);
    leg->SetFillStyle(1001);
    leg->SetFillColor(kWhite);
    leg->SetBorderSize(1);
    leg->AddEntry(h1[0][iPlot], "Official SM sample", "l");
    leg->AddEntry(h1[1][iPlot], "JHU Gen SM sample", "l");
    leg->Draw();
    c1->SaveAs("plots/"+ cutLabel[iPlot]+ "_8TeV.png");
    
    for (int i = 2; i<5; i++){
    
      TCanvas *c1 = new TCanvas();
      h2[0][iPlot]->SetLineColor(kRed);
      h2[0][iPlot]->SetMarkerColor(kRed);
      h2[0][iPlot]->SetMarkerStyle(20);
      h2[0][iPlot]->SetMarkerSize(1);
      h2[i][iPlot]->SetMarkerStyle(20);
      h2[i][iPlot]->SetMarkerSize(1);
      h2[0][iPlot]->SetNormFactor(1);
      h2[i][iPlot]->SetNormFactor(1);
      double max = 1.3*(TMath::Max(h2[0][iPlot]->GetMaximum(), h2[i][iPlot]->GetMaximum()));
      h2[0][iPlot]->Draw("ehisto");
      h2[i][iPlot]->Draw("ehisto, sames");
      h2[0][iPlot]->GetYaxis()->SetRangeUser(0, max);
      h2[0][iPlot]->GetXaxis()->SetTitle(cutTitle[iPlot]);
      leg = new TLegend(0.60,0.80,0.99,0.99);
      leg->SetFillStyle(1001);
      leg->SetFillColor(kWhite);
      leg->SetBorderSize(1);
      leg->AddEntry(h2[0][iPlot], "SM", "l");
      leg->AddEntry(h2[i][iPlot], sampleLabel[i], "l");
      leg->Draw();
      c1->SaveAs("plots/"+ cutLabel[iPlot]+ "_"+sampleLabel[i]+"_8TeV.png");
     
    
    
    }
    
  }


  
}
