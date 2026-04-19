#include <iostream>
using namespace std;

int main() 
{
    int choice;
    double value; 
    double result;

    cout << "Unit Converter\n";
    cout << "1 - Kilometers to meters\n";
    cout << "2 - Meters to kilometers\n";
    cout << "3 - Hours to minutes\n";
    cout << "4 - Minutes to seconds\n";
    cout << "Choose option: ";
    cin >> choice;

    cout << "Enter value: ";
    cin >> value;

    if (choice == 1) 
    {
        result = value * 1000;
        cout << "Result: " << result << " meters\n";
    }
    else if (choice == 2) 
    {
        result = value / 1000;
        cout << "Result: " << result << " kilometers\n";
    }
    else if (choice == 3) 
    {
        result = value * 60;
        cout << "Result: " << result << " minutes\n";
    }
    else if (choice == 4) 
    {
        result = value * 60;
        cout << "Result: " << result << " seconds\n";
    }
    else 
    {
        cout << "Invalid option\n";
    }

    return 0;
}