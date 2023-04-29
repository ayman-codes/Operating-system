#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get the player's move
void get_player_move(int* pile, int* stones, int board[]);

// function to get the computer's move
void get_computer_move(int* pile, int* stones, int board[]);


// main function
int main() {
    int board[5] = {5, 4, 3, 2, 1}; // starting board
    int pile, stones; // variables for the player's move
    int current_player = 1; // variable to keep track of the current player
    srand(time(NULL)); // seed the random number generator
    
    // main game loop
    while (1) {
        // print the current board
        printf("Current board:\n");
        int i, j;
        for (i = 0; i < 5; i++) {
            printf("Pile %d: ", i+1);
            for (j = 0; j < board[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
        // check if the game is over
        int game_over = 1;
        for (i = 0; i < 5; i++) {
            if (board[i] != 0) {
                game_over = 0;
                break;
            }
        }
        if (game_over) {
            printf("Game over! Player %d wins!\n", 3 - current_player);
            break;
        }
        // get the current player
        int pile, stones;
        if (current_player == 1) {
            get_player_move(&pile, &stones, board);
        } 
        else {
            get_computer_move(&pile, &stones, board);
        }
        // update the board
        board[pile] -= stones;
        // switch to the other player
        current_player = 3 - current_player;
    }
}

// function to get the player's move
void get_player_move(int* pile, int* stones, int board[]) {
// loop until a valid move is entered
    while (1) {
        printf("Which pile do you want to take stones from (1-5)? ");
        scanf("%d", pile);

        // check if the selected pile is valid and not empty
        if (*pile < 1 || *pile > 5 || board[*pile-1] == 0) {
            printf("Invalid pile, please try again.\n");
        continue;
        }

        printf("How many stones do you want to take (1-%d)? ", board[*pile-1]);
        scanf("%d", stones);

        // check if the selected number of stones is valid
        if (*stones < 1 || *stones > board[*pile-1]) {
            printf("Invalid number of stones, please try again.\n");
            continue;
        }

        // if the move is valid, exit the loop
        break;
    }
}

// function to get the computer's move
void get_computer_move(int* pile, int* stones, int board[]) {
    int i, nim_sum = 0;
    // calculate the nim-sum of the piles
    for (i = 0; i < 5; i++) {
        nim_sum ^= board[i];
    }
    // if the nim-sum is zero, choose a random move
    if (nim_sum == 0) {
        while (1) {
            pile = rand() % 5;

            if (board[*pile] != 0) {
            *stones = 1 + rand() % board[*pile];
            break;
            }
        }
    }

    // otherwise, make a winning move
    else {
        for (i = 0; i < 5; i++) {
            if ((nim_sum ^ board[i]) < board[i]) {
                *pile = i;
                *stones = board[i] - (nim_sum ^ board[i]);
                break;
            }
        }
    }

    // print the computer's move
    printf("Computer takes %d stones from pile %d.\n", *stones, *pile+1);
}