#include <stdio.h>

// Symbolic constants
#define NUM_RENTERS 5
#define NUM_CATEGORIES 3
#define SURVEY_CATEGORIES 3

// Function prototypes
void printCategories(const char* categories[], size_t totalCategories);
void getRatings(int survey[][NUM_CATEGORIES], size_t totalRiders);
void printSurveyResults(int survey[][NUM_CATEGORIES], size_t totalRiders);
void calculateCategoryAverages(int survey[][NUM_CATEGORIES], double averages[], size_t totalRiders);
void printCategoryData(const char* categories[], double averages[], size_t totalCategories);

int main() {
    const char* surveyCategories[SURVEY_CATEGORIES] = { "Safety", "Cleanliness", "Comfort" };
    // Create a 2D array to hold survey ratings
    int rideshareSurvey[NUM_RENTERS][NUM_CATEGORIES];

    // Create a 1D array to hold category averages
    double categoryAverages[NUM_CATEGORIES];

    // Print categories
    printCategories(surveyCategories, SURVEY_CATEGORIES);

    // Get ratings from each renter for each category
    getRatings(rideshareSurvey, NUM_RENTERS);

    // Print survey results
    printSurveyResults(rideshareSurvey, NUM_RENTERS);

    // Calculate category averages
    calculateCategoryAverages(rideshareSurvey, categoryAverages, NUM_RENTERS);

    // Print category averages
    printCategoryData(surveyCategories, categoryAverages, NUM_CATEGORIES);

    return 0;
}

// Function to print survey categories
void printCategories(const char* categories[], size_t totalCategories) {
    printf("%s", "Rating Categories:\t");
    for (size_t surveyCategory = 0; surveyCategory < totalCategories; ++surveyCategory) {
        printf("\t%zu.%s\t", surveyCategory + 1, categories[surveyCategory]);
    }
    puts(""); // start new line of output
}

// Function to get ratings from each renter for each category
void getRatings(int survey[][NUM_CATEGORIES], size_t totalRiders) {
    // Loop through riders
    for (size_t rider = 0; rider < totalRiders; ++rider) {
        printf("Enter ratings for Survey %zu:\t", rider + 1);

        // Loop through categories
        for (size_t category = 0; category < NUM_CATEGORIES; ++category) {
            scanf("%d", &survey[rider][category]);
        }
    }
}

// Function to print survey results
void printSurveyResults(int survey[][NUM_CATEGORIES], size_t totalRiders) {
    for (size_t rider = 0; rider < totalRiders; ++rider) {
        printf("Survey %zu:\t\t", rider + 1);
        for (size_t category = 0; category < NUM_CATEGORIES; ++category) {
            printf("\t\t%d", survey[rider][category]);
        }
        puts(""); // start new line of output
    }
}

// Function to calculate averages for each category
void calculateCategoryAverages(int survey[][NUM_CATEGORIES], double averages[], size_t totalRiders) {
    for (size_t category = 0; category < NUM_CATEGORIES; ++category) {
        double sum = 0.0;
        for (size_t rider = 0; rider < totalRiders; ++rider) {
            sum += survey[rider][category];
        }
        averages[category] = sum / totalRiders;
    }
}

// Function to print category averages
void printCategoryData(const char* categories[], double averages[], size_t totalCategories) {
    printf("Rating Averages\t");
    for (size_t category = 0; category < totalCategories; ++category) {
        printf("%12.1f", averages[category]);
    }
    puts(""); // start new line of output
    
}
