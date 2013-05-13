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

int x, y;

void init() {
}

void input() {
	cin >> x >> y;
}

void solve() {
	string res = "";
	int n = 1;
	for(;;n++){
		LL all = (n*(n+1))/2;
		LL man = abs(x) + abs(y);
		if(all >= man && ((all&1) == (man&1))) break;
	}
	for(int i = n; i >= 1; i--){
		if(abs(x) >= abs(y)){
			if(x >= 0) {
				res.PB('E');
				x -= i;
			}
			else{
				res.PB('W');
				x += i;
			}
		}
		else{
			if(y >= 0) {
				res.PB('N');
				y -= i;
			}
			else{
				res.PB('S');
				y += i;
			}
		}
	}
	reverse(ALL(res));
	gout << res << endl;
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
