#pragma once

#include "condition_parser.h"
#include "test_runner.h"
#include "command.h"

#include <iostream>
#include <vector>
#include "database.h"

void PasreRequest(istringstream&, Database&, stringstream&);
void TestParseEvent();
void TestAll();
void TestAll();
void TestDel();
void TestFind();
void TestLast();
void TestPrint();

