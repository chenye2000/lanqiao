#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int convert(string s)
{
    int d=0;
    if (s.size() != 8)
        d = s[11] - '0';
   return ((s[0]-'0')*10 + (s[1]-'0') + 24*d)*3600 + ((s[3]-'0')*10 + (s[4]-'0'))*60 + (s[6]-'0')*10 + (s[7]-'0');

}

int* strf(int s)
{
    int *a = new int [3];
    a[0] = s / 3600;
    s = s % 3600;
    a[1] = s / 60;
    a[2] = s % 60;
    return a;
}

int main()
{
    int n,i;
    string s;
    cin >> n;
    string *t = new string [4*n];
    int * sec = new int [4*n];
    int**a = new int* [n];
    for(i=0;i<n;i++)
        a[i] = new int [3];
    getchar();
    for(i=0;i<2*n;i++)
    {
        getline(cin,s);
        t[2*i]=s.substr(0,8);
        t[2*i+1]=s.substr(9);
        sec[2*i] = convert(t[2*i]);
        sec[2*i+1] = convert(t[2*i+1]);
    }
    for(i=0;i<n;i++)
    {
        int temp = (sec[i*4+1]-sec[i*4]+sec[i*4+3]-sec[i*4+2])/2;
        if (temp<0)
            temp = -1*temp;
        a[i] = strf(temp);
    }
    for(i=0;i<n;i++)
        printf("%02d:%02d:%02d\n",a[i][0],a[i][1],a[i][2]);
    return 0;
}
