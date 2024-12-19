#ifndef VCIPHER_H_
#define VCIPHER_H_
//#include "cipher.h"
#include "kcipher.h"

using namespace std;

/* A class that implements a
   Vigenere cipher class. It 
   inherts KCipher */



/* A class that implements a
   vigenere key cipher class. It 
   inherts class Cipher */
// 
class VCipher : public KCipher{

        public:
                VCipher();
                VCipher(string key);
                ~VCipher();
};

#endif


