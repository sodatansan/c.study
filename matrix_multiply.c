#include <stdio.h>

void mat_mul(const int a[4][3],const int b[3][4],int c[4][4])
{
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            for(int k=0;k<3;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

void mat_print(const int c[4][4])
{
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            printf("%4d",c[i][j]);
        }
        putchar('\n');
    }
}

int main(void)
{
    int a[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int b[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int c[4][4]={0};

    mat_mul(a,b,c);

    puts("a[4][3]とb[3][4]の積は...");    mat_print(c);

    return 0;
}
