#include <bits/stdc++.h>

using namespace std;


int main() {
    // 最大数字个数
    const int MAXN = 10000;

    int n, q;
    int case_count = 0;
    int num[MAXN] = {0};

    while (cin >> n >> q) {
        // 文件结束
        if (n == 0 && q == 0) {
            break;
        }

        // 输入 n 个数字
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        // 升序排序
        sort(num, num + n);

        cout << "CASE# " << ++case_count << ":" << endl;

        // 输入 q 个数字
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;

            // 查找数字
            int p = lower_bound(num, num + n, x) - num;

            if (num[p] == x) {
                cout << x << " found at " << p + 1 << endl;
            } else {
                cout << x << " not found" << endl;
            }
        }
    }

    return 0;
}