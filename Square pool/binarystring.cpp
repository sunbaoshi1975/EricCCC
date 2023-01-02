// bitset::count
#include <iostream>       // std::cout
#include <bitset>         // std::bitset

using namespace std;

int main () {
    char str[20]; scanf("%[0-1]", str);
    bitset<8> foo (str);

    std::cout << foo << " has ";
    std::cout << foo.count() << " ones and ";
    std::cout << (foo.size()-foo.count()) << " zeros.\n";

    return 0;
}