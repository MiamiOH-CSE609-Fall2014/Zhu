#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include<stdlib.h>
#include"digramFreqMatrix.h"

using namespace std;
vector< vector<int> > digramFreqMatrix(map<string,int> frequence)
{
  vector< vector<int> > frequence_Matrix;
  vector<int> vect_A,vect_G,vect_C,vect_T;
  vect_A.push_back(frequence["AA"]);
  vect_A.push_back(frequence["AG"]);
  vect_A.push_back(frequence["AC"]);
  vect_A.push_back(frequence["AT"]);
  frequence_Matrix.push_back(vect_A);

  vect_G.push_back(frequence["GA"]);
  vect_G.push_back(frequence["GG"]);
  vect_G.push_back(frequence["GC"]);
  vect_G.push_back(frequence["GT"]);
  frequence_Matrix.push_back(vect_G);

  vect_C.push_back(frequence["CA"]);
  vect_C.push_back(frequence["CG"]);
  vect_C.push_back(frequence["CC"]);
  vect_C.push_back(frequence["CT"]);
  frequence_Matrix.push_back(vect_C);

  vect_T.push_back(frequence["TA"]);
  vect_T.push_back(frequence["TG"]);
  vect_T.push_back(frequence["TC"]);
  vect_T.push_back(frequence["TT"]);
  frequence_Matrix.push_back(vect_T);
  return frequence_Matrix;
}




 
