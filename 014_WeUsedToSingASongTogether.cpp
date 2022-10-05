
/*
https://atcoder.jp/contests/typical90/tasks/typical90_n
014 - We Used to Sing a Song Together（★3）
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

int main()
{
    int N;
    cin >> N;
    vector <int> a(N);
    vector <int> b(N);

    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < N; i++)
    {
        cin >> b[i];
    }

    //どっちもソートするしかないと思う
    // 3 4
    // 4 6
    // 3-6 4-4をペアにすると 3
    // 3-4 4-6をペアにすると 3

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll res = 0;
    for(int i = 0; i < N; i++)
    {
        res += abs(a[i] - b[i]);
    }
    cout << res << endl;

    return 0;
}