  #include <stdlib.h>
  #include <stdbool.h>
  #include <string.h>
  #include <ctype.h>

  #include "disemvowel.h"

  bool checkVowel(char C) {
	char c = tolower(C);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
        }
        return false;
  }	  

  int countConsonant (char *str) {
	int count = 0;
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (!checkVowel(str[i])) {
			count++;
		}
	}
	return count;
  }
	      
  char *disemvowel(char *str) {
	int length = strlen(str);
	int numConsonants = countConsonant(str);
	char *newStr = (char*) calloc(numConsonants + 1, sizeof(char));

	int newIndex = 0;
	for (int old = 0; old < length; old++) {
		if (!checkVowel(str[old])) {
			newStr[newIndex] = str[old];
			newIndex++;
		}
	}
	newStr[newIndex] = '\0';
  	return newStr;
  }
