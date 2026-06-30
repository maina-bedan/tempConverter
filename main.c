
#include <stdio.h>

// --- FUNCTION PROFILES (Prototypes) ---
float celsiusToFahrenheit(float c);
float fahrenheitToCelsius(float f);
float celsiusToKelvin(float c);
float kelvinToCelsius(float k);
int isBelowAbsoluteZero(float celsius);

int main() {
    float value, finalTemp;
    int option;
    
    while(1) {
        printf("\n--- Temperature Converter ---\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n"); // Added directional conversion
        printf("5. Exit program\n");
        printf("Answer here: ");
        
        // Input validation: ensures the user enters a valid integer menu option
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clears the broken input from the buffer
            continue;                 // Restarts the loop to ask again
        }
        
        // Check if the user wants to quit
        if (option == 5) {
            printf("Exiting program. Goodbye!\n");
            break; // Breaks the loop and ends main()
        }
        
        // Check if the number is out of bounds
        if (option < 1 || option > 5) {
            printf("Please select a valid option from the menu (1-5).\n");
            continue;
        }
        
        printf("Enter value of temperature: ");
        // Input validation: ensures the user enters a valid floating-point number
        if (scanf("%f", &value) != 1) {
            printf("Invalid temperature value. Please try again.\n");
            while(getchar() != '\n'); // Clears the broken input from the buffer
            continue;
        }
        
        // Process selections and check for Absolute Zero limits
        if(option == 1) {
            if (isBelowAbsoluteZero(value)) continue;
            finalTemp = celsiusToFahrenheit(value);
            printf("The temperature in Fahrenheit is %.2f°F\n", finalTemp);
        }
        else if(option == 2) {
            // Convert to Celsius first to check Absolute Zero bounds
            float celsiusCheck = fahrenheitToCelsius(value);
            if (isBelowAbsoluteZero(celsiusCheck)) continue;
            finalTemp = celsiusCheck;
            printf("The temperature in Celsius is %.2f°C\n", finalTemp);
        }
        else if(option == 3) {
            if (isBelowAbsoluteZero(value)) continue;
            finalTemp = celsiusToKelvin(value);
            printf("The temperature in Kelvin is %.2fK\n", finalTemp);
        }
        else if(option == 4) {
            // Convert to Celsius first to check Absolute Zero bounds
            float celsiusCheck = kelvinToCelsius(value);
            if (isBelowAbsoluteZero(celsiusCheck)) continue;
            finalTemp = celsiusCheck;
            printf("The temperature in Celsius is %.2f°C\n", finalTemp);
        }
    }

    return 0;
}

// --- FUNCTION DEFINITIONS ---

// Conversion logic functions
float celsiusToFahrenheit(float c) {
    return (c * (9.0 / 5.0)) + 32.0;
}

float fahrenheitToCelsius(float f) {
    return (f - 32.0) * 5.0 / 9.0;
}

float celsiusToKelvin(float c) {
    return c + 273.15;
}

float kelvinToCelsius(float k) {
    return k - 273.15;
}

// Safety validation function
int isBelowAbsoluteZero(float celsius) {
    if (celsius < -273.15) {
        printf("Error: This temperature is physically impossible (Below Absolute Zero, -273.15°C).\n");
        return 1; // True, it is invalid
    }
    return 0; // False, it is valid
}
