#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int place1  =  0, place2  =  1;
void drop(int num, int wash[])
{
    if (num != 0)
	{
        printf("DROP %d %d\n", place1 + 2, num);
        wash[place1]  = wash[place1] + num;
    }
}
void take(int num, int wash[])
{
    if (num != 0)
        printf("TAKE %d %d\n", place2, num);
    wash[place2] = wash[place2] - num;
}
void move(int wash[]){
    if (wash[place1] != 0)
        printf ("MOVE %d->%d %d\n", place1 + 2, place2, wash[place1]);
    wash[place2] = wash[place2] + wash[place1];
    wash[place1] = 0;
}
int main(){
    int wash[2];
    char str[6];
    int total, num, temp, flag = 0;
    while (cin >> num && num)
	{
        if (flag++) printf ("\n");
        wash[0] = 0; wash[1] = 0;
        while (num--)
		{
            cin >> str >> total;
            if (str[0] == 'D') drop(total, wash);
            else
			{
                temp = min(wash[place2], total);
                take(temp, wash);
                total = total - temp;
                if (total > 0){ move(wash); take(total, wash); }
            }
        }
    }
    return 0;
}