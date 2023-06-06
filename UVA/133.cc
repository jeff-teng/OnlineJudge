#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, k, m;

    while (cin >> n >> k >> m && (n != 0 && k != 0 && m != 0)) {
        // 生成从 1 到 n 的序列
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }

        // k 初始位置
        int k_index = n - 1;

        // m 初始位置
        int m_index = 0;

        // 剩余人数
        int left = n;

        // 遍历序列
        while (n > 0) {
            // 获取每次的 k 和 m 下标
            for (int i = 0; i < k; i++) {
                k_index = (k_index + 1) % v.size();

                // 跳过 0
                while (v[k_index] == 0) {
                    k_index = (k_index + 1) % v.size();
                }
            }
            for (int i = 0; i < m; i++) {
                m_index = (m_index - 1 + v.size()) % v.size();

                // 跳过 0
                while (v[m_index] == 0) {
                    m_index = (m_index - 1 + v.size()) % v.size();
                }
            }

            // 如果 k 和 m 下标相同，说明只剩下一个元素
            if (k_index == m_index) {
                cout << setw(3) << v[k_index];
            } else {
                cout << setw(3) << v[k_index] << setw(3) << v[m_index];
            }

            // 删除 k 和 m 下标的元素
            v[k_index] = v[m_index] = 0;

            // 剩余人数减少
            if (k_index == m_index) {
                n--;
            } else {
                n -= 2;
            }

            // 最后一个元素不输出逗号
            if (n > 0) {
                cout << ",";
            }
        }

        cout << endl;
    }

    return 0;
}