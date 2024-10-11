#include <iostream>
#include <map>

using namespace std;


int main() {
    int n;

    map<char, double> atom_mass = {
        {'C', 12.01},
        {'H', 1.008},
        {'O', 16},
        {'N', 14.01},
    };

    cin >> n;

    while (n--) {
        string s;
        int mol = 0;
        double mass = 0;
        char current_char = '\0';

        cin >> s;

        for (auto c: s) {
            // 数字，累加 mol
            if (c >= '0' && c <= '9') {
                mol = mol * 10 + c - '0';
            } else {
                // 字母，直接计算质量
                if (atom_mass.count(current_char) > 0) {
                    mass += atom_mass[current_char] * max(1, mol);
                }

                mol = 0;
                current_char = c;
            }
        }

        // 加入最后一个
        mass += atom_mass[current_char] * max(1, mol);

        printf("%.3lf\n", mass);
    }

    return 0;
}
