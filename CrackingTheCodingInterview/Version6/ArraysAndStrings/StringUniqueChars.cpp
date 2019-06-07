// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

// Approach, go through the string and save values in a set check if
// it exists in the set and if it doesnt then carry on until finished.

//What if we cannot use additional data structures?
//
// -> If the string is in ascii create an array of bools and access
// -> the position in the array and set it to true, if it was already
// -> true then its not unique



#include <unordered_set>//unordered_set is O(1), whereas set is O(log n)
#include <iostream>

bool IsUnique(std::string const & s) {
    std::unordered_set<char> uniqueChars;

    for(int i = 0; i < s.length(); i++) {
        if(uniqueChars.find(s[i]) == uniqueChars.end()) {//doesnt exist
            uniqueChars.insert(s[i]);
        } else
            return false;
    }
    return true;
}


int main() {
    std::string s = "asdfghjklop";
    std::cout << "Unique: " << ((IsUnique(s)==0)? "False" : "True") << std::endl;
}
