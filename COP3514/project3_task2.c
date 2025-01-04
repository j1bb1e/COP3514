// Julia Brand
// Due 9/24/24
// Finds distinct numbers in an array and sorts in ascending order

#include <stdio.h>

int find_distinct(int numbers[], int n, int result[]);
int find_largest(int a[], int n);
void selection_sort(int a[], int n);
int inArray(int arr[], int size, int target);

int main(void) 
{
   int size = 0; //size of arrays
   int num = 0; //numbers to be put in array
   int s = 0; //count of distinct numbers

   printf("Enter the size of sequence: ");
   scanf("%d", &size);
   int a[size]; //instantiates arrays of size size
   int r[size];

   printf("Enter numbers: ");
   for(int i = 0; i < size; i++)
   {
      scanf("%d", &num);       //enters in numbers into array
      a[i] = num; 
   }

    s = find_distinct(a, size, r);
    selection_sort(r, s);

    printf("Output: ");

    for(int i = 0; i < s; i++)
    {
        printf("%d ", r[i]); //prints distinct numbers sorted
    }
}

int find_distinct(int numbers[], int n, int result[])
{
   int count = 0; //number of distinct numbers

   for(int i = 0; i < n; i++) //counter for numbers[]
   {
      if(i == 0) //first number in array is distinct
      {
         result[i] = numbers[i];
         count++;
      }
      else
      {
          if(inArray(result, n, numbers[i]) == 0) //if number is not already a distinct number
          {
              result[count] = numbers[i]; //adds new distinct number to result array
              count++;
          }
      }
    }
    return count; //returns count of distinct numbers
}

  int inArray(int arr[], int size, int target) //returns 1 if target is in array, 0 if not
  {
      for(int i = 0; i < size; i++)
      {
          if(arr[i] == target)
          {        
              return 1;
          }
      }
      return 0;
  }

void selection_sort(int a[], int n) //given
{
    int largest = 0, temp;
    if (n == 1)
        return;
    largest = find_largest(a, n);
    if (largest < n - 1) {
        temp = a[n-1];
        a[n-1] = a[largest];
        a[largest] = temp;
    }
selection_sort(a, n - 1);
}

int find_largest(int a[], int n) //given
{
    int largest_index = 0;
    int i;
    for (i = 1; i < n; i++)
        if (a[i] > a[largest_index])
            largest_index = i;
    return largest_index;
}
