#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
#include<math.h>
#include<stdio.h>
#include<cstdlib>
#include<iomanip>

using namespace std;
//set up sum average value and standard deviation
double sum=0.0;
double avg=0.0;//average value
double std_dev=0.0;//standard deviation
//set up vector for store data of name scores and grade 
vector<string> name_list;
vector<double> scores_list;
vector<char> grade_list;

string name;
double score=0.0;
//function for input student's information including name and score
void input_inf()
{
while(true)
  {
  try
    {

    
  cout<<"Enter the student's name or enter 'none' to quit: \n";
    getline(cin,name);
    // if name is none, out of the loop 
    if (name=="none")
      {
   break;
    }
    
    cout<<"Enter the score:\n";
    cin>>score;
    if(cin.fail())
      {
	cin.clear();
	cin.ignore();
	throw out_of_range("invalid score input");
      }
    cin.ignore();
    // set the out of range error make score between 0-100
    if(score<0.0||score>100.0)
      {
	throw out_of_range("Score should be between 0 to 100");
      }
    name_list.push_back(name);
    scores_list.push_back(score);
  }
  catch(out_of_range)
    {
      cout<<"Range error,please re-enter name and score"<<endl;
    } 
  }
}
//function for calculating the and value the grade of student
char grade_out(double st_score)
{
  if(st_score>=(avg+(1.5*std_dev)))
   
    { return 'A';}
  else if(st_score>=(avg+(0.5*std_dev)) && st_score<(avg+(1.5*std_dev)))
  { return 'B';}
  else if(st_score>=(avg+(-0.5*std_dev) )&& st_score<(avg+(0.5*std_dev)))
  { return 'C';}
  else if(st_score>=(avg+(-1.5*std_dev)) && st_score<(avg+(-0.5*std_dev)))
    { return 'D';}
  else if(st_score<(avg+(-1.5*std_dev)))
    return 'F';
}


int main()
{
  input_inf();
  //calculate average value 
  for(int i=0;i<scores_list.size();i++)
    {
sum+=scores_list[i];
    }
  avg=sum/scores_list.size();
  // calculate standard deviation value
  for(int i=0;i<scores_list.size();i++)
    {
      std_dev+=pow((scores_list[i]-avg),2);
    }
  std_dev=sqrt(std_dev/scores_list.size());

 
  cout<<"Grading scale"<<endl;
  if(avg+(1.5*std_dev)>100)
    {
      cout<<"A above 100.0%"<<endl;
    }
  else
    {
      printf("A above %.1f%%\n",(avg+(1.5*std_dev)));
      printf("B %.1f%% - %.1f%%\n",(avg+(0.5*std_dev)),(avg+(1.5*std_dev)));
      printf("C %.1f%% - %.1f%%\n",(avg+(-0.5*std_dev)),(avg+(0.5*std_dev)));
      printf("D %.1f%% - %.1f%%\n",(avg+(-1.5*std_dev)),(avg+(-0.5*std_dev)));
      printf("F below %.1f%%\n\n",(avg+(-1.5*std_dev)));
    }
  // store student's grade to vector
for(int i=0;i<scores_list.size();i++)
  {
    grade_list.push_back(grade_out(scores_list[i]));
  }
printf("\n\n\n");
string stname=" ";
string stgrade;
printf("   Name\t\t Score\t\tGrade\n");
//print out the list of grade
for(int i=0;i<scores_list.size();i++)
  {
    stname=name_list[i];
    stgrade=grade_list[i];
    printf("%d. %-15s%.1f%%\t\t%s\n",i+1,stname.c_str(),scores_list[i],stgrade.c_str());
  }
 printf("\n\n");
 printf("Class Average \t =\t%.2f%%\nStandard Deviation =\t%.2f\n",avg,std_dev);

return 0;
}
