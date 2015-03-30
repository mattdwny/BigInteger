#include "Position.h"

Position::Position(int value)
{
	m_value = value;
}

int Position::GetValue() const
{
	return m_value;
}

void Position::SetValue(int value)
{
	m_value = value;
}