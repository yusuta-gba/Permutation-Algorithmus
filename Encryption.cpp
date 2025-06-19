
#include <bitset>
#include <cassert>
#include <cstddef>
#include <iostream>
#include "Encryption.h"
#include "Box.h"
#include "Cryptanalysis.h"

using namespace std;

typedef bitset<8> byte;





void Encryption::getOffset( int num)
{

	int offset;
	int x = 0;
	for (int i = 0; i < 8; i++)
	{
		
		for (offset = 0; offset < 8; offset++)
		{
			
			x = 8 * i + offset;
			
			if (x == num)
			{
				this->a = i;
				this->b = offset;
				return;
			}
			
		}	
	}
	return;
	}
	




void Encryption::setPlainField(byte* plainField)
{
	for (int i = 0; i < 64; i++)
	{
		this->plainField[i] = plainField[i];
	}
//	this->bitMask = 0x01;

	
	this->MaskArray[0] = 0x01;
	this->MaskArray[1] = 0x02;
	this->MaskArray[2] = 0x04;
	this->MaskArray[3] = 0x08;
	this->MaskArray[4] = 0x10;
	this->MaskArray[5] = 0x20;
	this->MaskArray[6] = 0x40;
	this->MaskArray[7] = 0x80;
}

void Encryption::printPlainField()
{
	for (int i = 0; i < 64; i++)
	{
		printf(" %x ",this->plainField[i]);
			if ((i+1) % 4 == 0 && i != 0)
				cout << endl;
	}

}


void Encryption::setBit(byte* b, int position, bool flag)
{
	byte mask = 0x01;
	byte mask2 = 0x00;
	if (flag == true)
	{
		
		
		*b = *b | (mask << position);
	}
	else if (flag == false)
	{
		*b = *b & ~( mask2 << position);
	}

}

void  Encryption::getByte(byte b, int j)
{

	byte temp;
	for (int i = 7; i >= 0; i--)
	{
		temp = b & this->MaskArray[i];
	
		if (temp == 0x01)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x02)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x04)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x08)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x10)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x20)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x40)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x80)
		{
			this->BitArray[j][i] = true;
			printf("1");
		}
		else if(temp == 0x00)
		{
			this->BitArray[j][i] = false;
			printf("0");
		}
	}
	temp = 0x0;
	
	printf("\n");
	return;

}

void  Encryption::load1D()
{

	DA[0] = false;
	DA[1] = false;
	DA[2] = false;
	DA[3] = true;
	DA[4] = true;
	DA[5] = true;
	DA[6] = false;
	DA[7] = true;


	DA[8] = false;
	DA[9] = false;
	DA[10] = false;
	DA[11] = false;
	DA[12] = false;
	DA[13] = false;
	DA[14] = false;
	DA[15] = false;
	
	DA[16] = true;
	DA[17] = false;
	DA[18] = false;
	DA[19] = false;
	DA[20] = false;
	DA[21] = false;
	DA[22] = false;
	DA[23] = false;

	DA[24] = true;
	DA[25] = true;
	DA[26] = false;
	DA[27] = true;
	DA[28] = false;
	DA[29] = false;
	DA[30] = true;
	DA[31] = false;


	DA[32] = false;
	DA[33] = false;
	DA[34] = false;
	DA[35] = true;
	DA[36] = true;
	DA[37] = true;
	DA[38] = true;
	DA[39] = false;

	DA[40] = false;
	DA[41] = false;
	DA[42] = false;
	DA[43] = false;
	DA[44] = false;
	DA[45] = false;
	DA[46] = false;
	DA[47] = false;

	DA[48] = true;
	DA[49] = false;
	DA[50] = false;
	DA[51] = false;
	DA[52] = false;
	DA[53] = false;
	DA[54] = false;
	DA[55] = false;

	DA[56] = true;
	DA[57] = true;
	DA[58] = false;
	DA[59] = true;
	DA[60] = false;
	DA[61] = false;
	DA[62] = true;
	DA[63] = false;

	return;

}

void Encryption::ReverseOffset(int num)
{
	int offset;
	int x = 0;
	for (int i = 7; i >= 0; i--)
	{

		for (offset = 0; offset < 8; offset++)
		{

			x = 8 * i + offset;
			if (x == num)
			{
				this->a = i;
				this->b = offset;
				return;
			}
			x = 0;
		}

	}

	return;
}

