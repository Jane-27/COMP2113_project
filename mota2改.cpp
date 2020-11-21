#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;


bool bloodPK(struct monster);
void drawmap();
void keyDown(int[13][13], char, char &);


int inx=1;
int count = 400;
int upgrade_experience[3] = {400, 800,1200};

//map design
int map[11][13];
int map1[11][13] =

{
0, 16, 1, 9, 8, 9, 1, 1, 1, 1, 1, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
0, 6, 1, 1, 3, 1, 0, 1, 4, 1, 0, 1, 0,
0, 1, 11, 1, 0, 1, 0, 1, 6, 1, 0, 1, 0,
0, 0, 3, 0, 0, 1, 0, 0, 0, 3, 0, 1, 0,
0, 4, 1, 1, 0, 1, 3, 10, 18, 10, 0, 1, 0,
0, 1, 11, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0,
0, 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 0, 0, 3, 0, 0, 0, 3, 0, 0,
0, 6, 1, 4, 0, 4, 1, 1, 0, 1, 10, 1, 0,
0, 6, 1, 4, 0, 1, 15, 1, 0, 9, 1, 9, 0
};

int map2[11][13]={
0, 4, 1, 0, 4, 1, 4, 0, 1, 0, 1, 6, 0,
0, 1, 6, 0, 1, 4, 1, 0, 1, 3, 10, 1, 0,
0, 18, 1, 0, 4, 4, 4, 0, 1, 0, 0, 0, 0,
0, 3, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0,
0, 1, 1, 10, 1, 1, 1, 9, 1, 1, 1, 1, 0,
0, 3, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0,
0, 11, 1, 0, 0, 1, 0, 0, 1, 0, 1, 6, 0,
0, 1, 4, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0,
0, 6, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 0, 0, 8, 0, 1, 1, 0,
0, 16, 15, 1, 1, 1, 1, 0, 1, 3, 1, 16, 0};

int map3[11][13]={
0, 1, 4, 1, 0, 1, 100, 1, 0, 1, 1, 1, 0,
0, 6, 1, 4, 0, 1, 1, 1, 0, 4, 1, 1, 0,
0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 11, 1, 0,
0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 3, 0, 0,
0, 1, 18, 1, 3, 1, 8, 1, 1, 11, 1, 1, 0,
0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 8, 1, 9, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 3, 0, 0, 3, 0, 0, 0, 3, 0, 0, 3, 0,
0, 1, 0, 1, 10, 1, 0, 1, 18, 1, 0, 1, 0,
0, 1, 0, 9, 1, 4, 0, 1, 1, 6, 0, 15, 0,
0, 1, 0, 4, 9, 4, 0, 1, 9, 1, 0, 16, 0};



//role information
struct gameRole{
  int blood;
  int blue;
  int attack;
  int defense;
  int bluekey;
  int yellowkey;
  int level;
  int coin;
};

struct gameRole role = {500,250,50,38,0,0,0,0};



struct monster
{
  int blood;

  int coin;
};

struct monster bat = {84,3};
struct monster wizzard = {308,5};
struct monster GreenHeadMonster = {12,1};
struct monster RedHeadMonster = {20,2};
struct monster Skeleton = {50,6};

//input role name, initilize role information





bool bloodPK(struct monster mons)
{//PK, determine if the game can be playes
  role.blood = role.blood  - mons.blood;
  if(role.blood <= 0)

  {
    return false;
  }
  else
  {cout<< "You beat it";
    role.coin = role.coin + mons.coin;
    return true;
  }

}


void drawmap()
{//print map
 // print role information
  int i,j;
//  int x,y;
  cout << flush;
  for (i = 0; i < 11; i++){
    cout<<endl;
    for (j = 0; j < 13; j++)
    {cout << setw(4) << map[i][j];}
  }
  cout << endl;
}


