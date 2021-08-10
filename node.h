#pragma once
#include<string>
#include "token.h"
#include "Date.h"
using namespace std;
class Node {
public:
    virtual bool Evaluate(const Date&, const string&) const = 0;
};

class EmptyNode : public Node {
    bool Evaluate(const Date&, const string&) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison, const Date&);
    bool Evaluate(const Date&, const string&) const override;
private:
    const Date date_;
	const Comparison cmp_;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison, const string&);
    bool Evaluate(const Date&, const string&) const override;
private:
    const string event_;
    const Comparison cmp_;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(LogicalOperation, shared_ptr<Node>, shared_ptr<Node>);
    bool Evaluate(const Date&, const string&) const override;
private:
    const LogicalOperation lo_;
    const shared_ptr<Node> left_;
    const shared_ptr<Node> right_;
};

template<typename T>
bool СomparisonStringOrEvent(Comparison,const T&, const T&);


