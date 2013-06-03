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

LL n, p;


bool always(LL team){
    LL rank = 0;
    LL remain = team + 1;
    int _n = n-1;
    while(remain > 1){
        rank += (1LL<<_n);
        _n--;
        remain >>=1;
    }
    if(rank < p) return true;
    else return false;
}

bool can(LL team){
    int win_cnt = 0;
    LL remain = (1LL<<n) - team;
    while(remain > 1){
        win_cnt++;
        remain >>= 1;
    }
    LL rank = (1LL<<(n-win_cnt)) - 1;
    if(rank < p) return true;
    else return false;
}


void init() {
}

void input() {
    cin >> n >> p;
}

void solve() {
    
    LL lo = 0, hi = (1LL<<n);
    while(hi - lo > 1){
        LL med = (lo+hi)/2;
        if(always(med)) lo = med;
        else hi = med;
    }
    gout << lo;
    
    cout << " ";
    
    lo = 0, hi = (1LL<<n);
    while(hi - lo > 1){
        LL med = (lo+hi)/2;
        if(can(med)) lo = med;
        else hi = med;
    }
    cout << lo;
    
    cout << endl;
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
