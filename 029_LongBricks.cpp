
/*
https://atcoder.jp/contests/typical90/tasks/typical90_ac
029 - Long Bricks（★5）
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
#include <string>

#define ll long long
const ll MOD = 1000000007;
using namespace std;


//これも累積和っぽい

//W個のタイルが横にならんでいる
//N個のレンガを上にのっける
//レンガは、L[i] ~ R[i]のタイル上またはレンガ上に置かれる(レンガに重さはない)
//置いたレンガの高さを求める

//1~Wの高さを常に取得出来たらうれしいけど、速度的に間に合わなそう
//2 <= W <= 5*10^5
//1 <= N <= 2.5*10^5


//満点解法 セグメントツリー
struct SegmentTree 
{
    private:
        int n;
        vector<int> node;

    public:
        //元配列vをセグメント木で表現
        SegmentTree(vector<int> v)
        {
            //最下段のノード数は、元配列のサイズ以上になる最小の2冪
            int def = 0;
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
                node[i] = max(node[2*i + 1], node[2*i + 2]);
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
                node[x] = max(node[2*x + 1], node[2*x + 2]);
            }
        }

        //a,b 要求区間 (a~bの間にある)
        //k 自分がいるnodeのindex
        //l,r 対象区間 (各ノードがカバーしている区間)
        int getMax(int a, int b, int k = 0, int l = 0, int r=-1)
        {
            //最初に呼び出されたときの対象区間は [0, n)
            if(r < 0) r = n;
            
            //要求区間と対象区間が交わらない場合
            if(r <= a || b <= l)return -1;

            //要求区間が対象区間を完全に被覆
            //極端な話、 a = 0, b = n なら　node[0]を返せばいい
            if(a <= l && r <= b) return node[k];

            // 1段下の左側に潜る
            int vl = getMax(a, b, 2*k + 1, l, (l+r)/2);
            
            // 1段下の右側に潜る
            int vr = getMax(a, b, 2*k + 2, (l+r)/2 + 1, r);

            return max(vl, vr);
        }

};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int W, N;
	cin >> W >> N;
    
    vector <int> v(W,0);

    //セグ木の初期化
	SegmentTree seg(v);

    //
	for (int i = 0; i < N; ++i) {
		int L, R;
		cin >> L >> R;

        //高さ= L~R の最大 + 1 
		int height = seg.getMax(L - 1, R) + 1;
		//更新
        seg.update(L - 1, R, height);
		
        cout << height << endl;
	}
	return 0;
}


//2点の解法　座標圧縮する 
/*
int main()
{

    int W, N;
    cin >> W >> N;


    vector <int> lower(N, 0);
    vector <int> upper(N, 0);

    vector <int> copyArray(N * 2, 0);


    for(int i = 0; i < N; i++)
    {
        int l,r;
        cin >> l >> r;
        
        lower[i] = l;
        upper[i] = r;

        copyArray[i * 2] = l;
        copyArray[i * 2 + 1] = r;
    }

    sort(copyArray.begin(), copyArray.end());

    copyArray.erase(unique(copyArray.begin(), copyArray.end()), copyArray.end());

    vector <int> newL(N);
    vector <int> newR(N);

    for(int i = 0; i < N; i++)
    {
        newL[i] = lower_bound(copyArray.begin(), copyArray.end(), lower[i]) - copyArray.begin();
        //cout << "before:" << lower[i] << "  ,after:" << newL[i] << endl;

        newR[i] = lower_bound(copyArray.begin(), copyArray.end(), upper[i]) - copyArray.begin();
        //cout << "before:" << upper[i] << "  ,after:" << newR[i] << endl;
    }


    vector <int> high(W + 2, 0);
    for(int i = 0; i < N; i++)
    {
        int l,r;
        l = newL[i];
        r = newR[i];

        int hMax = 0;
        //max探し
        for(int x = l; x <= r; x++)
        {
            hMax = max(hMax, high[x]);
        }
        
        for(int x = l; x <= r; x++)
        {
            high[x] = hMax + 1;
        }

        cout << high[l] << endl;
    }

    return 0;
}
*/


//1点とる方法
/*
int main()
{

    int W, N;
    cin >> W >> N;

    vector <int> high(W + 2, 0);

    for(int i = 0; i < N; i++)
    {
        int l,r;
        cin >> l >> r;

        int hMax = 0;
        //max探し
        for(int x = l; x <= r; x++)
        {
            hMax = max(hMax, high[x]);
        }
        
        for(int x = l; x <= r; x++)
        {
            high[x] = hMax + 1;
        }

        cout << high[l] << endl;
    }
    return 0;
}
*/

