// Online C compiler to run C program online
#include <stdio.h>

int main() {
    float value, finalTemp;
    int option;

    printf("enter value of temperature: ");
    scanf("%f", &value);

    printf("\nIs it in:\n1.celcius\n2.fahrenheit\nanswer here: ");
    scanf("%d", &option);

    if(option==1)
    {
        finalTemp = (value*(9/5))+32;
        printf("the temperature in fahrenheit is %.2f", finalTemp);
    }
    else if(option==2)
    {
        finalTemp= (value-32)*5/9;
        printf("the temperature in celcius is %.2f", finalTemp);
    }

    return 0;
}
