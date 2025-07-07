#include <iostream>
#include "custom_lib.h"

using namespace std;

// Function to display a number with specified precision
void display_with_precision(double number, int precision) {
    // Extract integer and fractional parts
    int integer_part = static_cast<int>(number);
    double fractional_part = number - integer_part;

    // Print integer part
    cout << integer_part;

    // Print decimal point and fractional part
    if (precision > 0) {
        cout << ".";
        for (int i = 0; i < precision; ++i) {
            fractional_part *= 10;
            int digit = static_cast<int>(fractional_part) % 10;
            cout << digit;
        }
    }
    cout << endl;
}

int main() {
    int choice;
    double a, b, result;
    double num;
    bool exitProgram = false;

    do {
        // Display menu
        cout << "\nChoose an operation:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Square Root" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Addition
                cout << "Enter two numbers to add: ";
                cin >> a >> b;
                result = add(a, b);
                cout << "Result: " << result << endl;
                break;
            case 2:
                // Subtraction
                cout << "Enter two numbers to subtract (a - b): ";
                cin >> a >> b;
                result = subtract(a, b);
                cout << "Result: " << result << endl;
                break;
            case 3:
                // Multiplication
                cout << "Enter two numbers to multiply: ";
                cin >> a >> b;
                result = multiply(a, b);
                cout << "Result: " << result << endl;
                break;
            case 4:
                // Division
                cout << "Enter two numbers to divide (a / b): ";
                cin >> a >> b;
                result = divide(a, b);
                if (b == 0) {
                    cout << "Division by zero error. Result: " << result << endl;
                } else {
                    cout << "Result: ";
                    display_with_precision(result, 6); // Displaying result with precision of 6
                }
                break;
            case 5:
                // Square Root
                cout << "Enter a number to calculate its square root: ";
                cin >> num;
                result = square_root(num);
                if (num < 0) {
                    cout << "Square root of negative number error. Result: " << result << endl;
                } else {
                    cout << "Square Root: ";
                    display_with_precision(result, 6); // Displaying result with precision of 6
                }
                break;
            case 0:
                // Exit program
                exitProgram = true;
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 5." << endl;
                break;
        }

        // After displaying result, ask user to continue or exit
        if (!exitProgram) {
            char continueChoice;
            cout << "\nDo you want to continue? (Enter 'y' for Yes, 'n' for No): ";
            cin >> continueChoice;

            if (continueChoice != 'y' && continueChoice != 'Y') {
                exitProgram = true;
                cout << "Exiting program..." << endl;
            }
        }

    } while (!exitProgram);

    return 0;
}