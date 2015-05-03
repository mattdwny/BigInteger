#include "ArrayEntry.h"

ArrayEntry::ArrayEntry(int value, size_t index) : Position(value)
{
	mIndex = index;
}

int ArrayEntry::GetIndex() { return mIndex; }

void ArrayEntry::setIndex(size_t index) { mIndex = index; }