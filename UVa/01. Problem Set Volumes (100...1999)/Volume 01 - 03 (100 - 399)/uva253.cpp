/****
	*@PoloShen
	*Title:UVa 253
	*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct cube{
    char number[7];
    cube(){
        for (int i = 0; i < 6; ++i) number[i] = 0;
    }
    void rot_r(){
        char temp[6];
        for (int i = 0; i < 6; ++i) temp[i] = number[i];
        number[1] = temp[2]; number[2] = temp[4];
        number[3] = temp[1]; number[4] = temp[3];
    }
    void rot_u(){
        char temp[6];
        for (int i = 0; i < 6; ++i) temp[i] = number[i];
        number[0] = temp[1]; number[1] = temp[5];
        number[4] = temp[0]; number[5] = temp[4];
    }
    void rot_s(){
        char temp[6];
        for (int i = 0; i < 6; ++i) temp[i] = number[i];
        number[0] = temp[3]; number[2] = temp[0];
        number[3] = temp[5]; number[5] = temp[2];
    }
    friend bool operator==(const cube& a, const cube& b){
        for (int i = 0; i < 6; i++)
            if (a.number[i] != b.number[i]) return 0;
        return 1;
    }
};

bool checkface(cube f, cube modo){
    for (int i = 1; i <= 4; i++){
        if (f == modo) return 1;
        else f.rot_r();
    }
    for (int i = 1; i <= 4; i++){
        if (f == modo) return 1;
        else f.rot_u();
    }
    for (int i = 1; i <= 4; i++){
        if (f == modo) return 1;
        else f.rot_s();
    }
    return 0;
}

bool check(cube c, cube modo){
    cube face[6] = {c, c, c, c, c, c};
    face[1].rot_r();
    face[2].rot_u();
    face[3].rot_u(); face[3].rot_u();
    face[4].rot_u(); face[4].rot_u(); face[4].rot_u();
    face[5].rot_r(); face[5].rot_r(); face[5].rot_r();
    for (int i = 0; i < 6; i++){
        bool flag = checkface(face[i], modo);
        if (flag) return 1;
    }
    return 0;
}

void cubegenerate(string s,cube& a,cube& b){
    for (int i = 0; i < 12; i++){
        if (i < 6) a.number[i] = s[i];
        else b.number[i % 6] = s[i];
    }
}

void solve(string s){
    cube test, modo;
    cubegenerate(s, test, modo);
    if (check(test, modo)) printf("TRUE\n");
    else printf("FALSE\n");
}

int main(){
    string s;
    while (cin >> s) solve(s);
    return 0;
}