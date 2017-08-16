#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int inf = 1000*1000;

vector<pair<int,int> > ans;
vector<pair<int,int> > edges;
vector<int> ch[101];
int n,m;

int calc(int root) {
  queue<pair<int,int> > q;
  q.push(make_pair(root, 0));
  pair<int,int> p;
  int v,d;
  int max, max_prev;
  max = max_prev = 0;
  bool visited[101];
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
  int cnt = 0;
  while (!q.empty() && cnt < n - 1) {
    p = q.front();
    v = p.first;
    d = p.second;
    visited[v] = true;
    q.pop();
    for (int i = 0; i < ch[v].size(); i++) {
      if (!visited[ch[v][i]]) {
        cnt++;
        visited[ch[v][i]] = true;
        if (d+1 > max) {
          max_prev = max;
          max = d + 1;
        } else if (d+1 > max_prev) {
          max_prev = d + 1;
        }
        q.push(make_pair(ch[v][i], d+1));
      }
    }
  }

  return max + max_prev;
}

int calc_edge(int u, int v) {
  queue<pair<int,int> > q;
  q.push(make_pair(u, 0));
  q.push(make_pair(v, 0));
  pair<int,int> p;
  int d;
  int max, max_prev;
  max = max_prev = 0;
  bool visited[101];
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
  int cnt = 1;
  visited[u] = visited[v] = true;
  while (!q.empty() && cnt < n - 1) {
    p = q.front();
    v = p.first;
    d = p.second;
    q.pop();
    for (int i = 0; i < ch[v].size(); i++) {
      if (!visited[ch[v][i]]) {
        cnt++;
        visited[ch[v][i]] = true;
        if (d+1 > max) {
          max_prev = max;
          max = d + 1;
        } else if (d+1 > max_prev) {
          max_prev = d + 1;
        }
        q.push(make_pair(ch[v][i], d+1));
      }
    }
  }

  if (max + max_prev) {
    return max + max_prev+1;
  } else {
    return 1;
  }
}

void calc_ans(int root) {
  queue<int> q;
  q.push(root);
  int v;
  bool visited[101];
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }

  while (!q.empty() && ans.size() < n - 1) {
    v = q.front();
    visited[v] = true;
    q.pop();
    for (int i = 0; i < ch[v].size(); i++) {
      if (!visited[ch[v][i]]) {
        visited[ch[v][i]] = true;
        ans.push_back(make_pair(v, ch[v][i]));
        q.push(ch[v][i]);
      }
    }
  }
}

void calc_ans_edge(int u, int v) {
  queue<int> q;
  q.push(u);
  q.push(v);
  pair<int,int> p;
  int max, max_prev;
  max = max_prev = 0;
  bool visited[101];
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
  visited[v] = visited[u] = true;
  ans.push_back(make_pair(u,v));
  while (!q.empty() && ans.size() < n - 1) {
    v = q.front();
    q.pop();
    for (int i = 0; i < ch[v].size(); i++) {
      if (!visited[ch[v][i]]) {
        visited[ch[v][i]] = true;
        ans.push_back(make_pair(v, ch[v][i]));
        q.push(ch[v][i]);
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int x, y;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    ch[x].push_back(y);
    ch[y].push_back(x);
    edges.push_back(make_pair(x,y));
  }

  int center_point, center_edge;
  int point_dia = inf, r, edge_dia = inf;
  for (int j = 1; j <= n; j++) {
    r = calc(j);
    if (r < point_dia) {
      center_point = j;
      point_dia = r;
    }
  }

  for (int j = 0; j < edges.size(); j++) {
    r = calc_edge(edges[j].first, edges[j].second);
    if (r < edge_dia) {
      center_edge = j;
      edge_dia = r;
    }
  }

  if (point_dia < edge_dia) {
    calc_ans(center_point);
  } else {
    calc_ans_edge(edges[center_edge].first, edges[center_edge].second);
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }

  return 0;
}
