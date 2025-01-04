//Julia Brand
//Due 12/2/24
//Modifies add_student function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 100
#define NETID_LEN 40

struct student {
	char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
	double gpa;
	int attempts;
	struct student *next;
};

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts);
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts);
struct student * pop_student(struct student *registration);
void list_students(struct student *registration);
void list_gpa_min(struct student *registration, double gpa);
void list_cop2510_min(struct student *registration, int cop2510_grade);
struct student * clear_queue(struct student *registration);


///////////////////
// main function //
///////////////////

int main() {
	char code;
	char name[NAME_LEN+1], netid[NETID_LEN+1], cop2510_grade;
	double gpa;
	int attempts;

	struct student *registration = NULL;

	help();
	printf("\n");

	for (;;) {
		// read operation code
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while(getchar() != '\n') /* skips to end of line */
			;

		// run operation
		switch (code) {
			case 'h':
				help();
				break;
			case 'a':
				read(name, netid, &cop2510_grade, &gpa, &attempts);
				registration = add_student(registration, name, netid, cop2510_grade, gpa, attempts);
				break;
			case 'p':
				registration = pop_student(registration);
				break;
			case 'l':
				list_students(registration);
				break;
			case 'g':
				read(NULL, NULL, NULL, &gpa, NULL);
				list_gpa_min(registration, gpa);
				break;
			case 'c':
				read(NULL, NULL, &cop2510_grade, NULL, NULL);
				list_cop2510_min(registration, cop2510_grade);
				break;
			case 'q':
				registration = clear_queue(registration);
				return 0;
			default:
				printf("Illegal operation code!\n");
		}
		printf("\n");
	}
}

//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a student to the queue;\n");
	printf("\t'p' for removing a student from the queue;\n");
	printf("\t'l' for listing all students in the queue;\n");
	printf("\t'g' for searching students with a minimum GPA;\n");
	printf("\t'c' for searching students with a minimum grade in COP2510;\n");
	printf("\t'q' to quit.\n");
}

void read(char *name, char *netid, char *cop2510_grade, double *gpa, int *attempts) {
	if(name != NULL) {
		printf("Enter the name of the student: ");
		scanf("%[^\n]", name);
	}
	if(netid != NULL) {
		printf("Enter the NetID of the student: ");
		scanf("%s", netid);
	}
	if(cop2510_grade != NULL) {
		printf("Enter the COP2510 letter grade: ");
		scanf(" %c", cop2510_grade);
	}
	if(gpa != NULL) {
		printf("Enter the GPA: ");
		scanf("%lf", gpa);
	}
	if(attempts != NULL) {
		printf("Enter the number of previous attempts: ");
		scanf("%d", attempts);
	}
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////


//receives the registration linked list and the values for student name, NetID, COP2510 grade, GPA, and number of previous attempts, 
//and adds the new student to the registration linked list; this function returns a pointer to the updated queue
struct student * add_student(struct student *registration, char *name, char *netid, char cop2510_grade, double gpa, int attempts) 
{
	struct student *s = malloc(sizeof(struct student));

	if(s == NULL)
	{
		return registration;
	}
	
	//copies all of the students info into s
	strcpy(s -> name, name);
	strcpy(s -> netid, netid);
	s -> cop2510_grade = cop2510_grade;
	s -> gpa = gpa;
	s -> attempts = attempts;
	s -> next = NULL;

	if(registration == NULL || attempts > registration->attempts) //if list is empty or has the highest amount of attempts
	{
		s->next = registration;
        return s;
    }

	struct student *current = registration;

	while(current->next != NULL && current->next->attempts >= attempts) 
	{
    	current = current->next; //finds node to insert student
    }

	s->next = current->next;
    current->next = s;

	return registration;
}


// receives the registration linked list, prints the information of the next student to be registered (first come, first serve basis), 
//and removes it from the queue; if the queue is empty, this function does nothing; this function returns a pointer to the updated queue
struct student * pop_student(struct student *registration) 
{
	if(registration == NULL)
	{
		return registration;
	}

	// output format
	printf("|----------------------|----------------------|---------|-----|----------|\n");
	printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
	printf("|----------------------|----------------------|---------|-----|----------|\n");
	printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", registration->name, registration->netid, registration->cop2510_grade, registration->gpa, registration->attempts);
	printf("|----------------------|----------------------|---------|-----|----------|\n");

	struct student *temp = registration;
	registration = registration->next; //sets registration to its next node, skipping student which gets rid of it
	free(temp);

	return registration;
}


//receives the registration linked list and lists all students in it; if the queue is empty, this function does nothing
void list_students(struct student *registration) 
{
	if(registration == NULL)
	{
		return;
	}

	// output format
	printf("|----------------------|----------------------|---------|-----|----------|\n");
	printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
	printf("|----------------------|----------------------|---------|-----|----------|\n");

	struct student *r = registration;
    while(r != NULL) //lists all of the students
	{
    	printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", r->name, r->netid, r->cop2510_grade, r->gpa, r->attempts);
    	printf("|----------------------|----------------------|---------|-----|----------|\n");
    	r = r->next;
	}

}


// receives the registration linked list and a minimum GPA value, lists all students in the list that satisfy this condition; 
//if no students satisfy this condition, this function does nothing
void list_gpa_min(struct student *registration, double gpa) 
{	
	if(registration == NULL)
	{
		return;
	}

	int found = 0;

	for(struct student *r = registration; r != NULL; r = r -> next) //loops through list looking for someone to meet criteria
	{
		if(r -> gpa >= gpa)
		{
			found = 1;
		}
	}

	if(!found)
	{
		return; //will not print table unless there is someone who meets the criteria
	}

	struct student *r = registration;

	printf("|----------------------|----------------------|---------|-----|----------|\n");
	printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
	printf("|----------------------|----------------------|---------|-----|----------|\n");

	while(r != NULL) 
	{
        if(r -> gpa >= gpa) 
		{
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", r->name, r->netid, r->cop2510_grade, r->gpa, r->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
        }
        r = r -> next;
    }
}


// receives the registration linked list and a minimum COP2510 grade, lists all students in the list that satisfy this condition; 
//if no students satisfy this condition, this function does nothing;
void list_cop2510_min(struct student *registration, int cop2510_grade) 
{
	if(registration == NULL) 
	{
    	return;
    }

	int found = 0;

	for(struct student *r = registration; r != NULL; r = r -> next) //loops through list looking for someone to meet criteria
	{
		if(toupper(r -> cop2510_grade) <= toupper(cop2510_grade))
		{
			found = 1;
		}
	}

	if(!found)
	{
		return;	//will not print table unless there is someone who meets the criteria
	}

    struct student *r = registration;

    printf("|----------------------|----------------------|---------|-----|----------|\n");
    printf("| Name                 | NetID                | COP2510 | GPA | Attempts |\n");
    printf("|----------------------|----------------------|---------|-----|----------|\n");

    while (r != NULL) 
	{
        if(toupper(r -> cop2510_grade) <= toupper(cop2510_grade)) 
		{
            printf("| %-20s | %-20s |       %c | %1.1f | %8d |\n", r->name, r->netid, r->cop2510_grade, r->gpa, r->attempts);
            printf("|----------------------|----------------------|---------|-----|----------|\n");
        }
        r = r->next;
    }
}


// receives the registration linked list and deletes all students in it; this function returns a pointer to the updated queue.
struct student * clear_queue(struct student *registration)
 {
	while(registration != NULL) 
	{
        struct student *temp = registration;
        registration = registration->next;
        free(temp);
    }
    return NULL;
}
