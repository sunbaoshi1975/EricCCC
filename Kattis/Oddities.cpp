#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[n];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        
    }
    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 == 1 || a[i] % 2 == -1)
        {
            cout << a[i] << " is odd" << endl;
        }
        else
        {
            cout << a[i] << " is even" << endl;
        }
    }
    return 0;
}