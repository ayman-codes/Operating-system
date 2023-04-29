#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Initialize methods
int playerTurn(int numTokens, int take);
int player2Turn(int numTokens, int take);
int computerTurn(int numTokens);
void gamestart(void);
void player_VS_PC(void);
void pvp(void);
int row_define();

// Global variables
int rows = 5;
int r1,r2,r3,r4,r5;
int nextTokens, nextTokens2;
int player_counter1, player_counter2;

// We will edit board structure later so that
// we update the variables inside board and use
// them inside the functions
struct Board{
    int current_row;
    int removed_matchstick;
};


int main() {
    printf("=================================WELCOME to NIM game===============================");
    printf("\na) Inspect the initial board\nb)Play Multiplayer\nc) Play vs computer\n");

	//get user input
    char choice[1];
    scanf("%s", choice);

	//Start the initial board and define rows
    row_define();

    if (strcmp(choice, "a") == 0){ //if input is equal to a
        gamestart(); //print initial board
    }

    else if(strcmp(choice, "b") == 0){ // if input is b
        gamestart(); //start initial board
        pvp(); //start multiplayer method
    }

	else if (strcmp(choice, "c") == 0){ //if input is c
        gamestart(); //start initial board
        player_VS_PC(); // play vs computer
    }
}

// Define each row's value
int row_define(){
    /*
    this is based on 2n-1 equation usually used for pyramids printing
    The reason why we need this is because we want to print the board
    After each move
    */
    for(int i=0; i<= rows; i++){
        if(i==0){ //matchsticks in row 1
            r1 = i*2+1; // matchsticks are 0*2+1 = 1
        }
        if(i==1){ //row 2
            r2 = i*2+1; //matchsticks are (1*2+1) = 3
        }
        if(i==2){ //row 3
            r3 = i*2+1; //matchsticks are (2*2+1) = 5 
        }
        if(i==3){ //row 4
            r4 = i*2+1; //matchsticks are (3*2+1) = 7
        }
        if(i==4){ //row 5
            r5 = i*2+1; //matchsticks are (4*2+1) = 9
        }
    }
    return r5,r4,r3,r2,r1; //return matchsticks values
}

// Define function to load up the initial game board
void gamestart(){
    /*
    What this function does is check if each row is empty or not
    if row r5 is not empty then it will print 4 rows else if row 4 is 
    not empty then it will print 4 rows and so on. if all rows are empty
    it will display a game over message
    */
    printf("\n");
    int i, space, k = 0;

	//if row isn't empty
    if (r5!=0){
		//print matchsticks for 5 rows
        for (i = 1; i <= rows; ++i, k = 0) { // row definition
        for (space = 1; space <= rows - i; ++space) { // make space for matchsticks
            printf("  ");
        }
        while (k != 2 * i - 1) { // 2n-1 where n is the row
            printf("I "); //print matchsticks
            ++k;
        }
        printf("\n");
        } 
    }

	//if row 4 isn't empty
   else if(r4 != 0){
	//print matchsticks for 4 rows
        for (i = 1; i <= 4; ++i, k = 0) {
            for (space = 1; space <= 4 - i; ++space) {
                printf("  ");
            }
            while (k != 2 * i - 1) {
                printf("I ");
                ++k;
            }
        printf("\n");
        } 
   }   

	//the same goes on
    else if (r3!=0){
        for (i = 1; i <= 3; ++i, k = 0) {
        for (space = 1; space <= 3 - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("I ");
            ++k;
        }
        printf("\n");
        } 
    }

    else if (r2!=0){
        for (i = 1; i <= 2; ++i, k = 0) {
        for (space = 1; space <= 2 - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("I ");
            ++k;
        }
        printf("\n");
        } 
    }

    else if (r1!=0){
        for (i = 1; i <= 1; ++i, k = 0) {
        for (space = 1; space <= 1 - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("I ");
            ++k;
        }
        printf("\n");
        } 
    }
}

