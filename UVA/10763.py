import sys
from collections import defaultdict

while True:
    # 处理输入
    n = int(input())

    if n == 0:
        break

    # 交换字典
    dd = defaultdict(int)

    for _ in range(n):
        a, b = (int(x) for x in sys.stdin.readline().strip().split())

        # 不存在
        if dd[b, a] == 0:
            dd[a, b] += 1
        else:
            dd[b, a] -= 1

    # 检查结果
    if sum(dd.values()) > 0:
        print("NO")
    else:
        print("YES")