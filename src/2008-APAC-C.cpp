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

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout


int m, x;
double p;

double dp[2][(1<<15)+1];

void init() {
}

void input() {
	cin >> m >> p >> x;
}

void solve() {

	REP(i, 2) REP(j, (1<<15)+1) dp[i][j] = 0.0;
	dp[0][0] = 0.0;
	dp[0][1] = 1.0;

	for(int i = 1; i <= m; i++){
		for(int mask = 0; mask <= (1<<i); mask++){
			for(int j = (1<<(i-1)); j >= 0; j--){
				if(j > mask) continue;
				int jj = mask - j;
				if(jj > j) break;
				dp[1][mask] = max(dp[1][mask], dp[0][j] * p + dp[0][jj] * (1-p));
			}
		}
		swap(dp[0], dp[1]);
		REP(i, (1<<15)+1) dp[1][i] = 0.0;
	}
	printg("%.8f\n", dp[0][(int)(x/(1000000.0/(1<<m)))]);
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
