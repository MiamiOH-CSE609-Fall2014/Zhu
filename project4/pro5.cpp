#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<math.h> 
#include<ctime> 
#include<iomanip> 

using namespace std;
 
class Game
{    
public: 
  Game();                 
  void first_two();    //first two cards    
  void hit_cards();        // create a card 
  void welcome();    //welcome        
  void hit();         //hit cards
  int C_number();       //total number of cards
  char getsuit();     // get the random suit  
  float total_point();         
  void print();        
  void win_num();           
  void fail_num();        
  void draw_num();        
  void inform();        

private: 
  int cards[5];          
  int suit[5];
  int num;          
  int win;              
  int fail;             
  int draw;             
}; 
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
      //	if(huase[number]==huase[i]&&ppai[number]==ppai[i]) 
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

void judge(Game&player,Game&computer)                                             
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
  char jud='y'; 
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
  cout<<"◆Computer's "<<computer.C_number()<<"card is："<<computer.getsuit(); 
  computer.hit(); 
  cout<<".\n"<<endl; 
do 
  { 
    if(player.total_point()>21) 
      { 
	cout<<"Busting!!~!"<<endl; 
	jud=0; 
      } 
    else if(jud!=0) 
      { 
	cout<<"Hit or not??Y/N."; 
        cin>>jud; 
      } 
    if(((jud=='y'||jud=='Y')&&pjudge==1)) 
      {   
	if(player.C_number()<5&&jud!=0) 
	  {   
	    player.hit_cards(); 
	    cout<<"◆Your "<<player.C_number()<<"cards is ："<<player.getsuit(); 
	    player.hit(); 
	    cout<<".  Total Points："<<player.total_point()<<".\n"; 
	  } 
	else 
	  { 
	    jud=0; 
	    cout<<"You can not hit cards!"; 
	  } 
      } 
    else  
      { 
	pjudge=0; 
	jud=0; 
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
 judge(player,computer); 
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

