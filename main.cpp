#include <iostream>
#include "RSA.h"

using namespace std;
/*
 * Main function to test the RSA Cryptosystem.
 * This program prompts the user for two prime numbers, generates RSA keys,
 * encrypts a message, and then decrypts it.
 */
int main() {
    RSACryptosystem rsa;
    try {
    	// Prompt user for input primes
        rsa.prompter();
        // Check if the input values are prime
        rsa.primality_check();

        // Generate and display RSA key components
        cout << "n = " << rsa.calculate_n() << endl;
        cout << "phi(n) = " << rsa.calculate_phi() << endl;
        cout << "e = " << rsa.calculate_e() << endl;
        cout << "d = " << rsa.calculate_d() << endl;

        // Encrypt and display the message
        cout << "Encrypted message: " << rsa.encrypt() << endl;
        // Decrypt and display the message
        cout << "Decrypted message: " << rsa.decrypt() << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
