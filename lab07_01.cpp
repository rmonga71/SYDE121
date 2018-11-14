/*
Name: Rohan Monga
UWID: 20763838
Date: November 14, 2018
Course: SYDE 121
Lab: WEEF Lab, E2 Room 1792
Assignment: Lab 7 Assignment 1
Exercise: Exercise #1
File Name: lab07_01.cpp
Purpose: Print out a specified star formation based on a value n

I hereby declare that this code, submitted for credit for the course
SYDE 121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly
plagiarized by others.

Outline steps:

1. Create a function that will be responsible for printing each line. Must also determine
   whether the middle character will be a star or a space (this is based on the input value, n)
2. Create a function to call the mentioned print function

To test out my code, I used several different values for n as the input, ensuring that what appeared on the console
was the same as the predicted shape based on the pattern.
*/

#include <iostream>

using namespace std;

//------------------------Function Prototyping----------------------------------

void print_line(int n, int line);
//PURPOSE: responsible for printing "*" and " " values, also determines whether
          //middle value will be a star ("*") or a space, and prints accordingly
//INPUTS: input number n, line
//OUTPUTS: nothing to return

void pins(int n, int current_line);
//PURPOSE: calls the print function inside it in order to print out each line
//INPUTS: input number n, line
//OUTPUTS: nothing to return

void pins(int n);
//PURPOSE: ensures that the line to be included is always line 1
//INPUTS: input number n
//OUTPUTS: nothing to return

//-----------------------Main Function------------------------------------------

int main() {

  int n;
  cout << "Enter a positive number, n" << endl; //Basic UI
  cin >> n;
  pins(n);

  return 0;
}

//----------------------Function Definitions------------------------------------

void print_line(int n, int line) {
    int num_spaces = (n - line + 1); //determined this formula on paper first
    for (int x = 1; x <= num_spaces; x++) { //prints out the needed amount of spaces
        cout << " ";
    }

    for (int x = 1; x <= ((2 * line) - 1); x++) { //determined this formula on paper
        if (x % 2 == 0) {
            cout << " ";
        }else if (x % 2 != 0) {
            cout << "*";
        }
    }

cout << endl;

}

void pins(int n) {
    pins(n, 1);
}

void pins(int n, int current_line) {
    if (current_line == n) {  //for if the current line is the middle
        print_line(n, current_line);
    }else {
        print_line(n, current_line);
        pins(n, current_line + 1); //covers each line
        print_line(n, current_line);
    }
}
