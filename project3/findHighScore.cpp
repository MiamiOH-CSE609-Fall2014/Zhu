#include<iostream>
#include<string.h>
#include<vector>
#include<tuple>
#include"findHighScore.h"
#include"scoreSequence.h"

using namespace std;
tuple<int,int,string> findHighScore(string haystack,vector<string> needle,vector< vector<int> > score_Matrix)
{
  tuple<int,int,string> highscore;
  pair<int,int> tempscore;

  for(int i=0;i<needle.size();i++)
    {
      tempscore=scoreSequence(haystack,needle[i],score_Matrix);

      if(tempscore.second>get<1>(highscore))
        {
          get<0>(highscore)=tempscore.first;
          get<1>(highscore)=tempscore.second;
          get<2>(highscore)=needle[i];
        }
    }

  return highscore;
}
