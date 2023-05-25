#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, m;

    while (scanf("%d%d", &n, &m) != EOF) {
        printf("%d/%d = %d.", n, m, n / m);

        // 记录商和余数
        vector<pair<int, int>> qrpair;

        // 记录余数集合
        unordered_set<int> remainder;

        // 添加商和余数
        while (remainder.count(n % m) == 0) {
            remainder.insert(n % m);
            qrpair.push_back({n / m, n % m});
            n = n % m * 10;
        }

        // 添加最后一个商和余数
        qrpair.push_back({n / m, n % m});

        // 输出结果
        int start = 0;

        for (int i = 1; i < qrpair.size(); ++i) {
            // 输出循环节
            if (qrpair[i - 1].second == n % m) {
                printf("(");
                start = i - 1;
            }

            // 输出商
            if (i - start > 50) {
                printf("...");
                break;
            } else {
                printf("%d", qrpair[i].first);
            }
        }
        printf(")\n   %d = number of digits in repeating cycle\n\n", qrpair.size() - start - 1);
    }

    return 0;
}