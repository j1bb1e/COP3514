//Julia Brand
//Due 10/25/24
//splits a two-word string into two strings each containing one word
#include <stdio.h>

#define N 1000

void split(char *input,  char *word1, char *word2) // The function splits the string input into two words, stores in word1 and word2.
{
    while(*input == ' ' || *input == '\t') //skips white space to find the first word
    {
        input++;
    }

    while (*input != ' ' && *input != '\t' && *input != '\0') //goes until first word is done
    {
        *word1++ = *input++; //adds letter to the next position in the string
    }
    *word1 = '\0'; //adds null character at the end

    while(*input == ' ' || *input == '\t') //skips whitespace between the two words
    {
        input++;
    }

    while (*input != ' ' && *input != '\t' && *input != '\0')
    {
        *word2++ = *input++; //adds letter to the next position in the string
    }
    *word2 = '\0'; //null character at the end
}

int read_line(char *str, int n) //returns # of chars stored in str
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (i < n)
        {
            *str++= ch;
            i++;
        }
    }
    *str = '\0'; /* terminates string */
    return i; /* number of characters stored */
}

int main()
{
    char input[N];
    char word1[N];
    char word2[N];

    printf("Enter input: ");
    read_line(input, N);  //reads input

    split(input, word1, word2);  //splits input into its two words

    printf("First word: %s\n", word1);
    printf("Second word: %s\n", word2);

    return 0;
}