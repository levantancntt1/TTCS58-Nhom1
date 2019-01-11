#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

  char vitri[3][3] =  {{'1', '2', '3'},{ '4', '5', '6'},{ '7', '8', '9'}};
        
  void VeBanCo() // Hàm ve bàn co 
        {
            cout<<vitri[0][0]<<"  |  "<<vitri[0][1]<<"  |  "<<vitri[0][2]<<endl ;
            cout<<"-------------------"<<endl;
            cout<<vitri[1][0]<<"  |  "<<vitri[1][1]<<"  |  "<<vitri[1][2]<<endl ;
            cout<<"-------------------"<<endl;
            cout<<vitri[2][0]<<"  |  "<<vitri[2][1]<<"  |  "<<vitri[2][2]<<endl ;
        }
        void VeBanCo();
        void luotchoi();
        bool gameover();
        char turn;
        bool draw = false;
  void luotchoi()
        {
        	int choice;
        	int row = 0, column = 0;
        	if(turn == 'X')
        	{
        		cout<<"Nguoi choi thu nhat (X): ";
        	}
        	else if(turn == 'O')
        	{
        		cout<<"Nguoi choi thu hai (O)";
        	}
        	cin>>choice;
        	switch(choice)
        	{
        		case 1: row = 0; column = 0; break;
        		case 2: row = 0; column = 1; break;
				case 3: row = 0; column = 2; break;
				case 4: row = 1; column = 0; break;
				case 5: row = 1; column = 1; break;
				case 6: row = 1; column = 2; break;
				case 7: row = 2; column = 0; break;
				case 8: row = 2; column = 1; break;
				case 9: row = 2; column = 2; break;
				default:
					cout<<"Ban khong the danh tai vi tri nay!"<<endl;
					luotchoi();
        	}
        	if(turn == 'X' && vitri[row][column] != 'X' && vitri[row][column] !='O')
        	{
        		vitri[row][column] = 'X';
        		turn ='O';
        	}
        	else if(turn == 'O' && vitri[row][column] != 'X' && vitri[row][column] != 'O')
        	{
        		vitri[row][column] = 'O';
        		turn = 'X';
        	}
        	else
        	{
        		cout<<"Khong the danh tai vi tri nay!"<<endl;
        		luotchoi();
        	}
        }
        bool gameover()
        {
        	for(int i = 0; i < 3; i++) //Kiem tra thang
        	{
        		if((vitri[i][0] == vitri[i][1] && vitri[i][1] == vitri[i][2]) || (vitri[0][i] == vitri[1][i] && vitri[1][i] == vitri[2][i]) || (vitri[i][0] == vitri[1][1] && vitri[i][0] == vitri[2][2])||(vitri[i][2] == vitri[1][1] && vitri[i][0] == vitri[2][0]))
        		{
        			return true;
        		}
        	}
        	for(int i = 0; i < 3; i++) // Kiem tra hoa
        	{
        		for(int j = 0; j < 3; j++)
        		{
        			if(vitri[i][j] != 'X' && vitri[i][j] != 'O')
        			{return false;
        			}
        		}
        	}
        	draw = true;
        	return true;
        }
int main()
{
	cout<<"Tic Tac Toe"<<endl;
	cout<<"Nguoi choi 1: X"<<endl;
	cout<<"Nguoi choi 2: O"<<endl;
	turn = 'X';
	while(!gameover())
	{  
		VeBanCo();
		luotchoi();
		system("cls");
		gameover();
	}
	if(turn == 'O' && !draw)
	{   cin.ignore();
		VeBanCo();
		cout<<endl<<"Nguoi choi 1 thang!"<<endl;
	}
	else if(turn = 'X' && !draw)
	{   cin.ignore();
		VeBanCo();
		cout<<endl<<"Nguoi choi 2 thang!"<<endl;
	}
	else
	{   cin.ignore();
		VeBanCo();
		cout<<endl<<"Tro choi hoa!"<<endl;
	}
	
}
        
