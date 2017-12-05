/*
Implement a method to perform basic string compression using the counts of
repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the orig-
inal string, your method should return the original string.


NOTE:
C++ strings are mutable so the performance considerations of concatenation
are less of a concern.

 */

#include <iostream>

using namespace::std;

const string CompressStr(const string& str);

int main(int argc, char* argv[]) {

    //string input = "juan sebastian munoz arango";
    string input = "aaaaaaabvsssdddddddddmdddcc";

    cout << "Input  Str: " << input << endl;

    cout << "Compressed: " << CompressStr(input) << endl;
}

const string CompressStr(const string& str) {
    if(str.length() < 1)
        return str;
    string compressedStr = "";
    int amountOfTimes = 1;
    char charBeingCompressed = str[0];

    for(int i = 1; i < str.length(); i++) {
        if(charBeingCompressed != str[i]) {
            if(compressedStr.length() >= str.length())
                return str;
            compressedStr += charBeingCompressed + to_string(amountOfTimes);
            charBeingCompressed = str[i];
            amountOfTimes = 1;
        } else {
            amountOfTimes++;
        }
    }
    compressedStr += charBeingCompressed + to_string(amountOfTimes);
    return compressedStr;
}
