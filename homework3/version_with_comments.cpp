#include <algorithm> // std::sort
#include <iostream>  // std::cout，cin
#include <vector>    // std::vector
using namespace std;
struct A {
  int id, s, f, val;
};
// sort finish time 时要用
bool cmp2(A const &a, A const &b) { return a.f < b.f; }

int main() {
  int n = 0;              //共有多少笔data
  int k = 0;              // 每笔data里有多少个活动
  int maxActListSize = 0; //最大value取值时活动集合的size
  int tempASize = 0; //当前要检查的这笔data，这个原始活动集合
  vector<vector<A>> aList; //所有输入的原始资料
  A aS;                    //临时存放输入的一个活动结构
  cin >> n;
  //从input中读取并存入每笔data的所有活动
  for (int i = 0; i < n; ++i) {
    vector<A> tempA;
    cin >> k;
    for (int j = k; j > 0; --j) {
      cin >> aS.id;
      cin >> aS.s;
      cin >> aS.f;
      cin >> aS.val;
      tempA.push_back(aS);
    }
    aList.push_back(tempA);
  }
  //循环每笔data，并输入最大value值及其活动组合id
  for (int m = 0; m < n; ++m) {
    tempASize = (int)aList[m].size();
    sort(aList[m].begin(), aList[m].end(), cmp2); // sort by finish time asc
    vector<int> res;
    //新建res临时变量，存放当前这笔data里所有活动的value
    for (int i = 0; i < tempASize; ++i) {
      res.push_back(aList[m][i].val);
    }
    int t = -100; //为了避免小于活动的最小值（负数）
    //检查当前这笔资料里所有活动
    for (int i = 1; i < tempASize; ++i) {
      //如果活动value大于0才会去参与记录和比较，否则直接跳过
      if (aList[m][i].val > 0) {
        //轮询当前活动之前的所有活动
        for (int j = 0; j < i; ++j) {
          //在之前每轮的所有可能活动组合中（res中与t配合就可以找出来），找到组合里最后一个活动在当前活动的前面
          if (aList[m][j].f <= aList[m][i].s) {
            //在这里，当前活动肯定是正的。记录了本轮的最大值
            //比较当前活动的value与（之前每轮的最大值活动组合的value总和+当前活动的value）
            res[i] = max(res[i], aList[m][i].val + res[j]);
          }
          // t永远保留最大value值，它的作用就是与res配合可以相应找出对应的活动组合。
          t = max(res[i], t);
        }
      }
    }
    // print max value
    if (t != -100) {
      //当前笔data中的活动数量大于1
      cout << t << endl;
      vector<int> maxActList;
      //每次和res[i]比较，如果相等，说明此轮时最大值是被更新的；那么减去当前轮对应的这个活动value就得到了上次更新后的t值。
      //如此循环，每次相等的活动取出来并组合就是最后想要的最大值时的活动组合。因为如果不相等，可能就是当时的最大值活动组合而不是整体最大值
      for (int i = (int)res.size() - 1; i >= 0; --i) {
        if (res[i] == t) {
          t = t - aList[m][i].val;
          maxActList.push_back(aList[m][i].id);
        }
      }
      maxActListSize = (int)maxActList.size();
      //把最大值value情况下的活动id按照从小到大排序
      sort(maxActList.begin(), maxActList.end());
      for (int i = 0; i < maxActListSize - 1; ++i) {
        cout << maxActList[i] << " ";
      }
      cout << maxActList[maxActListSize - 1] << endl;
    } else {
      //当前笔data中的活动数量等于1时直接输出结果
      cout << aList[m][0].val << endl;
      cout << aList[m][0].id << endl;
    }
  }
  return 0;
}
