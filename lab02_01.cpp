/*

Student Name: Rohan Monga
Student Number: 
Date: Sept 19, 2018
SYDE121
Lab Room: WEEF Lab
Assignment: Lab02
Exercise 01
File name: lab02_01.cpp

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Weight Division Tool

Initial Program Steps:
1) Set initial value (valuegiven)
2) Declare a varibale for the number of 150 lb weights
3) Use the modulus operator to solve for the remainder after a whole number of 150 lb weights is used to fill up the initial weight given
4) Repeat for the remaining weight categories
5) Output the result in a coherent sentence with proper spacing.


*/

/*
The first thing I did was run the code and test the 1048 value. I then confirmed the output number of weights for each category was correct by using my
calculator. I then started from -1 and tested values upwards. -1 lb weight given yields an output that you need "-1" 1 lb weights, so the weight given has to be a
positive number. I then tried inputting 1,000,000 and the code outputted the correct value. It is therefore safe to assume that the range of values that work is 0<x<infinity, where x is the weight given.
*/

#include <iostream>

using namespace std;

int main() {

    int weight_given;

    cout << "What is the weight you want to compute?";
    cin >> weight_given;

    int weights150 = weight_given / 150; //declare the weights 150 variable
    int remainder = weight_given % 150; //used modulus operator to create an initial remainder variable

    int weights50 = remainder / 50; //repeated same process as 150lb for remaining weights
    remainder = remainder - (weights50 * 50);

    int weights30 = remainder / 30;
    remainder = remainder - (weights30 * 30);

    int weights15 = remainder / 15;
    remainder = remainder - (weights15 * 15);

    int weights1 = remainder / 1;
    remainder = remainder - (weights1 * 1);

    //output the result in a coherent sentence.
    cout << "You'll need " << weights150 << " 150 lb weights " << weights50 << " 50 lb weights " << weights30 << " 30 lb weights " << weights15 << " 15 lb weights " << "and " << weights1 << " 1 lb weights.";
    //output for part A of exercise 1 (weightgiven=1048): 6 (150lb), 2 (50lb), 1 (30lb), 1 (15lb), 3 (1lb)


    return 0;
}
