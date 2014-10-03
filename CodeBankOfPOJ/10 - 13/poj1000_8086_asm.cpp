#include <cstdio>
int main()
{
    int a = 0, b = 0, c = 0;
    while (~scanf("%d%d", &a, &b))
    {
        __asm
        {
            pushad
            mov eax, a
            mov edx, b
            add eax, edx
            mov c, eax
        }
        printf("%d\n", c);
    }
    return 0;
}