void player_VS_PC(){

	//check if row 5 isn't empty
	while(r5>0)
	{
        printf("You're on Row: %d\n", 5);
		printf("How many matchsticks would you like to remove? ");
		
		//get user input
		int ms_remove;
		scanf("%i", &ms_remove);
		
		//subtract r5 from the user input
		nextTokens = playerTurn(r5, ms_remove);
		
		//check if user takes all inputs
		if (nextTokens == r5)
		{
			continue; //jump back to start of the loop
		}
		
		r5 = nextTokens; //set r5 to the remainder of matchsticks
		
		r5 = computerTurn(r5); //computer removes matchsticks and returns remainder
	}
    r5 = 0; //when it's empty we set r5 to zero for the other loops
    gamestart(); //print the new board

	while(r4>0)
	{
        printf("You're on Row: %d\n", 4);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove;
		scanf("%i", &ms_remove);
		
		nextTokens = playerTurn(r4, ms_remove);
		
		if (nextTokens == r4)
		{
			continue;
		}
		
		r4 = nextTokens;
		
		r4 = computerTurn(r4);
	}
    r4 = 0;
    gamestart();

	while(r3>0)
	{
        printf("You're on Row: %d\n", 3);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove;
		scanf("%i", &ms_remove);
		
		nextTokens = playerTurn(r3, ms_remove);
		
		if (nextTokens == r3)
		{
			continue;
		}
		
		r3 = nextTokens;
		
		r3 = computerTurn(r3);
	}
    r3 = 0;
    gamestart();

	while(r2>0)
	{
        printf("You're on Row: %d\n", 2);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove;
		scanf("%i", &ms_remove);
		
		nextTokens = playerTurn(r2, ms_remove);
		
		if (nextTokens == r2)
		{
			continue;
		}
		
		r2 = nextTokens;
		
		r2 = computerTurn(r2);
	}
    r2 = 0;
    gamestart();

	while(r1>0)
	{
        printf("You're on Row: %d\n", 1);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove;
		scanf("%i", &ms_remove);
		
		nextTokens = playerTurn(r1, ms_remove);
		
		if (nextTokens == r1)
		{
			continue;
		}
		
		r1 = nextTokens;
		
		r1 = computerTurn(r1);
	}
	//if user was last to draw user lost
	printf("Computer wins.");
}


void pvp(){

	//check if row is empty
	while(r5>0)
	{
        printf("Player 1 Turn >>>> ");
        printf("You're on Row: %d\n", 5);
		printf("How many matchsticks would you like to remove? ");
		
		//user input
		int ms_remove;
		scanf("%i", &ms_remove);
		
		//remove matchsticks and get new matchsticks value
		nextTokens = playerTurn(r5, ms_remove);

		
		
		//jump to start loop if it's the same
		if (nextTokens == r5)
		{
			continue;
		}
		
		//set matchsticks to the remaining matchsticks values
		r5 = nextTokens;

		//if user removes all matchsticks return to start loop
        if (r5 == 0)
		{
			//this is used to keep track of user's turn
        	player_counter1 = nextTokens;
			continue;
		}

		//else we continue to user 2
		printf("\n\nPlayer 2 turn >>>> ");
        printf("You're on Row: %d\n", 5);
		printf("How many matchsticks would you like to remove? ");
		
		//same steps applies
		int ms_remove2;
		scanf("%i", &ms_remove2);

		nextTokens2 = player2Turn(r5, ms_remove2);
        player_counter2 = nextTokens2;
		
		r5 = nextTokens2;
	}
    r5 = 0; //when game ends of 5 rows set row 5 to zero
    gamestart(); //start the new board


	while(r4>0)
	{
		//check who's turn was last if player 2 has more
		// matchsticks then it's his turn since last player to 
		//remove matchsticks his/her matchsticks will be fewer
        if(player_counter1 < player_counter2){
            printf("Player 1 Turn >>>> ");
            printf("You're on Row: %d\n", 4);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove;
            scanf("%i", &ms_remove);
            
            nextTokens = playerTurn(r4, ms_remove);
            
            
            if (nextTokens == r4)
            {
				player_counter1 = nextTokens;
                continue;
            }
            
            r4 = nextTokens;

            if (r4 == 0)
            {
                continue;
            }
        }

        else
        {
            printf("\n\nPlayer 2 turn >>>> ");
            printf("You're on Row: %d\n", 4);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove2;
            scanf("%i", &ms_remove2);
            nextTokens2 = player2Turn(r4, ms_remove2);
            player_counter2 = nextTokens2;

            r4 = nextTokens;
        }
	}
    r4 = 0;
    gamestart();

	while(r3>0)
	{
        if(player_counter1 < player_counter2){
            printf("\n\nPlayer 1 turn >>>> ");
            printf("You're on Row: %d\n", 3);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove;
            scanf("%i", &ms_remove);
            
            nextTokens = playerTurn(r3, ms_remove);
            
            
            if (nextTokens == r3)
            {
                continue;
            }
            
            r3 = nextTokens;

            if (r3 == 0)
            {
				player_counter1 = nextTokens;
                continue;
            }
        }

		else
        {
            printf("\n\nPlayer 2 turn >>>> ");
            printf("You're on Row: %d\n", 3);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove2;
            scanf("%i", &ms_remove2);
            nextTokens2 = player2Turn(r3, ms_remove2);
            player_counter2 = nextTokens2;

            r3 = nextTokens;
        }
	}
    r3 = 0;
    gamestart();

	while(r2>0)
	{
        if(player_counter1 < player_counter2){
            printf("\n\nPlayer 1 turn >>>> ");
            printf("You're on Row: %d\n", 3);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove;
            scanf("%i", &ms_remove);
            
            nextTokens = playerTurn(r2, ms_remove);
            
            
            if (nextTokens == r2)
            {
                continue;
            }
            
            r2 = nextTokens;

            if (r2 == 0)
            {
				player_counter1 = nextTokens;
                continue;
            }
        }

		else if (player_counter1 > player_counter2 || player_counter1 == player_counter2)
        {
            printf("\n\nPlayer 2 turn >>>> ");
            printf("You're on Row: %d\n", 3);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove2;
            scanf("%i", &ms_remove2);
            nextTokens2 = player2Turn(r2, ms_remove2);
            player_counter2 = nextTokens2;

            r2 = nextTokens;
        }
	}
    r2 = 0;
    gamestart();

	while(r1>0)
	{
        if(player_counter1 < player_counter2){

            printf("\n\nPlayer 1 turn >>>> ");
            printf("You're on Row: %d\n", 1);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove;
            scanf("%i", &ms_remove);
            
            int nextTokens = playerTurn(r1, ms_remove);
            

            if(nextTokens == 0){
                printf("PLAYER 1 LOST! CONGRATULATIONS PLAYER 2");
            }
            
            if (nextTokens == r1)
            {
                continue;
            }
            
            r1 = nextTokens;
            
            if (0 == r1)
            {
				player_counter1 = nextTokens;
                continue;
            }
        }

        else
        {
            printf("\n\nPlayer 2 turn >>>> ");
            printf("You're on Row: %d\n", 2);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove2;
            scanf("%i", &ms_remove2);
            nextTokens2 = player2Turn(r1, ms_remove2);
            player_counter2 = nextTokens2;

            if(nextTokens == 0){
                printf("PLAYER 1 LOST! CONGRATULATIONS PLAYER 2");
            }

            r1 = nextTokens;
        }
	}
}

