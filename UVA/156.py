from collections import defaultdict

s_all = []

# 记录次数
d = defaultdict(int)

while True:
    # 处理输入
    in_s = input()

    if in_s == "#":
        break

    s_l = in_s.split()
    s_all.extend(s_l)

    # 遍历
    for s in s_l:
        d["".join(sorted(s.lower()))] += 1

# 遍历输出
for s in sorted(s_all):
    if d["".join(sorted(s.lower()))] < 2:
        print(s)