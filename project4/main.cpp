#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<math.h> 
#include<ctime> 
#include<iomanip>
#include"Game.h" 
using namespace std;
void judgegame(Game&player,Game&computer)                                             
{ 
  cout<<"··························"<<endl<<endl; 
  cout<<"All your cards："; 
  player.inform(); 
  cout<<"      Total points："<<player.total_point()<<endl<<endl; 
  cout<<"CPU's cards："; 
  computer.inform(); 
  cout<<"       Total points："<<computer.total_point()<<endl<<endl; 
  if((player.total_point()>21&&computer.total_point()>21)||(player.total_point()==computer.total_point())) 
    { 
      cout<<"Duce!"<<endl; 
      player.draw_num(); 
    } 
  else if(player.total_point()>21) 
    { 
      cout<<"Busting!!!"<<endl; 
      player.fail_num(); 
    } 
  else if(computer.total_point()>21) 
    { 
      cout<<"You Win!!!"<<endl; 
      player.win_num(); 
    } 
  else if(player.total_point()>computer.total_point()) 
    { 
      cout<<"You Win!!!"<<endl; 
      player.win_num(); 
    } 
  else 
    { 
      cout<<"You Lose!"<<endl; 
      player.fail_num(); 
    } 
} 
void playpai(Game&player,Game&computer)                                           
{ 
  char judge='y'; 
  int pjudge=1,cjudge=1; 
  player.first_two(); 
  computer.first_two(); 
  cout<<"\n◆You first and two cards are:"<<player.getsuit(); 
  player.hit(); 
  player.hit_cards(); 
  cout<<"   "<<player.getsuit(); 
  player.hit(); 
  cout<<".  Total Points："<<player.total_point()<<".\n"; 
  computer.hit_cards(); 
  cout<<"◆CPU's "<<computer.C_number()<<"card is："<<computer.getsuit(); 
  computer.hit(); 
  cout<<".\n"<<endl; 
do 
  { 
    if(player.total_point()>21) 
      { 
	cout<<"Busting!!~!"<<endl; 
	judge=0; 
      } 
    else if(judge!=0) 
      { 
	cout<<"Hit or not??Y/N."; 
        cin>>judge; 
      } 
    if(((judge=='y'||judge=='Y')&&pjudge==1)) 
      {   
	if(player.C_number()<5&&judge!=0) 
	  {   
	    player.hit_cards(); 
	    cout<<"◆Your "<<player.C_number()<<"cards is ："<<player.getsuit(); 
	    player.hit(); 
	    cout<<".  Total Points："<<player.total_point()<<".\n"; 
	  } 
	else 
	  { 
	    judge=0; 
	    cout<<"You can not hit cards!"; 
	  } 
      } 
    else  
      { 
	pjudge=0; 
	judge=0; 
      } 
    if(computer.total_point()<=17&&computer.C_number()<7) 
      { 
	computer.hit_cards(); 
        cout<<"◆Computer hit "<<computer.C_number()<<"card is ："<<computer.getsuit(); 
	computer.hit(); 
	cout<<".\n"<<endl; 
      } 
    else 
      cjudge=0; 
  }while(pjudge||cjudge); 
 judgegame(player,computer); 
} 

int main() 
{ 
  srand((unsigned)time(NULL));
  Game player,computer; 
  player.welcome(); 
  char sjudge; 
  cout<<"Start game or press any to continue Y/any key!"; 
  cin>>sjudge; 
do 
  {    
    system("cls"); 
    player.welcome(); 
    if(sjudge=='Y'||sjudge=='y') 
      { 
	playpai(player,computer); 
	player.print(); 
	sjudge=0; 
	cout<<"Continue or press key to end Y/any key!"; 
	cin>>sjudge; 
      } 
  }while(sjudge=='Y'||sjudge=='y'); 
 cout<<"Bye bye"<<endl; 
 return 0; 
} 
