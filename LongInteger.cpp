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
	sign = 0;
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

LongInteger* LongInteger::Add(const LongInteger* that) const
{
	LongInteger* sum = new LongInteger();
	if(this->sign == that->sign)
	{
		UnsignedAdd(sum, this, that);
		sum->sign = this->sign;
	}
	else
	{
		if(this->UnsignedGreaterThan(that))
		{
			UnsignedSubtract(sum, this, that);
			sum->sign = this->sign;
			if(sum->list->Size() == 0) sum->sign = 0;
		}
		else
		{
			UnsignedSubtract(sum, that, this);
			sum->sign = that->sign;
			if(sum->list->Size() == 0) sum->sign = 0;
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

size_t LongInteger::DigitCount() const
{
	size_t size = this->list->Size() - 1;
	if(size == -1) size = 0;
	size *= 8; //Logic error: this can overflow
	if(this->list->First() != NULL) size += Digits(this->list->First()->GetValue());
	return size; 
}

bool LongInteger::EqualTo(const LongInteger* that) const
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

bool LongInteger::GreaterThan(const LongInteger* that) const
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

bool LongInteger::LessThan(const LongInteger* that) const
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

LongInteger* LongInteger::Multiply(const LongInteger* that) const
{
	
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

LongInteger* LongInteger::Subtract(const LongInteger* that) const
{
	LongInteger* difference = new LongInteger();
	
	if(this->sign == that->sign)
	{
		if(this->UnsignedGreaterThan(that))
		{
			UnsignedSubtract(difference, this, that);
			difference->sign = this->sign;
			if(difference->list->Size() == 0) difference->sign = 0;
		}
		else
		{
			UnsignedSubtract(difference, that, this);
			difference->sign = -that->sign;
			if(difference->list->Size() == 0) difference->sign = 0;
		}
	}
	else
	{
		UnsignedAdd(difference, this, that);
		
		if	   (that->sign == -1) difference->sign = 1;
		else if(this->sign == -1) difference->sign = -1;
		else 					  difference->sign = fmax(this->sign, that->sign);
	}
	
	return difference;
}

/**
 *	@param S: the pointer to an initialized sum LongInteger
 *	@param A: the pointer to the larger LongInteger
 *	@param B: the pointer to the smaller LongInteger (can be equal to A) 
 */
LongInteger* LongInteger::UnsignedAdd(LongInteger* S, const LongInteger* A, const LongInteger* B) const
{
	Position* s = S->list->Last();
	Position* a = A->list->Last();
	Position* b = B->list->Last();
	
	size_t i = S->list->Size();
	size_t j = A->list->Size();
	size_t k = B->list->Size();
	
	int carry = 0;
	
	while(carry || i || j || k)
	{
		int value = carry;
		if(i)
		{
			value += s->GetValue();
			if(--i) s = S->list->Before(s);
		}
		if(j)
		{
			value += a->GetValue();
			if(--j) a = A->list->Before(a);
		}
		if(k)
		{
			value += b->GetValue();
			if(--k) b = B->list->Before(b);
		}
		
		carry = Overflow(value);
		value = Underflow(value);
		
		if(i) s->SetValue(value);
		else  S->list->InsertFirst(value);
	}
	
	return S;
}

bool LongInteger::UnsignedGreaterThan(const LongInteger* that) const
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

LongInteger* LongInteger::UnsignedMultiply(LongInteger* P, const LongInteger* A, const LongInteger* B) const
{
	int a1,a2;
	int b1,b2;
	int v1,v2;
	int z1,z2,z3;
	
	int zeroPadding = 0;
	int x = 10000;
	
	Position* a = A->list->Last();
	Position* b = B->list->Last();
	
	LongInteger* product = new LongInteger();
 
	int i = A->list->Size();
	while(i > 0)
	{
		LongInteger* temp = new LongInteger();
		for (int i = 0; i < zeroPadding; ++i) temp->list->InsertLast(0);

		a1 = UpperHalf(a->GetValue());
		a2 = LowerHalf(a->GetValue());
		
		int j = B->list->Size();
		while(j > 0)
		{			
			b1 = UpperHalf(b->GetValue());
			b2 = LowerHalf(b->GetValue());
			
			z1 = a1 * b1;
			z3 = a2 * b2;
			z2 = ( (a1 + a2) * (b1 + b2) ) - z1 - z3;
			
			v1 = z1 + UpperHalf(z2);
			v2 = z3 + (LowerHalf(z2) * x );
			
			temp->list->InsertFirst(v2);
			temp->list->InsertFirst(v1);
			
			if(--j) b = B->list->Before(b);
		}
		++zeroPadding;
		if(--i) a = A->list->Before(a);
	}
}

/**
 *	@param D: the pointer to an initialized difference LongInteger
 *	@param A: the pointer to the larger LongInteger
 *	@param B: the pointer to the smaller LongInteger (can be equal to A) 
 */
LongInteger* LongInteger::UnsignedSubtract(LongInteger* D, const LongInteger* A, const LongInteger* B) const
{
	Position* d = D->list->Last();
	Position* a = A->list->Last();
	Position* b = B->list->Last();
	
	size_t i = D->list->Size();
	size_t j = A->list->Size();
	size_t k = B->list->Size();
	
	int borrow = 0;
	while(i || j || k)
	{
		int value = borrow;
		if(i)
		{
			value += d->GetValue();
			if(--i) d = D->list->Before(d);
		}
		if(j)
		{
			value += a->GetValue();
			if(--j) a = A->list->Before(a);
		}
		if(k)
		{
			value -= b->GetValue();
			if(--k) b = B->list->Before(b);
		}
		
		borrow = Overflow(value);
		value  = Underflow(value);
		
		if(i) d->SetValue(value);
		else  D->list->InsertFirst(value);
	}
	
	return D;
}