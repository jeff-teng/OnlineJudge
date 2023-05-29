#include <bits/stdc++.h>

using namespace std;


// 矩形类
struct Rectangle {
    int w, h;
};


// 矩形排序
bool rectangle_cmp(Rectangle a, Rectangle b) {
    if (a.w != b.w) {
        return a.w < b.w;
    }
    return a.h < b.h;
}


int main() {
    Rectangle rectangle[6];

    while (cin >> rectangle[0].w >> rectangle[0].h) {
        for (int i = 1; i < 6; ++i) {
            cin >> rectangle[i].w >> rectangle[i].h;
        }

        // 短边为宽
        for (int i = 0; i < 6; ++i) {
            if (rectangle[i].w > rectangle[i].h) {
                swap(rectangle[i].w, rectangle[i].h);
            }
        }

        // 排序
        sort(rectangle, rectangle + 6, rectangle_cmp);

        // 是否可以组成合法箱子
        bool box_flag = true;

        // 每个矩形不是 2 个
        for (int i = 0; i < 6; i += 2) {
            if (rectangle[i].w != rectangle[i + 1].w || rectangle[i].h != rectangle[i + 1].h) {
                box_flag = false;
            }
        }

        // 宽深高没有对应相等
        if (rectangle[0].w != rectangle[2].w || rectangle[0].h != rectangle[4].w || rectangle[2].h != rectangle[4].h) {
            box_flag = false;
        }

        puts(box_flag? "POSSIBLE": "IMPOSSIBLE");
    }

    return 0;
}