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
	~DLLProjectList();

	Position* After(Position*);
	Position* Before(Position*);

	Position* First();

	void InsertFirst(int);
	void InsertLast(int);

	bool IsEmpty() const;

	bool IsFirst(Position*) const;
	bool IsLast(Position*) const;

	Position* Last();

	size_t Size() const;
};

#endif
