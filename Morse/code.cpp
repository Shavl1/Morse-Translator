#include "Morse.h"
#include <string>
using namespace std;

// Constructor
Morse::Morse(string text = "") : text(text) {};
// Setter-Getters
void Morse::setText(string st) { text = st; }
string Morse::getText() const { return text; }
string Morse::getMorse() const { return morse; }

void Morse::translate() {
	for (int i = 0; i < text.length(); i++) {
		// Checks if any character in string is part of alphabet, but uppercase
		if (text[i] >= 'A' && text[i] <= 'Z') {
			// Using ASCII table to get corresponding letter from Morse Alphabet
			morse += morseAlphabet[(text[i] - 65)];
			// Using Ternary Operator to make sure we won't end up with "/" in the end
			(i + 1 == text.length() || text[i + 1] == ' ') ? (morse += "") : (morse += " / ");
		}
		else if (text[i] >= 'a' && text[i] <= 'z') {
			morse += morseAlphabet[(text[i] - 97)];
			(i + 1 == text.length() || text[i + 1] == ' ') ? (morse += "") : (morse += " / ");
		}
		else if (text[i] >= '0' && text[i] <= '9') {
			morse += morseNumbers[text[i] - 48];
			(i + 1 == text.length() || text[i + 1] == ' ') ? (morse += "") : (morse += " / ");
		}
		else if (text[i] == ' ') {
			// If there is space between words, or numbers, to distinguish it I placed | between them
			morse += " | ";
		}
	}
}