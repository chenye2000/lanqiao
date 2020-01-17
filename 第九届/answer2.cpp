#include <iostream>

using namespace std;

int main()
{
    // 20世纪正好25个闰年，1901.01.01 星期二  Excel + 系统日期都可以获得
    int days = 25*366+75*365;
    cout << (days-1)/7 << endl;  // 5217
    return 0;
}
