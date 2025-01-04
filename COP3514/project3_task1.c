// Julia Brand
// Due 9/24/24
// Determines if a sequence of numbers is a good sequence according to Emily's rules

#include <stdio.h>

int main(void) 
{
   int size = 0;
   int num = 0;
   int count = 0; //counts good numbers

   printf("Enter the size of sequence: ");
   scanf("%d", &size);
   int numbers[size]; //creates an array with the size of the sequence

   printf("Enter numbers: ");
   for(int i = 0; i < size; i++)
   {
      scanf("%d", &num);       //enters in numbers into array
      numbers[i] = num; 
   }

   for(int i = 0; i < size; i++)
   {
      if((numbers[i] >= 0 && numbers[i] < size)) //checks if number is between 0 and size
      {
         count++; 
      }
      else
      {
         for(int j = 0; j < size; j++)
            {
               if(j * j == numbers[i]) //checks if number is a square of an integer less than size
               {
                  count++;
               }
            }
      }
   }

   if(count == size) //if all numbers in the sequence are good, it is a good sequence
   {
      printf("Output: yes");
   }
   else
   {
      printf("Output: no");

   }
   return 0;
}