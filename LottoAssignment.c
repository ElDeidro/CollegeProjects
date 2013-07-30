/*Assignment 2 : Lottery game.
Student no: C11720431
Date: 11/03/2012
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 6


void fullentry(int *e, int *b);       
void displayentry(int *displaye, int *displayb);
void sortedentry(int *array, int *extra);
void results(int *numarray, int *numextra);


int main(void)
{
    char optionchoice = ' ';;
    int entry[SIZE];
    int bonus; 

    //fullentry(entry, &bonus);
    
    while(optionchoice != '#')
    {
        printf ("Menu:\n"
                "\n1. Enter players chosen numbers"
                "\n2. Display players chosen numbers"
                "\n3. Sort players numbers in ascending order"
                "\n4. Check if player is a winner"
                "\n5. Display the frequency of the numbers entered\n");

        scanf("%1s",&optionchoice);
        getchar();
            
        switch(optionchoice)
        {

            case '1':
            {
                fullentry(entry, &bonus);
                break;
            }
            
            case '2':
            {
                displayentry(entry, &bonus);
                break;
            }
            case '3':
            {
                sortedentry(entry, &bonus);
                break;
            }
            case '4':
            {
                results(entry, &bonus);
                break;
            }
            case '5':
            {   
                break;
            }
            case '#':
            {
                break;
            }
            default:
            {
                printf("\nError: Invalid choice, please try again\n");
                break;
            }
            
        }
        system("pause");
    }
}

void fullentry(int *e, int *b)
{
    int i = 0;
    
    printf( "Please enter your 6 numbers between 1 and 42:\n");
    
	while (i<SIZE)
	{
		scanf("%2d/n", (e+i));
        flushall();
		
        if ((*(e+i) > 42 || *(e+i) < 1) || (*(e+i) == '\o'))
        {
            printf( "Invalid entry\n");
			printf( "Please enter a number between 1 and 42:\n");
            i--;
		}

        else
        {
            i++;
        }
                
        /*else
                {
                    int j;
                    
                    for(j=0; j<SIZE; j++)
                    {
                        
                        if(*(e+j) == *(e+i))
                        {
                            *(e+j) = *(e+j++);
                            i--;
                        }
                        ++j;
                    }
                }*/
        
	}
    
	printf("Please enter your bonus number:\n");
	
    int k;

    scanf("%2d", b);
    
    while (*b > 42 || *b < 1)
    {
        printf("Invalid number please try again:\n");
        scanf("%2d", b);
    }
    
    for(k=0; k<SIZE; k++)
    {
        while (*b == *(e+k))
        {
            printf("Invalid choice. Please enter your bonus number\n");
            scanf("%2d", b);
        }
    }
    
    printf("Your entry has been processed\n");

}

void displayentry(int *displaye, int *displayb)
{
    int i;
    
    printf("Your chosen numbers are:");
    
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", *(displaye+i));
    }
    printf("- %d\n", *displayb);
    

}

void sortedentry(int *array, int *extra)
{
    int i, j, min, temp;
    
    for(i=0; i<*(array-1); i++)
    {
        min = i;
        
        for(j = i+1; j<SIZE; j++)
        {
            if (*(array+j) < *(array+min))
            {
                min = j;
            }
        }
        
        temp = *(array+min);
        *(array+min) = *(array+i);
        *(array+i) = temp;
    }
    
    for(i=0; i<SIZE; i++)
    {
        printf("%d ", *(array+i));
    }
    printf("- %d\n", *extra);
    
}

void results(int *numarray, int *numextra)
{
    int i;
    int match = 0;
    int entrybonus = 0;
    
    int win[SIZE] = { 1, 3, 5, 7, 9, 11 };
    int winbonus = 42;
    
    for(i=0; i<SIZE; i++)
    {
        if (*(numarray+i) == *(win+i))
        {
            match++;
        }
        
        if (*numextra == winbonus)
        {
            entrybonus = 1;
        }
    }
    
    switch(match)
    {
        case 3:
            if(entrybonus == 1)
            {
                printf("Free lotto scratch card\n");
            }
            else
            {
                printf("Not a winner\n");
            }
            break;
            
        case 4:
        
            if(entrybonus == 1)
            {
                printf("Night out\n");
            }
            else
            {
                printf("Full petrol tank\n");
            }
            break;
        
        case 5:
        
            if(entrybonus == 1)
            {
                printf("Almost - just 1 away\n");
                
            }
            else
            {
                printf("Holidays paid for\n");
            }
            break;
        
        case 6:
            printf("Jackpot\n");
            break;
          
        default:
            printf("Not a winner\n");
    }
}