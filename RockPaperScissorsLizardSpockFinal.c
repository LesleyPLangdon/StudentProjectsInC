/* 
 * File:   main.c
 * Author: Lesley Potts-Langdon
 *
 * Created on October 21, 2016, 6:48 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char plAgain;//for inner do/while loop
char newPlay;//for outer do/while loop
int compC, playC;//to hold computer and player selections
int compWins;//to track number of games computer wins
int playWins;//to track number of games player wins
int draw;//to track number of ties
char plName[16];//to store player name
int totalGames;
float percentWon;
/*
 * main provides two do/while loops to control repeat games by one player or 
 * the option to switch to a new player.
 * Inside the inner loop functions are used to display the instructions, 
 * determine the computers choice, display that choice, play the game and
 * display the cumulative score.  The option is then given to play again.
 * The outer loop asks for the player name, resets scores to zero and gives
 * the option for a new player to play after one declines to play again.
 */
int main() {
        
    do
    {
    printf("Welcome to rock, paper, scissors, lizard, Spock.\n\n"
            "please enter your first name:  ");//asks for player name
    scanf("%s", &plName);//stores player name
    //gets( plName ); //stores player name
    compWins=0;//initializes or resets computer score to zero
    playWins=0;//initializes or resets player score to zero
    draw=0;//initializes or resets draws to zero
    
    do
    {
        instructions();//calls instructions function
        compC = compChoice();//sets computer choice
        displayCompChoice();//displays the computer choice
        playGame();//calls function to play game
        displayScore();//calls function to display the score
        playAgain();//calls function to ask if player wants to play again
    
    }while(plAgain=='y');//y sends back to beginning of loop
    percentWon = (playWins/totalGames)*100;
    printf("you won ");
    printf("%f", percentWon);
    printf("%s","% of the games");
    
    newPlayer();//calls function to ask if a new player wants to play
    
            
    }while(newPlay=='y');//y sends back to beginning of loop
    
    printf("\n\n Thank you for playing\n\n");
    
    
    scanf("%s");
    
    
    return(0);//should close program but doesn't seem to??
}
/*instructions function asks player make a selection and stores that 
 * selection in playC
 * preconditions: player has entered their name
 * postconditions: player has made selection
 */
void instructions()
{
    do{
    printf("Please select 1 for rock, 2 for paper, 3 for scissors, " 
                "4 for lizard and 5 for Spock.");
        scanf("%d",&playC);
    }while(playC<1||playC>5);//loops back till user makes valid selection
}
/*compChoice function uses random function to select a number between 1 and 5
 * to use as the computers choice
 * preconditions: none
 * postconditions: computer random selection made
 */
int compChoice()
{
    srand(time(NULL));
    return rand()%5+1;
}
/*displayCompChoice function prints out the computers selection
 * preconditions: computer selection made
 * postconditions: computer selection displayed
 */
void displayCompChoice()
{
    if(compC==1)
            printf("\nComputer chose Rock\n");
        else if(compC==2)
            printf("\nComputer chose Paper\n");
        else if(compC==3)
            printf("\nComputer chose Scissor\n");
        else if(compC==4)
            printf("\nComputer chose Lizard\n");
        else
            printf("\nComputer chose Spock\n");
}
/*playAgain function asks the player if they want to go again and stores
 * answer in plAgain
 * preconditions: game has cycled through at least once
 * postconditions: game cycles again or exits
 */
void playAgain()
{
    printf("\n\nPress y to go again?  ");
    scanf("%s", &plAgain);
    plAgain = tolower(plAgain);//converts to lowercase letter
}
/*newPlayer function is called after player says they don't want to play 
 * again to ask if another player wants to play
 * preconditions: game loop has exited
 * postconditions: game restarts for new player or exits
 */
void newPlayer()
{
    
    printf("\n\nPress y if another player like to try?  ");
    scanf("%s", &newPlay);
    newPlay = tolower(newPlay);//converts to lower case letter
}
/*displayScore function displays the cumulative score for computer, player
 * and number of ties
 * preconditions: at least one round of play has ended
 * postconditions: score is displayed
 */
