#include<stdio.h>
#include<malloc.h>  // header for memory location.
#include<stdlib.h>  // header for clear screen.
#include<conio.h>   // header for getch() function.

struct list{
    char task[100];
    struct list *next;
};
struct list *head, *curr, *tail;

int createdList, choice, insert;
char another = 'Y';

//---------- VIEWING FUNCTION ----------//
void view(){
    if (choice == 1)
        printf("\t\tVIEW A LIST\n");
    if (choice == 2)
        printf("\nUPDATED: ");
    printf("TO-DO LIST\n");
    curr = head;
    createdList = 0;
    while (curr != NULL){
        createdList++;
        printf("%d. [ ] %s\n", createdList, curr->task);
        curr = curr->next;
    }
    if (choice == 1){
        printf("\nEnter any key to go back to main...");
        getch();
        system("cls");
    }
}
//------ END OF THE VIEW FUNCTION ------//

//---------- CHECKING FUNCTION ----------//
void check(){
    printf("\t\t4. CHECKING THE LIST AS DONE\n");

    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
}
//----- END OF THE CHECKING FUNCTION ----//

//---------- DELETION FUNCTION ----------//
void delete(){
    int delete, found;
    struct list *compare1;

    another = 'Y';
    while (another == 'Y' || another == 'y'){
        system("cls");
        printf("\t\t3. DELETE LIST\n\n");
        view();
        found = 0;
        printf("Enter a number to be deleted: ");
        scanf("%d", &delete);

        // To find the number to be deleted and unlinked it
        curr = head;
        createdList = 0;
        while (curr->task != NULL && found == 0){
            createdList++;
            // if the number to be deleted is in the head node
            if ((createdList == delete) && (curr == head)){
                head = head->next;
                curr->next = NULL;
                found = 1;
            }
            // if the number to be deleted is in the tail node
            else if ((createdList == delete) && (curr == tail)){
                tail = compare1;
                tail->next = NULL;
                found = 1;
            }
            else if (createdList == delete){
                compare1->next = curr->next;
                curr->next = NULL;
                found = 1;
            }
            else {
                compare1 = curr;
                curr = curr->next;
            }
        }

        // Display if successful of not in the list
        if (found){ // the conditon of if (found) can be replace to if (found == 1)
            free(curr);
            printf("\n%d is successfully deleleted\n\nUPDATED: ", delete);
            view();
        }
        else
            printf("\n%d is not in the list\n", delete);

        printf("\nDo you want to add another list? (Y/N): ");
        scanf(" %c", &another);

        // Validation of the input 
        while ((another != 'Y' && another != 'y') && (another != 'N' && another != 'n')){
            printf("WARNING: INVALID CHOICE!\n\n");
            printf("Do you want to add another list? (Y/N): ");
            scanf(" %c", &another);
        }
    }
    system("cls");
}
//----- END OF THE DELETION FUNCTION ----//

//---------- ADD FUNCTION ----------//
void add(){
    printf("\t\t2. ADD LIST\n");
    another = 'Y';
    while (another == 'Y' || another == 'y'){
        view();
        createdList++;
        curr = (struct list *)malloc(sizeof(struct list));

        printf("%d. [ ] ", createdList);
        scanf("\n");
        gets(curr->task);

        if (curr->task[0] != '!'){
            tail->next = curr;
            curr->next = NULL;
            tail = curr;
        }

        printf("\nDo you want to add another list? (Y/N): ");
        scanf(" %c", &another);

        // Validation of the input 
        while ((another != 'Y' && another != 'y') && (another != 'N' && another != 'n')){
            printf("WARNING: INVALID CHOICE!\n\n");
            printf("Do you want to add another list? (Y/N): ");
            scanf(" %c", &another);
        }
    }
    system("cls");
}
//----- END OF THE ADD FUNCTION ----//

//---------- CREATING FUNCTION ----------//
void createList(){
    system("cls");
    printf("\t\t1. Create a list\n");

    head=curr=tail=NULL;

    curr = (struct list *)malloc(sizeof(struct list));

    printf("NOTE: Enter '!' to stop creating a list\n\n");
    printf("%d. [ ] ", createdList+1);
    scanf("\n");
    gets(curr->task);
    
    while (curr->task[0] != '!'){
        createdList++;
        if (head == NULL){
            head = curr;
            head->next = NULL;
            tail = curr;
        }
        else {
            tail->next = curr;
            curr->next = NULL;
            tail = curr;
        }

        curr = (struct list *)malloc(sizeof(struct list));

        printf("%d. [ ] ", createdList+1);
        scanf("\n");
        gets(curr->task);
    }


    printf("\nTO-DO LIST\n");
    if (head != NULL){
        curr = head;
        createdList = 0;
        while (curr != NULL){
            createdList++;
            printf("%d. [ ] %s\n", createdList, curr->task);
            curr = curr->next;
        }
    }
    else
        printf("No list created!\n");
    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
}
//----- END OF THE CREATING FUNCTION ----//


int main(){
    while (!createdList){
        printf("1. Create a list\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
            createList();
        else if (choice == 2){
            printf("Thank You for Using Our Program!\n");
            return 0;
        }
        else
            printf("WARNING: INVALID CHOICE!\n\n");
    }

    while (choice != 5){
        printf("\t\tTO-DO LIST PROGRAM\n");
        printf("1. View List\n");
        printf("2. Add List\n");
        printf("3. Delete List\n");
        printf("4. Checking the list as Done\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        system("cls");

        switch (choice){
            case 1 : view(); break;
            case 2 : add(); break;
            case 3 : delete(); break;
            case 4 : check(); break;
            case 5 : printf("Thank You for Using Our Program!"); return 0;
            default : break;
        }
    }

    return 0;
}