#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n;

    cin >> n;

    while (n--) {
        string s;

        // 字符串数组
        vector<string> str_arr;

        cin >> s;

        // 遍历环状所有字符串
        for (int i = 0; i < s.size(); ++i) {
            string empty_s = "";

            for (int j = 0; j < s.size(); ++j) {
                empty_s.push_back(s[(i + j) % s.size()]);
            }
            str_arr.push_back(empty_s);
        }

        // 排序输出
        sort(str_arr.begin(), str_arr.end());
        cout << str_arr[0] << endl;
    }

    return 0;
}