/*
Name: Rohan Monga
UWID: 20763838
Date: October 26, 2018
Course: SYDE 121
Lab: WEEF Lab, E2 Room 1792
Assignment: Lab 5 Assignment 2
Exercise: Exercise #1
File Name: lab05_02.cpp
Project: Statistics Tool
Purpose: Return select statistics given user inputted numbers

I hereby declare that this code, submitted for credit for the course
SYDE 121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly
plagiarized by others.

Outline steps:

1. Create a function that allows the user to input numbers (no more than 20)
2. Create a second function to process the user inputted numbers and output the following statistics:
    a) minimum value
    b) maximum value
    c) mean value
    d) population standard deviation value for the data set
3. Create another function that allows the user to edit their old values. Ensure they can only edit numbers that exist already.

To test this code, I tested a couple data sets using the program and recorded the outputs. Then, I used my calculator to
manually compute the statistics, and also used an online program to do the same. I did this for a couple data sets, with
no discrepancies between sources. I also tested the edit features several times to ensure that the intended number was being replaced
and that the new statistics generated were accurate as well.

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//-------------------------Input function------------------------------
//PURPOSE: allows the user to input numbers to be processed
//INPUT: user's numbers (as an array)
//OUTPUT: n/a

int input_numbers(double numbers[], const int& MAX_SIZE) {
    int list_size = 0;
    for (int x = 0; x < MAX_SIZE; x++) {
        string input;
        cout << "Please enter a number.\n";
        cout << "Once you're done, press \"d\" or \"done\"." << endl;
        cin >> input;
        if (input == "d" || input == "done" || input == "D" || input == "Done") {
            break;
        } else {
            numbers[x] = stod(input);
            list_size++;
        }
    }
    return list_size;
}

//--------------------Statistics processing function------------------
//PURPOSE: processes users numbers and outputs the statistics
//INPUT: user's numbers
//OUTPUT: nothing to return
void stats (double numbers[], const int& list_size) {
    double sum = 0;
    double min = numbers[0];
    double max = numbers[0];

    cout << endl << "Here are the numbers you entered, along with reference numbers:\n";
    cout << endl << "Reference: Value\n";

    for (int x = 0; x < list_size; x++) {
        double value = numbers[x];
        cout << x << ":        " << value << "\n";
        sum += value;
    }

    double mean = (sum / list_size);
    double sum_of_squared_differences = 0;

    for (int x = 0; x < list_size; x++) {
        double value = numbers[x];
        double difference_from_mean = (value - mean);
        double squared_difference_from_mean = pow( difference_from_mean, 2 );
        sum_of_squared_differences += squared_difference_from_mean;
    }
//final standard deviation calculation
    double std_deviation = sqrt(sum_of_squared_differences / list_size);

//--------------------------------Outputs for Mean, Std Dev------------------------
    cout << "\n";
    cout << "Mean: " << mean << "\n";
    cout << "Population Standard Deviation: " << std_deviation << "\n";

//---------------------------------Outputs and calculations for Max and Min------------------------------------
        for(int i = 0;i < list_size; ++i)
        {

           if(numbers[0] < numbers[i])
               numbers[0] = numbers[i];
        }
        cout << "Max: " << numbers[0] << endl;

        for(int i = 0;i < list_size; ++i)
        {

               if(numbers[0] > numbers[i])
                   numbers[0] = numbers[i];
            }
            cout << "Min: " << numbers[0] << endl;

    return;
}

//-----------------------Replace old values function-------------------------------
//PURPOSE: allows user to edit their old input values
//INPUTS: user numbers
//OUTPUTS: nothing to return

void edits(double numbers[], int list_size) {
    string reference_string;
    int reference;

    cout << endl << "You can now edit your old entry\n";

    while (true) {
        cout << "Enter reference number of data to edit. Alternatively, type \"q\" or \"quit\" to exit): ";
        cin >> reference_string;

        if (reference_string == "q" || reference_string == "quit" || reference_string == "Quit" || reference_string == "Q") {
            return;
        } else {
            reference = stoi(reference_string); //conversion
        }

        bool reference_is_valid = (0 <= reference && reference < list_size);
        if (reference_is_valid) {
            double new_value;
            cout << "The value is currently " << numbers[reference] << "\n";
            cout << "What do you want to change it to? ";
            cin >> new_value;
            numbers[reference] = new_value;
            stats(numbers, list_size);
        } else {
            cout << "Invalid reference number.\n"; //prevents user from changing a number that does not exist in the list
        }
    }
}

//------------------------Main Function------------------------------------

int main() {

//Initialise Variables
    const int MAX_SIZE = 20;
    double numbers[MAX_SIZE] = {0};

    int list_size = input_numbers(numbers, MAX_SIZE); //Input function

    stats(numbers, list_size); // Stats function

    edits(numbers, list_size);   // Edit old values function

    return 0;
}
