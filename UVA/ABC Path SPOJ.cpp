#include <bits/stdc++.h>
#define pi acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int>vc;
vector<vc>graph;
int xr[]= {-1,-1,-1,0,0,1,1,1};
int yc[]= {-1,0,1,-1,1,-1,0,1};

char ss[51][51];
bool visit[51][51];
int r,c,cnt,Max;
bool flag;

int dfs(int row,int col)
{
    if(ss[row][col]=='A'&&flag==false) return Max;
    flag=false;
    for(int i=0; i<8; i++)
    {
        int x=row+xr[i];
        int y=col+yc[i];
        if(x>=0&&x<r&&y>=0&&y<c&&visit[x][y]==0&&ss[x][y]==(ss[row]

[col]+1))
        {
            // cout<<x<<y<<endl;
            visit[x][y]=1;
            cnt++;
            Max=max(Max,cnt);
            //  cout<<Max<<endl;
            dfs(x,y);
            cnt--;
          //  visit[x][y]=0;
            //  return Max;
        }

    }
    return Max;


}


int main()
{
    //   freopen("inp.txt","r",stdin);
    int cas=0;
    while(~scanf("%d %d",&r,&c))
    {
        if(!r&&!c) break;
        for(int i=0; i<r; i++) cin>>ss[i];
        int res=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(ss[i][j]=='A')
                {
                    memset(visit,0,sizeof(visit));
                    cnt=1;
                    Max=1;
                    flag=true;
                    int v=  dfs(i,j);
                    //  cout<<v<<endl;
                    res=max( res, v);
                }
            }
        }
        printf("Case %d: %d\n",++cas,res);
    }

    return 0;
}


/*


#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#define in_range(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)
using namespace std;

char mat[51][51];
int r, c, dis[51][51];

void dfs(int i, int j, int dist){
	int x, y;
	dis[i][j] = dist+1;

	x = i-1;
	y = j-1;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

	x = i-1;
	y = j;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

	x = i-1;
	y = j+1;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

	x = i;
	y = j-1;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

	x = i;
	y = j+1;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

	x = i+1;
	y = j-1;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

	x = i+1;
	y = j;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

	x = i+1;
	y = j+1;
	if(in_range(x, y, r, c) && mat[x][y] == mat[i][j] + 1 && dis[x][y] < dis[i][j] + 1){
		dfs(x, y, dis[i][j]);
	}

}

int main(){

	int max, tc=0;

	while(true){
		scanf("%d%d", &r, &c);
		if(!r && !c)
			break;
		tc++;
		for(int i=0;i<r;i++){
			scanf("%s", mat[i]);
			for(int j=0;j<c;j++)
				dis[i][j] = 0;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(mat[i][j] == 'A' && dis[i][j] == 0)
					dfs(i, j, 0);
			}
		}
		max = dis[0][0];
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				if(max < dis[i][j])
					max = dis[i][j];
		}
		printf("Case %d: %d\n", tc, max);
	}
    return 0;
}


*/
