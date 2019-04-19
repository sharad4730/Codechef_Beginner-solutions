#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count=n;
    int j=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            count-=j;
            j=1;
        }
        else
            j++;
    }
    cout<<count;
    return 0;
}
