#include <cstdio>
#include <map>
#include <iostream>

using namespace std;


int main() {
    int T;

    cin >> T;

    while (T--) {
        int n, m;
        char s[50][1001] = {0};

        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
        }

        int diff = 0;
        string result = "";

        // 纵向统计
        for (int i = 0; i < m; ++i) {
            map<char, int> char_count;

            char max_char = 'A';
            int max_count = 0;
            string DNA = "ACGT";

            // 统计字符出现个数
            for (int j = 0; j < n; ++j) {
                if (char_count.count(s[j][i]) == 0) {
                    char_count[s[j][i]] = 0;
                }
                ++char_count[s[j][i]];
            }

            // 统计出现最多的字符
            for (auto c: DNA) {
                if (char_count[c] > max_count) {
                    max_char = c;
                    max_count = char_count[c];
                }
            }

            diff += n - max_count;
            result.push_back(max_char);
        }

        printf("%s\n%d\n", result.c_str(), diff);
    }

    return 0;
}