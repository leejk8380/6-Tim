#include <iostream> 
#include <iomanip> 
#include <time.h>
using namespace std; 
void game_2(int number_2, int answer_2); 

////////////////////////////////////////////////////////////////
int main(void) 
{ 
	int x;
	cout<<"game select : ";
	cin>>x;
	switch(x){
	////////////////////// 369+5의배수  게임 /////////////////////////
	  case 1:
	  int answer_2; 
	    cout<<"369+5의배수 game start!!!"<<endl; 
	      cout<<setw(3)<<1<<" : "; 
	        cin>>answer_2; 
		  game_2( 1, answer_2 ); 
	break;

	////////////////////////////////////////////////////////
	//
	//
	//////////////////// 로또게임 /////////////////////////
	 case 2:
	srand((unsigned int)time(0));
	int lotto_2[45] = {},ar_2[6],money_2=100;
	cout<<"가진돈 : "<<money_2<<endl;
L:
	cout<<"번호입력 : ";
	for(int i=0;i<6;i++){
		cin>>ar_2[i];
	}


	for(int a_2=0;a_2<45;a_2++){
		lotto_2[a_2]=a_2+1;
	}
	int temp_2,index1_2,index2_2;
	for(int a_2=0;a_2<100;a_2++){
		index1_2=rand()%45;
		index2_2=rand()%45;
		temp_2=lotto_2[index1_2];
		lotto_2[index1_2]=lotto_2[index2_2];
		lotto_2[index2_2]=temp_2;
	}
	for(int a_2=0;a_2<5;a_2++){
		cout<<lotto_2[a_2]<<"|";
	}	
	cout<<"보너스 : "<< lotto_2[5]<<endl;
	int c_2=0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(ar_2[i]==lotto_2[j]){
				c_2++;
			}
		}
	}
	if(c_2==0 ){
		money_2=money_2/2;
		cout<<"가진돈 : "<<money_2<<endl;
	}
	else if(c_2==1 || c_2==2){
		money_2=money_2*2;
		cout<<"가진돈 : "<<money_2<<endl;
	}
	else if(c_2==3 || c_2==4 || c_2==5){
		money_2=money_2*4;
		cout<<"가진돈 : "<<money_2<<endl;
	}
	else if(c_2==6){
		money_2=money_2*8;
		cout<<"가진돈 : "<<money_2<<endl;
	}
	cout<<"다시 하시겠습니까[1/0] : ";
	int l_2;
	cin>>l_2;
	cout<<endl;
	if(l_2==1)
		goto L;
		
	break;
	}
	/////////////////////////////////////////////////////


return 0;
} 


///////////////////////////////////////////////////////////////
void game_2(int number_2, int answer_2) 
{ 
	  if( answer_2==0 ) 
		    { 
			        if( number_2%10==3 || number_2%10==6 || number_2%10==9 ) 
					    { 
						          cout<<setw(3)<<++number_2<<" : "; 
							        cin>>answer_2; 
								      game_2(number_2, answer_2); 
								         } 
				   else 
					      { 
						           cout<<"게임 종료"<<endl; 
							        return; 
								  } 
		    } 
	  else if(answer_2!=0 && answer_2!=-1) 
	  { 
		    if( number_2%10==3 || number_2%10==6 || number_2%10==9 || number_2%10==0 || number_2%10==5) 
			      { 
				          cout<<"게임 종료"<<endl; 
					      return; 
					       } 
		     else if( number_2!=answer_2 ) 
			      { 
				         cout<<"게임 종료"<<endl; 
					    return; 
			      } 
		    else 
		    { 
			      cout<<setw(3)<<++number_2<<" : "; 
			        cin>>answer_2; 
				  game_2(number_2, answer_2); 
		    } 
	  } 
	  else if(answer_2==-1){
	  	if(number_2%10==0 || number_2%10==5){
			cout<<setw(3)<<++number_2<<" : ";
			cin>>answer_2;
			game_2(number_2,answer_2);
		}
		else{
			cout<<"게임 종료"<<endl;
			return;
		
		}
	  }
} 
