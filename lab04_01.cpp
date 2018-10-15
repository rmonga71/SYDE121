/*
Name: Rohan 
Date: October 15, 2018
Course: SYDE 121
Lab: WEEF Lab, E2 Room 1792
Assignment: Lab 4 Assignment 1
Exercise: Exercise #1
File Name: lab04_01.cpp
Project: Soccer Simulator
Purpose: Simulate a soccer game between 2 teams

Outline Steps:

1. Create a bool function to run the simulation
2. Define the length of the simulation as to halves of a random number of events betwen 1-30
3. Inside the bool function dictate the 6 main cases for possible events
    a. A shot
    b. B shot
    c. A foul
    d. B foul
    e. A penalty
    f. B penalty
4. Create 3 more functions: 1 for a shot on target, 1 for a foul, and 1 for a penalty
5. Define cases for each function based on specified lab parameters
6. Output statistics for each team at halftime and at the end of the game

To test and debug my code, I built and ran my code several times in order to ensure that everything that
was supposed to be random was random. I recorded outputs for several runs of the program and compared them,
making sure that there were not any noticeable patterns or repeats in number of events and which events actually occurred.

*/
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h> // printf NULL
#include <stdlib.h> //srand, rand
#include <time.h> //time

using namespace std;


//----------------------Declare Functions--------------------------------
bool run_soccer_simulation();

//PURPOSE: runs soccer simulation, returns false if unsuccessful
//INPUT: none
//OUTPUT: "Simulation completed successfully" if true

void shots_on_target(string team_name, int& goals, int& on_goal, int& off_goal, int& shot_blocked);

//PURPOSE: tracks and randomly determines the number of shots taken on target by each team in regular play
//INPUTS: team_name (string that indicates current team name), goals, shots on goal, shots off goal, and blocked shots for the current team.
//RETURNS: nothing to return

void foul(string team_name, int& goals, int& on_goal, int& off_goal, int& shot_blocked, int& fouls, int& yellows, int& reds);

//PURPOSE: tracks and randomly determines the number of fouls, goals, shots on goal, shots off goal, shots blocked, yellow cards, and red cards for each team off free kicks because of fouls
//INPUTS: team_name (string that indicates current team name), goals, shots on goal, fouls, yellow cards, and red cards for the current team (due to a foul)
//RETURNS: nothing to return

void penalty(string team_name, int& goals, int& on_goal, int& off_goal, int& fouls, int& yellows, int& reds);

//PURPOSE: tracks and randomly determines the number of fouls, goals, shots on goal, shots off goal, fouls, yellow cards, and red cards for each team off of penalty kicks/fouls near the goal
//INPUTS: team_name (string that indicates current team name), goals, shots on goal, shots off goal, fouls, yellow cards, and red cars for each current team (due to a penalty kick)
//RETURNS: nothing to return

//-----------------------Main Function-----------------------------
int main () {
    if (run_soccer_simulation())
        cout << "Simulation completed successfully!" << endl;

    return 0;
}

//---------------------Function Definitions--------------------------
bool run_soccer_simulation() {

    const string team_a = "Team A", team_b = "Team B"; //initialize variables - these will be used to track halftime stats
    int a_goals, b_goals, a_on_goal, b_on_goal, a_off_goal, b_off_goal, a_shot_blocked, b_shot_blocked;
    int number_events, current_event;
    int first_half, second_half;
    int a_fouls, b_fouls;
    int a_red_cards, a_yellow_cards;
    int b_red_cards, b_yellow_cards;

    srand (time(NULL)); //time value is constantly changing --> random
    number_events = rand() % 30 + 1;
    //add
    first_half = number_events / 2;
    second_half = number_events - first_half; //this ensures that the number of events per half is random (not evenly split)

cout << "Welcome to the soccer simulator. Enjoy the game!\n" << endl;

    for (int event = 1; event <= first_half; event++) { //for loop for the first half
        current_event = rand () % 6 + 1; //doesn't include 0

        switch (current_event) {

            case 1:
                shots_on_target(team_a, a_goals, a_on_goal, a_off_goal, a_shot_blocked);
                break;

            case 2:
                shots_on_target(team_b, b_goals, b_on_goal, b_off_goal, b_shot_blocked);
                break;

            case 3:
                foul(team_a, a_goals, a_on_goal, a_off_goal, a_shot_blocked, b_fouls, b_yellow_cards, b_red_cards);
                break;

            case 4:
                foul(team_b, b_goals, b_on_goal, b_off_goal, b_shot_blocked, a_fouls, a_yellow_cards, a_red_cards);
                break;

            case 5:
                penalty(team_a, a_goals, a_on_goal, a_off_goal, b_fouls, b_yellow_cards, b_red_cards);
                break;

            case 6:
                penalty(team_b, b_goals, b_on_goal, b_off_goal, a_fouls, a_yellow_cards, a_red_cards);
                break;

        }



    }
//-----------------First Half Stats-------------------
    cout << endl;
    cout << "End of first half!" << " The score is Team A " << a_goals << ", Team B " << b_goals << "\n\n";
    cout << "Here are the first half stats:\n\n";
    cout << "\t\t" << "Shots on goal: Team A - " << a_on_goal << ", Team B - " << b_on_goal << endl;
    cout << "\t\t" << "Shots missed: Team A - " << a_off_goal << ", Team B - " << b_off_goal << endl;
    cout << "\t\t" << "Fouls: Team A - " << a_fouls << ", Team B - " << b_fouls << endl;
    cout << "\t\t" << "Yellow cards: Team A - " << a_yellow_cards << ", Team B - " << b_yellow_cards << endl;
    cout << "\t\t" << "Red cards: Team A - " << a_red_cards << ", Team B - " << b_red_cards << endl;
    cout << endl;

    for (int event = 1; event <= second_half; event++) { //for loop for the second half
        current_event = rand () % 6 + 1; //doesn't include 0

        switch (current_event) {

            case 1:
                shots_on_target(team_a, a_goals, a_on_goal, a_off_goal, a_shot_blocked);
                break;

            case 2:
                shots_on_target(team_b, b_goals, b_on_goal, b_off_goal, b_shot_blocked);
                break;

            case 3:
                foul(team_a, a_goals, a_on_goal, a_off_goal, a_shot_blocked, b_fouls, b_yellow_cards, b_red_cards);
                break;

            case 4:
                foul(team_b, b_goals, b_on_goal, b_off_goal, b_shot_blocked, a_fouls, a_yellow_cards, a_red_cards);
                break;

            case 5:
                penalty(team_a, a_goals, a_on_goal, a_off_goal, b_fouls, b_yellow_cards, b_red_cards);
                break;

            case 6:
                penalty(team_b, b_goals, b_on_goal, b_off_goal, a_fouls, a_yellow_cards, a_red_cards);
                break;

        }



    }
//-------------Final End of Game Stats-------------
    cout << "That's the end of the game!" << " The score is Team A " << a_goals << ", Team B " << b_goals << "\n\n";
    cout << endl;
    cout << "Here are the final game stats:\n\n";
    cout << "\t\t" << "Shots on goal: Team A - " << a_on_goal << ", Team B - " << b_on_goal << endl;
    cout << "\t\t" << "Shots missed: Team A - " << a_off_goal << ", Team B - " << b_off_goal << endl;
    cout << "\t\t" << "Fouls: Team A - " << a_fouls << ", Team B - " << b_fouls << endl;
    cout << "\t\t" << "Yellow cards: Team A - " << a_yellow_cards << ", Team B - " << b_yellow_cards << endl;
    cout << "\t\t" << "Red cards: Team A - " << a_red_cards << ", Team B - " << b_red_cards << endl;
    cout << endl;
}

