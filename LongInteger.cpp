#include <stdio.h>
#include <cstddef>
#include <string>
#include <stdlib.h>
#include "LongInteger.h"
#include "UtilityOperations.h"

LongInteger::LongInteger(const string& str)
{
	// Do not change this line until Step 3
    this->list = new DLLProjectList();
	
	int first;
	
	if(str.at(0) == '-')
	{
		first = 1;
		sign = -1;
	}
	else //the string is positive
	{
		first = 0;
		sign = 1;
	}
	
	size_t length = str.length() - first;
	
	size_t mod = length % 8;
	
	if(mod == 0) mod = 8;
	
	list->InsertFirst(atoi(str.substr(first, mod).c_str()));
	
	for(size_t cursor = first + mod; cursor < str.length(); cursor += 8)
	{
		list->InsertLast(atoi(str.substr(cursor,8).c_str()));
	}
}

/*LongInteger::LongInteger(const LongInteger& ref)
{
	LongInteger* clone = new LongInteger();
	
	
	
	return clone;
}*/

LongInteger::~LongInteger()
{
    delete this->list;
}

/*LongInteger* LongInteger::Add(const LongInteger* that) const
{
	//Only works for "+" + "+", but delegating work is a pro strat
	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	size_t i = this->list->Size();
	size_t j = that->list->Size();
	
	LongInteger* sum = new DLLProjectList();
	
	int carry = 0;
	
	while(carry || i || j)
	{
		int value = carry;
		if(i)
		{
			value += temp1->Value();
			i -= 1;
			if(i) temp1 = this->list->Before(temp1);
		}
		if(j)
		{
			value += temp2->Value();
			j -= 1;
			if(j) temp2 = that->list->Before(temp2);
		}
		carry = Overflow(value);
		value = Underflow(value);
		
		sum->list->InsertFirst(value);
	}
	
	return sum;
}*/

void LongInteger::BlockOutput() const
{
	Position* temp = this->list->First();
	
	if(temp) printf("%08d", temp->Value());
	
	while(!this->list->IsLast(temp))
	{
		temp = this->list->After(temp);
		printf(", %08d", temp->Value());
	}
}

size_t LongInteger::DigitCount() const
{
	size_t size = this->list->Size() - 1;
	if(size == -1) size = 0;
	size *= 8; //Logic error: this can overflow
	if(this->list->First() != NULL) size += Digits(this->list->First()->Value());
	return size; 
}

bool LongInteger::EqualTo(const LongInteger* that) const
{
	if(this->list->Size() != that->list->Size()) return false;
	if(this->Sign() != that->Sign()) return false;
	
	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	while(!this->list->IsFirst(temp1))
	{
		if(temp1->Value() != temp2->Value()) return false;
		
		temp1 = this->list->Before(temp1);
		temp2 = that->list->Before(temp2);
	}
	return temp1->Value() == temp2->Value();
}

bool LongInteger::GreaterThan(const LongInteger* that) const
{
	if(this->list->Size() != that->list->Size()) return this->list->Size() > that->list->Size();
	if(this->list->Size() != that->list->Size()) return this->Sign()*this->list->Size() > this->Sign()*that->list->Size();

	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	while(!this->list->IsFirst(temp1))
	{
		if(temp1->Value() != temp2->Value()) return this->Sign()*temp1->Value() > that->Sign()*temp2->Value();
		
		temp1 = this->list->Before(temp1);
		temp2 = that->list->Before(temp2);
	}
	return this->Sign()*temp1->Value() > that->Sign()*temp2->Value();
}

bool LongInteger::LessThan(const LongInteger* that) const
{
	if(this->Sign() != that->Sign()) return this->Sign() < that->Sign();
	if(this->list->Size() != that->list->Size()) return this->Sign()*this->list->Size() < this->Sign()*that->list->Size();
	
	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	while(!this->list->IsFirst(temp1))
	{
		if(temp1->Value() != temp2->Value()) return this->Sign()*temp1->Value() < that->Sign()*temp2->Value();
		
		temp1 = this->list->Before(temp1);
		temp2 = that->list->Before(temp2);
	}
	return this->Sign()*temp1->Value() < that->Sign()*temp2->Value();
}

LongInteger* LongInteger::Multiply(const LongInteger* that) const
{
	
}

void LongInteger::Output() const
{
	if(this->Sign()) printf("-");
	Position* temp = this->list->First();
	
	if(temp) printf("%d", temp->Value());
	else 	 printf("0");
	
	while(!this->list->IsLast(temp))
	{
		temp = this->list->After(temp);
		printf("%08d", temp->Value());
	}
}

LongInteger* LongInteger::Power(const int p) const
{

}

bool LongInteger::Sign() const
{
	return sign == -1;
}

LongInteger* LongInteger::Subtract(const LongInteger* that) const
{

}