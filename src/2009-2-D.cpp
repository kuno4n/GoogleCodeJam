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

int n, x[40], y[40], r[40];

void init() {
}

void input() {
    cin >> n;
    REP(i, n) cin >> x[i] >> y[i] >> r[i];
}

LL makecand(double X, double Y, double R){
    LL S = 0LL;
    REP(i, n){
        if(R < r[i]) continue;
        double dx = X - x[i];
        double dy = Y - y[i];
        if((R-r[i])*(R-r[i]) >= dx*dx + dy*dy) S |= (1LL << i);
    }
    return S;
}

bool C(double R){
    vector <LL> cand;
    
    REP(i, n){
        REP(j, n){
            if(R < r[i] || R < r[j]) continue;
            double r1 = R - r[i];
            double r2 = R - r[j];
            double x1 = x[j] - x[i];
            double y1 = y[j] - y[i];
            double d = x1*x1 + y1*y1;
            double a = (d + r1*r1 - r2*r2) / 2;
            double b = d * r1 * r1 - a * a;
            if(b > 0) {
                b = sqrt(b);
                double xx1 = (a*x1 + y1*b) / d;
                double yy1 = (a*y1 - x1*b) / d;
                double xx2 = (a*x1 - y1*b) / d;
                double yy2 = (a*y1 + x1*b) / d;
                LL ij = (1LL << i) | (1LL << j);
                cand.push_back(makecand(xx1 + x[i], yy1 + y[i], R) | ij);
                cand.push_back(makecand(xx2 + x[i], yy2 + y[i], R) | ij);
            }
            
        }
    }
    
    REP(i, n){
        if(R < r[i]) continue;
        cand.push_back(makecand(x[i], y[i], R));
    }
    
    REP(i, SZ(cand)) REP(j, SZ(cand)) if((cand[i] | cand[j]) == (1LL << n) - 1) return true;
    return false;
}

void solve() {
    double lb = 0.0, ub = 2000.0;
    REP(i, 100){
        double md = (lb + ub) / 2;
        if(C(md)) ub = md;
        else lb = md;
    }
    printg("%.6f\n", ub);
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
