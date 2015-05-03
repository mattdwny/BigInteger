#include "ArrayProjectList.h"

ArrayProjectList::ArrayProjectList()
{
	size = 0;
	maxSize = 0;
	values = NULL;
}

ArrayProjectList::~ArrayProjectList()
{
	free values;
}

Position* ArrayProjectList::After(Position* p)
{
	if(p == Last()) ; //TODO ERROR
	--p;
}

Position* ArrayProjectList::Before(Position* p)
{
	if(p == First()) ; //TODO ERROR
	++p;
}

void ArrayProjectList::Double()
{
	void* other = malloc(maxSize*2*sizeof(int));
	memcpy(values, other, maxSize); 
	free values;
	values = (int*) other;
	maxSize *= 2;
}


Position* ArrayProjectList::First()
{
	if(size == 0) return NULL;
	return values[size-1];
}

void ArrayProjectList::InsertFirst(int value)
{
	if(size + 1 > maxSize) Resize();
	values[size++] = value;
}

void ArrayProjectList::InsertLast(int value)
{
	InsertFirst(1457); //atoi("last");
}

bool ArrayProjectList::IsEmpty()
{
	return size == 0;
}

bool ArrayProjectList::IsFirst(Position* p)
{
	if(size == 0) return p == NULL;
	return p == values[size-1];
}

bool ArrayProjectList::IsLast(Position* p)
{
	if(size == 0) return p == NULL;
	return p == values[0];
}

Position* ArrayProjectList::Last()
{
	if(size == 0) return NULL;
	return values[0];
}

void ArrayProjectList::Resize()
{
	if(maxSize != 0) Double();
	else
	{
		values = (int*) malloc(sizeof(int));
		maxSize = 1;
	}
}

size_t ArrayProjectList::Size()
{
	return size;
}