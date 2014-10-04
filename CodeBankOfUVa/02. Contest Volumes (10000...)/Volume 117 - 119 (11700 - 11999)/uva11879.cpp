void solve(BigInt a){
    BigInt b = a % 10;
    a = a / 10;
    b = b * 5;
    if (a < b) a = b - a;
    else a = a - b;
    a = a % 17;
    a = (a == 0)? printf("1\n"): printf("0\n");
}