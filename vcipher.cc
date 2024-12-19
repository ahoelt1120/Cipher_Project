#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"


// -------------------------------------------------------
// Vigenere (inherits from Running Key) Cipher implementation
// -------------------------------------------------------
//

/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

/* KCheshire smile implementation.
   It only contains the vector book
   and the bage number.
 */
struct VCipher::KCheshire {
        vector<string>book;
        unsigned int page = 0;
};

/* Default constructor
   This will actually not encrypt the input text
   because it will use the unscrambled alphabet
 */
VCipher::VCipher(){

        string alph = "";
	char c = 'a';
	for(unsigned int i = 0; i < MAX_LENGTH; i++){
		alph.push_back(c);
	} 
        grin = new KCheshire;
        grin->book.push_back(alph);
}

/* This constructor initiates the object with a
   input cipher key
 */
VCipher::VCipher(string key){
       //        if (!is_valid_page(pg_one)) {
        //      exit(EXIT_FAILURE);
        //}
	//
	string finalStr = "";
	int len = 0;

        grin = new KCheshire;

	
        for(int i=0; key[i] != '\0'; i++){
                if(key[i] == ' '){
                        cerr << "Invalid Running key: " << key << endl;
                        exit(EXIT_FAILURE);
		}else{
        	
		key[i] = LOWER_CASE(key[i]);
		len++;
		}
	}
	
	int counter = 0;
	for (unsigned int i = 0; i < MAX_LENGTH; i++){
		
		if (counter == len) {
			counter = 0;
		}
		
		finalStr.push_back(key[counter]);
		counter ++;
	}


        grin->book.push_back(finalStr);

}

/* Destructor
 */
VCipher::~VCipher(){
}


