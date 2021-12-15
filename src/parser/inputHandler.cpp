#include "inputHandler.h"
#include "addCommand.h"
#include "delCommand.h"
#include "findCommand.h"
#include "lastCommand.h"
#include "printCommand.h"

bool InputHandler::handleInput(const string& command,
	std::istringstream& is, Database& db, std::ostream& out) {
	if (command == "Del") {
		DelCommand dc;
		del = &dc;
		del->Execute(is, db, out);
	}
	else if (command == "Find") {
		FindCommand fc;
		find = &fc;
		find->Execute(is, db, out);
	}
	else if (command == "Add") {
		AddCommand ac;
		add = &ac;
		add->Execute(is, db, out);
	}
	else if (command == "Last") {
		LastCommand lc;
		last = &lc;
		last->Execute(is, db, out);
	}
	else if (command == "Print") {
		PrintCommand pc;
		print = &pc;
		print->Execute(is, db, out);
	}
	else if (command.empty()) {
		return false;
	}
	else {
		throw logic_error("Unknown command: " + command);
	}
	return true;
}