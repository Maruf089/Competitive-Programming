#include <bits/stdc++.h>

using namespace std;

#define LL long long
struct Hashing
{
    LL *hash1, *hash2;
    LL *inv1, *inv2;
    int n;
    LL mod1 = (LL) 1e9 + 97, mod2 = (LL) 1e9 + 9;
    LL multiplier1 = 43, multiplier2 = 31;
    LL invMultiplier1 = 441860508, invMultiplier2 = 838709685;
    // invMultiplier = modInv(multiplier, mod) //

    Hashing()
    {

    }

    Hashing(string &s)
    {
        build_Hash(s);
    }

    void build_Hash(string &s)
    {
        n = s.size();
        hash1 = new LL[n + 1];
        hash2 = new LL[n + 1];
        inv1 = new LL[n + 1];
        inv2 = new LL[n + 1];

        hash1[0] = hash2[0] = 0;
        inv1[0] = inv2[0] = 1;

        LL p1 = 1, p2 = 1;

        for (int i = 0; i < n; i++)
        {
            hash1[i + 1] = (hash1[i] + s[i] * p1) % mod1;
            p1 = (p1 * multiplier1) % mod1;
            inv1[i + 1] = inv1[i] * invMultiplier1 % mod1;
            hash2[i + 1] = (hash2[i] + s[i] * p2) % mod2;
            p2 = (p2 * multiplier2) % mod2;
            inv2[i + 1] = inv2[i] * invMultiplier2 % mod2;
        }
    }


    LL getHash(int i, int j)   //0-based, hash of substring [i, j]
    {
        return getHash_2(i, j - i + 1);
    }

    LL getHash_2(int i, int len)   //0- based, hash of substring [i, i+len-1]
    {
        return (((hash1[i + len] - hash1[i] + mod1) * inv1[i] % mod1) << 32)
               + (hash2[i + len] - hash2[i] + mod2) * inv2[i] % mod2;
    }

    LL revHash(int i, int j)   //0-based
    {
        return getHash(n - j - 1, n - i - 1);
    }

    void clear()
    {
        delete hash1;
        delete hash2;
        delete inv1;
        delete inv2;
    }
};




const int mx= 200002;
string pat;
string rev_pat;
///char txt[mx];
///char pat[mx];
int lps[mx];/// It is the heart of kmp search , longest prefix array which is also suffix till ith index

/// KMP pattern Matching O (n+m) time complexity ,where n and m is the length of text and pattern length
/// Here ,we use the logic of longest suffix which is also prefix


/// Fills lps[] for given patttern pat[0..M-1]
/// A two pointer approach
int computeLPSArray()
{
    /// traverser of prefix ,left
    int left = 0;
    int P=(pat).size();
    lps[0] = 0; /// lps[0] is always 0

    int right = 1;
    while (right < P)
    {
        if (pat[right] == pat[left])
        {
            left++;
            lps[right] = left;/// take longest suffix length which is also prefix
            right++;
        }
        else /// (pat[right] != pat[left])
        {
            if (left != 0)
            {
                left = lps[left - 1];
            }
            else /// if (len == 0) ,then start from again start ,because there is no common suffix and prefix till right index
            {
                lps[right] = 0;
                right++;
            }
        }
    }
    return lps[P-1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int caso=1;
    int n;
    string base;
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>pat;
        base=pat;
        rev_pat=pat;
        reverse(rev_pat.begin(),rev_pat.end());
        string will_be_add="";
        if(rev_pat==pat)
        {
            int mx_match_wth=computeLPSArray();
            for(int i=mx_match_wth; i<pat.length(); i++)
                will_be_add+=pat[i];
            cout<<base<<" "<<will_be_add<<endl;
        }
        else
        {
            string s,ss;
            s = pat;
            ss = pat;
            reverse(ss.begin(),ss.end());

            Hashing hh(s);
            Hashing revhh(ss);

            int ans = 1;
            for(int i=0; i<s.size(); i++)
            {
                long hash1 = hh.getHash(i,s.size()-1);
                long revhash1 = revhh.getHash(0,s.size()-1-i);

                if(hash1==revhash1)
                {
                    ans = s.size() - i;
                    break;
                }
            }
            ans = s.size() - ans;
            cout << s << ' ';
            if(ans)
            {
                ss = "";
                for(int i=0; i<ans; i++)
                    ss += s[i];
                reverse(ss.begin(),ss.end());
                cout << ss;
            }
            cout << endl;

            hh.clear();
            revhh.clear();

        }
    }
    return 0;
}
