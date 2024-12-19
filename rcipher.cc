#include <string>
#include <iostream>
#include "rcipher.h"

// -------------------------------------------------------
// ROT13 Cipher implementation
// -------------------------------------------------------
//
/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
        string cipher_alpha;
};


/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
RCipher::RCipher()
{	
   	smile = new CipherCheshire;
        string c_alph = "abcdefghijklmnopqrstuvwxyz";
        int rotate_value = 13 % 26;
        rotate_string(c_alph, rotate_value);
        smile->cipher_alpha = c_alph;
}

/* Destructor
 */
RCipher::~RCipher()
{
    // Implemented in cipher.cc
}

