// Algorithm analysis
// 이분 매칭 알고리즘 (Bipartite Matching)
#include <iostream>
#include <vector>

using namespace std;
#define MAX_N 201
#define MAX_M 201

int n,m;
bool adj[MAX_N][MAX_M];
vector<int> aMatch, bMatch;
vector<bool> visited;

bool dfs(int a) {
  if (visited[a]) return false;
  visited[a] = true;
  for (int b = 0; b < m; b++) {
    if (adj[a][b]) {
      if (bMatch[b] == -1 || dfs(bMatch[b])) {
        aMatch[a] = b;
        bMatch[b] = a;

        return true;
      }
    }
  }
  return false;
}

int bipartiteMatch() {
  aMatch = vector<int>(n, -1);
  bMatch = vector<int>(m, -1);

  int size = 0;

  for(int start = 0; start < n; start++) {
    visited = vector<bool>(n, false);
    if (dfs(start)) size++;
  }
  return size;
}

int main() {
  n = 4;
  m = 4;

  adj[0][0] = 1;
  adj[0][1] = 1;
  adj[0][3] = 1;

  adj[1][0] = 1;
  adj[1][1] = 1;

  adj[2][0] = 1;
  adj[2][2] = 1;

  adj[3][2] = 1;
  adj[3][3] = 1;

  cout << bipartiteMatch() << endl;
  return 0;

}