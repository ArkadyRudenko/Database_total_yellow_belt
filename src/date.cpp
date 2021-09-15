#include <iomanip>
#include "date.h"
using namespace std;

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

void Date::SetYear(int new_year) {
    year = new_year;
}

void Date::SetMonth(int new_month) {
    month = new_month;
}

void Date::SetDay(int new_day) {
    day = new_day;
}

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetDay() < rhs.GetDay();
}

bool operator>(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() > rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() > rhs.GetMonth();
    }
    return lhs.GetDay() > rhs.GetDay();
}

bool operator==(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return 0;
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return 0;
    }
    return lhs.GetDay() == rhs.GetDay();
}

bool operator!=(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return 1;
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return 1;
    }
    return lhs.GetDay() != rhs.GetDay();
}

bool operator>=(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() >= rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() >= rhs.GetMonth();
    }
    return lhs.GetDay() >= rhs.GetDay();
}

bool operator<=(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() <= rhs.GetYear();
    }
    else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() <= rhs.GetMonth();
    }
    return lhs.GetDay() <= rhs.GetDay();
}


ostream& operator<<(ostream& stream, const Date& lhs) {
    stream << setw(4) << setfill('0') << lhs.GetYear() << "-"
        << setw(2) << setfill('0') << lhs.GetMonth() << "-"
        << setw(2) << setfill('0') << lhs.GetDay();
    return stream;
}

ostream& operator<<(ostream& stream, const set<string>& lhs) {
    for (const string& i : lhs) {
        stream << i << endl;
    }
    return stream;
}

ostream& operator<<(ostream& stream, const vector<string>& v) {
    stream << "{ ";
    for (const auto& x : v) {
        stream << "\"" << x << "\"" << ", ";
    }
    stream << " }";
    return stream;
}
