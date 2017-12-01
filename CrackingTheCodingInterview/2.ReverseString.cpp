/*
  Reverse a string
 */

#include <iostream>

using namespace::std;

string test = "holag";

int main(int argc, char* argv[]) {
    char tmp;
    
    cout << "Original string: " << test << endl;
    for(int i = 0; i < test.length()/2; i++) {
        tmp = test[i];
        test[i] = test[test.length()-1-i];
        test[test.length()-1-i] = tmp;
    }
    cout << "Reversed: " << test << endl;
}
