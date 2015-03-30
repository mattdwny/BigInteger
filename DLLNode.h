#ifndef DLLNODE_H
#define DLLNODE_H

#include "Position.h"

class DLLNode : public Position
{
private:
	DLLNode* m_next;
	DLLNode* m_prev;

public:
	DLLNode(int, DLLNode*, DLLNode*);
	~DLLNode();

	DLLNode* GetNext() const { return m_next; }
	DLLNode* GetPrev() const { return m_prev; }

	void SetNext(const DLLNode* next) { m_next = next; }
	void SetPrev(const DLLNode* prev) { m_prev = prev; }
};

#endif
