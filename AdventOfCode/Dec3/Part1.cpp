/*
--- Day 3: No Matter How You Slice It ---
The Elves managed to locate the chimney-squeeze prototype fabric for
Santa's suit (thanks to someone who helpfully wrote its box IDs on the
wall of the warehouse in the middle of the night). Unfortunately,
anomalies are still affecting them - nobody can even agree on how to
cut the fabric.

The whole piece of fabric they're working on is a very large square - at least 1000 inches on each side.

Each Elf has made a claim about which area of fabric would be ideal
for Santa's suit. All claims have an ID and consist of a single
rectangle with edges parallel to the edges of the fabric. Each claim's
rectangle is defined as follows:

The number of inches between the left edge of the fabric and the left edge of the rectangle.
The number of inches between the top edge of the fabric and the top edge of the rectangle.
The width of the rectangle in inches.
The height of the rectangle in inches.
A claim like #123 @ 3,2: 5x4 means that claim ID 123 specifies a
rectangle 3 inches from the left edge, 2 inches from the top edge, 5
inches wide, and 4 inches tall. Visually, it claims the square inches
of fabric represented by # (and ignores the square inches of fabric
represented by .) in the diagram below:
...........
...........
...#####...
...#####...
...#####...
...#####...
...........
...........
...........
The problem is that many of the claims overlap, causing two or more claims to cover part of the same areas. For example, consider the following claims:
#1 @ 1,3: 4x4
#2 @ 3,1: 4x4
#3 @ 5,5: 2x2
Visually, these claim the following areas:
........
...2222.
...2222.
.11XX22.
.11XX22.
.111133.
.111133.
........
The four square inches marked with X are claimed by both 1 and 2. (Claim 3, while adjacent to the others, does not overlap either of them.)

If the Elves all proceed with their own plans, none of them will have enough fabric. How many square inches of fabric are within two or more claims?
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

tuple<int, int, int, int> ParseLineAndGenerateCoords(const string& s);
void MarkFabric(int x, int y, int width, int height);
void PrintFabric();


const int fabricWidth = 10;
const int fabricHeight = 10;
int fabric[fabricWidth][fabricHeight];

int main(int argc, char* argv[]) {

    string currentLine;
    ifstream myFile("InputP1.txt");
    /*  if(myFile.is_open()) {
        while(getline(myFile, currentLine)) {
            tuple<int, int, int, int> dataToWriteToFabric = ParseLineAndGenerateCoords(currentLine);
            MarkFabric(get<0>(dataToWriteToFabric), get<1>(dataToWriteToFabric), get<2>(dataToWriteToFabric), get<3>(dataToWriteToFabric));
        }
        }
*/
    tuple<int, int, int, int> dataToWriteToFabric = ParseLineAndGenerateCoords("#1 @ 1,3: 4x4");
    MarkFabric(get<0>(dataToWriteToFabric), get<1>(dataToWriteToFabric), get<2>(dataToWriteToFabric), get<3>(dataToWriteToFabric));
    dataToWriteToFabric = ParseLineAndGenerateCoords("#2 @ 3,1: 4x4");
    MarkFabric(get<0>(dataToWriteToFabric), get<1>(dataToWriteToFabric), get<2>(dataToWriteToFabric), get<3>(dataToWriteToFabric));
    dataToWriteToFabric = ParseLineAndGenerateCoords("#3 @ 5,5: 2x2");
    MarkFabric(get<0>(dataToWriteToFabric), get<1>(dataToWriteToFabric), get<2>(dataToWriteToFabric), get<3>(dataToWriteToFabric));
    PrintFabric();

    int counter = 0;
    for(int i = 0; i < fabricWidth; i++) {
        for(int j = 0; j < fabricHeight; j++) {
            if(fabric[i][j] > 1)
                counter++;
        }
    }

    cout << "Overlaped: " << counter << endl;
    return 0;
}

//marks the fabric matrix
void MarkFabric(int x, int y, int width,int height) {
    for(int i = x; i < x+width; i++)
        for(int j = y; j < y+height; j++) {
            fabric[i][j] = fabric[i][j] + 1;
        }
}



tuple<int, int, int, int> ParseLineAndGenerateCoords(const string& s) {
    string valueStr = Split(s, '@')[1];
    vector<string> dataStr = Split(valueStr, ':');

    vector<string> coordsStr = Split(dataStr[0], ',');
    vector<string> cutSizeStr = Split(dataStr[1], 'x');

    return make_tuple<int, int, int, int>(stoi(coordsStr[0]), stoi(coordsStr[1]), stoi(cutSizeStr[0]), stoi(cutSizeStr[1]));
}

void PrintFabric() {
    cout << "Fabric:" << endl;
    for(int i = 0; i < fabricWidth; i++) {
        for(int j = 0; j < fabricHeight; j++) {
            cout << fabric[i][j] << " ";
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

