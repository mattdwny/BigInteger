#include <stdio.h>
#include <cstddef>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "LongInteger.h"
#include "UtilityOperations.h"

LongInteger::LongInteger()
{
	this->list = new DLLProjectList();
}

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
	
	int i = (str.length()-first - 1) / 8;
	
	for(size_t cursor = str.length() - 8; --i >= 0; cursor -= 8)
	{
		printf("%i >= %i + %i\n", cursor,first,mod);
		list->InsertFirst(atoi(str.substr(cursor,8).c_str()));
	}
	
	list->InsertFirst(atoi(str.substr(first, mod).c_str()));
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

LongInteger* LongInteger::Add(const LongInteger* const that) const
{
	LongInteger* const sum = new LongInteger();
	
	if(this->sign == that->sign)
	{
		sum->sign = this->sign;
		UnsignedAdd(sum, this, that);
	}
	else
	{
		if(this->UnsignedGreaterThan(that))
		{
			sum->sign = this->sign;
			UnsignedSubtract(sum, this, that);
		}
		else
		{
			sum->sign = that->sign;
			UnsignedSubtract(sum, that, this);
		}
	}
	
	return sum;
}

void LongInteger::BlockOutput() const
{
	Position* temp = this->list->First();
	
	if(temp) printf("%08d", temp->GetValue());
	
	while(!this->list->IsLast(temp))
	{
		temp = this->list->After(temp);
		printf(", %08d", temp->GetValue());
	}
}

LongInteger* LongInteger::Clone() const
{
	LongInteger* clone = new LongInteger();
	
	clone->list = this->list->Clone();
	clone->sign = this->sign;
	
	return clone;
}

size_t LongInteger::DigitCount() const
{
	size_t size = this->list->Size() - 1;
	if(size == -1) size = 0;
	size *= 8; //Logic error: this can overflow
	if(this->list->First() != NULL) size += Digits(this->list->First()->GetValue());
	return size; 
}

bool LongInteger::EqualTo(const LongInteger* const that) const
{
	if(this->list->Size() != that->list->Size()) return false;
	if(this->sign != that->sign) return false;
	
	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	while(!this->list->IsFirst(temp1))
	{
		if(temp1->GetValue() != temp2->GetValue()) return false;
		
		temp1 = this->list->Before(temp1);
		temp2 = that->list->Before(temp2);
	}
	return temp1->GetValue() == temp2->GetValue();
}

bool LongInteger::GreaterThan(const LongInteger* const that) const
{
	if(this->sign != that->sign) return this->sign > that->sign;
	if(this->list->Size() != that->list->Size()) return this->sign*this->list->Size() > that->sign*that->list->Size();

	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	while(!this->list->IsFirst(temp1))
	{
		if(temp1->GetValue() != temp2->GetValue()) return this->sign*temp1->GetValue() > that->sign*temp2->GetValue();
		
		temp1 = this->list->Before(temp1);
		temp2 = that->list->Before(temp2);
	}
	return this->sign*temp1->GetValue() > that->sign*temp2->GetValue();
}

bool LongInteger::LessThan(const LongInteger* const that) const
{
	if(this->sign != that->sign) return this->sign < that->sign;
	if(this->list->Size() != that->list->Size()) return this->sign*this->list->Size() < that->sign*that->list->Size();
	
	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	while(!this->list->IsFirst(temp1))
	{
		if(temp1->GetValue() != temp2->GetValue()) return this->sign*temp1->GetValue() < that->sign*temp2->GetValue();
		
		temp1 = this->list->Before(temp1);
		temp2 = that->list->Before(temp2);
	}
	return this->sign*temp1->GetValue() < that->sign*temp2->GetValue();
}

LongInteger* LongInteger::Multiply(const LongInteger* const that) const
{
	if(this->sign == 0 || that->sign == 0) return new LongInteger();
	
	LongInteger* const product = new LongInteger();
	
	if(this->UnsignedGreaterThan(that)) UnsignedMultiply(product, this, that);
	else 								UnsignedMultiply(product, that, this);
	
	product->sign = this->sign*that->sign;
	product->StripZeros();
	
	return product;
}

void LongInteger::Output() const
{
	if(this->Sign()) printf("-");
	Position* temp = this->list->First();
	
	if(temp) printf("%d", temp->GetValue());
	else 	 printf("0");
	
	while(!this->list->IsLast(temp))
	{
		temp = this->list->After(temp);
		printf("%08d", temp->GetValue());
	}
}

LongInteger* LongInteger::Power(const int p) const
{

}

bool LongInteger::Sign() const
{
	return sign == -1;
}

void LongInteger::StripZeros()
{
	while(!list->IsEmpty())
	{
		if(list->First()->GetValue() == 0) list->RemoveFirst();
		else break;
	}
	
	if(list->IsEmpty()) sign = 0;	
}

