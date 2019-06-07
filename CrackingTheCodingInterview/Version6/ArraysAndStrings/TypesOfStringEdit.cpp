//One Away: There are three types of edits that can be performed on
//strings: insert a character, remove a character, or replace a
//character. Given two strings, write a function to check if they are
//one edit (or zero edits) away.

//EXAMPLE
//pale, pIe   -> true
//pales, pale -> true
//pale, bale  -> true
//pale, bake  -> false


//APPROACH:
//there are 2 options:
//1. the string lengths differ by one character and
//are the same (except by one char).
//OR
// 2. The string lengths are the same except for one char.
// so we go through the string and check for that.

#include <iostream>

bool OneStringEdit(std::string const & s1, std::string const & s2) {
    std::string largestStr;
    std::string smallerStr;
    if(s1.length() > s2.length()) {
        largestStr = s1;
        smallerStr = s2;
    } else {//happens if s1 == s2 in length
        largestStr = s2;
        smallerStr = s1;
    }

    if(!(largestStr.length() == smallerStr.length()+1 || //strings differ in 1 char
         largestStr.length() == smallerStr.length())) {//strings have the same size
        return false;
    }

    bool oneEdit = false;
    int offset = 0;
    for(int i = 0; i < smallerStr.length(); i++) {
        if(smallerStr[i] != largestStr[i+offset]) {
            if(oneEdit) {//we have already done an edit.
                return false;
            } else {
                oneEdit = true;
                if(smallerStr.length() != largestStr.length())
                    offset = 1;
            }
        }
    }
    if(smallerStr.length() == largestStr.length())
        if(oneEdit)
            return true;
        else
            return false;
    else
        return true;
}

int main() {
    std::string s1 = "pales";
    std::string s2 = "pale";

    std::cout << "S1: " << s1 << "\nS2: " << s2 << "\nOne edit: " << (OneStringEdit(s1, s2)==0? "false" : "true") << std::endl;

}
