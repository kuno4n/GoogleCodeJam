#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

int r, c, h, v;
string vs[110];

void init() {
}

void input() {
  cin >> r >> c >> h >> v;
  REP(i, r) cin >> vs[i];
}

void solve() {
  int all = 0;
  REP(i, r) REP(j, c) if(vs[i][j] == '@') all++;
  int div = (h+1)*(v+1);
  if (all%div != 0) {
    gout << "IMPOSSIBLE" << endl;
    return;
  }
  int part = all/div;
  int part_h = all/(h+1);
  int part_v = all/(v+1);

  if (part == 0) {
    gout << "POSSIBLE" << endl;
    return;
  }

  VI div_h;
  int cnt = 0;
  REP(i, r) {
    REP(j, c) if(vs[i][j] == '@') cnt++;
    if (cnt > part_h) {
      gout << "IMPOSSIBLE" << endl;
      return;
    }
    if (cnt == part_h) {
      div_h.push_back(i+1);
      cnt = 0;
    }
  }
  if (SZ(div_h) != h+1) {
    gout << "IMPOSSIBLE" << endl;
    return;
  }

  VI div_v;
  cnt = 0;
  REP(j, c) {
    REP(i, r) if(vs[i][j] == '@') cnt++;
    if (cnt > part_v) {
      gout << "IMPOSSIBLE" << endl;
      return;
    }
    if (cnt == part_v) {
      div_v.push_back(j+1);
      cnt = 0;
    }
  }
  if (SZ(div_v) != v+1) {
    gout << "IMPOSSIBLE" << endl;
    return;
  }

  REP(i, SZ(div_h)) {
    int start_h = (i == 0 ? 0 : div_h[i-1]);
    int end_h = div_h[i];
    REP(j, SZ(div_v)) {
      int start_v = (j == 0 ? 0 : div_v[j-1]);
      int end_v = div_v[j];

      cnt = 0;
      // printf("%d %d %d %d \n", start_h, end_h, start_v, end_v);
      FOR(ii, start_h, end_h) FOR(jj, start_v, end_v) if(vs[ii][jj] == '@') cnt++;
      // cout << cnt << endl;
      if (cnt != part) {
        gout << "IMPOSSIBLE" << endl;
        return;
      }
    }
  }
  gout << "POSSIBLE" << endl;
}

int main() {
	init();
	int number_of_test_cases;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases){
		input();
		solve();
	}
	return 0;
}
