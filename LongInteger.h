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
		
	void StripZeros();
	LongInteger* UnsignedArithmetic(LongInteger* C, const LongInteger* A, const LongInteger* B, bool add) const;
public:
	LongInteger();
	LongInteger(const string&);
	~LongInteger();

	LongInteger* Add     (const LongInteger* const) const;
	LongInteger* Subtract(const LongInteger* const) const;
	LongInteger* Multiply(const LongInteger* const) const;
	LongInteger* Power(const int) const;
	
	LongInteger* Clone() const;

	void BlockOutput() const;
	void Output() const;
	
	size_t DigitCount() const;
	
	bool EqualTo    (const LongInteger* const) const;
	bool LessThan   (const LongInteger* const) const;
	bool GreaterThan(const LongInteger* const) const;
	
	bool Sign() const;
	
	LongInteger* UnsignedAdd     (LongInteger* const, const LongInteger* const, const LongInteger* const) const;
	LongInteger* UnsignedMultiply(LongInteger* const, const LongInteger* const, const LongInteger* const) const;
	LongInteger* UnsignedSubtract(LongInteger* const, const LongInteger* const, const LongInteger* const) const;
	
	LongInteger* UnsignedAggregate(LongInteger* const, const LongInteger* const) const;
	
	bool UnsignedGreaterThan(const LongInteger* const that) const;
};

#endif // LONGINTEGER_H
