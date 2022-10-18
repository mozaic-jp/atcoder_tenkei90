
/*
https://atcoder.jp/contests/typical90/tasks/typical90_x
024 - Select +／- One（★2）
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <complex>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>

#define ll long long
const ll MOD = 1000000007;
using namespace std;

int main()
{

    int N,K;
    cin >> N >> K;

    vector <int> a(N);
    vector <int> b(N);
    for(int i = 0; i < N; i++)cin >> a[i];
    for(int i = 0; i < N; i++)cin >> b[i];

    //差が偶数でK以下なら大丈夫そう

    ll sa = 0;
    for(int i = 0; i < N; i++)
    {
        sa += abs(a[i] - b[i]);
    }

    string res;
    if(sa <= K && abs(K-sa) % 2 == 0)
    {
        res = "Yes";
    }
    else res = "No";

    cout << res << endl;



    return 0;
}