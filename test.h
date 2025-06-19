#include <stdio.h>

class tC {
	
	public:
		int key;
		int size;
		char * plainField;
		char ** cipherField;
		char * decryptedField;
		tC(int a, int b);
		void readPlainField();
		void readCipherField();
		void printDecryptedField();
		void setPlainField(char  * buf);
		void encrypt();
		void decrypt();
			
};

