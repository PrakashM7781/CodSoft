#include <iostream>
#include <stdexcept>

using namespace std;

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0)
    {
        throw runtime_error("Division by zero is not allowed.");
    }
    return a / b;
}

int main()
{
    double num1, num2;
    char operation;

    cout << "Simple Calculator" << endl;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    double result;

    try
    {
        switch (operation)
        {
        case '+':
            result = add(num1, num2);
            break;
        case '-':
            result = subtract(num1, num2);
            break;
        case '*':
            result = multiply(num1, num2);
            break;
        case '/':
            result = divide(num1, num2);
            break;
        default:
            cout << "Invalid operation!" << endl;
            return 1; // Exit with an error code
        }

        cout << "Result: " << result << endl;
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
        return 1; // Exit with an error code
    }

    return 0;
}
