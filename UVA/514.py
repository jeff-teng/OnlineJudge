import sys
from collections import deque

while True:
    n = int(sys.stdin.readline())

    if n == 0:
        break

    # 处理数据
    while True:
        l = [int(x) for x in sys.stdin.readline().strip().split()]

        if l[0] == 0:
            break

        dq1 = deque()
        dq2 = deque(range(n, 0, -1))

        # 模拟栈操作
        for i in range(n):
            while True:
                # 存在当前元素
                if len(dq1) > 0 and dq1[-1] == l[i]:
                    dq1.pop()
                    break
                if len(dq2) > 0 and dq2[-1] == l[i]:
                    dq2.pop()
                    break

                # 不存在当前元素
                if len(dq2) > 0:
                    dq1.append(dq2.pop())
                else:
                    break

        if len(dq1) + len(dq2) > 0:
            print("No")
        else:
            print("Yes")

    print("")