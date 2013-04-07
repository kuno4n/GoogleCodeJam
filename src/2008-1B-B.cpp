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


int prime[1000010]; // i番目の素数。必要なら外出し。
bool is_prime[1000011]; // is_prime[i]がtrueならiは素数。必要なら外出し。

int sieve(int n){
    int p = 0;
    for(int i=0; i<=n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j=2*i; j<=n; j+=i) is_prime[j] = false;
        }
    }
    return p;
    
}


const int MAX_N = 1000010;
int par[MAX_N];  //親
int rank[MAX_N]; //木の深さ

// n要素で初期化
void uf_init(int n){
    REP(i, n){
        par[i] = i;
        rank[i] = 0;
    }
}
//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
//xとyの属する集合を結合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rank[x] < rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}
//xとyが同じ集合に属するか
bool same(int x, int y){
    return find(x) == find(y);
}



LL a, b, p;

void init() {
    sieve(1000005);
}

void input() {
    cin >> a >> b >> p;
}

void solve() {
    uf_init(b-a+1);
    for(int i = p; i < 1000005  ; i++) if(is_prime[i]){
        LL begin = ((a-1)/i) * i + i;
        for(LL j = begin+i; j <= b; j += i) unite(begin-a, j-a);
    }
    set<int> s;
    REP(i, b-a+1) s.insert(find(i));
    gout << SZ(s) << endl;
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
