#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const  {
	return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date& d) 
    : date_(d), cmp_(cmp){};

bool DateComparisonNode::Evaluate(const Date& date, const string& event)  const {
    return ComparisonStringOrEvent(cmp_, date_, date);
}

EventComparisonNode::EventComparisonNode(Comparison cmp, const string& event)
    : event_(event), cmp_(cmp) {}

bool EventComparisonNode::Evaluate(const Date& data, const string& event) const {
    return ComparisonStringOrEvent(cmp_, event_, event);
}

LogicalOperationNode::LogicalOperationNode(
	LogicalOperation lo, shared_ptr<Node> left, shared_ptr<Node> right) 
    : lo_(lo), left_(left), right_(right) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const{
	if (lo_ == LogicalOperation::And) {
	    return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    } else {
		return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }
}

template<typename T>
bool ComparisonStringOrEvent(Comparison cmp_,const T& lhs,const T& rhs) {
        if (cmp_ == Comparison::Equal) {
		    return lhs == rhs;
	    }
        else if(cmp_ == Comparison::NotEqual){
		    return lhs != rhs;
	    }
        else if(cmp_ == Comparison::NotEqual){
		    return lhs != rhs;
	    }
        else if(cmp_ == Comparison::LessOrEqual){
		    return lhs >= rhs;
	    }
        else if(cmp_ == Comparison::Less){
		    return lhs > rhs;
	    }
        else if(cmp_ == Comparison::GreaterOrEqual){
		    return lhs <= rhs;
	    }
        else if(cmp_ == Comparison::Greater){
		    return lhs < rhs;
	    }
        else {
            throw logic_error("Unknown comparison token");
        }
}