LongInteger* LongInteger::Subtract(const LongInteger* const that) const
{
	LongInteger* difference;
	
	if (that->sign == 0) return this->Clone();
	
	if (this->sign == 0)
	{
		difference = that->Clone();
		difference->sign *= -1;
		return difference;
	}
	
	difference = new LongInteger();
	
	if(this->sign == that->sign)
	{
		if(this->UnsignedGreaterThan(that))
		{
			difference->sign = this->sign;
			UnsignedSubtract(difference, this, that);
		}
		else
		{
			difference->sign = -that->sign;
			UnsignedSubtract(difference, that, this);
		}
	}
	else
	{
		difference->sign = this->sign;
		UnsignedAdd(difference, this, that);
	}
	
	return difference;
}

/**
 *	@param C: the pointer to an initialized sum LongInteger
 *	@param A: the pointer to the larger LongInteger
 *	@param B: the pointer to the smaller LongInteger (can be equal to A) 
 */
LongInteger* LongInteger::UnsignedAdd(LongInteger* const C, const LongInteger* const A, const LongInteger* const B) const
{	
	return UnsignedArithmetic(C,A,B,true);
}

/**
 *	@param C: the pointer to an initialized LongInteger that will store the result
 *	@param A: the pointer to the larger LongInteger (for subtraction)
 *	@param B: the pointer to the smaller LongInteger (can be equal to A)
 * 	@param add: true if the function should add, false if the program should subtract 
 */
LongInteger* LongInteger::UnsignedArithmetic(LongInteger* const C, const LongInteger* const A, const LongInteger* const B, bool add) const
{
	Position* a = A->list->Last();
	Position* b = B->list->Last();
	Position* c = C->list->Last();
	
	size_t i = A->list->Size();
	size_t j = B->list->Size();
	size_t k = C->list->Size();
	
	int carry = 0;
	while(carry || i || j)
	{
		int value = carry;
		
		if(i)
		{
			value += a->GetValue();
			if(--i) a = A->list->Before(a);
		}
		if(j)
		{
			if(add) value += b->GetValue();
			else 	value -= b->GetValue();
			if(--j) b = B->list->Before(b);
		}
		
		carry = Overflow(value);
		value = Underflow(value);
		
		if(k)
		{
			c->SetValue(value);
			if(--k) c = C->list->Before(c);
		}
		else
		{
			C->list->InsertFirst(value);
		}
	}
	
	return C;
}

bool LongInteger::UnsignedGreaterThan(const LongInteger* const that) const
{
	if(this->list->Size() != that->list->Size()) return this->list->Size() > that->list->Size();

	Position* temp1 = this->list->Last();
	Position* temp2 = that->list->Last();
	
	while(!this->list->IsFirst(temp1))
	{
		if(temp1->GetValue() != temp2->GetValue()) return temp1->GetValue() > temp2->GetValue();
		
		temp1 = this->list->Before(temp1);
		temp2 = that->list->Before(temp2);
	}
	return temp1->GetValue() > temp2->GetValue();
}

LongInteger* LongInteger::UnsignedMultiply(LongInteger* const C, const LongInteger* const A, const LongInteger* const B) const
{	
	Position* a = A->list->Last();
	
	int zeroPadding = 0;
	int i = A->list->Size();
	while(i > 0)
	{
		Position* b = B->list->Last();
		LongInteger* temp = new LongInteger();
		
		for (int z = 0; z < zeroPadding; ++z) temp->list->InsertFirst(0);
		temp->list->InsertFirst(0);

		int a1 = UpperHalf(a->GetValue());
		int a2 = LowerHalf(a->GetValue());
		
		int carry = 0;
		int j = B->list->Size();
		while(j > 0)
		{			
			int b1 = UpperHalf(b->GetValue());
			int b2 = LowerHalf(b->GetValue());
			
			int z1 = a1 * b1;
			int z3 = a2 * b2;
			int z2 = (a1 + a2) * (b1 + b2) - z1 - z3;
			
			int v1 = z1 + UpperHalf(z2);
			int v2 = z3 + (LowerHalf(z2) * 10000 ) + carry;
			
			carry = Overflow (v2);
			v2    = Underflow(v2);
			
			temp->list->First()->SetValue(v2 + temp->list->First()->GetValue());
			temp->list->InsertFirst(v1);
			
			if(--j) b = B->list->Before(b);
		}
		if(carry) temp->list->First()->SetValue(temp->list->First()->GetValue() + carry);
		
		UnsignedAggregate(C, temp);
		
		delete temp;
		
		++zeroPadding;
		
		if(--i) a = A->list->Before(a);
	}
	
	return C;
}

LongInteger* LongInteger::UnsignedAggregate(LongInteger* const A, const LongInteger* const B) const
{
	return UnsignedArithmetic(A, A, B, true);
}

/**
 *	@param C: the pointer to an initialized difference LongInteger
 *	@param A: the pointer to the larger LongInteger
 *	@param B: the pointer to the smaller LongInteger (can be equal to A) 
 */
LongInteger* LongInteger::UnsignedSubtract(LongInteger* const C, const LongInteger* const A, const LongInteger* const B) const
{
	UnsignedArithmetic(C,A,B,false);
	C->StripZeros();
	return C;
}