#include "date.h"
#include "condition_parser.h"
#include "node.h"
#include "test_runner.h"
#include "command.h"

#include <iostream>
#include <vector>
#include <stdexcept>
#include "database.h"

#include "unit_tests.h"

using namespace std;

int main() {
    TestAll();

    Database db;

    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        InputHandler ih;
        if (!ih.handleInput(command, is, db, cout)) {
            continue;
        }      
    }

    return 0;
}

