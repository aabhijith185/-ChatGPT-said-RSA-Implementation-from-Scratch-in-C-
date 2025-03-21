#include"Helper.h"
/* Function to transform text into a numerical format for encryption */
vector<unsigned> ascii_to_int(const string& message)
{
	vector<unsigned> numeric_message;
	for(char c : message)
	{
		numeric_message.push_back(static_cast<int>(c));
	}

	return numeric_message;
}

//Function to convert decrypted numerical input to text
string int_to_ascii(const vector<unsigned>& numeric_message)
{
	string message;

	for(auto i :  numeric_message)
	{
		message += static_cast<char>(i);
	}

	return message;
}
/* Calculates modular exponent by "exponentiation by squaring"*/
unsigned modExp(unsigned base,unsigned exp,unsigned mod)
{
	unsigned result =1;
	while(exp>0)
	{
		//if exp is odd,multiply result with current base and take modulus
		if(exp%2 == 1)
		{
			result = (result*base)%mod;
		}
		//square the base & take modulus to avoid overflow in the next iteration
		base = (base*base)%mod;

		//exponent halving
		exp = exp>>1;
	}

	return result;
}
//Print encrypted text
void print_encrypted_text(vector<unsigned>& vec)
{
	for(auto i : vec)
	{
		cout<<i<<"";
	}
	cout<<endl;
}
