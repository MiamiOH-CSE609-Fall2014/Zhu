#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
#include<tuple>
#include<stdlib.h>
#include<map>
#include"parseFastaFile.h"

using namespace std;
tuple<string,vector<string>,string> parseFastaFile(string filepath)
{
  fstream Input;
  string header,sequence;
  vector<string> comments;
  Input.open(filepath,fstream::in);
  char buff[500];
  while(Input.getline(buff,500))
    {
      if(buff[0]=='>')
	{
	  header=buff;
	}
      else if(buff[0]==';')
	{
	  comments.push_back(buff);
	}
      else
	{
	  sequence=sequence+buff;
	}
    }
  tuple<string,vector<string>,string> DNA_data{header,comments,sequence};
  return DNA_data;
}
