#include <iostream>
using namespace std;
int main() {
    double num1, num2;
    char opr;
    double ans;

    cout << "Basic Calculator!" << endl;
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter an operator (+, -, *, /): ";
    cin >> opr;

    cout << "Enter the second number: ";
    cin >> num2;

    // Perform the selected operation
    switch (opr) {
        case '+':
            ans = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << ans << endl;
            break;
        case '-':
            ans = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << ans << endl;
            break;
        case '*':
            ans = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << ans << endl;
            break;
        case '/':
            if (num2 != 0) {
                ans = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << ans << endl;
            } else {
                cout << "Error: Division by zero is undefined." << endl;
            }
            break;
        default:
            cout << "Error: Invalid operator. Please use +, -, *, or /." << endl;
    }

    return 0;
}
