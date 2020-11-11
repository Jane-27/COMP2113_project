#include <iostream>
#include <sstream>
using namespace std;

char challenges_menu();
// Print chanllenges menu to screen and read user selection

int main()
{//begin the game and lead the palyer to paly it
  cout<< "Welcome to the magic land!"<<endl;
  cout<<"You can upgrade the level and obtain equipment by winning the wars."<<endl;
  cout<<" You will win in the end if your level is 10. "<<endl;
  cout<<endl;
  cout<<"Now, begin your survival travel!"<<endl;
  cout<<endl;

  int level=0;
  string equipment="dagger";
  cout<< "At the beginning, your imformation is as belowing:" <<endl;
  cout<< "Level: " << level <<endl;
  cout<< "Equipment: " << equipment <<endl;
  cout<<endl;


  cout<<"Choose a challenge："<<endl;
  char choice = challenges_menu();

}

char challenges_menu()
{
	char choice;

	// print challenge menu
	cout << "1. " << endl;
	cout << "2. " << endl;
	cout << "3. " << endl;
	cout << "4. " << endl;
	cout << "5. " << endl;
	cout << "6. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;

	return choice;
}
