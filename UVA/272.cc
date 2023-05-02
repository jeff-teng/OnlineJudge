#include <bits/stdc++.h>

using namespace std;


int main() {
    // 左右引号标记
    bool left_quote = true;

    // 读入字符
    char c;

    // 读入数据
    while((c = getchar()) != EOF) {
        // 非引号
        if (c != '\"') {
            printf("%c", c);
        }
        // 左引号
        else if (left_quote) {
            printf("``");
            left_quote = !left_quote;
        }
        // 右引号
        else {
            printf("''");
            left_quote = !left_quote;
        }
    }

    return 0;
}