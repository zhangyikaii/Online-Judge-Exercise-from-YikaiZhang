//// CPP program to illustrate Compute the parity of a 
//// number using XOR 
//#include <iostream>
//
//// Generating the look-up table while pre-processing 
//#define P2(n) n, n ^ 1, n ^ 1, n 
//#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n) 
//#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n) 
//#define LOOK_UP P6(0), P6(1), P6(1), P6(0) 
//
//// LOOK_UP is the macro expansion to generate the table 
//
//// Function to find the parity 
//int Parity(int num)
//{
//	unsigned int table[256] = { LOOK_UP };
//
//	// Number is considered to be of 32 bits 
//	int max = 16;
//
//	// Dividing the number into 8-bit 
//	// chunks while performing X-OR 
//	while (max >= 8) {
//		num = num ^ (num >> max);
//		max = max / 2;
//	}
//
//	// Masking the number with 0xff (11111111) 
//	// to produce valid 8-bit result 
//	return table[num & 0xff];
//}
//
//// Driver code 
//int main()
//{
//	unsigned int num = 1742346774;
//
//	// Result is 1 for odd parity, 0 for even parity 
//	bool result = Parity(num);
//
//	// Printing the desired result 
//	result ? std::cout << "Odd Parity" :
//		std::cout << "Even Parity";
//
//	return 0;
//}


// Program to find the parity of a given number 
#include <iostream>
using namespace std;

// Function to find the parity 
bool findParity(int result)
{
	int y = result ^ (result >> 1);
	y = y ^ (y >> 2);
	y = y ^ (y >> 4);
	y = y ^ (y >> 8);
	y = y ^ (y >> 16);

	// Rightmost bit of y holds the parity value 
	// if (y&1) is 1 then parity is odd else even 
	if (y & 1)
		return 1;
	return 0;
}

// Driver code 
int main()
{
	for (int i = 1; i <= 20; ++i) {
		cout << i << endl;
		(findParity(i) == 0) ? cout << "Even Parity\n" :
			cout << "Odd Parity\n";
	}

	/*(findParity(13) == 0) ? cout << "Even Parity\n" :
		cout << "Odd Parity\n";*/
	return 0;
}