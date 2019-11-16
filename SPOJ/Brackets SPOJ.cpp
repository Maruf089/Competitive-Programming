#include <iostream>
#include<bits/stdc++.h>
#define D(x) cout<< #x " = "<<x<<endl
using namespace std;
#define MAX 300005

struct DATA
{
    int open_brackets;
    int close_brackets;
    DATA()
    {
        open_brackets=close_brackets = 0;
    }
};

DATA sum[4*MAX];
char str[MAX];

void build_tree(int node, int a, int b)
{
    if(a>b)
    {
        return;
    }
    if(a==b)
    {
        if(str[a]=='(')
        {
            sum[node].open_brackets = 1;
            sum[node].close_brackets = 0;
        }
        else
        {
            sum[node].open_brackets = 0;
            sum[node].close_brackets = 1;
        }
   ///     cout << " a == b " <<endl;
   ///     cout<<" sum["<<node<<"] "<<str[node]<<" "<<sum[node].open_brackets<<" "<<sum[node].close_brackets<<" \n";
        return;
    }

    build_tree(2*node, a, (a+b)/2);
    build_tree((2*node)+1,((a+b)/2)+1, b);
///  D(node);
    int ol = sum[2*node].open_brackets;
    int cl = sum[2*node].close_brackets;
  ///  cout << " 2 * node "<<endl;
  ///  cout<<" sum["<<2*node<<"] = "<<" "<<sum[2*node].open_brackets<<" "<<sum[2*node].close_brackets<<endl;

    int orr = sum[2*node+1].open_brackets;
    int crr = sum[2*node+1].close_brackets;
 ///   cout << " 2 * node "<<endl;
  ///  cout<<" sum["<<2*node+1<<"] = "<<" "<<sum[2*node+1].open_brackets<<" "<<sum[2*node+1].close_brackets<<endl;

   ///  D(ol),D(cl);D(orr),D(crr);

    if(ol>=crr)
    {
   ///     cout << " if 1" << endl;
        sum[node].open_brackets = ol + orr - crr;
    }
    else
    {
   ///      cout << " else 1" << endl;
        sum[node].open_brackets = orr;
    }
    if(ol<=crr)
    {
  ///      cout << " if 2 "<< endl;
        sum[node].close_brackets = cl+crr-ol;
    }
    else
    {
  ///      cout << " else 2"<<endl;
        sum[node].close_brackets = cl;
    }
  ///  cout << " last part\n";
   /// cout<<" sum["<<node<<"] "<<str[node]<<" "<<sum[node].open_brackets<<" "<<sum[node].close_brackets<<" \n";
}

void update_tree(int node, int a, int b, int val)
{
    if(a>b)
    {
        return;
    }

    if(a==b)
    {
        if(str[val]=='(')
        {
            sum[node].open_brackets--;
            sum[node].close_brackets++;
            str[val] = ')';
        }
        else
        {
            sum[node].open_brackets++;
            sum[node].close_brackets--;
            str[val] = '(';
        }
 ///   cout<<str<<endl;
        return;
    }
    if(val <=(a+b)/2)
    {
        update_tree(2*node, a, (a+b)/2,val);
    }
    else
    {
        update_tree((2*node)+1,((a+b)/2)+1, b,val);
    }

 //   D(node);
    int ol = sum[2*node].open_brackets;
    int cl = sum[2*node].close_brackets;
 ///   cout << " 2 * node "<<endl;
///    cout<<" sum["<<2*node<<"] = "<<" "<<sum[2*node].open_brackets<<" "<<sum[2*node].close_brackets<<endl;

    int orr = sum[2*node+1].open_brackets;
    int crr = sum[2*node+1].close_brackets;
///    cout << " 2 * node "<<endl;
///    cout<<" sum["<<2*node+1<<"] = "<<" "<<sum[2*node+1].open_brackets<<" "<<sum[2*node+1].close_brackets<<endl;

///  D(ol),D(cl);D(orr),D(crr);

    if(ol>=crr)
    {
    ///    cout << " if 1" << endl;
        sum[node].open_brackets = ol + orr - crr;
    }
    else
    {
    ///     cout << " else 1" << endl;
        sum[node].open_brackets = orr;
    }
    if(ol<=crr)
    {
   ///     cout << " if 2 "<< endl;
        sum[node].close_brackets = cl+crr-ol;
    }
    else
    {
 ///       cout << " else 2"<<endl;
        sum[node].close_brackets = cl;
    }
 ///   cout << " last part\n";
  ///  cout<<" sum["<<node<<"] "<<str[node]<<" "<<sum[node].open_brackets<<" "<<sum[node].close_brackets<<" \n";
}
int main()
{
    int stlen, m, k;

    for(int i = 1; i<=10; i++)
    {
        printf("Test %d:\n",i);
        scanf("%d",&stlen);
        scanf("%s", str);
        stlen--;
        build_tree(1,0,stlen);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&k);
            if(k==0)
            {
                if(str[0]==')')
                {
                    cout<<"NO\n";
                }
                else
                {
        ///            cout<<sum[1].open_brackets<<" "<<sum[1].close_brackets;
                    if(sum[1].close_brackets==0&&sum[1].open_brackets==0)
                    {
                        printf("YES\n");
                    }
                    else
                    {
                        printf("NO\n");
                    }
                }

            }
            else
            {
                update_tree(1,0,stlen,k-1);
            }
        }
    }

}