bool Encryption::ReverseSearchBits(int num)
{
	this->ReverseOffset(num);
	return this->BitArray[this->a][this->b];

}

bool Encryption::searchBits(int num)
{
	/*******************
		*     0 ->  0 <=8
		*	  1 ->  9 <= 16
		*	  2 ->  16 <= 23
		*	  3 ->  24 <= 31
		*	  4 ->  32 <= 39
		*	  5 ->  40 <= 47
		*	  6 ->  48 <= 55
		*	  7 ->  56 <= 64
		*
		*********************/

		  this->getOffset(num);
	      return this->BitArray[this->a][this->b];
}



void Encryption::printBits(bool  * p1)
{
	for (int i = 0; i < 8; i++)
	{
		if (p1[i])
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	
}

void Encryption::linearGetBits()
{
	int x = 0;
	int y = 0;
	int counter = 0;
	for (int i = 1; i <= 8; i++)							// Einlesevorgang des Datenstroms V2													
	{
		x = 8 * i - 1;
		y = 8 * (i - 1);
		for (x; x >= y; x--)
		{
			counter++;

			printf("%d", this->ReverseSearchBits(x));
			if (counter == 8)
			{
				printf("\n");
				counter = 0;
			}
		}
	}
}

bool Encryption::linearGetBits(int v2)
{
	int x = 0;
	int y = 0;
	int counter = 0;
	for (int i = 1; i <= 8; i++)							// Einlesevorgang des Datenstroms V2													
	{
		x = 8 * i - 1;								// 64 -  (8 * 7) -> 64  
		y = 8 * (i - 1);							// 63	|	-1	
		for (x; x >= y; x--)							// 62	|	-2
		{									// 61	|	-3
			counter++;							// 60	|	-4
											// 59	|	-5
											// 58	|	-6
			if (v2 == counter)						// 57	|	-7
			{								// 56		-8								
				counter = 0;
				return this->ReverseSearchBits(x);
			}
		}
	}

}

void Encryption::select( int j)
{ 
	for (int i = j; i<j+8; i++)
	{
		if (i <= 3)
		{
			this->BitArrayV3[0][i] = this->BitArrayV2[8 - 2][7 - 1 - 2 * i];
			this->BitArrayV3[1][i] = this->BitArrayV2[8 - 4][7 - 1 - 2 * i];
			this->BitArrayV3[2][i] = this->BitArrayV2[8 - 6][7 - 1 - 2 * i];
			this->BitArrayV3[3][i] = this->BitArrayV2[8 - 8][7 - 1 - 2 * i];
			this->BitArrayV3[4][i] = this->BitArrayV2[8 - 1][7 - 1 - 2 * i];
			this->BitArrayV3[5][i] = this->BitArrayV2[8 - 3][7 - 1 - 2 * i];
			this->BitArrayV3[6][i] = this->BitArrayV2[8 - 5][7 - 1 - 2 * i];
			this->BitArrayV3[7][i] = this->BitArrayV2[8 - 7][7 - 1 - 2 * i];
		}
		else
		{
			switch (i)
			{
			case 4:
				this->BitArrayV3[0][i] = this->BitArrayV2[8 - 2][7];
				this->BitArrayV3[1][i] = this->BitArrayV2[8 - 4][7];
				this->BitArrayV3[2][i] = this->BitArrayV2[8 - 6][7];
				this->BitArrayV3[3][i] = this->BitArrayV2[8 - 8][7];
				this->BitArrayV3[4][i] = this->BitArrayV2[8 - 1][7];
				this->BitArrayV3[5][i] = this->BitArrayV2[8 - 3][7];
				this->BitArrayV3[6][i] = this->BitArrayV2[8 - 5][7];
				this->BitArrayV3[7][i] = this->BitArrayV2[8 - 7][7];
				break;
			case 5:
				this->BitArrayV3[0][i] = this->BitArrayV2[8 - 2][7-2];
				this->BitArrayV3[1][i] = this->BitArrayV2[8 - 4][7-2];
				this->BitArrayV3[2][i] = this->BitArrayV2[8 - 6][7-2];
				this->BitArrayV3[3][i] = this->BitArrayV2[8 - 8][7-2];
				this->BitArrayV3[4][i] = this->BitArrayV2[8 - 1][7-2];
				this->BitArrayV3[5][i] = this->BitArrayV2[8 - 3][7-2];
				this->BitArrayV3[6][i] = this->BitArrayV2[8 - 5][7-2];
				this->BitArrayV3[7][i] = this->BitArrayV2[8 - 7][7-2];
				break;
			case 6:
				this->BitArrayV3[0][i] = this->BitArrayV2[8 - 2][7-4];
				this->BitArrayV3[1][i] = this->BitArrayV2[8 - 4][7 - 4];
				this->BitArrayV3[2][i] = this->BitArrayV2[8 - 6][7 - 4];
				this->BitArrayV3[3][i] = this->BitArrayV2[8 - 8][7 - 4];
				this->BitArrayV3[4][i] = this->BitArrayV2[8 - 1][7 - 4];
				this->BitArrayV3[5][i] = this->BitArrayV2[8 - 3][7 - 4];
				this->BitArrayV3[6][i] = this->BitArrayV2[8 - 5][7 - 4];
				this->BitArrayV3[7][i] = this->BitArrayV2[8 - 7][7 - 4];
				break;
			case 7:
				this->BitArrayV3[0][i] = this->BitArrayV2[8 - 2][7 - 6];
				this->BitArrayV3[1][i] = this->BitArrayV2[8 - 4][7 - 6];
				this->BitArrayV3[2][i] = this->BitArrayV2[8 - 6][7 - 6];
				this->BitArrayV3[3][i] = this->BitArrayV2[8 - 8][7 - 6];
				this->BitArrayV3[4][i] = this->BitArrayV2[8 - 1][7 - 6];
				this->BitArrayV3[5][i] = this->BitArrayV2[8 - 3][7 - 6];
				this->BitArrayV3[6][i] = this->BitArrayV2[8 - 5][7 - 6];
				this->BitArrayV3[7][i] = this->BitArrayV2[8 - 7][7 - 6];
				break;
			}
		
		}
		
		
	}

	
	
}

int Encryption::convert(int j, bool flag1, bool flag2, bool flag3)
{
	
	int  c = 0x00;
	for (int i = 7; i >= 0; i--)
	{
		c = 2 * c;
		if(flag1 == true)
		{ 
		if (this->BitArray[j][i] == 1)
		{
			c = c + 1;
			
		}
		}
		else if (flag2 == true)
		{
			if (this->BitArrayV2[j][i] == 1)
			{
				c = c + 1;

			}

		}
		else if (flag3 == true)
		{

			if (this->BitArrayV3[j][i] == 1)
			{
				c = c + 1;

			}
		}
	}

	return c;
} 

void Encryption::printBytes()
{

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf(" %x ",this->hexArray[i][j]);
		}
		printf("\n");
	}
}

