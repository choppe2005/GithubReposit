#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RAND_MINUTES_FACTOR 1.2
#define MAX_RAND_MINUTES_FACTOR 1.5
#define SENTINEL_VALUE -1

// Function prototypes
double getValidDouble(double min, double max, double sentinel);
double calculateFare(double base, double minuteCost, double mileCost, double minRate, double miles, int minutes);
void printFare(int count, double miles, int minutes, double fare);

int main(void) {
    // Constants and variables initialization
    int minMiles = 1;
    int maxMiles = 100;
    double baseFare = 1.8;
    double costPerMinute = 0.25;
    double costPerMile = 1.2;
    double minFlatRate = 20.0;

    // Business summary variables
    int riderCount = 0;
    int totalMiles = 0;
    int totalMinutes = 0;
    double totalFare = 0.0;

    // Seed for random number generation
    srand(time(NULL));

    double miles;
    // Main loop for rider mode, continues until the sentinel value is entered
    while ((miles = getValidDouble(minMiles, maxMiles, SENTINEL_VALUE)) != SENTINEL_VALUE) {
        // Calculate random minutes based on the number of miles
        int minMinutes = (int)(MIN_RAND_MINUTES_FACTOR * miles);
        int maxMinutes = (int)(MAX_RAND_MINUTES_FACTOR * miles);
        int minutes = minMinutes + rand() % (maxMinutes - minMinutes + 1);

        // Calculate fare
        double fare = calculateFare(baseFare, costPerMinute, costPerMile, minFlatRate, miles, minutes);

        // Print fare information for the current rider
        printFare(++riderCount, miles, minutes, fare);

        // Update total information for the business summary
        totalMiles += (int)miles;
        totalMinutes += minutes;
        totalFare += fare;
    }

    // Business summary
    if (riderCount > 0) {
        printf("\nUCCS Ride Share Business Summary\n\n");
        printFare(riderCount, totalMiles, totalMinutes, totalFare);
    }
    else {
        printf("There were no rides\n");
    }

    return 0;
}

// Function to get a valid double input within a specified range or sentinel value
double getValidDouble(double min, double max, double sentinel) {
    double input;
    char buffer[100];
    int isValidInput = 0;
    while (!isValidInput) {
        // Prompt user for input
        printf("Enter the number of miles to your destination: ");

        // Check if the input is a valid double
        if (scanf("%lf", &input) != 1) {
            // Invalid input, clear buffer
            scanf("%s", buffer);
            printf("Error: You did not enter a number.\n");
        }
        else if (input == sentinel) {
            return sentinel; // Sentinel value entered
        }
        else if (input < min || input > max) {
            printf("Error: Not within %.2lf and %.2lf miles.\n", min, max);
        }
        else {
            isValidInput = 1;
            return input; // Valid input
        }
    }
}

// Function to calculate the fare based on specified parameters
double calculateFare(double base, double minuteCost, double mileCost, double minRate, double miles, int minutes) {
    double fare = base + (minuteCost * minutes) + (mileCost * miles);
    return (fare < minRate) ? minRate : fare;
}

// Function to print fare information for a rider
void printFare(int count, double miles, int minutes, double fare) {
    printf("\nCurrent Ride Information\n\n");
    printf("Rider\tNumber of Miles     Number of Minutes    Ride Fare Amount\n");
    printf("%-8d%-20.2lf%-22d$%-16.2lf\n", count, miles, minutes, fare);
}