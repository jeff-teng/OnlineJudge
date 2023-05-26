#include <bits/stdc++.h>

using namespace std;


int main() {
    string s1, s2;

    while (cin >> s1 >> s2) {
        int i = 0, j = 0;

        // 扫描 s1，s2
        while (i < s1.size() && j < s2.size()) {
            // 扫描 s1，s2
            if (s1[i] == s2[j++]) {
                ++i;
            }
        }

        // s1 扫描完
        if (i == s1.size()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}