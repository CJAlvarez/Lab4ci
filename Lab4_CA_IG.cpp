#include <iostream>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

// Cifrado de César.
string getCesar(string);
// Cifrado de Vigenère.
string getVigenere(string, string);
// XOR.
void getXOR(string, string);
// Para encontrar el número del abecedario.
int getLetterNumber(char);
// Para encontrar la letra del abecedario.
char findLetter(int);

int main() {
	int option;
	string text, key;
	
	do {
	   cout << "Ingrese texto a cifrar: ";
		cin >> text;
		cout << "Ingrese palabra clave: ";
		cin >> key;

		cout << "Ingrese ejercicio a ejecutar: \n1) Cifrado de Vigenènere. \n2) Cifrado de César. \n3) Cifrado de XOR. \n4) Salir. \nVen y diviértete!... Punchis punchis!: ";
		cin >> option;

		if (option == 1) {
			cout << "Palabra final: " << getVigenere(key, text) << endl;
		} else if (option == 2) {
			cout << "Palabra final: " << getCesar(text) << endl;
		} else if (option == 3) {
			getXOR(key, text);
		}
	} while (option != 4);

	return 0;
}

string getVigenere(string key, string text) {
	stringstream word;
	char letterText, letterKey, letter;
	int COUNT = 0, value, numberKey, numberText;
	string finalWord;

	for(int i = 0; i < text.length(); i++) {
		if (COUNT >= key.length()) {
         COUNT = 0;
      }

		numberKey = getLetterNumber(key.at(COUNT));
		numberText = getLetterNumber(text.at(i));
		value = ((numberKey + numberText) % 26);
		letter = findLetter(value);

		word << letter;

		COUNT++;		
	}

	finalWord = word.str();

	return finalWord;
}

string getCesar(string text) {
	int number;
	int letter;
	int value;
	char character;
	string finalWord;
	stringstream word;

	cout << "Ingrese el número de desplazamiento: ";
	cin >> number;

	for(int i = 0; i < text.length(); i++) {
		letter = (int) text.at(i);
		character = (char) (letter + number);

		if ((letter + number >= 65 && letter + number < 90) || (letter + number >= 97 && letter + number < 122)) {
			character = (char) (letter + number);
		} else if (letter + number >= 90) {
			value = letter - 91;
			letter = 65 + number;
			character = (char) (letter + number);
		} else if (letter + number >= 122) {
			value = letter - 123;
			letter = 97 + value;
			character = (char) (letter + number);
		}

		if (letter != ' ') {
			word << character;
		} else {
			word << " ";
		}
	}

	finalWord = word.str();

	return finalWord;
}

void getXOR(string key, string text){
   int textSize = text.length();
   int keySize = key.length();
   int textArray [textSize];
   int keyArray [keySize];
   bitset <8> bitText[textSize];
   bitset <8> bitKey[keySize];

      /***** Text ******/
   // String to int[]
   for (int i = 0; i < textSize; i++){
      textArray[i] = text.at(i);
   }
   // int[] to bitset[]
   for (int i = 0; i < textSize; i++){
      bitText[i] = textArray[i];
   }

      /***** Key *****/
   // String to int[] 
   for (int i = 0; i < keySize; i++){
      keyArray[i] = key.at(i);
   }

   // int[] to bitset[]
   for (int i = 0; i < keySize; i++){
      bitKey[i] = keyArray[i];
   }

      /* Mix Text-Key*/
   bitset <8> filledBitKey[textSize];
   int counterKey = 0;

   for (int i = 0; i < textSize; i++){
      if (counterKey >= keySize){
         counterKey = 0;
      }
      filledBitKey[i] = bitKey[counterKey];
      counterKey++;
   }

   bitset <8> lastBitset[textSize];
   for (int i = 0; i < textSize; i++){
      lastBitset[i] = bitText[i] ^ filledBitKey[i];
//    cout << lastBitset[i] << " ";
   }
// cout << endl;

      /* bitset[] to int[] */
   for (int i = 0; i < textSize; i++){
      cout << lastBitset[i].to_ulong() << " ";
   }
   cout << endl;
}

char findLetter(int x) {
	switch (x) {
	   case 1:
        	return 'a';
      case 2:

                return 'b';

      case 3:

                return 'c';

      case 4:

                return 'd';

      case 5:

                return 'e';

            case 6:

                return 'f';

            case 7:

                return 'g';

            case 8:

                return 'h';

            case 9:

                return 'i';

            case 10:

                return 'j';

            case 11:

                return 'k';

            case 12:

                return 'l';

            case 13:

                return 'm';

            case 14:

                return 'n';

            case 15:

                return 'o';

            case 16:

                return 'p';

            case 17:

                return 'q';

            case 18:

                return 'r';

            case 19:

                return 's';

            case 20:

                return 't';

            case 21:

                return 'u';

            case 22:

                return 'v';

            case 23:

                return 'w';

            case 24:

                return 'x';

            case 25:

                return 'y';

            case 26:

                return 'z';
	}
}

int getLetterNumber(char letter) {
        switch (letter) {
            case 'a':

                return 1;


            case 'b':

                return 2;

            case 'c':

                return 3;

            case 'd':

                return 4;

            case 'e':

                return 5;

            case 'f':

                return 6;

            case 'g':

                return 7;

            case 'h':

                return 8;

            case 'i':

                return 9;

            case 'j':

                return 10;

            case 'k':

                return 11;

            case 'l':

                return 12;

            case 'm':

                return 13;

            case 'n':

                return 14;

            case 'o':

                return 15;

            case 'p':

                return 16;

            case 'q':

                return 17;

            case 'r':

                return 18;

            case 's':

                return 19;

            case 't':

                return 20;

            case 'u':

                return 21;

            case 'v':

                return 22;

            case 'w':

                return 23;

            case 'x':

                return 24;

            case 'y':

                return 25;

            case 'z':

                return 26;
	}
}
