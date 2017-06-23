#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct A
{
	int id, s, f, val;
};
bool cmp2(A const &a, A const &b) {
	return a.f < b.f;
}
int main( )
{
	int n = 0;
	int k = 0;
	int maxActListSize = 0;
	int tempASize = 0;
	vector< vector<A> > aList;
	A aS;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		vector<A> tempA;
		cin >> k;
		for (int j = k; j > 0; --j)
		{
			cin >> aS.id;
			cin >> aS.s;
			cin >> aS.f;
			cin >> aS.val;
			tempA.push_back(aS);
		}
		aList.push_back(tempA);
	}
	for (int m = 0; m < n; ++m)
	{
		tempASize = (int)aList[m].size();
		sort(aList[m].begin(), aList[m].end(), cmp2);
		vector<int> res;
		for (int i = 0; i < tempASize; ++i)
		{
			res.push_back(aList[m][i].val);
		}
		int t = -100;
		for (int i = 1; i < tempASize; ++i)
		{
			if (aList[m][i].val > 0)
			{
				for (int j = 0; j < i; ++j)
				{
					if (aList[m][j].f <= aList[m][i].s)
					{
						res[i] = max(res[i] , aList[m][i].val + res[j]);
					}
					t = max(res[i], t);
				}
			}
		}
		if (t != -100)
		{
			cout << t << endl;
			vector<int> maxActList;
			for (int i = (int)res.size() - 1; i >= 0; --i)
			{
				if (res[i] == t)
				{
					t = t - aList[m][i].val;
					maxActList.push_back(aList[m][i].id);
				}
			}
			maxActListSize = (int)maxActList.size();
				sort(maxActList.begin(), maxActList.end());
				for (int i = 0; i < maxActListSize - 1; ++i)
				{
					cout << maxActList[i] << " ";
				}
				cout << maxActList[maxActListSize - 1] << endl;
		}
		else {
			cout << aList[m][0].val << endl;
			cout << aList[m][0].id << endl;
		}
	}
	return 0;
}
