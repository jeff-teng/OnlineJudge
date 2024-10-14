import heapq

# 优先队列
hq = []

# 放入初始丑数
heapq.heappush(hq, 1)

# 每次取出一个，放入2、3、5的倍数
out_count = 0

for i in range(1500):
    # 去除一个
    a = heapq.heappop(hq)

    # 放入2、3、5的倍数
    if a * 2 not in hq:
        heapq.heappush(hq, a * 2)
    if a * 3 not in hq:
        heapq.heappush(hq, a * 3)
    if a * 5 not in hq:
        heapq.heappush(hq, a * 5)

print("The 1500'th ugly number is {a}.".format(a=a))
