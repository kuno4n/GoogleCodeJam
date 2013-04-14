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


const int MAX_N = 110;
LL nCr[MAX_N+1][MAX_N+1];

void makepas(){
	for(int i=1; i<=MAX_N; i++){
		nCr[i][0] = 1;
		nCr[i][i] = 1;
		for(int j=1; j<i; j++){
			nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
		}
	}
}

LL retnCr(int n, int r){
	if(n <= 0 || n < r) return 0;
	else return nCr[n][r];
}

string spow(string s){ // "1001" -> "1002001"
	string res(SZ(s)*2-1, ' ');
	REP(i, SZ(s)*2-1) res[i] = '0';
	REP(i, SZ(s)){
		REP(j, SZ(s)){
			int ii = s[i] - '0';
			int jj = s[j] - '0';
			res[i+j] += ii*jj;
		}
	}
	return res;
}

string a, b;
LL cnt1[60], cnt2[120];

void init() {
	makepas();

	REP(i, 60) cnt1[i] = 0;
	REP(i, 120) cnt2[i] = 0;
	cnt1[1] = 3;
	cnt2[1] = 3;
	for(int i = 2; i <= 55; i++){
		cnt1[i] += 2; // 20002, 10001
		int canuse = (i-2)/2; // ex. 100001 -> 2  100010001 -> 3 100000001 -> 3
		for(int j = 1; j <= 3; j++) cnt1[i] += retnCr(canuse, j); // ex. 100110011001 (5C2)
		if(i&1){
			cnt1[i] += 3; // 2001002, 1002001, 1001001
			for(int j = 1; j <= 3; j++) cnt1[i] += retnCr(canuse, j);  // ex. 1001101011001 (5C2)
			for(int j = 1; j <= 1; j++) cnt1[i] += retnCr(canuse, j);  // ex. 1001002001001 (5C1)
		}
	}
	for(int i = 1; i <= 55; i++){
		cnt2[i*2-1] = cnt1[i];
	}
}

LL over(string a){ // ’·‚³SZ(a)‚Ì”’l‚Ì’†‚Åa‚ð’´‚·‚à‚Ì
	LL res = 0;
	int len = SZ(a);
	if(!(len&1)) return 0;

	if(len == 1){
		if(a[0] - '0' < 1) return 3;
		else if(a[0] - '0' < 4) return 2;
		else if(a[0] - '0' < 9) return 1;
	}

	int len2 = len/2 + 1;

	string tmp1(len2, '0'); tmp1[0] = '1'; tmp1[len2-1] = '1';
	string tmp2(len2, '0'); tmp2[0] = '2'; tmp2[len2-1] = '2';

	if(spow(tmp1) > a) res++; //1000000001
	if(spow(tmp2) > a) res++; //2000000002

	int canuse = (len2-2)/2;
	for(int i = 1; i <= canuse; i++){
		string tmpi = tmp1;
		tmpi[i] = '1'; tmpi[len2-1-i] = '1';
		if(spow(tmpi) > a) res++; // 1010000101
		for(int j = i+1; j <= canuse; j++){
			string tmpj = tmpi;
			tmpj[j] = '1'; tmpj[len2-1-j] = '1';
			if(spow(tmpj) > a) res++; // 1011001101
			for(int k = j+1; k <= canuse; k++){
				string tmpk = tmpj;
				tmpk[k] = '1'; tmpk[len2-1-k] = '1';
				if(spow(tmpk) > a) res++; // 1011111101
			}
		}
	}

	if(!(len2&1)) return res;

	string tmp11 = tmp1; tmp11[len2/2] = '1';
	if(spow(tmp11) > a) res++; //10000100001
	string tmp12 = tmp1; tmp12[len2/2] = '2';
	if(spow(tmp12) > a) res++; //10000200001
	string tmp21 = tmp2; tmp21[len2/2] = '1';
	if(spow(tmp21) > a) res++; //20000100002
	
	for(int i = 1; i <= canuse; i++){
		string tmpi = tmp11;
		tmpi[i] = '1'; tmpi[len2-1-i] = '1';
		if(spow(tmpi) > a) res++; // 10100100101
		for(int j = i+1; j <= canuse; j++){
			string tmpj = tmpi;
			tmpj[j] = '1'; tmpj[len2-1-j] = '1';
			if(spow(tmpj) > a) res++; // 10110101101
			for(int k = j+1; k <= canuse; k++){
				string tmpk = tmpj;
				tmpk[k] = '1'; tmpk[len2-1-k] = '1';
				if(spow(tmpk) > a) res++; // 10111111101
			}
		}
	}
	
	for(int i = 1; i <= canuse; i++){
		string tmpi = tmp12;
		tmpi[i] = '1'; tmpi[len2-1-i] = '1';
		if(spow(tmpi) > a) res++; // 10100200101
	}

	return res;

}



