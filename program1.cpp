#include <iostream>
#include <string>
#include <unordered_map> 
#include <algorithm>

using namespace std;

unordered_map<string, string> morseCode;

void buildMorseCode() {
	morseCode["A"] = ".-";
	morseCode["B"] = "-...";
	morseCode["C"] = "-.-.";
	morseCode["D"] = "-..";
	morseCode["E"] = ".";
	morseCode["F"] = "..-.";
	morseCode["G"] = "--.";
	morseCode["H"] = "....";
	morseCode["I"] = "..";
	morseCode["J"] = ".---";
	morseCode["K"] = "-.-";
	morseCode["L"] = ".-..";
	morseCode["M"] = "--";
	morseCode["N"] = "-.";
	morseCode["O"] = "---";
	morseCode["P"] = ".--.";
	morseCode["Q"] = "--.-";
	morseCode["R"] = ".-.";
	morseCode["S"] = "...";
	morseCode["T"] = "-";
	morseCode["U"] = "..-";
	morseCode["V"] = "...-";
	morseCode["W"] = ".--";
	morseCode["X"] = "-..-";
	morseCode["Y"] = "-.--";
	morseCode["Z"] = "--..";
	morseCode["0"] = "-----";
	morseCode["1"] = ".----";
	morseCode["2"] = "..---";
	morseCode["3"] = "...--";
	morseCode["4"] = "....-";
	morseCode["5"] = ".....";
	morseCode["6"] = "-....";
	morseCode["7"] = "--...";
	morseCode["8"] = "---..";
	morseCode["9"] = "----.";
}

string encrypt(string msg) {
	string encrypted = "";
	for (int i = 0; i < msg.length(); i++) {
		if (msg[i] != ' ') {
			string s(1, msg[i]);
			encrypted += morseCode[s] + " ";
		}
		else {
			encrypted += " ";
		}
	}
	return encrypted;
}

string decrypt(string msg) {
	string decrypted = "", let = "", s;
	int count = 0;
	msg += "";
	for (int i = 0; i < msg.length(); i++) {
		if (msg[i] != ' ') {
			count = 0;
			let += msg[i];
		}
		else {
			count++;
			if (count == 2) {	
				decrypted += " ";
			}
			else {
				for (auto it = morseCode.begin(); it != morseCode.end(); ++it) {
					if (it->second == let) {
						decrypted += it->first;
						break;
					}
				}
				let = "";
			}
		}
	}
	return decrypted;
}

int main() {
	string msg, eMsg, dMsg;
	buildMorseCode();
	cout << "Enter a string: ";
	getline(cin, msg);
	transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
	eMsg = encrypt(msg);
	dMsg = decrypt(eMsg);
	cout << "Encrypted string is: "<<eMsg<<endl;
	cout << "Decrypted string is: " << dMsg << endl;
	return 0;
}