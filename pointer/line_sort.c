/**
 * 从stdin中输入多行字符串，对这些字符串按照字典序进行排序，输出到
 * stdout
 *
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define STDIN_FILENO 0
#define MAX_SIZE 10*(1<<10)  /* 10kB */
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *lineptr[], int a, int b);

int main(int argc, char *argv[])
{
    int nlines;
    nlines = readlines(lineptr, MAXLINES);

    if (nlines > 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    }

    return 0;
}

/**
 * 本想用mmap()方式把stdin映射成一块vm, 相当于把重定向到stdin的文件映射到内存里，
 * 但是tty的stdin不能mmap.
 */
int readlines(char *lineptr[], int nlines)
{
    int i = 0;
    size_t len = 0;

    /* getline()从stdin读取一行，getline会自动的分配一个buffer，不需要自己申请 */
    while (getline(&lineptr[i++], &len, stdin) != -1) {
        if (i >= nlines)
            break;
    }

    return i;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++) {
        /* 这里注意要使用strlen(lineptr[i]), 因为lineptr[i]是char*类型，如果用了sizeof会返回8 */
        fwrite(lineptr[i], sizeof(char), strlen(lineptr[i]), stdout);
    }
}

/**
 * 快排递归版(K&R)
 */
void qsort(char *lineptr[], int left, int right)
{
    if (left >= right)
        return;

    swap(lineptr, left, (left + right) / 2);
    int pivot = left;
    int i;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, i, left);
    }

    swap(lineptr, left, pivot);

    qsort(lineptr, left, pivot - 1);
    qsort(lineptr, pivot + 1, right);
}

/**
 * lineptr[a]指向lineptr[b]
 * lineptr[b]指向lineptr[a]
 */
void swap(char *lineptr[], int a, int b)
{
    char *tmp = lineptr[a];
    lineptr[a] = lineptr[b];
    lineptr[b] = tmp;
}


