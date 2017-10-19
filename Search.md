# 搜索
## 查找表
是由同一类型的数据元素（或记录）构成的集合。

### 静态查找表与动态查找表

| 静态查找表 | 动态查找表 |
| --- | --- |
| 1\. 查询某个特定的数据元素是否在查找表中 2\. 检索某个特定的数据元素的各种属性 | 1\. 查询某个特定的数据元素是否在查找表中 2\. 检索某个特定的数据元素的各种属性 3\. 在查找表中插入一个数据元素 4\. 从查找表中删去一个某个数据元素|

## 查找
在一个含有众多的数据元素的查找表中，找出某个特定的数据元素（或记录）。
### 主关键字与次关键字
唯一标示为主关键字，非必须唯一标示为次关键字。
### 查找的成功与不成功
查找不成功则返回一个空记录或空指针。

## 静态查找表
创建，销毁，搜索，遍历。
### 顺序表的查找
从最后一个开始逐个比对。

```
int searchSeq (int* array, int key, int length) {
int i;
    for (i = length -1; (array[i] != key) && i >= 0; --i);
    return i;
}
```

> 是否应该使用哨兵？

### 平均查找长度
`ASL = ∑PiCi`

> 顺序表查找，成功时ASL为(n + 1) / 2；不成功为3 *( n + 1 ) / 4

### 有序表的查找
#### 折半查找

```
int searchBin (int * array, int key, int arrayLength) {
    int low = 0, high = arrayLength - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == array[mid])
            return mid;
        else if (key < array[mid])
            high = mid - 1;
        else low = mid + 1;
    }
return -1;
```

##### 性能分析
平均查找长度
`ASL = (n + 1) / n log(n + 1）- 1`






