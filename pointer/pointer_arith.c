/**
 * Demo of pointer arithmetic
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    /* p1, p2是指向char*的指针，这2个指针是有类型的，指向的类型是char*。
     * 指针跟一个整数相加，指针会向前步进sizeof(指向类型)个字节。假如
     * p1指向的地址为0x1234， p1 + 1就为0x1238。这就解释了为什么++argv
     * 会把argv移动到下一个参数，而不是第一个参数的第二个字符。
     *
     * */
    char **p1, **p2;
    p1 = argv;
    p2 = argv + 1;
    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);
    printf("p2 - p1 = %lu\n", p2 - p1);
    printf("(char*)p2 - (char*)p1 = %lu\n", (char*)p2 - (char*)p1);

    /* echo */
    while (--argc) {
        printf("%s\n", *++argv);
    }
    return 0;
}

