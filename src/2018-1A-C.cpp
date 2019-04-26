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

int n;
double p;
LL w[300];
LL h[300];

vector < pair < double, double > > seg;

void init() {
}

void input() {
  cin >> n >> p;
  REP(i, n) cin >> w[i] >> h[i];
}

void solve() {
  seg.clear();
  double sum = 0;
  REP(i, n) sum += (w[i]+h[i])*2.0;
  seg.push_back(make_pair(sum, sum));
  REP(i, n) {
    vector < pair < double, double > > tmp;
    vector < pair < double, double > > _new;

    for(auto s : seg) {
      tmp.push_back(s);
      tmp.push_back(make_pair(s.first + min(w[i],h[i])*2, s.second + sqrt(w[i]*w[i]+h[i]*h[i])*2));
    }
    sort(ALL(tmp));

    pair < double, double > cur = make_pair(-1, -1);
    for(auto s: tmp) {
      if (cur.first == -1) {
        cur = s;
        continue;
      }
      if (s.first <= cur.second ) {
        cur.second = max(cur.second, s.second);
        continue;
      }
      _new.push_back(cur);
      cur = s;
    }
    _new.push_back(cur);
    seg = _new;
  }

  gout << "";
  REP(i, SZ(seg)) {
    if (p < seg[i].first) {
      printf("%.6f\n", seg[i-1].second);
      return;
    }
    if (seg[i].first <= p && p <= seg[i].second) {
      printf("%.6f\n", p);
      return;
    }
  }
  printf("%.6f\n", seg[SZ(seg)-1].second);
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
