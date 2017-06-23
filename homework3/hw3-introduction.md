# Introduction to Homework3 of Algorithm
> Author : 大祥  
> StartTime: 2017-06-23 ，ModifyTime：2017-06-23

## Requirement
**activity-selection problem**
給定N個工作，每個工作由編號，開始時間，結束時間和產值構成。選出能最大化產值的工作集合且其時間不會有重疊的情形。

輸入:

第一行為一整數n，代表接下來會有n筆測試資料 (n <= 10)。

每筆測試資料的第一行為一整數k(<=1000)，k代表接下來會有k行(表示該筆測資有k個activity)

每個activity由四個數字構成(皆為整數，中間用一個空白分開)，分別為activity的編號(number)、開始時間(start time>=0)、結束時間(finish time>0)、產值(value)。

輸出:  

螢幕輸出。每筆測資輸出兩行，  
第一行: activity不衝突的情況下，value總和的最大值為多少，  
第二行: 列出此最大化value的activity集合, 以activity的編號由小到大列出(每個activity編號中間請用空白鍵格開。

## Test Example
input：  
2  
3  
1 0 3 4  
2 3 4 1  
3 3 5 2  
5  
1 8 21 19  
2 10 15 12  
3 4 9 18  
4 20 30 25  
5 0 5 15

output:  
6  
1 3  
55  
2 3 4

## Introduction to My Program code
### a.此程式所使用之邏輯、原理及語言之概要性說明。
本次作业使用C++ program language。所以采用二维 vector 记录每笔输入的活动集合。第一维表示多少笔 data ，第二维存放每笔 data 的所有活动，使用 STL 中 algorithm library 中 sort function 排序。

#### 概要逻辑
主要逻辑是通过 DP 的方法，对一个已经按照 finish time 排好序的 list 进行从底向上的比较。从1个元素的比较开始，在这两个活动不重叠的情况下，用下面的最优子结构取得每增加一个活动进入计算后的最大产值(m表示第几笔data):

$$ res[i]= \begin{cases} aList[m][i].val, & \text {if $i$ is 0} \\ {max}(res[i], aList[m][i].val + res[j]), & \text{if $i$  $\geq$  1} \end{cases} $$

再利用一个 t 变量，记录当前截止的最大产值。
$$ t = {max}(res[i] , t) $$

#### 详细做法
对每笔资料用for循环检查，用 m 标记。对该笔 data （活动集合）：

1. 用 C++ sort function 按照结束时间属性排序所有活动。
2. 先把每个活动的val属性值也就是产值记录在新的 vector res里面，这里面记录了当前活动的最大产值。
3. 从第2个开始循环每个 res 中的值，用i标记。再开小的循环用j标记，循环在i之前的所有活动。    
在之前每个活动 aList[m][j]的结束时间小于当前活动 aList[m][i]的开始时间的条件下( **也就是不重叠**)，将其与之前所有的 res[j] + aList[m][i].val 中的值比较，用res[i]记录较大者。当j标记的小循环，轮询过之前所有活动后，res[i] 就得到了当前轮中的新最大值或者保持原来自己的value不变。
4. 得到每一轮的最大值后，在与t进行比较，如果比上轮最大值更大，那么t就会更新。**t永远记录到目前的活动为止的最大值。**  
t与res配合就能找出来参与到最大值的活动组合。
5. 当检测当前活动以前的小循环和循环所有活动的大循环都结束后，t就是题目要的最大value产值。
6. 输出最大value产值情况下的活动组合id：因为在res中要么当新增的活动能够增大整体最大产值时，res[i]才会变大；否则就是保持初始化时值不变。  
所以我可以用 **t与从最后一个开始res元素比较，当相等时说明就是在这里更新的，这个元素就是最大产值情况下的活动之一**，把它存到 maxActList 中。  
之后 把t减去这个元素原始value产值，得到上一次更新后的t值，再进行下一次比较...
7. 对新得到的 maxActList ，利用 C++ 中的 sort function 排序，得到新的从小到大的 活动组合 id。
