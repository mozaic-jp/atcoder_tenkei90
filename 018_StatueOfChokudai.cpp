
/*
https://atcoder.jp/contests/typical90/tasks/typical90_r
018 - Statue of Chokudai（★3）
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

long double T,L,X,Y;
long double PI = 3.14159265358979;


long double query(long double I)
{
    long double cx = 0;
    long double cy = - (L/ 2.0) * sin(I / T * 2.0 *PI);
    long double cz = (L/2.0) - (L/ 2.0) * cos(I / T * 2.0 *PI);
    
    // 距離を求める 
    long double dx = sqrt((cx - X) * (cx - X) + (cy - Y) * (cy - Y));

    long double dy = cz;
    long double kaku = atan2(dy, dx);


    //360度換算に変換 (ラジアンΠ = 180°)
    return kaku * 180.0L / PI;

}

int main()
{

    cin >> T >> L >> X >> Y;
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        long double e;
        cin >> e;

        //俯角を求める

        //E8のいる位置を
        // (ex,ey,ez)とすると、
        // (X,Y,0)を原点とした
        // (ex,ey,ez) と(ex,ey,0) の角度を求めればよさそう
        
        //いる位置に求め方
        //rcosθ, rsinθ)
        // θと rcosθ, rsinθの関係性は
        //
       printf("%.12Lf\n", query(e));

    }


    return 0;
}