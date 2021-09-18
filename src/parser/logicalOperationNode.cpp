#include "logicalOperationNode.h"

LogicalOperationNode::LogicalOperationNode(
	LogicalOperation lo, shared_ptr<Node> left, shared_ptr<Node> right)
	: lo_(lo), left_(left), right_(right) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	if (lo_ == LogicalOperation::And) {
		return left_->Evaluate(date, event) && right_->Evaluate(date, event);
	}
	else {
		return left_->Evaluate(date, event) || right_->Evaluate(date, event);
	}
}