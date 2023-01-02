#include <iostream>
#include <cstring>

using namespace std;

#define TYPES       3

int count[TYPES] = {0};
char names[TYPES][20] = {"alphabet", "digit", "special character"};

void OutputResult(const int type);
int isvowel(int _c);
int main() {
    string str = "Hello Eric Sun 2011";
    //getline(cin, str);
   
    for(char ch : str) {
        if(isalpha(ch)) count[0]++;
        else if(isdigit(ch)) count[1]++;
        else count[2]++;
    }

    for(int i = 0; i < TYPES; i++) {
        OutputResult(i);
    }

    int alpha = 0;
	int vowel = 0;
	for(char ch : str) {
        if(isalpha(ch)) {
			alpha++;
            // convert to lower case and call isvowel()
			if(isvowel(tolower(ch))) vowel++;
		}
    }    
}

void OutputResult(const int type) {
    printf("The number of %s is %d\r\n", names[type], count[type]);
}

int isvowel(int _c) {
    const char vowels[] = "aeiou";
    for(char ch : vowels) {
        if(_c == ch) return 1;
    }
    return 0;
}