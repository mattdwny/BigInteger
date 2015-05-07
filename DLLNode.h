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

	DLLNode* GetNext() const;
	DLLNode* GetPrev() const;

	void SetNext(DLLNode* next);
	void SetPrev(DLLNode* prev);
};

#endif
