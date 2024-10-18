import sys

T = int(sys.stdin.readline().strip())

for _ in range(T):
    n = int(sys.stdin.readline().strip())

    l = []
    st = set()

    # 处理输入
    for __ in range(n):
        a, b = (int(x) for x in sys.stdin.readline().strip().split())
        st.add((a, b))
        l.append((a, b))
    l.sort()

    # 是否对称
    flag = True

    # 对称 x 值
    x = l[0][0] + l[-1][0]

    # 遍历
    for t in l:
        # 找不到对称点
        if (x - t[0], t[1]) not in st:
            flag = False
            break

    if flag:
        print("YES")
    else:
        print("NO")
