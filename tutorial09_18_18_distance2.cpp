#include <iostream>

 using namespace std;

int main() {
    // Step 1, Modify the program given above to convert miles in to kilometers
    // Step 2, Output the result to a precision of four decimal points
    double temp_kilometers = 50; // declared variables at the start
    double temp_miles = 0; // put one space between operator and operand

    temp_miles = temp_kilometers * 1.60934; // use brackets to enforce operator precendence

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4); // change precision to four decimal points

    cout << temp_kilometers << " in kilometers equals "
         << temp_miles << " in miles \n";

return 0;
}

