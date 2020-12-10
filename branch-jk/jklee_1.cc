#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime> 

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
		cout << " 2. return game select page " << endl;
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
		cout << " 2. return game select page " << endl;
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
		cout << " 2. return game select page " << endl;
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
		cout << " 2. return game select pase " << endl;
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
		cout << " 2. return game select pase " << endl;
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
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////// one-pull ///////////////////////////////////////////////////////
	op_page:
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////// baseball ///////////////////////////////////////////////////////
	b_page:
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	return 0;
}
