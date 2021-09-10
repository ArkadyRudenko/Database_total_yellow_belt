#include "command.h"

string ParseEvent(istream& is) {
	string event;
	is >> ws;
	getline(is, event);
	return event;
}

void DelCommand::Execute(std::istringstream& is, Database& db) {
	auto condition = ParseCondition(is);
	auto predicate = [condition](const Date& date, const string& event) {
		return condition->Evaluate(date, event);
	};
	int count = db.RemoveIf(predicate);
	cout << "Removed " << count << " entries" << endl;
}

void AddCommand::Execute(std::istringstream& is, Database& db) {
	const auto date = ParseDate(is);
	const auto event = ParseEvent(is);
	db.Add(date, event);
}

void FindCommand::Execute(std::istringstream& is, Database& db) {
	auto condition = ParseCondition(is);
	auto predicate = [condition](const Date& date, const string& event) {
		return condition->Evaluate(date, event);
	};

	const auto entries = db.FindIf(predicate);
	for (const auto& entry : entries) {
		cout << entry << endl;
	}
	cout << "Found " << entries.size() << " entries" << endl;
}

void PrintCommand::Execute(std::istringstream& is, Database& db) {
	db.Print(cout);
}

void LastCommand::Execute(std::istringstream& is, Database& db) {
	try {
		cout << db.Last(ParseDate(is)) << endl;
	}
	catch (invalid_argument&) {
		cout << "No entries" << endl;
	}
}

bool InputHandler::handleInput(const string& command,
	std::istringstream& is, Database& db) {
	if (command == "Del") {
		DelCommand dc;
		del = &dc;
		del->Execute(is, db);
	}
	else if (command == "Find") {
		FindCommand fc;
		find = &fc;
		find->Execute(is, db);
	}
	else if (command == "Add") {
		AddCommand ac;
		add = &ac;
		add->Execute(is, db);
	}
	else if (command == "Last") {
		LastCommand lc;
		last = &lc;
		last->Execute(is, db);
	}
	else if (command == "Print") {
		PrintCommand pc;
		print = &pc;
		print->Execute(is, db);
	}
	else if (command.empty()) {
		return false;
	}
	else {
		throw logic_error("Unknown command: " + command);
	}
	return true;
}