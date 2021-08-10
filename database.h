#pragma once
#include "date.h"
#include<map>
#include <iostream>
#include <sstream>
#include<set>
#include<string>
#include<vector>
#include<functional>
#include <algorithm>
using namespace std;

class Database {
public:
    void Add(const Date& date, const string& event);
    void Print(ostream& is) const;
 
    string Last(const Date&) const;
 
    vector<string> FindIf(function<bool(const Date&, const string&)> predicate) const;
    
    int RemoveIf(function<bool(const Date&, const string&)>);
 
 
private:
    map<Date, vector<string>> vstorage;
    map<Date, set<string>> storage;
};

