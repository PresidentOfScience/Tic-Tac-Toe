// Nama : Fendy Wijaya
// NIM : 2602092150
// Assignment I - Array 2D

#include <stdio.h>

void display_board(char board[3][3]){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%c", board[i][j]);
			if(j != 2) printf("|");
		}
		puts("");
		if(i != 2) printf("-+-+-\n");
	}
	puts("");
}

bool win_checker(char board[3][3]){
	for(int i=0; i<3; i++){
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
	}
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
	
	return 0;
}

int main(){
	printf("Tic-Tac-Toe Game Program\n");
	printf("--------------------------\n\n");

	char board[3][3] = {{'1', '2', '3'},
						{'4', '5', '6'},
						{'7', '8', '9'}};
	int turn = 0;
	bool check = 0;
	while(check == 0 && turn < 9){
		char move;
		if(turn % 2 == 0) printf("X's turn:\n");
		else printf("O's turn:\n");
		display_board(board);
		printf("Enter your move (1-9) : ");
		scanf("%c", &move); getchar();
		puts("");
		
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(turn%2 == 0 && move == board[i][j]) board[i][j] = 'X';
				else if(turn%2 == 1 && move == board[i][j]) board[i][j] = 'O';				
			}
		}
		
		check = win_checker(board);
		turn++;
	}
	
	if(check == 1 && turn % 2 == 1 && turn <= 9){
		printf("X wins!\n");
		display_board(board);
	}
	else if(check == 1 && turn % 2 == 0 && turn <= 9){
		printf("O wins!\n");
		display_board(board);
	}
	else{
		printf("No one wins the game!\n");
		display_board(board);
	}
	
	return 0;
}
