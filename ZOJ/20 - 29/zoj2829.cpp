#include <iostream>
#define Maxinum 100000
using namespace std;
int SolveSet[Maxinum];
void BuildSet(){
    int i=0;
    SolveSet[0]=3;
    const int a=3;const int b=5;
    int ka=2;int kb=1;
    int temp_a,temp_b;
    for(i=1;i<Maxinum;i++){
        temp_a=ka*a;
        temp_b=kb*b;
        if(temp_a<temp_b){SolveSet[i]=temp_a;ka++;}
        else if(temp_a>temp_b){SolveSet[i]=temp_b;kb++;}
        else if(temp_a==temp_b){SolveSet[i]=temp_b;ka++;kb++;}

    }
}

int main()
{
    BuildSet();
    int pos;
    while(cin>>pos){
        cout<<SolveSet[pos-1]<<endl;
    }
    return 0;
}