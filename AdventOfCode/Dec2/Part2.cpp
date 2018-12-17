/*
  --- Part Two ---
Confident that your list of box IDs is complete, you're ready to find the boxes full of prototype fabric.

The boxes will have IDs which differ by exactly one character at the same position in both strings. For example, given the following box IDs:

abcde
fghij
klmno
pqrst
fguij
axcye
wvxyz
The IDs abcde and axcye are close, but they differ by two characters
(the second and fourth). However, the IDs fghij and fguij differ by
exactly one character, the third (h and u). Those must be the correct
boxes.

What letters are common between the two correct box IDs? (In the example above, this is found by removing the differing character from either ID, producing fgij.)
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace::std;

string CheckBoxCorrectness(const string& id1, const string& id2);

int main(int argc, char* argv[]) {

    string currentLine;
    ifstream myFile("InputP2.txt");

    vector<string> data;

    if(myFile.is_open()) {
        while(myFile >> currentLine) {
            data.push_back(currentLine);
        }
        cout << "Number of boxes: " << data.size() << endl;

        for(int i = 0; i < data.size(); i++) {
            for(int j = i+1; j < data.size(); j++) {
                //cout << "Checking " << data[i] << " vs " << data[j] << endl;
                string correct = CheckBoxCorrectness(data[i], data[j]);
                //string correct = CheckBoxCorrectness("fghij", "fguij");
                if(!correct.empty()) {
                    cout << "ID1: " << data[i] << endl;
                    cout << "ID2: " << data[j] << endl;
                    cout << "CorrectSTR: " << correct << endl << endl;
                    break;
                }
            }
        }
    }
    return 0;
}


//if comparison is not correct then returns an empty string;
string CheckBoxCorrectness(const string& id1, const string& id2){
    //assuming that both strings have the exact same length.
    string correct = id1;
    int differingChars = 0;
    int idx = -1;
    for(int i = 0; i < id1.length(); i++) {
        if(id1[i] != id2[i]) {
            differingChars++;
            idx = i;
            if(differingChars > 1)
                return "";
        }
    }
    if(differingChars != 1)
        correct.clear();
    else {
        correct = correct.erase(idx, 1);
    }
    return correct;
}
