#include <stdio.h>

void increment_data(int *y,int *m,int *d){
    // それぞれの月の月末の日付 //
    int month_last_days[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //　同じ月で日付が変わる場合　//
    if(*d<month_last_days[*m]){
        (*d)++;
    }
    //　月をまたいで日付が変わる場合　//
    else if(*m!=12 && *d==month_last_days[*m]){
        (*m)++; *d=1;
    }
    //　年をまたいで日付が変わる場合　//
    else{
        (*y)++; *m=1; *d=1;
    }
}

int main(void)
{
    int y,m,d;
    // それぞれの月の月末の日付 //
    int month_last_days[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    do{
    printf("西暦（年）を入力してください："); scanf("%d", &y);
    printf("月を入力してください："); scanf("%d", &m);
    printf("日を入力してください："); scanf("%d", &d);
    }while(y<1 || m<1 || m>12 || d<1 || d>month_last_days[m]);

   increment_data(&y,&m,&d);

    printf("次の日は西暦%d年%d月%d日です。",y,m,d);

    return 0;
}
