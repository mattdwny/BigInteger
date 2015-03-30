#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <String>
#include "DLLProjectList.h"

using std::string;

class LongInteger
{
private:
	ProjectList* list;
	enum Sign {NEGATIVE = 1, ZERO = 2, POSITIVE = 3};
	Sign sign;

public:
	LongInteger(const string&);
	~LongInteger();

	LongInteger* Add(const LongInteger*) const;
	LongInteger* Subtract(const LongInteger*) const;
	LongInteger* Multiply(const LongInteger*) const;
	LongInteger* Power(const int pow) const;

	int DigitCount() const;
	
	bool EqualTo(const LongInteger *) const;
	bool LessThan(const LongInteger*) const;
	bool GreaterThan(const LongInteger*) const;

	void Output() const;
	
	Sign Sign() const;
};

#endif // LONGINTEGER_H
