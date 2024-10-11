#include <iostream>
#include <map>

using namespace std;


// 判断字符串是否为回文串
bool is_palindrome(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        // 首位对应位置字符不同
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}


// 判断字符串是否为镜像串
bool is_mirrored(string s) {
    // 原字符和镜像字符
    string c = "AEHIJLMOSTUVWXYZ12358";
    string r = "A3HILJMO2TUVWXY51SEZ8";

    // 构造映射关系
    map<char, char> m;
    for (int i = 0; i < c.size(); ++i) {
        m[c[i]] = r[i];
    }

    for (int i = 0; i < s.size(); ++i) {
        // 不存在镜像字符
        if (m.count(s[i]) == 0) {
            return false;
        }

        // 首位对应位置字符不为镜像
        if (m[s[i]] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}


int main() {
    string s;

    // 输出字符串
    string output_string[2][2] = {
        {" -- is not a palindrome.", " -- is a regular palindrome."},
        {" -- is a mirrored string.", " -- is a mirrored palindrome."},
    };

    // 输入字符串
    while (cin >> s) {
        bool mirrored_flag = is_mirrored(s);
        bool palindrome_flag = is_palindrome(s);

        printf("%s%s\n\n", s.c_str(), output_string[mirrored_flag][palindrome_flag].c_str());
    }

    return 0;
}