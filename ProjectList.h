#ifndef PROJECTLIST_H
#define PROJECTLIST_H

#include <cstddef>
#include "Position.h"

class ProjectList
{
public:
	virtual ~ProjectList() { }

	virtual Position* After(Position*) const = 0;
	virtual Position* Before(Position*) const = 0;
	
	virtual Position* First() const = 0;
	virtual Position* Last() const = 0;

	virtual void InsertFirst(int) = 0;
	virtual void InsertLast(int) = 0;

	virtual bool IsEmpty() const = 0;

	virtual bool IsFirst(Position*) const = 0;
	virtual bool IsLast(Position*) const = 0;
	
	virtual void RemoveFirst() = 0;

	virtual size_t Size() const = 0;
};

#endif
