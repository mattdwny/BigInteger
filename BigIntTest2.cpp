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
	
	//For each Long Integer add it to every other Long Integer (one at a time) and print the result
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			LongInteger* result = f->Add(s);
			
			//cout << c1 << " + " << c2 << endl;
			result->Output();
			cout << endl;
			
			//delete result; //without a proper destructor this is pointless
		}
	}
	
	//For  each  Long  Integer  subtract  it  from  every  other  Long  Integer  (one  at  a  time)  and  print  the results
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			LongInteger* result = f->Subtract(s);
			
			//cout << c1 << " - " << c2 << endl;
			result->Output();
			cout << endl;
			
			//delete result; //without a proper destructor this is pointless
		}
	}
	
	//For each Long Integer multiply it by every other Long Integer (one at a time) and print the result
	/*
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			LongInteger* result = f->Multiply(s);
			
			cout << c1 << " * " << c2 << endl;
			result->Output();
			cout << endl;
			
			//delete result; //without a proper destructor this is pointless
		}
	}
	*/
/*
Compute the following (in alphabetical order):
I
= A + 
D
J
= B + 
C
K
= C + D
L
= 
I
+
I
M = A + I
N
= B + 
K
O = A 
–
D
P
= C 
–
D
Q
= D 
–
C
R = L
–
L
S
= 
P
–
O
T
= 
N 
–
Q
U = A * D
V = B * C
W
= 
D * D
X
= 
O * I
Y
= 
J * P
Z 
= M
* N
	*/
	
}

