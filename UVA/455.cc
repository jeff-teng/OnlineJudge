#include <iostream>

using namespace std;


int main() {
    int n;

    cin >> n;

    while (n--) {
        string s;
        bool equal_flag = false;

        cin >> s;

        for (int i = 1; i <= s.size(); ++i) {
            equal_flag = true;

            // 每次偏移 i，寻找最小偏移的 i
            for (int j = 0; j < s.size(); ++j) {

                // 存在字符不相等，不是循环节
                if (s[j] != s[(j + i) % s.size()]) {
                    equal_flag = false;
                    break;
                }
            }

            // 找到最小偏移
            if (equal_flag) {
                cout << i << endl;
                break;
            }
        }

        // 输出额外空行
        if (n > 0) {
            putchar('\n');
        }
    }

    return 0;
}