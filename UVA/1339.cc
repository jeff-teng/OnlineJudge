#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    string s1, s2;

    while (cin >> s1 >> s2) {
        // 统计每一个字符串字符出现的频率
        int a[26] = {0}, b[26] = {0};

        for (int i = 0; i < s1.size(); i++) {
            a[s1[i] - 'A']++;
        }

        for (int i = 0; i < s2.size(); i++) {
            b[s2[i] - 'A']++;
        }

        // 排序
        sort(a, a + 26);
        sort(b, b + 26);

        // 比较频次是否一致
        bool flag = true;

        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                flag = false;
                break;
            }
        }

        // 输出结果
        puts(flag ? "YES" : "NO");
    }

    return 0;
}