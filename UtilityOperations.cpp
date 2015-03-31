#include "UtilityOperations.h"

/**
 * Returns the number of digits in regular integer "val" as an integer
 *
 * @param 0-8 digits in base ten [0,99999999]
 * @return 0-8 (# of digits)
 */
int Digits(int val)
{
	//return ceil(log10(digits + 1));
	int digits = 0;
	while(val)
	{
		val /= 10;
		++digits;
	}
	return digits;
}

/**
 * Returns the four rightmost digits of an 8 digit integer
 *
 * @param 0-8 digits in base ten [0,99999999]
 * @return the four least significant digits
 */
int LowerHalf(int val)
{
	return val % 10000;
}

/**
 * Returns the overflow digit (9th digit in a 9 digit integer)
 *
 * @param a chunk of data in range [0,2^31-1]
 * @return any digits more significant digits in base ten [0,99999999]
 */
int Overflow(int val)
{
	return val / 100000000;
}

/**
 * Returns the 8 rightmost digits of regular integer "val"
 *
 * @param a chunk of data in range [0,2^31-1]
 * @return 0-8 least significant digits in base ten [0,99999999]
 */
int Underflow(int val)
{
	return val % 100000000;
}

/**
 * Returns the four leftmost digits of an 8 digit integer
 *
 * @param 0-8 digits in base ten [0,99999999]
 * @return the four most significant digits
 */
int UpperHalf(int val)
{
	//assert(Overflow(val) == 0);
	return val / 10000;
}