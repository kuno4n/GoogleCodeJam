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

const int MAX_V = 6400;

int V;
VI G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v){
    G[u].PB(v);
    G[v].PB(u);
}

bool dfs(int v){
    used[v] = true;
    REP(i, SZ(G[v])){
        int u = G[v][i], w = match[u];
        if(w < 0 || (!used[w] && dfs(w))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(){
    int res = 0;
    MSET(match, -1);
    REP(v, V){
        if(match[v] < 0){
            MSET(used, 0);
            if(dfs(v)) res++;
        }
    }
    return res;
}



int m, n;
char seat[80][80];

void init() {
}

void input() {
    cin >> m >> n;
    REP(i, m) REP(j, n) cin >> seat[i][j];
    REP(i, MAX_V) G[i].clear();
}

void solve() {
    V = m*n;
    int num = 0;
    REP(i, m) REP(j, n){
        if(seat[i][j] == '.'){
            num++;
            if(j < n-1){
                if(seat[i][j+1] == '.') add_edge(i*n + j+1, i*n + j);
                if(i > 0 && seat[i-1][j+1] == '.') add_edge((i-1)*n + j+1, i*n + j);
                if(i < m-1 && seat[i+1][j+1] == '.') add_edge((i+1)*n + j+1, i*n + j);
            }
        }
    }
    gout << num - bipartite_matching() << endl;
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
