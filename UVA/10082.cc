#include <bits/stdc++.h>

using namespace std;


int main() {
    // 字符串常量
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    // 读入字符
    char c;

    // 读入数据
    while((c = getchar()) != EOF) {
        // 查找字符串
        char *p = strchr(s, c);

        // 找到
        if (p == NULL) {
            putchar(c);
        } else {
            putchar(*(p - 1));
        }
    }

    return 0;
}