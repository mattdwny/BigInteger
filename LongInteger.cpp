#include "LongInteger.h"

LongInteger::LongInteger(const string& str)
{
	// Do not change this line until Step 3
    this->list = new DLLProjectList();
}

LongInteger::~LongInteger()
{
    delete this->list;
}

void LongInteger::output()
{

}

bool LongInteger::getSign()
{

}

int LongInteger::getDigitCount()
{

}

bool LongInteger::equalTo(const LongInteger* i) const
{

}

bool LongInteger::lessThan(const LongInteger* i) const
{

}

bool LongInteger::greaterThan(const LongInteger* i) const
{

}

LongInteger* LongInteger::add(const LongInteger* i) const
{

}

LongInteger* LongInteger::subtract(const LongInteger* i) const
{

}

LongInteger* LongInteger::multiply(const LongInteger* i) const
{

}

LongInteger* LongInteger::power(const int p) const
{

}
