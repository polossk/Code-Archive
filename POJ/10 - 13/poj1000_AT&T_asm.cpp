#include <cstdio>
int main()
{
    int a = 0, b = 0, c = 0;
    while (~scanf("%d%d", &a, &b))
    {
        __asm__ __volatile__
        (
            "movl %1, %%eax;\n\t"\
            "movl %2, %%edx;\n\t"\
            "add %%edx, %%eax; \n\t"\
            "movl %%eax, %0; \n\t"\
            :"=m"(c)              // output
            :"r"(a), "r"(b)       // input
            :"eax", "edx"
        );
        printf("%d\n", c);
    }
    return 0;
}
