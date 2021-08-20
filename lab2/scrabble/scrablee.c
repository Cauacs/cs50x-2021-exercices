#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    
    if (score1 > score2)
    {
        printf("Player 1 is the winner\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 is the winner\n");
    }
    else
    {
        printf("Is a tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int soma = 0;
    int n = strlen(word);

    for (int i = 0;i < n; i++)
    {
        if (isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        int letter = word[i];

        switch (letter)
        {
            case 'a':
                soma = soma + POINTS[0];
            break;

            case 'b':
                soma = soma + POINTS[1];
            break;

            case 'c':
                soma = soma + POINTS[2];
            break;

            case 'd':
                soma = soma + POINTS[3];
            break;
            
            case 'e':
                soma = soma + POINTS[4];
            break;
            
            case 'f':
                soma = soma + POINTS[5];
            break;

            case 'g':
                soma = soma + POINTS[6];
            break;

            case 'h':
                soma = soma + POINTS[7];
            break;

            case 'i':
                soma = soma + POINTS[8];
            break;
            
            case 'j':
                soma = soma + POINTS[9];
                
            break;
            
            case 'k':
                soma = soma + POINTS[10];
            break;

            case 'l':
                soma = soma + POINTS[11];
            break;

            case 'm':
                soma = soma + POINTS[12];
            break;

            case 'n':
                soma = soma + POINTS[13];
            break;
            
            case 'o':
                soma = soma + POINTS[14];
            break;
            
            case 'p':
                soma = soma + POINTS[15];
            break;

            case 'q':
                soma = soma + POINTS[16];
            break;

            case 'r':
                soma = soma + POINTS[17];
            break;

            case 's':
                soma = soma + POINTS[18];
            break;
            
            case 't':
                soma = soma + POINTS[19];
            break;    
            
            case 'u':
                soma = soma + POINTS[20];
            break;

            case 'v':
                soma = soma + POINTS[21];
            break;

            case 'w':
                soma = soma + POINTS[22];
            break;

            case 'x':
                soma = soma + POINTS[23];
            break;
            
            case 'y':
                soma = soma + POINTS[24];
            break;
            
            case 'z':
                soma = soma + POINTS[25];
            break;
            
            default :
                soma = soma + 0;
            break;    
        }
    }
    

    return soma;
}