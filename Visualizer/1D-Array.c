#include<stdio.h>
#include<stdlib.h>  // header for clear screen.
#include<conio.h>   // header for getch.
#include<math.h>    // header for log10
int arraySize, i, j, input, numOfDigits;

void visual(int num[]){
    printf("\nV I S U A L I Z E\n");    // Upper Part
    printf("\t\t");                     //
    for (i=0; i<arraySize; i++)         //
        printf("-------");              // End of the Upper Part

    printf("\nNumber Entered: ");   // Middle Part
    for (i=0; i<arraySize; i++){    //
        if (i == j && input == 1)   // The if statement used to print the latest input number.
            printf("|  %d  |", num[j]);
        else if (j > i)             // The else if statement is used to print the previous input number.
            printf("|  %d  |", num[i]);
        else                        // The else statement is used print the blank box in preparation to the next number to be input.
            printf("|     |");      //
    }                               // End of the Middle Part

    printf("\n\t\t");               // Lower Part
    for (i=0; i<arraySize; i++)     //
        printf("-------");          // End of the Lower Part

    printf("\n\t Index: ");
    for (i=0; i<arraySize; i++)
        printf("%4d   ", i);
    printf("\n\n");
}

int main(){
    printf("----------------------------------------------------\n");
    printf("\t\tVISUALIZE YOUR ARRAY\n");
    printf("----------------------------------------------------\n");
    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);
    int num[arraySize];

    visual(num);
    for (j=0; j<arraySize; j++){
        printf("Enter any key to continue...");
        getch();    // Hold the key to be entered from the user.
        system("cls");  // To clear the screen.
        printf("NUMBER SHOULD BE 1 DIGIT ONLY!\nEnter an integer number[%d]: ", j+1);
        scanf("%d", &num[j]);
        numOfDigits = (int)log10(num[j]) + 1;   // To count the number of digits of the input interger.
        while (numOfDigits > 1){
            printf("\nNUMBER SHOULD BE 1 DIGIT ONLY!\nEnter an integer number[%d]: ", j+1);
            scanf("%d", &num[j]);
            numOfDigits = (int)log10(num[j]) + 1;   // To count the number of digits of the input interger.
        }
        input = 1;  // To symbolize that the user have another input.
        visual(num);
    }
    
    // Printing the stored values in the array
    printf("\nSequence Array's Elements:\n");
    for (i=0; i<arraySize; i++)
        printf("%d  ", num[i]);
    return 0;
}