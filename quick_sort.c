#include <stdio.h>

#define MAX_SIZE 100 //最大100個まで対応
//並び替え関数
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//クイックソート
void quick_sort(int *data,int left,int right){
    //部屋の範囲が逆転したり、部屋が1つ（left == right）になったら並び替え終了
    if(left>=right) return; 
    //調べる範囲のちょうど真ん中にある数字をpivotに
    int pivot=data[left+(right-left)/2];    
    int i=left;  
    int j=right; 

    //「小さいグループ」と「大きいグループ」に分ける
    while(i<=j){
        //左側からpivotより「大きいやつ」を見つけるまで右へ進む
        while(data[i]<pivot) i++;      
        //右側からpivotより「小さいやつ」を見つけるまで左へ進む
        while(data[j]>pivot) j--; 
        
        //見つけたターゲット同士を入れ替える
        if(i<=j){
            swap(&data[i],&data[j]); 
            i++; //右の次の部屋へ
            j--; //左の次の部屋へ
        }
    }
    //分けられた2つのグループを、さらに細分化していき繰り返す
    //左側のグループ（pivotより小さいグループ）をもう一度クイックソート
    quick_sort(data,left,j);   
    // 右側のグループ（pivotより大きかったグループ）をもう一度クイックソート
    quick_sort(data,i,right);
}

int main(void) {
    int num;
    int data[MAX_SIZE];

    // 任意の数値を入力
    do {
        printf("何個の数字を並び替えますか？(1?%d): ", MAX_SIZE);
        scanf("%d",&num);
    }while(num<1 || num>MAX_SIZE);
    for(int i=0;i<num;i++){
        printf("整数%d : ",i+1);
        scanf("%d",&data[i]);
    }

    //関数呼び出し
    quick_sort(data,0,num-1);

    // 結果
    puts("昇順に並び替えました。");
    for(int i=0;i<num;i++){
        printf("整数%d : %d\n",i+1,data[i]);
    }
    return 0;
}
