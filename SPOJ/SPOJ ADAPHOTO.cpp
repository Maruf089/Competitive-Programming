#include<bits/stdc++.h>
using namespace std;

class suffix_automaton
{
    struct state
    {
        int len,link = 0;
        bool terminal = false;
        bool is_clone = false;
        map<char,int>next;
        state(int len=0) : len(len) {}
        bool have_next(char ch)
        {
            return ( next.find(ch) != next.end() );
        }
    };
    vector<state>st;
    vector<long long>dp;
    vector<long long>tot_length;
    int last = 0;
public:
    suffix_automaton()
    {
        st.push_back(state());
        st[0].link = -1;
    }
    suffix_automaton(const string &s) : suffix_automaton()
    {
        for(char ch : s)
            sa_extend(ch);
        mark_terminals();
        dp = vector<long long>(st.size());
        tot_length = vector<long long>(st.size());
    }

    void mark_terminals()
    {
        for(int cur = last; cur>=0; cur = st[cur].link)
            st[cur].terminal = true;
    }

    void sa_extend(char c)
    {
        int cur = st.size(); /// creat new node
        st.push_back(state(st[last].len + 1));
        int parent = last;
        last = cur;

        while (parent != -1 && !st[parent].have_next(c))
        {
            st[parent].next[c] = cur; /// connect edge(parent,new node)
            parent = st[parent].link;
        }
        if(parent == -1)
        {
            st[cur].link = 0;
        }
        else
        {
            int probable_fail_link = st[parent].next[c]; /// found probable fail node
            if (st[parent].len + 1 == st[probable_fail_link].len)
            {
                st[cur].link = probable_fail_link; /// coonect edge(new node , probable fail node)
            }
            else
            {
                int clone = st.size(); /// make clone node
                st.push_back((st[probable_fail_link]));
                st[clone].is_clone = true;
                st[clone].len = st[parent].len + 1;
                st[clone].next = st[probable_fail_link].next;
                st[clone].link = st[probable_fail_link].link;
                while (parent != -1 && st[parent].next[c] == probable_fail_link)
                {
                    st[parent].next[c] = clone; /// connect(parent,clone node)
                    parent = st[parent].link;
                }
                st[probable_fail_link].link = st[cur].link = clone;
            }
        }
    }

    int lcs (string T)
    {
        int v = 0, l = 0, best = 0, bestpos = 0;
        for (int i = 0; i < T.size(); i++)
        {
            while (v && !st[v].next.count(T[i]))
            {
                v = st[v].link ;
                l = st[v].len ;
            }
            if (st[v].next.count(T[i]))
            {
                v = st [v].next[T[i]];
                l++;
            }
            if (l > best)
            {
                best = l;
                bestpos = i;
            }
        }
        return T.substr(bestpos - best + 1, best).size();
    }


};


int main()
{
    int t = 1;
    //cin >> t;
    while(t--)
    {
        string s, T;
        cin >> s >> T;
        suffix_automaton obj(s);

        cout << obj.lcs(T) << endl;
    }
}

