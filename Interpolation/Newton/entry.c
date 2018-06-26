#include <stdio.h>
#define MAXN 100
#define ORDER 4
 
int main(int argc, char const *argv[])
{
    float ax[MAXN+1], ay[MAXN+1], diff[MAXN+1][ORDER+1],
            nr=1.0, dr=1.0, x, p, h, yp;
    int n, i, j, k;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    printf("Enter the values in the form of x,y \n");
    for (i=0;i<=n;i++){
        scanf("%f %f", &ax[i], &ay[i]);
    }
    printf("Enter the values of x for which values of y is wanted \n ");
    scanf("%f", &x);
    h=ax[1]-ax[0];

    /**
     * now making the diff table calculating the first order differences
     * /
     */
    for(i=0;i<=n-1;i++)
        diff[i][i] =ay[i+1]-ay[i];
    /**
     * calculating the second and higher order differences 
     * */
    for (j=2;j<=ORDER;j++){
        for(i=0;i<=n-j;i++){
            diff[i][j] = diff[i+1][j-1] -diff[i][j-1];
        
        }
    }
    // now finding x0
    i=0;
    while(!(ax[i] > x)) i++;
    i--;
    p=(x-ax[i])/h;
    yp= ay[i];
    for(k=1;k<=ORDER;k++){
        nr *=p-k+1;
        dr *=k;
        yp += (nr/dr)*diff[i][k];

    }   
    printf("when x= %6.1f , y = %6.2f .\n ", x, yp); 
    return 0;
}
