
/*
https://atcoder.jp/contests/typical90/tasks/typical90_s
019 - Pick Two（★6）
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

    vector <int> a(N * 2);
    for(int i = 0; i < N * 2; i++)cin >> a[i];


    //同時に消せるのは隣合うものだけ

    // Nが200なので、なんとかなる?
    
    // 0ならば、いつとってもよいか
    // 5 6 8 7 6 5 5 10

    //新しいやつを作る時間あるのか???

    ll res = 0;
    int min_dif = MOD;
    bool isdelete = false;

    while(a.size() > 0)
    {
        if(isdelete)
        {
            min_dif = MOD;
            isdelete = false;
        }

        for(int j = 0; j < a.size() - 1; j++)
        {
            int sa = abs(a[j] - a[j+1]);
            if(sa == 0 || sa == min_dif)
            {
                res += sa;

                cout << "delete:" << a[j] << "," <<  a[j+1] << endl; 

                a.erase(a.begin() + j , a.begin() + j + 2);
                isdelete = true;
                break;
            }

            min_dif = min(min_dif, sa);
        }
    }

    cout << res << endl;



    return 0;
}