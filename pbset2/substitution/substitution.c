#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("./substituition Key\n");
        return 1;
    }

    if(argc > 2)
    {
        printf("Only one string as argument\n");
        return 1;
    }
    if(strlen(argv[1]) != 26)
    {
        printf("Your key should contain 26 characters\n");
        return 1;
    }


    int lk = strlen(argv[1]);

    for(int i = 0; i < lk; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Only alphabetic characters allowed\n");
            return 1;
        }
    }

    for(int i = 0; i < lk; i++)
    {
        for(int j = i + 1; j < lk; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    string txt = get_string("Plaintext: ");

    int lt = (strlen(txt));

    char cipher[lt];


    for(int i = 0; i < lt; i++)
    {
        int letter = txt[i];
        switch(letter)
        {

        case 'a':
            cipher[i] = tolower(argv[1][0]);
            break;

        case 'b':
            cipher[i] = tolower(argv[1][1]);
            break;

        case 'c':
            cipher[i] = tolower(argv[1][2]);
            break;

        case 'd':
            cipher[i] = tolower(argv[1][3]);
            break;

        case 'e':
            cipher[i] = tolower(argv[1][4]);
            break;
        case 'f':
            cipher[i] = tolower(argv[1][5]);
            break;

        case 'g':
            cipher[i] = tolower(argv[1][6]);
            break;

        case 'h':
            cipher[i] = tolower(argv[1][7]);
            break;

        case 'i':
            cipher[i] = tolower(argv[1][8]);
            break;
        case 'j':
            cipher[i] = tolower(argv[1][9]);
            break;

        case 'k':
            cipher[i] = tolower(argv[1][10]);
            break;

        case 'l':
            cipher[i] = tolower(argv[1][11]);
            break;

        case 'm':
            cipher[i] = tolower(argv[1][12]);
            break;

        case 'n':
            cipher[i] = tolower(argv[1][13]);
            break;
        case 'o':
            cipher[i] = tolower(argv[1][14]);
            break;

        case 'p':
            cipher[i] = tolower(argv[1][15]);
            break;

        case 'q':
            cipher[i] = tolower(argv[1][16]);
            break;

        case 'r':
            cipher[i] = tolower(argv[1][17]);
            break;

        case 's':
            cipher[i] = tolower(argv[1][18]);
            break;
        case 't':
            cipher[i] = tolower(argv[1][19]);
            break;

        case 'u':
            cipher[i] = tolower(argv[1][20]);
            break;

        case 'v':
            cipher[i] = tolower(argv[1][21]);
            break;

        case 'w':
            cipher[i] = tolower(argv[1][22]);
            break;

        case 'x':
            cipher[i] = tolower(argv[1][23]);
            break;
        case 'y':
            cipher[i] = tolower(argv[1][24]);
            break;

        case 'z':
            cipher[i] = tolower(argv[1][25]);
            break;

        case 'A':
            cipher[i] = argv[1][0];
            break;

        case 'B':
            cipher[i] = argv[1][1];
            break;

        case 'C':
            cipher[i] = argv[1][2];
            break;
        case 'D':
            cipher[i] = argv[1][3];
            break;

        case 'E':
            cipher[i] = argv[1][4];
            break;

        case 'F':
            cipher[i] = argv[1][5];
            break;

        case 'G':
            cipher[i] = argv[1][6];
            break;

        case 'H':
            cipher[i] = argv[1][7];
            break;
        case 'I':
            cipher[i] = argv[1][8];
            break;

        case 'J':
            cipher[i] = argv[1][9];
            break;

        case 'K':
            cipher[i] = argv[1][10];
            break;

        case 'L':
            cipher[i] = argv[1][11];
            break;

        case 'M':
            cipher[i] = argv[1][12];
            break;
        case 'N':
            cipher[i] = argv[1][13];
            break;

        case 'O':
            cipher[i] = argv[1][14];
            break;

        case 'P':
            cipher[i] = argv[1][15];
            break;

        case 'Q':
            cipher[i] = argv[1][16];
            break;

        case 'R':
            cipher[i] = argv[1][17];
            break;
        case 'S':
            cipher[i] = argv[1][18];
            break;

        case 'T':
            cipher[i] = argv[1][19];
            break;

        case 'U':
            cipher[i] = argv[1][20];
            break;

        case 'V':
            cipher[i] = argv[1][21];
            break;

        case 'W':
            cipher[i] = argv[1][22];
            break;
        case 'X':
            cipher[i] = argv[1][23];
            break;

        case 'Y':
            cipher[i] = argv[1][24];
            break;

        case 'Z':
            cipher[i] = argv[1][25];
            break;

        default :
            cipher[i] = letter;
            break;

        }
    }

    printf("Cipher: ");
    for(int i = 0; i < lt; i++)
    {
        printf("%c", cipher[i]);
    }
}