void Encryption::loadHex(bool flag1, bool flag2, bool flag3)
{

	for (int i = 1; i <= 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->hexArray[i - 1][j] = this->convert(4 * (i-1) + j,flag1,flag2,flag3);
		}
		
	}
}

void Encryption::mirror(int j)
{
	
		
	for (int i = j; i < j+8; i++)
	{
		this->BitArrayV2[i][1 - 1] = this->BitArray[5-1][i];
		this->BitArrayV2[i][2 - 1] = this->BitArray[1-1][i];
		this->BitArrayV2[i][3 - 1] = this->BitArray[6-1][i];
		this->BitArrayV2[i][4 - 1] = this->BitArray[2-1][i];
		this->BitArrayV2[i][5 - 1] = this->BitArray[7-1][i];
		this->BitArrayV2[i][6 - 1] = this->BitArray[3-1][i];
		this->BitArrayV2[i][7 - 1] = this->BitArray[8-1][i];
		this->BitArrayV2[i][8 - 1] = this->BitArray[4-1][i];

		//if (i == 3)
		//	cout  << this->BitArrayV2[3][8-1] <<  " FOUND " << this->BitArray[3][i] << endl;
	}


			
			
}
void Encryption::printBitV2()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d", this->BitArrayV2[i][j]);
		}
		printf("\n");

	}
}

void Encryption::printBitV3()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d", this->BitArrayV3[i][j]);
		}
		printf("\n");

	}
}

void Encryption::printBitV1()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			printf("%d", this->BitArray[i][j]);
		}
		printf("\n");

	}
}
void Encryption::printBitV58()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d", this->DA[i*8+j]);
		}
		printf("\n");

	}
}
void Encryption::printPERM()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			printf("%d", this->DA2[i * 8 + j]);
		}
		printf("\n");

	}
}

void Encryption::permutate()
{
	for (int i = 0; i < 64; i++)
	{
		
		DA2[i] = DA[ip[i]-1];
			
	}
}


