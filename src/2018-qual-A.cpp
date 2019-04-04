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


LL D;
string S;

void init() {
}

LL cnt(string s) {
  LL c = 1;
  LL res = 0;
  REP(i, SZ(s)) {
    if (s[i] == 'C') c <<= 1;
    else res += c;
  }
  return res;
}

string swap(string s) {
  for (int i = SZ(s)-2; i >= 0; i--) {
    if (s[i] == 'C' && s[i+1] == 'S') {
      s[i] = 'S';
      s[i+1] = 'C';
      return s;
    }
  }
  return "NG";
}

void input() {
  cin >> D >> S;
  int res = 0;
  while(1) {
    if(cnt(S) <= D) {
      gout << res << endl;
      return;
    }
    S = swap(S);
    res++;
    if (S == "NG") {
      gout << "IMPOSSIBLE" << endl;
      return;
    }
  }
}

void solve() {
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
