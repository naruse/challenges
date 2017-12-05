/*
Implement an algorithm to determine if a string has all unique
characters. What if you cannot use additional data structures?

Assumption:
We assume all available chars is in ASCII hence 256 possible chars.
 */

#include <iostream>

using namespace::std;

const int availableChars = 256;
bool possibleChars[availableChars];

void InitializePossibleChars();
bool StringContainsUniqueChars(const string& str);

int main(int argc, char* argv[]) {
    InitializePossibleChars();

    string test = "abcdeftgh";
    cout << "String \"" << test << "\" is unique: " << (StringContainsUniqueChars(test)? "true" : "false") << endl;
    int t = 3/2;
    cout << t << endl;
}

void InitializePossibleChars() {
    for(int i = 0; i < availableChars; i++)
        possibleChars[i] = false;
}

bool StringContainsUniqueChars(const string& str) {
    if(str.length() > availableChars)//string contains more than all the
                                     //possible chars, hence there are
                                     //repeated chars
        return false;

    for(int i = 0; i < str.length(); i++) {
        if(possibleChars[int(str[i])])
            return false;
        possibleChars[int(str[i])] = true;
    }
    return true;
}
