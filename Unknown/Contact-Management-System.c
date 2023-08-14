#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
struct info{
    struct info *prev;
    char name[26];
    char number[12];
    char email[26];
    struct info *next;
};
struct info *head, *curr, *tail;
int createdContact, choice;


void createContact(){
    printf("\t\t1. CREATE CONTACT INFORMATION\n");
    printf("NOTE: Name and Email's max of 25 characters only! And max of 11 digits for Number\n\tEnter '!' to stop creating a contact information\n\n");
    head=curr=tail=NULL;

    curr = (struct info *)malloc(sizeof(struct info));
    printf("Enter name: ");
    scanf("\n");
    gets(curr->name);
    // Validation of the input
    while (strlen(curr->name) > 25){
        printf("WARNING:You reached the maximum characters [25]\n");
        printf("Enter name: ");
        scanf("\n");
        gets(curr->name);
    }

    
    while (curr->name[0] != '!'){
        printf("Enter number: ");
        scanf("\n");
        gets(curr->number);
        // Validation of the input for number
        while (strlen(curr->number) > 11){
            printf("WARNING:You reached the maximum digit [11]\n");
            printf("Enter number: ");
            scanf("\n");
            gets(curr->number);
        }

        printf("Enter email: ");
        scanf("\n");
        gets(curr->email);
        // Validation of the input for email
        while (strlen(curr->email) > 25){
            printf("WARNING:You reached the maximum characters [25]\n");
            printf("Enter email: ");
            scanf("\n");
            gets(curr->email);
        }

        if (head==NULL){
            head = curr;
            head->prev = NULL;
            head->next = NULL;
            tail = curr;
        }
        else{
            tail->next = curr;
            curr->prev = tail;
            curr->next = NULL;
            tail = curr;
        }

        curr = (struct info *)malloc(sizeof(struct info));
        printf("Enter name: ");
        scanf("\n");
        gets(curr->name);
        // Validation of the input
        while (strlen(curr->name) > 25){
            printf("WARNING:You reached the maximum characters [25]\n");
            printf("Enter name: ");
            scanf("\n");
            gets(curr->name);
        }
    }


    printf("\n%48s\n", "Contact Information:");
    if (head!=NULL){
        printf("%-28s%-14s%-28s\n", "NAME", "NUMBER", "EMAIL");
        curr = head;
        while (curr != NULL){
            printf("%-28s%-14s%-28s\n", curr->name, curr->number, curr->email);
            curr = curr->next;
        }
    }
    else
        printf("No contact information record!\n");

}

int main(){
    while (!createdContact){
        printf("1. Create contact information\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        // Validation of the input
        while (choice!=1 && choice!=2){
            system("cls");
            printf("WARNING: INVALID CHOICE\n");
            printf("1. Create contact information\n");
            printf("2. Exit\n");
            printf("Enter choice: ");
            printf("Enter choice: ");
            scanf("%d", &choice);
        }

        if (choice==1)
            createContact();
        else {
            system("cls");
            printf("-----------------------------------------------------------------\n");
            printf("\t\tThank You for Using Our Program!\n");
            printf("-----------------------------------------------------------------\n");
            return 0;
        }
    }
    return 0;
}