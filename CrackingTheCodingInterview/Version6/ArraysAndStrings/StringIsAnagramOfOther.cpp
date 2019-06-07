//given 2 strings, check if one is a permutation of the other.
//prettymuch check if string s1 is an anagram of s2.

//Approach:

// First of all lets check that both strings have the same size.
// if they both have the same size then with a map<char, int> lets add
// the number of times each char appears and then go through the
// second string and check against the map
//


#include <unordered_map>
#include <iostream>

bool IsAnagram(std::string const & s1, std::string const & s2) {
    if(s1.length() != s2.length())
        return false;

    std::unordered_map<char, int> detectedChars;

    //fill the map.
    for(int i = 0; i < s1.length(); i++) {
        if(detectedChars.find(s1[i]) == detectedChars.end())//doesnt exist
            detectedChars[s1[i]] = 1;
        else
            detectedChars[s1[i]]++;
    }
    //lets check against the map
    for(int i = 0; i < s2.length(); i++) {
        if(detectedChars.find(s2[i]) == detectedChars.end())//doesnt exists in map
            return false;
        else {
            detectedChars[s2[i]]--;
            if(detectedChars[s2[i]] < 0)
                return false;
        }
    }
    return true;
}

int main() {
    std::string s1 = "animal";
    std::string s2 = "lamina";

    std::cout << (IsAnagram(s1, s2) == 0? "False" : "True") << std::endl;
}
