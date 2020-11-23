#include <stdio.h>

#define N   16

typedef struct{
    char num[10];
    int score;
}SCORE;

static int get_maxdata(SCORE *a, SCORE *b, int len)
{
    int i = 0; 
    int n = 0;
    int top_score;
    top_score = a[0].score;
    for(i=1; i<len; i++){             //遍历数组，找出最高的分数
        if(top_score < a[i].score){
            top_score = a[i].score;       
        }
    }

    printf("The top_score = %d\r\n", top_score);        //将最高分数打印

    for(i = 0; i<len; i++){           //遍历数组，将和最高分数相同的元素全部找出来
        if(top_score == a[i].score){
            b[n] = a[i];
            n++;
        }
    }
    return n;
}

void main(void)
{
    int i,n;
    SCORE r[N];
    SCORE s[N]={{"GA05",85},{"GA03",76},{"GA02",69},{"GA04",85},
                {"GA01",91},{"GA07",72},{"GA08",64},{"GA06",87},
                {"GA015",85},{"GA013",91},{"GA012",64},{"GA014",91},
                {"GA011",77},{"GA017",64},{"GA018",64},{"GA016",72}};


    n = get_maxdata(s, r, N);
    for(i = 0; i < n; i++)
        printf("%d: num:%s score:%d\r\n", i, r[i].num, r[i].score);
}