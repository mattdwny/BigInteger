#ifndef ARRAYPROJECTLIST_H
#define ARRAYPROJECTLIST_H

#include "ProjectList.h"
#include "ArrayEntry.h"

class ArrayProjectList : public ProjectList
{

private:
	Position* values;
	size_t maxSize; 
	size_t size;

public:
    ArrayProjectList();
    ~ArrayProjectList();

    Position* After (Position*);
    Position* Before(Position*);
	
	void Double();
	
    void InsertFirst(int);
    void InsertLast (int);

    Position* First();
    Position* Last();

    bool IsFirst(Position*);
    bool IsLast(Position*);

    bool IsEmpty();

	void RemoveFirst();
	
    size_t Size();
};

#endif
