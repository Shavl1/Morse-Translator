#pragma once
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
	Morse(string text);
	void setText(string st);
	string getText() const;
	string getMorse() const;
	void translate();
};