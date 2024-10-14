# 字符串集合
s_set = set()

try:
    while(True):
        # 处理输入
        in_s = input()

        # 非字母字符替换为空格
        in_s = "".join(c if c.isalpha() else ' ' for c in in_s)

        # 遍历字符串
        for s in in_s.split():
            # 去除非字母字符
            out_s = "".join(c for c in s if c.isalpha())

            # 添加到集合
            s_set.add(out_s.lower())

except:
    # 集合去重排序输出
    for s in sorted(list(s_set)):
        print(s)
