/*
* This file contains the implementation of the RSA algorithm, including key generation,
* encryption, and decryption. The RSA algorithm is based on the difficulty of factoring
* large prime numbers.
*/

#include <stdexcept>
#include <numeric>
#include"RSA.h"


/*
 * Prompts the user to input two prime numbers.
 * This function reads two prime numbers `p` and `q` from user input.
 * These primes will be used to generate the RSA keys.
 */
void RSACryptosystem::prompter() {
    cout << "Please enter a prime number p: ";
    cin >> p;
    cout << "Please enter a prime number q: ";
    cin >> q;
}
/*
 * Checks primality of the inputs p& q
 * This function tests if `p` and `q` are prime numbers by checking their factors.
 * If either of them is non-prime, it throws a runtime error.
 */
void RSACryptosystem::primality_check() {
    vector<unsigned> p_factors;
    for (unsigned i = 2; i <= static_cast<unsigned>(sqrt(static_cast<double>(p))); i++)
    {
    	if(p%i == 0)
    	{
    		p_factors.push_back(i);
    		p_factors.push_back(p/i);
    	}
    }
    vector<unsigned> q_factors;
    for (unsigned i = 2; i <= static_cast<unsigned>(sqrt(static_cast<double>(q))); i++)
    {
     	if(q%i == 0)
     	{
     		q_factors.push_back(i);
     		q_factors.push_back(q/i);
     	}
     }

    if(p_factors.size() != 0 || q_factors.size() != 0)
    {
    	throw(runtime_error("non prime input"));
    }
}
/*   Calculates the value of `n = p * q`           */
unsigned RSACryptosystem::calculate_n() {
    n = p * q;
    return n;
}
/* Calculates Euler's totient function phi(n) = (p - 1) * (q - 1)*/
unsigned RSACryptosystem::calculate_phi() {
    phi_n = (p - 1) * (q - 1);
    return phi_n;
}
/*.
 * Calculates the public key exponent `e`
 * The value of `e` is calculated such that 1 < `e` < φ(n) and gcd(e, φ(n)) = 1.
 */
unsigned RSACryptosystem::calculate_e() {

    unsigned i =2;
    while(gcd(i,phi_n) != 1)
    	i++;
    e = i;

    if(e >= phi_n)
    	throw(runtime_error("e is greater than or equal to phi_n"));
    return e;
}
/*
 * Calculates the private key exponent `d`
 * The value of `d` satisfies the condition `(e * d) mod φ(n) = 1`
 */
unsigned RSACryptosystem::calculate_d() {
   /* (e*d)mod phi_n =1*/
	unsigned k =1;

	while(((k*phi_n)+1)%e != 0)
		k++;
	d = ((k*phi_n)+1)/e;
	return d;
}
/*
 * Encrypts the input message using RSA encryption.
 * The ciphertext is computed as:
 * `cipher_text = (secret_message^e) mod n`
 */
vector<unsigned> RSACryptosystem::encrypt(const string& message)
{
	//convert the input text to numerical format for encryption
	vector<unsigned> numeric_message = ascii_to_int(message);

	for(unsigned num : numeric_message)
	{
		if(num >= n)
		{
			throw runtime_error("Message character should be smaller than n");
		}
		encrypted_message.push_back(modExp(num,e,n));
	}

	return encrypted_message;
}
/*
 * Decrypts the ciphertext using RSA decryption.
 * decrypted_text = (cipher_text^d) mod n
 */
string RSACryptosystem::decrypt(const vector<unsigned>& ciphertext) {
	vector<unsigned> decrypted_array;

	for(auto cipher:ciphertext)
	{
		decrypted_array.push_back(modExp(cipher,d,n));
	}

	decrypted_text = int_to_ascii(decrypted_array);
	return decrypted_text;
}
