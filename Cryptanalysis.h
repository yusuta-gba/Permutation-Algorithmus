#pragma once
#include "Encryption.h"
#include <bitset>
#include <cassert>
#include <cstddef>
using namespace std;
typedef bitset<8> byte;

class Cryptanalysis {

public:
	Encryption D;
	int SearchIndex = 0;		
	int CounterIndex = 0;
	int KeyMask[4];			
	void initialize(Encryption p1);
	void encode(int a, int b, int c, int d);			// Enkodierung der Arithmetischen-Suche
	void tree(bool l1, bool l2, bool l3, bool l4, int stop); /* Ausführung der Kryptoanalyse auf Basis einer Brute - Force - Suche, welches die Enkodierung abhängig von den 4 Parametern ausführt, 
																zusätzlich einen weiteren Parameter besitzt, welcher die Arithmeitsche-Suche terminiert
															  */
};