#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<map>
#include"parseScoringFile.h"

using namespace std;
vector< vector<int> > parseScoringFile(string filepath)
{
  fstream Input;
  Input.open(filepath,fstream::in);
  vector<int> temp;
  vector< vector<int> > Scoredata;
  char buff[500];
  while(Input.getline(buff,500,','))
    {
      temp.push_back(stoi(buff));
      Input.getline(buff,500,',');

      temp.push_back(stoi(buff));
      Input.getline(buff,500,',');
      temp.push_back(stoi(buff));

      Input.getline(buff,500);
      temp.push_back(stoi(buff));

      Scoredata.push_back(temp);
      temp.clear();

    }
  return Scoredata;
}
