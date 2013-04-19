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

int n;
int Kcnt[210], K[210][410]; //  1 <= K[i][j] <= 200(MAX_keytype)
int T[210]; // 1 <= T[i] <= 200(MAX_keytype)

bool checked[(1<<20)];
VI res;

void init() {
}

void input() {
    res.clear();
    cin >> Kcnt[0] >> n;
    REP(i, Kcnt[0]) cin >> K[0][i];
    REP(i, n){
        cin >> T[i+1] >> Kcnt[i+1];
        REP(j, Kcnt[i+1]) cin >> K[i+1][j];
    }
}



bool dfs(int S){
    if(checked[S]) return false;
    checked[S] = true;
    if(S == (1<<n)-1) return true;
    
    int key[210];
    REP(i, 210) key[i] = 0;
    REP(i, Kcnt[0]) key[K[0][i]]++;
    REP(i, n) if(S & (1 << i)) {
        REP(j, Kcnt[i+1]) key[K[i+1][j]]++;
        key[T[i+1]]--;
    }
    
    REP(i, n) if(!(S & (1 << i)) && key[T[i+1]] > 0){
        if(dfs(S | (1 << i))){
            res.PB(i);
            return true;
        }
    }
    return false;
    
}

void solve() {
    REP(i, (1<<20)) checked[i] = false;
    if(dfs(0)){
        reverse(ALL(res));
        gout << "";
        REP(i, SZ(res)) printf("%d%c", res[i] + 1, i == SZ(res)-1 ? '\n' : ' ');
        return;
    }
    gout << "IMPOSSIBLE" << endl;
    return;
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
