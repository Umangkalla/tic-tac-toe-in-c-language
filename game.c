#include <stdio.h>
#include <stdbool.h>
#include "rules.h"
#include <stdlib.h>
#include <conio.h>



//now we will write code for game 
int main(){
    char board[]={'_','_','_','_','_','_','_','_','_'},turn='X';
    bool game = true;
    int turn_count=0;

    printf("WELCOME TO TIC TAC TOE!!!!!\n type '777' to exit\n\n");
    while(game){
        display_table(board);
		side(board, &turn);
		turn_count++;
        if (win_loose(board)) {
			display_table(board);
			printf("%c Wins!!!", turn);
            getch();
			exit(0);
        }
       if (draw(turn_count)) {
			display_table(board);
			printf("Draw!!!");
			getch();
			exit(0);
		}
		switch_turn(&turn);
    }

    return 0;
}