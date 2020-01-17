#include<iostream>
#include<string>
using namespace std;


// 用大整数乘法暴力求解乘积结果，共31位0
string muti(string as,string bs)
{
    string result;
    int an[400]={0},bn[400]={0},c[1000]={0},aLen,bLen,cLen;
    aLen=as.length();
    bLen=bs.length();

    //倒序存储到整型数组中
    for(int i=0;i<aLen;i++){
        an[aLen-i-1]=as[i]-'0';
    }

    for(int i=0;i<bLen;i++){
        bn[bLen-i-1]=bs[i]-'0';
    }

    //对a b 数组进行计算 
    for(int i=0;i<bLen;i++){
        for(int j=0;j<aLen;j++){
            c[i+j] = c[i+j] + an[j]*bn[i];
            c[i+j+1] = c[i+j+1] + c[i+j]/10;
            c[i+j] = c[i+j] % 10;
        }
    }

    cLen=aLen+bLen;

    //删除可能出现的前导0
    while(c[cLen-1]==0  && cLen>1){
        cLen--;
    }

    for(int i=cLen-1;i>=0;i--){
        result = result + (char)(c[i]+'0');
    }
    return result;

}

int main(){
    string result = "1";
    int i;
    string *numbers = new string [100];
    for(i=0;i<100;i++)
        cin >> numbers[i];

    for(i=0;i<100;i++)
    {
        result = muti(result,numbers[i]);
    }
    cout << endl << result << endl;
    // 结果是112142221918653666702449201125076321480831896827506427440731023870278025729017605653056978504625081950967446934475613782859722081655293509714201067451491601144000940085173776751705443818861349991600968912829674368417898694508188364854988187881792613763161458365648071883922054736261940944120399031297726871056069331318210560000000000000000000000000000000
    return 0;
}
