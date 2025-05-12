#include <iostream>
#include <cstdlib>
#include <ctype.h>
#include <conio.h>

using namespace std;
//TicTacToe Game
void displayBoard(char board[3][3]);  //�����������
int checkGameStatus(char board[3][3],int row,int col,char current_player);

int main()
{
	system("CHCP 1253 > nul");
	
	char player1, player2, current_player;   //������ ����������
	char board[3][3];
	int row, col, game_status = 0, p=1 ,moves = 0 ;
	
	for(row=0; row< 3; row++)
	{
			for(col= 0; col< 3; col++)      //������� ��� ������ �� �� ������� (-)
			board[row][col]='-';
	}    
	cout<<endl<<endl<<"TicTacToe"<<endl;
	cout<<"----------------------"<<endl<<endl<<endl;
	cout<<"       "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
	cout<<"      "<<"---+---+---"<<endl;
	cout<<"       "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
	cout<<"      "<<"---+---+---"<<endl;
	cout<<"       "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl<<endl<<endl;
	cout<<"Player 1 please choose the symbol you want to play with:type 'O', or 'X': ";
	player1=getch();
	player1=toupper(player1);
	cout<<endl<<endl;
	//������� ��� ��� ���������� ��� ������ ��������.
	while(player1 != 'X' && player1 != 'O')
	{
		cout<<"Wrong symbol please try putting O or X : ";
		player1=getch();
		player1=toupper(player1);
		cout<<endl<<endl;
	}
	if(player1=='O')
		player2='X';
	else
		player2='O';
	cout<<"Player 2 your symbol is: "<<player2<<endl<<endl;
	current_player=player2;
	//����� ��� ��� �������� ��� ���� ������� �������, � ����� ��������� �������� ���� ����� ������� 9 ��������.
	while(game_status==0 && moves<9)
	{
		moves++;
		if(current_player==player1)
		{
			current_player=player2;
			p=2;
		}
	    else
		{
			current_player=player1;
			p=1;
	    }
		cout<<"Player "<<p;
		cout<<" give me the row and column you want your symbol to be put(for exaple 0 0): ";
		cin>>row>>col;
		cout<<endl<<endl;
		while(row<0 || row>2 || col<0 || col>2)   //������� ������ �������������
		{
			cout<<"Wrong move. Try again: \n\n";
			cout<<"Give me the row and column you want your symbol to be put(for exaple 0 0): ";
			cin>>row>>col;
		}
		while (board[row][col] == 'X' || board[row][col] == 'O') //������� ��� � ���� ����� �����
		{
			cout << "Cell already occupied! Try again.\n\n";
			cout<<"Give me the row and column you want your symbol to be put(for exaple 0 0): ";
			cin>>row>>col;
			cout<<endl;
		}
        
		game_status=checkGameStatus(board, row, col, current_player);
		system("CLS");
		displayBoard(board);	
	}
	//�������� ������ � ���������.
	if(game_status==1)
		cout<<"Player "<<p<<" you won the match\n\n";
	else
		cout<<"The game ended in a draw :)\n\n";
	system("PAUSE");
	return 0;
}

//��������� ��� �� �������� ��� ������ ���� ���� ��� ������ ���� �������
void displayBoard(char board[3][3])
{
	cout<<endl<<endl<<"TicTacToe"<<endl;
	cout<<"----------------------"<<endl<<endl<<endl;
	cout<<"       "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
	cout<<"      "<<"---+---+---"<<endl;
	cout<<"       "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
	cout<<"      "<<"---+---+---"<<endl;
	cout<<"       "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl<<endl<<endl;	
}

//��������� ��� ���������� ��� �������� ��� ������ ��� ������ ���������� ��� ����������
int checkGameStatus(char board[3][3],int row ,int col,char player)
{
	int status=0;
	
	board[row][col]=player;
	for(int i=0; i<3; i++)
	{
		//��������� ��� ������ ����
		if(board[i][0]==player && board[i][1]==player && board[i][2]==player || board[0][i]==player && board[1][i]==player && board[2][i]==player)
			status=1;
		//������ ����
		if(board[0][0]==player && board[1][1]==player && board[2][2]==player || board[2][0]==player && board[1][1]==player && board[0][2]==player)
			status=1;	
	}
	return status;		
}
