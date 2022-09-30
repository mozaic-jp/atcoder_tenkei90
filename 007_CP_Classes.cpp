/*
https://atcoder.jp/contests/typical90/tasks/typical90_g
007 - CP Classes（★3）（★5）

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
    int N;
    cin >> N;
    vector <int> a(N);
    for(int i = 0; i < N; i++)cin >> a[i];

    int Q;
    cin >> Q;
    vector <int> b(Q);
    for(int i = 0; i < Q; i++)cin >> b[i];


    //a[N]をソート
    //a[N]を二分探索
    //どちらか近い方にする

    sort(a.begin(),a.end());



    for(int i = 0; i < Q; i++)
    {
        //a[N]を二分探索
        int l,r;
        l = 0; r = N;

        while(l + 1 < r)
        {
            int m = (l + r)/2;
            //b[i]のほうが小さいなら
            if(b[i] < a[m])
            {
                r = m;
            }
            else 
            {
                l = m;
            }
        }


        int res;
        res = min(abs(b[i] - a[l]), abs(b[i] - a[r]));
        cout << res << endl;
    }


    return 0;
}
