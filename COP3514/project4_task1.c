//Julia Brand
//Due 10/20/24
//determines winner of board game

#include <stdio.h>

void round_result(int* board, int n);

int turn = 0;  // even for marjories turn, odd for johns turn
int lastroundturn = 0; //keeping track of who starts the round

void round_result(int* board, int n)
{
    int msum = 0;           //marjories sum
    int jsum = 0;           // johns sum
    int* first = board;       // points to first number in array
    int* last = board + n - 1;    // points to last number in array

    while (first <= last) //until the numbers meet in the middle
    {
        if (*first > *last) //if first number is greater
        {
            if (turn % 2 == 0) //if marjories turn
            {
                msum += *first; //add to marjories sum
            }
            else //if johns turn
            {
                jsum += *first; //add to johns sum
            }

            first++; //move pointer to next number in array
        }
        else //if last number is greater or equal than first number
        {
            if (turn % 2 == 0) //if marjories turn
            {
                msum += *last; //add to marjories sum
            }
            else //if johns turn
            {
                jsum += *last; //add to johns sum
            }
            last--; //move pointer to next last number in array
        }
        turn++; //next turn
    }

    if (msum > jsum)
    {
        printf("Marjorie\n");
    }
    else if (jsum > msum)
    {
        printf("John\n");
    }
    else
    {
        printf("Draw\n");
    }
}

int main()
{
    int T; //rounds 
    int N; //numbers

    scanf("%d", &T); //reads amount of rounds

    while (T--)
    {
        //reads amount of numbers
        scanf("%d", &N);

        int board[N];
        for (int i = 0; i < N; i++)
        {
            scanf("%d", (board + i)); //gets numbers for array
        }

        //gets result of round
        round_result(board, N);
        
        if(lastroundturn % 2 == 0)
        {
            turn = 1;
            lastroundturn = turn;
        }
        else                            //getrs who starts the next round
        {
            turn = 0;
            lastroundturn = turn;
        }
    }

    return 0;
}
