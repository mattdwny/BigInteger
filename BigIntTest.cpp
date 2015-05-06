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
	 
	LongInteger* A = new LongInteger("2222");
	LongInteger* B = new LongInteger("99999999");
	LongInteger* C = new LongInteger("-246813575732");
	LongInteger* D = new LongInteger("180270361023456789");
	LongInteger* E = new LongInteger("1423550000000010056810000054593452907711568359");
	LongInteger* F = new LongInteger("-350003274594847454317890");
	LongInteger* G = new LongInteger("29302390234702973402973420937420973420937420937234872349872934872893472893749287423847");
	LongInteger* H = new LongInteger("-98534342983742987342987339234098230498203894209928374662342342342356723423423");
	
	 
	units[0] = A;
	units[1] = B;
	units[2] = C;
	units[3] = D;
	units[4] = E;
	units[5] = F;
	units[6] = G;
	units[7] = H;
	
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
	
	cout << endl;
	
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
	
	cout << endl;
	
	/**
	 * Begin Step 4
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		cout << c1 << " has sign " << f->Sign() << " and digits " << f->DigitCount() << endl;
	}
	
	cout << endl;
	
	/**
	 * Begin Step 5
	 */
	
	int a = 2222;
	int b = 99999999;
	
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
	
	cout << endl;
	
	/**
	 * Begin Step 6
	 */
	
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			cout << c1 << " = " << c2 << endl;
			cout << f->EqualTo(s) << endl;
			
			cout << c1 << " < " << c2 << endl;
			cout << f->LessThan(s) << endl;
			
			cout << c1 << " > " << c2 << endl;
			cout << f->GreaterThan(s) << endl;
		}
	}
	
	/**
	 * Begin Part 2222
	 */
	 
	/**
	 * Begin Step 1
	 */
	 
	 //For each Long Integer add it to every other Long Integer (one at a time) and print the result
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			LongInteger* result = f->Add(s);
			
			cout << c1 << " + " << c2 << endl;
			result->Output();
			cout << endl;
			
			delete result; //without a proper destructor this is pointless
		}
	}
	 
	 /**
	 * Begin Step 2
	 */

	//For  each  Long  Integer  subtract  it  from  every  other  Long  Integer  (one  at  a  time)  and  print  the results
	for(char c1 = 'a'; c1 <= 'h'; ++c1)
	{
		LongInteger* f = units[c1 - 97];
		
		for(char c2 = 'a'; c2 <= 'h'; ++c2)
		{
			LongInteger* s = units[c2 - 97];
			
			LongInteger* result = f->Subtract(s);
			
			cout << c1 << " - " << c2 << endl;
			result->Output();
			cout << endl;
			
			delete result; //without a proper destructor this is pointless
		}
	}
	
	 /**
	 * Begin Step 3
	 */
	
	//For each Long Integer multiply it by every other Long Integer (one at a time) and print the result
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
			
			delete result; //without a proper destructor this is pointless
		}
	}
	
	 /**
	 * Begin Step 4
	 */	 
	 
	LongInteger* I = A->Add     (D);
	LongInteger* J = B->Add     (C);
	LongInteger* K = C->Add     (D);
	LongInteger* L = I->Add     (I);
	LongInteger* M = A->Add     (I);
	LongInteger* N = B->Add     (K);
	LongInteger* O = A->Subtract(D);
	LongInteger* P = C->Subtract(D);
	LongInteger* Q = D->Subtract(C);
	LongInteger* R = L->Subtract(L);
	LongInteger* S = P->Subtract(O);
	LongInteger* T = N->Subtract(Q);
	LongInteger* U = A->Multiply(D);
	LongInteger* V = B->Multiply(C);
	LongInteger* W = D->Multiply(D);
	LongInteger* X = O->Multiply(I);
	LongInteger* Y = J->Multiply(P);
	LongInteger* Z = M->Multiply(N);
	
	printf("I = \n");
	I->Output();
	printf("\n");
	printf("J = \n");
	J->Output();
	printf("\n");
	printf("K = \n");
	K->Output();
	printf("\n");
	printf("L = \n");
	L->Output();
	printf("\n");
	printf("M = \n");
	M->Output();
	printf("\n");
	printf("N = \n");
	N->Output();
	printf("\n");
	printf("O = \n");
	O->Output();
	printf("\n");
	printf("P = \n");
	P->Output();
	printf("\n");
	printf("Q = \n");
	Q->Output();
	printf("\n");
	printf("R = \n");
	R->Output();
	printf("\n");
	printf("S = \n");
	S->Output();
	printf("\n");
	printf("T = \n");
	T->Output();
	printf("\n");
	printf("U = \n");
	U->Output();
	printf("\n");
	printf("V = \n");
	V->Output();
	printf("\n");
	printf("W = \n");
	W->Output();
	printf("\n");
	printf("X = \n");
	X->Output();
	printf("\n");
	printf("Y = \n");
	Y->Output();
	printf("\n");
	printf("Z = \n");
	Z->Output();
	printf("\n");
	
	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete F;
	delete G;
	delete H;
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

