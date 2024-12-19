#include <string>
#include <iostream>
#include <vector>
#include "ccipher.h"
#include "kcipher.h"




/* Helper function definitions
 */

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

/* Running key smile implementation.
   It only contains the cipher alphabet
 */
struct KCipher::KCheshire {
	vector<string>book;
	unsigned int page = 0;
};


/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
KCipher::KCipher(){

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
KCipher::KCipher(string pg_one){
	
	if(pg_one.length() == 0){
                cerr << "Invalid Running key: " << pg_one << endl;
                exit(EXIT_FAILURE);
        }

    	grin = new KCheshire;

	for(int i=0; pg_one[i] != '\0'; i++){
		
		if ((!(isalpha(pg_one[i]))) && pg_one[i] != ' '){
                        cerr << "Invalid Running key: " << pg_one << endl;
                        exit(EXIT_FAILURE);

                }
     		if (pg_one[i] == ' '){ 
			pg_one.erase(i,1);}
		}

    	grin->book.push_back(pg_one);

}

/* This member function adds a key
   to the vector book
 */
void KCipher::add_key(string page){
	
	if(page.length() == 0){
		cerr << "Invalid Running key: " << page << endl;
                        exit(EXIT_FAILURE);
	}

	for(int i=0; page[i] != '\0'; i++){
		if ((!(isalpha(page[i]))) && page[i] != ' '){
                        cerr << "Invalid Running key: " << page << endl;
                        exit(EXIT_FAILURE);

                }
	}
	for(int i=0; page[i] != '\0'; i++){
		if(page[i] == ' '){
                        page.erase(i,1);}
        }
	grin->book.push_back(page);
}

/* This member function sets the page
   id to a number
 */
void KCipher::set_id(unsigned int id){
	
	if ((grin->book).size() < id){
		cerr << "Warning: invalid id: " << id << endl;
    		exit(EXIT_FAILURE);
	}

	grin->page = id;
	

}

/* This member function encrypts the input text
   using the vector book
 */
string KCipher::encrypt(string raw){

	// rotate to letter in string
	// find position of letter in vector in alphabet
	cout << "Encrypting..." << endl;
	string retStr;	
	string enc_alph;
	int raw_pos;
	int pg_pos;
	string page_str = grin->book[grin->page];


	int cnt = 0;
	for(int i = 0; raw[i] != '\0'; i++){
		if (raw[i] != ' '){
		enc_alph = "abcdefghijklmnopqrstuvwxyz";
		if(isupper(raw[i])){
			raw[i] = LOWER_CASE(raw[i]);
			raw_pos = find_pos(enc_alph, raw[i]);
	                pg_pos = find_pos(enc_alph, page_str[cnt]);
        	        rotate_string(enc_alph, raw_pos);
                	retStr.push_back(UPPER_CASE(enc_alph[pg_pos]));
			cnt++;
		}else{
		raw_pos = find_pos(enc_alph, raw[i]);
		pg_pos = find_pos(enc_alph, page_str[cnt]);
		rotate_string(enc_alph, raw_pos);
		retStr.push_back(enc_alph[pg_pos]);
		cnt++;
		}
		}else{
			retStr.push_back(' ');
		}
	}
	cout << "Done" << endl;
	return retStr;

}

/* This member function decrypts the input text
   using the vector book
 */
string KCipher::decrypt(string enc){
	cout << "Decrypting..." << endl;
	string retStr;
	string norm_alph = "abcdefghijklmnopqrstuvwxyz";
        string enc_alph;
        int enc_pos;
        int pg_pos;
	
	int cnt = 0;
	string page_str = grin->book[grin->page];
	for (int i = 0; enc[i] != '\0'; i++){
		if (enc[i] != ' '){
			 if(isupper(enc[i])){
				enc[i] = LOWER_CASE(enc[i]);
				enc_alph = "abcdefghijklmnopqrstuvwxyz";
		                pg_pos = find_pos(enc_alph, page_str[cnt]);
                		rotate_string(enc_alph, pg_pos);
                		enc_pos = find_pos(enc_alph, enc[i]);
                		retStr.push_back(UPPER_CASE(norm_alph[enc_pos]));
				cnt++;
			 }else{
		enc_alph = "abcdefghijklmnopqrstuvwxyz";
		pg_pos = find_pos(enc_alph, page_str[cnt]);
		rotate_string(enc_alph, pg_pos);
		enc_pos = find_pos(enc_alph, enc[i]);
		retStr.push_back(norm_alph[enc_pos]);
		cnt++;
		}}else{
			retStr.push_back(' ');
		}
	} 
	cout << "Done" << endl;
	return retStr;	
}

/* Destructor
 */
KCipher::~KCipher(){
	delete grin;
}



