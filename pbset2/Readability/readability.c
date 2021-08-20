#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Insert the text: ");

    int nletters = count_letters(text);

    int nwords = count_words(text) + 1;

    int nsentences = count_sentences(text);

    double L = (double) nletters /  nwords * 100;

    double S = (double) nsentences /  nwords * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;



    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else    
    {
      printf("Grade %i\n", (int) round(index));
    }


}



int count_letters(string text)
{
    int letters = 0;
    int length = strlen(text);

    for (int i = 0; i < length; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

int count_words(string text)
{
    int words = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if(isspace(text[i]))
        {
            words++;
        }
    }

    return words;
}


int count_sentences(string text)
{
    int sentences = 0;
    int length = strlen(text);

    for(int i = 0; i < length; i++)
    {
        if(text[i] == '.'|| text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}