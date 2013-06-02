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

LL MOD = 1000002013;

LL p1, p2;
LL N, M;
LL o[1010], e[1010], p[1010];
vector < pair<LL, pair<int, LL> > > table; //station, (start/end), p

void init() {
}

void input() {
	table.clear();
	cin >> N >> M;
	REP(i, M){
		cin >> o[i] >> e[i] >> p[i];
		pair<LL, pair<int, LL> > tmp0 = make_pair(o[i], make_pair(0, p[i]));
		pair<LL, pair<int, LL> > tmp1 = make_pair(e[i], make_pair(1, p[i]));
		table.push_back(tmp0);
		table.push_back(tmp1);
	}
	sort(ALL(table));
	p1 = 0; p2 = 0;
}

void solve() {
	REP(i, M){
		LL m = (e[i]-o[i]+MOD)%MOD;
		LL pp = (((m*(m-1))/2) % MOD ) % MOD;
		p1 = (p1 + (pp * p[i])%MOD ) % MOD;
	}
	pair<LL, LL> stk[2010]; //station, start_p
	int ptr = -1;
	REP(i, SZ(table)){
		LL station = table[i].first;
		int start_end = table[i].second.first;
		LL tickets = table[i].second.second;
		if(start_end == 0) stk[++ptr] = make_pair(station, tickets);
		else{
			LL remain = tickets;
			while(remain){
				LL use = min(remain, stk[ptr].second);
				LL m = (station-stk[ptr].first+MOD)%MOD;
				LL pp = (((m*(m-1))/2) % MOD ) %MOD;
				p2 = (p2 + (pp * use)%MOD ) % MOD;
				remain -= use;
				stk[ptr].second -= use;
				if(stk[ptr].second == 0) ptr--;
			}
		}
	}
	assert(ptr == -1);
	assert(stk[0].second == 0);
	assert(stk[1].second == 0);
	gout << (p2 - p1 + MOD) % MOD << endl;
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
