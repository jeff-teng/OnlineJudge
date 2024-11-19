import sys
from collections import deque

# 输入
T = int(sys.stdin.readline().strip())

for _ in range(T):
    n, m = (int(x) for x in sys.stdin.readline().strip().split())
    l = [int(x) for x in sys.stdin.readline().strip().split()]

    # 排序
    sorted_l = sorted(l, reverse=True)

    # 当前最大元素的下标
    max_i = 0

    # 构造双端队列
    dq = deque(l)

    # 次数
    count = 1

    # 模拟
    while True:
        # 取队首
        f = dq.popleft()

        # 队首元素为目标元素，且最大
        if m == 0 and f == sorted_l[max_i]:
            break

        # 队首元素最大，更新最大元素下标，位置前移
        if f == sorted_l[max_i]:
            count += 1
            max_i += 1
        else:
            dq.append(f)

        # 移动目标元素
        m = (len(dq) + m - 1) % len(dq)

    # 输出结果
    print(count)