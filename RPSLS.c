
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * 
 */
int main() {
    int compC, playC;
    int compWins;
    int playWins;
    int draw;
    char plAgain=('n');
    char newPlay=('n');
    char plName[16];
    srand(time(NULL));
    while(newPlay==('y'||'Y'))
    {
    printf("please enter your first name:  ");
    gets( plName );
    
    compWins=0;
    playWins=0;
    draw=0;
    
    while(plAgain=='y'||'Y')
    {
        printf("Welcome to rock, paper, scissors, lizard, Spock. "
            "Please select 1 for rock, 2 for paper, 3 for scissors, " 
                "4 for lizard and 5 for Spock.");
        scanf("%d",&playC);
       
        compC = 1;
        
        if(compC == 1)
            if(playC==1)
            {
                printf("You both chose Rock, it is a draw");
                draw++;
            }
            else if(playC==2)
            {
                printf("\nPaper covers Rock. \n");
                printf("%s", plName);
                printf(" wins");
                playWins++;
            }
            else if(playC==3)
            {
                printf("\nRock smashes Scissors. \n");
                printf("%s", plName);
                printf(" looses");
                compWins++;
                
            }
            else if(playC==4)
            {
                printf("\nRock crushes Lizard. \n");
                printf("%s", plName);
                printf(" looses");
                compWins++;
            }
            else if(playC==5)
            {
                printf("\nSpock vaporizes Rock. \n");
                printf("%s", plName);
                printf(" wins");
                playWins++;
            } 
        
    printf("\nComputer has won ");
    printf("%s", compWins);
    printf(" game(s)");
    printf("%s", plName);
    printf(" has won ");
    printf("%s", playWins);
    printf(" game(s)\n");
    printf("%s", draw);
    printf(" game(s) have been ties");
    
        
    printf("\n\nPress y to go again?  ");
    gets( plAgain );
    }
    
    printf("\n\nPress y if another player like to try?  ");
    gets( newPlay );
            
    }
    
    
    
    
    
    return (EXIT_SUCCESS);
}

