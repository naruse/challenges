/*
  --- Part Two ---

Amidst the chaos, you notice that exactly one claim doesn't overlap by
even a single square inch of fabric with any other claim. If you can
somehow draw attention to it, maybe the Elves will be able to make
Santa's suit after all!

For example, in the claims above, only claim 3 is intact after all claims are made.

What is the ID of the only claim that doesn't overlap?

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <sstream>

//lo mejor es hacerlo con int[][] en vez de tratar de smart it oout.

using namespace::std;
//Utils
vector<string> Split(const string& s, char delimiter);
void ltrim(string &s);
void rtrim(string &s);
void trim(string &s);

tuple<int, int, int, int, int> ParseLineAndGenerateCoords(const string& s);
void MarkFabric(int x, int y, int width, int height, int idOfMarker);
void PrintFabric();


const int fabricWidth = 1000;
const int fabricHeight = 1000;
tuple<int, int> fabric[fabricWidth][fabricHeight];//id and number of cuts

bool overlappedIDs[1412];


int main(int argc, char* argv[]) {

    string currentLine;
    ifstream myFile("Input2.txt");
    if(myFile.is_open()) {
        while(getline(myFile, currentLine)) {
            tuple<int, int, int, int, int> dataToWriteToFabric = ParseLineAndGenerateCoords(currentLine);
            MarkFabric(get<0>(dataToWriteToFabric), get<1>(dataToWriteToFabric), get<2>(dataToWriteToFabric), get<3>(dataToWriteToFabric), get<4>(dataToWriteToFabric));
        }
    }

    int counter = 0;
    for(int i = 0; i < fabricWidth; i++) {
        for(int j = 0; j < fabricHeight; j++) {
            if(get<0>(fabric[i][j]) > 1)
                counter++;
        }
    }


    for(int i = 1; i < 1412; i++)//start from 1 as input id starts from 1
        if(overlappedIDs[i] == false) {
            cout << "Not overlapped: " << i << endl;
        }

    return 0;
}

//marks the fabric matrix
void MarkFabric(int x, int y, int width,int height, int _idOfMarker) {
    for(int i = x; i < x+width; i++)
        for(int j = y; j < y+height; j++) {
            int idPosIJ = get<0>(fabric[i][j]);
            if(idPosIJ != 0) {
                overlappedIDs[_idOfMarker] = true;
                overlappedIDs[get<0>(fabric[i][j])] = true;
                //cout << "Overlapped ID" << endl;
            }

            fabric[i][j] = make_tuple(_idOfMarker, get<1>(fabric[i][j]) + 1);//no make_tuple<int, int>(..) because its an rvalue (std::move()<- "its a cast to rvalues)
            // cout << "Marked with ID: " << _idOfMarker << " --?--> " << get<0>(fabric[i][j]) << endl;
        }
}



tuple<int, int, int, int, int> ParseLineAndGenerateCoords(const string& s) {
    string id = Split(s, '@')[0].erase(0,1);
    string valueStr = Split(s, '@')[1];
    vector<string> dataStr = Split(valueStr, ':');

    vector<string> coordsStr = Split(dataStr[0], ',');
    vector<string> cutSizeStr = Split(dataStr[1], 'x');

    return make_tuple<int, int, int, int, int>(stoi(coordsStr[0]), stoi(coordsStr[1]), stoi(cutSizeStr[0]), stoi(cutSizeStr[1]), stoi(id));
}

void PrintFabric() {
    cout << "Fabric:" << endl;
    for(int i = 0; i < fabricWidth; i++) {
        for(int j = 0; j < fabricHeight; j++) {
            cout << get<0>(fabric[i][j]) << " ";
        }
        cout << endl;
    }
}


// UTILS
void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) { return !isspace(ch); }));
}
void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) { return !isspace(ch);}).base(), s.end());
}
void trim(string &s) {
    ltrim(s); rtrim(s);
}
vector<string> Split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delimiter))
        tokens.push_back(token);
    return tokens;
}

