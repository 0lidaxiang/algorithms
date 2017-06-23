# Introduction to Homework1 of Algorithm
> Author : 大祥  
> StartTime: 2017-06-23 ，ModifyTime：2017-06-23

## Requirement
**recursive and non-recursive version program**

求出一串數字中，連續區間中的和的最大值為多少？

請將課本方法以遞迴(HW1-1)與非遞迴(HW1-2)實現，程式直接讀取測資並以螢幕輸出。

輸入：  
第1行為一個整數n，接下來輸入n 個整數，n不超過100000  

輸出：  
給出這一串數字裡最大的連續區間index以及他們的和  

## Test Example
輸入範例：  
16  
13 -3 -25 20 -3 -16 -23 18 20 -1 12 -5 -22 15 -4 7   
8  
1 2 3 4 5 6 7 -7  

輸出範例：  
7 10 49  
0 6 28

## Introduction to My Program code
### 1.递归方法
递归方式的作业是参考书上内容。
将所有情况分为三种,一种是在 mid 左边,一种是在 mid 右边,一种是跨越了 mid。但是由
于跨越了 mid 的情况又可以分为 mid 左边和 mid 右边两种情况,所以可以通过对
find_maxmum_subarray 递归实现对所有情况的遍历,中间可能会访问
find_max_crossing_subarray ,但是最后都会归结到一个元素的基本情况,这时会直接返回。

### 2.非递归方法
给定一个数组,若想求它的最大子数组,还可以用动态规划方法来做。这里采取的办法是用
空间换时间,但由于本题中只需要记载最大子数组,所以我只需要设置变量记住取得最大子
数组时左边界和右边界、以及找到第 i 个元素的目前最大值需要存起来,以便后期计算可以
调用。无需重新计算。所以这里只需要用一个除了 main 函数以外的函数 bottom_up_cut_rod
计算动态规划就可以了。
