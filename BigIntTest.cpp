#include <stdio.h>
#include <iostream>
#include "LongInteger.h"
#include "UtilityOperations.h"

using namespace std;

LongInteger* units[8];

int main(int argc, char* argv[])
{
	/**
	 * Begin Step 1
	 */
	 
	LongInteger A = LongInteger("2222");
	LongInteger B = LongInteger("99999999");
	LongInteger C = LongInteger("-246813575732");
	LongInteger D = LongInteger("180270361023456789");
	LongInteger E = LongInteger("1423550000000010056810000054593452907711568359");
	LongInteger F = LongInteger("-350003274594847454317890");
	LongInteger G = LongInteger("29302390234702973402973420937420973420937420937234872349872934872893472893749287423847");
	LongInteger H = LongInteger("-98534342983742987342987339234098230498203894209928374662342342342356723423423");
	
	 
	units[0] = &A;
	units[1] = &B;
	units[2] = &C;
	units[3] = &D;
	units[4] = &E;
	units[5] = &F;
	units[6] = &G;
	units[7] = &H;
	
	/**
	 * Begin Step 2
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		cout << c1 << " is ";
		f->BlockOutput();
		cout << endl;
	}
	
	/**
	 * Begin Step 3
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		cout << c1 << " is ";
		f->Output();
		cout << endl;
	}
	
	/**
	 * Begin Step 4
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		cout << c1 << " is ";
		f->Output();
		cout << " with sign " << f->Sign() << " and digits " << f->DigitCount() << endl;
	}
	
	/**
	 * Begin Step 5
	 */
	
	int a = 2222;
	int b = 99999999;
	
	cout << endl;
	
	cout << "a's Digits is " << Digits(a) << endl;
	cout << "a's LowerHalf is " << LowerHalf(a) << endl;
	cout << "a's Overflow is " << Overflow(a) << endl;
	cout << "a's Underflow is " << Underflow(a) << endl;
	cout << "a's UpperHalf is " << UpperHalf(a) << endl;
	
	cout << endl;
	
	cout << "b's Digits is " << Digits(b) << endl;
	cout << "b's LowerHalf is " << LowerHalf(b) << endl;
	cout << "b's Overflow is " << Overflow(b) << endl;
	cout << "b's Underflow is " << Underflow(b) << endl;
	cout << "b's UpperHalf is " << UpperHalf(b) << endl;
	
	/**
	 * Begin Step 6
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			cout << c1 << " = " << c2 << " => ";
			f->Output();
			cout << " = ";
			s->Output();
			cout << endl;
			cout << f->EqualTo(s) << endl;
			
			cout << c1 << " < " << c2 << " => ";
			f->Output();
			cout << " < ";
			s->Output();
			cout << endl;
			cout << f->LessThan(s) << endl;
			
			cout << c1 << " > " << c2 << " => ";
			f->Output();
			cout << " > ";
			s->Output();
			cout << endl;
			cout << f->GreaterThan(s) << endl;
		}
	}
}

