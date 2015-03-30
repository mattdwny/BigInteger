#include "LongInteger.h"

LongInteger::LongInteger(const string& str)
{
	// Do not change this line until Step 3
    this->list = new DLLProjectList();
	
	int first;
	
	if(str.at(0) == '-')
	{
		first = 1;
		sign = Sign::NEGATIVE;
	}
	else //the string is positive
	{
		first = 0;
		sign = Sign::POSITIVE;
	}
	
	size_t length = str.length() - first;
	
	size_t mod = length % 8;
	
	if(mod == 0) mod = 8;
	
	list.InsertFirst(str.substr(first, mod));
	
	for(size_t cursor = first + mod; i < length + first; cursor += 8)
	{
		list.InsertLast(str.substr(i,8));
	}
}

LongInteger::~LongInteger()
{
    delete this->list;
}

LongInteger* LongInteger::Add(const LongInteger* that) const
{
	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	size_t i = this->list->Size();
	size_t j = that->list->Size();
	
	LongInteger* sum = new DLLProjectList();
	
	int carry = 0;
	
	while(carry || s1 || s2)
	{
		int value = carry;
		if(i)
		{
			value += temp1->GetValue();
			i -= 1;
			if(i) temp1 = this->list->Before(temp1);
		}
		if(j)
		{
			value += temp2->GetValue();
			j -= 1;
			if(j) temp2 = that->list->Before(temp2);
		}
		carry = UtilityOperations.Overflow(value);
		value = UtilityOperations.Underflow(value);
		
		sum->list->InsertFirst(value);
	}
	
	return sum;
}

int LongInteger::DigitCount() const
{

}

bool LongInteger::EqualTo(const LongInteger* i) const
{
	if(this->Size() != i->Size()) return false;
	if(this->Sign() != i->Sign()) return false;
	
	Position* temp1 = this->list->
	Position* temp2 =
}

bool LongInteger::GreaterThan(const LongInteger* i) const
{
	
}

bool LongInteger::LessThan(const LongInteger* i) const
{
	
}

LongInteger* LongInteger::Multiply(const LongInteger* i) const
{
	
}

void LongInteger::Output() const
{
	
}

LongInteger* LongInteger::Power(const int p) const
{

}

bool LongInteger::Sign()
{
	if     (sign == Sign::NEGATIVE) return true;
	else if(sign == Sign::POSITIVE) return false;
	else 							return false;
}

LongInteger* LongInteger::Subtract(const LongInteger* i) const
{

}