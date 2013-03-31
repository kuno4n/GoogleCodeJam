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



string _int2str(int a, int len){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    while(SZ(res) < len) res = "0"+res;
    return res;
}

typedef vector < VI > mat;

mat mul(mat &A, mat &B){
    mat C(SZ(A), VI(SZ(B[0])));
    REP(i, SZ(A)){
        REP(k, SZ(B)){
            REP(j, SZ(B[0])){
                C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % 1000;
            }
        }
    }
    return C;
}

mat pow(mat A, LL n){
    mat B(SZ(A), VI(SZ(A)));
    REP(i, SZ(A)) B[i][i] = 1;
    while(n > 0){
        if(n&1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

LL n;
int a[40], b[40];



//void init(){}
//
//void input(){
//    cin >> n;
//}
//
//void solve(){
//    mat A(2, VI(2));
//    A[0][0] = 3; A[0][1] = 5;
//    A[1][0] = 1; A[1][1] = 3;
//    
//    mat B = pow(A, n);
//    int res = (B[0][0] *2 + 999) % 1000;
//    gout << _int2str(res, 3) << endl;
//}

void init() {
    a[0] = 3;
    b[0] = 1;
    for(int i = 1; i < 40; i++){
        a[i] = (a[i-1]*a[i-1] + 5*b[i-1]*b[i-1]) % 1000;
        b[i] = (2*a[i-1]*b[i-1]) % 1000;
    }
}

void input() {
    cin >> n;
}

void solve() {
    int tmpa = 1;
    int tmpb = 0;
    for(int i = 39; i >= 0; i--){
        if(n >= (1LL << i)){
            n -= (1LL << i);
            int _tmpa = tmpa;
            int _tmpb = tmpb;
            tmpa = (_tmpa*a[i] + 5*_tmpb*b[i]) % 1000;
            tmpb = (_tmpa*b[i] + _tmpb*a[i]) % 1000;
        }
    }
    int res = (tmpa * 2 + 999) % 1000;
    gout << _int2str(res, 3) << endl;
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
