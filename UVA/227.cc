#include <bits/stdc++.h>

using namespace std;


int main() {
    int puzzles_num = 0;
    char puzzles[5][6];

    while (scanf("%[^\n]%*c", puzzles[0]) != EOF) {
        // 记录空格位置
        int x = 0, y = 0;

        // 终止游戏
        if (puzzles[0][0] == 'Z') {
            break;
        }

        // 继续输入
        for (int i = 1; i < 5; ++i) {
            scanf("%[^\n]%*c", puzzles[i]);
        }

        // 寻找空格位置
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (puzzles[i][j] == ' ') {
                    x = i;
                    y = j;
                }
            }
        }

        // 输入指令序列
        char c;

        bool no_config = false;

        // 根据指令移动
        while ((c = getchar()) != '0') {
            if (c == 'A' && x > 0) {
                swap(puzzles[x][y], puzzles[x - 1][y]);
                --x;
            } else if (c == 'B' && x < 4) {
                swap(puzzles[x][y], puzzles[x + 1][y]);
                ++x;
            } else if (c == 'L' && y > 0) {
                swap(puzzles[x][y], puzzles[x][y - 1]);
                --y;
            } else if (c == 'R' && y < 4) {
                swap(puzzles[x][y], puzzles[x][y + 1]);
                ++y;
            } else if (strchr("ABLR", c)) {
                no_config = true;
            }
        }

        // 接收额外的换行符
        getchar();

        // 输出结果
        if (puzzles_num > 0) {
            putchar('\n');
        }

        printf("Puzzle #%d:\n", ++puzzles_num);

        if (no_config) {
            printf("This puzzle has no final configuration.\n");
        } else {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (j > 0) {
                        putchar(' ');
                    }
                    putchar(puzzles[i][j]);
                }
                putchar('\n');
            }
        }
    }

    return 0;
}