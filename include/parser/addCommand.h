#pragma once

#include "command.h"

class AddCommand : public Command {
public:
	void Execute(std::istringstream&, Database&, std::ostream&) override;
};