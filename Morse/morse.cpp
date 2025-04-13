#include <iostream>
#include <string>
using namespace std;

class Morse {
	string text;
	string morse = "";
	string morseAlphabet[26] = {
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.","....",
		"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
		"--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
		"-.--", "--.."
	};
	string morseNumbers[10] = {
		"-----", ".----", "..---", "...--", "....-", ".....",
		"-....", "--...", "---..", "----."
	};
public:
	// Constructor
	Morse(string text = "") : text(text) {};
	void setText(string st) { text = st; }
	string getText() const { return text; }
	string getMorse() const { return morse; }
	void translate() {
		for (int i = 0; i < text.length(); i++) {
			// Checks if any character in string is part of alphabet, but uppercase
			if (text[i] >= 'A' && text[i] <= 'Z') {
				// Using ASCII table to get corresponding letter from Morse Alphabet
				morse += morseAlphabet[(text[i] - 65)];
				// Using Ternary Operator to make sure we won't end up with "/" in the end
				(i + 1 == text.length() || text[i+1] == ' ') ? (morse += "") : (morse += " / ");
			}
			else if (text[i] >= 'a' && text[i] <= 'z') {
				morse += morseAlphabet[(text[i] - 97)];
				(i + 1 == text.length() || text[i+1] == ' ') ? (morse += "") : (morse += " / ");
			}
			else if(text[i] >= '0' && text[i]<='9') {
				morse += morseNumbers[text[i] - 48];
				(i + 1 == text.length() || text[i + 1] == ' ') ? (morse += "") : (morse += " / ");
			}
			else if (text[i] == ' ') {
				// If there is space between words, or numbers, to distinguish it I placed | between them
				morse += " | ";
			}
		}
	}
};

int main() {
	string text;
	cout << "Enter the text: ";
	getline(cin, text);
	Morse morse(text);
	morse.translate();
	cout << "The text in Morse Alphabet is:\n" << morse.getMorse() << endl;
} 