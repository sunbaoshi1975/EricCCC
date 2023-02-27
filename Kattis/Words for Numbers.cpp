#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

const string ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
                       "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
const string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

vector<string> SplitWords(string s) {
    istringstream iss(s);
    vector<std::string> v;
    while(iss >> s) {
        v.push_back(s);
    }
    return v;
}

int processLine(string line);
int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Words for Numbers.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    string line;
    while(getline(std::cin, line)) {
        if(!processLine(line)) break;
        cout << endl;
    }
    return 0;
}

bool IsNumber(string word) {
    return((word.find_first_not_of("0123456789") == string::npos));
}

string SpellNumber(int num, bool first) {
    string s = "";
    if(num <= 99) { 
        if(num <= 20) {
            s = ones[num];
        } else {
            s = tens[num / 10];
            if(num % 10 > 0) {
                s += "-";
                s += ones[num % 10];
            }
        }
        if(first) {
            s[0] -= ('a' - 'A');
        }
    }
    return s;
}

int processLine(string line) {
    vector<string> words;
    words = SplitWords(line);
    string s;
    for(int i = 0; i < words.size(); i++) {
        if(IsNumber(words[i])) {
            s = SpellNumber(atoi(words[i].c_str()), i == 0);
            if(s.size() > 0) cout << s << " ";
        } else {
            cout << words[i] << " ";
        }
    }
    return(words.size());
}