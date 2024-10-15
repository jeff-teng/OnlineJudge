from collections import deque

while True:
    # 处理输入
    n = int(input())
    if n == 0:
        break

    # 模拟
    dq = deque(range(1, n + 1))

    l = []

    while len(dq) > 1:
        l.append(dq.popleft())
        dq.append(dq.popleft())

    print("Discarded cards:", end="")
    if l:
        print(" {}".format(str(l)[1:-1]))
    else:
        print()
    print("Remaining card: {}".format(dq.popleft()))