/*
Write a method to replace all spaces in a string with'%20'. You may assume
that the string has sufficient space at the end of the string to hold the
additional characters, and that you are given the "true" length of the
string. (Note: if imple- menting in Java, please use a character array so
that you can perform this opera- tion in place.)

EXAMPLE:
True Length: 13
Input: "Mr John Smith    "
Output:"Mr%20Dohn%20Smith"


Approach:
Given the true length, lets start from the end of the true length while
having an index that counts the replaced chars
*/


#include <iostream>

using namespace::std;

void ReplaceSpaces(string& str, int trueLength);

int main(int argc, char* argv[]) {
    /*string test = "Mr John Smith    ";
      int testTrueLength = 13;*/

    string test = "Mr John Smith       ";
    int testTrueLength = 14;

    cout << "InputStr: " << test << endl;

    ReplaceSpaces(test, testTrueLength);

    cout << "Replaced: " << test << endl;
}



void ReplaceSpaces(string& str, int trueLength) {
    int indexStr = str.length() - 1;//index that places replaced chars.
    for(int i = trueLength-1; i >= 0; i--) {
        if(str[i] == ' ') {
            str[indexStr] = '0';
            str[indexStr-1] = '2';
            str[indexStr-2] = '%';
            indexStr -= 3;
        } else {
            str[indexStr] = str[i];
            indexStr--;
        }
    }
}
