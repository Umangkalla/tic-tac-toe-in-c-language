#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#define termination 777

//to display the board
void display_table(char board[]){
    int i,j;
    for(i=0;i<9;i++){
            printf("%c",board[i]);
            if (((i + 1) % 3) == 0) {
			printf("\n");
            }
        
    }
}

//to assign the value and position
void side(char board[],char *turn){
   int position;
   char check = 'n';
   while(check == 'n'){
   printf("Turn of %c", *turn);
   printf("\nEnter position: ");
   scanf("%d", &position);
   if (position == termination) {
      exit(0);
   }
   if(board[position - 1]=='X' || board[position -1]=='O'){
      printf("Position already occupied please make your turn somewhere else\n");
   } 
   else{
      board[position - 1] = *turn;
      check = 'y';
      }
   }
   check = 'n';
}
//to switch turn to another player
void switch_turn(char *turn) {
   if (*turn == 'X') {*turn = 'O';}
   else {*turn = 'X';}
}

//to check wheather the player win or not
bool win_loose(char board[]) {
   bool win = false;
   //Row 1
   if (board[0] != '_') {
      if (board[0] == board[1]) {
         if (board[0] == board[2]) {
            win = true;
         }
      }
   }
//Row 2
   if (board[3] != '_') {
      if (board[3] == board[4]) {
         if (board[3] == board[5]) {
            win = true;
         }
      }
   }
//Row 3
   if (board[6] != '_') {
      if (board[6] == board[7]) {
         if (board[6] == board[8]) {
            win = true;
         }
      }
   }
//Column 1
   if (board[0] != '_') {
      if (board[0] == board[3]) {
         if (board[0] == board[6]) {
            win = true;
         }
      }
   }
//Column 2
   if (board[1] != '_') {
      if (board[1] == board[4]) {
         if (board[1] == board[7]) {
            win = true;
         }
      }
   }
//Column 3
   if (board[2] != '_') {
      if (board[2] == board[5]) {
         if (board[2] == board[8]) {
            win = true;
         }
      }
   }
//diognal 1
   if (board[0] != '_') {
      if (board[0] == board[4]) {
         if (board[0] == board[8]) {
            win = true;
         }
      }
   }
//diognal 2
   if (board[2] != '_') {
      if (board[2] == board[4]) {
         if (board[2] == board[6]) {
            win = true;
         }
      }
   }
return win;

}

//to check for draw
bool draw(int turn_count) {
   if (turn_count < 9) {
      return false;
   }
   else {
      return true;
   }
}