#include <iostream>

using namespace std;


// 计算各个位数的和
int cal_digit_sum(int n) {
    int digit_sum = 0;

    while (n) {
        digit_sum += n % 10;
        n /= 10;
    }

    return digit_sum;
}


// 数字生成计算初始化
int *digit_generator_init() {
    int *digit_generator = (int *)malloc(sizeof(int) * 100001);

    for (int i = 1; i <= 100000; ++i) {
        int digit_sum = cal_digit_sum(i) + i;

        // 保存最小的数字生成
        if (digit_generator[digit_sum] == 0) {
            digit_generator[digit_sum] = i;
        }
    }

    return digit_generator;
}


int main() {
    int n;
    int *digit_generator = digit_generator_init();

    cin >> n;

    while (n--) {
        int number;
        cin >> number;
        printf("%d\n", digit_generator[number]);
    }

    return 0;
}