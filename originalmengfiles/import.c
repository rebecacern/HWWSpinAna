//#include "HZZ4L_RooSpinZeroPdf.cc+"
//#include "RooWorkSpace.h"
//#include "TFile.h"
//#include "RooRealVar.h"
using namespace RooFit;
void import(){
 gROOT->ProcessLine("gSystem->AddIncludePath(\"-I$ROOFITSYS/include/\")");
  gROOT->ProcessLine("gSystem->Load(\"libRooFit\")");
  gROOT->ProcessLine("gSystem->Load(\"libHiggsAnalysisCombinedLimit.so\")");
//TFile *f =new TFile("test2.root","recreate");
TString namebox[13]={
"",
"CMS_hww_MVALepEffBoundingUp",
"CMS_hww_MVALepResBoundingUp",
"CMS_hww_MVAMETResBoundingUp",
"CMS_hww_MVAJESBoundingUp",
//"CMS_hwwof_0j_MVAggH_ALTStatBounding_7TeVUp",
//"CMS_hwwof_0j_MVAggHStatBounding_7TeVUp",
"CMS_hwwof_0j_MVAggH_ALTStatBounding_8TeVUp",
"CMS_hwwof_0j_MVAggHStatBounding_8TeVUp",
"CMS_hww_MVALepEffBoundingDown",
"CMS_hww_MVALepResBoundingDown",
"CMS_hww_MVAMETResBoundingDown",
"CMS_hww_MVAJESBoundingDown",
//"CMS_hwwof_0j_MVAggH_ALTStatBounding_7TeVDown",
//"CMS_hwwof_0j_MVAggHStatBounding_7TeVDown"
"CMS_hwwof_0j_MVAggH_ALTStatBounding_8TeVDown",
"CMS_hwwof_0j_MVAggHStatBounding_8TeVDown"
};

        RooWorkspace w("w");
TFile *fh = new TFile("hwwof_0j.input_8TeV.root","read");
RooRealVar x ("CMS_zz4l_fg4","CMS_zz4l_fg4",-1,1);
RooRealVar D1 ("CMS_th1x","CMS_th1x",0, 126);
for (int k =0;k<13;k++){
cout<<k<<endl;
TString hisname1 = "_"+namebox[k];
TString hisname2 = "_"+namebox[k];
TString hisname = "_"+namebox[k];
if(hisname.Contains("StatBounding")){
	if(hisname.Contains("ALT"))
		hisname1=namebox[0];
	else
		hisname2=namebox[0];
}
if(k==0)
{
hisname1=namebox[k];
hisname2=namebox[k];

}

TH1F *T1_o = (TH1F*)fh->Get("histo_ggH"+hisname1);
TH1F *T2_o = (TH1F*)fh->Get("histo_ggH_ALT"+hisname2);
TH1F *T3_o = (TH1F*)fh->Clone("histo_int");

T3_o->Reset();
TH1F *T1= new TH1F("histo_ggH_rebin"+hisname,"",126,0,126);
TH1F *T2= new TH1F("histo_ggH_ALT_rebin"+hisname,"",126,0,126);
TH1F *T3= new TH1F("histo_ggH_int_rebin"+hisname,"",126,0,126);
for (int i=0;i<126;i++){
T1->SetBinContent(i+1,T1_o->GetBinContent(i+1));
T2->SetBinContent(i+1,T2_o->GetBinContent(i+1));
T3->SetBinContent(i+1,T3_o->GetBinContent(i+1));
}
//cout<<T1->Integral()<<" "<<T2->Integral()<< " "<<T3->Integral()<<endl;
//TFile *f= new TFile("fixedMu.root","read");
//RooWorkSpace *wold = (RooWorkSpace)
//RooDataHist *hist1 = 
  float dLowX = T1->GetXaxis()->GetXmin();
  float dHighX = T1->GetXaxis()->GetXmax();
//D1.setBins(126);
RooDataHist *hist1 = new RooDataHist("hist1"+hisname,"hist1"+hisname,RooArgList(D1),T1);
RooDataHist *hist2 = new RooDataHist("hist2"+hisname,"hist2"+hisname,RooArgList(D1),T2);
RooDataHist *hist3 = new RooDataHist("hist2"+hisname,"hist2"+hisname,RooArgList(D1),T3);
        RooHistFunc *histfunc1 = new RooHistFunc("histfunc1"+hisname,"histfunct1"+hisname,RooArgSet(D1),*hist1);
        RooHistFunc *histfunc2 = new RooHistFunc("histfunc2"+hisname,"histfunct2"+hisname,RooArgSet(D1),*hist2);
        RooHistFunc *histfunc3 = new RooHistFunc("histfunc3"+hisname,"histfunct3"+hisname,RooArgSet(D1),*hist3);
   HZZ4L_RooSpinZeroPdf *ggHpdf = new HZZ4L_RooSpinZeroPdf("ggH"+hisname,"ggH"+hisname,D1,x,RooArgList(*histfunc1,*histfunc2,*histfunc3));
	x.setVal(0);
	cout<<ggHpdf->getVal()<<endl;

	x.setVal(1);
	cout<<ggHpdf->getVal()<<endl;
w.import(*ggHpdf,RecycleConflictNodes());
}
w.writeToFile("test2.root");
 //       f->cd();
 //       w.Write();
 //       f->Close();
}
