import sys

l = []
st = set()

while True:
    # 处理输入
    s = sys.stdin.readline()
    if not s:
        break

    s = s.strip()

    st.add(s)
    l.append(s)

# 遍历字符串
for s in l:
    if len(s) == 1:
        continue

    # 分割字符串
    for i in range(1, len(s)):
        a, b = s[:i], s[i:]

        # 查找
        if a in st and b in st:
            print(s)
            break