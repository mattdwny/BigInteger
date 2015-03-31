#include "LongInteger.h"

LongInteger* units[8];

int main(int argc, char* argv[])
{
	/**
	 * Begin Step 1
	 */
	 
	units[0] = LongInteger("2222");
	units[1] = LongInteger("99999999");
	units[2] = LongInteger("-246813575732");
	units[3] = LongInteger("180270361023456789");
	units[4] = LongInteger("1423550000000010056810000054593452907711568359");
	units[5] = LongInteger("-350003274594847454317890");
	units[6] = LongInteger("29302390234702973402973420937420973420937420937234872349872934872893472893749287423847");
	units[7] = LongInteger("-98534342983742987342987339234098230498203894209928374662342342342356723423423");
	
	/**
	 * Begin Step 2
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c)
	{
		LongInteger* f = units[c1 - 97];
		
		cout << c1 << " is " << f->BlockOutput() << endl;
	}
	
	/**
	 * Begin Step 3
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c)
	{
		LongInteger* f = units[c1 - 97];
		
		cout << c1 << " is " << f->Output() << endl;
	}
	
	/**
	 * Begin Step 4
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c)
	{
		LongInteger* f = units[c1 - 97];
		cout << c1 << " is " << c1->Output() << " with sign " << f->Sign() << " and digits " << f->DigitCount() << endl;
	}
	
	/**
	 * Begin Step 5
	 */
	
	int a = 2222;
	int b = 99999999;
	
	cout << endl;
	
	cout << "a's Digits is " << UtilityOperations.Digits(a) << endl;
	cout << "a's LowerHalf is " << UtilityOperations.LowerHalf(a) << endl;
	cout << "a's Overflow is " << UtilityOperations.Overflow(a) << endl;
	cout << "a's Underflow is " << UtilityOperations.Underflow(a) << endl;
	cout << "a's UpperHalf is " << UtilityOperations.UpperHalf(a) << endl;
	
	cout << endl;
	
	cout << "b's Digits is " << UtilityOperations.Digits(b) << endl;
	cout << "b's LowerHalf is " << UtilityOperations.LowerHalf(b) << endl;
	cout << "b's Overflow is " << UtilityOperations.Overflow(b) << endl;
	cout << "b's Underflow is " << UtilityOperations.Underflow(b) << endl;
	cout << "b's UpperHalf is " << UtilityOperations.UpperHalf(b) << endl;
	
	/**
	 * Begin Step 6
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c)
		{
			LongInteger* s = units[c2 - 97];
			
			cout << c1 << " = " << c2 << " => " << f->Output() << " = " << s->Output() << endl;
			cout << f->EqualTo(s) << endl;
			cout << c1 << " < " << c2 << " => " << f->Output() << " < " << s->Output() << endl;
			cout << f->LessThan(s) << endl;
			cout << c1 << " > " << c2 << " => " << f->Output() << " > " << s->Output() << endl;
			cout << f->GreaterThan(s) << endl;
		}
	}
}

