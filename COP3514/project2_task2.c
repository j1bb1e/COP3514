// Julia Brand
// Due 9/17/24
// Reads sequences of words and finds the winner of the scrabble game

#include <stdio.h>

int main(void) 
{
    int a = 0;
    int b = 0;
    char c = ' ';

    printf("Enter the first sequence: ");
    while ((c = getchar()) != '\n') 
    {
        if (c == ' ') 
        {
            continue; //ignores whitespace
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') //calculates points for vowels
        {
            a++;
        } 
        else if (c == 't' || c == 'n' || c == 's' || c == 'r' || c == 'h') //calculates points for popular consonants
        {
            a += 2;
        } 
        else 
        {
            a += 3; // calculates points for the rest
        }
    }

    printf("Enter the second sequence: ");
    while ((c = getchar()) != '\n') 
    {
        if (c == ' ') 
        {
            continue; //ignores whitespace
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') //calculates points for vowels
        {
            b++;
        } 
        else if (c == 't' || c == 'n' || c == 's' || c == 'r' || c == 'h') //calculates points for popular consonants
        {
            b += 2;
        } 
        else 
        {
            b += 3; // calculates points for the rest
        }
    }

    if (a > b)
    {
        printf("Marjorie wins!");
    } 
    else if (b > a) 
    {
        printf("John wins!");
    } 
    else 
    {
        printf("Play again!");
    }

    return 0;
}