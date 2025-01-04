// Julia Brand
// Due 12/2/24
//Modifies project 7 to use qsort

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

struct customer 
{
    char email[50];
    int lessons;
    char name[50];
};

int search(struct customer list[], int n, int num_lessons, struct customer result[]);
int countCustomers(FILE *file);
void printCustomers(struct customer a[], int n, FILE *file);
int compareCustomers(const void *a, const void *b);

int main() 
{
    FILE *input = fopen("customers.csv", "r");
    FILE *output = fopen("result.csv", "w");

    int num_lessons;
    printf("Enter the number of lessons for searching: ");
    scanf("%d", &num_lessons);

    int numCustomers = countCustomers(input); //total number of customers
    rewind(input);

    struct customer list[MAX];
    for (int i = 0; i < numCustomers; i++) 
    {
        fscanf(input, "%[^,],%d,%[^\n]\n", list[i].email, &list[i].lessons, list[i].name); //stores every customer in an array
    }

    struct customer result[MAX]; //array of customers with greater than the lessons specified by the user
    int numFound = search(list, numCustomers, num_lessons, result); //number of customers stored in above array

    qsort(result, numFound, sizeof(struct customer), compareCustomers); //implements qsort
    
    printCustomers(result, numFound, output); //above array into the output file

    fclose(input);
    fclose(output);

    return 0;
}

//The function searches in the array list for customers whose number of lessons are greater than num_lessons, and store the result in 
//the array result. n is the number of customers in the array list. The function returns the number of customers who has taken greater 
//than num_lessons of lessons and stored in the result array.
int search(struct customer list[], int n, int num_lessons, struct customer result[]) 
{
    int count = 0;

    for(int i = 0; i < n; i++) //loops through total amount of customers
    {
        if(list[i].lessons > num_lessons) //when a customer has greater than the amount of lessons asked for
        {
            strcpy(result[count].email, list[i].email);
            result[count].lessons = list[i].lessons;
            strcpy(result[count].name, list[i].name);
            count++;
        }
    }
    
    return count;
}

int countCustomers(FILE *file) //counts total customers in input file
{
    int num = 0;
    char buffer[100];

    while(fgets(buffer, sizeof(buffer), file) != NULL) //counts lines
    {
        num++;
    }

    return num;
}

void printCustomers(struct customer a[], int n, FILE *file) //prints list of customers from result array
{
    for(int i = 0; i < n; i++) 
    {
        fprintf(file, "%s,%d,%s\n", a[i].email, a[i].lessons, a[i].name);
    }
}

int compareCustomers(const void *a, const void *b) 
{
    const struct customer *customerA = (const struct customer *)a;
    const struct customer *customerB = (const struct customer *)b;

     return customerB->lessons - customerA->lessons; //descending order by lessons
}
