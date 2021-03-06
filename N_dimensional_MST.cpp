//calculation weight of maximum spanning tree of n dimensional nodes using manhattan distance
//DDIMST
//problem link: https://www.codechef.com/OCT20A/problems/DDMIST
//tutorial link: https://discuss.codechef.com/t/ddimmst-editorial/79385


#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e5 + 7;

int dsu[N];

int get(int v) {
  if (v == dsu[v]) return v;
  else return dsu[v] = get(dsu[v]);
}

void uni(int u, int v) {
  dsu[get(u)] = get(v);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, d;
  cin >> n >> d;
  vector <vector <int> > x(n, vector <int> (d));
  for (int i = 0; i < n; i++) for (int j = 0; j < d; j++) cin >> x[i][j];
  vector <pair <int, pair <int, int> > > e;
  auto add_edge = [&] (int u, int v) {
    int sum = 0;
    for (int i = 0; i < d; i++)
      sum += abs(x[u][i] - x[v][i]);
    e.push_back({sum, {u, v}});
  };
  for (int mask = 0; mask < (1 << d); mask++) {
    vector <pair <int, int> > e;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < d; j++) {
        if ((mask >> j) & 1) {
          sum += x[i][j];
        } else {
          sum -= x[i][j];
        }
      }
      e.push_back({sum, i});
    }
    int s = min_element(e.begin(), e.end())->second;
    int t = max_element(e.begin(), e.end())->second;
    for (int x = 0; x < n; x++) {
      add_edge(s, x);
      add_edge(t, x);
    }
  }
  sort(e.rbegin(), e.rend());
  for (int i = 0; i < n; i++) dsu[i] = i;
  ll ans = 0;
  for (auto c : e) {
    int u = c.second.first, v = c.second.second;
    if (get(u) != get(v)) {
      uni(u, v);
      ans += c.first;
    }
  }
  cout << ans << '\n';
}
