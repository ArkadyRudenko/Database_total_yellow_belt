#include "lastCommand.h"

void LastCommand::Execute(std::istringstream& is, Database& db, std::ostream& out) {

	try {
		out << db.Last(ParseDate(is)) << endl;
	}
	catch (invalid_argument&) {
		out << "No entries" << endl;
	}
}