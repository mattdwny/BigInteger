#include "DLLNode.h"

DLLNode::DLLNode(int value, DLLNode* next, DLLNode* prev) : Position(value)
{
	m_next = next;
	m_prev = prev;
}

DLLNode::~DLLNode() { }

void DLLNode::SetNext(DLLNode* next) { m_next = next; }
void DLLNode::SetPrev(DLLNode* prev) { m_prev = prev; }
	
DLLNode* DLLNode::GetNext() { return m_next; }
DLLNode* DLLNode::GetPrev() { return m_prev; }
