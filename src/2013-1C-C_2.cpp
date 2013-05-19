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



struct D { LL min_value; bool delay; };
struct SegTree {
  static const int n = 1<<23;  // the number of leaves
  // static const int n = 1<<3;  // the number of leaves
  D v[2*n];
 
  void init(LL x) { REP(i, 2*n) v[i] = (D){x, false}; }
 
  void remove_delay(int node) {
    if (v[node].delay) {
      if (node < n) {
        if (v[node*2+0].min_value < v[node].min_value) v[node*2+0] = v[node];
        if (v[node*2+1].min_value < v[node].min_value) v[node*2+1] = v[node];
      }
      v[node].delay = false;
    }
  }
 
  LL join(int node) {
    LL vl = v[node*2+0].min_value;
    LL vr = v[node*2+1].min_value;
    return min(vl, vr);
  }
 
  void osub(int node, int lp, int rp, int fr, int to, LL value) {
    if (rp<=fr || to<=lp) return;
    if (fr<=lp && rp<=to) {
      if (v[node].min_value < value) v[node] = (D){value, true};
      return;
    }
    remove_delay(node);
    int mp = (lp+rp)/2;
    osub(node*2+0, lp, mp, fr, to, value);
    osub(node*2+1, mp, rp, fr, to, value);
 
    if (node < n) {
      v[node].min_value = join(node);
    }
  }
  void overwrite(int fr, int to, LL value) { osub(1, 0, n, fr, to, value); }
 
  LL msub(int node, int lp, int rp, int fr, int to) {
    if (rp<=fr || to<=lp) return 1LL<<60;
    if (fr<=lp && rp<=to) {
      return v[node].min_value;
    }
    remove_delay(node);
    int mp = (lp+rp)/2;
    LL vl = msub(node*2+0, lp, mp, fr, to);
    LL vr = msub(node*2+1, mp, rp, fr, to);
    return min(vl, vr);
  }
  LL get_min(int fr, int to) { return msub(1, 0, n, fr, to); }
 
  // DEBUG
  void outp(int node) {
    printf("(%lld %d) ", v[node].min_value, v[node].delay);
  }
  void outpu() {
    int u=2;
    FOR(i, 1, 2*n) {
      printf("%d:", i);
      outp(i);
      if (i==u-1) { puts(""); u*=2; }
    }
  }
};

struct Q {
  LL lo, hi, val;
  Q(LL lo, LL hi, LL val) : lo(lo), hi(hi), val(val){}
};
map<LL, vector<Q> > query;
SegTree seg;


void test() {
  seg.init(0LL);

  seg.overwrite(0, 1, 27);
  seg.overwrite(1, 2, 28);
  seg.overwrite(2, 3, 40);
  seg.overwrite(3, 4, 30);

  seg.outpu();
  seg.overwrite(0, 4, 25);
  seg.outpu();

  cout << seg.get_min(0, 4) << endl;
  seg.outpu();
}


int res, N;

void init() {
}

void input() {
	query.clear();
	
	cin >> N;
	REP(i, N){
		int d, nn, w, e, s, dd, dp, ds;
		cin >> d >> nn >> w >> e >> s >> dd >> dp >> ds;
//		query[d].push_back(Q(w, e, s));
		REP(i, nn){
			query[d].push_back(Q(w, e, s));
			d += dd;
			w += dp;
			e += dp;
			s += ds;
//			query[d].push_back(Q(w, e, s));
		}
	}
	
	map <LL, LL> comp;
	FIT(it, query){
		FIT(itt, it->second){
			comp[itt->lo] = -1;
			comp[itt->hi] = -1;
		}
	}
	int cnt = 0;
	FIT(it, comp) it->second = cnt++;
	FIT(it, query){
		FIT(itt, it->second){
			itt->lo = comp[itt->lo];
			itt->hi = comp[itt->hi];
		}
	}
	res = 0;
}

void solve() {
	seg.init(0LL);
	
	FIT(it, query){
		FIT(itt, it->second){
			if(itt->val > seg.get_min(itt->lo, itt->hi)) res++;
		}
		FIT(itt, it->second){
			seg.overwrite(itt->lo, itt->hi, itt->val);
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
//	test();
	return 0;
}
