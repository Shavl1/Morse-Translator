#include <iostream>
#include <string>
#include "Morse.h"
using namespace std;

int main() {
	string text;
	cout << "Enter the text: ";
	getline(cin, text);
	Morse morse(text);
	morse.translate();
	cout << "The text in Morse Alphabet is:\n" << morse.getMorse() << endl;
} 