#ifndef ARRAYENTRY_H
#define ARRAYENTRY_H

#include "Position.h"

class ArrayEntry : public Position {

private:
    size_t mIndex;

public:
    ArrayEntry(int, size_t);
	
	int GetIndex();
	void SetIndex(size_t);
};

#endif
