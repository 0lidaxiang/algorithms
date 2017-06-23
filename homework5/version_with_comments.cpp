#include <iostream>
#include <vector>
using namespace std;
// e 表示边数,v 表示输入的 node 数量, graph_index 表示当前是第几个
// graph, temp_v_size 表示实际存储到 graph (vector)中的 vertex 数量,
// temp_edge_size 表示 输入的边数,在 v>n 时方便计算实际存储到 graph (vector)中的
// vertex 数量。
static int e = 0, v = 0, graph_index = 0, temp_v_size = 0, temp_edge_size = 0;
// 存储 vertex,index 表示 parent vertex,value 表示它的邻接表-child_indexs
vector<vector<int>> graph(1000);
// index 对应上面的 graph index,表示每个 vertext 的颜色
vector<int> color(1000, 0);
// 表示每个图的判定是否是 singly-connected 的结果,0 表示不是,1 表示是
vector<int> result(1000, 1);
// 从 root_index 开始递归的用 dfs 搜索所有节点,直到发现一个 v.color=2
// 也就是黑色时, 跳出循环,因为这表明该图还有 front edge 和 cross edge,所以它不是
// singly connected
void dfs_visit(int root_index) {
  color[root_index] = 1;
  int adjSize = graph[root_index].size();
  // 循环 root_index 节点的所有邻接表,也就是所有 child_node
  for (int m = 0; m < adjSize; ++m) {
    if (graph[root_index][m] < 1000) {
      // 发现子节点 v.color=2 也就是黑色
      if (color[m] == 2) {
        // 存储这个图的判定结果,0 表示非 singly connected
        result[graph_index] = 0;
        break;
      }
      // 发现子节点 v.color=0 也就是白色,则继续 dfs 寻找
      else if (color[m] == 0) {
        dfs_visit(m);
      }
    }
    3 / 7
  }
  color[root_index] = 2;
}
// 用两层 loop dfs 方法判定当前 graph 是否是 singly connected
void dfs_scc() {
  //当前 graph 的大小
  int temp_graph_size = graph.size();
  //以所有的 node 为起点
  for (int i = 0; i < temp_graph_size; ++i) {
    // 如果中途已经发现这个 graph 不是 singly connected,那么直接跳出
    if (result[graph_index] == 0) {
      break;
    }
    // 以所有的其他点为终点,进行 dfs 搜索
    for (int j = 0; j < temp_graph_size; ++j) {
      if (result[graph_index] == 0) {
        break;
      }
      // 在 dfs 之前先重新恢复由于上次 dfs 导致的 node 颜色变化
      for (int m = 0; m < temp_graph_size; ++m) {
        if (color[m] != 0) {
          color[m] = 0;
        }
      }
      dfs_visit(i);
    }
  }
}
// 添加 node
void add_node(int id, int child_id) {
  // 如果父节点的邻接表为空,那么表示父节点尚未被添加进图,则执行添加操作
  if (graph[id].empty()) {
    4 / 7graph [id].resize(v, 1000);
    color[id] = 0;
    temp_v_size++;
  }
  // 如果子节点的邻接表为空,那么表示子节点尚未被添加进图,则执行添加操作
  if (graph[child_id].empty()) {
    graph[child_id].resize(v, 1000);
    color[child_id] = 0;
    temp_v_size++;
  }
  // 检查子节点是否存在于父节点的邻接表中
  bool is_find_child = false;
  int adj_size = graph[id].size();
  for (int j = 0; j < adj_size; ++j) {
    if (graph[id][j] == child_id) {
      is_find_child = true;
      break;
    }
  }
  // 检查子节点是否存在于父节点的邻接表中,若不存在则添加
  if (!is_find_child) {
    temp_edge_size++;
    graph[id][child_id] = child_id;
  }
}
int main() {
  int n = 0, id = 0, child = 0;
  cin >> n;
  result.resize(n, 1);
  for (int m = 0; m < n; ++m) {
    cin >> v;
    cin >> e;
    temp_v_size = 0;
    5 / 7temp_edge_size = 0;
    graph.resize(v);
    color.resize(v);
    // 取 v 和 e 中较大值为标准,来建构当前 graph
    if (v > e) {
      while (1) {
        if (temp_v_size < v) {
          cin >> id;
          cin >> child;
          add_node((int)id, (int)child);
        } else {
          break;
        }
      }
    } else {
      while (1) {
        if (temp_edge_size < e) {
          cin >> id;
          cin >> child;
          add_node((int)id, (int)child);
        } else {
          break;
        }
      }
    }
    int t_g_size = graph.size();
    //删掉多余的邻接表中的元素
    for (int i = t_g_size - 1; i >= 0; --i) {
      int t_adj_size = graph[i].size();
      for (int j = t_adj_size - 1; j >= 0; --j) {
        if (*graph[i].end() == 0) {
          graph[i].pop_back();
          6 / 7t_adj_size = t_adj_size - 1;
        } else {
          break;
        }
      }
    }
    // 释放 memory
    graph.resize(temp_v_size);
    // 对当前 graph 进行判定是否是 singly connected
    dfs_scc();
    graph.clear();
    vector<vector<int>>().swap(graph);
    graph_index++;
  }
  int resultSize = result.size();
  // 输出结果
  for (int i = 0; i < resultSize; i++) {
    if (result[i] == 1) {
      cout << i + 1 << " YES" << endl;
    } else {
      cout << i + 1 << " NO" << endl;
    }
  }
  // 清理 memory
  result.clear();
  vector<int>().swap(result);
  return 0;
}
