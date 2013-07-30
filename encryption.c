#include <stdio.h>
#include <string.h>

//convert the letters to numbers
void letterconversion(char *alphabet, char *input, int *intform);
//convert the numbers to letters
void numberconversion(char *alpha, char *output, int *modform);
//emcrypting function
void encrypt(int *numform, int *result);
//decrypting function
void decrypt(int *encryption, int *numberform);
//identity proof
void modproof();

int n = 29; 

int main()
{
    char letter[29] = {'*','A','B','C','D','E','F','G','H','I',
                        'J','K','L','M','N','O','P','Q','R','S',
                        'T','U','V','W','X','Y','Z','[','%'};
    char plaintext[8];
    char cyphertext[8];
    //temporary variable
    char cyphertemp[4];
            
    int plain[4];
    int cypher[4];
                        
    printf("Enter 8 digit string \n");
    gets(plaintext);

    //index variables
    unsigned int i, j;
    //convert lowercase letters to uppercase
    for(i=0;i<8;i++)
    {   
        if(plaintext[i]>=97)
        {
            plaintext[i] = plaintext[i] - 32;
        }
    }
    
    printf("Input string (plaintext) : ");

	for(i = 0; i < (sizeof(plaintext) / sizeof(char)); i+=4)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%c", plaintext[i + j]);
            //call function to convert letters
			letterconversion(letter, plaintext + i, plain);
            //encrypt the numbers
			encrypt(plain, cypher);
            //convert the numbers to the cypher text
			numberconversion(letter, cyphertemp, cypher);
			cyphertext[i + j] = cyphertemp[j];
		}
	}

	printf("\nEncrypted (cyphertext)   : ");
	for(i = 0; i < (sizeof(plaintext) / sizeof(char)); i++)
	{
		printf("%c", cyphertext[i]);
	}
    
    printf("\nDecrypted (plaintext)    : ");
	for(i = 0; i < (sizeof(plaintext) / sizeof(char)); i+=4)
	{
		for(j = 0; j < 4; j++)
		{
			printf("%c", plaintext[i + j]);
            //call function to convert letters
			letterconversion(letter, (plaintext + i), plain);
            //decrypt the numbers
			decrypt(plain, cypher);
            //convert the numbers to the cypher text
			numberconversion(letter, cyphertemp, cypher);

			cyphertext[i + j] = cyphertemp[j];
		}
	}
    //call proof function
    modproof();
    getchar();
    return 0;
}

void letterconversion(char *alphabet, char *input, int *intform)
{
    //index variables                
    int i, j;
    
    //compare letter string to inputted string
    for(i=0; i<4; i++)
    {
            for(j=0; j<29; j++)
            {
                //if match, assign number to element i in plain and print to screen    
                if(*(alphabet+j) == *(input+i))
                    {
                        *(intform+i) = j;
                    }
            }
    }
}

void numberconversion(char *alpha, char *output, int *modform)
{
    //index variables                
    int i, k;
    
    //compare letter string to inputted string
    for(k=0; k<4; k++)
    {
        for(i=0; i<29; i++)
        {
            //if modform is equal to index variable i, assign the corresponding letter into output
            if(*(modform+k) == i)
            {
                *(output+k) = *(alpha+i);
            }
        }
    }
    
}
//encryption function
void encrypt(int *numform, int *result)
{
    
    int E[4][4] =   {{9, 12, 23, 1},
                    {24, 5, 24, 19},
                    {13, 2, 21, 13},
                    {1, 3, 25, 15}};
    //index variables
    int i, k;

    //multiplication of matrix elements
    for(i=0;i<4;i++)
    {
            result[i] = 0;
            
            for(k=0;k<4;k++)
            {
                result[i]+= (E[i][k]) * (numform[k]);
            }
        
        *(result+i) = *(result+i) % n;
    }
}
//decryption function
void decrypt(int *encrypted, int *numberform)
{
    int D[4][4] =  {{10, 12, 8, 12},
                    {6, 21, 23, 13},
                    {20, 11, 19, 5},
                    {17, 25, 27, 27}};
    //index variables                
    int i, k;
    
    //multiplication of matrix elements
    for(i=0;i<4;i++)
    {
        numberform[i] = 0;
            
        
            for(k=0;k<4;k++)
            {
                //if element in modform is equal to index variable i, assign the corresponding alphabetical letter into output
                numberform[i]+= (D[i][k]) * (encrypted[k]);
            }
    //get encrypted numbers mod 29    
    *(encrypted+i) = *(encrypted+i) % n;
    }
}

void modproof()
{
    int E[4][4] =   {{9, 12, 23, 1},
                    {24, 5, 24, 19},
                    {13, 2, 21, 13},
                    {1, 3, 25, 15}};
                    
    int D[4][4] =  {{10, 12, 8, 12},
                    {6, 21, 23, 13},
                    {20, 11, 19, 5},
                    {17, 25, 27, 27}};
                   
    //index variables
    int i, j ,k;
    int result[4][4];
    int identity[4][4];
    
    printf("\n\nIdentity matrix:");
    
    for(i=0;i<4;i++)
    {
        printf("\n");
        for(j=0;j<4;j++)
        {
            result[i][j] = 0;
 
            for(k=0;k<4;k++)
            {
                //multiply the matrix elements and store them in variable called result
                result[i][j]+= E[i][k] * D[k][j];
                //get result mod 9 and store in identity
                identity[i][j] = (result[i][j] % n);
            }
            printf("%d ", identity[i][j]);
        }
    }
}