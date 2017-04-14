#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void nuGame();
void loadGame();
void controls();

void abandonedRoom();

int main()
{
	int menuChoice;

	cout << "Welcome to our Adventure Game! \n"; //need a name
	cout << "Would you like to: \n";
	cout << "\t 1. Start a New Game\n";
	cout << "\t 2. Load a Saved Game\n";
	cout << "\t 3. Look at the Game Controls\n";
	cout << "\t 4. Quit \n";
	cout << "Please choose between options 1-4. \n";
	cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:
		nuGame();
		break;
	case 2:
		loadGame();
		break;
	case 3:
		controls();
		break;
	case 4:
		return 0;
	default:
		cout << "Please choose between options 1-4. \n \n";
		main();
		break;
	}
}

void nuGame() //function to start a new game, can't be void
{
	string name;
	char gender; //don't feel like we need gender 
	string savePt;
	ofstream outP;

	cout << "Starting a New Game. \n";
	cout << "Please enter the name you'd like to be called. \n"; //name
	cin.ignore();
	getline(cin, name);
	cout << "Please enter your gender (f/m). \n";
	cin >> gender;
	cout << "Would you like to save to slot 1, 2, or 3. \n";
	cin >> savePt;
	savePt += ".txt";
	cout << savePt << "\n";
	outP.open(savePt);
	outP << "abandonedRoom()";
	outP << name << endl;
	outP << gender << endl;

	cout << "Thank you, your progress will be automatically saved.";

	abandonedRoom();

}

void loadGame() //function to load a saved game
{
	string save;
	ifstream inP; //ifstream to search for a numbered file
	cout << "Would you like to load save 1, 2, or 3. \n";
	cin >> save;
	save += ".txt";
	


	
}

void controls() //function to show the various controls
{
	char next;

	cout << "Press L to look around the area. \n";
	cout << "\t After pressing 'L', the game will tell you what's in the room.";

	cout << "Press N, S, E, or W to head in the \n respective North, South, East, or West direction. \n";
	cout << "\t After pressing 'N', you would head through the door to the N but \n if there isn't a door";
	cout << " the game will tell you there's nothing to pass through there. \n";

	cout << "Press G to grab an item from the environment. \n";
	cout << "\t After pressing 'G crowbar', you will pick up a crowbar and add it to your inventory. \n";

	cout << "Press U 'itemname' to use an item from your inventory. \n";
	cout << "\t After pressing 'U crowbar', you'd be able to use the crowbar to for example pry open a door. \n";

	cout << "Press M to return to the main menu. \n";

	cout << "Press Q to quit.";

	cout << "Press any key and hit enter to return to the main menu. \n";
	cin >> next;
	cout << " \n";
	main();
}

void abandonedRoom()
{
	char move;
	int cond;
	string action;
	ofstream outP;



	cout << "You wake up on a hard, cold floor. \n";
	cout << "As you stand up, you see a door in front of you.\n";
	cout << "What do you do? \n";
	cin >> move;

	while (cond = 1)
	{
		switch (move)
		{
		case 'L':
			cout << "As your eyes adjust to the harsh light, you notice a crowbar in the corner of the room.";
			break;
		case 'N':
		{	
			if()
			cout << "You try to open the door, but it won't budge.";
			break;
		}
		case 'S':
			cout << "There's a wall there. You can't walk through walls.";
			break;
		case 'W':
			cout << "There's a wall there. You can't walk through walls.";
			break;
		case 'E':
			cout << "There's a wall there. You can't walk through walls.";
			break;
		case 'C':
			controls();
		case 'M':
			main();
		case 'Q' :
			return;

		}
	}
	cout << "What would you like to do now?\n";
	cin.ignore();
	getline(cin,action);
	if (action == "U Crowbar")
	{
		cout << "You've picked up the crowbar. It has been added to your inventory.";
		
	}

}