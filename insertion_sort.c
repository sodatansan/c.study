#include <stdio.h>

#define MAX_SIZE 100 // 最大100個まで対応
//並び替え関数
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//挿入ソート
void insertion_sort(int *data,int num){
    for(int i=1;i<num;i++){
        int target=data[i]; // 挿入したい主役の数字を退避
        int j=i-1;
        // 自分より大きい数字を、1つずつ右にずらして隙間を作る
        while(j>=0 && data[j]>target){
            data[j+1]=data[j];
            j--;
        }
        // 空いた正しい位置に主役を差し込む
        data[j+1]=target;
    }
}


int main(void) {
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
    insertion_sort(data,num);

    // 結果
    puts("昇順に並び替えました。");
    for(int i=0;i<num;i++){
        printf("整数%d : %d\n",i+1,data[i]);
    }

    return 0;
}
