#include<stdio.h>
#include<stdlib.h>  // header for clear screen.
#include<conio.h>   // header for getch.
#include<math.h>    // header for log10
int arraySize, i, input;

void visual(int num[], int numOfDigits[], int count[]){
    int j, k;

    //---------- UPPER PART ----------
    printf("\nV I S U A L I Z E\n");
    printf("\t\t");
    for (j=0; j<arraySize; j++){
        count[j] = 0;
        if (i==j && input==1){          // To print the design for the LATEST INPUT
            for (k=0; k<numOfDigits[i]; k++){
                printf("-");
                count[i]++; // To count the number of '-' in preparation to the number of spaces for the index number.
            }
            printf("------");
            count[i]+=6;    // To count the number of '-' in preparation to the number of spaces for the index number.
        }
        else if (j < i){                // To print the design for the PREVIOUS INPUT
            for (k=0; k<numOfDigits[j]; k++){
                printf("-");
                count[j]++; // To count the number of '-' in preparation to the number of spaces for the index number.
            }
            printf("------");
            count[j]+=6;    // To count the number of '-' in preparation to the number of spaces for the index number.
        }
        else                    // To print the design in preparetion for the next number to be input.
            printf("-------");
    }
    //---- End of the UPPER PART -----
    printf("\n");
    
    //---------- MIDDLE PART ----------
    printf("Number Entered: ");
    for (j=0; j<arraySize; j++){
        if (i == j && input == 1)       // To print the LATEST INPUT NUMBER.
            printf("|  %d  |", num[i]);
        else if (j < i)                 // To print the PREVIOUS INPUT NUMBER.
            printf("|  %d  |", num[j]);
        else                            // To print the BLANK box in preparetion for the next number to be input.
            printf("|     |");
    }
    //----- End of the MIDDLE PART ----

    //---------- LOWER PART ----------
    printf("\n\t\t");
    for (j=0; j<arraySize; j++){
        if (i==j && input==1){          // To print the design for the LATEST INPUT
            for (k=0; k<numOfDigits[i]; k++)
                printf("-");
            printf("------");
        }
        else if (j < i){                // To print the design for the PREVIOUS INPUT
            for (k=0; k<numOfDigits[j]; k++)
                printf("-");
            printf("------");
        }
        else                            // To print the design in preparetion for the next number to be input.
            printf("-------");
    }
    //----- End of the LOWER PART ----

    printf("\n\t Index: ");
    for (j=0; j<arraySize; j++){
        if (j==i && input==1){  // To print the Index Number for the LATEST INPUT NUMBER.
            if (count[i] % 2 == 1){ // If the value of count[i] is odd number
                for (k=0; k<count[i]/2; k++){
                    printf(" ");
                }
                printf("%d", j);
                for (k=0; k<count[i]/2; k++){
                    printf(" ");
                }
            }   // End of the inner if statememnt
            else{   // If the value of count[i] is an even number
                for (k=0; k<(count[i]-1)/2; k++){
                    printf(" ");
                }
                printf("%d", j);
                for (k=0; k<count[i]/2; k++){
                    printf(" ");
                }
            }   // End of the inner else statemet
        }
        else if (j < i){    // To print the Index Number for the PREVIOUS INPUT NUMBER.
            if (count[j] % 2 == 1){ // If the value of count[j] is odd number
                for (k=0; k<count[j]/2; k++){
                    printf(" ");
                }
                printf("%d", j);
                for (k=0; k<count[j]/2; k++){
                    printf(" ");
                }
            }   // End of the inner if statememnt
            else{   // If the value of count[j] is an even number
                for (k=0; k<(count[j]-1)/2; k++){
                    printf(" ");
                }
                printf("%d", j);
                for (k=0; k<count[j]/2; k++){
                    printf(" ");
                }
            }   // End of the inner else statemet
        }
        else
            printf("   %d   ", j);
    }
    printf("\n\n");
}

int main(){
    printf("--------------------------------------------------------------------------\n");
    printf("\t\t\tVISUALIZE YOUR ARRAY\n");
    printf("--------------------------------------------------------------------------\n");
    printf("Enter array size: ");
    scanf("%d", &arraySize);

    int num[arraySize], numOfDigits[arraySize], count[arraySize];

    visual(num, numOfDigits, count);
    for (i=0; i<arraySize; i++){
        printf("Enter any key to continue...");
        getch();    // Hold the key to be entered from the user.
        system("cls");  // To clear the screen.
        printf("--------------------------------------------------------------------------\n");
        printf("\t\t\tVISUALIZE YOUR ARRAY\n");
        printf("--------------------------------------------------------------------------\n");
        printf("NUMBER SHOULD NOT BE A NEGATIVE!\nEnter an integer number[%d]: ", i);
        scanf("%d", &num[i]);
        while (num[i] < 0){
            printf("\nNUMBER SHOULD NOT BE A NEGATIVE!\nEnter an integer number[%d]: ", i);
            scanf("%d", &num[i]);
        }
        input = 1;  // To symbolize that the user have another input.
        numOfDigits[i] = (int)log10(num[i]) + 1;    // To count the number of digits of the input integer.
        visual(num, numOfDigits, count);
    }
    
    // Printing the stored values in the array
    printf("\nS E Q U E N C E  A R R A Y ' S  E L E M E N T S:\n");
    for (i=0; i<arraySize; i++)
        printf("%d  ", num[i]);
    return 0;
}