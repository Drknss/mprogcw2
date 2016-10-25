#pragma once
#include "burst.h"
#include <iostream>
#include <string>

using namespace std;

void main() {
	burst *b = new burst();

	string test = "1001101010100100111011101010101010101110010101010100101010101010111101011100101001011001001001001010100100100111110111011101000";
	cout << test << endl;
	cout << b->addErrors(test) << endl;

	system("PAUSE");
}