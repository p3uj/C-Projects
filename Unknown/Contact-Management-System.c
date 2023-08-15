#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct info{
    struct info *prev;
    char name[26];
    char number[12];
    char email[26];
    struct info *next;
};
struct info *head, *curr, *tail;
int createdContact, choice, i, found;
char another;


void view(){
    if (choice == 1)
        printf("\t\t1. VIEW CONTACT INFORMATION\n");

    printf("\n%45s\n", "Contact Information:");
    if (head!=NULL){
        printf("%-6s%-28s%-14s%-28s\n", "NO.", "NAME", "NUMBER", "EMAIL");
        curr = head;
        i = 0;
        while (curr != NULL){
            i++;
            printf("%-5d %-28s%-14s%-28s\n", i, strupr(curr->name), curr->number, curr->email);
            curr = curr->next;
        }
    }
    else
        printf("No contact information record!\n");
    
    if (choice == 1){
        printf("\nEnter any key to go back to main...");
        getch();
        system("cls");
    }
}

void add(){
    another = 'Y';

    while (another == 'Y' || another == 'y'){
        system("cls");
        printf("\t\t2. ADD CONTACT INFORMATION\n");
        view();
        curr = (struct info *)malloc(sizeof(struct info));
        printf("\nEnter name: ");
        scanf("\n");
        gets(curr->name);
        // Validation of the input
        while (strlen(curr->name) > 25){
            printf("WARNING:You reached the maximum characters [25]\n");
            printf("Enter name: ");
            scanf("\n");
            gets(curr->name);
        }

        printf("Enter number: ");
        scanf("\n");
        gets(curr->number);
        // Validation of the input for number
        while (strlen(curr->number) < 11 || strlen(curr->number) > 11){
            printf("\nWARNING: Number should be 11 digits\n");
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

        // Linked
        tail->next = curr;
        curr->prev = tail;
        curr->next = NULL;
        tail = curr;
        // End of linked

        printf("\nDo you want to add more? (Y/N): ");
        scanf("%c", &another);
        // Validation of the input
        while ((another != 'Y' && another != 'y') && (another != 'N' && another != 'n')){
            printf("WARNING: INVALID CHOICE!\n\n");
            printf("Do you want to add more? (Y/N): ");
            scanf(" %c", &another);
        }
    }
    system("cls");
    printf("\t\t2. ADD CONTACT INFORMATION\n");
    view();
    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
}

void delete(){
    int num;
    another = 'Y';

    while (another == 'Y' || another == 'y'){
        system("cls");
        printf("\t\t3. DELETE CONTACT INFORMATION\n");
        view();
        found = 0;

        printf("\nEnter number to be delete: ");
        scanf("%d", &num);

        i = 0;
        curr = head;
        while (curr != NULL && !found){
            i++;
            // If the number to be deleted is in the head node.
            if ((num == i) && (curr == head)){
                head = head->next;
                head->prev = NULL;
                curr->next = NULL;
                found = 1;
            }
            // If the number to be deleted is in the tail node.
            else if ((num == i) && (curr == tail)){
                curr = tail;
                tail = tail->prev;
                tail->next = NULL;
                curr->prev = NULL;
                found = 1;
            }
            // If the number to be deleted is not in the head and curr node.
            else if (num == i){
                curr->prev->next = curr->next;  // update 'yung next ng node na nasa likod ni curr.
                curr->next->prev = curr->prev;  // update 'yung prev ng node na nasa harap ni curr.
                curr->prev = NULL;
                curr->next = NULL;
                found = 1;
            }
            else
                curr = curr->next;
        }
        if (!found)
            printf("%d is not in the list!\n", num);
        else{
            free(curr);
            printf("Records in %d is successfully deleted!\n", num);
            view();
        }
        
        printf("\nDo you want to add more? (Y/N): ");
        scanf(" %c", &another);
        // Validation of the input
        while ((another != 'Y' && another != 'y') && (another != 'N' && another != 'n')){
            printf("WARNING: INVALID CHOICE!\n\n");
            printf("Do you want to add more? (Y/N): ");
            scanf(" %c", &another);
        }
    }
    system("cls");
    printf("\t\t3. DELETE CONTACT INFORMATION\n");
    view();
    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
}

void create(){
    printf("\t\t1. CREATE CONTACT INFORMATION\n");
    printf("NOTE: Name and Email's max of 25 characters only! And number should be 11 digits\n\tEnter '!' to stop creating a contact information\n\n");
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
        createdContact = 1;
        printf("Enter number: ");
        scanf("\n");
        gets(curr->number);
        // Validation of the input for number
        while (strlen(curr->number) < 11 || strlen(curr->number) > 11){
            printf("\nWARNING: Number should be 11 digits\n");
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

    printf("\n%45s\n", "Contact Information:");
    if (head!=NULL){
        printf("%-6s%-28s%-14s%-28s\n", "NO.", "NAME", "NUMBER", "EMAIL");
        curr = head;
        i = 0;
        while (curr != NULL){
            i++;
            printf("%-5d %-28s%-14s%-28s\n", i, strupr(curr->name), curr->number, curr->email);
            curr = curr->next;
        }
    }
    else
        printf("No contact information record!\n");

    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
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
        system("cls");
        if (choice==1)
            create();
        else {
            system("cls");
            printf("-----------------------------------------------------------------\n");
            printf("\t\tThank You for Using Our Program!\n");
            printf("-----------------------------------------------------------------\n");
            return 0;
        }
        
        while (createdContact && choice != 4){
            printf("1. View\n");
            printf("2. Add\n");
            printf("3. Delete\n");
            printf("4. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            
            system("cls");
            switch (choice){
                case 1 : view(); break;
                case 2 : add(); break;
                case 3 : delete(); break;
                case 4 : printf("-----------------------------------------------------------------\n");
                         printf("\t\tThank You for Using Our Program!\n");
                         printf("-----------------------------------------------------------------\n");
                         return 0; break;
                default : printf("WARNING: INVALID CHOICE\n"); break;
            }
        }
    }
    return 0;
}