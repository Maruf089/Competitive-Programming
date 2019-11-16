
#include<bits/stdc++.h>
using namespace std;

int main() {
    long int n, i = 1, cases,a,b,c,d,e,f,ans;
    long int arr[100000];
    cin>>cases;

    while( cases-- ) {
      cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5]>>n;
      for(int m=6;m<=n;m++)
      {
          arr[m]=(arr[m-1]+arr[m-2]+arr[m-3]+arr[m-4]+arr[m-5]+arr[m-6])%10000007;
      }
        printf("Case %ld: %ld\n", i++, arr[n] % 10000007);
    }
    return 0;
}
