#include <stdio.h>

#define MAX_SIZE 100 // 最大100個まで対応
//並び替え関数
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//バブルソート
void bubble_sort(int *data,int num){
    for(int i=0;i<num-1;i++){
        for(int j=0;j<num-1-i;j++) { //-iをすることで並び替え済みを排除
            if(data[j]>data[j+1]){
                swap(&data[j], &data[j+1]); 
            }
        }
    }
}

int main(void){
    int num;
    int data[MAX_SIZE];

    // 任意の数値を入力
    do{
        printf("何個の数字を並び替えますか？(1〜%d):",MAX_SIZE);
        scanf("%d",&num);
    }while(num<1 || num>MAX_SIZE);
    for(int i=0;i<num;i++){
        printf("整数%d :",i+1);
        scanf("%d",&data[i]);
    }

    //関数呼び出し
    bubble_sort(data,num);

    // 結果
    puts("昇順に並び替えました。");
    for(int i=0;i<num;i++){
        printf("整数%d :%d\n",i+1,data[i]);
    }

    return 0;
}
