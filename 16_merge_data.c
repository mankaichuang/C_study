/*
*   数据表记录包含索引和数值（int范围的正整数），请对表索引相同的记录进行合并
*   即将相同索引的数值进行求和运算，输出按照key值升序进行输出；
*/

//hash表法
#include <stdio.h>

int main(void)
{
    int key_value[1000] = {0};
    int key,value;
    int i;
    int num;
    scanf("%d",&num);
    for(i = 0; i < num; i++){
        scanf("%d%d", &key, &value);
        key_value[key] += value; 
    }
    for(i=0; i<1000; i++){
        if(key_value[i] > 0){
            printf("%d %d\n", i, key_value[i]);
        }
    }
}

//结构体指针法，机考提示有可能造成栈溢出，数组越界，外部测试OK
// #include <stdio.h>

// struct data{
//     int key;
//     int value;
// };
// int main(void)
// {
//     struct data *p;
//     int num;                //输入的数据总数
//     int i,j;
//     int count=0;            //key值的总数，相同的key值合并
//     int tempvalue,tempkey;  //临时存放输入key和value
//     int flag = 0;           //key值重复标志
//     scanf("%d", &num);
//     for(i = 0; i< num; i++){
//         if(i > 0){
//             scanf("%d%d", &p->key, &p->value);
//             tempvalue = p->value;
//             tempkey = p->key;
//             p = p - i;                      //将P指向初始位置，用于遍历 
//             for(j = 0; j < i; j++){
//                 if(p->key == tempkey){      //如果key值重复
//                     p->value += tempvalue;  //进行value合并
//                     flag = 1;               //标志置1
//                 }
//                 p++;
//             }
//             if(!flag){                      //如果标志为0，说明是新key，
//                 p++;                        //指针偏移
//                 count++;                    //计数器加1
//             }else{
//                 flag = 0;                   //清零标志，不进行地址加1
//             }
//         }else{                              //第一次输入，直接保存，地址加1
//             scanf("%d%d", &p->key, &p->value); 
//             p++;
//             count++;
//         }
//         getchar();                          //清回车
//     }
//     p = p - count;                          //p指向初始位置
//     if(count > 1){
//         for(i = 0; i<count-1; i++){               //冒泡排序
//             for(j = 0; j<count-1-i; j++){
//                 if((p+j)->key > (p+j+1)->key){
//                     tempkey = (p+j)->key;
//                     tempvalue = (p+j)->value;
//                     (p+j)->key = (p+j+1)->key;
//                     (p+j)->value = (p+j+1)->value;
//                     (p+j+1)->key = tempkey;
//                     (p+j+1)->value = tempvalue;
//                 }
//             }
//         }
//     }
//     for(i = 0; i<count; i++){
//         printf("%d %d\n",p->key, p->value);
//         p++;
//     }
//     return 0;
// }

// /*
// *   数据表记录包含索引和数值（int范围的正整数），请对表索引相同的记录进行合并
// *   即将相同索引的数值进行求和运算，输出按照key值升序进行输出；
// */

// #include <stdio.h>

// struct data{
//     int key;
//     int value;
// };
// int main(void)
// {
//     struct data *p;
//     int num;                //输入的数据总数
//     int i,j;
//     int cnt = 0;            //key值的总数，相同的key值合并
//     int tempvalue,tempkey;  //临时存放输入key和value
//     scanf("%d", &num);
//     for(i = 0; i< num; i++){
//         scanf("%d%d", &(p+i)->key, &(p+i)->value);
//         getchar();                          //清回车
//     }
//     if(num > 1){
//         for(i = 0; i<num-1; i++){               //冒泡排序
//             for(j = 0; j<num-1-i; j++){
//                 if((p+j)->key > (p+j+1)->key){
//                     tempkey = (p+j)->key;
//                     tempvalue = (p+j)->value;
//                     (p+j)->key = (p+j+1)->key;
//                     (p+j)->value = (p+j+1)->value;
//                     (p+j+1)->key = tempkey;
//                     (p+j+1)->value = tempvalue;
//                 }
//             }
//         }
//         for(i = 1; i<num; i++){        //去重
//             if((p+cnt)->key != (p+i)->key){
//                 cnt++;
//                 (p+cnt)->key = (p+i)->key;
//                 (p+cnt)->value = (p+i)->value;
//             }else{
//                 (p+cnt)->value += (p+i)->value;
//             }
//         }
//         cnt++;
//     }else{
//         cnt = num;
//     }
//     for(i = 0; i<cnt; i++){
//         printf("%d %d\n",p->key, p->value);
//         p++;
//     }
//     return 0;
// }