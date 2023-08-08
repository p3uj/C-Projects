#include<stdio.h>
#include<stdlib.h>
int choice;
char transaction = 'Y';
float amountDep, totalBal, amountWit;

//-----Main Menu Function-----//
void mainMenu(){
    printf("\tWELCOME TO ISKOLAR NG BANGKO!\n");
    printf("----------------------------------------------\n");
    printf("[1] Account Balance\n");
    printf("[2] Deposit\n");
    printf("[3] Withdraw\n");
    printf("[4] Exit\n");
}
//-----End of the Main Menu Function-----//

//-----Account Balance Function-----//
void accountBalance(){
    printf("----------------------------------------------\n");
    printf("\t\tACCOUNT BALANCE\n");
    printf("----------------------------------------------\n");
    printf("Balance: %0.2f\n", totalBal);
    printf("----------------------------------------------\n");
    printf("Do you have other transaction? (Y/N): ");
    scanf(" %c", &transaction);
    system("cls");
}
//-----End of the Account Balance Function-----//

//-----Deposit Function-----//
void deposit(){
    printf("----------------------------------------------\n");
    printf("\t\tDEPOSIT\n");
    printf("----------------------------------------------\n");
    printf("Enter the amount: ");
    scanf("%f", &amountDep);
    totalBal += amountDep;  // totalBal variable will accumulate all values entered in amountDep variable.
    printf("\n%.2f is successfully deposit\n\n", amountDep);
    printf("Current Balance: %.2f\n", totalBal);
    printf("----------------------------------------------\n");
    printf("Do you have other transaction? (Y/N): ");
    scanf(" %c", &transaction);
    system("cls");
}
//-----End of the Deposit Function-----//

//-----Withdraw Function-----//
void withdraw(){
    printf("----------------------------------------------\n");
    printf("\t\tWITHDRAW\n");
    printf("----------------------------------------------\n");
    printf("Current Balance: %.2f\n\n", totalBal);
    printf("Enter the amount to be withdraw: ");
    scanf("%f", &amountWit);
    if (amountWit < totalBal){
        totalBal -= amountWit;  // totalBal variable will accumulate all values entered in amountWit variable.
        printf("%.2f is successfully withdraw\n\nCurrent Balance: %.2f\n", amountWit, totalBal);
    }
    else
        printf("Insufficient Balance!\n");
    printf("----------------------------------------------\n");
    printf("Do you have other transaction? (Y/N): ");
    scanf(" %c", &transaction);
    system("cls");
}
//-----End of the Withdraw Function-----//

//-----Exit Function-----//
void exitFunction(){
    printf("----------------------------------------------\n");
    printf("\t   End of the program!\n");
    printf("----------------------------------------------\n");
}
//-----End of the Exit Function-----//

int main(){
    while (transaction == 'Y' || transaction == 'y'){
        printf("----------------------------------------------\n");
        mainMenu();
        printf("----------------------------------------------\n");
        printf("Enter the desire transaction: ");
        scanf("%d", &choice);
        while (choice > 4 || choice == 0){
            printf("WARNING: INVALID CHOICE!\n\n");
            printf("Enter the desire transaction: ");
            scanf("%d", &choice);
        }
        system("cls");
        switch (choice){
            case 1: accountBalance(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: exitFunction(); return 0; break;
            default: 
        }
    }
    exitFunction();

    return 0;
}