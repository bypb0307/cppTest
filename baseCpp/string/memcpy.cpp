/*
 * @Author: chenq
 * @Date: 2020-12-08 16:24:21
 * @LastEditTime: 2020-12-08 22:06:10
 * @Descripttion: strcpy memcpy与memmove
 */

//memcpy与memmove都是对内存进行拷贝可以拷贝任何内容，而strcpy仅是对字符串进行操作
//memcpy与memmove拷贝多少是通过其第三个参数进行控制，而strcpy是当拷贝至'\0'停止
//memmove函数的功能同memcpy基本一致，但是当src区域和dst内存区域重叠时，memcpy可能会出现错误，而memmove能正确进行拷贝

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

char *strCpy(char *dest, const char *src)
{
    assert(dest != nullptr && src != nullptr);
    if (dest == src)
    {
        return dest;
    }
    char *p = dest;
    const char *q = src;
    while (*q != '\0')
    {
        *p++ = *q++;
    }
    *p = '\0';
    return dest;
}

void *memCpy(void *dest, const void *src, int n)
{
    assert(dest != nullptr && src != nullptr);
    if (dest == src)
    {
        return dest;
    }
    char *p1 = (char *)dest;
    const char *p2 = (char *)src;
    while (n-- > 0)
    {
        *p1++ = *p2++;
    }
    return dest;
}

void *memMove(void *dest, const void *src, int n)
{
    assert(dest != nullptr && src != nullptr);
    if (dest == src)
    {
        return dest;
    }
    char *p1 = (char *)dest;
    const char *p2 = (char *)src;
    if (p1 < p2)
    {
        while (n-- > 0)
        {
            *p1++ = *p2++;
        }
    }
    else
    {
        while (--n >= 0)
        {
            *(p1 + n) = *(p2 + n);
        }
    }
    return dest;
}

template <class T>
void printArr(T *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printArr<int>(a, 10);

    memMove(a + 1, a, 6 * sizeof(int));
    printArr<int>(a, 10);

    char s1[] = "abcdefghij";
    char s2[20] = {0};
    printArr<char>(s1, strlen(s1));
    printArr<char>(s2, strlen(s2));
    strCpy(s2, s1);
    printArr<char>(s1, strlen(s1));
    printArr<char>(s2, strlen(s2));

    return 0;
}