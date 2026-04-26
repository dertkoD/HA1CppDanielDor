#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

string normalizeTemperatureUnit(string unit)
{
    if (unit == "c")
        return "C";
    else if (unit == "f")
        return "F";
    else if (unit == "k")
        return "K";
    else
        return unit;
}

string normalizeDistanceUnit(string unit)
{
    if (unit == "M")
        return "m";
    else if (unit == "KM")
        return "km";
    else if (unit == "MI")
        return "mi";
    else if (unit == "FT")
        return "ft";
    else
        return unit;
}

string normalizeWeightUnit(string unit)
{
    if (unit == "KG")
        return "kg";
    else if (unit == "G")
        return "g";
    else if (unit == "LB")
        return "lb";
    else if (unit == "OZ")
        return "oz";
    else
        return unit;
}

string normalizeTimeUnit(string unit)
{
    if (unit == "H")
        return "h";
    else if (unit == "MIN")
        return "min";
    else if (unit == "S")
        return "s";
    else
        return unit;
}

bool isTemperatureUnit(string unit)
{
    unit = normalizeTemperatureUnit(unit);

    if (unit == "C" || unit == "F" || unit == "K")
        return true;
    else
        return false;
}

bool isDistanceUnit(string unit)
{
    unit = normalizeDistanceUnit(unit);

    if (unit == "m" || unit == "km" || unit == "mi" || unit == "ft")
        return true;
    else
        return false;
}

bool isWeightUnit(string unit)
{
    unit = normalizeWeightUnit(unit);

    if (unit == "kg" || unit == "g" || unit == "lb" || unit == "oz")
        return true;
    else
        return false;
}

bool isTimeUnit(string unit)
{
    unit = normalizeTimeUnit(unit);

    if (unit == "h" || unit == "min" || unit == "s")
        return true;
    else
        return false;
}

double toBaseTemperature(double value, string unit)
{
    unit = normalizeTemperatureUnit(unit);

    // Base unit: Celsius
    if (unit == "C")
        return value;
    else if (unit == "F")
        return (value - 32) * 5.0 / 9.0;
    else
        return value - 273.15;
}

double fromBaseTemperature(double value, string unit)
{
    unit = normalizeTemperatureUnit(unit);

    // Base unit: Celsius
    if (unit == "C")
        return value;
    else if (unit == "F")
        return value * 9.0 / 5.0 + 32;
    else
        return value + 273.15;
}

double toBaseDistance(double value, string unit)
{
    unit = normalizeDistanceUnit(unit);

    // Base unit: meters
    if (unit == "m")
        return value;
    else if (unit == "km")
        return value * 1000;
    else if (unit == "mi")
        return value * 1609.34;
    else
        return value * 0.3048;
}

double fromBaseDistance(double value, string unit)
{
    unit = normalizeDistanceUnit(unit);

    // Base unit: meters
    if (unit == "m")
        return value;
    else if (unit == "km")
        return value / 1000;
    else if (unit == "mi")
        return value / 1609.34;
    else
        return value / 0.3048;
}

double toBaseWeight(double value, string unit)
{
    unit = normalizeWeightUnit(unit);

    // Base unit: grams
    if (unit == "kg")
        return value * 1000;
    else if (unit == "g")
        return value;
    else if (unit == "lb")
        return value * 453.592;
    else
        return value * 28.3495;
}

double fromBaseWeight(double value, string unit)
{
    unit = normalizeWeightUnit(unit);

    // Base unit: grams
    if (unit == "kg")
        return value / 1000;
    else if (unit == "g")
        return value;
    else if (unit == "lb")
        return value / 453.592;
    else
        return value / 28.3495;
}

double toBaseTime(double value, string unit)
{
    unit = normalizeTimeUnit(unit);

    // Base unit: seconds
    if (unit == "h")
        return value * 3600;
    else if (unit == "min")
        return value * 60;
    else
        return value;
}

double fromBaseTime(double value, string unit)
{
    unit = normalizeTimeUnit(unit);

    // Base unit: seconds
    if (unit == "h")
        return value / 3600;
    else if (unit == "min")
        return value / 60;
    else
        return value;
}

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double readValue()
{
    double value;

    while (true)
    {
        cout << "Value: ";
        cin >> value;

        if (cin.fail())
        {
            cout << "Invalid number. Try again.\n";
            clearInput();
        }
        else
        {
            return value;
        }
    }
}

