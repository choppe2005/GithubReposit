#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_RAND_MINUTES_FACTOR 1.2
#define MAX_RAND_MINUTES_FACTOR 1.5
#define SENTINEL_VALUE -1

// Function prototypes
double getValidDouble(double min, double max, double sentinel);
int calculateRandomNumber(int min, int max);
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
    //current rider amounts
    double currentMiles = 0;
    unsigned int currentMinutes = 0;
    double currentFare = 0;

    // Business summary 
    int riderCount = 0;
    int totalMiles = 0;
    int totalMinutes = 0;
    double totalFare = 0.0;

    // Seed for random number generation
    unsigned int randMin = 0;
    unsigned int randMax = 0;

    // Main loop for rider mode, continues until the sentinel value is entered

    do {
        // Calculate random minutes based on the number of miles
        puts("Welcom to the UCCS Ride Share. We can only provide services for rides from 1 to 100 miles.");
            puts("Enter the number of miles to your destination");
            currentMiles = getValidDouble(minMiles, maxMiles, SENTINEL_VALUE);
            if (currentMiles != SENTINEL_VALUE)
            {
                //calculate random numbers
                randMin = MIN_RAND_MINUTES_FACTOR * currentMiles;
                randMax = MAX_RAND_MINUTES_FACTOR * currentMiles;
                //calulate rand min & fare
                currentMinutes = calculateRandomNumber(randMin, randMax);
                currentFare = calculateFare(baseFare, costPerMinute, costPerMile, minFlatRate, currentMiles, currentMinutes);
               //totals
                totalMiles += currentMiles;
                totalMinutes += currentMinutes;
                totalFare += currentFare;
                riderCount++;
                puts("current Ride Information");
                PrintFare(riderCount, currentMiles, currentMinutes, currentFare);
            
            }
    } while (currentMiles != SENTINEL_VALUE);
        puts("UCCS Ride Share Business Summary");
        printFare(riderCount, currentMiles, currentMinutes, currentFare);
    return 0;
}

// Function to get a valid double input within a specified range or sentinel value
double getValidDouble(double min, double max, double sentinel) {
    bool isValid = false;
    int scanfReturn = 0;
    double validDouble = 0;
    while (validDouble == false) {
        // Prompt user for input
        printf("Enter the number of miles to your destination: ");
        scanfReturn = scanf("%1f", &validDouble);
        //clearbuffer
        while (getchar() != '\n'); {

        }
        if (scanfReturn == 1) {
            if ((validDouble >= min && validDouble <= max) || (validDouble == sentinel))
            {
                isValid = true;
            }
            else
            {
                printf("Error: Not a valid number between %d and %d! reenter the value .", min, max);
            }
        }
        else
        {
            puts("Error: Not a number!. reenter the value.");
        }
    }
    return validDouble;
}//getValidDouble


// Function to calculate the fare based on specified parameters
double calculateFare(double base, double minuteCost, double mileCost, double minRate, double miles, int minutes) {
    double fare = base + (minuteCost * minutes) + (mileCost * miles);
    if (fare <= minRate)
    {
        fare = minRate;
    }
    return fare;
}
int calculateRandomNumber(int min, int max) {
    int randNum = rand() % (max - min + 1) + min;
    return randNum;
}

// Function to print fare information for a rider
void printFare(int count, double miles, int minutes, double fare) {
    if (count == 0) {
        puts("There Were no riders");
    }
    else {
        printf("\nCurrent Ride Information\n\n");
        printf("Rider   \tNumber of Miles     Number of Minutes    Ride Fare Amount\n");
        printf("%-8d%-20.2lf%-22d$%-16.2lf\n", count, miles, minutes, fare);
    }
    
}