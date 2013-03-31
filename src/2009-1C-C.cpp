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
#include "cout.h"

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

int INF = (1<<29);

int p, q, Q[100];
VI a;
int dp[102][102];

void init() {
}

void input() {
    cin >> p >> q;
    REP(i, q) cin >> Q[i];
}

void solve() {
    a.clear();
    REP(i, q) a.push_back(Q[i]);
    a.push_back(0);
    a.push_back(p+1);
    sort(ALL(a));
    
    REP(i, 102) REP(j, 102) dp[i][j] = INF;
    REP(i, q+1) dp[i][i+1] = 0;
    
    for(int i = 1; i <= q; i++) for(int j = 0; j <= q-i; j++) for(int k = 1; k <= i; k++)
        dp[j][j+i+1] = min(dp[j][j+i+1], dp[j][j+k] + dp[j+k][j+i+1] + a[j+i+1]-a[j]-2);
    
    gout << dp[0][q+1] << endl;
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