char readAgain()
{
    char again;

    while (true)
    {
        cout << "\nAnother conversion? (y/n): ";
        cin >> again;

        if (again == 'y' || again == 'Y' || again == 'n' || again == 'N')
            return again;
        else
            cout << "Invalid choice. Try again.\n";
    }
}

int main()
{
    string category;
    string fromUnit;
    string toUnit;
    double value;
    double baseValue;
    double result;
    char again = 'y';

    cout << fixed << setprecision(2);
    cout << "Unit Converter\n";
    cout << "--------------\n";

    while (again == 'y' || again == 'Y')
    {
        while (true)
        {
            cout << "\nCategories:\n";
            cout << "1 - Temperature\n";
            cout << "2 - Distance\n";
            cout << "3 - Weight\n";
            cout << "4 - Time\n";
            cout << "q - Quit\n";
            cout << "Choose category: ";
            cin >> category;

            if (category == "1" || category == "2" || category == "3" || category == "4" || category == "q" || category == "Q")
                break;
            else
                cout << "Invalid category. Try again.\n";
        }

        if (category == "q" || category == "Q")
        {
            cout << "Goodbye!\n";
            break;
        }

        if (category == "1")
        {
            while (true)
            {
                cout << "\nTemperature units: C, F, K\n";
                cout << "Convert from: ";
                cin >> fromUnit;

                if (isTemperatureUnit(fromUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            while (true)
            {
                cout << "Convert to: ";
                cin >> toUnit;

                if (isTemperatureUnit(toUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            fromUnit = normalizeTemperatureUnit(fromUnit);
            toUnit = normalizeTemperatureUnit(toUnit);

            value = readValue();

            baseValue = toBaseTemperature(value, fromUnit);
            result = fromBaseTemperature(baseValue, toUnit);

            cout << "Result: " << value << " " << fromUnit << " = " << result << " " << toUnit << "\n";
        }
        else if (category == "2")
        {
            while (true)
            {
                cout << "\nDistance units: m, km, mi, ft\n";
                cout << "Convert from: ";
                cin >> fromUnit;

                if (isDistanceUnit(fromUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            while (true)
            {
                cout << "Convert to: ";
                cin >> toUnit;

                if (isDistanceUnit(toUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            fromUnit = normalizeDistanceUnit(fromUnit);
            toUnit = normalizeDistanceUnit(toUnit);

            value = readValue();

            baseValue = toBaseDistance(value, fromUnit);
            result = fromBaseDistance(baseValue, toUnit);

            cout << "Result: " << value << " " << fromUnit << " = " << result << " " << toUnit << "\n";
        }
        else if (category == "3")
        {
            while (true)
            {
                cout << "\nWeight units: kg, g, lb, oz\n";
                cout << "Convert from: ";
                cin >> fromUnit;

                if (isWeightUnit(fromUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            while (true)
            {
                cout << "Convert to: ";
                cin >> toUnit;

                if (isWeightUnit(toUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            fromUnit = normalizeWeightUnit(fromUnit);
            toUnit = normalizeWeightUnit(toUnit);

            value = readValue();

            baseValue = toBaseWeight(value, fromUnit);
            result = fromBaseWeight(baseValue, toUnit);

            cout << "Result: " << value << " " << fromUnit << " = " << result << " " << toUnit << "\n";
        }
        else if (category == "4")
        {
            while (true)
            {
                cout << "\nTime units: h, min, s\n";
                cout << "Convert from: ";
                cin >> fromUnit;

                if (isTimeUnit(fromUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            while (true)
            {
                cout << "Convert to: ";
                cin >> toUnit;

                if (isTimeUnit(toUnit))
                    break;
                else
                    cout << "Invalid unit. Try again.\n";
            }

            fromUnit = normalizeTimeUnit(fromUnit);
            toUnit = normalizeTimeUnit(toUnit);

            value = readValue();

            baseValue = toBaseTime(value, fromUnit);
            result = fromBaseTime(baseValue, toUnit);

            cout << "Result: " << value << " " << fromUnit << " = " << result << " " << toUnit << "\n";
        }

        again = readAgain();
    }

    if (again == 'n' || again == 'N')
        cout << "Goodbye!\n";

    return 0;
}