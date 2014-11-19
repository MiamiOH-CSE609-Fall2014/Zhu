#include<iostream>
#include<string>
#include<map>
#include<vector>
#include"scoreSequence.h"

using namespace std;
pair<int,int> scoreSequence(string haystack,string needle,vector< vector<int> > score_Matrix)
{
pair<int,int> Max_score={0,0};
int tempscore,totalscore;
string hayPart;
map<char,int> gene_rank={{'A',0},{'G',1},{'C',2},{'T',3}};

     int length=haystack.length()-needle.length();
     for (int i=0;i<length+1;i++)
       {
	 totalscore=0;tempscore=0;
	 hayPart=haystack.substr(i,needle.length());
	 for(int i=0;i<needle.length();i++)
	   {
	     tempscore=score_Matrix[gene_rank[hayPart[i]]][gene_rank[needle[i]]];
	     totalscore+=tempscore;
	   }
	 if(totalscore>=Max_score.second)
	   {
	     Max_score.first=i;
	     Max_score.second=totalscore;
	   }
       }
     return Max_score;
    }
