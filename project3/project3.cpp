#include<iostream>
#include<cstdlib>
#include<vector>
#include<map>
#include<iterator>
#include<string>
#include<stdlib.h>
#include<list>
#include<fstream>
#include<tuple>
#include"parseFastaFile.h"
#include"digramFreqMatrix.h"
#include"digramFreqScores.h"
#include"parseScoringFile.h"
#include"scoreSequence.h"
#include"findHighScore.h"

using namespace std;
void display_Matrix(vector< vector<int> > matrix)
{
  cout<<endl;
  cout<<"  A  G  C  T"<<"\n";
  int g=1;
  for(int i = 0; i < 4; i++)
    {  
      if(g==1)
{
cout<<"A ";
      }
      else  if(g==2)
	{cout<<"G ";}
      else  if(g==3){
	cout<<"C ";}
      else  if(g==4)
	{cout<<"T ";}
      for(int j = 0; j < 4; j++)
	{
	  cout<<matrix[i][j]<<" ";

	}
      cout<<"\n";
      g++;
    }
           
}

int main(int argc, char** argv)
{
  string file=" ";
  file=argv[1];
  tuple<string,vector<string>,string>DNA_data=parseFastaFile(file); 
  display_Matrix(digramFreqMatrix(digramFreqScores(get<2>(DNA_data))));
  
  string scorepath=" ";
  scorepath=argv[2];
  vector<vector<int> > score_Matrix;
  score_Matrix=parseScoringFile(scorepath);
  display_Matrix(score_Matrix);


  cout<<"How many sequences would you like to score? "<<endl;
  int sequence_number;
  cin>>sequence_number;
  string s_sequence;
  vector<string> sequence;
  for(int i=0;i<sequence_number;i++)
{
  cout<<"Enter the sequence "<<i+1<<":"<<endl;
    cin>>s_sequence;
    sequence.push_back(s_sequence);
    s_sequence="";
  }

  tuple<int,int,string> highscore;
  highscore=findHighScore(get<2>(DNA_data),sequence,score_Matrix);
  cout<<"The Sequence is\n";
  cout<<get<2>(highscore)<<"\n";
  cout<<"\nThe Score is:  "<<get<1>(highscore)<<" at position : "<<get<0>(highscore)<<"\n";
  cout<<"The needle which produces the maximum score among the needles: "<<get<2>(highscore);
  cout<<"\n";

  return 0;
}
