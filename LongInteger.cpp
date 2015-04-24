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
	LongInteger* product = new LongInteger();
	if(this->sign == 0 || that->sign == 0) return product;
	
	//more stuff
	
	return 0;
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

LongInteger* LongInteger::Subtract(const LongInteger* that) const
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
 *	@param S: the pointer to an initialized sum LongInteger
 *	@param A: the pointer to the larger LongInteger
 *	@param B: the pointer to the smaller LongInteger (can be equal to A) 
 */
LongInteger* LongInteger::UnsignedAdd(LongInteger* S, const LongInteger* A, const LongInteger* B) const
{	
	return UnsignedArithmetic(S,A,B,true);
}

/**
 *	@param C: the pointer to an initialized LongInteger that will store the result
 *	@param A: the pointer to the larger LongInteger (for subtraction)
 *	@param B: the pointer to the smaller LongInteger (can be equal to A)
 * 	@param add: true if the function should add, false if the program should subtract 
 */
LongInteger* LongInteger::UnsignedArithmetic(LongInteger* C, const LongInteger* A, const LongInteger* B, bool add) const
{
	Position* c = C->list->Last();
	Position* a = A->list->Last();
	Position* b = B->list->Last();
	
	size_t i = C->list->Size();
	size_t j = A->list->Size();
	size_t k = B->list->Size();
	
	int carry = 0;
	while(carry || i || j || k)
	{
		int value = carry;
		if(i)
		{
			value += c->GetValue();
			if(--i) c = C->list->Before(c);
		}
		if(j)
		{
			value += a->GetValue();
			if(--j) a = A->list->Before(a);
		}
		if(k)
		{
			if(add) value += b->GetValue();
			else 	value -= b->GetValue();
			if(--k) b = B->list->Before(b);
		}
		
		carry = Overflow(value);
		value = Underflow(value);
		
		if(i) c->SetValue(value);
		else  C->list->InsertFirst(value);
	}
	
	return C;
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
	UnsignedArithmetic(D,A,B,false);
	D->StripZeros();
	return D;
}