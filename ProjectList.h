#ifndef PROJECTLIST_H
#define PROJECTLIST_H

#include "Position.h"

class ProjectList
{
public:

	virtual ProjectList() { }
	virtual ~ProjectList() { }

	virtual Position* After(const Position*) = 0;
	virtual Position* Before(const Position*) = 0;

	virtual Position* First() = 0;
	virtual Position* Last() = 0;

	virtual void InsertFirst(int) = 0;
	virtual void InsertLast(int) = 0;

	virtual bool IsEmpty() const = 0;

	virtual bool IsFirst(const Position*) const = 0;
	virtual bool IsLast(const Position*) const = 0;

	virtual std::size_t Size() const = 0;
};


#endif
