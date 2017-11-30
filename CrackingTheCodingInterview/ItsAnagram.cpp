/*
  Problem:
  Given 2 strings, write a method to know if one is a permutation of the
  other.

  Approach:
  if we assume the string is in ASCII, we can use an integer array of 256
  chars and mark the used chars and add them.

  Assuming the interviewer mentions the string is in UNICODE, then the max #
  of values can be 1.114112. As of unicode 6.0, only 109.384 values are
  assigned (~10%).

  In this case, then we use a unordered_map to count each occurrence.
 */

#include <iostream>
#include <unordered_map>

using namespace::std;

bool IsAnagram(const string& s1, const string& s2);

int main(int argc, char* argv[]) {
    string s1 = "сайfн";
    string s2 = "санfй";

    cout << s1 << " anagram of " << s2 << "?: " << (IsAnagram(s1, s2)? "yes" : "no") << endl;
}


bool IsAnagram(const string& s1, const string& s2){
    if(s1.length() != s2.length())
        return false;

    unordered_map<char, int> detectedChars;


    for(int i = 0; i < s1.length(); i++) {
        if(detectedChars.find(s1[i]) == detectedChars.end())//doesnt exist in map
            detectedChars[s1[i]] = 1;
        else
            detectedChars[s1[i]]++;
    }

    for(int  i = 0; i < s2.length(); i++) {
        if(detectedChars.find(s2[i]) == detectedChars.end())
            return false;
        else {
            detectedChars[s2[i]]--;
            if(detectedChars[s2[i]] < 0)
                return false;
        }
    }
    return true;
}
