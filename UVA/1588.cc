#include <bits/stdc++.h>

using namespace std;


// 获取最小契合长度
int get_min_length(string s1, string s2) {
    int ans = s1.size() + s2.size();

    // 偏移量
    for (int i = 0; i < s1.size(); ++i) {
        bool flag = true;

        // 遍历重合部分
        for (int j = 0; j <= s1.size() - i; ++j) {
            // 超出 s2 长度
            if (j >= s2.size()) {
                break;
            }

            if (s1[i + j] == '2' && s2[j] == '2') {
                flag = false;
            }
        }

        // 可以契合
        if (flag) {
            ans = min(ans, int(max(s1.size(), s2.size() + i)));
        }
    }

    return ans;
}


int main() {
    string s1, s2;

    while (cin >> s1 >> s2) {
        int ans = s1.size() + s2.size();

        // 分别以 s1 s2 为基准进行偏移
        ans = min(ans, get_min_length(s1, s2));
        ans = min(ans, get_min_length(s2, s1));

        cout << ans << endl;
    }

    return 0;
}