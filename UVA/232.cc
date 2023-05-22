#include <bits/stdc++.h>

using namespace std;


int main() {
    int r, c;
    int puzzle_num = 0;

    while (scanf("%d", &r) != EOF && r != 0) {
        scanf("%d", &c);

        char m[10][11] = {0};
        int mark_num[10][11] = {0};

        // 输入字符矩阵
        for (int i = 0; i < r; ++i) {
            scanf("%s", m[i]);
        }

        // 标记字符矩阵
        int current_num = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                // 当前格子为白格，左边或者上边是非白格
                if (m[i][j] != '*'
                    && ((i == 0 || m[i - 1][j] == '*') || (j == 0 || m[i][j - 1] == '*'))) {
                    mark_num[i][j] = ++current_num;
                }
            }
        }

        // 输出结果
        if (puzzle_num > 0) {
            putchar('\n');
        }

        printf("puzzle #%d:\n", ++puzzle_num);

        // 输出横向结果
        printf("Across\n");

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                // 横向的开头
                if ((j == 0 || m[i][j - 1] == '*') && m[i][j] != '*') {
                    int j_copy = j;

                    printf("%3d.", mark_num[i][j_copy]);

                    // 输出字符
                    while (j_copy < c && m[i][j_copy] != '*') {
                        putchar(m[i][j_copy++]);
                    }

                    putchar('\n');
                }
            }
        }

        // 输出纵向结果
        printf("Down\n");

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                // 纵向的开头
                if ((i == 0 || m[i - 1][j] == '*') && m[i][j] != '*') {
                    int i_copy = i;

                    printf("%3d.", mark_num[i_copy][j]);

                    // 输出字符
                    while (i_copy < r && m[i_copy][j] != '*') {
                        putchar(m[i_copy++][j]);
                    }

                    putchar('\n');
                }
            }
        }
    }

    return 0;
}