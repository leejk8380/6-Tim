#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(void)
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
            if ((input1 == 1 && comsel == 0)) cout << "Rock vs Rock  Draw :l" << endl; 
            else if ((input1 == 1 && comsel == 1)) cout << "Rock vs Paper  Lose :(" << endl; 
            else if ((input1 == 1 && comsel == 2)) cout << "Rock vs Scissors  Win :D" << endl; 

            else if ((input1 == 2 && comsel == 0)) cout << "Paper vs Rock  Win :D" << endl; 
            else if ((input1 == 2 && comsel == 1)) cout << "Paper vs Paper  Draw :l" << endl; 
            else if ((input1 == 2 && comsel == 2)) cout << "Paper vs Scissors  Lose :(" << endl;         

            else if ((input1 == 3 && comsel == 0)) cout << "Scissors vs Rock  Lose :(" << endl; 
            else if ((input1 == 3 && comsel == 1)) cout << "Scissors vs Paper  Win :D" << endl; 
            else if ((input1 == 3 && comsel == 2)) cout << "Scissors vs Scissors  Draw :l" << endl; 
        }

        if (sel1 == 2)
        {
            if ((input2 == 1 && comsel == 0)) cout << "Rock vs Rock  Draw :l" << endl; 
            else if ((input2 == 1 && comsel == 1)) cout << "Rock vs Paper  Lose :(" << endl;
            else if ((input2 == 1 && comsel == 2)) cout << "Rock vs Scissors  Win :D" << endl; 
            
            else if ((input2 == 2 && comsel == 0)) cout << "Paper vs Rock  Win :D" << endl; 
            else if ((input2 == 2 && comsel == 1)) cout << "Paper vs Paper  Draw :l" << endl; 
            else if ((input2 == 2 && comsel == 2)) cout << "Paper vs Scissors  Lose :(" << endl; 
            
            else if ((input2 == 3 && comsel == 0)) cout << "Scissors vs Rock  Lose :(" << endl; 
            else if ((input2 == 3 && comsel == 1)) cout << "Scissors vs Paper  Win :D" << endl; 
            else if ((input2 == 3 && comsel == 2)) cout << "Scissors vs Scissors  Draw :l" << endl;   
        }

        cout << "Continue? 1.Yes 2. No " << endl;

        cin >> connew;

        if (connew == 2) break;
    }

    return 0;
}
