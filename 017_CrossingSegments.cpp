
/*
https://atcoder.jp/contests/typical90/tasks/typical90_q
017 - Crossing Segments（★7）
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
const ll MOD = 1000000007;
using namespace std;

/// @brief 小課題3で使用
class BIT {
    
public:
    int size_ = 1;
    vector <ll> bit;

    void init(int sz)
    {
        size_ = sz + 2;
        bit.resize(size_ + 2, 0);
    }
    void add(int pos,  ll x)
    {
        //0だと困るので、1-indexedに変えておく
        pos++;
        while(pos <= size_)
        {
            bit[pos] += x;
            //i の最後に立っている1のビット = i & -i
            //負の数は「ビット反転+1」で表現される
            // -6 は、 6が00...0110 なので、 11...1001 + 1 の 11...1010 となる
            //6 & -6 = (00...0110) & (11...1010) = 00…0010
            //add は、最後に立っている1のbitを足して、次の追加場所を求める

            pos += (pos & -pos);
        }
    }
    
    ll sum(int pos)
    {
        ll s = 0;
        //0だと困るので、1-indexedに変えておく
        pos++;
        while(pos >= 1)
        {
            s += bit[pos];
            pos -= (pos & -pos);
        }
        return s;
    }
};



ll shokadai1(vector <pair <int,int> > lr)
{
    //全探索でやってみる

    //下記の2パターンならよい
    //例(1,4)と(2,5)など
    //l[i] < l[j] < r[i] < r[j]
    //l[j] < l[i] < r[j] < r[i]

    int res = 0;
    //l[i]でソートして考える
    sort(lr.begin(),lr.end());
    for(int i = 0; i < lr.size(); i++)
    {
        for(int j = i+1; j < lr.size();j++)
        {
            if(lr[i].first < lr[j].first && lr[j].first < lr[i].second && lr[i].second < lr[j].second)
            {
                res++;
            }
        }
    }

    return res;
}

ll shokadai2(int N, vector <pair <int,int> > lr)
{
    // shokadai1だと M = 100000のときにTLEになるので他の方法を考える
    // 条件の余事象
    //1. 端点で交わる           ※ l[i],l[j],r[i],r[j] のいずれかが一致　
    //2. 完全に交わらない       ※ l[i] < r[i] < l[j] < r[j]
    //3. どちらかが覆っている   ※ l[i] < l[j] < r[j] < r[i]   

    ll M = lr.size();

    // 端点で交わるものの通り数

    // 点i にある線分の個数をcnt[i]とするときの通り数
    // Σ　i(i-1)/2
    //ソートした
    vector <ll> v3(N+1);
    ll res1 = 0;
    for(int i = 0; i < M; i++)
    {
        v3[lr[i].first] += 1;
        v3[lr[i].second] += 1;
    }
    for(int i = 1; i <= N; i++)
    {
        res1 += v3[i] * (v3[i] -1LL)/2LL;
        //N(N-1)/2
    }

    // r[i] <= l[j]; 
    //2. 完全に交わらない       ※ l[i] < r[i] < l[j] < r[j]
    ll res2 = 0;
    vector <ll> v1(N+1);
    vector <ll> v2(N+1);
    for(int i = 0; i < M; i++)
    {
        v1[lr[i].second] += 1;
        // l - 1 の数を集める 
        v2[lr[i].first-1] += 1;
    }

    //累積和  i以下のモノの和を足す
    for(int i = 1; i <= N; i++)
    {
        v1[i] += v1[i-1];
    }

    // 完全に交わらないものの数
    for(int i = 1; i <= N; i++)
    {
        res2 += v1[i] * v2[i];
    }

    //3. どちらかが覆っている   ※ l[j] < l[i] < r[i] < r[j]   
    //Rの小さい順にソートして、
    // L[j] < L[i]となっているもの ※Rでソートしているため、r[i] < r[j]はわかっている
    //
    vector <pair <int,int> > rl(M);
    for(int i = 0; i < M; i++)
    {
        rl[i].first = lr[i].second;
        rl[i].second = lr[i].first;
    }

    sort(rl.begin(), rl.end());
    
    // L[i]の個数
    vector <ll> cnt(N + 1, 0);

    ll res3 = 0;
    for(int i = 0; i < M; i++)
    {
        ll cl = rl[i].second;
        ll cr = rl[i].first;
        ll ret = 0;
        for(int j = cl + 1; j <= cr; j++)
        {
            ret += cnt[j];
        }
        res3 += ret;
        cnt[cl] += 1;
    }

    ll total = M * (M - 1) / 2LL;
    ll res = total - res1 - res2 - res3;


    //cout << "total:" << total << endl;
    //cout << "res1:" << res1 << endl;
    //cout << "res2:" << res2 << endl;
    //cout << "res3:" << res3 << endl;
    
    return res;
}


ll shokadai3(int N, vector <pair <int,int> > lr)
{
    // shokadai1だと M = 100000のときにTLEになるので他の方法を考える
    // 条件の余事象
    //1. 端点で交わる           ※ l[i],l[j],r[i],r[j] のいずれかが一致　
    //2. 完全に交わらない       ※ l[i] < r[i] < l[j] < r[j]
    //3. どちらかが覆っている   ※ l[i] < l[j] < r[j] < r[i]   
    //小課題2 では、 3の計算量がN * Mとなっていたため、TLEとなってしまった。
    // 3の他の方法を考える

    ll M = lr.size();

    // 端点で交わるものの通り数

    // 点i にある線分の個数をcnt[i]とするときの通り数
    // Σ　i(i-1)/2
    //ソートした
    vector <ll> v3(N+1);
    ll res1 = 0;
    for(int i = 0; i < M; i++)
    {
        v3[lr[i].first] += 1;
        v3[lr[i].second] += 1;
    }
    for(int i = 1; i <= N; i++)
    {
        res1 += v3[i] * (v3[i] -1LL)/2LL;
        //N(N-1)/2
    }

    // r[i] <= l[j]; 
    //2. 完全に交わらない       ※ l[i] < r[i] < l[j] < r[j]

    ll res2 = 0;
    vector <ll> v1(N+1);
    vector <ll> v2(N+1);
    for(int i = 0; i < M; i++)
    {
        v1[lr[i].second] += 1;
        // l - 1 の数を集める 
        v2[lr[i].first-1] += 1;
    }

    //累積和  i以下のモノの和を足す
    for(int i = 1; i <= N; i++)
    {
        v1[i] += v1[i-1];
    }

    // 完全に交わらないものの数
    for(int i = 1; i <= N; i++)
    {
        res2 += v1[i] * v2[i];
    }

    //3. どちらかが覆っている   ※ l[j] < l[i] < r[i] < r[j]   
    //BITで求める
    // セグ木の　1~だけを求められる軽い版
    BIT Z; 
    Z.init(N + 2);

    vector <pair <int, int> > rl(M);
    for(int i = 0; i < M; i++)
    {
        rl[i].first = lr[i].second;
        rl[i].second = lr[i].first;
    }
    sort(rl.begin(), rl.end());

    ll res3 = 0;
    for(int i = 0; i < M; i++)
    {
        ll cl = rl[i].second;
        ll cr = rl[i].first;

        ll ret = Z.sum(cr) - Z.sum(cl);
        res3 += ret;

        //足す
        Z.add(cl, 1);
    }


    ll total = M * (M - 1) / 2LL;
    ll res = total - res1 - res2 - res3;
    /*
    cout << "total:" << total << endl;
    cout << "res1:" << res1 << endl;
    cout << "res2:" << res2 << endl;
    cout << "res3:" << res3 << endl;
    */
    
    return res;
}

//
int main()
{
    int N, M;

    //const char *fileName = "./subtask3_handmade.txt";

    //std::ifstream ifs(fileName);

    cin >> N >> M;
    //ifs >> N >> M;
    vector <pair <int,int> > lr(M);
    for(int i = 0; i < M; i++)
    {
        cin >> lr[i].first >> lr[i].second;
    }

    ll res;

    //res = shokadai1(lr);

    //res = shokadai2(N, lr);
    res = shokadai3(N, lr);

    cout << res << endl;

    return 0;
}