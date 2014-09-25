#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int rowA=0;int rowB=0;int columnA=0;int columnB=0;//set up rows and columns
  // cout<<"Enter Matrix A's row number"<<endl;
  cin>>rowA;//input row number of Matrix A
  // cout<<"Enter Matrix B's row number"<<endl;
  cin>>rowB;//input row number of Matrix B
  // cout<<"Enter Matrix A's column number"<<endl;
  cin>>columnA;//input column number of Matrix A
  // cout<<"Enter Matrix B's column number"<<endl;
  cin>>columnB;//input column number of Matrix B
  if(rowA==0||rowB==0||columnA==0||columnB==0)//judge whether the matrix is null or not
    {
      cout<<"Invalid  matrix form  please try again"<<endl;
      return 1;
    }
  else if(rowB!=columnA)//judge whether the two matrix can multiple or not
    {
      cout<<"Invalid input"<<endl;
      return 1;
    }
  else
    {
      vector<vector<double> > A(rowA,vector<double>(columnA));//set up the size of matrix A
      vector<vector<double> > B(rowB,vector<double>(columnB));//set up the size of matrix B
      vector<vector<double> > C(rowA,vector<double>(columnB));//set up the size of matrix C
     
      //cout<<"Enter the element of Matrix A"<<endl;//input the element of Matrix A
      for(int i=0;i<rowA;i++)
	{
	  for(int j=0;j<columnA;j++)
	    {
	      cin>>A[i][j];
	    }
	}

      // cout<<"Enter the element of Matrix B"<<endl;//input the element of Matrix B

      for(int i=0;i<rowB;i++)
	{
	  for(int j=0;j<columnB;j++)
	    {
	      cin>>B[i][j];
	    }
	}

      for(int i=0;i<rowA;i++)//caculate using matrix multiple principle
	{
	  for(int j=0;j<columnB;j++)
	    {
	     double  temp=0;
	      for(int k=0;k<rowB;k++)
		{
		  temp+=A[i][k]*B[k][j];
		}
	      C[i][j]=temp;
	    }
	}
      cout<<endl;
      // cout<<"the Matrix A is : "<<endl;//display matrix A

       for(int i=0;i<rowA;i++)
      	{
        for(int j=0;j<columnA;j++)
        {
        cout<<A[i][j]<<" ";
       }
       cout<<endl;
      	}
       cout<<endl;
       // cout<<"the Matrix B is : "<<endl;//display matrix B
       for(int i=0;i<rowB;i++)
      	{
        for(int j=0;j<columnB;j++)
          {
            cout<<B[i][j]<<" ";
          }
        cout<<endl;
      	}
       cout<<endl;
       // cout<<"the Matrix C is : "<<endl;//display matrix C
       for(int i=0;i<rowA;i++)
      	{
        for(int j=0;j<columnB;j++)
        {
          cout<<C[i][j]<<" ";
        }
        cout<<endl;
      	}
    }
  return 0;
}
