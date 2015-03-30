#ifndef DLLPROJECTLIST_H
#define DLLPROJECTLIST_H

#include "ProjectList.h"
#include "DLLNode.h"

class DLLProjectList : public ProjectList
{
private:
	Position* head;
	Post* tail;
	std::size_t size;

public:
	DLLProjectList();
	~DLLProjectList();

	Position* After(const Position*);
	Position* Before(const Position*);

	Position* First();

	void InsertFirst(int);
	void InsertLast(int);

	bool IsEmpty() const;

	bool IsFirst(const Position*) const;
	bool IsLast(const Position*) const;

	Position* Last();

	std::size_t Size() const;
};

#endif
