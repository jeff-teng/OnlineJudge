# 获取下一个序列
def get_next_seq(i_l):
    new_i_l = []

    for i in range(1, len(i_l)):
        new_i_l.append(abs(i_l[i] - i_l[i - 1]))
    new_i_l.append(abs(i_l[-1] - i_l[0]))

    return tuple(new_i_l)

def check_zero(i_l):
    for item in i_l:
        if item != 0:
            return False
    return True

# 处理输入
T = int(input())

# 是否出现过
st_zero = set()
st_loop = set()

for _ in range(T):

    n = int(input())
    i_l = tuple(int(x) for x in input().split())

    st = set()

    while True:
        if i_l in st_zero or check_zero(i_l):
            st_zero.update(st)
            print("ZERO")
            break
        elif i_l in st_loop or i_l in st:
            st_loop.update(st)
            print("LOOP")
            break
        st.add(tuple(i_l))
        i_l = get_next_seq(i_l)