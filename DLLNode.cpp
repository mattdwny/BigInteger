#include "DLLNode.h"

DLLNode::DLLNode(int value, DLLNode * next, DLLNode * prev) : Position(value) {
	this->next = next;
	this->prev = prev;
}
