/*
https://atcoder.jp/contests/typical90/tasks/typical90_f
006 - Smallest Subsequence（★5）

【問題文】
英小文字のみからなる、長さ N の文字列 S が与えられます。
長さが K である S の部分列のうち、辞書順で最小であるものを出力してください。

【制約】
1≤K≤N≤100000
S は英小文字のみからなる長さ N の文字列
N,K は整数

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#define ll long long
const ll MOD = 1000000007;
using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";

//後ろから見て行って、
//先頭の文字を入れ替える必要があるか
//あるなら以降をシフトして入れ替える必要があるかをチェックするとよさそう
//サンプルなら
//7 3
//atcoder
//初期値
// der
// o → 無視
// cde
// t → 無視
// acd 
//計算量だけ不安

//nex の作成 ※nex[i][c]:文字列 S の i 文字目以降で、文字 c が出現する最小の添字 (存在しない場合は N)
vector<vector<int>> calc_next(const string &S)
{
    //文字列の長さ
    int N = S.size();

    //答え 初期値N
    vector<vector<int>> res (N+1, vector<int> (26, N));

    //後ろから見る
    for(int i = N - 1 ; i >= 0; --i)
    {
        //i+1文字目以降の結果をコピー
        res[i] = res[i + 1];
        //i文字目の情報を反映
        res[i][S[i] - 'a'] = i;
    }

    return res;
}





int main()
{
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;

    //nex の作成 ※nex[i][c]:文字列 S の i 文字目以降で、文字 c が出現する最小の添字 (存在しない場合は -1)
    auto nex = calc_next(S);

    string res = "";

    //貪欲法
    int j = -1;
    for(int i = 0; i < K; ++i)
    {
        for(char c = 'a'; c <= 'z'; ++c)
        {
            int k = nex[j+1][c-'a'];
            //K文字作れていればOK
            if(N - k >= K - i)
            {
                res += c;
                j = k;  //次の参照ポジション
                break;
            }
        }
    }


    cout << res << endl;
    return 0;
}


string solve1(int N, int K, string S)
{
    string res;

    res = S.substr(N - K, K);

    for(int i = N - K - 1; i >= 0; i--)
    {
        char tar = S[i];
        int cnt = 0;
        //tar のほうが辞書順で小さいなら
        while(tar <= res[cnt])
        {
            char tmp = res[cnt];
            res[cnt] = tar;
            tar = tmp;
            cnt++;
        }
    }

    return res;
}