#include <iostream>

using namespace std;


// 获取数字个数
void get_digit_count(int n, int digit_count[]) {
    while (n) {
        ++digit_count[n % 10];
        n /= 10;
    }
}


int main() {
    int n;

    cin >> n;

    while (n--) {
        int num;
        int digit_count[10] = {0};

        cin >> num;

        // 循环累加数字计数
        for (int i = 0; i < num; ++i) {
            get_digit_count(i + 1, digit_count);
        }

        for (int i = 0; i < 10; ++i) {
            if (i > 0) {
                putchar(' ');
            }
            printf("%d", digit_count[i]);
        }
        putchar('\n');
    }

    return 0;
}