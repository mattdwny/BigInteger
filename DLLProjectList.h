#ifndef DLLPROJECTLIST_H
#define DLLPROJECTLIST_H

#include <cstddef>
#include "ProjectList.h"
#include "DLLNode.h"

class DLLProjectList : public ProjectList
{
private:
	DLLNode* head;
	DLLNode* tail;
	size_t size;

	void ClipZeros();
	
public:
	DLLProjectList();
	DLLProjectList(const DLLProjectList* const);
	~DLLProjectList();

	Position* After (Position*) const;
	Position* Before(Position*) const;
	
	Position* First() const;
	Position* Last() const;
	
	DLLNode* GetHead() const { return head; }
	DLLNode* GetTail() const { return tail; }
	
	size_t GetSize() const { return size; }

	void InsertFirst(int);
	void InsertLast(int);

	bool IsEmpty() const;

	bool IsFirst(Position*) const;
	bool IsLast(Position*) const;
	
	void RemoveFirst();

	size_t Size() const;
};

#endif
