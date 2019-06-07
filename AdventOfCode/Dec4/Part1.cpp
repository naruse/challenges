/*
  --- Day 4: Repose Record ---
You've sneaked into another supply closet - this time, it's across
from the prototype suit manufacturing lab. You need to sneak inside
and fix the issues with the suit, but there's a guard stationed
outside the lab, so this is as close as you can safely get.

As you search the closet for anything that might help, you discover
that you're not the first person to want to sneak in. Covering the
walls, someone has spent an hour starting every midnight for the past
few months secretly observing this guard post! They've been writing
down the ID of the one guard on duty that night - the Elves seem to
have decided that one guard was enough for the overnight shift - as
well as when they fall asleep or wake up while at their post (your
puzzle input).

For example, consider the following records, which have already been
organized into chronological order:

[1518-11-01 00:00] Guard #10 begins shift
[1518-11-01 00:05] falls asleep
[1518-11-01 00:25] wakes up
[1518-11-01 00:30] falls asleep
[1518-11-01 00:55] wakes up
[1518-11-01 23:58] Guard #99 begins shift
[1518-11-02 00:40] falls asleep
[1518-11-02 00:50] wakes up
[1518-11-03 00:05] Guard #10 begins shift
[1518-11-03 00:24] falls asleep
[1518-11-03 00:29] wakes up
[1518-11-04 00:02] Guard #99 begins shift
[1518-11-04 00:36] falls asleep
[1518-11-04 00:46] wakes up
[1518-11-05 00:03] Guard #99 begins shift
[1518-11-05 00:45] falls asleep
[1518-11-05 00:55] wakes up

Timestamps are written using year-month-day hour:minute format. The
guard falling asleep or waking up is always the one whose shift most
recently started. Because all asleep/awake times are during the
midnight hour (00:00 - 00:59), only the minute portion (00 - 59) is
relevant for those events.

Visually, these records show that the guards are asleep at these times:

Date   ID   Minute
            000000000011111111112222222222333333333344444444445555555555
            012345678901234567890123456789012345678901234567890123456789
11-01  #10  .....####################.....#########################.....
11-02  #99  ........................................##########..........
11-03  #10  ........................#####...............................
11-04  #99  ....................................##########..............
11-05  #99  .............................................##########.....

The columns are Date, which shows the month-day portion of the
relevant day; ID, which shows the guard on duty that day;
and Minute, which shows the minutes during which the guard
was asleep within the midnight hour. (The Minute column's
header shows the minute's ten's digit in the first row and
the one's digit in the second row.) Awake is shown as .,
and asleep is shown as #.

Note that guards count as asleep on the minute they fall asleep, and
they count as awake on the minute they wake up. For example, because
Guard #10 wakes up at 00:25 on 1518-11-01, minute 25 is marked as
awake.

If you can figure out the guard most likely to be asleep at a specific
time, you might be able to trick that guard into working tonight so
you can have the best chance of sneaking in. You have two strategies
for choosing the best guard/minute combination.

Strategy 1: Find the guard that has the most minutes asleep. What
minute does that guard spend asleep the most?

In the example above, Guard #10 spent the most minutes asleep, a total
of 50 minutes (20+25+5), while Guard #99 only slept for a total of 30
minutes (10+10+10). Guard #10 was asleep most during minute 24 (on two
days, whereas any other minute the guard was asleep was only seen on
one day).

While this example listed the entries in chronological order, your
entries are in the order you found them. You'll need to organize them
before they can be analyzed.

What is the ID of the guard you chose multiplied by the minute you
chose? (In the above example, the answer would be 10 * 24 = 240.)
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <sstream>
#include <algorithm>
#include <map>

#include "Date.h"

using namespace::std;
//Utils
vector<string> Split(const string& s, char delimiter);
void ltrim(string &s);
void rtrim(string &s);
void trim(string &s);

Date ParseDate(const string &s);
tuple<Date, int> ProcessLine(const string& s);

vector<tuple<Date, int> > statusOfGuards;

bool Compare(const tuple<Date, int>& d1, const tuple<Date, int>& d2);

int main(int argc, char* argv[]) {

    Date d(10,10,10,10,10);
    string currentLine;
    ifstream myFile("Input1.txt");
    if(myFile.is_open()) {
        while(getline(myFile, currentLine)) {
            tuple<Date, int> statusTuple = ProcessLine(currentLine);
            statusOfGuards.push_back(statusTuple);
        }
    }

    sort(statusOfGuards.begin(), statusOfGuards.end(), Compare);

    map<int, tuple<int,int> > maxMinutesSleepingPerGuard;//guardID, <totalMinutesSleep, longestsleep>
    int currentGuardID = -1;

    for(int i = 0; i < statusOfGuards.size(); i++) {
        cout << get<0>(statusOfGuards[i]).ToString() << " --- " << get<1>(statusOfGuards[i]) << endl;
    }

    for(int i = 0; i < statusOfGuards.size(); i++) {

        currentGuardID = get<1>(statusOfGuards[i]);
        //cout << "ID: " << currentGuardID << " i: " << i <<  endl;
        i++;


        if(maxMinutesSleepingPerGuard.find(currentGuardID) == maxMinutesSleepingPerGuard.end())//add GuardIDToDictionary
            maxMinutesSleepingPerGuard[currentGuardID] = make_tuple<int, int>(0, 0);


        int timeSlept = 0;
        int timeWokeUp = 0;
        while(get<1>(statusOfGuards[i]) == -1 || get<1>(statusOfGuards[i]) == -2) {
            if(get<1>(statusOfGuards[i]) == -2) {//guy sleeps
                timeSlept = get<0>(statusOfGuards[i]).minute;
                i++;
            }
            if(get<1>(statusOfGuards[i]) == -1) {//guy wakes up
                timeWokeUp = get<0>(statusOfGuards[i]).minute;
                i++;
            }
            int currentTimeSlept = timeWokeUp - timeSlept;
            int longestSleep = get<1>(maxMinutesSleepingPerGuard[currentGuardID]);


            if(get<1>(maxMinutesSleepingPerGuard[currentGuardID]) < currentTimeSlept) {
                longestSleep = currentTimeSlept;
                
            }

            maxMinutesSleepingPerGuard[currentGuardID] = make_tuple(get<0>(maxMinutesSleepingPerGuard[currentGuardID])+currentTimeSlept, longestSleep);
        }
        i--;
    }

    cout << "Max time each guard sleeps (GuardID => TotalMinutesSlept, longestSleep)" << endl;
    for(map<int, tuple<int, int> >::iterator it = maxMinutesSleepingPerGuard.begin(); it != maxMinutesSleepingPerGuard.end(); ++it)
        cout << it->first << " => " << get<0>(it->second) << ", " << get<1>(it->second) << endl;


    return 0;
}

bool Compare(const tuple<Date, int>& d1, const tuple<Date, int>& d2) {
    if(get<0>(d1).year < get<0>(d2).year)
        return true;
    if(get<0>(d1).year == get<0>(d2).year && get<0>(d1).month < get<0>(d2).month)
        return true;
    if(get<0>(d1).year == get<0>(d2).year && get<0>(d1).month == get<0>(d2).month && get<0>(d1).day < get<0>(d2).day)
        return true;
    if(get<0>(d1).year == get<0>(d2).year && get<0>(d1).month == get<0>(d2).month && get<0>(d1).day == get<0>(d2).day && get<0>(d1).hour < get<0>(d2).hour)
        return true;
    if(get<0>(d1).year == get<0>(d2).year && get<0>(d1).month == get<0>(d2).month && get<0>(d1).day == get<0>(d2).day && get<0>(d1).hour == get<0>(d2).hour && get<0>(d1).minute < get<0>(d2).minute)
        return true;
    return false;
}


tuple<Date, int> ProcessLine(const string& s) {
    vector<string> dateAndStatus = Split(s, ']');
    Date d = ParseDate(dateAndStatus[0]);

    trim(dateAndStatus[1]);
    int status = 0;
    if(dateAndStatus[1].find("Guard") == 0) {
        int guardID = -1;
        vector<string> statusGuard = Split(dateAndStatus[1], '#');
        status = stoi(Split(statusGuard[1], ' ')[0]);
    } else if(dateAndStatus[1].find("wakes") == 0) {
        status = -1;//wake "W";
    } else if(dateAndStatus[1].find("falls") == 0) {
        status = -2;//sleep "S";
    } else {
        cout << "ERROR: Unknown state: " << dateAndStatus[1] << endl;
    }

    return make_tuple(d, status);
}


Date ParseDate(const string &s) {//string in form[YYYY-MM-DD HH:mm]
    string pureDate = s;
    pureDate.erase(0,1);//remove [
    for(int i = 0; i < pureDate.length(); i++) {
        if(pureDate[i] == '-' || pureDate[i] == ':')
            pureDate[i] = ' ';
    }
    vector<string> dateArr = Split(pureDate, ' ');

    return Date(stoi(dateArr[0]), stoi(dateArr[1]), stoi(dateArr[2]), stoi(dateArr[3]), stoi(dateArr[4]));
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
