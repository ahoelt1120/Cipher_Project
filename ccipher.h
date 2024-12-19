#ifndef CCIPHER_H_
#define CCIPHER_H_
#include "cipher.h"

using namespace std;

/* A class that implements a
   Caesar cipher class. It 
   inherits the Cipher class */
// Each of these files contain the classes you need to implement
// You can define the class's structure
// Format for this in pictures at very top


class CCipher : public Cipher{ 
	// private params: add a new cheshire smile
	// public: constructors, destructors, etc.
	public:
    		CCipher();
   		CCipher(int shift);
    		~CCipher();
};


/* Helper function headers 
 */

void rotate_string(string& in_str, int rot);
#endif

