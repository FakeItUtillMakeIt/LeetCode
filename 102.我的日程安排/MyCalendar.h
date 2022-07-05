#pragma once

#ifndef MY_CALENDAR_H
#define MY_CALENDAR_H

#include <vector>

using namespace std;

class MyCalendar {
public:
    vector<vector<int>> zoneCalendar;

    MyCalendar() {

    }

    bool book(int start, int end) {
        if (zoneCalendar.empty())
        {
            zoneCalendar.push_back({ start,end });
            return true;
        }
        for (int i=0;i<zoneCalendar.size();i++)
        {
        }
    }
};

class Solution {

public:
    Solution() {
        MyCalendar* obj = new MyCalendar();
        bool param_1 = obj->book(15, 20);
    }

};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


#endif
