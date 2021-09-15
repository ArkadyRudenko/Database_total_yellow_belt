#pragma once
#include<set>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;
struct Date {
public:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

    void SetYear(int new_year);
    void SetMonth(int new_month);
    void SetDay(int new_day);

    int year;
    int month;
    int day;
};

ostream& operator<<(ostream&, const vector<string>&);
bool operator<(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
bool operator==(const Date&, const Date&);

ostream& operator<<(ostream& , const Date&);

