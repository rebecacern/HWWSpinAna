#include "Math/VectorUtil.h"
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>
#include <iostream>
#include <fstream>
#include "TLegend.h"
#include "TPaveText.h"
#include "TRandom.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TSystem.h"

const int verboseLevel =   1;
const bool tau = true; //tau removal on/off

//Fixed quantities
const double mz = 91.1876;
const double mw = 80.4;
const double mmu = 0.105;
const double lumi8 = 19.365;
const double lumi7 = 4.924;

//kinamtic cuts
const double ptleadingcut = 30; //leading jet
const double separation = 15; //15 is the chosen cut
const double metcut = -10; 
const double mtcut = 85;
const double separationjj = 60; //60
const double phicut = 1.8; // 1.8

//Other
const double factor = 1; //Fake factor

//Syst. values 
double JESerr = 0.05; // 0.10 also

//Histos
int nbins = 20;
double nbinlow = 0;
double nbinhigh = 400;


double precision(double value){
  
  int precisionValue;
  if (value == 0) precisionValue = 0;
  else if (value < 10) precisionValue = 4;
  else precisionValue = 5;
  
  return precisionValue;
  
}

double Unroll2VarTo1VarVersion2(double mll, double mt){
double val = -1.;
if (mll > 12 && mll <= 30 && mt > 60 && mt <= 70) val = 1;
else if(mll > 30 && mll <= 45 && mt > 60 && mt <= 70) val = 2;
else if(mll > 45 && mll <= 60 && mt > 60 && mt <= 70) val = 3;
else if(mll > 60 && mll <= 75 && mt > 60 && mt <= 70) val = 4;
else if(mll > 75 && mll <= 100 && mt > 60 && mt <= 70) val = 5;
else if(mll > 100 && mll <= 125 && mt > 60 && mt <= 70) val = 6;
else if(mll > 125 && mll <= 150 && mt > 60 && mt <= 70) val = 7;
else if(mll > 150 && mll <= 175 && mt > 60 && mt <= 70) val = 8;
else if(mll > 175 && mll <= 200 && mt > 60 && mt <= 70) val = 9;
else if(mll > 12 && mll <= 30 && mt > 70 && mt <= 80) val = 10;
else if(mll > 30 && mll <= 45 && mt > 70 && mt <= 80) val = 11;
else if(mll > 45 && mll <= 60 && mt > 70 && mt <= 80) val = 12;
else if(mll > 60 && mll <= 75 && mt > 70 && mt <= 80) val = 13;
else if(mll > 75 && mll <= 100 && mt > 70 && mt <= 80) val = 14;
else if(mll > 100 && mll <= 125 && mt > 70 && mt <= 80) val = 15;
else if(mll > 125 && mll <= 150 && mt > 70 && mt <= 80) val = 16;
else if(mll > 150 && mll <= 175 && mt > 70 && mt <= 80) val = 17;
else if(mll > 175 && mll <= 200 && mt > 70 && mt <= 80) val = 18;
else if(mll > 12 && mll <= 30 && mt > 80 && mt <= 90) val = 19;
else if(mll > 30 && mll <= 45 && mt > 80 && mt <= 90) val = 20;
else if(mll > 45 && mll <= 60 && mt > 80 && mt <= 90) val = 21;
else if(mll > 60 && mll <= 75 && mt > 80 && mt <= 90) val = 22;
else if(mll > 75 && mll <= 100 && mt > 80 && mt <= 90) val = 23;
else if(mll > 100 && mll <= 125 && mt > 80 && mt <= 90) val = 24;
else if(mll > 125 && mll <= 150 && mt > 80 && mt <= 90) val = 25;
else if(mll > 150 && mll <= 175 && mt > 80 && mt <= 90) val = 26;
else if(mll > 175 && mll <= 200 && mt > 80 && mt <= 90) val = 27;
else if(mll > 12 && mll <= 30 && mt > 90 && mt <= 100) val = 28;
else if(mll > 30 && mll <= 45 && mt > 90 && mt <= 100) val = 29;
else if(mll > 45 && mll <= 60 && mt > 90 && mt <= 100) val = 30;
else if(mll > 60 && mll <= 75 && mt > 90 && mt <= 100) val = 31;
else if(mll > 75 && mll <= 100 && mt > 90 && mt <= 100) val = 32;
else if(mll > 100 && mll <= 125 && mt > 90 && mt <= 100) val = 33;
else if(mll > 125 && mll <= 150 && mt > 90 && mt <= 100) val = 34;
else if(mll > 150 && mll <= 175 && mt > 90 && mt <= 100) val = 35;
else if(mll > 175 && mll <= 200 && mt > 90 && mt <= 100) val = 36;
else if(mll > 12 && mll <= 30 && mt > 100 && mt <= 110) val = 37;
else if(mll > 30 && mll <= 45 && mt > 100 && mt <= 110) val = 38;
else if(mll > 45 && mll <= 60 && mt > 100 && mt <= 110) val = 39;
else if(mll > 60 && mll <= 75 && mt > 100 && mt <= 110) val = 40;
else if(mll > 75 && mll <= 100 && mt > 100 && mt <= 110) val = 41;
else if(mll > 100 && mll <= 125 && mt > 100 && mt <= 110) val = 42;
else if(mll > 125 && mll <= 150 && mt > 100 && mt <= 110) val = 43;
else if(mll > 150 && mll <= 175 && mt > 100 && mt <= 110) val = 44;
else if(mll > 175 && mll <= 200 && mt > 100 && mt <= 110) val = 45;
else if(mll > 12 && mll <= 30 && mt > 110 && mt <= 120) val = 46;
else if(mll > 30 && mll <= 45 && mt > 110 && mt <= 120) val = 47;
else if(mll > 45 && mll <= 60 && mt > 110 && mt <= 120) val = 48;
else if(mll > 60 && mll <= 75 && mt > 110 && mt <= 120) val = 49;
else if(mll > 75 && mll <= 100 && mt > 110 && mt <= 120) val = 50;
else if(mll > 100 && mll <= 125 && mt > 110 && mt <= 120) val = 51;
else if(mll > 125 && mll <= 150 && mt > 110 && mt <= 120) val = 52;
else if(mll > 150 && mll <= 175 && mt > 110 && mt <= 120) val = 53;
else if(mll > 175 && mll <= 200 && mt > 110 && mt <= 120) val = 54;
else if(mll > 12 && mll <= 30 && mt > 120 && mt <= 140) val = 55;
else if(mll > 30 && mll <= 45 && mt > 120 && mt <= 140) val = 56;
else if(mll > 45 && mll <= 60 && mt > 120 && mt <= 140) val = 57;
else if(mll > 60 && mll <= 75 && mt > 120 && mt <= 140) val = 58;
else if(mll > 75 && mll <= 100 && mt > 120 && mt <= 140) val = 59;
else if(mll > 100 && mll <= 125 && mt > 120 && mt <= 140) val = 60;
else if(mll > 125 && mll <= 150 && mt > 120 && mt <= 140) val = 61;
else if(mll > 150 && mll <= 175 && mt > 120 && mt <= 140) val = 62;
else if(mll > 175 && mll <= 200 && mt > 120 && mt <= 140) val = 63;
else if(mll > 12 && mll <= 30 && mt > 140 && mt <= 160) val = 64;
else if(mll > 30 && mll <= 45 && mt > 140 && mt <= 160) val = 65;
else if(mll > 45 && mll <= 60 && mt > 140 && mt <= 160) val = 66;
else if(mll > 60 && mll <= 75 && mt > 140 && mt <= 160) val = 67;
else if(mll > 75 && mll <= 100 && mt > 140 && mt <= 160) val = 68;
else if(mll > 100 && mll <= 125 && mt > 140 && mt <= 160) val = 69;
else if(mll > 125 && mll <= 150 && mt > 140 && mt <= 160) val = 70;
else if(mll > 150 && mll <= 175 && mt > 140 && mt <= 160) val = 71;
else if(mll > 175 && mll <= 200 && mt > 140 && mt <= 160) val = 72;
else if(mll > 12 && mll <= 30 && mt > 160 && mt <= 180) val = 73;
else if(mll > 30 && mll <= 45 && mt > 160 && mt <= 180) val = 74;
else if(mll > 45 && mll <= 60 && mt > 160 && mt <= 180) val = 75;
else if(mll > 60 && mll <= 75 && mt > 160 && mt <= 180) val = 76;
else if(mll > 75 && mll <= 100 && mt > 160 && mt <= 180) val = 77;
else if(mll > 100 && mll <= 125 && mt > 160 && mt <= 180) val = 78;
else if(mll > 125 && mll <= 150 && mt > 160 && mt <= 180) val = 79;
else if(mll > 150 && mll <= 175 && mt > 160 && mt <= 180) val = 80;
else if(mll > 175 && mll <= 200 && mt > 160 && mt <= 180) val = 81;
else if(mll > 12 && mll <= 30 && mt > 180 && mt <= 200) val = 82;
else if(mll > 30 && mll <= 45 && mt > 180 && mt <= 200) val = 83;
else if(mll > 45 && mll <= 60 && mt > 180 && mt <= 200) val = 84;
else if(mll > 60 && mll <= 75 && mt > 180 && mt <= 200) val = 85;
else if(mll > 75 && mll <= 100 && mt > 180 && mt <= 200) val = 86;
else if(mll > 100 && mll <= 125 && mt > 180 && mt <= 200) val = 87;
else if(mll > 125 && mll <= 150 && mt > 180 && mt <= 200) val = 88;
else if(mll > 150 && mll <= 175 && mt > 180 && mt <= 200) val = 89;
else if(mll > 175 && mll <= 200 && mt > 180 && mt <= 200) val = 90;
else if(mll > 12 && mll <= 30 && mt > 200 && mt <= 220) val = 91;
else if(mll > 30 && mll <= 45 && mt > 200 && mt <= 220) val = 92;
else if(mll > 45 && mll <= 60 && mt > 200 && mt <= 220) val = 93;
else if(mll > 60 && mll <= 75 && mt > 200 && mt <= 220) val = 94;
else if(mll > 75 && mll <= 100 && mt > 200 && mt <= 220) val = 95;
else if(mll > 100 && mll <= 125 && mt > 200 && mt <= 220) val = 96;
else if(mll > 125 && mll <= 150 && mt > 200 && mt <= 220) val = 97;
else if(mll > 150 && mll <= 175 && mt > 200 && mt <= 220) val = 98;
else if(mll > 175 && mll <= 200 && mt > 200 && mt <= 220) val = 99;
else if(mll > 12 && mll <= 30 && mt > 220 && mt <= 240) val = 100;
else if(mll > 30 && mll <= 45 && mt > 220 && mt <= 240) val = 101;
else if(mll > 45 && mll <= 60 && mt > 220 && mt <= 240) val = 102;
else if(mll > 60 && mll <= 75 && mt > 220 && mt <= 240) val = 103;
else if(mll > 75 && mll <= 100 && mt > 220 && mt <= 240) val = 104;
else if(mll > 100 && mll <= 125 && mt > 220 && mt <= 240) val = 105;
else if(mll > 125 && mll <= 150 && mt > 220 && mt <= 240) val = 106;
else if(mll > 150 && mll <= 175 && mt > 220 && mt <= 240) val = 107;
else if(mll > 175 && mll <= 200 && mt > 220 && mt <= 240) val = 108;
else if(mll > 12 && mll <= 30 && mt > 240 && mt <= 260) val = 109;
else if(mll > 30 && mll <= 45 && mt > 240 && mt <= 260) val = 110;
else if(mll > 45 && mll <= 60 && mt > 240 && mt <= 260) val = 111;
else if(mll > 60 && mll <= 75 && mt > 240 && mt <= 260) val = 112;
else if(mll > 75 && mll <= 100 && mt > 240 && mt <= 260) val = 113;
else if(mll > 100 && mll <= 125 && mt > 240 && mt <= 260) val = 114;
else if(mll > 125 && mll <= 150 && mt > 240 && mt <= 260) val = 115;
else if(mll > 150 && mll <= 175 && mt > 240 && mt <= 260) val = 116;
else if(mll > 175 && mll <= 200 && mt > 240 && mt <= 260) val = 117;
else if(mll > 12 && mll <= 30 && mt > 260 && mt <= 280) val = 118;
else if(mll > 30 && mll <= 45 && mt > 260 && mt <= 280) val = 119;
else if(mll > 45 && mll <= 60 && mt > 260 && mt <= 280) val = 120;
else if(mll > 60 && mll <= 75 && mt > 260 && mt <= 280) val = 121;
else if(mll > 75 && mll <= 100 && mt > 260 && mt <= 280) val = 122;
else if(mll > 100 && mll <= 125 && mt > 260 && mt <= 280) val = 123;
else if(mll > 125 && mll <= 150 && mt > 260 && mt <= 280) val = 124;
else if(mll > 150 && mll <= 175 && mt > 260 && mt <= 280) val = 125;
else if(mll > 175 && mll <= 200 && mt > 260 && mt <= 280) val = 126;
else return -2.0;
val = val - 0.00001;
val = (val/126.-0.5)*2.0;
return val;
}

