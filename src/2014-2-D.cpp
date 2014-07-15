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

int m, n;
string vs[4][8];
int ptr[4];

LL mx_trie;
LL mx_cnt;

string S[8];

void go(){
    REP(i, n) if(ptr[i] == 0) return;
    LL tmp_trie = 0;
    REP(i, n){
        set<string> s;
        s.insert("");
        REP(j, ptr[i]){
            string str = vs[i][j];
            REP(k, SZ(str)+1) s.insert(str.substr(0, k));
        }
        tmp_trie += SZ(s);
    }
    if(mx_trie < tmp_trie){
        mx_cnt = 1;
        mx_trie = tmp_trie;
    }
    else if(mx_trie == tmp_trie) mx_cnt++;
}

void dfs(int target){
    if(target == m){
        go();
        return;
    }
    REP(i, n){
        vs[i][ptr[i]++] = S[target];
        dfs(target+1);
        ptr[i]--;
    }
}

void init() {
}

void input() {
    cin >> m >> n;
    REP(i, m) cin >> S[i];
}

void solve() {
    mx_trie = 0;
    mx_cnt = 0;
    MSET(ptr, 0);
    dfs(0);
    gout << mx_trie << " " << mx_cnt << endl;
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


