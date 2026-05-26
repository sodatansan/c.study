#include <stdio.h>
#include <string.h>

#define NAME_LEN 50  //名前の文字数

//学生を表す構造体//
typedef struct{
    char name[NAME_LEN]; //名前
    int height;          //身長
    double weight;       //体重
} Student;

//学生を入れ替え//
void swap_Student(Student *x,Student *y){
    Student temp=*x;
    *x=*y;
    *y=temp;
}

//名前の昇順でソート//
void sort_by_name(Student a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(strcmp(a[j-1].name,a[j].name)>0){
                swap_Student(&a[j-1],&a[j]);
            }
        }
    }
}

//身長の昇順にソート//
void sort_by_height(Student a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1].height > a[j].height){
                swap_Student(&a[j-1],&a[j]);
            }
        }
    }
}

//体重の昇順でソート//
void sort_by_weight(Student a[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1].weight > a[j].weight){
                swap_Student(&a[j-1],&a[j]);
            }
        }
    }
}

int main(void)
{
    int num;
    int select;

    //学生数を入力//
    puts("学生の人数を入力してください。(1~100)");
    scanf("%d",&num);

    Student std[num];
    //それぞれの学生の名前、身長、体重を入力//
    puts("学生の名前、身長、体重を入力してください。");
    for(int i=0;i<num;i++){
        printf("名前：");
        scanf("%s",std[i].name);
        printf("身長：");
        scanf("%d",&std[i].height);
        printf("体重：");
        scanf("%lf",&std[i].weight);
        if(i<num-1)
            puts("次の学生を入力してください。"); 
    }
    //入力データ表示//
    puts("\n入力データ一覧");
    for(int i=0;i<num;i++){
        printf("%-8s %6d%6.1f\n",std[i].name,std[i].height,std[i].weight);
    }

    puts("\n何で並び替えますか？(1:名前順、2:身長順、3:体重順)");
    scanf("%d", &select);

    switch(select){
        case 1: //名前の昇順にソート
            sort_by_name(std,num);
            puts("\n名前順に並び替えました。");
            break; 
        case 2: //身長の昇順にソート
            sort_by_height(std,num);
            puts("\n身長順に並び替えました。");
            break;

        case 3: //体重の昇順にソート
            sort_by_weight(std,num);
            puts("\n体重順に並び替えました。");
            break;

        default: //それ以外は何もしない
            puts("\n1?3以外の数字が入力されたため、そのまま出力します。");
            break;
    }

    //結果表示//
    for(int i=0;i<num;i++){
        printf("%-8s %6d%6.1f\n",std[i].name,std[i].height,std[i].weight);
    }
    return 0;
}
