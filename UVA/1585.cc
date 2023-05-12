#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;

    cin >> n;

    while (n--) {
        string s;
        int score = 0;
        int current_score = 0;

        cin >> s;

        for (auto c: s) {
            if (c == 'X') {
                // 重制当前得分
                current_score = 0;
            } else {
                // 加上当前得分
                score += ++current_score;
            }
        }

        cout << score << endl;
    }

    return 0;
}