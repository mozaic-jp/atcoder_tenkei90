/*
https://atcoder.jp/contests/typical90/tasks/typical90_o
015 - Don't be too close（★6）
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <complex>
#include <queue>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

//べき乗
ll modpow(ll a, ll b, ll m)
{
    //a^b mod m
    ll p = 1;
    ll q = a;

    for(int i = 0; i < 30; i++)
    {
        if((b & (1LL << i)) != 0)
        {
            p *= q;
            p %= m;
        }
        // 階乗を1 ,2 , 4, 8とやっていく
        q *= q;
        q %= m;
    }
    return p;
}


ll Div(ll a, ll b, ll m)
{
    // a/b の逆元を求める
    return (a * modpow(b, m-2, m)) % m;
}

// 変数
ll mod = 1000000007;
ll N;
ll fact[200009];    //i! 階乗
ll factinv[200009]; //fact[i]の逆元

void init() {
	fact[0] = 1;
	for (int i = 1; i <= 200000; i++) fact[i] = (1LL * i * fact[i - 1]) % mod;
	for (int i = 0; i <= 200000; i++) factinv[i] = Div(1, fact[i], mod);
}

ll ncr(int n, int r)
{
    if(n < r || r < 0)return 0;
    return (fact[n] * factinv[r] % mod) * factinv[n-r] % mod;
}

ll query(int K)
{
    ll ret = 0;
    //N個中何個選ぶかを全探索
    //そもそもKが大きいと1個か2個しか選べないのでそこに注目する。
    for(int a = 1; a <= N / K + 1; a++)
    {
        //N-(k-1)(a-1)Ca 通りとなる
        int s1 = N - (K-1)*(a-1);
        int s2 = a;
        ret += ncr(s1,s2);
        ret %= mod;
    }

    return ret;
}


int main()
{
    cin >> N;

    //幅 k　のものを並べる問題に置き換えればよい

    //k = 1 {1},{2},{3} , {1,2,3}, {1,2,3,4,n} = 2^N - 1
    //k = 2 {1}.... , {1,3},{1,5}..., {2,4} 

    //dp[k][i] += dp[k][i-k];
    //dp[k][i] += dp[k][i-k];
    
    // k = Nから始めればいける?

    //2個しかおけないとき    
    //k = N N
    //k = N-1  N + 1
    //k = N-2  N + 3(2+1)
    //k = N-3  N + 6(3+2+1)
    //k = N-4  N + 10(4+3+2+1)

    // 3個おけるパターン
    //　隙間なくおける 1
    //  

    // a個置くとすると、
    //N-(k-1)(a-1)Ca 通りとなる
    //pを選んだらp+k-1までは選べない
    //そんな(k-1)が全部で(a-1)個ある

    init();

    // Step #3. 出力
	for (int k = 1; k <= N; k++) {
		ll res = query(k);
		cout << res << endl;
	}
	return 0;
}