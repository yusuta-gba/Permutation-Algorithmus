
#include "test.h"
#include <iostream>
using namespace std;
tC::tC(int a, int b)
{ 
	this->key = a;
  	this->size = b;
	this->plainField = new char[this->size];	  
	int width = this->size / this->key;
	this->cipherField = new char *[this->key];
	this->decryptedField = new char[this->size];
	for(int i = 0; i < this->size; i++)
	{	
		this->cipherField[i] = new char[this->size/this->key];
		
	}

}

void tC::readPlainField()
{
	printf("%s", this->plainField);
}
void tC::readCipherField()
{
	printf("%s", this->cipherField);
}
void tC::setPlainField(char * buffer)
{
	for(int i = 0; i< this->size; i++)
	{
		this->plainField[i] = buffer[i];
	}
}
void tC::encrypt()
{
	int currentIndex = 0;
	for( int i = 0; i< this->size; i++)
	{
		currentIndex = i % this->key; 
		this->cipherField[currentIndex][i % (this->size/this->key)] = this->plainField[i];
		
	}
	
	for(int j = 0; j< 5; j++)
	{
		for(int i = 0; i < this->key; i++)
		{
			printf("%c",this->cipherField[j][i]);
		}
		}
		printf("\nENDE\n");
}


void tC::decrypt()
{
	int ci;
	
	for(int i = 0; i < this->size; i++)
	{
		ci = i % this->key;
		this->decryptedField[i] = this->cipherField[ci][i % (this->size / this->key)];
	}
	cout << this->decryptedField << endl;
}

void tC::printDecryptedField()
{
	for(int i = 0; i < this->size; i++)
	{
		cout << decryptedField[i];
	}
	cout << endl;
}
/*
void tC::decrypt()
{ 
	int space =this->size / this->key;
	for ( int z = 0; z < this->size; z++)
	{
		for(int h = 0; h < 4; h++)
		{
			if ( z % space < h )
				printf("%c",cipherField[h][z % space]);

			
		}
	}

}*/
