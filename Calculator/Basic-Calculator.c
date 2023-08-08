#include<stdio.h>
#include<stdlib.h>  // header file for clearing the screen.
char operator, choice;
float num1, num2;
int main(){
    choice = 'Y';
    while (choice == 'Y' || choice == 'y'){
        printf("\n\t   OPERATOR\n");
        printf("---------------------------------");
        printf("\n|   +\t|   -\t|   *\t|   /\t|\n");
        printf("---------------------------------");
        printf("\nEnter the chosen operator: " );
        scanf(" %c", &operator);
        if (operator == '+' || operator == '-' || operator == '*' || operator == '/'){
            printf("\nEnter the first number: ");
            scanf("%f", &num1);
            printf("Enter the second number: ");
            scanf("%f", &num2);
        }
        switch(operator){
            case '+': printf("\n%.2f + %.2f = %.2f", num1, num2, num1+num2); break;
            case '-': printf("\n%.2f + %.2f = %.2f", num1, num2, num1-num2); break;
            case '*': printf("\n%.2f + %.2f = %.2f", num1, num2, num1*num2); break;
            case '/': printf("\n%.2f + %.2f = %.2f", num1, num2, num1/num2); break;
            default: printf("WARNING: Invalid Operator");
        }
        printf("\n\nDo you want to continue this program? (Y/N): ");
        scanf(" %c", &choice);
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n'){
            printf("\nWARNING: Invalid Input");
            printf("\nDo you want to continue this program? (Y/N): ");
            scanf(" %c", &choice);
        }
        system("cls");
    }
    printf("\nThank you for using our program!");
    return 0;
}