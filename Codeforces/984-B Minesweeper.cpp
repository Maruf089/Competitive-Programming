#include<iostream>
#define INT(z) (int)z - 48
using namespace std;
int main()
{
    int x, y, temp, flag = 0;
    cin >> x >> y ;
    char arr[x][y] = {0} ;

    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            cin >> arr[i][j] ;
        }
    }
    /// . = -2
    /// * = -6

    for(int i=0; i<x; i++)
    {
        for(int j=0; j<y; j++)
        {
            int count = 0;
            if(INT(arr[i][j])!=-6)
            {
                if((i-1)>=0)
                {
                    if(arr[i-1][j]=='*') count++ ;
                }
                if((j-1)>=0)
                {
                    if(arr[i][j-1]=='*') count++ ;
                }
                if((i-1)>=0 && (j-1)>=0)
                {
                    if(arr[i-1][j-1]=='*') count++ ;
                }
                if((i+1)<x)
                {
                    if(arr[i+1][j]=='*') count++ ;
                }
                if((j+1)<y)
                {
                    if(arr[i][j+1]=='*') count++ ;
                }
                if((i+1)<x && (j+1)<y)
                {
                    if(arr[i+1][j+1]=='*') count++ ;
                }
                if((i-1)>=0 && (j+1)<y)
                {
                    if(arr[i-1][j+1]=='*') count++ ;
                }
                if((i+1)<x && (j-1)>=0)
                {
                    if(arr[i+1][j-1]=='*') count++ ;
                }
                ///cout << count << endl;
                if(arr[i][j]!='.')
                {
                    if(count!=INT(arr[i][j]))
                        flag = 1;
                }
                else
                    if(count!=0)
                        flag = 1;
            }
        }
    }

    if(flag==1)
        cout << "NO";
    else
        cout << "YES";
}
