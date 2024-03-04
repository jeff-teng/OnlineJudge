#include <bits/stdc++.h>

using namespace std;


// 读取字符，过滤换行
char readchar() {
    char c = getchar();

    while (c == '\n') {
        c = getchar();
    }

    return c;
}


// 读取并记录编码
bool readcodes(char table[8][1 << 8]) {
    // 位数，数字
    int len = 1, v = 0;

    // 读取字符
    while (char c = getchar()) {
        // 文件结束
        if (c == EOF) {
            return false;
        }

        // 换行符
        if (c == '\n') {
            break;
        }

        // 记录编码
        table[len][v] = c;

        // 位数增加
        if (++v == (1 << len) - 1) {
            v = 0;
            len++;
        }
    }

    return true;
}


// 根据指定长度读取整数
int readint(int len) {
    int v = 0;

    while (len--) {
        v = (v << 1) + readchar() - '0';
    }

    return v;
}


int main() {
    // 编码表
    char table[8][1 << 8];

    // 循环读取记录编码
    while (readcodes(table)) {
        // 读取编码长度
        while (int len = readint(3)) {
            // 读取并输出字符
            for (int v = readint(len); v != (1 << len) - 1; v = readint(len)) {
                putchar(table[len][v]);
            }
        }
        putchar('\n');

        // 接收换行符
        getchar();
    }

    return 0;
}
