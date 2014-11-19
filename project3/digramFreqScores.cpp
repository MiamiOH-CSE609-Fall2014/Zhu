#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include<iterator>
#include<map>
#include"digramFreqScores.h"

using namespace std;
map<string,int> digramFreqScores(string sequence)
{
  map<string,int> frequence={
      
	{"AA",0},{"AC",0},{"GT",0},
	{"AG",0},{"CC",0},{"CA",0},
	{"CG",0},{"TT",0},{"GG",0},
	{"GC",0},{"AT",0},{"GA",0},
	{"TG",0},{"TA",0},{"TC",0},
	{"CT",0}
      };
  for(int i=1;i<sequence.size();i++)
    {
      ++frequence[sequence.substr(i-1,2)];
    }
  return frequence;
}
