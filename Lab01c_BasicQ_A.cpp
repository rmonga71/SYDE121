#include <iostream>

using namespace std; // avoids having to type std:_ in front of everything
                    // you can't use using namespace std everywhere, but for now in school it is fine

int main() {
    int uw_id, age, date_of_birth; // allocates space for three pieces of data
                                    // formate DDMMYYYY

    string name;
    // accept as input UWID, age, and date of birth
    // print all three in a cohesively formatted sentence
    cout << "Welcome, user!" << endl;

    cout << "What is your name? " << endl;
    cin >> name;

    cout << "What is your UWID? " << endl;
    cin >> uw_id;


    cout << "What is your age? " << endl;
    cin >> age;

    cout << "What is your date of birth (formate DDMMYYYY)? " << endl;
    cin >> date_of_birth;

    cout << "Hello " << name;
    cout << ", your age is " << age;
    cout << " your UWID is " << uw_id;
    cout << " and your date of birth is " << date_of_birth << "." << endl;

        return 0; // terminate the program
}
