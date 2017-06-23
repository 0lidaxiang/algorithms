#include <iostream>
#include <vector>
using namespace std;

static int e  = 0, v = 0 , graph_index  = 0, temp_v_size = 0, temp_edge_size = 0;
vector< vector<int> > graph(1000);
vector<int> color(1000 , 0);
vector<int> result(1000 , 1);

void dfs_visit(int root_index)
{
  color[root_index] = 1;

  int adjSize = graph[root_index].size();
  for (int m = 0; m < adjSize; ++m)
  {
    if (graph[root_index][m] < 1000)
    {
      if (color[m] ==  2)
      {
        result[graph_index] = 0;
        break;
      }
      else if (color[m] == 0)
      {
        dfs_visit(m);
      }
    }
  }
  color[root_index] = 2;
}

void dfs_scc()
{
  int temp_graph_size = graph.size();

  for (int i = 0; i < temp_graph_size; ++i)
  {
    if (result[graph_index] == 0)
    {
      break;
    }

    for (int j = 0; j < temp_graph_size; ++j)
    {
      if (result[graph_index] == 0)
      {
        break;
      }

      for (int m = 0; m < temp_graph_size; ++m)
      {
        if (color[m] != 0)
        {
          color[m] = 0;
        }
      }
      dfs_visit(i);
    }
  }
}

void add_node(int id, int child_id)
{
  if (graph[id].empty())
  {
    graph[id].resize(v , 1000);
    color[id] = 0;
    temp_v_size++;
  }

  if (graph[child_id].empty())
  {
    graph[child_id].resize(v , 1000);
    color[child_id] = 0;
    temp_v_size++;
  }

  bool is_find_child = false;
  int adj_size = graph[id].size();
  for (int j = 0; j < adj_size; ++j)
  {
    if (graph[id][j] == child_id)
    {
      is_find_child = true;
      break;
    }
  }
  if (!is_find_child)
  {
    temp_edge_size++;
    graph[id][child_id] = child_id;
  }
}

int main ()
{
  int n = 0, id = 0, child = 0;
  cin >> n;
  result.resize(n, 1);

  for (int m = 0; m < n; ++m)
  {
    cin >> v;
    cin >> e;

    temp_v_size = 0;
    temp_edge_size = 0;
    graph.resize(v);
    color.resize(v);
    if (v > e)
    {
      while (1) {
        if (temp_v_size < v)
        {
          cin >> id;
          cin >> child;
          add_node((int)id, (int)child);
        }
        else {
          break;
        }
      }
    }
    else {
      while (1) {
        if (temp_edge_size < e)
        {
          cin >> id;
          cin >> child;
          add_node((int)id, (int)child);
        }
        else {
          break;
        }
      }
    }

    int t_g_size = graph.size();
    for (int i = t_g_size - 1; i >= 0; --i)
    {
      int t_adj_size = graph[i].size();
      for (int j = t_adj_size - 1; j >= 0 ; --j)
      {
        if (*graph[i].end() == 0)
        {
          graph[i].pop_back();
          t_adj_size = t_adj_size - 1;
        }
        else {
          break;
        }
      }
    }

    graph.resize(temp_v_size);
    dfs_scc();
    graph.clear();
    vector< vector<int> >().swap(graph);
    graph_index++;
  }

  int resultSize = result.size();

  for (int i = 0; i < resultSize; i++) {
    if (result[i] == 1)
    {
      cout << i + 1 << " YES" << endl;
    }
    else
    {
      cout << i + 1 << " NO" << endl;
    }
  }

  result.clear();
  vector<int>().swap(result);

  return 0;
}