a = [i for i in range(10, 0, -1)]
# 按照从小到大排序，保留原来的索引
b = sorted(range(len(a)), key=lambda x: a[x])  
# 如果用c++写，写法如下
# vector<int> a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
# vector<int> b(a.size());
# iota(b.begin(), b.end(), 0);
