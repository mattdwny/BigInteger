#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
	int mValue;
	
public:
	Position(int value);
	int GetValue() const;
	void SetValue(int value);
};

#endif