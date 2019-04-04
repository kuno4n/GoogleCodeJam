#define _USE_MATH_DEFINES
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

double a;

void init() {
}

void input() {
  cin >> a;
}

double calc() {
    double mn = M_PI/4;
    double mx = M_PI/2;
    int cnt = 0;
    while(1) {
      cnt++;
      double th = (mn+mx)/2.0;
      double tmp = M_SQRT2 * sin(th);
      if (abs(tmp-a) < 0.0000000001 || cnt > 100) {
        return th - M_PI/4;
      }
      if (tmp < a) mn = th;
      else mx = th;
    }
}

void solve() {
  double th = calc();
  double x = 0.5 * cos(th);
  double y = 0.5 * sin(th);
  gout << endl;
  printf("%.10f %.10f 0\n", x, y);
  printf("%.10f %.10f 0\n", y, -x);
  printf("0 0 0.5\n");
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
