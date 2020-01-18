// 没有什么好的解法，只能排序后从大到小检查了
#include<iostream>
#include<algorithm>
using namespace std;

int *a;

int main()
{
	int n,i,j,k,l;
	cin >> n >> l;
	a = new int [n];
	for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            for(k=j+1;j<n;j++)
                if((a[i]+a[j]+a[k])%l==0)
                   {
                       cout << a[i]+a[j]+a[k] << endl;
                       return 0;
                   }
}
