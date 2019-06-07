//Given a string, write a function to check if it is a permutation of
//a palindrome. A palindrome is a word or phrase that is the same
//forwards and backwards. A permutation is a rearrangement of
//letters.The palindrome does not need to be limited to just
//dictionary words.

//EXAMPLE:
//Input: Tact Coa
//Output: True (permutations: "taco cat". "atco cta". etc.)

//Approach
//A couple of things to notice:
//Spaces dont matter as far as we have even number of letters and at MOST 1
//odd number of letters
// So we go through the string and count the number of letters
//appearances and then go through the dict and check if it has all the
//values even and at most 1 odd.


#include <iostream>
#include <unordered_map>


bool CheckIfPermutationOfPalindrome(std::string const& s) {
    std::unordered_map<char, int> detectedChars;
    //fill the map
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ')//we dont care about spaces
            continue;

        if(detectedChars.find(s[i]) == detectedChars.end()) {//doesnt exist
            detectedChars[s[i]] = 1;
        } else {
            detectedChars[s[i]]++;
        }
    }

    //now lets iterate through the map and check
    bool oddDetected = false;
    for(auto const& it : detectedChars) {
        if(it.second % 2 != 0) {//we found an odd value
            if(!oddDetected) {
                oddDetected = true;
            } else {
                return false;//we have more than one off value
            }
        }
    }
    return true;
}




int main() {
    std::string s = "aabd bcc   cb  baaaadaa";
    std::cout << "S: " << s << " Permutation: " << (CheckIfPermutationOfPalindrome(s)==0 ? "False" : "true") << std::endl;

    
}