void displayScore()
{
    printf("\nComputer has won ");
        printf("%d", compWins);
        printf(" game(s)");
        printf("%s", plName);
        printf(" has won ");
        printf("%d", playWins);
        printf(" game(s)\n");
        printf("%d", draw);
        printf(" game(s) have been ties");
}
/*Five different if statements to determine the winner
 * preconditions: player and computer have made selections
 * postcondition: winner is determined and outcome displayed
 */
void playGame()
{
   if(compC == 1)
            if(playC==1){
                printf("You both chose Rock, it is a draw");
                draw++;
                totalGames++;
            }
            else if(playC==2){
                printf("\nPaper covers Rock. \n");
                playerWins();
            }
            else if(playC==3){
                printf("\nRock smashes Scissors. \n");
                computerWins();
            }
            else if(playC==4){
                printf("\nRock crushes Lizard. \n");
                computerWins();
            }
            else if(playC==5){
                printf("\nSpock vaporizes Rock. \n");
                playerWins();
            }  
   if(compC == 2)
            if(playC==1){
                printf("\nPaper covers Rock. \n");
                computerWins();
            }
            else if(playC==2){
                printf("\nYou both chose Paper. It's a draw.\n");
                draw++;
                totalGames++;
            }
            else if(playC==3){
                printf("\nScissors cut Paper. \n");
                playerWins();
            }
            else if(playC==4){
                printf("\nLizard eats Paper. \n");
                playerWins();
            }
            else if(playC==5){
                printf("\nPaper disproves Spock. \n");
                computerWins();
            }  
   if(compC == 3)
            if(playC==1){
                printf("\nRock smashes Scissors. \n");
                playerWins();
            }
            else if(playC==2){
                printf("\nScissors cut Paper. \n");
                computerWins();
            }
            else if(playC==3){
                printf("\nYou both chose Scissors.  It's a draw.\n");
                draw++;
                totalGames++;
            }
            else if(playC==4){
                printf("\nScissors decapitates Lizard. \n");
                computerWins();
            }
            else if(playC==5){
                printf("\nSpock vaporizes Scissors. \n");
                playerWins();
            } 
   if(compC == 4)
            if(playC==1){
                printf("\nRock crushes Lizard. \n");
                playerWins();
            }
            else if(playC==2){
                printf("\nLizard eats Paper.\n");
                computerWins();
            }
            else if(playC==3){
                printf("\nScissors decapitate Lizard. \n");
                playerWins();
            }
            else if(playC==4){
                printf("\nYou both picked Lizard.  It's a draw.\n");
                draw++;
                totalGames++;
            }
            else if(playC==5){
                printf("\nLizard poisons Spock. \n");
                computerWins();
            }  
   if(compC == 5)
            if(playC==1){
                printf("\nSpock vaporizes Rock. \n");
                computerWins();
            }
            else if(playC==2){
                printf("\nPaper disproves Spock.\n");
                playerWins();
            }
            else if(playC==3){
                printf("\nSpock smashes Scissor. \n");
                computerWins();
            }
            else if(playC==4){
                printf("\nLizard poisons Spock.\n");
                playerWins();
            }
            else if(playC==5){
                printf("\nYou both picked Spock. It's a draw.\n");
                draw++;
                totalGames++;
            }  
   
}
/*computerWins function announces computer as the winner and adds one to 
 * compWins total
 * preconditions: playGame() has determined the computer to be the winner
 * postconditions: winner is displayed and score updated
 */
void computerWins()
{
    printf("%s", plName);
    printf(" looses");
    compWins++;
    totalGames++;
}
/*playerWins function announces player as the winner and adds one to
 * playWins total
 * preconditions: playGame() has determined the player to be the winner
 * postcondition: winner is displayed and score updated
 */
void playerWins()
{
    printf("%s", plName);
    printf(" wins");
    playWins++;
    totalGames++;
}


