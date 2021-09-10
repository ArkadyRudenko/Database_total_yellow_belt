#pragma once
#include "database.h"
#include "condition_parser.h"

#include <string>
#include <sstream>

string ParseEvent(istream&);

class Command {
public:
	virtual void Execute(std::istringstream& is, Database& db) = 0;
};

class DelCommand : public Command {
public:
	void Execute(std::istringstream&, Database&) override;
};

class FindCommand : public Command {
public:
	void Execute(std::istringstream&, Database&) override;
};

class AddCommand : public Command {
public:
	void Execute(std::istringstream&, Database&) override;
};

class PrintCommand : public Command {
public:
	void Execute(std::istringstream&, Database&) override;
};

class LastCommand : public Command {
public:
	void Execute(std::istringstream&, Database&) override;
};

class InputHandler {
public:
	bool handleInput(const string& command,
		std::istringstream& is, Database& db);

private:
	Command* del;
	Command* find;
	Command* add;
	Command* last;
	Command* print;
};
