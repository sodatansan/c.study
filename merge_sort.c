#include <stdio.h>

#define MAX_SIZE 100 //最大100個まで対応

//マージソート(並び替えて合体)
void merge(int *data,int left,int mid,int right){
    int i=left;  //左の先頭
    int j=mid+1; //右の先頭
    int k=0;     //空の配列の要素番号
    int temp[MAX_SIZE]; //並び替えた結果を一時的にキープする空の配列
    //左側グループと右側グループの「先頭同士」を比べ、小さい方をtempに
    while(i<=mid && j<=right){
        if(data[i]<=data[j]){
            temp[k]=data[i]; //左側グループの先頭が小さければ、tempにコピー
            i++; //左側グループの先頭を詰める
        }
        else{
            temp[k]=data[j]; //右側グループの先頭が小さければ、tempにコピー
            j++; //右側グループの先頭を詰める
        }
        k++;
    }
    //どちらかのチームが空っぽになった後、残った数字をtempに詰める
    while(i<=mid){  //左チームが残っていたら詰める
        temp[k++]=data[i++];
    }
    while(j<=right){ //右チームが残っていたら詰める
        temp[k++]=data[j++];
    }
    //tempで並び終えた数字を、本物の配列（data）に書き戻す
    for(i=left,k=0;i<=right;i++,k++){
        data[i]=temp[k];
    }
}

//マージソート(細分化)
void merge_sort(int *data, int left, int right) {
    //部屋の範囲が逆転したり、要素が1個だけ（left == right）になったらストップ
    if(left>=right) return;
    //真ん中の位置を計算する
    int mid=left+(right-left)/2;

    //ターゲットの範囲を、左半分と右半分に「これ以上割れない」という最小単位まで割り続ける
    merge_sort(data,left,mid);      //左半分を分解
    merge_sort(data,mid+1,right); //右半分を分解
    //関数を呼び出してバラバラになった左右のグループ並び替えながら合体
    merge(data,left,mid,right);
}

int main(void){
    int num;
    int data[MAX_SIZE];

    //任意の数値を入力
    do{
        printf("何個の数字を並び替えますか？(1?%d): ", MAX_SIZE);
        scanf("%d",&num);
    }while(num<1 || num>MAX_SIZE);
    for(int i=0;i<num;i++){
        printf("整数%d : ",i+1);
        scanf("%d",&data[i]);
    }

    //関数呼び出し
    merge_sort(data,0,num-1);

    //結果
    puts("昇順に並び替えました。");
    for(int i=0;i<num;i++){
        printf("整数%d : %d\n",i+1,data[i]);
    }

    return 0;
}
