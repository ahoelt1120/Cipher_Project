#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"


// -------------------------------------------------------
// Caesar Cipher implementation
// Implement here
//
/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
    	string cipher_alpha;
};


// -------------------------------------------------------
// Caesar cipher implementation
/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
CCipher::CCipher()
{
   smile = new CipherCheshire;
   smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";

}

/* This constructcor initiates the object with a
   input cipher key
 */
CCipher::CCipher(int shift)
{
    if (shift >= 0){
        smile = new CipherCheshire;
	string c_alph = "abcdefghijklmnopqrstuvwxyz";
	int rotate_value = shift % 26;
	rotate_string(c_alph, rotate_value);
        smile->cipher_alpha = c_alph;
    }else{
    cerr << "Error: Caesar cipher is less than 0" << endl;
    exit(EXIT_FAILURE);
    }
}
/* Destructor
 */
CCipher::~CCipher()
{
    // Implemented in cipher.cc
}



// -------------------------------------------------------


// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{	
    reverse(in_str.begin(), in_str.begin() + rot);
    reverse(in_str.begin() + rot, in_str.end());
    reverse(in_str.begin(), in_str.end());

    
}
