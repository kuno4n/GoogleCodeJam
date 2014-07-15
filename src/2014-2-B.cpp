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




LL a[1010];

int n;

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

void init() {
}

void input() {
    cin >> n;
    REP(i, n){
        cin >> a[i];
    }
}

void solve() {
    int ptr1 = 0;
    int ptr2 = n-1;
    int res = 0;
    while(ptr1 < ptr2){
        int mn = 1000000001;
        int ptr;
        for(int i = ptr1; i <= ptr2; i++) if(a[i] < mn) mn = a[i], ptr = i;
        if(ptr - ptr1 < ptr2 - ptr){
            for(int i = ptr; i > ptr1; i--){
                res++;
                swap(a[i], a[i-1]);
            }
            ptr1++;
        }
        else{
            for(int i = ptr; i < ptr2; i++){
                res++;
                swap(a[i], a[i+1]);
            }
            ptr2--;
        }
    }
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