//define player choices
int playerTurn(int numTokens, int take)
{
	//invalid input
	if (take < 1 || take > 9)
	{
		printf("\nYou MUST remove a matchstick between 1 and 9.\n\n");
		return numTokens;
	}
	//subtract the total matchsticks from user input and return the remaining
	int remainingTokens = numTokens - take;
	
	printf("\nPlayer takes %i matchsticks.\n", take);
	printf("%i matchsticks remaining.\n\n", remainingTokens);
	
	return remainingTokens;
}

int player2Turn(int numTokens, int take)
{
	if (take < 1 || take > 9)
	{
		printf("\nYou MUST remove a matchstick between 1 and 9.\n\n");
		return numTokens;
	}
	int remainingTokens = numTokens - take;
	
	printf("\nPlayer takes %i matchsticks.\n", take);
	printf("%i matchsticks remaining.\n\n", remainingTokens);
	
	return remainingTokens;
}


int computerTurn(int numTokens)
{
	//computer will pick a random value
	srand(time(NULL));
	int r;
	int take;

	//if remaining matchsticks aren't zero
	if(numTokens>0){
		//pick a random value range 0 to total number of matchsticks
		r = rand() % numTokens; 
		// computer takes between total value of matchsticks and random int
		take = numTokens % r;
		if(take == 0){
			take=1; //don't allow computer to pick 0 if it has choice
		}
	}
	
	//if no matchsticks remaining
	else if(numTokens==0){
		take = 0; //take zero
	}
	
	//remaining matchsticks
	int remainingTokens = numTokens - take;
	
	printf("Computer takes %u tokens.\n", take);
	printf("%i tokens remaining.\n\n", remainingTokens);
	
	return remainingTokens;
}
/*
int computerTurn(int numTokens)
{
	int take = numTokens % 4;
	int remainingTokens = numTokens - take;
	
	printf("Computer takes %u tokens.\n", take);
	printf("%i tokens remaining.\n\n", remainingTokens);
	
	return remainingTokens;
}
//this part works better but i wanted to show case a smarter pc
*/