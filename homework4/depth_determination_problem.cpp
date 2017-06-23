#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node{
  int id;
  int p;
};
vector<Node> tree;
static int treeSize = 0;

void make_tree(int nodeId)
{
  Node node;
  node.id = nodeId;
  tree.push_back(node);
}
void graft(int r, int v)
{
  treeSize = tree.size();
  for (int i = 0; i < treeSize; i++) {
    if (tree[i].id == r)
    {
      tree[i].p = v;
      break;
    }
  }
}

int find_depth(int parrentIndex)
{
  int d = 0;
  int parrentId = tree[parrentIndex].p;

  for (int i = 0; i < treeSize; i++) {
    if (parrentId == tree[i].id) {
      d = find_depth(i) + 1;
      break;
    }
  }
  return d;
}

int main ()
{
  int r, v, nodeId;
	string str = "";
	while (1)
	{
		cin >> str;
    if (str == "M") {
      cin >> nodeId;
      make_tree(nodeId);
    }
    else if (str == "G") {
      cin >> r;
      cin >> v;
      graft(r, v);
    }
    else if (str == "F") {
      cin >> nodeId;
      treeSize = tree.size();
      int parrentIndex = 0;
      for (int i = 0; i < treeSize; i++) {
        if (tree[i].id == nodeId) {
          parrentIndex = i;
          break;
        }
      }
      cout << nodeId << " " << find_depth(parrentIndex) << endl;
    }
    else if (str == "E") {
      break;
    }
	}
	return 0;
}
