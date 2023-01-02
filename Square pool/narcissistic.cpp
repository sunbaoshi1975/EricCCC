#include <iostream>

using namespace std;

int main() {
    int n = 0;

    // 0^3 to 9^3
    const int var[] = {0, 1, 8, 27, 64, 125, 216, 343, 512, 729};
    for(int i = 1; i <= 9; i++) {
        for(int j = 0; j <=9; j++) {
            for(int k = 0; k <=9; k++) {
                if(var[i] + var[j] +var[k] == i * 100 + j * 10 + k) {
                    cout << i << j << k << endl;
                    n++;
                }
            }
        }
    }
    cout << "total: " << n << endl;
    return 0;
}