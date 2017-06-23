#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 存放结node
struct Node{
  int id;
  int p;
};
// 存放所有的 node 的 森林或者single tree
vector<Node> tree;
// store the size of nodes
static int treeSize = 0;

// make a tree Or node
void make_tree(int nodeId)
{
  Node node;
  node.id = nodeId;
  tree.push_back(node);
}
// 合并 two sub-trees
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

//find a node depth of tree[parrentIndex]
int find_depth(int parrentIndex)
{
  int d = 0;
  int parrentId = tree[parrentIndex].p;

  for (int i = 0; i < treeSize; i++) {
    if (parrentId == tree[i].id) {
      d = find_depth(i) + 1;  // this one node depth + 1 when finding its parrent node
      break;
    }
  }
  return d;
}

int main ()
{
  int r, v, nodeId;
	string str = ""; // store the first row & first col, the command
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
      int parrentIndex = 0;  // find the index of the user input node_id
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
