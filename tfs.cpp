#include <iostream>
#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;

void Playerturn(int &bluep, int &redp, int &yellowp, int &num, char &choice, int &winorlose)
{
  //output the curret status
  cout << "Your turn." << endl;
  cout << "Blue: " << bluep << ", " << "Red: " << redp << ", " << "Yellow: "
  << yellowp << endl;
  cout << "Please Input the group you want to take(b, r or y):" << endl;
  //palyer input a color
  cin >> choice;
  //ensure player input the right character
  while (choice != 'b' && choice != 'r' && choice != 'y'){
    cout << "Please input a valid group: " << endl;
    cin >> choice;
  }
//palyer input a number
  cout << "Please Input the number of stones you want to take :" << endl;
  cin >> num;
//different cases
    if (choice == 'b')
    {
      while (num > bluep || num <= 0){
        cout << "Please input a valid number: " << endl;
        cin >> num;}
      bluep = bluep - num;
    }
    else if (choice == 'r')
    {
      while (num > redp || num<=0){
        cout << "Please input a valid number: " << endl;
        cin >> num;}
      redp = redp - num;
    }
    else if (choice == 'y')
    {
      while (num > yellowp || num <= 0){
        cout << "Please input a valid number: "<< endl;
        cin >> num;}
      yellowp = yellowp - num;
    }
    cout << "Blue: " << bluep << ", " << "Red: " << redp << ", " << "Yellow: "
    << yellowp << endl;
    cout << "--------------------------------------------------" << endl;
    if ( (bluep == 1 && redp == 0 && yellowp == 0) ||
      (bluep == 0 && redp == 1 && yellowp == 0) ||
      (bluep == 0 && redp == 0 && yellowp == 1) )
    {
      cout << "You WIN!!!!!" << endl;
      winorlose = 1 ;
    }
}


int Monsterturn(int &bluem, int &redm, int &yellowm, char c, int &winorlose)
{
  if ( (bluem == 1 && redm == 0 && yellowm == 0) ||
    (bluem == 0 && redm == 1&&yellowm==0)||(bluem==0&&redm==0&&yellowm==1) )
  {return 0;}
  cout << "Monster's turn" << endl;
  //Three groups are left
  if (redm != 0 && bluem != 0 && yellowm != 0)
  {
    if(c == 'b')
    {
      bluem = 0;
    }
    else if(c == 'r')
    {
      redm = 0;
    }
    else if (c == 'y')
    {
      yellowm = 0;
    }
  }
  //two gourp are left
  else if ( (redm == 0 && bluem != 0 && yellowm != 0) || (redm != 0 && bluem == 0 && yellowm != 0)
  || (redm != 0 && bluem != 0 && yellowm == 0) )
  {
    if(redm == 0)
    {
      if (bluem == 1) {yellowm = 0;}
      else if (yellowm == 1) {bluem = 0;}
      else if (yellowm == 2 && bluem == 2)
      {int ram;
        ram = rand()%2;
        if( ram == 0)
        {yellowm = 1;}
        else if (ram == 1)
        {bluem = 1;}
      }
      else {
        if (bluem == 2) {yellowm = 2;}
        else if (yellowm == 2) {bluem = 2;}
        else {bluem = 2;}
      }
    }
    else if(bluem == 0)
    {
      if (redm == 1) {yellowm = 0;}
      else if (yellowm == 1) {redm = 0;}
      else if (yellowm == 2 && redm == 2)
      {int ram;
        ram = rand()%2;
        if( ram == 0)
        {redm = 1;}
        else if (ram ==1 )
        {yellowm = 1;}
      }
      else {
        if (redm == 2) {yellowm = 2;}
        else if (yellowm == 2) {redm = 2;}
        else {yellowm = 2;}
      }
    }
    else if (yellowm == 0)
    {
      if (bluem == 1) {redm = 0;}
      else if (redm == 1) {bluem = 0;}
      else if (bluem == 2 && redm == 2)
      {int ram;
        ram = rand()%2;
        if( ram == 0)
        {redm = 1 ;}
        else if (ram ==1)
        {bluem = 1;}
      }
      else {
        if (bluem == 2) {redm = 2;}
        else if (redm == 2) {bluem = 2;}
        else {bluem = 2;}
      }
    }
  }
  //one group is left
  else if ( (redm == 0 && bluem == 0 && yellowm != 0)
  || (redm != 0 && bluem == 0 && yellowm == 0) ||
  (redm == 0 && bluem != 0 && yellowm == 0) )
  {
    if (yellowm != 0) {yellowm = 1;}
    if (bluem != 0) {bluem = 1;}
    if (redm != 0) {redm = 1;}
    }
  cout << "Blue: " << bluem << ", " << "Red: " << redm << ", " << "Yellow: "
    << yellowm << endl;
  cout << "--------------------------------------------------" << endl;
  if ( (bluem == 1 && redm == 0 && yellowm == 0) ||
  (bluem == 0 && redm == 1 && yellowm == 0) || (bluem == 0 && redm == 0 && yellowm == 1))
  {
    cout << "You lose!" << endl;
    winorlose = 2;

  }
  return 0;
}



bool tfs()
{//out put the role of the game2
  cout << "There are 3 stone groups with different colors. \n" << endl;
  cout << "The first group has 3 blue balls." << endl;
  cout << "The second group has 5 red balls." << endl;
  cout << "The third group has 7 yellow balls. \n" << endl;

  cout << "1. You can take as many stones as you want from ONE group in your turn." << endl;
  cout << "2. Then MONSTER will then take a few stones from ONE group." << endl;
  cout << "3. The one who takes the last stone loses." << endl;
  cout << endl;

  int * b = new int(3);
  int * r = new int(5);
  int * y = new int(7);

  int num, winorlose=0;
  char choice;
  while (winorlose == 0)
  {
  Playerturn(*b, *r, *y, num, choice, winorlose);
  Monsterturn(*b, *r, *y, choice, winorlose);
  }
  delete b;
  delete r;
  delete y;

  if(winorlose ==1 )
    {return true;}
  else 
    {return false;}


}
