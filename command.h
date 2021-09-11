#pragma once
#include "database.h"
#include "condition_parser.h"

#include <string>
#include <sstream>

string ParseEvent(istream&);

class Command {
public:
	virtual void Execute(std::istringstream& is, Database& db, std::ostream&) = 0;
};

class DelCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};

class FindCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};

class AddCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};

class PrintCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};

class LastCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};

class InputHandler {
public:
	bool handleInput(const string& command,
		std::istringstream& is, Database& db, std::ostream&);

private:
	Command* del;
	Command* find;
	Command* add;
	Command* last;
	Command* print;
};
