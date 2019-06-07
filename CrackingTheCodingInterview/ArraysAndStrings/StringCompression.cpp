//Implement a method to perform basic string compression using the
//counts of repeated characters. For example, the string aabcccccaaa
//would become a2b1c5a3. If the "compressed" string would not become
//smaller than the original string, your method should return the
//original string.

//APPROACH
//go through the string and start assembling the string while
//comparing with the size, if the current size is bigger then return
//the originalimmediately

#include <iostream>

std::string CompressString(std::string const& s) {

    std::string compressedString = "";

    char currentChar = s[0];
    int countRepetitions = 1;
    for(int i = 1; i < s.length(); i++) {
        if(compressedString.length() > s.length())
            return s;

        if(currentChar == s[i]) {
            countRepetitions++;
        } else {
            compressedString += currentChar + std::to_string(countRepetitions);
            currentChar = s[i];
            countRepetitions = 1;
        }
    }
    compressedString += currentChar + std::to_string(countRepetitions);
    return compressedString;
}

int main() {
    std::string s = "aabcccccaaa";
    std::cout << "Original  : " << s << std::endl;
    std::cout << "Compressed: " << CompressString(s) << std::endl;
}

