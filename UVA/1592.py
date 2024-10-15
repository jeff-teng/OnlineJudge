try:
    while True:
        # 处理输入
        n, m = (int(x) for x in input().split())

        s_all = []

        for i in range(n):
            s_all.append(input().split(","))

        # 找到标记
        flag = False

        # 遍历列的组合
        for i in range(m):
            for j in range(m):
                if i >= j:
                    continue

                # 记录曾经出现的行
                d = {}

                for k in range(n):
                    # 第一次出现
                    if (s_all[k][i], s_all[k][j]) not in d:
                        d[s_all[k][i], s_all[k][j]] = k
                    else:
                        flag = True
                        print("NO")
                        print(d[s_all[k][i], s_all[k][j]] + 1, k + 1)
                        print(i + 1, j + 1)
                        break
                if flag:
                    break
            if flag:
                break

        # 没有找到
        if not flag:
            print("YES")

except:
    pass