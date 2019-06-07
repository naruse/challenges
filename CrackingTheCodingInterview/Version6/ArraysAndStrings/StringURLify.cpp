//Write a method to replace all spaces in a string with %20
// EXAMPLE
// Input: "Mr John Smith " J 13
// Output: "Mr%20J ohn%20Smith"


//Approach:
//since we have the real length, lets have a pointer at the end and
//then we start moving characters to the end and when we encounter a
//space we add %20 and carry on until 0.


#include <iostream>

void URLify(std::string & s, int stringEnd) {
    int endIndex = s.length()-1;
    for(int i = stringEnd-1/*<---!!! -1!!!*/; i >= 0; i--) {
        if(s[i] != ' ') {
            s[endIndex] = s[i];
            endIndex--;
        } else {//we found a space
            s[endIndex] = '0';
            s[endIndex-1] = '2';
            s[endIndex-2] = '%';
            endIndex-=3;
        }
    }
}

int main() {
    std::string s = "O hallo there, how are you          ";
    int realLength = 26;

    std::cout << "Original: '" << s << "'" << std::endl;
    URLify(s, realLength);
    std::cout << "URLified: '" << s << "'" << std::endl;
}
