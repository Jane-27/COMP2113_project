#include <iostream>
using namespace std;

void Playerturn(int &bluep,int &redp,int &yellowp, int &num, char &choice,int &winorlosep)
{
  cout<<"Your turn."<<endl;
  cout<<"Blue: "<<bluep<<", "<<"Red: "<<redp<<", "<<"Yellow: "<<yellowp<<endl;
  cout<<"Please Input the group you want to take(b, r or y):"<<endl;

  cin>>choice;
  while (choice!='b' && choice != 'r' && choice != 'y'){
    cout <<"Please input a valid group: "<<endl;
    cin>>choice;
  }

  cout<<"Please Input the number of stones you want to take :"<<endl;
  cin>>num;

    if(choice== 'b')
    {
      while (num > bluep||num<=0){
        cout <<"Please input a valid number: "<<endl;
        cin>>num;}
      bluep = bluep- num;
    }
    else if(choice == 'r')
    {
      while (num > redp||num<=0){
        cout <<"Please input a valid number: "<<endl;
        cin>>num;}
      redp = redp-num;
    }
    else if (choice == 'y')
    {
      while (num > yellowp||num<=0){
        cout <<"Please input a valid number: "<<endl;
        cin>>num;}
      yellowp = yellowp-num;
    }
    cout<<"Blue: "<<bluep<<", "<<"Red: "<<redp<<", "<<"Yellow: "<<yellowp<<endl;
    cout<<"--------------------------------------------------"<<endl;
    if ( (bluep==1&&redp==0&&yellowp==0)||(bluep==0&&redp==1&&yellowp==0)||(bluep==0&&redp==0&&yellowp==1))
    {
      cout<<"You WIN!!!!!"<<endl;
      winorlosep=1;
    }
}


int Monsterturn(int &bluem,int &redm,int &yellowm,char c, int &winorlosem)
{
  if ( (bluem==1&&redm==0&&yellowm==0)||(bluem==0&&redm==1&&yellowm==0)||(bluem==0&&redm==0&&yellowm==1))
  {return 0;}
  cout<<"Monster's turn"<<endl;
  if (redm!=0&&bluem!=0&&yellowm!=0)//Three groups are left
  {
    srand( time(0));//implement random number to choose which group to take
    int group = rand() % 3;
    if (group ==0){bluem = rand()%bluem;}
    if (group ==1){redm = rand()%redm;}
    if (group ==2){yellowm = rand()%yellowm;}

  }


  else if ( (redm==0&&bluem!=0&&yellowm!=0) || (redm!=0&&bluem==0&&yellowm!=0) ||
  (redm!=0&&bluem!=0&&yellowm==0) )//two gourp are left
  {
    if(redm==0)
    {
      if (bluem==1){yellowm=0;}
      else if (yellowm==1){bluem=0;}
      else if (yellowm==2&&bluem==2){bluem=1;}//加一个random让blue or yellow =2
      else {
        if (bluem== 2){yellowm=2;}
        else if (yellowm == 2){bluem = 2;}
        else{
          int group = rand() % 2;
          if (group ==0){bluem = rand()%bluem;}
          else if (group ==1){yellowm = rand()%yellowm;}
        }
      }
    }
    else if(bluem==0)
    {
      if (redm==1){yellowm=0;}
      else if (yellowm==1){redm=0;}
      else if (yellowm==2&&redm==2){redm=1;}//加一个random让blue or yellow =2
      else {
        if (redm == 2){yellowm=2;}
        else if (yellowm == 2){redm = 2;}
        else{
          int group = rand() % 2;
          if (group ==0){redm = rand()%redm;}
          else if (group ==1){yellowm = rand()%yellowm;}
        }//加一个random让blue or yellow =2
      }
    }
    else if (yellowm==0)
    {
      if (bluem==1){redm=0;}
      else if (redm==1){bluem=0;}
      else if (bluem==2&&redm==2){redm=1;}//加一个random让blue or yellow =2
      else {
        if (bluem == 2){redm=2;}
        else if (redm == 2){bluem = 2;}
        else{
          int group = rand() % 2;
          if (group ==0){redm = rand()%redm;}
          else if (group ==1){bluem= rand()%bluem;}
        }//加一个random让blue or yellow =2
      }
    }
  }
  else if ((redm==0&&bluem==0&&yellowm!=0) || (redm!=0&&bluem==0&&yellowm==0) ||
  (redm==0&&bluem!=0&&yellowm==0))//one group is left
  {
    if (yellowm!= 0){yellowm=1;}
    if (bluem!= 0){bluem=1;}
    if (redm!= 0){redm=1;}
    }
  cout<<"Blue: "<<bluem<<", "<<"Red: "<<redm<<", "<<"Yellow: "<<yellowm<<endl;
  cout <<"--------------------------------------------------"<<endl;
  if ( (bluem==1&&redm==0&&yellowm==0)||(bluem==0&&redm==1&&yellowm==0)||(bluem==0&&redm==0&&yellowm==1))
  {
    cout<<"You lose!"<<endl;
    winorlosem=1;

  }
  return 0;
}



int main()
{
  cout<< "There are three piles of balls, one pile has 3 blue balls";
  cout<<",one pile has 5 red balls,nd one pile has seven yellow balls.";
  cout<<"There are three stone groups. Each has 3, 5 and 7 stones."<<endl;

  cout<<"1. You can take how many stones you want from a group in your turn."<<endl;
  cout<<"2. Then MONSTER will take a few stones from a group."<<endl;
  cout<<"3. The one who takes the last stone loses."<<endl;
  cout<<endl;
  int b=3, r=5, y=7,winorlose=0, num;
  char choice;
  while (winorlose==0){


  Playerturn(b,r,y,num,choice,winorlose);
  Monsterturn(b,r,y, choice,winorlose);
  }




}
