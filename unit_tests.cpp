#include "unit_tests.h"

void PasreRequest(istringstream& test, Database& db, stringstream& out) {
    for (string line; getline(test, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        InputHandler ih;
        if (!ih.handleInput(command, is, db, out)) {
            continue;
        }
    }
}

void TestParseEvent() {
    {
        istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        istringstream is("   sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
    }
    {
        istringstream is("  first event  \n  second event");
        vector<string> events;
        events.push_back(ParseEvent(is));
        events.push_back(ParseEvent(is));
        AssertEqual(events, vector<string>{"first event  ", "second event"}, "Parse multiple events");
    }
}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestParseCondition, "TestParseCondition");
    tr.RunTest(TestDel, "TestDel");
    tr.RunTest(TestFind, "TestFind");
    tr.RunTest(TestLast, "TestLast");
    tr.RunTest(TestPrint, "TestPrint");
}


void TestDel() {
    Database db;
    std::stringstream out;
    string line_test = "Add 2017-06-01 1st of June\nAdd 2017-07-08 8th of July\nAdd 2017-07-08 Someone's birthday\nDel date == 2017-07-08\n Del event == \"1st of June\"";

    istringstream test(line_test);
    PasreRequest(test, db, out);
    
    string expectation = "Removed 2 entries";
    string expectation2 = "Removed 1 entries";
    string real;
    getline(out, real);
    AssertEqual(real, expectation, "[DEL_COMMAND] #1 ");
    real.clear();
    getline(out, real);
    AssertEqual(real, expectation2, "[DEL_COMMAND] #2 ");
}

void TestFind() {
    Database db;

    string line_test = "Add 2017-01-01 Holiday\nAdd 2017-03-08 Holiday\n Add 2017-01-01 New Year\nFind event != \"working day\"\n";

    istringstream test(line_test);
    std::stringstream out;

    PasreRequest(test, db, out);
    string exp1 = "2017-01-01 Holiday";
    string exp2 = "2017-01-01 New Year";
    string exp3 = "2017-03-08 Holiday";
    string exp4 = "Found 3 entries";
    vector<string> test_exp = {
        exp1, exp2, exp3, exp4
    };
    int i = 0;
    for (string real; getline(out, real); i++) {
        AssertEqual(real, test_exp[i], "[FIND_COMMAND]");
    }
}

void TestLast() {
    Database db;

    string line_test = "Add 2017-01-01 New Year\nAdd 2017-03-08 Holiday\nAdd 2017-01-01 Holiday\nLast 2016-12-31\nLast 2017-01-01\nLast 2017-06-01\n";

    istringstream test(line_test);
    std::stringstream out;

    PasreRequest(test, db, out);
    string exp1 = "No entries";
    string exp2 = "2017-01-01 Holiday";
    string exp3 = "2017-03-08 Holiday";
    vector<string> test_exp = {
        exp1, exp2, exp3
    };
    int i = 0;
    for (string real; getline(out, real); i++) {
        AssertEqual(real, test_exp[i], "[LAST_COMMAND]");
    }
}

void TestPrint() {
    Database db;

    string line_test = "Add 2017-01-01 Holiday\nAdd 2017-03-08 Holiday\nAdd 2017-1-1 New Year\nAdd 2017-1-1 New Year\nPrint\n";

    istringstream test(line_test);
    std::stringstream out;

    PasreRequest(test, db, out);

    string exp1 = "2017-01-01 Holiday";
    string exp2 = "2017-01-01 New Year";
    string exp3 = "2017-03-08 Holiday";
    vector<string> test_exp = {
        exp1, exp2, exp3
    };
    int i = 0;
    for (string real; getline(out, real); i++) {
        AssertEqual(real, test_exp[i], "[PRINT_COMMAND]");
    }
}