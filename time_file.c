#include <stdio.h>
#include <time.h>

#define LOG_FILE "log.txt"  //記録ファイル名

//現在時刻をファイルに書き込む
void write_time(struct tm *now){
    FILE *fp;

    // 書き込みモードでオープン
    if((fp=fopen(LOG_FILE,"w"))==NULL){
        printf("\aファイルをオープンできません。\n");
        return;
    }

    //日時をファイルに書き込む
    fprintf(fp, "%d %d %d %d %d %d\n",
        now->tm_year + 1900,  // 年（-1900されているため+1900）
        now->tm_mon  + 1,     // 月（0始まりのため+1）
        now->tm_mday,         // 日
        now->tm_hour,         // 時
        now->tm_min,          // 分
        now->tm_sec           // 秒
    );

    fclose(fp); //クローズ
    printf("現在の日時をファイルに保存しました。\n");
}

//ファイルから前回の日時を読み込んで表示する
void read_time(void){
    FILE *fp;
    int year,mon,day,hour,min,sec;

    //読み取りモードでオープン
    if((fp=fopen(LOG_FILE,"r"))==NULL){
        printf("前回の記録がありません。（初回起動）\n");
        return;
    }

    //ファイルから日時を読み込む
    if(fscanf(fp,"%d %d %d %d %d %d",&year,&mon,&day,&hour,&min,&sec)==6){
        printf("前回の起動日時：%d年%d月%d日 %02d時%02d分%02d秒\n",year,mon,day,hour,min,sec);
    }else{
        printf("ファイルの読み込みに失敗しました。\n");
    }

    fclose(fp); //クローズ
}

//現在時刻を画面に表示する
void print_current_time(struct tm *now){

    printf("現在の日時：%d年%d月%d日 %02d時%02d分%02d秒\n",
        now->tm_year + 1900,
        now->tm_mon  + 1,
        now->tm_mday,
        now->tm_hour,
        now->tm_min,
        now->tm_sec
    );
}

int main(void){
    time_t t=time(NULL);          //現在時刻を取得
    struct tm *now=localtime(&t); //ローカル時間に変換


    printf("=== 起動ログプログラム ===\n\n");

    //前回の起動日時を読み込んで表示
    read_time();

    //現在時刻を表示
    print_current_time(now);

    //現在時刻をファイルに保存
    write_time(now);

    return 0;
}
