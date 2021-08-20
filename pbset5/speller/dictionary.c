// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Number of words loaded into the memory
int nwords = 0;

// Hash table
node *table[N];


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int h = hash(word);

    for(node *tmp = table[h]; tmp != NULL; tmp = tmp->next)
    {
        if(strcasecmp(tmp->word, word) == 0)
            return true;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int finalv = 0;

        switch(word[0])
        {
            case 'a':
            case 'A':
                finalv += 0;
                break;

            case 'b':
            case 'B':
                finalv += 1;
                break;

            case 'c':
            case 'C':
                finalv += 2;
                break;

            case 'd':
            case 'D':
                finalv += 3;
                break;

            case 'e':
            case 'E':
                finalv += 4;
                break;

            case 'f':
            case 'F':
                finalv += 5;
                break;

            case 'g':
            case 'G':
                finalv += 6;
                break;

            case 'h':
            case 'H':
                finalv += 7;
                break;

            case 'i':
            case 'I':
                finalv += 8;
                break;

            case 'j':
            case 'J':
                finalv += 9;
                break;

            case 'k':
            case 'K':
                finalv += 10;
                break;

            case 'l':
            case 'L':
                finalv += 11;
                break;

            case 'm':
            case 'M':
                finalv += 12;
                break;

            case 'n':
            case 'N':
                finalv += 13;
                break;

            case 'o':
            case 'O':
                finalv += 14;
                break;

            case 'p':
            case 'P':
                finalv += 15;
                break;

            case 'q':
            case 'Q':
                finalv += 16;
                break;

            case 'r':
            case 'R':
                finalv += 17;
                break;

            case 's':
            case 'S':
                finalv += 18;
                break;

            case 't':
            case 'T':
                finalv += 19;
                break;

            case 'u':
            case 'U':
                finalv += 20;
                break;

            case 'v':
            case 'V':
                finalv += 21;
                break;

            case 'w':
            case 'W':
                finalv += 22;
                break;

            case 'x':
            case 'X':
                finalv += 23;
                break;

            case 'y':
            case 'Y':
                finalv += 24;
                break;

            case 'z':
            case 'Z':
                finalv += 25;
                break;
        }
    
    return finalv;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for(int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // TODO
    FILE *file = fopen(dictionary, "r");

    if(file == NULL)
        return false;

    char buffer[LENGTH + 1];

    while(fscanf(file, "%s", buffer) != EOF)
    {

        node *n = malloc(sizeof(node));
        
        n->next = NULL;

        if(n == NULL)
            return false;

        strcpy(n->word, buffer);

        unsigned int h = hash(buffer);

        if(table[h] == NULL)
        {
            table[h] = n;
        }

        else
        {
            n->next = table[h];
            table[h] = n;
        }

        nwords++;
    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return nwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for(int i = 0; i < N; i++)
    {
        node *cursor = NULL;
        cursor = table[i];
        node *tmp = NULL;
        tmp = cursor;

       while(cursor != NULL)
       {
           cursor = cursor->next;
           free(tmp);
           tmp = cursor;
       }
    }
    return true;
}
