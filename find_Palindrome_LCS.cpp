/*
Dynamic programming

HW2 15-2 Longest palindrome subsequence
A palindrome is a nonempty string over some alphabet that reads the same forward and backward. Examples of palindromes are all strings of length 1, civic, racecar, and aibohphobia (fear of palindromes). Give an efficient algorithm to find the longest palindrome that is a subsequence of a given input string. For example, given the input character, your algorithm should return carac.
 
題目說明：
給定字串，請找出其中最長且是迴文的子序列及其長度，字串由連續字符、字母或數字所組成，且其給定字串長度不會超過1000。
 
螢幕輸入:
輸入測資的第一行(N)為測資個數，代表接下來會有N筆給定字串，每筆測資為一行。
 
螢幕輸出:
待輸入測資讀取結束後再輸出結果。每筆測資用兩行輸出答案，第一行輸出子序列最長迴文長度，第二行輸出最長迴文子序列。請勿輸出任何其他文字或符號等。

Example： 
螢幕輸入:
2
514a3ab1
61bca7a8sb6
 
螢幕輸出:
5
1a3a1
7
6ba7ab6
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

static vector <vector<int> > c ;
static string palinadromeLCS = "";
static string reverseStr;

string reverseString(string str)
{
	reverseStr = "";
	char temp[str.size()];
	strcpy(temp, str.c_str());

	for (int i = str.size() - 1; i >= 0 ; --i)
	{
		reverseStr = reverseStr + temp[i];
	}
	return reverseStr;
}

void findLCSInTwoSequence(char X[], char Y[])
{
	int m = strlen(X);

	c.resize(m + 1);

	for (int i = 0; i < m + 1; i++)
	{
		c[i].resize(m + 1);
		c[i][0] = 0;
		c[0][i] = 0;
	}

	for (int i = 1; i < m + 1; ++i)
	{
		for (int j = 1; j < m + 1; ++j)
		{
			if (X[i - 1] == Y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
			}
			else
			{
				c[i][j] = c[i][j - 1];
			}
		}
	}
}

void createLCS(char X[], char Y[], int i, int j)
{
	palinadromeLCS = "";
	if (i == 0 || j == 0)
	{
		return;
	}

	if (X[i - 1] == Y[j - 1])
	{
		createLCS(X, Y, i - 1, j - 1);
		palinadromeLCS = palinadromeLCS + X[i - 1];
	}
	else if (c[i - 1][j] >= c[i][j - 1])
	{
		createLCS(X, Y, i - 1, j);
	}
	else
	{
		createLCS(X, Y, i, j - 1);
	}
}
void findLCS(string input[], int inputSize)
{
	int strLength = 0;
	string XStr = "";
	string YStr = "";

	for (int m = 0; m < inputSize; ++m)
	{
		XStr = input[m];

		YStr = reverseString(input[m]);
		strLength = XStr.size();

		char X[strLength];
		char Y[strLength];
		strcpy(X, XStr.c_str());
		strcpy(Y, YStr.c_str());

		findLCSInTwoSequence(X, Y);
		createLCS(X, Y, strLength, strLength);

		cout << palinadromeLCS.size() << endl;
		cout << palinadromeLCS << endl;
	}
}

int main ()
{
	int n;
	cin >> n;
	string input[n] ;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	findLCS(input, n);

	return 0;
}