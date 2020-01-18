#include <iostream>

using namespace std;

int update(int ***d,int *a,int e,int f,int g) // 更新伤害值，若有爆炸的战舰返回1，否则返回0
{
    if (a[0] > e || a[2] > f || a[4] > g)
        return 0;
    if (a[1]>e)
        a[1]=e;
    if(a[3]>f)
        a[3]=f;
    if (a[5]>g)
        a[5]=g;
    int i,j,k;
    for(i=a[0]-1; i<a[1]; i++)
        for(j=a[2]-1; j<a[3]; j++)
            for(k=a[4]-1; k<a[5]; k++)
            {
                d[i][j][k] = d[i][j][k] - a[6];
                if(d[i][j][k]<0)
                    return 1;
            }
    return 0;
}


int main()
{
    int a,b,c,m,i,j,k;
    cin >> a >> b >> c >> m;
    int **att = new int* [m];
    for(i=0; i<m; i++)
        att[i] = new int [7];
    int ***d = new int ** [a];
    for(i=0; i<a; i++)
        d[i] = new int * [b];
    for(i=0; i<a; i++)
        for(j=0; j<b; j++)
            d[i][j]=new int [c];
    for(i=0; i<a; i++)
        for(j=0; j<b; j++)
            for(k=0; k<c; k++)
                cin >> d[i][j][k];
    for(i=0; i<m; i++)
        for(j=0; j<7; j++)
            cin >> att[i][j];
    for(i=0;i<m;i++)
    {
        if(update(d,att[i],a,b,c))
            break;
    }
    cout << i+1 << endl;
}
