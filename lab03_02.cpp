/*
Student Name: Rohan 
Date: September 26th 2018
Course: SYDE 121
Lab Room: WEEF LAB, Room 1792
Assignment: Lab03
Exercise: 02
File name: lab03_02.cpp
Project: Lab03: Drone Ball Drop Problem
Purpose: Calculate the time it takes for a ball to fall from a drone at a height of 15000m using a provided distance formula.

I hereby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts.  This coded solution has
not been plagiarized from other sources and has not been knowingly plagiarized by others.

To test the program logic, I tested numerous values. Overall, I found that by editing the prescribed ranges you could go up
to extremely large numbers (for example I tested 1,500,000 meters as a drop height). As long you the number is greater than 0
(it has to fall in order to have a drop height), then the program works.

Project Outline Steps:
1. Initialize variables, store gravity as a constant and all others as doubles to ensure decimal places are preserved
2. Add formatting/precision settings to ensure answers are in 3 decimal places
3. Use a for loop for distance fallen between 0 and 14000 to print out position updates at time intervals of 1 second
4. Add a print statement updating the user that the ball is close to hitting the ground. This will also serve as a natural break in
   the code to separate the two for loops.
5. Use a second for loop for distance fallen between 14000 and 15000 to print out position updates at time intervals of 0.1 seconds


                                    //ANSWER to question (b) was 55.500 seconds to reach the ground.

*/

#include <iostream>
#include <math.h> //include the math.h library in order to access the power function for the distance formula

using namespace std;

int main() {

double time; //initialize the time variable
const double GRAVITY = 9.80665; //defining gravity as a constant with a value of 9.80665
double distance_fallen; //intialize the distance fallen variable

cout.setf(ios::fixed); //precision settings
cout.setf(ios::showpoint);
cout.precision(3); //precision settings --> 3 decimal places


    for (distance_fallen = 0; distance_fallen <= 14000; time += 1) { //for loop that says from distance fallen 0m to 14000, with time going up in 1s intervals, use the distance formula
        distance_fallen = (0.5) * (GRAVITY) * pow(time, 2);
        if (distance_fallen < 15000) {
        cout << "At time interval " << time << " the distance was " << distance_fallen << endl;
            }
    }

    cout << endl;
    cout << "The ball is almost at the ground!" << endl; //this is the point where the time intervals switch from 1s to 0.1s
    cout << endl; //formatting for a cleaner looking output

    for (distance_fallen = 14000; distance_fallen <= 15000; time += 0.1) { //for loop that says from distance fallen 14000 to 15000, with time going up in 0.1s intervals, use the distance formula
        distance_fallen = (0.5) * (GRAVITY) * pow(time, 2);
        if (distance_fallen < 15000) {
        cout << "At time interval " << time << " the distance is " << distance_fallen << endl;
            }
    }

    cout << endl;
    cout << "The ball has reached the ground. It took " << time << " seconds." << endl;
    //Answer was 55.500 seconds for question b.

return 0;

}
