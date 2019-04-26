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

int bitcnt(LL n){
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}

LL r, b, c;
LL m[1010], s[1010], p[1010];

void init() {

}

void input() {
  cin >> r >> b >> c;
  REP(i, c) cin >> m[i] >> s[i] >> p[i];
}

bool C(LL sec) {
  vector<LL> vl;
  REP(i, c) {
    vl.push_back(min(m[i], max(0LL, (sec-p[i])/s[i])));
  }
  sort(ALL(vl));
  reverse(ALL(vl));
  LL bit = accumulate(vl.begin(), vl.begin()+r, 0LL);
  if (bit >= b) return true;
  return false;
}

void solve() {
  LL lo = 0;
  LL hi = (1LL<<60);
  while(lo+1 < hi) {
    LL mid = (lo + hi) / 2;
    if (C(mid)) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  gout << hi << endl;
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
