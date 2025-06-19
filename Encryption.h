#pragma once
#include <bitset>
#include <cassert>
#include <cstddef>
#include "Box.h"

using namespace std;
typedef bitset<8> byte;

class Encryption
{

public:
	byte plainField[64];
	byte proceedInput[8];
	byte bitMask;
	byte MaskArray[8];
	byte InputTempArray[8];
	bool DA[64];
	bool DA2[64];
	bool BitArray[52][8];
	bool BitArrayV2[52][8];
	bool BitArrayV3[52][8];
	int  hexArray[13][4];
	int a;
	int b;
	int x;
	int y;
	Box BoxA;
	int ip[64] = {
		58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9, 1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7
	};
	
	void printPERM();
	void permutate();
	void setPlainField(byte* parameter_1);
	void printPlainField();
	void printBits(bool * p1);
	void printBytes();
	void f(byte* c);
	void select(int j);					// Ausführung einer Selektion
	void inversepermutate(byte* plainField);
	int convert(int j, bool flag1, bool flag2, bool flag3);
	


	void setBit(byte* a, int position, bool flag);	// Setzen eines Bits an einer festgelegten Position
	void getByte(byte a, int j );
	bool searchBits(int num);						
	void ReverseOffset(int num);					// Berechnung eines Offsetwerts auf Basis einer Linearen-Funktion
	bool ReverseSearchBits(int num);
	void getOffset(int num);			
	void linearGetBits();					
	bool linearGetBits(int v2);
	void load1D();
	//void linearsearch(int p1);
	void loadHex(bool flag1,bool flag2, bool flag3);  // Bits in Bytes umwandeln und diese in eiem Byte-Array speichern !
	void mirror(int i);	
	void printBitV1();// Ausführung der Transposition
	void printBitV2();
	void printBitV3();
	void printBitV58();
	
	//void arithmetik_search(int p1);

	byte BitByteConverter(bool);
	// byte getByte(int anzahl);
	

	
};
