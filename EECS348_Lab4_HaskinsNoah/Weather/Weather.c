#include <stdio.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temperature, converted_temperature;
    int input_scale, target_scale;

    while (1) {
        printf("Enter the temperature: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Invalid temperature. Please try again.\n");
            fflush(stdin);
            continue;
        }

        printf("Choose the input scale:\n");
        printf("1. Fahrenheit\n");
        printf("2. Celsius\n");
        printf("3. Kelvin\n");
        printf("Enter your choice: ");
        if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
            printf("Invalid input scale. Please try again.\n");
            fflush(stdin);
            continue;
        }

        printf("Choose the target scale:\n");
        printf("1. Fahrenheit\n");
        printf("2. Celsius\n");
        printf("3. Kelvin\n");
        printf("Enter your choice: ");
        if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
            printf("Invalid target scale. Please try again.\n");
            fflush(stdin);
            continue;
        }

        // Convert temperature
        switch (input_scale) {
            case 1: // Fahrenheit
                switch (target_scale) {
                    case 2: converted_temperature = fahrenheit_to_celsius(temperature); break;
                    case 3: converted_temperature = fahrenheit_to_celsius(temperature) + 273.15; break;
                }
                break;
            case 2: // Celsius
                switch (target_scale) {
                    case 1: converted_temperature = celsius_to_fahrenheit(temperature); break;
                    case 3: converted_temperature = celsius_to_kelvin(temperature); break;
                }
                break;
            case 3: // Kelvin
                switch (target_scale) {
                    case 1: converted_temperature = kelvin_to_celsius(temperature) + 32; break;
                    case 2: converted_temperature = kelvin_to_celsius(temperature); break;
                }
                break;
        }

        // Display converted temperature and categorization
        printf("Converted temperature: %.2f %s\n", converted_temperature, target_scale == 1 ? "Fahrenheit" : target_scale == 2 ? "Celsius" : "Kelvin");
        categorize_temperature(converted_temperature);

        break; // Exit the loop after successful conversion
    }

    return 0;
}

// Function implementations
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32.0);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Freezing\nWear a jacket.\n");
    } else if (celsius <= 10) {
        printf("Cold\nDress warmly.\n");
    } else if (celsius <= 25) {
        printf("Comfortable\nEnjoy the weather!\n");
    } else if (celsius <= 35) {
        printf("Hot\nStay hydrated.\n");
    } else {
        printf("Extreme Heat\nAvoid outdoor activities during peak hours.\n");
    }
}