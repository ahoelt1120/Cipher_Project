#include "cipher.h"

/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

/* This function checks the cipher alphabet
   to make sure it's valid
 */
bool is_valid_alpha(string alpha);


// -------------------------------------------------------
// Cipher implementation
/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
Cipher::Cipher()
{
   smile = new CipherCheshire;
   smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
         
}

/* This constructor initiates the object with a
   input cipher key
 */
Cipher::Cipher(string cipher_alpha)
{
    // Checking if the alphabet is valid
    for (int i = 0; cipher_alpha[i] != 0; i++){
    if (!(is_valid_alpha(cipher_alpha)) && cipher_alpha[i] != ' '){
   	cerr << "Invalid cipher alphabet/key: " << cipher_alpha << endl;
    	exit(EXIT_FAILURE);}
    }
	smile = new CipherCheshire;
        smile->cipher_alpha = cipher_alpha;
}


/* Destructor
 */
Cipher::~Cipher()
{
    // Freeing memeory
    delete smile;
}

/* This member function encrypts the input text 
   using the intialized cipher key
 */
string Cipher::encrypt(string raw)
{
    cout << "Encrypting...";
    
    string retStr;
    
    int pos = 0;
    string temp;

    string reg_alph = "abcdefghijklmnopqrstuvwxyz";

    // Looping through the string and substituting
    // the letter in the string with the letter in 
    // the cipher alphabet
    //
    for(int i = 0; raw[i] != '\0'; i++){
	if(isupper(raw[i])){
		temp = LOWER_CASE(raw[i]);
		pos = find_pos(reg_alph, temp[0]);
        	retStr.push_back(UPPER_CASE(smile->cipher_alpha[pos]));		
	}else if (isspace(raw[i])){
		retStr.push_back(raw[i]); 
	}else{ 
	pos = find_pos(reg_alph, raw[i]);
	retStr.push_back(smile->cipher_alpha[pos]);
	
	}
    }


    cout << "Done" << endl;

    return retStr;
}


/* This member function decrypts the input text 
   using the intialized cipher key
 */
string Cipher::decrypt(string enc)
{
    string retStr;
    cout << "Decrypting...";
    

    int pos = 0;
    string temp;

    string reg_alph = "abcdefghijklmnopqrstuvwxyz";

    // Creating the decrypted string with
    // the cipher alphabet
    for(int i = 0; enc[i] != '\0'; i++){
	if(isupper(enc[i])){
                temp = LOWER_CASE(enc[i]);
                pos = find_pos(smile->cipher_alpha, temp[i]);
                retStr.push_back(UPPER_CASE(reg_alph[pos]));
        }else if (isspace(enc[i])){
		retStr.push_back(enc[i]);
	}else{
        pos = find_pos(smile->cipher_alpha, enc[i]);
        retStr.push_back(reg_alph[pos]);
    
	}
	}

	//cout << retStr <<endl;

    cout << "Done" << endl;
    
    return retStr;

}
// -------------------------------------------------------


//  Helper functions 
/* Find the character c's position in the cipher alphabet/key
 */
unsigned int find_pos(string alpha, char c)
{
    unsigned int pos = 0;
	
    for(int i = 0; alpha[i] != '\0'; i++){
	if (alpha[i] == c){
		pos = i;
		break;
	}
		}

    return pos;
}

/* Make sure the cipher alphabet is valid - 
   a) it must contain every letter in the alphabet 
   b) it must contain only one of each letter 
   c) it must be all lower case letters 
   ALL of the above conditions must be met for the text to be a valid
   cipher alphabet.
 */
bool is_valid_alpha(string alpha)
{
    bool is_valid = true;
    if(alpha.size() != ALPHABET_SIZE) {
        is_valid = false; 
    } else {
        unsigned int letter_exists[ALPHABET_SIZE];
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            letter_exists[i] = 0;
        }
        for(unsigned int i = 0; i < alpha.size(); i++) {
            char c = alpha[i];
            if(!((c >= 'a') && (c <= 'z'))) {
                is_valid = false;
            } else {
                letter_exists[(c - 'a')]++;
            }
        }
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            if(letter_exists[i] != 1) {
                is_valid = false;
            }
        }
    }

    return is_valid;
}
