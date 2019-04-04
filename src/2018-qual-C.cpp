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


int a;

void init() {
}

void input() {
  cin >> a;
}

void solve() {
  int m[1010][1010];
  REP(i, 1010) REP(j, 1010) m[i][j] = 0;
  int curX = 2;
  int curY = 2;
  while(1) {
    bool ok = true;
    FOR(i, curX-1, curX+2) FOR(j, curY-1, curY+2) {
      if (m[i][j] == 0) ok = false;
    }
    if (ok) {
      curX += 3;
    }
    cout << curX << " " << curY << endl;
    int b, c;
    cin >> b >> c;
    if (b == 0 || b == -1) break;
    m[b][c] = 1;
  }
}

int main() {
	init();
	int number_of_test_cases;
	cin >> number_of_test_cases;
	REP(i,number_of_test_cases){
		input();
		solve();
	}
	return 0;
}
