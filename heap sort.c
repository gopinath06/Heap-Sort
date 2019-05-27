#include<stdio.h>
#include<malloc.h>
int main()  {
    int n, *h, i, c, r=0, t;
    scanf("%d",&n);
    h = malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        scanf("%d",&h[i]);
    for(i=1; i<n; i++)  {
        c = i;
        do  {
            r = (c-1)/2;
            if(h[r]<h[c])   {
                t = h[r];
                h[r] = h[c];
                h[c] = t;
            }
            c = r;
        }while(c!=0);
    }
    for(i=0; i<n; i++)
        printf("%d ",h[i]);
    printf("\n");
    for(i=n-1; i>=0; i--)   {
        t = h[0];
        h[0] = h[i];
        h[i] = t;
        r = 0;
       do  {
            c = r*2 + 1;
            if(h[c]<h[c+1] && c<i-1)
                c++;
            if(h[r]<h[c] && c<i)    {
                t = h[r];
                h[r] = h[c];
                h[r] = t;
            }
            r = c;
           // printf("%d",h[i]);
        }while(c<i);
       //  printf("%d",h[i]);
    }

    for(i=0; i<n; i++)
        printf("%d ",h[i]);
}
