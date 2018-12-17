#pragma once

using namespace::std;

class Date {
 public:
    int year;
    int month;
    int day;
    int hour;
    int minute;
 Date(int yr, int mth, int dy, int hr, int mn) :
    year(yr), month(mth), day(dy), hour(hr), minute(mn) {}

    string ToString() {
        return to_string(year) + " " + to_string(month) + " " + to_string(day) + " " + to_string(hour) + " " + to_string(minute);
    }
};
