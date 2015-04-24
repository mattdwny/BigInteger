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
			
			delete result; //without a proper destructor this is pointless
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
			
			delete result; //without a proper destructor this is pointless
		}
	}
	
	//For each Long Integer multiply it by every other Long Integer (one at a time) and print the result
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			LongInteger* result = f->Multiply(s);
			
			//cout << c1 << " * " << c2 << endl;
			result->Output();
			cout << endl;
			
			delete result; //without a proper destructor this is pointless
		}
	}

	LongInteger* I = A.Add(&D);
	LongInteger* J = B.Add(&C);
	LongInteger* K = C.Add(&D);
	LongInteger* L = I->Add(I);
	LongInteger* M = A.Add(I);
	LongInteger* N = B.Add(K);
	LongInteger* O = A.Subtract(&D);
	LongInteger* P = C.Subtract(&D);
	LongInteger* Q = D.Subtract(&C);
	LongInteger* R = L->Subtract(L);
	LongInteger* S = P->Subtract(O);
	LongInteger* T = N->Subtract(Q);
	LongInteger* U = A.Multiply(&D);
	LongInteger* V = B.Multiply(&C);
	LongInteger* W = D.Multiply(&D);
	LongInteger* X = O->Multiply(I);
	LongInteger* Y = J->Multiply(P);
	LongInteger* Z = M->Multiply(N);
	
	I->Output();
	printf("\n");
	J->Output();
	printf("\n");
	K->Output();
	printf("\n");
	L->Output();
	printf("\n");
	M->Output();
	printf("\n");
	N->Output();
	printf("\n");
	O->Output();
	printf("\n");
	P->Output();
	printf("\n");
	Q->Output();
	printf("\n");
	R->Output();
	printf("\n");
	S->Output();
	printf("\n");
	T->Output();
	printf("\n");
	U->Output();
	printf("\n");
	V->Output();
	printf("\n");
	W->Output();
	printf("\n");
	X->Output();
	printf("\n");
	Y->Output();
	printf("\n");
	Z->Output();
	printf("\n");
	
	delete I;
	delete J;
	delete K;
	delete L;
	delete M;
	delete N;
	delete O;
	delete P;
	delete Q;
	delete R;
	delete S;
	delete T;
	delete U;
	delete V;
	delete W;
	delete X;
	delete Y;
	delete Z;
}

