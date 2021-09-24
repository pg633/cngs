import heapq
from collections import defaultdict
import collections
import itertools

# itertools.combinations(points, 3) 返回某个列表的全排列


class Solution(object):
    def largestTriangleArea(self, points):
        def area(p, q, r):
            return .5 * abs(p[0] * q[1] + q[0] * r[1] + r[0] * p[1] -
                            p[1] * q[0] - q[1] * r[0] - r[1] * p[0])

        return max(
            area(*triangle) for triangle in itertools.combinations(points, 3))


#  collections.Counter 统计
# 获取元素
# list(c.elements())
# 最常见出现的k个元素：
# Counter('abracadabra').most_common(3)
# 读文件统计词频并按照出现次数排序，文件是以空格隔开的单词的诸多句子：
def func():
    from collections import Counter
    lines = open("./data/input.txt", "r").read().splitlines()
    lines = [lines[i].split(" ") for i in range(len(lines))]
    words = []
    for line in lines:
        words.extend(line)
    result = Counter(words)
    print(result.most_common(10))


# 　在Python里面有一个模块collections，解释是数据类型容器模块。这里面有一个collections.defaultdict()经常被用到。

a = defaultdict(int)
# a[1] = 1
# a["b"]
# print "a['a']==", a["a"]
# print a----------a['a']== 0
# defaultdict(<type 'int'>, {'a': 0, 1: 1, 'b': 0})


class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        return list(
            map({
                v: k
                for k, v in dict(
                    enumerate(sorted(dict.fromkeys(arr).keys()),
                              start=1)).items()
            }.get, arr))


class Solution:
    def freqAlphabets(self, s: str) -> str:
        def get(s):
            return chr(int(s) + 96)

        i, ans = 0, ""
        while i < len(s):
            if i + 2 < len(s) and s[i + 2] == '#':
                ans += get(s[i:i + 2])
                i += 2
            else:
                ans += get(s[i])
            i += 1
        return ans


class Solution:
    def maximum69Number(self, num: int) -> int:
        return int(str(num).replace('6', '9', 1))


# list 2 str
def list2str():
    '''
        list 2 str
    '''

    test_list = []
    test_str = "".join(test_list)


# str转list
def str2list():
    test_str = ""
    test_list = list(test_str)


#  遍历一个 dict
def tranvel_dict():
    a = {'a': '1', 'b': '2', 'c': '3'}
    # 方式一：
    for key in a:
        print(key+':'+a[key])
    # 方式二：
    for key in a.keys():
        print(key+':'+a[key])
    # 方式三：
    for key, value in a.items():
        print(key+':'+value)
    # 方式四：
    for (key, value) in a.items():
        print(key+':'+value)

    # 2、遍历value值：
    for value in a.values():
        print(value)
    # 3、遍历字典项
    for kv in a.items():
        print(kv)


# 堆操作
  # heapq.heappush
  # heapq.heappop
   # heapq.heapify

# map 默认值
def collections_defaultdict():
    collections.defaultdict(set)


# string to set
def string2set():
    s = "123"
    return set(s)


def cc():
    print(("123")
