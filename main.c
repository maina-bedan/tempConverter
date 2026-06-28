// Online C compiler to run C program online
#include <stdio.h>

int main() {
    float value, finalTemp;
    int option;
    
    // The while(1) loop keeps the program running until you choose to exit
    while(1) {
        printf("\n--- Temperature Converter ---\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Exit program\n");
        printf("Answer here: ");
        
        // Input validation: ensures the user enters a valid integer menu option
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clears the broken input from the buffer
            continue;                 // Restarts the loop to ask again
        }
        
        // Check if the user wants to quit
        if (option == 4) {
            printf("Exiting program. Goodbye!\n");
            break; // Breaks the loop and ends main()
        }
        
        // Check if the number is out of bounds (e.g., typing 5 or 99)
        if (option < 1 || option > 4) {
            printf("Please select a valid option from the menu (1-4).\n");
            continue;
        }
        
        printf("Enter value of temperature: ");
        // Input validation: ensures the user enters a valid floating-point number
        if (scanf("%f", &value) != 1) {
            printf("Invalid temperature value. Please try again.\n");
            while(getchar() != '\n'); // Clears the broken input from the buffer
            continue;
        }
        
        if(option == 1)
        {
            // Fixed: Changed 9/5 to 9.0/5.0 to fix the integer division bug
            finalTemp = (value * (9.0 / 5.0)) + 32;
            printf("The temperature in Fahrenheit is %.2f\n", finalTemp);
        }
        else if(option == 2)
        {
            finalTemp = (value - 32) * 5.0 / 9.0;
            printf("The temperature in Celsius is %.2f\n", finalTemp);
        }
        else if(option == 3)
        {
            // New feature: Celsius to Kelvin logic
            finalTemp = value + 273.15;
            printf("The temperature in Kelvin is %.2f\n", finalTemp);
        }
    }

    return 0;
}
