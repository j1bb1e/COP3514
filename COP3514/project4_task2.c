//Julia Brand
//due 10/20/24
//prints how many times the number in a position was seen before and after that position

#include <stdio.h>

void before_after(int *array, int n);

void before_after(int *array, int n) 
{
    for (int *i = array; i < array + n; i++) //current position
    {
        int bef = 0;
        int aft = 0;

        for (int *j = array; j < i; j++)  //counts how many times that number appears from beginning to current position
        {
            if (*j == *i) 
            {
                bef++;
            }
        }

        for (int *k = i + 1; k < array + n; k++) //counts how many times that number appears from current position to end
        {
            if (*k == *i) 
            {
                aft++;
            }
        }
        printf("%d %d\n", bef, aft);
    }
}

int main() 
{
    int N;
    scanf("%d", &N); //gets amount of numbers

    int array[N];
    for (int i = 0; i < N; i++) 
    {
        scanf("%d", array + i); //reads in numbers
    }

    before_after(array, N);

    return 0;
}