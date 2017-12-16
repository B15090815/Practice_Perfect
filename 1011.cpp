#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int k=0;
    int a[1001];
    a[1] = 1;
    a[2] = 2;
    for(int i=3;i<=n;i++)
    {
        a[i] = 1;
        for(int j=1;j<=i/2;j++)
        {
            a[i] = a[i] + a[j];
        }
    }
    cout<<a[n];
    return 0;
}
