#include <stdio.h>

#define MAX_SIZE 100 // 最大100個まで対応
//並び替え関数
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
//選択ソート
void selection_sort(int *data,int num){
    for(int i=0;i<num-1;i++){
        int min_idx=i; // 左端の箱を一番小さい箱として仮定
        for(int j=i+1;j<num;j++){
            if(data[j]<data[min_idx]){
                min_idx=j; // もっと小さい箱を見つけたら更新
            }
        }
        // 見つかった一番小さい箱と、左端の箱を交換
        if(min_idx!=i){
            swap(&data[i],&data[min_idx]);
        }
    }
}
int main(void){
    int num;
    int data[MAX_SIZE];

    // 任意の数値を入力
    do {
        printf("何個の数字を並び替えますか？(1〜%d): ", MAX_SIZE);
        scanf("%d",&num);
    }while(num<1 || num>MAX_SIZE);
    for(int i=0;i<num;i++){
        printf("整数%d : ",i+1);
        scanf("%d",&data[i]);
    }

    //関数呼び出し
    selection_sort(data,num);

    // 結果
    puts("昇順に並び替えました。");
    for(int i=0;i<num;i++){
        printf("整数%d : %d\n",i+1,data[i]);
    }

    return 0;
}
