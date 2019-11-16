#include <stdio.h>
#define sqr(x) (x)*(x)
const double eps = 1e-7;

int main()
{
    int T, icase = 1;
    double a, b, c;
    scanf("%d", &T);
    while(T--){
        scanf("%lf%lf%lf", &a, &b, &c);
        printf("Case %d: ", icase++);
        if(sqr(b)-a*c < eps){
            printf("-1\n");
            continue;
        }
        printf("%.16lf\n", a*c*(a+b)/(sqr(b)-a*c) + a*c*(b+c)/(sqr(b)-a*c));
    }

    return 0;
}
