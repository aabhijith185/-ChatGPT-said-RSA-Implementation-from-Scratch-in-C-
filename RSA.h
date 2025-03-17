#ifndef RSA_H_
#define RSA_H_

#include <boost/multiprecision/cpp_int.hpp>
#include <vector>
#include <string>

using boost::multiprecision::cpp_int;

class RSACryptosystem {
public:
    unsigned p;//a prime input
    unsigned q;//a prime input
    unsigned n;//n = p*q
    unsigned phi_n;//(p-1)*(q-1)
    unsigned e;//1<e<phi_n;  e and phi_n are coprimes
    unsigned d;//(e*d)mod phi_n =1
    unsigned secret_message;

    cpp_int cipher_text;
    cpp_int decrypted_text;

    void prompter();
    void primality_check();
    unsigned calculate_n();
    unsigned calculate_phi();
    unsigned calculate_e();
    unsigned calculate_d();

    cpp_int encrypt();
    cpp_int decrypt();
};

#endif /* RSA_H_ */
