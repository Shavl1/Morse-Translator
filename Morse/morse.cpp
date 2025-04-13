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
public:
	Morse(string text = "") : text(text) {};
	void setText(string st) { text = st; }
	string getText() const { return text; }
	string getMorse() const { return morse; }
	void translate() {
		int length = text.length();
		for (int i = 0; i < length; i++) {
			if (text[i] >= 'A' && text[i] <= 'Z') {
				morse += morseAlphabet[(text[i] - 65)];
				(i + 1 == length || text[i+1] == ' ') ? (morse += "") : (morse += " / ");
			}
			else if (text[i] >= 'a' && text[i] <= 'z') {
				morse += morseAlphabet[(text[i] - 97)];
				(i + 1 == length || text[i+1] == ' ') ? (morse += "") : (morse += " / ");
			}
			else if (text[i] == ' ') {
				morse += " | ";
			}
		}
	}
};

int main() {
	Morse morse;
	string text;
	cout << "Enter the text: ";
	getline(cin, text);
	morse.setText(text);
	morse.translate();
	cout << morse.getMorse();
} 