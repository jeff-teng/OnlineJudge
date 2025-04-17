#include <iostream>
#include <list>
#include <string>

using namespace std;


int main() {
    string s;

    while (cin >> s) {
        list<char> l;

        // 插入位置
        auto pos = l.begin();

        // 遍历字符串
        for (auto c: s) {
            if (c == '[') {
                pos = l.begin();
            } else if (c == ']') {
                pos = l.end();
            } else {
                l.insert(pos, c);
            }
        }

        // 遍历列表输出
        for (auto c: l) {
            cout << c;
        }

        cout << endl;
    }

    return 0;
}