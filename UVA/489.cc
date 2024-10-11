#include <iostream>

using namespace std;


// 判断字符是否已经全部猜对
bool judge_all_guessed(const bool answer_char_guessed[], const string &answer) {
    for (int i = 0; i < answer.size(); ++i) {
        if (!answer_char_guessed[answer[i] - 'a']) {
            return false;
        }
    }

    return true;
}


int main() {
    int round;

    while (cin >> round && round != -1) {
        // 答案和猜测
        string answer, guess;

        cin >> answer >> guess;

        // 是否全部猜对
        bool all_guessed = false;

        // 猜错次数
        int wrong_count = 0;

        // 答案中的字符是否已经被猜中
        bool answer_char_guessed[26] = {false};

        // 字符是否被猜过
        bool char_guessed[26] = {false};

        // 记录猜错的次数，标记猜对的字符
        for (int i = 0; i < guess.size(); ++i) {
            if (answer.find(guess[i]) == string::npos) {
                // 字符没有被猜过
                if (!char_guessed[guess[i] - 'a']) {
                    ++wrong_count;
                }
                char_guessed[guess[i] - 'a'] = true;

                // 错误次数超过7次
                if (wrong_count >= 7) {
                    break;
                }
            } else {
                // 字符被猜对
                answer_char_guessed[guess[i] - 'a'] = true;

                // 判断是否全部猜对
                if (judge_all_guessed(answer_char_guessed, answer)) {
                    all_guessed = true;
                    break;
                }
            }
        }

        // 输出结果
        cout << "Round " << round << endl;

        if (all_guessed) {
            cout << "You win." << endl;
        } else if (wrong_count >= 7) {
            cout << "You lose." << endl;
        } else {
            cout << "You chickened out." << endl;
        }
    }

    return 0;
}