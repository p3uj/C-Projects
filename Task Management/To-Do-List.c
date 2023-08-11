#include<stdio.h>
#include<malloc.h>  // header for memory location.
#include<stdlib.h>  // header for clear screen.
#include<conio.h>   // header for getch() function.
#include<string.h>  // header for strlen function.

struct list{
    char task[101];     // Maximum of 100 characters only.
    struct list *next;
};
struct list *head, *curr, *tail;

int created = 0, numList, choice, found, num;
char another = 'Y';

//---------- VIEWING FUNCTION ----------//
void view(){
    if (choice == 2){
        printf("-----------------------------------------------------------------\n");
        printf("\t\t\t2. VIEW A LIST\n");
        printf("-----------------------------------------------------------------\n");
    }

    printf("TO-DO LIST\n");
    if (head != NULL){
        curr = head;
        numList = 0;
        while (curr != NULL){
            numList++;
            printf("%d. %s\n", numList, curr->task);
            curr = curr->next;
        }
    }
    else
        printf("No list created!\n");
    if (choice == 2){
        printf("\nEnter any key to go back to main...");
        getch();
        system("cls");
    }
}
//------ END OF THE VIEW FUNCTION ------//

//---------- DELETION FUNCTION ----------//
void delete(){
    struct list *compare1;
    another = 'Y';

    while (another == 'Y' || another == 'y'){
        system("cls");
        printf("-----------------------------------------------------------------\n");
        printf("\t\t\t4. DELETE LIST\n");
        printf("-----------------------------------------------------------------\n");
        view();
        found = 0;
        printf("Enter a number to be deleted: ");
        scanf("%d", &num);

        // To find the number to be deleted and unlinked it
        curr = head;
        numList = 0;
        while (curr->task != NULL && found == 0){
            numList++;
            // if the number to be deleted is in the head node.
            if ((numList == num) && (curr == head)){
                head = head->next;
                curr->next = NULL;
                found = 1;
            }
            // if the number to be deleted is in the tail node.
            else if ((numList == num) && (curr == tail)){
                tail = compare1;
                tail->next = NULL;
                found = 1;
            }
            // if the number to be deleted is not in the head and tail node.
            else if (numList == num){
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
            system("cls");
            printf("-----------------------------------------------------------------\n");
            printf("\t\t\t4. DELETE LIST\n");
            printf("-----------------------------------------------------------------\n");
            view();
        }
        else
            printf("\n%d is not in the list\n", num);

        printf("\nDo you want to add another list? (Y/N): ");
        scanf(" %c", &another);

        // Validation of the input 
        while ((another != 'Y' && another != 'y') && (another != 'N' && another != 'n')){
            printf("WARNING: INVALID CHOICE!\n\n");
            printf("Do you want to add another list? (Y/N): ");
            scanf(" %c", &another);
        }
    }
    if (head == NULL)
        created = 0;    // set to 0 since there is no list.
    system("cls");
}
//----- END OF THE DELETION FUNCTION ----//

//---------- ADD FUNCTION ----------//
void add(){
    another = 'Y';

    while (another == 'Y' || another == 'y'){
        system("cls");
        printf("-----------------------------------------------------------------\n");
        printf("\t\t\t3. ADD LIST\n");
        printf("-----------------------------------------------------------------\n");
        view();
        numList++;

        curr = (struct list *)malloc(sizeof(struct list));
        printf("%d. ", numList);
        scanf("\n");
        gets(curr->task);

        // Validation of the input
        while (strlen(curr->task) > 100){
            printf("\nWARNING: You reached the limit of characters. Max: 100 characters only!\n");
            printf("%d. ", numList+1);
            scanf("\n");
            gets(curr->task);
        }

        // Linked
        tail->next = curr;
        curr->next = NULL;
        tail = curr;
        // End of the Linked

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
    printf("-----------------------------------------------------------------\n");
    printf("\t\t\t1. CREATE A LIST\n");
    printf("-----------------------------------------------------------------\n");

    head=curr=tail=NULL;

    curr = (struct list *)malloc(sizeof(struct list));
    numList = 0;

    printf("NOTE: Maximum of 100 characters only! Enter '!' to stop creating a list\n\n");
    printf("%d. ", numList+1);
    scanf("\n");
    gets(curr->task);

    // Validation of the input
    while (strlen(curr->task) > 100){
        printf("\nWARNING: You reached the limit of characters. Max: 100 characters only!\n");
        printf("%d. ", numList+1);
        scanf("\n");
        gets(curr->task);
    }
    
    while (curr->task[0] != '!'){
        numList++;
        created = 1;
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
        printf("%d. ", numList+1);
        scanf("\n");
        gets(curr->task);

        // Validation of the input
        while (strlen(curr->task) > 100){
            printf("\nWARNING: You reached the limit of characters. Max: 100 characters only!\n");
            printf("%d. ", numList+1);
            scanf("\n");
            gets(curr->task);
        }
    }

    system("cls");
    printf("-----------------------------------------------------------------\n");
    printf("\t\t\t1. CREATE A LIST\n");
    printf("-----------------------------------------------------------------\n");
    printf("TO-DO LIST\n");
    if (head != NULL){
        curr = head;
        numList = 0;
        while (curr != NULL){
            numList++;
            printf("%d. %s\n", numList, curr->task);
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
    while (!created){
        printf("1. Create a list\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        system("cls");
        while (choice != 1 && choice != 2){
            system("cls");
            printf("WARNING: INVALID CHOICE!\n");
            printf("1. Create a list\n");
            printf("2. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
        }
        if (choice == 1)
            createList();
        else {
            system("cls");
            printf("-----------------------------------------------------------------\n");
            printf("\t\tThank You for Using Our Program!\n");
            printf("-----------------------------------------------------------------\n");
            return 0;
        }

        while (created && choice != 5){
            printf("-----------------------------------------------------------------\n");
            printf("\t\t\tTO-DO LIST PROGRAM\n");
            printf("-----------------------------------------------------------------\n");
            printf("1. Create a list\n");
            printf("2. View List\n");
            printf("3. Add List\n");
            printf("4. Delete List\n");
            printf("5. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            system("cls");

            switch (choice){
                case 1 : createList(); break;
                case 2 : view(); break;
                case 3 : add(); break;
                case 4 : delete(); break;
                case 5 : printf("-----------------------------------------------------------------\n");
                        printf("\t\tThank You for Using Our Program!\n");
                        printf("-----------------------------------------------------------------\n");
                        return 0;
                default : break;
            }
        }
    }
    return 0;
}