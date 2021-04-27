/*
Author : Ahmet Cemal Sert
Title : CMPE252 HW1 Part2
 */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define SIZE 250



float myAtof(char *string, char *error);
void calculation(char *string, char*error);

int main()
{
    char string[SIZE];
    char errorState=0;

    printf("Enter an arithmetic operation:\n");
    scanf("%s",string);

    calculation(string,&errorState);

    if (errorState==1) printf("Error has been occurred due to inappropriate input!\n");

    return 0;
}

// Function to convert string into float.
float myAtof(char* string, char* error){

    float result = 0;
    int sign = 1; // sign of the number
    double integer = 0; // integer part of the number
    double fraction = 0; // fraction part of the number
    int isFractioned = 0;
    int fractionDivisor = 1; // Divisor of the fraction


        // Checks the sign of the input string
        if (*string == '+') ++string;

        else if (*string == '-')
        {
            sign = -1;
            ++string;
        }

        while (*string != '\0') // while the input is not empty loop continues
        {
            if (*string >= '0' && *string <= '9')
            {
                if (isFractioned)
                {
                    fraction = fraction*10 + (*string - '0');
                    fractionDivisor *= 10;
                }
                else integer = integer*10 + (*string - '0'); // Calculates the integer by multiplying it with ten and substracting the '0' char from string

            }
            else if (*string == '.') // if input equals '.'
            {
                if (isFractioned) return sign * (integer + fraction/fractionDivisor);

                else isFractioned = 1;
            }
            else if(*string < '0' || *string > '9'){
                *error = 1;
            }
            else return sign * (integer + fraction/fractionDivisor);

            ++string;
        }

        // prepares the result by adding the fraction part of the number to the integer part of the number and multiplying it by sign
        result = sign * (integer + fraction/fractionDivisor);

        return result;

    }

    void calculation(char *string,char *error){

    int index = 0;

    float operand1 = 0; // first operand
    float operand2 = 0; //  second operand

    char errorState = 0; // error state

    // Arrays to keep operands
    char first_arr[SIZE] = {0};
    char second_arr[SIZE]= {0};



    for (int i = 0; string[i] != '\0'; i++) // while the input is not empty loop continues
    {
        if (string[i] =='+') // if the operator is '+'
        {
            index = 0;

            for (int j = 0; j < i; j++) first_arr[j] = string[j]; // puts first operand into first array

            for (int j = i+1; string[j] != '\0'; j++) second_arr[index++] = string[j]; // puts second operand into second array

            // sends the first_arr which keeps the first operand to myAtof function and assigns it to operand1
            operand1 = myAtof(first_arr,&errorState);

            // Checks the errorState
            if (errorState == 1){
                *error = 1;
                return;
            }

            // sends the second_arr which keeps the second operand to myAtof function and assigns it to operand2
            operand2 = myAtof(second_arr,&errorState);

            // Checks the errorState
            if (errorState == 1){
                *error = 1;
                return;
            }

            // adittion operation
            float addition = operand1+operand2;

            // formats the string as desired
            printf("%.2f + %.2f = %.2f\n",operand1,operand2,addition);
        }

        else if (string[i] =='-')
        {
            index = 0;

            for (int j = 0; j < i; j++) first_arr[j] = string[j];

            for (int j = i+1; string[j] != '\0'; j++) second_arr[index++] = string[j];

            operand1= myAtof(first_arr,&errorState);

            if (errorState == 1){
                *error = 1;
                return;
            }

            operand2 = myAtof(second_arr,&errorState);

            if (errorState == 1){
                *error = 1;
                return;
            }
            float substraction = operand1-operand2;
            printf("%.2f - %.2f = %.2f\n",operand1,operand2,substraction);
        }
        else if (string[i] =='/')
        {
            index = 0;
            for (int j = 0; j < i; j++) first_arr[j] = string[j];

            for (int j = i+1; string[j] != '\0'; j++) second_arr[index++] = string[j];

            operand1= myAtof(first_arr,&errorState);

            if (errorState == 1){
                *error = 1;
                return;
            }

            operand2 = myAtof(second_arr,&errorState);

            if (errorState == 1){
                *error = 1;
                return;
            }
            if(operand2 ==0){
                printf("Cannot divided into 0.");
                return;
            }

            float division = operand1 / operand2;
            printf("%.2f / %.2f = %.2f\n",operand1,operand2,division);
        }
        else if (string[i] =='*')
        {
            index = 0;
            for (int j = 0; j < i; j++) first_arr[j] = string[j];

            for (int j = i+1; string[j] != '\0'; j++) second_arr[index++] = string[j];

            operand1= myAtof(first_arr,&errorState);

            if (errorState == 1){
                *error = 1;
                return;
            }
            operand2 = myAtof(second_arr,&errorState);

            if (errorState == 1){
                *error = 1;
                return;
            }

            float multiplication = operand1*operand2;
            printf("%.2f * %.2f = %.2f\n",operand1,operand2,multiplication);
        }
        else{
            continue;
        }
    }
}
