/*

Student Name: Rohan Monga
Student Number: 
Date: Sept 19, 2018
SYDE121
Lab Room: WEEF Lab
Assignment: Lab02
Exercise 03
File name: lab02_03.cpp

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

Project: Sum Tool

Initial steps:

1) Initialize n, a, and d variables as well for numbers 1 and 2
2) Add user interface so that numbers can be inputted
3) Link inputted numbers to the sum equation via the variables n and a
4) Set d = 1, since it is always 1 in this problem.

First, I used my calculator to ensure that my program outputted the correct sums. Then, I tested various ranges of values (positive/negative, negative/negative, positive/positive).
All values checked out after confirming using my calculator. I also tried doing an order with a larger number first, and the code still worked.
To conclude, the sum program works for all real integers.

*/

#include <iostream>

using namespace std;

int main() {

    int number1; // initialize variables for numbers 1 and 2
    int number2;

    cout << "What are the range of numbers you want to add?"; // basic user interface
    cin >> number1;
    cin >> number2;

    int n; // number of integers to be added
    int a; // the first number
    int d;  // difference between each number
    int sum;

    n = number2;
    a = number1;
    d = 1;

    sum = (n / 2) * (2 * a + (n - 1) * d); // sum equation
    cout << "The sum of the numbers between " << number1 << " and " << number2 << " is " << sum << ".";

    return 0;
}