LL under(string a){ // ’·‚³SZ(a)‚Ì”’l‚Ì’†‚Åa–¢–ž‚Ì‚à‚Ì
	LL res = 0;
	int len = SZ(a);
	if(!(len&1)) return 0;

	if(len == 1){
		if(a[0] - '0' > 4) return 2;
		else if(a[0] - '0' > 1) return 1;
		return 0;
	}

	int len2 = len/2 + 1;

	string tmp1(len2, '0'); tmp1[0] = '1'; tmp1[len2-1] = '1';
	string tmp2(len2, '0'); tmp2[0] = '2'; tmp2[len2-1] = '2';

	if(spow(tmp1) < a) res++; //1000000001
	if(spow(tmp2) < a) res++; //2000000002

	int canuse = (len2-2)/2;
	for(int i = 1; i <= canuse; i++){
		string tmpi = tmp1;
		tmpi[i] = '1'; tmpi[len2-1-i] = '1';
		if(spow(tmpi) < a) res++; // 1010000101
		for(int j = i+1; j <= canuse; j++){
			string tmpj = tmpi;
			tmpj[j] = '1'; tmpj[len2-1-j] = '1';
			if(spow(tmpj) < a) res++; // 1011001101
			for(int k = j+1; k <= canuse; k++){
				string tmpk = tmpj;
				tmpk[k] = '1'; tmpk[len2-1-k] = '1';
				if(spow(tmpk) < a) res++; // 1011111101
			}
		}
	}

	if(!(len2&1)) return res;

	string tmp11 = tmp1; tmp11[len2/2] = '1';
	if(spow(tmp11) < a) res++; //10000100001
	string tmp12 = tmp1; tmp12[len2/2] = '2';
	if(spow(tmp12) < a) res++; //10000200001
	string tmp21 = tmp2; tmp21[len2/2] = '1';
	if(spow(tmp21) < a) res++; //20000100002
	
	for(int i = 1; i <= canuse; i++){
		string tmpi = tmp11;
		tmpi[i] = '1'; tmpi[len2-1-i] = '1';
		if(spow(tmpi) < a) res++; // 10100100101
		for(int j = i+1; j <= canuse; j++){
			string tmpj = tmpi;
			tmpj[j] = '1'; tmpj[len2-1-j] = '1';
			if(spow(tmpj) < a) res++; // 10110101101
			for(int k = j+1; k <= canuse; k++){
				string tmpk = tmpj;
				tmpk[k] = '1'; tmpk[len2-1-k] = '1';
				if(spow(tmpk) < a) res++; // 10111111101
			}
		}
	}
	
	for(int i = 1; i <= canuse; i++){
		string tmpi = tmp12;
		tmpi[i] = '1'; tmpi[len2-1-i] = '1';
		if(spow(tmpi) < a) res++; // 10100200101
	}

	return res;

}


void input() {
	cin >> a >> b;
}

void solve() {
	LL res = 0;
	for(int i = SZ(a); i <= SZ(b); i++) res += cnt2[i];
	res -= under(a);
	res -= over(b);

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
