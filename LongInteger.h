#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <string>
#include "DLLProjectList.h"

using std::string;

class LongInteger
{
private:
	ProjectList* list;
	int sign;

public:
	LongInteger(const string&);
	~LongInteger();

	LongInteger* Add(const LongInteger*) const;
	LongInteger* Subtract(const LongInteger*) const;
	LongInteger* Multiply(const LongInteger*) const;
	LongInteger* Power(const int) const;

	void BlockOutput() const;
	void Output() const;
	
	size_t DigitCount() const;
	
	bool EqualTo(const LongInteger *) const;
	bool LessThan(const LongInteger*) const;
	bool GreaterThan(const LongInteger*) const;
	
	bool Sign() const;
};

#endif // LONGINTEGER_H
