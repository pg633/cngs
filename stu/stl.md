1. [1 项目背景](#1-项目背景)
2. [2 项目内容](#2-项目内容)
   1. [2.1 stl 相关知识](#21-stl-相关知识)
   2. [2.2 stl](#22-stl)

# 1 项目背景
* 1 我也不知道什么时候能写完这个玩意 
# 2 项目内容
* 一些有的没的快速写代码的内容 










##  2.1 stl 相关知识 
vector 倍增2m 空间 m/4 缩容 
map 使用前用find 看看有没有
bitset ~s 对s 按位取反
    s.count() 看看有多少个1 
    所有位为0 时 any 返回false none = true
    至少有1位为 1 时，any 返回1 none 返回0 

    s.set() 所有位 =1 
    s.set(k,v) 把 k 置位为 v 
    s.reset s 所有位置位为0 
    s.reset(k) 把k 置位0
    s.flip() s全部取反 
    s.flip(k) 把k 取反 
    
algorithm 
    unique  去重 
        int m = unique(a.begin(),a.end()) -a.begin();
        int m = unique(a+1,a+m+1) - (a+1);
    random_shuffle 随机打乱 

    next_permutation 下一个排列 

        do{

        }while(next_permutation(a.begin(),a.end());

    sort 排序 
        sort(a.begin(),a.end() []( auto & l,auto & r){
            return l<r;
        });

随机数 
    int random(int n)
    {
        return rand()*rand() %n;
    }
    static{ 
        srand((unsigned)time(0));

    }


    c++ 写代码就是简洁啊 - 喜欢凤铃的pg633
dp 刷起来 空间不压缩 - 喜欢凤铃的pg633


int[][] dp = new int[m][n];
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        // 计算 dp[i][j]


for (int i = m - 1; i >= 0; i--)
    for (int j = n - 1; j >= 0; j--)
        // 计算 dp[i][j]

// 斜着遍历数组
for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
        int j = l + i - 1;
        // 计算 dp[i][j]
    }
}


// 二分搜索 


精确的 位运算 
    转小写
    ('a' | ' ') = 'a'
    转大写
    （'a' & '_') = 'A'
    大写转小写 
    （'a' ^ ' ') = 'A'
    判断是否异号
        int x = -1, y = 2;
        bool f = ((x ^ y) < 0); // true
    交换两个数 
        a ^= b;
        b ^= a;
        a ^= b;
    +1 
        n = -~n;
    -1 
        n = ~-n;
    
    消除最后一个1 
        n & (n-1)

## 2.2 stl 


累加 (std::accumulate)
    accumulate(begin, end, init, op)

    返回给定区间内元素的累加值与给定初值的和，初值不可省略
        可指定求和运算，默认为std::plus
        vector<int>vec = {1, 2, 3, 4};
        cout<<accumulate(vec.begin(), vec.end(), 0); 
        //累加, 输出: 10
        cout<<accumulate(vec.begin(), vec.end(), 1, bit_xor<int>());
        //异或和，输出: 5
        运算操作函数对象见 functional 头文件，常用如下
        函数对象	含义
        multiplies	乘法
        bit_xor	按位异或
        bit_and	按位与
​

前缀和 (std::partial_sum)
    partial_sum(begin, end, res)

        计算给定区间的前缀和，存入res （iterator）中，可以直接存入原容器

        int a[5] = {1, 2, 3, 4, 5};
        partial_sum(a, a+5, a); 
        // a : {1, 3, 6, 10, 15}
        ​

        递增填充 (std::iota)
        iota(begin, end, value)

        递增填充给定区间，即

        *(d_first)   = value;
        *(d_first+1) = ++value;
        ...
        示例：

        vector<int>vec;
        vec.resize(10);
        iota(vec.begin(), vec.end(), 0);
        //vec: {0, 1, 2, ..., 9}
        ​

定值填充 (std::fill)
    fill(begin, end, val)

    填充给定区间为val

    fill_n(begin, n, val)

    指定区间起点和长度

    ​

    生成值填充 (std::generate)
    generate(begin, end, func)
    generate_n(begin, n, func)
    使用函数生成给定区间的值

    int a[10];
    generate(a, a+5, read);
    其中 read 函数可以为

    int read(){
        int ret;
        scanf("%d", &ret);
        return ret;
    }
 

逐元素函数操作 (std::for_each)
    for_each(begin, end, func)

        对区间内的元素执行一元函数 func

        int a[5] = {1, 2, 3, 4, 5};
        for_each(a, a+5, [](int &x){ x&=1; });
        //a : {1, 0, 1, 0, 1}
        感觉非常有用，配合 lambda 比写 for 循环舒服多了，应用场景非常广泛

        ​

逐元素函数计算 (std::transform)
    transform(begin, end, res, func)

    对区间内的元素执行一元函数 func ，将返回值存到 res （也是 iterator）中

        可以直接存入原容器

        int a[5] = {1, 2, 3, 4, 5};
        transform(a, a+5, a, [](int x) { return __gcd(x, 2); });
        //a : {1, 2, 1, 2, 1}
        ​

计数与条件计数 (std::count & std::count_if)
    count(begin, end, value)


计数区间内值为 value 的元素个数
    count_if(begin, end, func)

        计数区间内满足条件的元素个数，func 为一元谓词
        int a[5] = {1, -1, 2, -2, 3};
        cout<<count(a, a+5, 2); 
        //输出 : 1
        cout<<count_if(a, a+5, [](int x) { return x>0; });
        //输出 : 3
        ​




数值运算小库 numeric
    accumulate 求和
    iota 填充元素依次相加
    reduce mmp 没试出来
    inner_product 两个依次想乘
    adjacent_difference 判断两个之间的差
    partial_sum 前缀和
    gcd/lcm  板子... 





hive  to mysql
mysql -> mysql 


