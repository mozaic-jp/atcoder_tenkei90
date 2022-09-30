
/*
https://atcoder.jp/contests/typical90/tasks/typical90_h
008 - AtCounter（★4）

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <complex>
#include <algorithm>
#define ll long long
const ll MOD = 1000000007;
using namespace std;



const string T = "atcoder";
int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    //atcoderとなる組み合わせ
    
    //nexでできる?

    //dp[i][j]:文字列 S の最初の i 文字から何文字か抜き出してつなげる方法のうち、それが "atcoder" の最初の j 文字まで一致するような方法の個数

    vector<vector<int>> dp(N+1, vector<int>(T.size()+1, 0));

    // 初期条件
    dp[0][0] = 1;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j <= T.size(); ++j)
        {
            //S[i]を選ばない場合
            dp[i+1][j] += dp[i][j];
            dp[i+1][j] %= MOD; 

            //S[i]を選ぶ場合
            if(j < T.size() && S[i] == T[j])
            {
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
        }
    }

    cout << dp[N][T.size()] << endl;
    return 0;
}