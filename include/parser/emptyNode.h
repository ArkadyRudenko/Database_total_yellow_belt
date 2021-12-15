#pragma once

#include "node.h"

class EmptyNode : public Node {
    bool Evaluate(const Date&, const string&) const override;
};
