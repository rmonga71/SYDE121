/*
Name: Rohan Monga
UWID: 20763838
Date: November 14, 2018
Course: SYDE 121
Lab: WEEF Lab, E2 Room 1792
Assignment: Lab 7 Assignment 2
Exercise: #2
File Name: lab07_02.cpp
Purpose: To take input of a target string and substring and see if said
         substring is found inside the target string.

I hereby declare that this code, submitted for credit for the course
SYDE 121, is a product of my own efforts. This coded solution has
not been plagiarized from other sources and has not been knowingly
plagiarized by others.

Outline steps:

1. Create a bool function that will run the entire program
2. Create a function to check the first character of the substring for a match with the target string
3. Then, if the first characters match, have a second function continue to check if the strings match.

To test my code, I inputted various substring and target string pairs and checked if my program outputted
the correct verdict. I used substrings of various lengths and used special characters as well. I also tested
out the special cases, such as if the substring is longer than the target string then the program should always
return false, etc.

 */
#include <iostream>
#include <vector>

using namespace std;

//-----------------------------Function Prototyping-----------------------------

bool check_if_contains(vector <char> target_string, vector <char> substring, unsigned long int target_size, unsigned long int substring_size, int p1, int p2);
//PURPOSE: starting with the first character, check for matching characters between the substring and the target string
//INPUTS: target_string, substring, target_string size, substring size, index values
//RETURNS: none

bool match_finder(vector <char> target_string, vector <char> substring, unsigned long int substring_size, int p1, int p2);
//PURPOSE:checks if consecutive characters match until the substring reaches its endpoint
//INPUTS: target_string, substring, substring size, index values
//RETURNS: none

bool run_string_check();
//PURPOSE:initalizes variables, gathers input, and calls the functions
//INPUTS: target_string, substring string
//RETURNS: outputs true or false

bool run_again();
//PURPOSE: allows the user to run the same program again (with different srings).
//INPUTS: none
//RETURNS: none

//------------------------------Main Function-----------------------------------
int main() {

    run_string_check();
    run_again();

    return 0;
}

//------------------------------Function Definitions----------------------------

bool run_string_check() {

    vector <char> target_string;
    vector <char> substring;

    //User's inputs
    char user_target;
    char user_substring;

    //Basic UI
    cout << endl << "Please enter a target string. After the string is complete, enter a period (.). \n";
    cout << "This is the string from which a substring will be looked for.\n\n";

    while (user_target != '.') {
        cin >> user_target;
        target_string.push_back(user_target);
    }

    //Basic UI
    cout << "Please enter a substring. After the string is complete, enter a period (.). \n";
    cout << "This is the string that will be searched for inside the target string.\n\n";

    while (user_substring != '.') {
        cin >> user_substring;
        substring.push_back(user_substring);
    }

    target_string.pop_back();
    substring.pop_back();

    unsigned long int target_size = target_string.size();
    unsigned long int substring_size = substring.size();
    int p1 = 0; //index variables, for accessing certain characters
    int p2 = 0;

    if (check_if_contains(target_string, substring, target_size, substring_size, p1, p2)) {
        cout << "True: your entered substring is a substring in your target string." << endl;
    }else {
        cout << "False: your entered substring is not a substring in your target string." << endl;
        cout << "Please ensure you did not make any typing mistakes in either of your strings.";
    }
    return true;
}

bool check_if_contains(vector <char> target_string, vector <char> substring, unsigned long int target_size, unsigned long int substring_size, int p1, int p2) {

//Cases: --> substring cannot be longer than target string
//       --> substring size and target size can't be 0
//       --> if first character of substring is a match, have to check rest of characters


    if (target_string[p2] == target_string[target_size - 1]) {
        return false; //has to be false if the first letter is not found at all in the target_string
    }else if ((substring_size > target_size) || (substring_size == 0) || (target_size == 0)) { //in order for substring to be contained in target string, must be shorter
        return false;
    }else if (substring[p1] == target_string[p2]) { //if first substring character matches any in target string, call match_finder again
        return match_finder(target_string, substring, substring_size, p1, p2);
    }else {
        return check_if_contains(target_string, substring, target_size, substring_size, p1, p2 + 1);
    }
}

bool match_finder(vector <char> target_string, vector <char> substring, unsigned long int substring_size, int p1, int p2) {

    if (substring[p1] == substring[substring_size - 1]) {
        return true;
    }else if (substring[p1] == target_string[p2]) { //checks next characters
        return match_finder(target_string, substring, substring_size, p1 + 1, p2 + 1);
    }else {
        return false; //no match
    }
}

bool run_again() {
    string answer;

    cout << endl;
    cout << "Would you like to run again with different strings? (Type yes/no): ";

    while(true) { //ask until they answer yes or no
        cin >> answer;
        if (answer == "Yes" || answer == "yes") {
          run_string_check();
            return true;
        } else if (answer == "No" || answer == "no") {
            return false;
        }
        cout << "Invalid input. Type \"yes\" or \"no\": "; //if the user doesn't answer yes or no
    }
}
