#include "findCommand.h"

void FindCommand::Execute(std::istringstream& is, Database& db, std::ostream& out) {
	auto condition = ParseCondition(is);
	auto predicate = [condition](const Date& date, const string& event) {
		return condition->Evaluate(date, event);

	};

	const auto entries = db.FindIf(predicate);
	for (const auto& entry : entries) {
		out << entry << endl;
	}
	out << "Found " << entries.size() << " entries" << endl;
}