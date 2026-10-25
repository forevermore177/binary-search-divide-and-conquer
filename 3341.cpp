#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;
using ll =long long;
unordered_map<ll, vector<int>>buckets;
int n;
ll a[200001];
int st[200001][20];
int solve(int l,int r,ll nowh){
    if (l>r)return 0;
    if (l==r) return (a[l] > nowh) ? 1:0;
    int len = r-l+1;
    int solution_1 = len;
    if (nowh!=0) {
        vector<int>&temp = buckets[nowh];
        solution_1 -= upper_bound(temp.begin(),temp.end(),r) - lower_bound(temp.begin(),temp.end(),l); 
    }
    int k = static_cast<int>(floor(log2(len)));
    int p1 = st[l][k];
    int p2 = st[r - (1 << k) + 1][k];
    int mid = (a[p1] < a[p2])?p1:p2;
    int solution_2 = a[mid]-nowh;
    solution_2+=solve(l,mid-1,a[mid])+solve(mid+1,r,a[mid]);
    return min(solution_1,solution_2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (buckets.count(a[i]) == 0)
            buckets.insert({a[i],{i}});
        else
            buckets[a[i]].push_back(i);
    } 
    int up=static_cast<int>(floor(log2(n)));
    for (int j=0;j<=up;j++){
        for (int i=1;i+(1 << j)-1<=n;i++){ // i -> i + 2^(j)-1
            if (j==0)
                st[i][0]=i;
            else{
                int &t1 = st[i][j-1];
                int &t2 = st[i+(1 << (j-1))][j-1];
                if (a[t1] < a[t2])
                    st[i][j]=t1;
                else
                    st[i][j]=t2;
            }
        }
    }
    cout<<solve(1, n, 0);
}
/*
## 1. [l,r]中高度≧h的有几个
由于每次递归都确保h作为上一次的最小值小于等于区间内所有的长度，因而只需要计算 **[l,r]中高度=h的有几个**
### 问题变为：[l,r]中高度=h的有几个
定义一个
```cpp
unordered_map<int,vector<int>>bucket;
```
记录高度为h的下标，然后对区间进行二分查找
**可以使用STL的upper bound和lower bound实现**

## 2. [l,r]中h最小值及所在位置
### ST表
#### 定义
对于数列$a_1,a_2,...,a_n$定义：
$$st_{i_j}=\min(a_i,a_{i+1},...,a_{i+2^j-1})$$
递推：
$$st_{i_0}=a_i,st_{i_j}=\min(st_{i_{j-1}},st_{{i+2^{j-1}}_{j-1}})$$
#### 时间复杂度
1. 预处理：$O(nlogn)$
2. 访问区间：$O(1)$
#### 取对数
```cpp
#include <cmath>
double k = floor(log2(X)) 
```
返回满足 $2^k≤X$的最大整数 $k$,返回值是double型，需要静态变量转换
#### 访问$O(1)$的实现
取两块中间有重叠的区间：
- 块1：$[l,l + 2^k - 1]$
- 块2：$[r - 2^k + 1,r]$

那么只需要比较二者的最小值即可！
**而非把长度拆成若干个2的幂次的和**

#### 2的幂次
与其打表，不如用**学过的位运算** （1 << k）

### 变形与求下标
只需要将ST表定义为：**从i开始，长度$2^j$内最小值的下标**
那么递推关系类似成立

## 3. 边界点的tip
当$l==r$时，应判断$a[l]与nowh$的关系，如果**相等返回0**，否则返回1
*/