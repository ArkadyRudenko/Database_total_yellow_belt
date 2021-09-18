#pragma once

#include "node.h"

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation, shared_ptr<Node>, shared_ptr<Node>);
    bool Evaluate(const Date&, const string&) const override;
private:
    const LogicalOperation lo_;
    const shared_ptr<Node> left_;
    const shared_ptr<Node> right_;
};