/*
Name: Rohan Monga
UWID: 20763838
Date: September 27, 2018
Course: SYDE 121
Lab: WEEF Lab, E2 Room 1792
Assignment: Lab 3 Assignment 1
Exercise: Exercise #1
File Name: lab03_01.cpp
Project: Prime Number, Odd Digit Sum and Palindrome Tool
Purpose: Determine all the prime numbers below an inputted value, and state if any of these numbers are palindromic or have digits that sum to an odd number.

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

//Reference URL: http://oeis.org/A002385

To test the program logic, I tested several values of known status as prime or not, odd digit sum or not, and palindromic or not.
I tested a number type from each number range (100,000 - 10,000), (9999 - 1000), (999 - 100), (99 - 10), (9 - 2).
For example for the (999-100) number range, I knew the number 131 was prime and palindromic with an odd digit sum.
I confirmed my code reflected this, then I looked for the number 120 which is not prime and confirmed it was not there.
I then checked 113 as a number that is prime and has an odd digit sum but is not palindromic.
Finally for that range, I checked the number 181 as a number that is palindromic and prime but does not have digits that sum up to an odd number.

The program techincally works for values up to 99,999. However, this number could be modified within the code by adding another
range of numbers (999,999 - 100,000) and using the same code format as the rest of the number ranges.

Project Outline Steps:

1. Declare variables and strings
2. Add a basic UI that asks the user to input a number and explains the purpose of the program
3. Add an if statement block that rejects negative values and
4. Add an overarching for statement that establishes the definition of prime using factor properties
5. Under the above for statement, and if statements for different number ranges
    (Have to use different number ranges because the definition of palindromic will change depending on the number of digits)
6. Have the said if statements check for if a number is prime, and/or palindromic/has an odd digit sum.

*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    // declare variables
    int user_number; //users inputted number
    int digit_ten_thousands;
    int digit_thousands;
    int digit_hundreds;
    int digit_tens;
    int digit_ones;
    int prime_checker = 2; //starts at 2, will increase as numbers are checked for factors

    //declare strings to make code cleaner and easier to read
    string prime_ = " is prime.";
    string prime_oddsum = " is a prime number with digits that sum to an odd number.";
    string prime_pal = " is a prime number that is also palindromic.";
    string prime_oddsum_pal = " is a prime number with digits that sum to an odd number that is also palindromic.";

    // basic UI------------------------
    cout << "This program is designed to find all the prime numbers under an entered number." << endl;
    cout << "Enter a number!" << endl;
    cin >> user_number;

    //if statement for Easter egg (42) and positive number only conditions
   if (user_number < 0) {
    cout << "Please rerun the program and enter a positive number." << endl;
   }else if (user_number == 42) {
    cout << "You found an Easter Egg! The answer to everything is 42!" << endl;
    cout << endl;
   }else if (user_number > 10000 && user_number <= 100000) {
    cout << "That's a big number! You're going to be waiting a while..." << endl;
   }

    //initial overarching for statement, determines criteria for if a number is prime or not
    for (int num = 2; num <= user_number; num++) {
        bool prime_number = true;
        for (prime_checker = 2; prime_checker * prime_checker <= num; prime_checker++) { //declare a bool for if a number is prime (true) or not (false)
            if (num % prime_checker == 0) {
                prime_number = false;
            }
        }
//---------------------Numbers 2 to 10-------------------
        if (prime_number) {

            if (num >= 2 && num < 10 ) { //since there's only 1 digit to each number between 2-9, all primes are palindromic.
                cout << num << prime_pal << endl;
            }else if (num > 10 && num < 100) {
                digit_tens = num / 10;  //converts numbers into their digit components (0-9)
                digit_ones = num % 10;

                int digit_sum = digit_tens + digit_ones;

                if (digit_sum % 2 > 0 && digit_tens == digit_ones) {
                    cout << num << prime_oddsum_pal << endl;
                } else if (digit_tens == digit_ones) {
                    cout << num << prime_pal << endl;
                } else if (digit_sum % 2 > 0) { //if the digits sum up to a number that it is not divisible by 2, the digit sum is odd
                    cout << num << prime_oddsum << endl;
                } else {
                    cout << num << prime_ << endl;  //otherwise it is just a regular prime number
                }
            }

//-------------------Numbers fromm 100 to 1000---------------------------

            else if (num > 100 && num < 1000) {
                digit_hundreds = num / 100;
                digit_tens = (num % 100) / 10;
                digit_ones = num % 10;

                int digit_sum = digit_hundreds + digit_tens + digit_ones;

                if (digit_sum % 2 > 0 && digit_hundreds == digit_ones) {
                    cout << num << prime_oddsum_pal << endl;
                } else if (digit_hundreds == digit_ones) {
                    cout << num << prime_pal << endl;
                } else if (digit_sum % 2 > 0){
                    cout << num << prime_oddsum << endl;
                } else {
                    cout << num << prime_ << endl;
                }
            }

//-----------------Numbers from 1000 to 10000---------------------

            else if (num > 1000 && num < 10000) {
                digit_thousands = num / 1000;
                digit_hundreds = (num % 1000) / 100;
                digit_tens = ((num % 1000) % 100) / 10;
                digit_ones = num % 10;

                int digit_sum = digit_thousands + digit_hundreds + digit_tens + digit_ones;

                if (digit_sum % 2 > 0) { //if the first digit = the fourth digit and the 2nd digit = the 3rd digit then the number is palindromic
                    cout << num << prime_oddsum << endl;
                }else {
                    cout << num << prime_ << endl; //There are no prime palindromes with four digits, so you don't have to test between 9999 and 1000.
                }
            }

//------------------Numbers from 10000 to 100000-----------------------

            else if (num > 10000 && num < 100000) {
                digit_ten_thousands = num / 10000;
                digit_thousands = (num % 10000) / 1000;
                digit_hundreds = ((num % 10000) % 1000) / 100;
                digit_tens = (((num % 10000) % 1000) % 100) / 10;
                digit_ones = num % 10;

                int digit_sum = (digit_ten_thousands + digit_thousands + digit_hundreds + digit_tens + digit_ones);

                if (digit_sum % 2 > 0) {
                    cout << num << prime_oddsum << endl;
                } else {
                    cout << num << prime_ << endl;
                }
            }
        }
        }

    return 0;
}
