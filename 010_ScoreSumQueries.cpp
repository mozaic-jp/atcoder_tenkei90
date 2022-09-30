
/*
https://atcoder.jp/contests/typical90/tasks/typical90_j
010 - Score Sum Queries（★2）
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

int main()
{
    //1組の
    //出席番号 1 ~ i番までの合計点数を持っておく(sum_c1)
    //sum_c1[r] - sum_c1[l-1]で一発で求められるようにする

    int N;
    cin >> N;
    vector <int> sum_c1(N+1, 0);
    vector <int> sum_c2(N+1, 0);

    //出席番号 1 ~ i番までの合計点数を持っておく(sum_c1)
    for(int i = 0; i < N; ++i)
    {
        sum_c1[i+1] = sum_c1[i];
        sum_c2[i+1] = sum_c2[i];

        int c,p;
        cin >> c >> p;
        if(c == 1)
        {
            sum_c1[i+1] += p;
        }
        else
        {
            sum_c2[i+1] += p;
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; ++i)
    {
        int l,r;
        cin >> l >> r;
        int res_c1, res_c2;
        //sum_c1[r] - sum_c1[l-1]で一発で求められるようにする
        res_c1 = sum_c1[r] - sum_c1[l-1];
        res_c2 = sum_c2[r] - sum_c2[l-1];

        cout << res_c1 << " " << res_c2 << endl;
    }

    return 0;
}
