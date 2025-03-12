#include <stdio.h>
#include <stdlib.h>

char checkend(char[9]);

int main() {
  
  char board[9];

  for (int i = 0; i < 9; i++) {
    board[i] = ' ';
  }

  int choice = 100;
  int shape = 'X';

  while (1==1) {

    system("clear");

    printf(" %c | %c | %c\n---|---|---\n %c | %c | %c\n---|---|---\n %c | %c | %c\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);

    while (100 == choice) {
      printf("(1-9): ");
      scanf("%d", &choice);

      if (choice > 9 || choice < 1) {
        printf("Error: number is not in range 1-9, %d.\n", choice);
        choice = 100;
      } else if (board[choice-1] == 'O' || board[choice-1] == 'X') {
        printf("Error: place on the board already taken!\n");
        choice = 100;
      }
    }
    
    board[choice-1] = shape;
    shape = ('X' == shape) ? 'O' : 'X';
    choice = 100;
    
    if ('O' == checkend(board) || 'X' == checkend(board)) {
      system("clear");
      printf(" %c | %c | %c\n---|---|---\n %c | %c | %c\n---|---|---\n %c | %c | %c\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
      break;
    }
  }

  printf("You Won!\n");
  return 0;
}

char checkend(char board[9]) {
  if (board[0] == board[1] && board[2] == board[0]) {return board[0];}
  else if (board[3] == board[4] && board[5] == board[3]) {return board[3];}
  else if (board[6] == board[7] && board[8] == board[6]) {return board[6];}
  else if (board[0] == board[3] && board[0] == board[6]) {return board[0];}
  else if (board[1] == board[4] && board[7] == board[1]) {return board[1];} 
  else if (board[2] == board[5] && board[8] == board[2]) {return board[2];}
  else if (board[0] == board[4] && board[8] == board[0]) {return board[0];}
  else if (board[6] == board[4] && board[2] == board[6]) {return board[6];}

  return 'N';
}
