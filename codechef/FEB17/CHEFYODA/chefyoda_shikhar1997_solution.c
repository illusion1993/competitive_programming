#include<stdio.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        int n,m,f;
        double p,k,r,ans=0,j,s;
        scanf("%d%d%lf%lf",&n,&m,&p,&k);
        if((n%2==0&&m%2==0)||p==0)
        {
            printf("1.000000\n");
        }
        else if(n%2==1&&m%2==1)
        {
            printf("0.000000\n");
        }
        else
        {
            r=p;
            if(r>k/2)
                r=k-r;
            for(j=1;j<=r;j++)
            {
                ans=ans+log(k-r+j);
                ans=ans-log(j);
            }
            //printf("%lf\n",exp(ans));
            /*for(j=1;j<=k;j++)
            {
                ans=ans-log(2);
            }*/
            ans=ans-k*log(2);
            //printf("%lf\n",exp(ans));
            s=ans;
            ans=exp(ans);
            f=0;
            for(j=p+1;j<=k;j++)
            {
                s=s+(log(k-(j-1))-log(j));
                ans=ans+exp(s);
                if(exp(s)==0.0)
                {
                    if(j<k/2)
                    {
                        f=1;
                    }
                    break;
                }
                //printf("%lf\n",exp(s));
            }
            if(f==0)
                printf("%lf\n",ans);
            else
                printf("1.000000\n");
        }
    }
    return 0;
}
