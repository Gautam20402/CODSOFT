#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Generate a random number between 1 and 100
    int Number = rand() % 100 + 1;
    int u_g = 0;

    cout << "Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100." <<endl;
    cout << "Can you guess what it is?" << endl;

    // Loop until the user guesses the correct number
    while (u_g != Number) {
        cout << "Enter your guess: ";
        cin >> u_g;

        if (u_g < Number) {
            cout << "Too low! Try again." << endl;
        } else if (u_g > Number) {
            cout << "Too high! Try again." <<endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << Number << endl;
        }
    }

    return 0;
}
