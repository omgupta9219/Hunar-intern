#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to convert an integer part from any base to decimal
int integerToDecimal(const string &num, int base) {
    int len = num.length();
    int power = 1; // Initialize the power of base
    int result = 0;

    for (int i = len - 1; i >= 0; i--) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9')
            digit = num[i] - '0';
        else
            digit = num[i] - 'A' + 10;
        result += digit * power;
        power *= base;
    }

    return result;
}

// Function to convert the fractional part from any base to decimal
double fractionalToDecimal(const string &num, int base) {
    double result = 0.0;
    double power = 1.0 / base;

    for (char digit : num) {
        int value;
        if (digit >= '0' && digit <= '9')
            value = digit - '0';
        else
            value = digit - 'A' + 10;
        result += value * power;
        power /= base;
    }

    return result;
}

// Function to convert a decimal integer to any base
string decimalToInteger(int num, int base) {
    string result = "";
    while (num > 0) {
        int remainder = num % base;
        if (remainder >= 10)
            result += (remainder - 10) + 'A';
        else
            result += remainder + '0';
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result == "" ? "0" : result;
}

// Function to convert a decimal fraction to any base
string decimalToFractional(double num, int base, int precision = 6) {
    string result = "";
    while (precision--) {
        num *= base;
        int integral = (int)num;
        if (integral >= 10)
            result += (integral - 10) + 'A';
        else
            result += integral + '0';
        num -= integral;
    }
    return result;
}

// Function to convert between bases
string convertBase(const string &num, int fromBase, int toBase) {
    size_t point = num.find('.');
    string intPart = point == string::npos ? num : num.substr(0, point);
    string fracPart = point == string::npos ? "" : num.substr(point + 1);

    int decimalInt = integerToDecimal(intPart, fromBase);
    double decimalFrac = fractionalToDecimal(fracPart, fromBase);

    string result = decimalToInteger(decimalInt, toBase);
    if (!fracPart.empty())
        result += "." + decimalToFractional(decimalFrac, toBase);

    return result;
}

int main() {
    string num;
    int fromBase, toBase;

    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the base of the input number: ";
    cin >> fromBase;
    cout << "Enter the base to convert to: ";
    cin >> toBase;

    string result = convertBase(num, fromBase, toBase);
    cout << "The number " << num << " in base " << fromBase << " is " << result << " in base " << toBase << endl;

    return 0;
}

