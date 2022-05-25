// Copyright (c) 2022 Sarah All rights reserved.
//
// Created by: Sarah
// Created on: May, 18th, 2022
// This program asks the user for the base and the height. It then calculates
// the volume & lateral surface area of the square pyramid & displays it to
// the user.
#include <iostream>
#include <iomanip>
#include <cmath>

// this function calculates the volume
float CalcVolume(float base, float height) {
    float volume;
    volume = (height/3)*pow(base, 2);

    return volume;
}

// this function calcualtes the lateral surface area.
float CalcLatArea(float base, float height) {
    float lateralArea;
    lateralArea = base * (sqrt(pow(base, 2) + 4*(pow(height, 2))));

    return lateralArea;
}


int main() {
    // declare variables
    float heightFloat;
    float baseFloat;
    float volumeSqu;
    float latSq;
    std::string baseString, heightString;

    // introduction
    std::cout << "The program calculates the volume of the square pyramid & "
                 "the lateral surface area.";
    std::cout << std::endl;
    std::cout << std::endl;

    // get user input
    std::cout << "Enter the base of the square pyramid: ";
    std::cin >> baseString;

    try {
        // convert from string to float
        baseFloat = std::stof(baseString);

        // get user input
        std::cout << "Enter the height of the square pyramid: ";
        std::cin >> heightString;

        try {
            // convert from string to float
            heightFloat = std::stof(heightString);

            // sets a range & calls the function
            if (baseFloat > 0 && heightFloat > 0) {
               volumeSqu = CalcVolume(baseFloat, heightFloat);
               latSq = CalcLatArea(baseFloat, heightFloat);

               // display results to the user
               std::cout << std::endl;
               std::cout << "The volume of the square pyramid is "
                         << std::fixed;
               std::cout << std::setprecision(2) << volumeSqu << " cm³ and\n"
                         << std::fixed;
               std::cout << "the lateral surface area of the square pyramid ";
                            "pyramid is ";
               std::cout << std::setprecision(2) << latSq << " cm².";
            } else {
                std::cout << "The base and height must be greater than 0.";
                std::cout << std::endl;
            }
        // handles the error case
        } catch (std::invalid_argument) {
            std::cout << heightString << " is not a valid input.";
        }
    // handles the error case
    } catch (std::invalid_argument) {
        std::cout << baseString << " is not a valid input.";
    }
}
