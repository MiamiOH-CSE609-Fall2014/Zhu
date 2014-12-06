#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<math.h> 
#include<ctime> 
#include<iomanip> 
#include"Game.h"
using namespace std;
Game::Game()                   
{ 
  num=0; 
  win=0; 
  fail=0; 
  draw=0; 
} 
void Game::welcome()                                                                           
{ 
  cout<<"****************************************************\n"; 
  cout<<"   welcome to Casino BlackJack 21"<<endl; 
  cout<<"   game rules:"<<endl;; 
  cout<<" 1.Player can take at most 5 cards\n"; 
  cout<<" 2.If the total points of cards is over 21, then busting"<<endl; 
  cout<<" 3.'J','Q','K', are 10 point and 'A' is 1 or 11\n"<<endl;
  cout<<" 4.'S' stands for 'Spade','H' stands for 'Heart','D' stands for 'Diamond,'C' stands for 'Ciud'\n"<<endl;;  
  cout<<"good luck to you!"<<endl; 
  cout<<"*****************************************************\n"<<endl; 
} 
void Game::first_two()                                                           
{   
  cards[num]=rand()%13+1; 
  num++; 
} 
void Game::hit_cards()                                                              
{ 
  // int judge; 
  //  do                                                                       
  // { 
  // panduan=0;                                                             
  // huase[number]=rand()%4+3; 
  cards[num]=rand()%13+1; 
  // for(int i=0;i<number;i++) 
  //if(huase[number]==huase[i]&&ppai[number]==ppai[i]) 
  //  panduan=1; 
  // }while(panduan); 
  num++; 
} 
void Game::hit()                                                            
{ 
  if(cards[num-1]==1) 
    cout<<"  A"; 
  else if(cards[num-1]==11) 
    cout<<"  J"; 
  else if(cards[num-1]==12) 
    cout<<"  Q"; 
  else if(cards[num-1]==13) 
    cout<<"  K"; 
  else 
    cout<<"  "<<cards[num-1]; 
} 
char Game::getsuit()                                          
{ 
  char temp;
  
  vector<char> cs={'S','H','C','D'};
 
  temp=cs[rand()%4]; 
  return temp; 
} 
void Game::inform()                                                       
{  
  for(int i=0;i<num;i++) 
    { 
      if(cards[i]==1) 
	cout<<setw(3)<<"A"; 
      else if(cards[i]==11) 
	cout<<setw(3)<<"J"; 
      else if(cards[i]==12) 
	cout<<setw(3)<<"Q"; 
      else if(cards[i]==13) 
	cout<<setw(3)<<"k"; 
      else 
	cout<<setw(3)<<cards[i]; 
    } 
} 
int Game::C_number()                                                          
{ 
  return num;
} 

float Game::total_point()                                                     
{ 
  int i; 
  float total=0; 
  for(i=0;i<num;i++) 
    { 
      if(cards[i]==1) 
	total=total+11; 
      else if(cards[i]<=10) 
	total=total+cards[i]; 
      else 
	total=total+10; 
    } 
  for(i=0;i<num;i++) 
    { 
      if(cards[i]==1&&total>21) 
	total=total-10; 
      if(total<=21) 
	break; 
    } 
  return total; 
} 
void Game::win_num()                                                               
{ 
  win++; 
} 
void Game::fail_num()                                                               
{ 
  fail++; 
} 
void Game::draw_num()                                                               
{  
  draw++; 
} 
void Game::print()                                                              
{ 
  cout<<"\n··························"<<endl; 
  cout<<"Win"<<win<<"case,"<<"Lose"<<fail<<"case,"<<"Draw"<<draw<<"case."<<endl<<endl; 
  cout<<"··························"<<endl; 
} 
