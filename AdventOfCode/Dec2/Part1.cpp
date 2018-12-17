/*
To make sure you didn't miss any, you scan the likely candidate boxes
again, counting the number that have an ID containing exactly two of
any letter and then separately counting those with exactly three of
any letter. You can multiply those two counts together to get a
rudimentary checksum and compare it to what your device predicts. 

For example, if you see the following box IDs:

abcdef contains no letters that appear exactly two or three times.
bababc contains two a and three b, so it counts for both.
abbcde contains two b, but no letter appears exactly three times.
abcccd contains three c, but no letter appears exactly two times.
aabcdd contains two a and two d, but it only counts once.
abcdee contains two e.
ababab contains three a and three b, but it only counts once.

Of these box IDs, four of them contain a letter which appears exactly
twice, and three of them contain a letter which appears exactly three
times. Multiplying these together produces a checksum of 4 * 3 = 12. 

What is the checksum for your list of box IDs?

TO COMPILE: g++ -std=c++11 -stdlib=libc++ Part1.cpp -o main
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <tuple>

using namespace::std;

tuple<int, int> ProcessLetters(const string&);

int main(int argc, char* argv[]) {

    string currentLine;
    ifstream myFile("InputP1.txt");

    int a = 0;
    int b = 0;

    if(myFile.is_open()) {
        while(myFile >> currentLine) {
            tuple<int, int> processedValues = ProcessLetters(currentLine);
            a += get<0>(processedValues);
            b += get<1>(processedValues);
        }
        cout << a << " " << b << " => " << (a * b) << endl;
    }
    return 0;
}


tuple<int, int> ProcessLetters(const string &s) {
    int appearsTwice = 0;
    int appearsTrice = 0;

    unordered_map<char,int> values;
    for(int i = 0; i < s.length(); i++) {
        if(values.find(s[i]) == values.end()) {
            //not found
            values[s[i]] = 1;
        } else { //found
            values[s[i]]++;
        }
    }
    for(unordered_map<char,int>::iterator it=values.begin(); it != values.end(); it++) {
        if(it->second == 2)
            appearsTwice = 1;
        if(it->second == 3)
            appearsTrice = 1;
        if(appearsTwice == 1 && appearsTrice == 1)
            break;

    }
    cout << appearsTwice << " " << appearsTrice << endl;
    return make_tuple(appearsTwice, appearsTrice);
}
