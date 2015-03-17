#ifndef LONGINTEGER_H
#define LONGINTEGER_H

#include <String>
#include "DLLProjectList.h"

using std::string;


class LongInteger
{
private:
    ProjectList * list;

public:
    LongInteger(const string&);
    ~LongInteger();

    void output();

    bool getSign();

    int getDigitCount();

    bool equalTo(const LongInteger *) const;
    bool lessThan(const LongInteger*) const;
    bool greaterThan(const LongInteger*) const;

    LongInteger* add(const LongInteger*) const;
    LongInteger* subtract(const LongInteger*) const;
    LongInteger* multiply(const LongInteger*) const;
    LongInteger* power(const int pow) const;
};

#endif // LONGINTEGER_H
