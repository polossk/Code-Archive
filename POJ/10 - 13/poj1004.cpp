#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double ave = 0, sum = 0, temp;
    for(int i = 0; i < 12; i++){
        cin >> temp;
        sum += temp;
    }
    ave = sum / 12.0;
    printf("$%.2lf", ave);
    return 0;
}