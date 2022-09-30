/*
https://atcoder.jp/contests/typical90/tasks/typical90_e
005 - Restricted Digits（★7）

【問題文】
数字 c[1],c[2],…,c[K]のみを使うことで作れる N 桁の正の整数のうち 
B の倍数であるものは何個あるでしょうか。 
10^9 +7 で割った余りを求めてください。

【制約】
1≤K≤9
1≤c[1]<c[2]<⋯<c[K]≤9
1≤N≤10^18
2≤B≤1000
入力はすべて整数

【小課題】
1.(1 点)： N≤10000, B≤30
2.(3 点)： B≤30
3.(3 点)： 追加の制約はない。

【考察】
小課題1の制約なら、桁dpでできそう

小課題2,3は行列の圧縮が必要そう
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define ll long long
const ll MOD = 1000000007;
using namespace std;

//小課題1_解法
int shokadai1()
{
    ll N,b,K;
    cin >> N >> b >> K;
    vector <int> c(K);
    for(int i = 0; i < K; ++i)
    {
        cin >> c[i];
    }
    
    //dp[桁数][あまり]
    vector<vector<ll>> dp(N + 1, vector<ll>(b, 0));
    dp[0][0] = 1;

    for(ll i = 0; i < N; ++i)
    {
        for(ll j = 0; j < b; ++j)
        {
            for(ll k = 0; k < K; ++k)
            {
                // [i+1桁][あまりnj] に dp[i桁目][あまりj] を足す 
                // 1回目ならdp[1][c[i]]に1個あるよっていうのを示せる
                ll nj = (j * 10 + c[k]) % b;
                dp[i + 1][nj] += dp[i][j];      //dp[i][j]の渡し先を決定
                dp[i + 1][nj] %= MOD;
            }
        }
    }

    cout << dp[N][0] << endl;
    return 0;
}

int shokadai2()
{
    //小課題2の解法
    //圧縮の式を考える

    //dp[i + 1][nj] += dp[i][j];      //dp[i][j]の渡し先を決定
    //dp[i+2][mnj] = dp[i + 1][nj]  dp[i][j];      //dp[i][j]の渡し先を決定

    ll N,b,K;
    cin >> N >> b >> K;
    vector <int> c(K);
    for(int i = 0; i < K; ++i)
    {
        cin >> c[i];
    }

    //dp[桁数][あまり]
    vector<vector<ll>> dp(N + 1, vector<ll>(b, 0));

    // dp[i] と dp[j] を掛け合わせて dp[i+j] を得る処理
    // tj: 10^j を B で割ったあまり
    auto mul = [&](const vector<long long>& dpi,
                   const vector<long long>& dpj,
                   long long tj) -> vector<long long> {
        vector<long long> res(B, 0);
        for (long long p = 0; p < B; ++p) {
            for (long long q = 0; q < B; ++q) {
                res[(p * tj + q) % B] += dpi[p] * dpj[q];
                res[(p * tj + q) % B] %= MOD;
            }
        }
        return res;
    };


}


int main()
{
    //shokadai1();
    //飛ばす
    shokadai2();


}