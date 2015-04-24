#include "Position.h"

Position::Position(int value)
{
	mValue = value;
}

int Position::GetValue() const
{
	return mValue;
}

void Position::SetValue(int value)
{
	mValue = value;
}