int main(char argv[], int argc)
{


	byte plainfield[64] =
	{

		// 0 .. 3
	  0x1d, 0x00, 0x80, 0xd2,  // 4 .. 7
	  0x1e, 0x00, 0x80, 0xd2,  // 8 .. 11
	  0xe5, 0x03, 0x00, 0xaa,  // 12 .. 14
	  0xe1, 0x03, 0x40, 0xf9,  // 15 .. 18
	  0xe2, 0x23, 0x00, 0x91,  // 19 .. 22
	  0xe6, 0x03, 0x00, 0x91,  // 23 .. 27
	  0xc0, 0x01, 0x00, 0xd0,  // 28 .. 31
	  0x00, 0xdc, 0x47, 0xf9,  // 32 .. 35
	  0x03, 0x00, 0x80, 0xd2,  // 36 .. 39
	  0xc5, 0xf7, 0xff, 0x97,  // 40 .. 43
	  0x88, 0xf8, 0xff, 0x97,  // 44 .. 47

	  0x90, 0x90, 0x90, 0x90,  // 48 .. 51
	  0x90, 0x90, 0x90, 0x90,  // 52 .. 55
	  0x90, 0x90, 0x90, 0x90,  // 56 .. 59
	  0x90, 0x90, 0x90, 0x90   // 60 .. 63
	};





	Encryption DES;
	Box A;
	Cryptanalysis Tool;
	DES.setPlainField(plainfield);			// Einlesen des Eingabefelds


	for (int j = 0; j <= 56; j++)
	{
		DES.getByte(plainfield[j], j);
		
	}

	DES.load1D();
	
	printf("OK!");
	printf("*******\n");

	printf("\n********************\n");		// Ausführen der Permutations-Chiffre
	DES.loadHex(true, false, false);			// Das erste Bit-Array konvertieren und diese dann im Byte-Array speichern
	DES.printBytes();
	printf("*********************\n");
	DES.printBitV58();
	printf("*********************\n");
	DES.printBitV1();
	printf("*********************\n");
	printf("MIRROR !!!!  \n");
	DES.mirror(0);
	DES.printBitV2();
	printf("*********************\n");
	//  Ausführung der Transposition
	DES.loadHex(false, true, false);	   // Das zweite Bit-Array konvertieren und diese dann im selben Byte-Array speichern !	
	DES.select(0);
	DES.loadHex(false, false, true);	   // Das dritte Bit-Array konvertieren und diese dann im selben Byte-Array speichern !
	DES.printBitV3();

	printf("*********************\n");
	printf("PERM-ORACLE ! ! !\n");
	DES.permutate();
	DES.printPERM();
	printf("*********************\n");
	DES.mirror(8);						// Ausführung der näüchsten Transposition
	DES.loadHex(false, true, false);
	DES.select(8);						// Auswählen der einzelnen Bits und diese  in einem weiteren Byte-Array speichern
	DES.loadHex(false, false, true);
	DES.printBytes();
	printf("*********************\n");
	DES.mirror(16);					    // Ausführung der nächsten Transposition
	DES.loadHex(false, true, false);
	DES.select(16);
	DES.loadHex(false, false, true);
	DES.printBytes();
	printf("*********************\n");
	DES.mirror(24);
	DES.loadHex(false, true, false);
	DES.select(24);
	DES.loadHex(false, false, true);
	DES.printBytes();
	printf("*********************\n");
	DES.mirror(32);					// Ausführung der letzten Transposition
	DES.loadHex(false, true, false);
	DES.select(32);					// Auswählen der einzelnen Bits und diese in einem weiteren Byte-Array speichern
	DES.loadHex(false, false, true);
	DES.printBytes();			   // Ausgabe der einzelnen Bytes !
	printf("********************\n");
	
	Tool.initialize(DES);
	Tool.tree(true, true, true, true,1);
	printf("************");

		int ByteMask[4];
		ByteMask[0] = 0x1e;
		ByteMask[1] = 0x00;
		ByteMask[2] = 0x80;
		ByteMask[3] = 0xd2;
	for (int i = 0; i <= 3; i++)
	{
		printf("\n%2x ^ %2x = %2x\n", ByteMask[i], Tool.KeyMask[i], ByteMask[i] ^ Tool.KeyMask[i]);
	}
	printf("*************");

//	DES.loadHex();
//	DES.permutate();
//	DES.printBytes();
}
