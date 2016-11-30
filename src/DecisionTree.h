#ifndef DECISION_TREE_H
#define	DECISION_TREE_H

#include "Sample.h"
#include <iosfwd>
#include <memory>
namespace ID3 {

enum DecisionNodeType {
	DN_ROOT_TYPE,
	DN_INNER_TYPE,
	DN_LEAF_TYPE
};

class DecisionNode {
public:
	typedef std::size_t size_t;

	DecisionNode(DecisionNodeType newType, Attribute newAttr,
				 size_t newValue = 0, size_t newDecision = 0)
		: type(newType), attr(newAttr), attrValue(newValue),
			decision(newDecision) { }
	void print(std::ostream& os) const;
private:
	DecisionNodeType type;
	Attribute attr;
	size_t attrValue;
	size_t decision;	// only used when type is DN_LEAF_TYPE
};

class DecisionTree {
public:
	DecisionTree(const DecisionNode& newNode,
				 struct DecisionTree* newChild = nullptr,
				 struct DecisionTree* newSib = nullptr)
		: node(newNode), firstChild(newChild), nextSibling(newSib) { }

	~DecisionTree()
	{
		delete nextSibling;
		delete firstChild;
	}

	void addChild(DecisionTree* subTree);
	void print(std::ostream& os, std::size_t spaceCnt = 0) const;
private:
	DecisionNode node;
	struct DecisionTree* firstChild;
	struct DecisionTree* nextSibling;
};

inline std::ostream& operator<<(std::ostream& os,
								const DecisionNode& node)
{
	node.print(os);
	return os;
}

double CalcEntropyOf(const Samples& samples,
					 const Attribute& attr,
					 double attrValue);

double CalcConditionalEntropyOf(const Samples& samples,
								const Attribute& attr);

Attribute FindBestAttribute(const Samples& samples,
							const Attributes& attributes);

std::shared_ptr<DecisionTree> GenerateDecisionTree(
									const Samples& samples,
									const Attributes& attributes);
}
#endif // DECISION_TREE_H
