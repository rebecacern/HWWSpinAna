//Rebeca Gonzalez Suarez
//rebeca@cern.ch

#include "TH1.h"
#include "TH2.h"
#include "TKey.h"
#include "TFile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "inputs.h"


using namespace std;
void datacardmaker(bool regular = true){

  const int np = 18;
  TString processName[np] =  { "qqbarH_ALT", "ggH_ALT", "ZH", "WH", "qqH", "ggH", "qqWW", "ggWW", "VV", "Top", "Zjets", "WjetsE", "Wgamma", "Wg3l", "Ztt", "WjetsM", "qqWW2j", "Data"};
 
  char rootFile[300];
  sprintf(rootFile,"../fa3/0m/hwwof_0j.input_8TeV.root");
 
  
  TFile *_file0 = TFile::Open(rootFile);
  
  TH1F*  h[np];
  for (int i = 0; i < np; i++){
    h[i] = (TH1F*) _file0->Get("histo_"+ processName[i]);
  }
 
  char datacardFile[300]; 
  
  if (regular) sprintf(datacardFile,"../fa3/0m/hwwof_0j_new.txt");
  else sprintf(datacardFile,"../fa3/0m/hwwof_0j_inter.txt");
 

  ofstream datacard(datacardFile); 
  
  datacard << "imax 1 number of channels" << endl;
  datacard << "jmax * number of background" << endl;
  datacard << "kmax * number of nuisance parameters" << endl;
  datacard << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
  datacard << "Observation " << h[np-1]->Integral() << endl;
  datacard << "shapes *   *  " ;
  datacard << "hwwof_0j.input_8TeV.root  histo_$PROCESS histo_$PROCESS_$SYSTEMATIC" << endl;
  datacard << "shapes data_obs * hwwof_0j.input_8TeV.root  histo_Data " << endl;
  if (!regular) datacard << "shapes ggH ch1 rootfiles/test.root w:ggH_ w:$PROCESS_$SYSTEMATIC" << endl;
  datacard << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
  
  datacard << "bin\t\t\t\t\t\t\t" ;
  for (int i = 0; i < np -1; i++) { datacard << "j0of8tev\t";} 
  datacard << endl;
  datacard << "process\t\t\t\t\t\t\t";
  for (int i = 0; i < np -1; i++) { datacard << processName[i] << "\t" ;} 
  datacard << endl;
  datacard << "process\t\t\t\t\t\t\t";
  for (int i = 0; i < np -1; i++) { datacard << i-5 << "\t";} 
  datacard << endl;
  datacard << "rate\t\t\t\t\t\t\t" ;
  for (int i = 0; i < np -1; i++) { if (i<5 && !regular)  datacard << "0\t" ; else datacard << setprecision(precision(h[i]->Integral())) << h[i]->Integral() << "\t";}
  datacard << endl;
  
   datacard << "----------------------------------------------------------------------------------------------------------------------------------" << endl;
 
  
 
  datacard << "lumi_8TeV\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i!=0 && i!=2 && i!=3 && i!=4 && i!=np-3 && i!=np-7 && i!=np-8 && i!=np-9) datacard << "1.026\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVALepEffBounding\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || (i==5 && regular) || i==6 || i==7 || i == 4 || i==16) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
    
  datacard << "CMS_hww_MVALepResBounding\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || (i==5 && regular) || i==6 || i==7 || i==8 || i==9 || i==16) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVAMETResBounding\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || (i==5 && regular) || i==6 || i==7 || i == 4 || i== 5 || i==16) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  if (!regular){
  /////////////  
  //Shape1
  datacard << "CMS_hww_MVALepEffBounding\t\tshape1\t\t";
  for (int i = 0; i < np -1; i++) { if (i==5) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
    
  datacard << "CMS_hww_MVALepResBounding\t\tshape1\t\t";
  for (int i = 0; i < np -1; i++) { if (i==5)  datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVAMETResBounding\t\tshape1\t\t";
  for (int i = 0; i < np -1; i++) { if (i==5)  datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  /////////////
  }
  
  datacard << "CMS_hww_MVAJESBounding\t\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || (i==5 && regular)|| i==6 || i==7 || i==8 || i==9 || i==16) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  if (!regular){
  /////////////  
  //Shape1
  datacard << "CMS_hww_MVAJESBounding\t\t\tshape1\t\t";
  for (int i = 0; i < np -1; i++) { if (i==5) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  /////////////  
  }
  
  datacard << "FakeRate_e\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==10) datacard << "1.360\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "FakeRate_m\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==15) datacard << "1.360\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVAWEBounding\t\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==11) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVAWMBounding \t\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==15) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "UEPS\t\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || i==5) datacard << "0.940\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "interf_ggH\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || i==5) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "pdf_gg\t\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || i==5) datacard << "1.072\t"; else datacard << "-\t";}
  datacard << endl;
    
  datacard << "pdf_qqbar\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==8 || i==12 || i==13) datacard << "1.040\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_PDFggWW\t\t\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==7) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_PDFqqWW\t\t\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==6) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_ggH\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || i==5) datacard << "1.160\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_ggH1in\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || i==5) datacard << "0.920\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_ggH2in\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || i==5) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;

  datacard << "QCDscale_qqH\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==5) datacard << "1.010\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_WW2j\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==16) datacard << "1.360555\t"; else datacard << "-\t";}
  datacard << endl;
   
  datacard << "QCDscale_VV\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==8) datacard << "1.040\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_Vgamma\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==12) datacard << "1.300\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww2l2n_QCDscale_ggVV\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==7) datacard << "1.300\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_WW_EXTRAP\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==7) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_ggH_ACCEPT\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1 || i==5) datacard << "1.020\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_qqH_ACCEPT\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { datacard << "-\t";}
  datacard << endl;
  
  datacard << "QCDscale_VH_ACCEPT\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_0j_ttbar_8TeV\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==9) datacard << "1.137\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_Z_8TeV\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==10) datacard << "1.000\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_0j_WW_8TeV_SHAPE\t\tlnU\t\t";
  for (int i = 0; i < np -1; i++) { if (i==6) datacard << "2.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_Wg3l\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==13) datacard << "1.400\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_Ztt\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==14) datacard << "1.100\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "BRhiggs_hvv\t\t\t\tlnN\t\t";
  for (int i = 0; i < np -1; i++) { if (i==1) datacard << "1.0423\t"; else datacard << "-\t";}
  datacard << endl;
  
  
  datacard << "CMS_hww_MVATopBounding\t\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==9) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVAWWBounding\t\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==6) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVAWWNLOBounding\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==6) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hww_MVAWWNLOBounding\t\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==6) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAggH_ALTStatBounding_8TeV\tshape\t";
  for (int i = 0; i < np -1; i++) { if (i==1) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  if (regular){
  datacard << "CMS_hwwof_0j_MVAggHStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==5) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  } else {
  /////////////  
  //Shape1
  datacard << "CMS_hwwof_0j_MVAggHStatBounding_8TeV\tshape1\t\t";
  for (int i = 0; i < np -1; i++) { if (i==5) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  ///////////// 
  }
  datacard << "CMS_hwwof_0j_MVAqqWWStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==6) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAggWWStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==7) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAVVStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==8) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVATopStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==9) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAZjetsStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==10) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAWjetsEStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==11) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAWgammaStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==12) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAWg3lStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==13) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAZttStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==14) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAWjetsMStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==15) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  
  datacard << "CMS_hwwof_0j_MVAqqWW2jStatBounding_8TeV\tshape\t\t";
  for (int i = 0; i < np -1; i++) { if (i==16) datacard << "1.0\t"; else datacard << "-\t";}
  datacard << endl;
  



}
