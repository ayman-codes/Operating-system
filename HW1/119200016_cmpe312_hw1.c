#include  <stdio.h>
#include <string.h>

int playerTurn(int numTokens, int take);
int player2Turn(int numTokens, int take);
int computerTurn(int numTokens);
void gamestart(void);
void gameupdater(void);
void pvp(void);

// board has number of rows
struct Board{
    int rows;
};
int row_define(struct Board, int);
//int rows = 5;
int r1,r2,r3,r4,r5;
int nextTokens, nextTokens2;
int player_counter1, player_counter2;




int main() {
    printf("=================================WELCOME to NIM game===============================");
    printf("\na) Start the game\nb)Play Multiplayer\n");

    char choice[1];
    scanf("%s", choice);
    //printf(choice);
    //gamestart();

    struct Board b = {0};

    row_define(b, 5);
    if (strcmp(choice, "a") == 0){
        gamestart();
    }

    else if(strcmp(choice, "b") == 0){
        gamestart();
        pvp();
    }

    //gameupdater();
}

// Define each row's value
int row_define(struct Board b, int rows){
    /*
    this is based on 2n-1 equation usually used for pyramids printing
    The reason why we need this is because we want to print the board
    After each move
    */
   rows = 5;
   b.rows = rows;
    for(int i=0; i<= rows; i++){
        if(i==0){
            r1 = i*2+1;
        }
        if(i==1){
            r2 = i*2+1;
        }
        if(i==2){
            r3 = i*2+1;
        }
        if(i==3){
            r4 = i*2+1;
        }
        if(i==4){
            r5 = i*2+1;
        }
    }
    return r5,r4,r3,r2,r1;
}

// Define function to load up the initial game board
void gamestart(){
    /*
    What this function does is check if each row is empty or not
    if row r5 is not empty then it will print 4 rows else if row 4 is 
    not empty then it will print 4 rows and so on. if all rows are empty
    it will display a game over message
    */
   struct Board b = {}
    printf("\n");
    int i, space, k = 0;
    if (r5!=0){
        for (i = 1; i <= rows; ++i, k = 0) {
        for (space = 1; space <= rows - i; ++space) {
            printf("  ");
        }
        while (k != 2 * i - 1) {
            printf("I ");
            ++k;
        }
        printf("\n");
        } 
    }

   else if(r4 != 0){
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

void gameupdater(){

	while(r5>0)
	{
        printf("You're on Row: %d\n", 5);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove;
		scanf("%i", &ms_remove);
		
		int nextTokens = playerTurn(r5, ms_remove);
		
		if (nextTokens == r5)
		{
			continue;
		}
		
		r5 = nextTokens;
		
		r5 = computerTurn(r5);
	}
    r5 = 0;
    gamestart();

	while(r4>0)
	{
        printf("You're on Row: %d\n", 4);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove;
		scanf("%i", &ms_remove);
		
		int nextTokens = playerTurn(r4, ms_remove);
		
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
		
		int nextTokens = playerTurn(r3, ms_remove);
		
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
		
		int nextTokens = playerTurn(r2, ms_remove);
		
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
		
		int nextTokens = playerTurn(r1, ms_remove);
		
		if (nextTokens == r1)
		{
			continue;
		}
		
		r1 = nextTokens;
		
		r1 = computerTurn(r1);
	}

	printf("Computer wins.");
}


void pvp(){

	while(r5>0)
	{
        printf("Player 1 Turn >>>> ");
        printf("You're on Row: %d\n", 5);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove;
		scanf("%i", &ms_remove);
		
		nextTokens = playerTurn(r5, ms_remove);
        player_counter1 = nextTokens;
		
		if (nextTokens == r5)
		{
			continue;
		}
		
		r5 = nextTokens;


        if (r5 == 0)
		{
			continue;
		}

		printf("\n\nPlayer 2 turn >>>> ");
        printf("You're on Row: %d\n", 5);
		printf("How many matchsticks would you like to remove? ");
		
		int ms_remove2;
		scanf("%i", &ms_remove2);

		nextTokens2 = player2Turn(r5, ms_remove2);
        player_counter2 = nextTokens2;
		
		r5 = nextTokens2;
	}
    r5 = 0;
    gamestart();


	while(r4>0)
	{
        if(player_counter1 < player_counter2){
            printf("Player 1 Turn >>>> ");
            printf("You're on Row: %d\n", 4);
            printf("How many matchsticks would you like to remove? ");
            
            int ms_remove;
            scanf("%i", &ms_remove);
            
            nextTokens = playerTurn(r4, ms_remove);
            player_counter1 = nextTokens;
            
            if (nextTokens == r4)
            {
                continue;
            }
            
            r4 = nextTokens;

            if (r4 == 0)
            {
                continue;
            }
        }

        else if (player_counter1 > player_counter2 || player_counter1 == player_counter2)
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
            player_counter1 = nextTokens;
            
            if (nextTokens == r3)
            {
                continue;
            }
            
            r3 = nextTokens;

            if (r3 == 0)
            {
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
            player_counter1 = nextTokens;
            
            if (nextTokens == r2)
            {
                continue;
            }
            
            r2 = nextTokens;

            if (r2 == 0)
            {
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
            player_counter1 = nextTokens;

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
                continue;
            }
        }

        else if (player_counter1 > player_counter2 || player_counter1 == player_counter2)
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

int playerTurn(int numTokens, int take)
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
	int take = numTokens % 4;
	int remainingTokens = numTokens - take;
	
	printf("Computer takes %u tokens.\n", take);
	printf("%i tokens remaining.\n\n", remainingTokens);
	
	return remainingTokens;
}