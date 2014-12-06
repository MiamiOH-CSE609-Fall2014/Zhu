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
