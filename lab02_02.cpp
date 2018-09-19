/*

Student Name: Rohan Monga
Student Number: 20763838
Date: Sept 19, 2018
SYDE121
Lab Room: WEEF Lab
Assignment: Lab02
Exercise 02
File name: lab02_02.cpp

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Population Estimate Tool

Initial steps:

1) Access the math library in order to use the power function
2) Add and declare all variables, including the e constant
3) For 2018 declared the population formula
4) Then repeated using the same formula but each time redefined the year varibale

I used my calculator to confirm that the values were accurate for each year based on the prescribed population formula.
I also tested a wide range of values, including randomly chosen numbers between 0-3000. Numbers going up from 2000 make sense, as they get larger and larger.
However, going down from 2000 the numbers get smaller and a rate that doesn't really make sense, as in the year 1000 there were without a doubt more than 12.367 people on the Earth.
In terms of the equation, positive numbers all make sense, however it can be assumed that the rate of population growth has changed over time, and will do so in the future. To conlcude, the
farther you get from 2000, in either the future or the past direction, the values make less sense. Negative numbers especially don't work in the equation, even though an input of -2000 would be the equivalent of 2000 B.C.

*/

#include <iostream>
#include <math.h> // access the math library to use the power function

using namespace std;

int main () {

    //for the year 2018
    //also had to declare initial variables and the consant, e

    int year = 2018;
    const double E = 2.71828; //named e "E" as per the SYDE121 style guide, got the value of e from my calculator
    double population = 6.0 * pow(E, 0.02 * (year - 2000)); // population formula using

    cout.precision(5); // change precision to 5 decimal points for clarity
    cout << "The population in the year " << year << " is " << population << " billion." << endl;

    // for the year 2025

    year = 2025;
    population = 6.0 * pow(E, 0.02 * (year - 2000));

    cout.precision(2);
    cout << "The population in the year " << year << " is " << population << " billion." << endl;

    // for the year 2050

    year = 2050;
    population = 6.0 * pow(E, 0.02 * (year - 2000));

    cout.precision(2);
    cout << "The population in the year " << year << " is " << population << " billion." << endl;

    // for the year 2100

    year = 2100;
    population = 6.0 * pow(E, 0.02 * (year - 2000));

    cout.precision(2);
    cout << "The population in the year " << year << " is " << population << " billion." << endl;

    return 0;
}

