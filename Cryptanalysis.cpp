#include "Cryptanalysis.h"



void Cryptanalysis::initialize(Encryption d)	// Initialisierung eines Objekts
{
	this->D = d;
}

void Cryptanalysis::encode(int a,  int b, int c, int d)															// Arithmetische Suche	berechnen
{
	this->SearchIndex = this->SearchIndex + 4 * a + (2 * b + 2 * c) * d;
	this->CounterIndex++;
	printf(" %2x . %2x + 4 * %2x + (  2 * %2x + 2 * %2x) * %x )\n", this->CounterIndex,this->SearchIndex, a, b, c, d);
	return;
}



void Cryptanalysis::tree(bool l1, bool l2, bool l3, bool l4, int stop)		// Anhand von  4 Parametern soll die Arithmetische Suche erfolgen !
{
	


										/*
										*  Enkodierung										*/
		encode(1, 0, 0, 0);
		if (l1 == true)
		{
			encode(0,1,0,1);													// Herausfinden von zwei Offsetwerten und die Bytes in einem anderen Array laden !
			this->D.ReverseOffset(this->SearchIndex);
			this->KeyMask[2] = this->D.hexArray[this->D.a][this->D.b];			
			this->KeyMask[3] = this->D.hexArray[this->D.a][this->D.b+1];
			encode(0, 0, 1, 1);
			this->D.ReverseOffset(this->SearchIndex);
			this->KeyMask[0] = this->D.hexArray[this->D.a][this->D.b];
			this->KeyMask[1] = this->D.hexArray[this->D.a][this->D.b + 1];
			if (stop == 1)
			{
				return;
			}
				
		}
		else 
		{
			encode(0, 1, 1, 1);
		}
		encode(2, 0, 0, 0);

		if (l2 == true)														// Herausfinden von zwei Offsetwerten und die Bytes in einem anderen Array laden !
		{
			encode(0,1,0,1);
			this->D.ReverseOffset(this->SearchIndex);
			this->KeyMask[2] = this->D.hexArray[this->D.a][this->D.b];
			this->KeyMask[3] = this->D.hexArray[this->D.a][this->D.b + 1];
			encode(0, 0, 1, 1);
			this->D.ReverseOffset(this->SearchIndex);
			this->KeyMask[0] = this->D.hexArray[this->D.a][this->D.b];
			this->KeyMask[1] = this->D.hexArray[this->D.a][this->D.b + 1];
			if (stop == 2)
				return;
		}
		else
		{
			encode(0, 1, 1, 1);
		}

		encode(2, 0, 0, 0);
		if (l3 == true)
		{
			encode(0,1,0,1);
			this->D.ReverseOffset(this->SearchIndex);					// Herausfinden von zwei Offsetwerten und die Bytes in einem anderen Array laden !
			this->KeyMask[2] = this->D.hexArray[this->D.a][this->D.b];
			this->KeyMask[3] = this->D.hexArray[this->D.a][this->D.b + 1];
			encode(0,0,1,1);
			this->D.ReverseOffset(this->SearchIndex);
			this->KeyMask[0] = this->D.hexArray[this->D.a][this->D.b];
			this->KeyMask[1] = this->D.hexArray[this->D.a][this->D.b + 1];
			if (stop == 3)
				return;
		}
		else 
		{
			encode(0, 1, 1, 1);
		}

		if (l4 == true)
		{
			encode(0, 1, 0, 1);											// Herausfinden von zwei Offsetwerten und die Bytes in einem anderen Array laden !
			this->D.ReverseOffset(this->SearchIndex);
			this->KeyMask[2] = this->D.hexArray[this->D.a][this->D.b];
			this->KeyMask[3] = this->D.hexArray[this->D.a][this->D.b + 1];
			encode(0, 0, 1, 1);
			this->D.ReverseOffset(this->SearchIndex);
			this->KeyMask[0] = this->D.hexArray[this->D.a][this->D.b];
			this->KeyMask[1] = this->D.hexArray[this->D.a][this->D.b + 1];
			if (stop == 4)
				return;
		}
		else
		{
			encode(0, 1, 1, 1);
		}
}
