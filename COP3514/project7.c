// Julia Brand
// Due 11/19/24
// A yoga studio is planning to host an event for their loyal customers. 
// They have gathered some data about their regular customers. The data include email address, number of lessons taken, and name. 
// Write a program that reads data from a file, finds customers who have taken more than a certain number of lessons, 
// and writes the result to an output file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

struct customer {
    char email[50];
    int lessons;
    char name[50];
};

int search(struct customer list[], int n, int num_lessons, struct customer result[]);
int countCustomers(FILE *file);
void printCustomers(struct customer a[], int n, FILE *file);

int main() {
    FILE *input = fopen("customers.csv", "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen("result.csv", "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    int num_lessons;
    printf("Enter the number of lessons for searching: ");
    scanf("%d", &num_lessons);

    int numCustomers = countCustomers(input);
    rewind(input); // Rewind file pointer to beginning for reading

    struct customer list[MAX];
    for (int i = 0; i < numCustomers; i++) {
        fscanf(input, "%[^,],%d,%[^\n]\n", list[i].email, &list[i].lessons, list[i].name);
    }

    struct customer result[MAX];
    int numFound = search(list, numCustomers, num_lessons, result);

    printCustomers(result, numFound, output);

    fclose(input);
    fclose(output);

    return 0;
}

int search(struct customer list[], int n, int num_lessons, struct customer result[]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (list[i].lessons > num_lessons) {
            strcpy(result[count].email, list[i].email);
            result[count].lessons = list[i].lessons;
            strcpy(result[count].name, list[i].name);
            count++;
        }
    }
    
    return count;
}

int countCustomers(FILE *file) {
    int num = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        num++;
    }

    return num;
}

void printCustomers(struct customer a[], int n, FILE *file) {
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%d,%s\n", a[i].email, a[i].lessons, a[i].name);
    }
}
