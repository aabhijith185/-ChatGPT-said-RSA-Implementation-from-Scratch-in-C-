#ifndef HELPER_H_
#define HELPER_H_

#include<vector>
#include<string>
#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
using namespace std;

vector<unsigned> ascii_to_int(const string& message);
string int_to_ascii(const vector<unsigned>& numeric_message);
unsigned modExp(unsigned base,unsigned exp,unsigned mod);
void print_encrypted_text(vector<unsigned>& vec);


#endif
