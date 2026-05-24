#include <stdio.h>

#define MAX_SIZE 100 //最大100個まで対応

//ヒープソート（3つの塊（親・左子・右子）の比較を繰り返す関数）
void down_heap(int *data,int left,int right){
    int temp=data[left]; //最初の親の値
    int parent=left;     //親の部屋番号
    int child;           //子の部屋番号
    //子が存在する限り、3つの塊の比較を繰り返す
    while(parent*2+1<=right){
        child=parent*2+1; //対象を左の子に変える
        //右の子も存在し、かつ左の子より大きければ、右の子を比較する
        if(child+1<=right && data[child]<data[child+1]){
            child++;
        }
        //親の値の方が大きければ、3つの塊の並びは正しくなるため終了
        if(temp>=data[child]){
            break;
        }
        //子どもの方が大きければ、親の部屋へ移動
        data[parent]=data[child];
        parent=child; //親の現在地を、下に落とした子の部屋へ移動
    }
    data[parent]=temp; //最後に空いた部屋に値をはめ込む
}

//ヒープソート（メイン関数）
void heap_sort(int *data,int num){
    int i;
    //下層の3つの塊から順に上へ向かってピラミッドを作る
    for(i=(num - 2)/2;i>=0;i--){
        down_heap(data,i,num-1);
    }
    //頂点の親を後ろに追いやり、残った子で次の親を決める
    for(i=num-1;i>0;i--){
        //頂点(0番)の最大値と今の一番後ろ(i番)の値を入れ替える
        int temp=data[0];
        data[0]=data[i];
        data[i]=temp;
        //親を範囲から外し、再び頂点(0番)から3つの塊の比較を行う
        down_heap(data,0,i-1);
    }
}

int main(void){
    int num;
    int data[MAX_SIZE];

    //任意の数値を入力
    do{
        printf("何個の数字を並び替えますか？(1?%d):",MAX_SIZE);
        scanf("%d",&num);
    }while(num<1 || num>MAX_SIZE);
    for(int i=0;i<num;i++){
        printf("整数%d : ",i+1);
        scanf("%d",&data[i]);
    }

    //関数呼び出し
    heap_sort(data,num);

    //結果
    puts("昇順に並び替えました。");
    for(int i=0;i<num;i++){
        printf("整数%d : %d\n",i+1,data[i]);
    }

    return 0;
}