void keyDown(int map[11][13], char userKey, char &whetherdie)
{

  int i,j;
  for (int q = 0;q < 13; q++)
  {
    for (int p = 0;p < 13; p++)
    {
      if (map[q][p] == 15)
      {i = q;
      j=p;}
    }
  }

  switch (userKey)
  {//left

    case 'a':

    //place to go to is empty
      if(map[i][j-1] == 1 )
      {
        map[i][j] = 1;
        map[i][j-1] = 15;
      }
      else if (map[i][j-1] == 16)
      {//go upstair
        int i1 = 0,j1 = 0;
        if (inx == 1){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map2[i1][j1];}
        }
            inx = 2;
          }
        else if (inx == 2){
          for (i1 = 0;i1 < 11; i1++)
          {
            for (j1 = 0;j1 < 13; j1++)
            {map[i1][j1] = map3[i1][j1];}
          }
              inx = 3;
            }


      }
      else if (map[i][j-1] == 17)
      {//go dowmstair
        int i1 = 0,j1 = 0;
        if (inx == 2){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map1[i1][j1];}
        }
            inx = 1;
          }
        else if (inx == 3){
          for (i1 = 0;i1 < 11; i1++)
          {
            for (j1 = 0;j1 < 13; j1++)
            {map[i1][j1] = map2[i1][j1];}
          }
              inx = 2;
            }
      }
      //key
      else if (map[i][j-1] == 4)
      {
        map[i][j] = 1;
        map[i][j-1] = 15;
        role.bluekey++;
      }
      else if (map[i][j-1] == 3)
      {if (role.bluekey>0){
        map[i][j] = 1;
        map[i][j-1] = 15;
        role.bluekey--;}
        else{cout<<"You need to collect blue keys.";}

      }
      else if (map[i][j-1] == 10)
      {
        cout << "You meet the bat, fight it or not？(please input Y or N)";
        char YorN;
        cin >> YorN;
        if( YorN == 'Y')
        {
          //PK
          if (bloodPK(bat))
          {

            map[i][j] = 1;
            map[i][j-1] = 15;

          }
          else
          {whetherdie='y';
            cout << "You die, whether to resurrect or not?";
          }
        }

      }

      else if (map[i][j-1] == 18)
      {
        cout << "You meet the wozzard, fight it or not？";
        char YorN;
        cin >> YorN;
        if( YorN == 'Y')
        {
          //PK
          if (bloodPK(wizzard))
          {
            cout << "You beat it";
            map[i][j] = 1;
            map[i][j-1] = 15;
          }
          else
          {whetherdie = 'y';
            cout<<"You die, whether to resurrect or not?";
          }
        }

      }
      else if (map[i][j-1] == 8)
      {
        cout << "You meet the red head monster, fight it or not？";
        char YorN;
        cin >> YorN;
        if( YorN == 'Y')
        {
          //PK
          if (bloodPK(RedHeadMonster))
          {
            cout << "You beat it";
            map[i][j] = 1;
            map[i][j-1] = 15;
          }
          else
          {whetherdie = 'y';
            cout<<"You die, whether to resurrect or not?";
          }
        }
      }
      else if (map[i][j-1] == 9)
      {
        cout << "You meet the green head monster, fight it or not？";
        char YorN;
        cin >> YorN;
        if( YorN == 'Y')
        {
          //PK
          if (bloodPK(GreenHeadMonster))
          {
            cout << "You beat it";
            map[i][j] = 1;
            map[i][j-1] = 15;
          }
          else
          {whetherdie = 'y';
            cout<<"You die, whether to resurrect or not?";
          }
        }
      }
      else if (map[i][j-1] ==11)
      {
        cout << "You meet the Skeleton, fight it or not？";
        char YorN;
        cin >> YorN;
        if( YorN == 'Y')
        {
          //PK
          if (bloodPK(Skeleton))
          {
            cout << "You beat it";
            map[i][j] = 1;
            map[i][j-1] = 15;
          }
          else
          {whetherdie = 'y';
            cout<<"You die, whether to resurrect or not?";
          }
        }
      }
      else if (map[i][j-1] ==6)
      {
        role.blood = role.blood + 143;
        map[i][j] = 1;
        map[i][j-1] = 15;
      }
      else if (map[i][j-1] == 100)
      {//go upstair
        if (role.coin <20)
        {
          cout << "You don't have enough cions.";
        }
        else {cout<<"You enter the final round!";
      }
    }
      break;

    //right

    case 'd':
    if(map[i][j+1] == 1 )
    {
      map[i][j] = 1;
      map[i][j+1] = 15;
    }
    else if (map[i][j+1] == 16)
    {//go upstair
        int i1 = 0,j1 = 0;
      if (inx == 1){
      for (i1 = 0;i1 < 11; i1++)
      {
        for (j1 = 0;j1 < 13; j1++)
        {map[i1][j1] = map2[i1][j1];}
      }
          inx = 2;
        }
      else if (inx == 2){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map3[i1][j1];}
        }
            inx = 3;
          }
    }
    else if (map[i][j+1] == 17)
    {//go dowmstair
      int i1 = 0,j1 = 0;
      if (inx == 2){
      for (i1 = 0;i1 < 11; i1++)
      {
        for (j1 = 0;j1 < 13; j1++)
        {map[i1][j1] = map1[i1][j1];}
      }
          inx = 1;
        }
      else if (inx == 3){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map2[i1][j1];}
        }
            inx = 2;
          }
    }
    //key
    else if (map[i][j+1] == 4)
    {
      map[i][j] = 1;
      map[i][j-1] = 15;
      role.bluekey++;
    }
    else if (map[i][j+1] == 3)
    {if (role.bluekey>0){
      map[i][j] = 1;
      map[i][j+1] = 15;
      role.bluekey--;}
      else{cout<<"You need to collect blue keys.";}

    }
    else if (map[i][j+1] == 10)
    {
      cout << "You meet the bat, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(bat))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i][j+1] = 15;

        }
        else
        {whetherdie='y';
          cout << "You die, whether to resurrect or not?";
        }
      }

    }

    else if (map[i][j+1] == 18)
    {
      cout << "You meet the wozzard, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(wizzard))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i][j+1] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }

    }
    else if (map[i][j+1] == 8)
    {
      cout << "You meet the red head monster, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(RedHeadMonster))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i][j+1] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i][j+1] == 9)
    {
      cout << "You meet the green head monster, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(GreenHeadMonster))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i][j+1] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i][j+1] ==11)
    {
      cout << "You meet the Skeleton, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(Skeleton))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i][j+1] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i][j+1] ==6)
    {
      role.blood = role.blood + 143;
      map[i][j] = 1;
      map[i][j-1] = 15;
    }
    else if (map[i][j+1] == 100)
    {//go upstair
      if (role.coin <20)
      {
        cout << "You don't have enough cions.";
      }
      else {cout<<"You enter the final round!";}
    }
    break;


    case 'w':
    if(map[i-1][j] == 1 )
    {
      map[i][j] = 1;
      map[i-1][j] = 15;
    }
    else if (map[i-1][j] == 16)
    {//go upstair
        int i1 = 0,j1 = 0;
      if (inx == 1){
      for (i1 = 0;i1 < 11; i1++)
      {
        for (j1 = 0;j1 < 13; j1++)
        {map[i1][j1] = map2[i1][j1];}
      }
          inx = 2;
        }
      else if (inx == 2){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map3[i1][j1];}
        }
            inx = 3;
          }
    }
    else if (map[i-1][j] == 17)
    {//go dowmstair
      int i1 = 0,j1 = 0;
      if (inx == 2){
      for (i1 = 0;i1 < 11; i1++)
      {
        for (j1 = 0;j1 < 13; j1++)
        {map[i1][j1] = map1[i1][j1];}
      }
          inx = 1;
        }
      else if (inx == 3){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map2[i1][j1];}
        }
            inx = 2;
          }
    }
    //key
    else if (map[i-1][j] == 4)
    {
      map[i][j] = 1;
      map[i-1][j] = 15;
      role.bluekey++;
    }
    else if (map[i-1][j] == 3)
    {if (role.bluekey>0){
      map[i][j] = 1;
      map[i-1][j] = 15;
      role.bluekey--;}
      else{cout<<"You need to collect blue keys.";}

    }
    else if (map[i-1][j] == 10)
    {
      cout << "You meet the bat, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(bat))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i-1][j] = 15;

        }
        else
        {whetherdie='y';
          cout << "You die, whether to resurrect or not?";
        }
      }

    }

    else if (map[i-1][j] == 18)
    {
      cout << "You meet the wozzard, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(wizzard))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i-1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }

    }
    else if (map[i-1][j] == 8)
    {
      cout << "You meet the red head monster, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(RedHeadMonster))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i-1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i-1][j] == 9)
    {
      cout << "You meet the green head monster, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(GreenHeadMonster))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i-1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i-1][j] ==11)
    {
      cout << "You meet the Skeleton, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(Skeleton))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i-1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i-1][j] ==6)
    {
      role.blood = role.blood + 143;
      map[i][j] = 1;
      map[i-1][j] = 15;
    }
    else if (map[i-1][j] == 100)
    {//go upstair
      if (role.coin <20)
      {
        cout << "You don't have enough cions.";
      }
      else {cout<<"You enter the final round!";}
  }
    break;


    case 's':

    if(map[i+1][j] == 1 )
    {
      map[i][j] = 1;
      map[i+1][j] = 15;
    }
    else if (map[i+1][j] == 16)
    {//go upstair
      int i1 = 0,j1 = 0;
      if (inx == 1){
      for (i1 = 0;i1 < 11; i1++)
      {
        for (j1 = 0;j1 < 13; j1++)
        {map[i1][j1] = map2[i1][j1];}
      }
          inx = 2;
        }
      else if (inx == 2){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map3[i1][j1];}
        }
            inx = 3;
          }
    }
    else if (map[i+1][j] == 17)
    {//go dowmstair
      int i1 = 0,j1 = 0;
      if (inx == 2){
      for (i1 = 0;i1 < 11; i1++)
      {
        for (j1 = 0;j1 < 13; j1++)
        {map[i1][j1] = map1[i1][j1];}
      }
          inx = 1;
        }
      else if (inx == 3){
        for (i1 = 0;i1 < 11; i1++)
        {
          for (j1 = 0;j1 < 13; j1++)
          {map[i1][j1] = map2[i1][j1];}
        }
            inx = 2;
          }
    }
    //key
    else if (map[i+1][j] == 4)
    {
      map[i][j] = 1;
      map[i+1][j] = 15;
      role.bluekey++;
    }
    else if (map[i+1][j] == 3)
    {if (role.bluekey>0){
      map[i][j] = 1;
      map[i+1][j] = 15;
      role.bluekey--;}
      else{cout<<"You need to collect blue keys.";}

    }
    else if (map[i+1][j] == 10)
    {
      cout << "You meet the bat, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(bat))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i+1][j] = 15;

        }
        else
        {whetherdie='y';
          cout << "You die, whether to resurrect or not?";
        }
      }

    }

    else if (map[i+1][j] == 18)
    {
      cout << "You meet the wozzard, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(wizzard))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i+1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }

    }
    else if (map[i+1][j] == 8)
    {
      cout << "You meet the red head monster, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(RedHeadMonster))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i+1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i+1][j] == 9)
    {
      cout << "You meet the green head monster, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(GreenHeadMonster))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i+1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i+1][j] ==11)
    {
      cout << "You meet the Skeleton, fight it or not？";
      char YorN;
      cin >> YorN;
      if( YorN == 'Y')
      {
        //PK
        if (bloodPK(Skeleton))
        {
          cout << "You beat it";
          map[i][j] = 1;
          map[i+1][j] = 15;
        }
        else
        {whetherdie = 'y';
          cout<<"You die, whether to resurrect or not?";
        }
      }
    }
    else if (map[i+1][j] ==6)
    {
      role.blood = role.blood + 143;
      map[i][j] = 1;
      map[i+1][j] = 15;
    }
    else if (map[i+1][j] == 100)
    {//go upstair
      if (role.coin <20)
      {
        cout << "You don't have enough cions.";
      }
      else {cout<<"You enter the final round!";
    }
    break;
  }
}

}

int main()
{

  cout<<"You enter an amazing world. You destinametion is SUCCESS. You have to enter it"<<endl;
  ocut<<"Use the arrow keys to move the character, it will automatically fight monsters when it
   hits the monsters, and the ones that cannot be defeated cannot pass. Go to the item an
   d automatically pick it up, and the blue door will collide and open (it wi
     ll cost the corresponding color key)";

  int i1, j1;
  for (i1 = 0;i1 < 11; i1++)
  {
    for (j1 = 0;j1 < 13; j1++)
      {map[i1][j1] = map1[i1][j1];}
  }

  char die='n';
  while (die != 'y')
  {
    drawmap();

    cout<<"input which direction to go:";
    char dir;

    cin>>dir;//为啥会直接跳过

    keyDown(map, dir, die);
  }


return 0;
}
