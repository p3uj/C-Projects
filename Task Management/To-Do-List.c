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

//---------- CHECKING FUNCTION ----------//
void check(){
    printf("\t\tDONE A LIST\n");
    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
}
//----- END OF THE CHECKING FUNCTION ----//



//---------- DELETION FUNCTION ----------//
void delete(){
    printf("\t\tDELETE A LIST\n");
    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
}
//----- END OF THE DELETION FUNCTION ----//


//---------- VIEWING FUNCTION ----------//
void view(){
    if (choice == 1)
        printf("\t\tVIEW A LIST\n");
    else
        printf("\nUPDATED: ");
    printf("TO-DO LIST\n");
    curr = head;
    createdList = 0;
    while (curr != NULL){
        createdList++;
        printf("%d. [ ] %s\n", createdList, curr->task);
        curr = curr->next;
    }
    printf("\nEnter any key to go back to main...");
    getch();
    system("cls");
}
//------ END OF THE VIEW FUNCTION ------//

//---------- ADD FUNCTION ----------//
void add(){
    printf("\t\tADD A LIST\n");
    another = 'Y';
    while (another == 'Y' || another == 'y'){
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

    view();
}
//----- END OF THE ADD FUNCTION ----//

//---------- CREATING FUNCTION ----------//
void createList(){
    system("cls");
    printf("\t\tCREATE A LIST\n");

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