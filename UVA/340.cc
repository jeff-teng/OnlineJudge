#include <iostream>
#include <vector>
#include <map>

using namespace std;


// 是否结束本轮游戏
bool end_game(vector<int> guess) {
    for (int num: guess) {
        // 存在非 0 元素
        if (num != 0) {
            return false;
        }
    }

    return true;
}


// 统计位置、数字正确数量
int get_all_right_count(vector<int> answer, vector<int> guess) {
    int all_right_count = 0;

    for (int i = 0; i < answer.size(); ++i) {
        if (answer[i] == guess[i]) {
            ++all_right_count;
        }
    }

    return all_right_count;
}


// 统计各元素数量
map<int, int> get_item_count(vector<int> v) {
    map<int, int> item_count;

    for (int num: v) {
        if (item_count.count(num) == 0) {
            item_count[num] = 0;
        }
        ++item_count[num];
    }

    return item_count;
}


// 统计位置正确数量
int get_location_right_count(vector<int> answer, vector<int> guess) {
    int location_right_count = 0;

    // 统计答案各元素数量
    map<int, int> answer_count = get_item_count(answer);

    // 统计猜数各元素数量
    map<int, int> guess_count = get_item_count(guess);

    for (auto kv: answer_count) {
        // 在猜数中也存在
        if (guess_count.count(kv.first)) {
            location_right_count += min(kv.second, guess_count[kv.first]);
        }
    }

    return location_right_count;
}


int main() {
    // 游戏局数
    int game_num = 0;

    // 猜数个数
    int number_count = 0;

    while (cin >> number_count and number_count > 0) {
        printf("Game %d:\n", ++game_num);

        int number;

        // 答案数组
        vector<int> answer;

        // 输入答案
        for (int i = 0; i < number_count; ++i) {
            cin >> number;
            answer.push_back(number);
        }

        // 输入猜数
        while (true) {
            // 猜数数组
            vector<int> guess;

            for (int i = 0; i < number_count; ++i) {
                cin >> number;
                guess.push_back(number);
            }

            // 结束游戏
            if (end_game(guess)) {
                break;
            }

            // 位置、数字正确数量
            int all_right_count = get_all_right_count(answer, guess);

            // 位置正确数量
            int location_right_count = get_location_right_count(answer, guess);

            printf("    (%d,%d)\n", all_right_count, location_right_count - all_right_count);
        }
    }

    return 0;
}