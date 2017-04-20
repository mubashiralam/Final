#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void nuGame();
void loadGame();
void controls();

void abandonedRoom();
void hallway1Kev();

void hall1NKev();
//void hall1S();
void hall1WAlex();
//void hall1E();

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
//	char gender; //don't feel like we need gender so leaving it out for now, dont even really need name yet
	string savePt;
	ofstream outP;

	cout << "Starting a New Game. \n";
	cout << "Please enter the name you'd like to be called. \n"; //name
	cin.ignore();
	getline(cin, name);
//	cout << "Please enter your gender (f/m). \n";
//	cin >> gender;
	cout << "Would you like to save to slot 1, 2, or 3. \n";
	cin >> savePt;
	savePt += ".txt";
	cout << savePt << "\n";
	outP.open(savePt);
	outP << "abandonedRoom() \n";
	outP << name << endl;
//	outP << gender << endl;

	cout << "Thank you, your progress will be automatically saved. \n \n";

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
	cout << "\t After pressing 'L', the game will tell you what's in the room. \n \n";

	cout << "Press N, S, E, or W to head in the \n respective North, South, East, or West direction. \n";
	cout << "\t After pressing 'N', you would head through the door to the N but \n if there isn't a door";
	cout << " the game will tell you there's nothing to pass through there. \n \n";

	cout << "Press G to grab an item from the environment. \n";
	cout << "\t After pressing 'G crowbar', you will pick up a crowbar and add it to your inventory. \n \n";

	//cout << "Press U 'itemname' to use an item from your inventory. \n";
	//cout << "\t After pressing 'U crowbar', you'd be able to use the crowbar to for example pry open a door. \n";

	cout << "Press M to return to the main menu. \n \n";

	cout << "Press Q to quit. \n \n";

	cout << "Press any key and hit enter to return to the main menu. \n";
	cin >> next;
	cout << " \n";
	main();
}

void abandonedRoom()
{
	char move;
	int cond = 0, crowbar = 0, cond2 = 0;
	string action, pickup;
	ofstream outP;
	

	if (cond == 0)
	{
		cout << "You wake up on a hard, cold floor. \n";
		cout << "As you stand up, you see a door in front of you.\n";
		cond = 1;
	}


	do
	{
		cout << "What do you do? \n";
		cin >> move;
		switch (move)
		{
		case 'L':
		case 'l':
			if (crowbar == 0)
				cout << "As your eyes adjust to the harsh light, you notice a crowbar in the corner of the room. \n";
			else
				cout << "The room is pretty bare with some shelves to your left, and a bright white light directly above you. \n You have already picked up the crowbar. \n";
			break;
		case 'N':
		case 'n':
		{
			if (crowbar == 0)
				cout << "You try to open the door, but it won't budge. \n";
			else
			{
				cout << "You used the crowbar to pry open the door and walked through. \n";
				hallway1Kev();
			}
			break;
		}
		case 'S':
		case 's':
			cout << "There's a wall there. You can't walk through walls. \n";
			break;
		case 'W':
		case 'w':
			cout << "There's a wall there. You can't walk through walls. \n";
			break;
		case 'E':
		case 'e':
			cout << "There's a wall there. You can't walk through walls. \n";
			break;
	//	case 'C':
//		case 'c':
	//		controls();
		case 'G':
		case 'g':
			cout << "What would you like to pick up? \n";
			cin.ignore();
			getline(cin, pickup);
			if (pickup == "Crowbar" || pickup == "crowbar")
			{
				crowbar = 1;
				cout << "You've picked up the crowbar. It has been added to your inventory. \n";
				cond2 = 0;
			}
			else
				cout << "That's not here. \n";
			break;
		case 'M':
		case 'm':
			main();
		case 'Q':
		case 'q':
			return;
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}

	//	cout << "What would you like to do now?\n";
		//cin.ignore();
//		getline(cin, action);
	//	if (action == "G Crowbar")
	//	{
//			crowbar = 1;
//			cout << "You've picked up the crowbar. It has been added to your inventory.";
		//
		//}
	} while (cond2 != 1);

}

void hallway1Kev()
{
	char move;
	bool cond;
	cout << "You moved into the hallway after breaking open the door. \n";
	cin >> move;

	while (cond = 0)
	{
		switch (move)
		{
		case 'L':
			cout << "It's an empty hallway, with a doors in each direction. \n";
			break;
		case 'N':
			cout << "You head to the North door. \n It's labelled as 'Auxiliary Storage.' ";
			hall1NKev();
			break;
		case 'S':
			cout << "You head to the South door. \n";
			//hall1S();
			break;
		case 'W':
			cout << "You head to the West door. \n It's labelled as 'Basement.' ";
			hall1WAlex();
			break;
		case 'E':
			cout << "You head to the East door. \n";
			//hall1E();
			break;
		case 'C':
			controls();
		case 'M':
			main();
		case 'Q':
			return;
		default :
			cout << "Did not recognize that command. Please try something. \n";
		}
	}
}

void hall1NKev()
{
	char move;
	bool cond;
	cout << "You went into the room labeled 'Auxiliary Storage.' \n";
	cin >> move;

	while (cond = 0)
	{
		switch (move)
		{
		case 'L':
			cout << " \n";
			break;
		case 'N':
			cout << " \n";
			hall1NKev();
			break;
		case 'S':
			cout << " \n";
			//hall1S();
			break;
		case 'W':
			cout << " \n";

			break;
		case 'E':
			cout << " \n";

			break;
		case 'C':
			controls();
		case 'M':
			main();
		case 'Q':
			return;
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}
		cout << " \n";
	}
}

void hall1WAlex()
{
	char move;
	bool cond;
	cout << "You went into the room labeled 'Basement.' \n";
	cin >> move;

	while (cond = 0)
	{
		switch (move)
		{
		case 'L':
			cout << " \n";
			break;
		case 'N':
			cout << " \n";
			hall1NKev();
			break;
		case 'S':
			cout << " \n";
			//hall1S();
			break;
		case 'W':
			cout << " \n";
			hall1WAlex();
			break;
		case 'E':
			cout << " \n";

			break;
		case 'C':
			controls();
		case 'M':
			main();
		case 'Q':
			return;
		default:
			cout << "Did not recognize that command. Please try something. \n";
		}
	}
}
