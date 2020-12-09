#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	srand(time(NULL));
	int com_choice;
	int user_input;
	int game_con = 1;
	int game_ans = 1;

	cout << "         --------------------------------" << endl;
	cout << "               [ Up & Down Game !! ]     " << endl;
	cout << "         --------------------------------" << endl;
	cout << "   Guess the number chosen by the computer(1~100) " << endl;
	cout << endl;


	while (game_con)
	{
		com_choice = rand() % 100;
		if (com_choice == 0) com_choice++;

		while (game_ans)
		{
			cout << "User's choice : ";
			cin >> user_input;

			if (user_input > 100) cout << "  That is Too Big !!";
			else if (user_input < 0) cout << "  Not Negative :(";
			else if (user_input > com_choice) cout << "  DOWN !! " << endl;
			else if (user_input < com_choice) cout << "  UP !!" << endl;
			else
			{
				cout << "===================================" << endl;
				cout << "That is Answer!! Congraturation~~:D" << endl;
				cout << "===================================" << endl;
				game_ans = 0;
				break;
			}
		}

		cout << "Continue?  1.Yes  2.NO  User's choice : ";
		cin >> user_input;
		cout << endl;
		
		if (user_input == 1)
		{
			game_ans = 1;
			game_con = 1;
		}
		else
		{
			game_ans = 0;
			game_con = 0;
			break;
		}

	}
	return 0;
}