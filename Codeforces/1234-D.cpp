//
///**Bismillahir Rahmanir Rahim.**/
//#include<bits/stdc++.h>
//#define ln '\n'
//#define pf printf
//#define sf scanf
//#define inp(x) scanf("%lld",&x)
//#define D(x) cout<< #x " = "<<x<<endl
//#define foreach(i,c) for(__typeof(c.begin())i=c.begin();i!=c.end();i++)
//
//#define f0(i,b) for(int i=0;i<(b);i++)
//#define f1(i,b) for(int i=1;i<=(b);i++)
//#define _case cout<<"Case "<<++cs<<": "
//
//#define MOD 1000000007
//#define countv(v,a) count(v.begin(),v.end(),a)
//#define grtsrt(v) sort(v.begin(),v.end(),greater<int>())
//#define mnv(v) *min_element(v.begin(),v.end())
//#define mxv(v) *max_element(v.begin(),v.end())
//#define uniq(v) v.resize( unique(all(v)) - v.begin())
//
//#define PI acos(-1)
//#define ll long long int
//#define ull unsigned long long
//
//#define vi vector <int>
//#define vll vector <ll>
//#define vs vector <string>
//#define pb push_back
//#define eb emplace_back
//#define mpii map <int,int>
//#define mpsi map <string,int>
//#define mpll map <long long,long long>
//#define MP make_pair
//#define F first
//#define S second
//
//#define GCD(a,b) __gcd(a,b)
//#define LCM(a,b) (a*(b/__gcd(a,b)))
//
//#define rev(v) reverse(v.begin(),v.end())
//#define srt(v) sort(v.begin(),v.end())
//
//#define all(v) v.begin(),v.end()
//#define MEM(a, b) memset(a, b, sizeof(a))
//
//#define fast ios_base::sync_with_stdio(false)
//using namespace std;
//
//const ll INF = 0x3f3f3f3f3f3f3f3f;
//const long double EPS = 1e-9;
//const int inf = 0x3f3f3f3f;
///// count set bit C = (num * 0x200040008001ULL & 0x111111111111111ULL) % 0xf; /// 32 bit integer
//
///*------------------------------Graph Moves----------------------------*/
////Rotation: S -> E -> N -> W
////const int fx[] = {0, +1, 0, -1};
////const int fy[] = {-1, 0, +1, 0};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
////const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
////const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
///*---------------------------------------------------------------------*/
//
//int BIT[26][100010], n;
//
//void update(int pos, int idx, int x)
//{
//    while (idx <= n)
//    {
//        BIT[pos][idx] += x;
//        idx += (idx & -idx);
//    }
//}
//
//int go(int pos, int idx)
//{
//    int sm = 0;
//    while (idx > 0) {
//        sm += BIT[pos][idx];
//        idx -= (idx & -idx);
//    }
//    return sm;
//}
//
//int query(int pos, int i, int j)
//{
//    return go(pos, j) - go(pos, i - 1);
//}
//
//int main()
//{
//        string s;
//        cin >> s;
//        n = s.length();
//        s = "#" + s;
//        for (int i = 1; i < (int)s.length(); i++) {
//            update(s[i] - 'a', i, 1);
//        }
//
//        int q;
//        cin >> q;
//        while (q--) {
//            int Q;
//            cin >> Q;
//            if (Q & 1) {
//                int pos;
//                char ch;
//                cin >> pos >> ch;
//                update(s[pos] - 'a', pos, -1);
//                s[pos] = ch;
//                update(s[pos] - 'a', pos, 1);
//            }
//            else {
//                int l, r;
//                cin >> l >> r;
//                int ans = 0;
//                for (int i = 0; i < 26; i++)
//                    if (query(i, l, r) > 0) ans++;
//                cout << ans << endl;
//            }
//        }
//
//}


/// Another with set and lower_bound
#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	vector<set<int>> poss(26);
	for (int i = 0; i < int(s.size()); ++i) {
		poss[s[i] - 'a'].insert(i);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			--pos;
			poss[s[pos] - 'a'].erase(pos);
			s[pos] = c;
			poss[s[pos] - 'a'].insert(pos);
		} else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			int cnt = 0;
			for (int c = 0; c < 26; ++c) {
				auto it = poss[c].lower_bound(l);
				if (it != poss[c].end() && *it <= r) ++cnt;
			}
			cout << cnt << endl;
		}
	}

	return 0;
}


