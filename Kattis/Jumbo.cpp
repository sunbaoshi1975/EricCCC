#include <iostream>
using namespace std;

int main()
{
    int n, arr[200], sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sum -= n - 1;
    cout << sum;
}