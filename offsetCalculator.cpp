/*Samuel Snowden
CIS1202.501
4/28/2024
*/
#include <iostream>

using namespace std;

// Define custom exceptions
class invalidCharacterException : public exception {
    virtual const char* what() const noexcept override {
        return "Invalid character";
    }
};

class invalidRangeException : public exception {
    virtual const char* what() const noexcept override {
        return "Invalid range";
    }
};

// Function to calculate character offsets
char character(char start, int offset) {
    // Check if start is a letter
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }

    // Convert start to uppercase to avoid case transition
    start = toupper(start);

    // Calculate the new character
    char result = start + offset;

    // Check if the result is out of range
    if (!isalpha(result)) {
        throw invalidRangeException();
    }

    return result;
}

int main() {
    try {
        // Test cases
        cout << "character('a', 1) = " << character('a', 1) << endl; // Output: b
        cout << "character('a', -1) = " << character('a', -1) << endl; // Exception: invalidRangeException
        cout << "character('Z', -1) = " << character('Z', -1) << endl; // Output: Y
        cout << "character('?', 5) = " << character('?', 5) << endl; // Exception: invalidCharacterException
        cout << "character('A', 32) = " << character('A', 32) << endl; // Exception: invalidRangeException
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
