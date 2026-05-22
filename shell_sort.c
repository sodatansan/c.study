#include <stdio.h>

#define MAX_SIZE 100 //最大100個まで対応
//シェルソート
void shell_sort(int *data,int num){
    //gapの間隔で、1周ごとに間隔を半分に狭めていく
    for(int gap=num/2;gap>0;gap/= 2){       
        //gap個離れた隣同士をグループにして、順番にチェック
        for(int i=gap;i<num;i++){    
            int target=data[i]; //並び替えたい主役の数字を退避
            int j=i-gap; //gap個左の部屋の番号
            //主役より大きい数字が左側にある間は、gap個右へずらす
            while(j>=0 && data[j]>target){
                data[j+gap]=data[j]; //gap個右へコピー
                j-=gap;                //gap個左の部屋へ進む
            }
            //空いた正しい位置に主役を差し込む
            data[j+gap]=target;
        }
    }
}
int main(void){
    int num;
    int data[MAX_SIZE];

    //任意の数値を入力
    do {
        printf("何個の数字を並び替えますか？(1?%d): ", MAX_SIZE);
        scanf("%d",&num);
    }while(num<1 || num>MAX_SIZE);
    for(int i=0;i<num;i++){
        printf("整数%d : ",i+1);
        scanf("%d",&data[i]);
    }

    //関数呼び出し
    shell_sort(data,num);

    //結果
    puts("昇順に並び替えました。");
    for(int i=0;i<num;i++){
        printf("整数%d : %d\n",i+1,data[i]);
    }
    return 0;
}
