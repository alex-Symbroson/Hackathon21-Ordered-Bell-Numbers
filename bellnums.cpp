
#include <iostream>
#include <gmpxx.h>

using namespace std;

mpz_class *num0, *num1;

void bell_number(int n)
{
	mpz_class *num;
	num0[1] = 1;
	
	cout << "[" << (n > 1 ? "1, 1" : n ? "1" : "");
	
	for(int i=0; i<n-1; i++)
	{
		for(int k=1; k<i+2; k++)
			num1[k] = k * (num0[k-1] + num0[k]);

		num=num0; num0=num1; num1=num;

		mpz_class sum = 0;
		for(int k=1; k<=n; k++)
			sum += num1[k] = k * (num0[k-1] + num0[k]);
		cout << ", " << sum;
	}
	
	cout << "]\n";
}

int main (int argc, const char** argv)
{
	int n = 10;
	if(argc > 1) n = stoi(argv[1]);
	mpz_class _num0[n+1], _num1[n+1];
	num0=_num0; num1=_num1;
	bell_number(n);
}

