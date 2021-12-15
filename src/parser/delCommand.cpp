#include "delCommand.h"

void DelCommand::Execute(std::istringstream& is, Database& db, std::ostream& out) {
	auto condition = ParseCondition(is);
	auto predicate = [condition](const Date& date, const string& event) {
		return condition->Evaluate(date, event);
	};
	int count = db.RemoveIf(predicate);
	out << "Removed " << count << " entries" << endl;
}
