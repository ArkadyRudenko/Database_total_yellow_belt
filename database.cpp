#pragma once
#include "database.h"


void Database::Add(const Date& date, const string& event) {
    if (!storage[date].count(event)) {
        storage[date].insert(event);
        vstorage[date].push_back(event);
    }
}

void Database::Print(ostream& is) const {
    for (const auto& item : vstorage) {
        for (const string& event : item.second) {
            is << item.first << " " << event << endl;
        }
    }
}

vector<string> Database::FindIf(
    function<bool(const Date&, const string&)> predicate) const {
        vector<string> findevents;
        for (const auto& [date, events] : storage) {
            for (const string& event : events) {
                if (predicate(date, event)) {
                    ostringstream os;
                    os << date << " " << event;
                    findevents.push_back(os.str());
                }
            }
        }
    return findevents;
}

int Database::RemoveIf(function<bool(const Date&, const string&)> predicate) {
    map<Date, set<string>> erasevents;
    int count = 0;
    for (const auto& [date, events] : vstorage) {
        for (const string& event : events) {
            if (predicate(date, event)) {
                count++;
                erasevents[date].insert(event);
            }
        }
    }
    for (const auto& [date, events]: erasevents) {
        for (const string& event : events) {
            auto it = remove(vstorage[date].begin(), vstorage[date].end(), event);
            vstorage[date].erase(it, vstorage[date].end());
            storage[date].erase(event);
            if (storage[date].empty()) {
                vstorage.erase(date);
                storage.erase(date);
            }
        }
    }
    return count;
}

string Database::Last(const Date& date) const {
    if(vstorage.empty())
        throw invalid_argument("Empty database");
    auto it = vstorage.upper_bound(date);
    if (it == vstorage.cbegin())
        throw invalid_argument("Empty database");
    else {
        it--;
        ostringstream os;
        os << it->first << " " << *it->second.rbegin();
        return os.str();
    }
}

ostream& operator<<(ostream& stream, const pair<Date, string>& p) {
    stream << p.first <<  " " << p.second << endl;
    return stream;
}