// CSC1060C03
// Module 1 - Assignment 1
// 2023-06-03
// Stephen L. Belden

#include <iostream>

int main() {
    //
    // Exercise 34
    //
    {
        std::cout << "Exercise 34" << std::endl;

        // Define constants needed for later math, and initialize input variable
        const float DEALER_COST_MULTIPLIER = 0.85;
        float listPrice = 0;

        // Prompt the user for input
        std::cout << "Enter the list price of the car: ";
        std::cin >> listPrice;

        // Do the math
        float dealerCost = listPrice * DEALER_COST_MULTIPLIER;
        float dealerMinPrice = dealerCost + 500.00;

        // Show the result to the user
        std::cout << "The least the dealer will accept is: " << dealerMinPrice << std::endl << std::endl;
    }


    //
    // Exercise 35
    //
    {
        std::cout << "Exercise 35" << std::endl;

        // Define constants needed for later math, and initialize input variable
        const float PI = 3.141592;
        float radius = 0;

        // Prompt the user for input
        std::cout << "Enter the radius of the sphere: ";
        std::cin >> radius;

        // Do the math
        float sphereVolume = (4.0 / 3.0) * PI * radius * radius * radius;
        float sphereArea = 4.0 * PI * radius * radius;

        // Show the result to the user
        std::cout << "The volume of this sphere is: " << sphereVolume << std::endl;
        std::cout << "The surface area of this sphere is: " << sphereArea << std::endl << std::endl;
    }


    //
    // Exercise 36
    //
    {
        std::cout << "Exercise 36" << std::endl;

        // Define constants needed for later math, and initialize input variables
        const float PER_SQUARE_YARD_COST = 35.0 / 5000;
        const float PER_FERTILIZER_APPLICATION_COST = 30.0;
        const float PER_TREE_COST = 50.0;
        float lawnArea = 0;
        int numFertilizerApplications = 0;
        int numTreesPlanted = 0;

        // Prompt the user for input
        std::cout << "Enter the area of your lawn in square yards: ";
        std::cin >> lawnArea;
        std::cout << "Enter the number of fertilizing applications: ";
        std::cin >> numFertilizerApplications;
        std::cout << "Enter the number of trees to be planted: ";
        std::cin >> numTreesPlanted;

        // Do the math
        float subtotalLawn = lawnArea * PER_SQUARE_YARD_COST;
        float subtotalFertilizer = numFertilizerApplications * PER_FERTILIZER_APPLICATION_COST;
        float subtotalTrees = numTreesPlanted * PER_TREE_COST;
        float totalCost = subtotalLawn + subtotalFertilizer + subtotalTrees;

        // Show the result to the user
        std::cout << "The total cost for these services will be: $" << totalCost << std::endl << std::endl;
    }
}
