/*Program: assignment1.c
This program facilitates electronic voting for a presidential election
Author: Deirdre Corr c11720431
Date: ............
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ALLCANDIDATESNAMES 7
#define COUNT 7


int main()
{
    char *candidates[ALLCANDIDATESNAMES] = {"A Michael D Higgins", "B Sean Gallagher", "C Martin McGuinness",
                                            "D Gay Mitchell", "E Mary Davis", "F Dana Rosemary Scallon",
                                            "G David Norris"}; //array of strings to store the name of each candidate
                                    
    int i;
                                    
    printf("The candidates are:\n");
    for(i=0;i<7;i++)
    {
        printf("%s\n", candidates[i]); //prints each candidates name and their assigned letter
    }
    
    char candletter; //initialises the assigned letter of a candidate

    int candvote[COUNT] = {0}; //array to count votes of 1st preference candidates
    int candvote2[COUNT] = {0}; //array to count votes of 2nd preference candidates
    int candvote3[COUNT] = {0}; //array to count votes o 3rd preference candidates
    
    
    int totalvote = 0; //totalvote count starts at 0
    int spoiledvote = 0; //spoiledvote count starts at 0
    
    int firstchoice; 
    int secondchoice;
    int thirdchoice;
    
    int j; //initialises j for for loop
    
    for(j=-1;j<totalvote;j++) //for loop to allow each voter to enter their first second and third preferences and count all votes and spoiled votes
    {
        
        printf("For your first preference, please enter 1 followed by the assigned letter of your chosen candidate.\n");
        scanf("%d%c", &firstchoice, &candletter); //reads in number 1 for the first preference and the assigned letter of the candidate of choice
    
        if (firstchoice == 1) //if voter enters the character 1
        {
            switch (candletter)
            {
                case 'A': //if voter enters A
                {
                printf("You voted Michael D Higgins as your first preference.\n\n");
                candvote[0] = candvote[0]++; //add vote to Higgins vote count
                totalvote = totalvote++; //increment total vote count
                break;
                }
    
                case 'B': //if voter enters B
                {
                printf("You voted Sean Gallagher as your first preference.\n\n");
                candvote[1] = candvote[1]++;
                totalvote = totalvote++;
                break;
                }
                
                case 'C': //if voter enters C
                {
                printf("You voted Martin McGuinness as your first preference.\n\n");
                candvote[2] = candvote[2]++;
                totalvote = totalvote++;
                break;
                }
        
                case 'D': //if voter enters D
                {
                printf("You voted Gay Mitchell as your first preference.\n\n");
                candvote[3] = candvote[3]++;
                totalvote = totalvote++; 
                break;
                }
                
                case 'E': //if voter enters E
                {
                printf("You voted Mary Davis as your first preference.\n\n");
                candvote[4] = candvote[4]++;
                totalvote = totalvote++;
                break;
                }
                
                case 'F': //if voter enters F
                {
                printf("You voted Dana Rosemary Scallon as your first preference.\n\n");
                candvote[5] = candvote[5]++;
                totalvote = totalvote++;
                break;
                }                    
                
                case 'G': //if voter enters G
                {
                printf("You voted David Norris as your first preference.\n\n");
                candvote[6] = candvote[6]++;
                totalvote = totalvote++;
                break;
                }
                
                default: //if voter enters a letter outside the range A-G or an invalid character
                {
                printf("Error, invalid vote.\n\n");
                spoiledvote = spoiledvote++;
                }
            }
        }

        else
        {
            printf("Error, invalid vote.\n"); //if voter enters a character other than 1
            spoiledvote = spoiledvote++;
        }
        
        system("pause");
        
        printf("For your second preference, please enter 2 followed by the assigned letter of your chosen candidate. If you have no 2nd preference vote, please enter 00\n");
        scanf("%d%c", &secondchoice, &candletter); //reads in '2' for the voters second preference and the assigned letter of the chosen candidate.
    
        if (secondchoice == 2) //if voter enters 2
        {
            switch (candletter)
            {
                case 'A': //if voter enters A
                {
                printf("You voted Michael D Higgins as your second preference.\n\n");
                candvote2[0] = candvote2[0]++; //increments Higgins 2nd vote count
                totalvote = totalvote++; //increments the total vote count
                break;
                }
    
                case 'B':
                {
                printf("You voted Sean Gallagher as your second preference.\n\n");
                candvote2[1] = candvote2[1]++;
                totalvote = totalvote++;
                break;
                }
                
                case 'C':
                {
                printf("You voted Martin McGuinness as your second preference.\n\n");
                candvote2[2] = candvote2[2]++;
                totalvote = totalvote++;
                break;
                }
        
                case 'D':
                {
                printf("You voted Gay Mitchell as your second preference.\n\n");
                candvote2[3] = candvote2[3]++;
                totalvote = totalvote++; 
                break;
                }
                
                case 'E':
                {
                printf("You voted Mary Davis as your second preference.\n\n");
                candvote2[4] = candvote2[4]++;
                totalvote = totalvote++;
                break;
                }
                
                case 'F':
                {
                printf("You voted Dana Rosemary Scallon as your second preference.\n\n");
                candvote2[5] = candvote2[5]++;
                totalvote = totalvote++;
                break;
                }                    
                
                case 'G':
                {
                printf("You voted David Norris as your second preference.\n\n");
                candvote2[6] = candvote2[6]++;
                totalvote = totalvote++;
                break;
                }
                
                default:
                {
                printf("Error, invalid vote.\n\n");
                spoiledvote = spoiledvote++;
                }
            }
        }
    
        if (secondchoice == 0) //if the voter enters 0
        {
            printf("You chose not to enter a second preference.\n");
        }
    
        if (secondchoice!=2&&secondchoice!=0)
        {
            printf("Error, invalid vote.\n\n");
            spoiledvote = spoiledvote++; //incremenets spoiled vote count
        }
    
        system("pause");
        
        printf("For your third preference, please enter 3 followed by the assigned letter of your chosen candidate. If you have no 3rd preference vote, please enter 00\n\n");
        scanf("%d%c", &thirdchoice, &candletter); //reads in 3 for the voters third preference and the aissigned letter of the chosen candidate
    
        if (thirdchoice == 3)//if voter enters 3
        {
            switch (candletter)
            {
                case 'A': //if voter enters A
                {
                printf("You voted Higgins as your third preference.\n\n");
                candvote3[0] = candvote3[0]++;
                totalvote = totalvote++;
                break;
                }
    
                case 'B':
                {
                printf("You voted Gallagher as your third preference.\n\n");
                candvote3[1] = candvote3[1]++;
                totalvote = totalvote++;
                break;
                }
                
                case 'C':
                {
                printf("You voted Martin McGuinness as your first preference.\n\n");
                candvote3[2] = candvote3[2]++;
                totalvote = totalvote++;
                break;
                }
        
                case 'D':
                {
                printf("You voted Gay Mitchell as your first preference.\n\n");
                candvote3[3] = candvote3[3]++;
                totalvote = totalvote++; 
                break;
                }
                
                case 'E':
                {
                printf("You voted Mary Davis as your first preference.\n\n");
                candvote3[4] = candvote3[4]++;
                totalvote = totalvote++;
                break;
                }
                
                case 'F':
                {
                printf("You voted Dana Rosemary Scallon as your first preference.\n\n");
                candvote3[5] = candvote3[5]++;
                totalvote = totalvote++;
                break;
                }                    
                
                case 'G':
                {
                printf("You voted David Norris as your first preference.\n\n");
                candvote3[6] = candvote3[6]++;
                totalvote = totalvote++;
                break;
                }
                
                default:
                {
                printf("Error, invalid vote.\n\n");
                spoiledvote = spoiledvote++;
                }
            }
        }
        
        if (thirdchoice!=3&&thirdchoice!=0) //if 3 or 0 is not entered, vote is deemed spoiled and the spoiled vote count is incremented
        {
            printf("Error, invalid vote.\n\n");
            spoiledvote = spoiledvote++;
        }
    
    
        printf("Thank you for voting!\n\n");
        printf("Next voter: ");
        system("pause"); //prompts voter to enter any key to continue
        system("cls"); //clears the screen for the next voter
    
        
    }
    
    char votefinish = '#';
    scanf("%c", &votefinish);
    
    int k;
    
    for(k=0;k<COUNT;k++)
    {
        printf("%s\n", candidates[k]);
        printf("%c\n", candvote[k]);
       
    }
        
    
    char mostvotes, leastvotes;
    printf("Please enter the candidate with the most votes");
    scanf("%c\n", &mostvotes);
    printf("Please enter the candidate with the least votes");
    scanf("%c\n", &leastvotes);
    
    
}//end main