void shots_on_target(string team_name, int& goals, int& on_goal, int& off_goal, int& shot_blocked) {

    int shot_outcome;

    shot_outcome = rand() % 4;

    switch(shot_outcome) {

        case 0:
            cout << "\t" << team_name << " has scored a goal!\n\n";
            ++goals;
            break;

        case 1:
            cout << "\t" << team_name << " has a shot on goal, but it is saved!\n\n";
            ++on_goal;
            break;

        case 2:
            cout << "\t" << team_name << " has a shot, but they miss!\n\n";
            ++off_goal;
            break;

        case 3:
            cout << "\t" << team_name << " has a shot but it is blocked by the defense. Selfless play!\n\n";
            ++shot_blocked;
            break;
    }

}

void foul(string team_name, int& goals, int& on_goal, int& off_goal, int& shot_blocked, int& fouls, int& yellows, int& reds) {

    int foul_outcome, cards;

    foul_outcome = rand() % 4;
    cards = rand() % 3;

    switch(foul_outcome) {

        case 0:
            cout << "\t" << team_name << " has a free kick after the foul. They score!\n\n";
            ++goals;
            ++fouls;
            break;

        case 1:
            cout << "\t" << team_name << " has a free kick after the foul, but it is saved. Wow!\n\n";
            ++on_goal;
            ++fouls;
            break;

        case 2:
            cout << "\t" << team_name << " has a free kick after the foul, but they miss the net! Nice try!\n\n";
            ++off_goal;
            ++fouls;
            break;

        case 3:
            cout << "\t" << team_name << " has a free kick after the foul, but it is blocked by a defender!\n\n";
            ++shot_blocked;
            ++fouls;
            break;

    }

    switch(cards) {

        case 0:
            cout << "\t" << team_name << " receives no card for their foul.\n\n";
            break;

        case 1:
            cout << "\t" << team_name << " has received a yellow card!\n\n";
            ++yellows;
            break;

        case 2:
            cout << "\t" << team_name << " has a received a red card! Oh no!\n\n";
            ++reds;
            break;

    }

}

void penalty(string team_name, int& goals, int& on_goal, int& off_goal, int& fouls, int& yellows, int& reds) {

    int penalty_outcome, penalty_cards;

    penalty_outcome = rand() % 3;
    penalty_cards = rand () % 3;

    switch(penalty_outcome) {

        case 0:
            cout << "\t" << team_name << " has a penalty shot. They score!\n\n";
            ++goals;
            ++fouls;
            break;

        case 1:
            cout << "\t" << team_name << " has a penalty shot, but it is saved! Wow!\n\n";
            ++on_goal;
            ++fouls;
            break;

        case 2:
            cout << "\t" << team_name << " has a penalty shot, but they miss the net!\n\n";
            ++off_goal;
            ++fouls;
            break;

    }

    switch(penalty_cards) {

        case 0:
            cout << "\t" << team_name << " does not receive a card on the penalty! Interesting call.\n\n";
            break;

        case 1:
            cout << "\t" << team_name << " receives a yellow card for the penalty!\n\n";
            ++yellows;
            break;

        case 2:
            cout << "\t" << team_name << " receives a red card! Dangerous play!\n\n";
            ++reds;
            break;

    }

}

