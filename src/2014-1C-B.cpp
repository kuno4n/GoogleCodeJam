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


const int MAX_N = 1000;
int par[MAX_N];  //親
int _rank[MAX_N]; //木の深さ

// n要素で初期化
void init(int n){
    REP(i, n){
        par[i] = i;
        _rank[i] = 0;
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
    if(_rank[x] < _rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(_rank[x] == _rank[y]) _rank[x]++;
    }
}
//xとyが同じ集合に属するか
bool same(int x, int y){
    return find(x) == find(y);
}


const int MOD = 1000000007;
int n;
string ss[110];


long long modFact(int n){
    long long res = 1;
    while(n > 1){
        res = (res*n) % MOD;
        n--;
    }
    return res;
}

void init() {
}

void input() {
    cin >> n;
    REP(j, n){
        string s;
        cin >> s;
        string tmp = "";
        tmp += s[0];
        for(int i = 1; i < SZ(s); i++) if(s[i] != s[i-1]) tmp += s[i];
        ss[j] = tmp;
        
    }
}

void solve() {
    LL res = 1;
    
    vector <string> vs1;
    vector <string> vs2;
    
    REP(i, 26){
        char c = 'a' + i;
        int cnt = 0;
        string s = ""; s += c;
        REP(j, n) if(SZ(ss[j]) == 1 && ss[j] == s) cnt++;
        if(cnt){
            res = (res * modFact(cnt)) % MOD;
            vs1.push_back(s);
        }
    }
    REP(i, n) if(SZ(ss[i]) != 1) vs2.push_back(ss[i]);
    
    bool ng = false;
    int ct[26]; MSET(ct, 0);
    REP(i, SZ(vs2)){
        char c;
        int cnt;
        
        c = vs2[i][0];
        cnt = 0;
        REP(j, SZ(vs2)) REP(k, SZ(vs2[j])){
            char d = vs2[j][k];
            if(c == d){
                if(i!=j && k == SZ(vs2[j])-1) cnt++;
                else if(!(i==j && k == 0)) ng = true;
            }
            if(cnt > 1) ng = true;
        }
        
        c = vs2[i][SZ(vs2[i])-1];
        cnt = 0;
        REP(j, SZ(vs2)) REP(k, SZ(vs2[j])){
            char d = vs2[j][k];
            if(c == d){
                if(k == 0) cnt++;
                else if(!(i==j && k == SZ(vs2[i])-1)) ng = true;
            }
            if(cnt > 1) ng = true;
        }
        
        for(int j = 1; j < SZ(vs2[i])-1; j++) ct[vs2[i][j]-'a']++;
    }
    REP(i, 26) if(ct[i] > 1) ng = true;
    
    int next[n]; MSET(next, -1);
    REP(i, SZ(vs2)) REP(j, SZ(vs2)) if(i != j && vs2[i][SZ(vs2[i])-1] == vs2[j][0]) next[i] = j;
    REP(i, SZ(vs2)){
        int ptr = next[i];
        while(ptr != -1){
            ptr = next[ptr];
            if(ptr == i){
                ng = true;
                break;
            }
        }
    }
    
    REP(i, SZ(vs1)){
        char c = vs1[i][0];
        REP(j, SZ(vs2)) for(int k = 1; k < SZ(vs2[j])-1; k++) if(c == vs2[j][k]) ng = true;
    }
    
    if(ng){
        gout << 0 << endl;
        return;
    }
    
    REP(i, SZ(vs1)) vs2.push_back(vs1[i]);
    init(SZ(vs2));
    REP(i, SZ(vs2)){
        char c;
        c = vs2[i][0];
        REP(j, SZ(vs2)) if(c == vs2[j][SZ(vs2[j])-1]) unite(i, j);
        c = vs2[i][SZ(vs2[i])-1];
        REP(j, SZ(vs2)) if(c == vs2[j][0]) unite(i, j);
    }
    
    set<int> s;
    REP(i, SZ(vs2)) s.insert(find(i));
    res = (res * modFact(SZ(s))) % MOD;
    
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
