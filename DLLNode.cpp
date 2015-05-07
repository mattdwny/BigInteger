#include "DLLNode.h"

DLLNode::DLLNode(int value, DLLNode* next, DLLNode* prev) : Position(value)
{
	m_next = next;
	m_prev = prev;
}

DLLNode::~DLLNode() { }

DLLNode* DLLNode::GetNext() const { return m_next; }
DLLNode* DLLNode::GetPrev() const { return m_prev; }

void DLLNode::SetNext(DLLNode* next) { m_next = next; }
void DLLNode::SetPrev(DLLNode* prev) { m_prev = prev; }
