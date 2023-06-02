#include <bits/stdc++.h>

using namespace std;


// 初始化打表
map<string, tuple<int, int>> init_table() {
    map<string, tuple<int, int>> table;

    // 基础等式
    // (1 - 2 ^ (-M - 1)) * 2 ^ (2 ^ E - 1) == A * B ^ 10

    // 两边取对数
    // log10((1 - 2 ^ (-M - 1))) + (2 ^ E - 1) * log10(2) = log10(A) + B

    for (int i = 0; i <= 9; ++i) {
        for (int j = 1; j <= 30; ++j) {
            // 计算左边
            double left = log10(1 - pow(2, -i - 1)) + (pow(2, j) - 1) * log10(2);

            // 计算 B
            int B = floor(left);

            // 计算 A
            double A = pow(10, left - B);

            // A 保留 15 位小数，写入字符串
            char buf[20] = {0};
            sprintf(buf, "%.15lf", A);

            // 转化为 string 类型
            string s = buf;

            // 保存到表
            table[s + " " + to_string(B)] = make_tuple(i, j);
        }
    }

    return table;
}


int main() {
    string s;

    // 打表
    auto table = init_table();

    // 查表输出
    while (cin >> s && s != "0e0") {
        // 字符串分割，e 替换为空格
        s.replace(s.find('e'), 1, " ");

        // 重新读入
        double a, A;
        int b, B;

        sscanf(s.c_str(), "%lf%d", &a, &b);

        // 遍历表
        for (auto m: table) {
            // 重新读入
            sscanf(m.first.c_str(), "%lf %d", &A, &B);

            // 比较
            if (fabs(A - a) < 1e-4 && B == b) {
                // 输出
                printf("%d %d\n", get<0>(m.second), get<1>(m.second));

                // 跳出循环
                break;
            }
        }
    }

    return 0;
}