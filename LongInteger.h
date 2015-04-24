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

	LongInteger* Add(const LongInteger*) const;
	LongInteger* Subtract(const LongInteger*) const;
	LongInteger* Multiply(const LongInteger*) const;
	LongInteger* Power(const int) const;
	
	LongInteger* Clone() const;

	void BlockOutput() const;
	void Output() const;
	
	size_t DigitCount() const;
	
	bool EqualTo(const LongInteger *) const;
	bool LessThan(const LongInteger*) const;
	bool GreaterThan(const LongInteger*) const;
	
	bool Sign() const;
	
	LongInteger* UnsignedAdd     (LongInteger* S, const LongInteger* A, const LongInteger* B) const;
	LongInteger* UnsignedMultiply(				  const LongInteger* A, const LongInteger* B) const;
	LongInteger* UnsignedSubtract(LongInteger* D, const LongInteger* A, const LongInteger* B) const;

	bool UnsignedGreaterThan(const LongInteger* that) const;
};

#endif // LONGINTEGER_H
