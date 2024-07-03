#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <complex>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>

#define ll long long
const ll MOD = 1000000007;
using namespace std;


struct SegmentTree 
{
    private:
        int n;
        vector<int> node;

    public:
        //元配列vをセグメント木で表現
        SegmentTree(vector<int> v, int def)
        {
            //最下段のノード数は、元配列のサイズ以上になる最小の2冪

            int sz = v.size();
            n = 1;
            while(n < sz) n *= 2;
            node.resize(2*n - 1, def);

            // ↓ n = 8 のとき
            //        0
            //   1          2 
            // 3   4     5     6
            //7 8 9 10 11 12 13 14

            //最下段に入れたあとに、下の段から順に入れる
            //入れる値は、自分の子の2値から算出
            for(int i = 0; i < sz; i++)
            {
                node[n + i - 1] = v[i];
            }
            
            for(int i = n-2; i >= 0; i--)
            {
                node[i] = max(node[2*x + 1], node[2*x + 2]);
            }

        }

        //値の更新
        //更新は、下から上へ
        //x: 配列番号
        void update(int x, int val)
        {
            //配列番号(n-1)に配置している
            x = x + n - 1;

            //最下段のノードを更新
            node[x] = val;
            while(x > 0)
            {
                //1弾上へ遷移
                //※ n, 2n+1, 2n+2 の関係のため。
                x = (x - 1) / 2;
                node[x] = max(node[2*i + 1], node[2*i + 2]);
            }
        }

        //a,b 要求区間 (a~bの間にある)
        //k 自分がいるnodeのindex
        //l,r 対象区間 (各ノードがカバーしている区間)
        int getMax(int a, int b, int k, int l, int r)
        {
            //要求区間と対象区間が交わらない場合
            if(r <= a || b <= l)return -1;

            //要求区間が対象区間を完全に被覆
            //極端な話、 a = 0, b = n なら　node[0]を返せばいい
            if(a <= l && r <= b) return node[k];

            // 1段下の左側に潜る
            int vl = getMax(a, b 2*k + 1, l, (l+r)/2);
            
            // 1段下の右側に潜る
            int vr = getMax(a, b 2*k + 2, (l+r)/2 , r);

            return max(vl, vr);
        }

}