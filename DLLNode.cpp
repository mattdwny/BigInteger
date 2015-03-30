#include "DLLNode.h"

DLLNode::DLLNode(int value, DLLNode* next, DLLNode* prev) : Position(value)
{
	m_next = next;
	m_prev = prev;
}

DLLNode::~DLLNode()
{

}

void DLLNode::SetNext(const DLLNode* next) { m_next = next; }
void DLLNode::SetPrev(const DLLNode* prev) { m_prev = prev; }
	
DLLNode* DLLNode::GetNext() const { return m_next; }
DLLNode* DLLNode::GetPrev() const { return m_prev; }
