
/*
https://atcoder.jp/contests/typical90/tasks/typical90_l
012 - Red Painting（★4）
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

//上下左右
int mov_x[] = {0,  0, -1, 1};
int mov_y[] = {1, -1,  0, 0};
int mov_size = 4;

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

// その他の変数
UnionFind UF;
bool used[2009][2009];

int main()
{
    //t1で赤で塗る
    //t2でマスからマスに赤だけを通ってたどり着けるかチェック

    int H, W, Q;
    cin >> H >> W >> Q;
    // Step #2. Union Find の初期化
	UF.init(H * W);


    vector<vector<int>> m(H, vector<int>(W, 0));

    for(int i = 0; i < Q; ++i)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            //赤で塗りつぶす
            int x,y;
            cin >> y >> x;
            for(int j = 0; j < mov_size; ++j)
            {
                int dest_y,dest_x;
                dest_y = y + mov_y[j];
                dest_x = x + mov_x[j];
                if(dest_y < 1 || H < dest_y || dest_x < 1 || W < dest_x)continue;
                if (used[dest_y][dest_x] == false) continue;
                //HとWの桁が被らないように
                int hash1 = (y - 1) * W + (x - 1);
		        int hash2 = (dest_y - 1) * W + (dest_x - 1);
                UF.unite(hash1, hash2);
            }

            used[y][x] = true;

        }
        else
        {

            string res = "No";
            //マスからマスに赤だけを通ってたどり着けるかチェック
            int x1,y1,x2,y2;
            cin >> y1 >> x1 >> y2 >> x2;

            if(used[y1][x1] == true && used[y2][x2] == true)
            {
                int hash1 = (y1 - 1) * W + (x1 - 1);
		        int hash2 = (y2 - 1) * W + (x2 - 1);
                if (UF.same(hash1, hash2) == true) res = "Yes";
            }

            cout << res << endl;
        }
    }

    return 0;
}
