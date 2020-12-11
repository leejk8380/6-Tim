#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime> 
#include <time.h>

using namespace std; 

typedef struct list_node {
	int pw_3;
	string ID_3;
	int score[5];
	// score[0] : 369
	// score[1] : lotto
	// score[2] : up down
	// score[3] : one pull
	// score[4] : baseball
	struct list_node *next;
} NODE;

int main() {
	string ID_3;
	int pw_3, choose_3, re_3;
	int istrue = 0;
	char del_3;
	NODE * head = NULL;
	NODE * temp;
	NODE * prev;
	NODE * usernode_3;
	
	while(1){
		cout << "-------------------------welcome to 6-tim game world!!-------------------------" << endl;
		cout << " " << endl;
		cout << " select please " << endl;
		cout << " " << endl;
		cout << " 1. Login " << endl;
		cout << " 2. create ID " << endl;
		cout << " 3. delete ID " << endl;
		cout << " 4. exit " << endl;
		cout << " " << endl;
		cout << " -> ";
		cin >> choose_3;
		switch(choose_3){
			case 1:
				while(1){
					cout << "-------------------------Login page-------------------------" << endl << endl;
					cout << " select number " << endl << endl;
					cout << "1. return back page" << endl;
					cout << "2. login" << endl << endl;
					cout << " -> ";
					cin >> re_3;

					if(re_3 == 1) break;
					else if(re_3 == 2){
						cout << " " << endl;
						cout << " input your ID/password " << endl << endl;
						cout << " ID : ";
						cin >> ID_3;
						cout << " password : ";
						cin >> pw_3;
						temp = head;
						while(temp != NULL){
							if(temp->ID_3 == ID_3 && temp->pw_3 == pw_3){
								usernode_3 = temp;
								cout << " " << endl;
								cout << " login.....complete! " << endl << endl;
								goto game_point;
							}
							temp = temp->next;
						}
						cout << " " << endl;
						cout << " wrong ID or password. try again " << endl << endl;
					}
					else{
						cout << " " << endl;
						cout << "wrong number" << endl << endl;
					}
				}
			break;
			case 2:
				while(1){
					istrue = 0;
					cout << "-------------------------create page-------------------------" << endl << endl;
					cout << " select number " << endl << endl;
					cout << "1. return back page" << endl;
					cout << "2. create" << endl << endl;
					cout << " -> ";
					cin >> re_3;

					if(re_3 == 1) break;
					else if(re_3 == 2){
						cout << " " << endl;
						cout << " create ID : ";
						cin >> ID_3;
						cout << " create password : ";
						cin >> pw_3;

						prev = NULL;
						temp = head;
						while(temp != NULL){
							if(ID_3 == temp->ID_3){
								cout << " " << endl;
								cout << "already exist ID!!!!!" << endl << endl;
								istrue = 1;
								break;
							}
							prev = temp;
							temp = temp->next;
						}
						if(istrue) continue;
						if(prev == NULL){
							head = (NODE*)malloc(sizeof(NODE));
							head->pw_3 = pw_3;
							head->ID_3 = ID_3;
							for(int i_3 = 0; i_3 < 5; i_3++)
								head->score[i_3] = 0;
							head->next = NULL;
							cout << " " << endl;
							cout << " creat.....complete! " << endl << endl;
						}
						else{
							temp = (NODE*)malloc(sizeof(NODE));
							temp->pw_3 = pw_3;
							temp->ID_3 = ID_3;
							for(int i_3 = 0; i_3 < 5; i_3++)
								temp->score[i_3] = 0;
							temp->next = NULL;
							prev->next = temp;
							cout << " " << endl;
							cout << " creat.....complete! " << endl << endl;
						}
						break;
					}
					else
						cout << " " << endl;
						cout << "wrong number" << endl << endl;
				}
			break;
			case 3:
				while(1){
					cout << "-------------------------delete page-------------------------" << endl << endl;
					cout << " select number " << endl << endl;
					cout << "1. return back page" << endl;
					cout << "2. delete" << endl << endl;
					cout << " -> ";
					cin >> re_3;
					
					if(re_3 == 1) break;
					else if(re_3 == 2){
						cout << " delete ID : ";
						cin >> ID_3;
						cout << " delete password : ";
						cin >> pw_3;

						prev = NULL;
						temp = head;
						while(temp != NULL){
							if(temp->ID_3 == ID_3 && temp->pw_3 == pw_3){
								cout << " are you sure? (y/n) ";
								cin >> del_3;
								if(del_3 == 'y' || del_3 == 'Y'){
									cout << " " << endl;
									cout << "delete.....complete!" << endl << endl;
									break;
								}
							}
							prev = temp;
							temp = temp->next;
						}
						if(temp == NULL){
							cout << "there is no ID" << endl << endl;
							continue;
						}
						if(prev == NULL){
							head = temp->next;
							free(temp);
						}
						else{
							prev = temp->next;
							free(temp);
						}
						break;
					}
					else
						cout << " " << endl;
						cout << "wrong number" << endl << endl;
				}
			break;
			case 4:
				cout << "See you next!" << endl;
				return 0;
			default:
				cout << " Wrong number! try again " << endl << endl;
			break;
		}
	}
	//usernode_3->score[i] = 4;
	game_point:
	
	cout << "-------------------------Select game-------------------------" << endl;
	cout << " " << endl;
	cout << " 1. 369 " << endl;
	cout << " 2. Lotto " << endl;
	cout << " 3. Up and down " << endl;
	cout << " 4. On-pull game " << endl;
	cout << " 5. Baseball game " << endl;
	cout << " 6. my recent score " << endl;
	cout << " 7. exit game " << endl;
	cout << " " << endl;
	cout << " -> ";
	cin >> choose_3;
	if(choose_3 == 1){
		start_369:
		cout << "-------------------------369 game-------------------------" << endl;
		cout << " " << endl;
		cout << " 1. start game " << endl;
		cout << " 2. return game select page " << endl << endl;
		cout << " -> ";
		cin >> choose_3;
		if(choose_3 == 1) goto page_369;
		else if(choose_3 == 2) goto game_point;
		else{
			cout << " Wrong number! try again " << endl;
			goto start_369;
		}
	}
	else if(choose_3 == 2){
		lotto_start:
		cout << "-------------------------Lotto game-------------------------" << endl;
		cout << " " << endl;
		cout << " 1. start game " << endl;
		cout << " 2. return game select page " << endl << endl;
		cout << " -> ";
		cin >> choose_3;
		if(choose_3 == 1) goto lotto_page;
		else if(choose_3 == 2) goto game_point;
		else{
			cout << " Wrong number! try again " << endl;
			goto lotto_start;
		}
	}
	else if(choose_3 == 3){
		ud_start:
		cout << "-------------------------Up and down game-------------------------" << endl;
		cout << " " << endl;
		cout << " 1. start game " << endl;
		cout << " 2. return game select page " << endl << endl;
		cout << " -> ";
		cin >> choose_3;
		if(choose_3 == 1) goto ud_page;
		else if(choose_3 == 2) goto game_point;
		else{
			cout << " Wrong number! try again " << endl;
			goto ud_start;
		}	
	}
	else if(choose_3 == 4){
		op_start:
		cout << "-------------------------One-pull game-------------------------" << endl;
		cout << " " << endl;
		cout << " 1. start game " << endl;
		cout << " 2. return game select page " << endl << endl;
		cout << " -> ";
		cin >> choose_3;
		if(choose_3 == 1) goto op_page;
		else if(choose_3 == 2) goto game_point;
		else{
			cout << " Wrong number! try again " << endl;
			goto op_start;
		}
	}
	else if(choose_3 == 5){
		b_start:
		cout << "-------------------------Baseball game-------------------------" << endl;
		cout << " " << endl;
		cout << " 1. start game " << endl;
		cout << " 2. return game select page " << endl << endl;
		cout << " -> ";
		cin >> choose_3;
		if(choose_3 == 1) goto b_page;
		else if(choose_3 == 2) goto game_point;
		else{
			cout << " Wrong number! try again " << endl;
			goto b_start;
		}	
	}
	else if(choose_3 == 6){
		cout <<	"-------------------------my recent score-------------------------" << endl;
		for(int i_3=0;i_3<5;i_3++){
			cout << "score[";
			switch(i_3){
				case 0:
					cout << "369] : ";
				break;
				case 1:
					cout << "lotto] : ";
				break;
				case 2:
					cout << "up down] : ";
				break;
				case 3:
					cout << "one pull] : ";
				break;
				case 4:
					cout << "baseball] : ";
				break;
			}
			cout << usernode_3 -> score[i_3] << endl;
		}
		cout <<	"" << endl;
		goto game_point;
	}
	else if(choose_3 == 7){
		cout << "See you next!" << endl;
		return 0;	
	}
	else{
		cout << " Wrong number! try again " << endl;
		goto game_point;
	}


	/////////////////////////////////////////////////////// 369 ///////////////////////////////////////////////////////
	page_369:
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////// lotto ///////////////////////////////////////////////////////
	lotto_page:
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////// up_down ///////////////////////////////////////////////////////
	ud_page:
	{
		srand(time(NULL));
		int com_choice;
		int user_input;
		int game_con = 1;
		int game_ans = 1;
		int game_num = 1;

		cout << "         --------------------------------" << endl;
		cout << "               [ Up & Down Game !! ]     " << endl;
		cout << "         --------------------------------" << endl;
		cout << "   Guess the number chosen by the computer(1~100) " << endl;
		cout << "              You have 5 chances " << endl;
		cout << endl;
		usernode_3->score[2] = 0;


		while (game_con)
		{
			com_choice = rand() % 100;
			if (com_choice == 0) com_choice++;

			while (game_ans)
			{
				if (game_num > 5)
				{
					cout << "===================================" << endl;
					cout << "    Over 5 chances. You lose :(   " << endl;
					cout << "===================================" << endl;
					usernode_3->score[2] -= 1;
					break;					
				}

				cout << "User's choice : ";
				cin >> user_input;

				
				if (user_input > 100) cout << "  That is Too Big !!";
				else if (user_input < 0) cout << "  Not Negative :(";
				else if (user_input > com_choice) cout << "  DOWN !! " << endl;
				else if (user_input < com_choice) cout << "  UP !!" << endl;
				else if (user_input == com_choice)
				{
					cout << "===================================" << endl;
					cout << "That is Answer!! Congraturation~~:D" << endl;
					cout << "===================================" << endl;
					usernode_3->score[2] += 1; 
					game_ans = 0;
					break;
				}
				game_num++;
			}

			cout << "Continue?  1.Yes  2.NO  User's choice : ";
			cin >> user_input;
			cout << endl;
		
			if (user_input == 1)
			{
				game_ans = 1;
				game_con = 1;
				game_num = 1;
			}
			else
			{
				game_ans = 0;
				game_con = 0;
				break;
			}

		}
		goto game_point;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////// one-pull ///////////////////////////////////////////////////////
	op_page:
	{
	srand(time(NULL)); 
    	int com1; 
	int com2;
	int input1; 
	int input2; 
	int sel1; 
	int sel2;  
	int comsel;
	int connew = 1;

	cout << "         --------------------------------" << endl;
	cout << "          [ Rock Paper Scissors Game!! ] " << endl;
	cout << "         --------------------------------" << endl;
	cout << endl;
	usernode_3->score[3] = 0;

	while (connew = 1)
	{
		cout << "What choice left hand?  1.Rock 2.Paper 3.Scissors" << endl;
		cin >> input1;
		cout << "What choice right hand?  1.Rock 2.Paper 3.Scissors" << endl;
		cin >> input2;

		cout << "-------------------------------" << endl;

		if (input1 == 1) cout << "Left hand = Rock" << endl; 
		else if (input1 == 2) cout << "Left hand = Paper" << endl;
		else if (input1 == 3) cout << "Left hand = Scissors" << endl;
		else cout << "No choice left hand" << endl;

		if (input2 == 1) cout << "Right hand = Rock" << endl;
		else if (input2 == 2) cout << "Right hand = Paper" << endl;
		else if (input2 == 3) cout << "Right hand = Scissors" << endl; 
		else cout << "No choice right hand" << endl; 

		cout << "------------- V S -------------" << endl;

		com1 = rand() % 3;
		com2 = rand() % 3;

		if ((com1 == com2) && (com1 < 2)) com2 = com2 + 1;
		else if ((com1 == com2) && (com1 == 2)) com2 = com2 - 1;

		if (com1 == 0) cout << "Computer left hand = Rock" << endl;
		else if (com1 == 1) cout << "Computer left hand = Paper" << endl; 
		else if (com1 == 2) cout << "Computer left hand = Scissors" << endl;

		if (com2 == 0) cout << "Computer right hand = Rock" << endl; 
		else if (com2 == 1) cout << "Computer right hand = Paper" << endl; 
		else if (com2 == 2) cout << "Computer right hand = Scissors" << endl; 
		cout << "-------------------------------" << endl;

		cout << "What hand?  1.Left 2.Right " << endl;

		cin >> sel1;

		sel2 = rand() % 3;

		if (sel2 <= 2)
		{
		    comsel = com1;
		    cout << "Computer choose left hand!!" << endl; 
		}
		else
		{
		    comsel = com2;
		    cout << "Computer choose right hand!!" << endl; 
		}

		if (sel1 == 1)
		{
		    if ((input1 == 1 && comsel == 0)) {
			cout << "Rock vs Rock  Draw :l" << endl; 
			usernode_3->score[3] += 1;
			}
		    else if ((input1 == 1 && comsel == 1)) {
			cout << "Rock vs Paper  Lose :(" << endl; 
			usernode_3->score[3] -= 3;
			}
		    else if ((input1 == 1 && comsel == 2)) {
			cout << "Rock vs Scissors  Win :D" << endl; 
			usernode_3->score[3] += 3; 
			}

		    else if ((input1 == 2 && comsel == 0)) {
			cout << "Paper vs Rock  Win :D" << endl; 
			usernode_3->score[3] += 3; 
			}
		    else if ((input1 == 2 && comsel == 1)) {
			cout << "Paper vs Paper  Draw :l" << endl;
			usernode_3->score[3] += 1;
			} 
		    else if ((input1 == 2 && comsel == 2)) {
			cout << "Paper vs Scissors  Lose :(" << endl;       
			usernode_3->score[3] -= 3;
			}  

		    else if ((input1 == 3 && comsel == 0)) {
			cout << "Scissors vs Rock  Lose :(" << endl; 
			usernode_3->score[3] -= 3;
			}
		    else if ((input1 == 3 && comsel == 1)) {
			cout << "Scissors vs Paper  Win :D" << endl; 
			usernode_3->score[3] += 3; 
			}
		    else if ((input1 == 3 && comsel == 2)) {
			cout << "Scissors vs Scissors  Draw :l" << endl; 
			usernode_3->score[3] += 1;
			}
		}

		if (sel1 == 2)
		{
		    if ((input2 == 1 && comsel == 0)){
			 cout << "Rock vs Rock  Draw :l" << endl; 
			usernode_3->score[3] += 1;
			}
		    else if ((input2 == 1 && comsel == 1)) {
			cout << "Rock vs Paper  Lose :(" << endl;
			usernode_3->score[3] -= 3;
			}
		    else if ((input2 == 1 && comsel == 2)) {
			 cout << "Rock vs Scissors  Win :D" << endl;
			usernode_3->score[3] += 3; 
		    	}
		    
		    else if ((input2 == 2 && comsel == 0)){
			 cout << "Paper vs Rock  Win :D" << endl; 
			usernode_3->score[3] += 3;
			}
		    else if ((input2 == 2 && comsel == 1)){
			 cout << "Paper vs Paper  Draw :l" << endl; 
			usernode_3->score[3] += 1;
			}
		    else if((input2 == 2 && comsel == 2)) {
			cout << "Paper vs Scissors  Lose :(" << endl; 
			usernode_3->score[3] -= 3;
			}	    
		    else if ((input2 == 3 && comsel == 0)){
			 cout << "Scissors vs Rock  Lose :(" << endl; 
			usernode_3->score[3] -= 3;
			}
		    else if ((input2 == 3 && comsel == 1)){
			 cout << "Scissors vs Paper  Win :D" << endl; 
			usernode_3->score[3] += 3;
			}
		    else if((input2 == 3 && comsel == 2)){
			 cout << "Scissors vs Scissors  Draw :l" << endl;
			usernode_3->score[3] += 1;
			}   
		}

		cout << "Continue? 1.Yes 2. No " << endl;

		cin >> connew;

		if (connew == 2) break;
	}
	goto game_point;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////// baseball ///////////////////////////////////////////////////////
	b_page:
	int computerBall[3]; 
	int userBall[3]; 
	int count_3 = 1; 
	int strike; 
	int ball; 
	srand(static_cast<unsigned int>(time(NULL))); 

	for (int i=0;i<3;i++){ 
		computerBall[i] = (rand() % 9) + 1; 
		for (int j = 0; j < i; j++){
			if (computerBall[i] == computerBall[j] && i != j) i--;
		}
	}
	while (true){ 
		cout << "[" << count_3 << "] round" << endl; 
		while (true){ 
			cout << "input 3 number and spacebar (ex:3 5 4) : "; 
			cin >> userBall[0] >> userBall[1] >> userBall[2]; 
			if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9){
				cout << "only 1~9 number allow!" << endl; 
				continue; 
			} 
			else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2]){ 
				cout << "No duplicate number!" << endl; 
				continue;
			} 
			break; 
		}

		strike = 0; 
		ball = 0; 

		for (int i=0;i<3;i++){
			for (int j=0;j<3;j++){
				if (computerBall[i] == userBall[j]){
					if (i == j) strike++;
					else ball++; 
				}
			}
		}
		if (strike || ball) cout << "[result] strike : " << strike << ", ball : " << ball << endl << endl; 
		else cout << "[result] out!!!" << endl << endl; 
		if (strike == 3){ 
			cout << "***** you win *****" << endl << endl;
			usernode_3 -> score[4] = (11 - count_3) * 10;
			break;
		}
		else if (count_3 == 9){
			cout << "***** you lose.. the answer is : "; 
			cout << computerBall[0] << computerBall[1] << computerBall[2] << " *****" << endl << endl;
			usernode_3 -> score[4] = count_3;
			break;
		} 
		count_3++;
	} 
	cout << "continue? (y/n)" << endl << endl;
	cout << " -> ";
	cin >> del_3;
	if(del_3 == 'y' || del_3 == 'Y') goto b_page;
	else if(del_3 == 'n' || del_3 == 'N') goto game_point;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
