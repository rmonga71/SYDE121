/*
Name: Rohan Monga
UWID: 20763838
Date: September 27, 2018
Course: SYDE 121
Lab: WEEF Lab, E2 Room 1792
Assignment: Lab 3 Assignment 3
Exercise: Exercise #3
File Name: lab03_03.cpp
Project: Horoscope Tool

I hereby declare that this code, submitted for credit for the course SYDE121, is a product of my own efforts.
This coded solution has not been plagiarized from other sources and has not been knowingly plagiarized by others.

I tested a number of values that are not valid dates in order to test the program logic.
I tested every month (0-12) with the day "40". I also tested Feb 30th, September 31st, and other exceptions.

Project Outline Steps:
1. Intialize variables for date of birth and month of birth and strings for information about each zodiac sign
2. Add a basic user interface to collect data for month of birth and date of birth
3. Add conditions so that the user can't enter invalid dates
4. Use if statements to narrow down months then date ranges to assign a zodiac sign to the user
5. On a case to case basis add any more needed restrictions/conditions for entering dates (like Feb has 28 days)

*/

//References: Astrology information is from the link www.astrology-zodiac-signs.com

#include <iostream>
#include <string>

using namespace std;

int main() {

int date_of_birth; //initialize date of birth and month of birth variables
int month_of_birth;

//initialize strings for each of the zodiac signs
string Aquarius = "You are an Aquarius. You're shy and quiet, but also energetic. A strength of yours is being original. You're compatible with Leo and Sagittarius. Your element is air.";
string Capricorn = "You are a Capricorn. You represent time and responsibility. A strength of yours is that you'd make a good manager. You're compatible with Taurus and Cancers. Your element is earth.";
string Pisces = "You are a Pisces. You are very friendly. A strength of yours is that you are wise. You are compatible with Virgos and Tarus. Your element is water.";
string Aries = "You are an Aries. You are courageous and determined. A strength of yours is your confidence. You are compatible with Libras and Leos. Your element is fire.";
string Taurus = "You are a Taurus. You are practical and well-grounded. A strength of yours is your reliability. You are compatible with Scorpios and Cancers. Your element is earth.";
string Gemini = "You are a Gemini. You are expressive and quick-witted. A strenght of yours is ability to learn quickly. You are compatible with Sagittarius and Aquarius. Your element is air.";
string Cancer = "You are a Cancer. You intuitive and sentimental. A strength of yours is your imagination. You are compatible with Capricorns and Taurus. Your element is water.";
string Leo = "You are a Leo. You are creative and a natural born leader. A strength of yours is your warm heart. You're compatible with Aquarius and Geminis. Your element is fire.";
string Virgo = "You are a Virgo. You are loyal and have a deep sense of humanity. A strength of yours is your trait as a hard-worker. You are compatible with Pisces and Cancers. Your element is Earth.";
string Libra = "You are a Libra. Partnership is very important to you, and but you can be indecisive. A strength of yours is social ability. You are compatible with Aries and Sagittarius. Your element is air.";
string Scorpio = "You are a Scorpio. You are practice and well-grounded. Your element is water. You are compatible with Taurus and Cancers.";
string Sagittarius = "You are a Sagittarius. You are generous, idealistic, and have a great sense of humour. Your element is Fire, and you are compatible with Gemini and Aries.";

cout << "What is your date of birth (day)?"; //basic user interface
cin >> date_of_birth;

cout << "What is your birth month (format 0-12)?"; //basic user interface
cin >> month_of_birth;

if (date_of_birth > 31) //conditions to ensure only valid dates are entered (no month has more 31 days)
    cout << "Please try again and enter a valid date.";
else if (month_of_birth > 12)
    cout << "Please try again and enter a valid date."; //there are only 12 different months
else if (month_of_birth == 1 && date_of_birth >= 20)
    cout << Aquarius;
else if (month_of_birth == 1 && date_of_birth < 20)
    cout << Capricorn;
else if (month_of_birth == 2 && date_of_birth >= 19 && date_of_birth < 28)
    cout << Pisces;
else if (month_of_birth == 2 && date_of_birth < 19)
    cout << Aquarius;
else if (month_of_birth == 2 && date_of_birth > 29) //Feb 28th is the last day in the month, but in a leap year Feb 29th exists.
    cout << "Please try again and enter a valid date.";
else if (month_of_birth == 3 && date_of_birth <= 20)
    cout << Pisces;
else if (month_of_birth == 3 && date_of_birth > 20)
    cout << Aries;
else if (month_of_birth == 4 && date_of_birth <= 19)
    cout << Aries;
else if (month_of_birth == 4 && date_of_birth > 19 && date_of_birth < 31) //April 30th is the last day in the month.
    cout << Taurus;
else if (month_of_birth == 4 && date_of_birth > 30)
    cout << "Please try again and enter a valid date.";
else if (month_of_birth == 5 && date_of_birth <= 20)
    cout << Taurus;
else if (month_of_birth == 5 && date_of_birth > 20)
    cout << Gemini;
else if (month_of_birth == 6 && date_of_birth <= 20)
    cout << Gemini;
else if (month_of_birth == 6 && date_of_birth > 20 && date_of_birth < 31)
    cout << Cancer;
else if (month_of_birth == 6 && date_of_birth > 30)
    cout << "Please try again and enter a valid date.";
else if (month_of_birth == 7 && date_of_birth <= 22)
    cout << Cancer;
else if (month_of_birth == 7 && date_of_birth > 22)
    cout << Leo;
else if (month_of_birth == 8 && date_of_birth <= 22)
    cout << Leo;
else if (month_of_birth == 8 && date_of_birth > 22)
    cout << Virgo;
else if (month_of_birth == 9 && date_of_birth <= 22)
    cout << Virgo;
else if (month_of_birth == 9 && date_of_birth > 22 && date_of_birth < 31)
    cout << Libra;
else if (month_of_birth == 9 && date_of_birth > 30) //September 30th is the last day of the month.
    cout << "Please try again and enter a valid date.";
else if (month_of_birth == 10 && date_of_birth <= 22)
    cout << Libra;
else if (month_of_birth == 10 && date_of_birth > 22)
    cout << Scorpio;
else if (month_of_birth == 11 && date_of_birth <= 21)
    cout << Scorpio;
else if (month_of_birth == 11 && date_of_birth > 21 && date_of_birth < 31)
    cout << Sagittarius;
else if (month_of_birth == 11 && date_of_birth > 30) //November 30th is the last day of the month.
    cout << "Please try again and enter a valid date.";
else if (month_of_birth == 12 && date_of_birth <= 21)
    cout << Sagittarius;
else if (month_of_birth == 12 && date_of_birth > 21)
    cout << Capricorn;

    return 0;
}
