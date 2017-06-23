#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

static vector<vector<int>> c;
static string palinadromeLCS = "";
static string reverseStr;

// create a reverse order string of string str
string reverseString(string str) {
  reverseStr = "";
  char temp[str.size()];
  strcpy(temp, str.c_str());

  // read str by reverse order
  for (int i = str.size() - 1; i >= 0; --i) {
    reverseStr = reverseStr + temp[i];
  }
  return reverseStr;
}

//建立一个保存了每个字符比对后是否增加了longest palindrome
// subsequence结果的table以及该字符的 index
void findLCSInTwoSequence(char X[], char Y[]) {
  int m = strlen(X);

  c.resize(m + 1);

  for (int i = 0; i < m + 1; i++) {
    c[i].resize(m + 1);
    c[i][0] = 0;
    c[0][i] = 0;
  }

  // build table
  for (int i = 1; i < m + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      // this means the next same char is X[i - 1].So, the length of
      // longest-palindrome-subsequence should be plus 1.
      if (X[i - 1] == Y[j - 1]) {
        c[i][j] = c[i - 1][j - 1] + 1;
      } else if (c[i - 1][j] >= c[i][j - 1]) {
        c[i][j] = c[i - 1][j];
      } else {
        c[i][j] = c[i][j - 1];
      }
    }
  }
}

// 根据之前建构的table创建出该string的longest palindrome subsequence
void createLCS(char X[], char Y[], int i, int j) {
  palinadromeLCS = "";
  if (i == 0 || j == 0) {
    return;
  }

  // record this char because X and Y all have it.
  if (X[i - 1] == Y[j - 1]) {
    createLCS(X, Y, i - 1, j - 1);
    palinadromeLCS = palinadromeLCS + X[i - 1];
  } else if (c[i - 1][j] >= c[i][j - 1]) {
    createLCS(X, Y, i - 1, j);
  } else {
    createLCS(X, Y, i, j - 1);
  }
}

// for循环对每个string做查找longest palindrome subsequence
void findLCS(string input[], int inputSize) {
  int strLength = 0;
  string XStr = "";
  string YStr = "";

  for (int m = 0; m < inputSize; ++m) {
    XStr = input[m];

    // 通过reverseString() 得到一个新的逆序string
    YStr = reverseString(input[m]);
    strLength = XStr.size();

    char X[strLength];
    char Y[strLength];
    strcpy(X, XStr.c_str());
    strcpy(Y, YStr.c_str());

    // 建立一个保存了每个字符比对后是否增加了longest palindrome
    // subsequence结果的table以及该字符的 index
    findLCSInTwoSequence(X, Y);
    // 根据之前建构的table创建出该string的longest palindrome subsequence
    createLCS(X, Y, strLength, strLength);

    // print 该string的longest palindrome subsequence
    cout << palinadromeLCS.size() << endl;
    cout << palinadromeLCS << endl;
  }
}

int main() {
  int n;
  cin >> n;
  string input[n];
  for (int i = 0; i < n; i++) {
    cin >> input[i];
  }
  findLCS(input, n);

  return 0;
}
