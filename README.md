# C_study

C语言每日一练。

1、将指定字符串中的*去掉，如果字符串头有*，要保留，有几个保留几个；
    例：源字符串为****abAb*CDEF*ff*****，输出为：****abAbCDEFff。
    该题考查：1、字符串指针的遍历；2、从字符串中删除某一字符；3、gets的应用。
    文件名为：1_del_char.c

2、输入一段字符串，输出该字符串中a-z中所有小写字母的个数；
    所有字母的个数保存在一个数组中，函数返回数组有两种方法：
    第一、通过指针返回，即函数的返回值为数组的首地址，当调用函数时，进行遍历，
    获取数组所有成员；
    第二、通过函数参数，将要保存的数组以参数方式传递进去；

3、输入一个数字，获取小于等于该数字的所有质数或者合数
    第一、将输入的字符串转换成数字，使用atoi函数，头文件stdlib.h；
    第二、计算质数和合数的方法:
    if(i % j == 0){
        break;
    }
    break之后，如果j < i,那么就是合数，因为没有增加到i，就整除了
    如果 j = i或者 i = 2 ，那么就是质数，因为一直也没有整除。

4、从指定字符串数组中查找给定的字符串，如果找到返回其索引，如果没有找到返回-1
    考查的要点：
    第一、字符串比较函数strcmp；
    第二、字符串数组的遍历，实际上就是获取字符串数组的长度。

5、sizeof使用过程中的两个要点：
    第一、对结构体进行sizeof，跟字节对齐有关；
    第二、数组传参之后，sizeof的问题。

6、get_maxdata.c,添加一个程序，测试公司电脑ssh设置
    获取一组数据中最大的数据（最大数据不唯一）

7、7_array_pointer.c指针数组和数组指针的练习

8、8_del_equal_value.c,将整型数组中数值相等的元素只保留一个，其他的删除，
    返回新数组的长度

9、9_hw_last_string.c,华为C语言题，计算字符串最后一个单词的长度，单词以空格隔开。

10、10_hw_get_char_num.c华为C语言题，计算某字母出现的次数

11、11_hw_sort_removal.c华为C语言题，明明的随机数

12、12_hw_string_cut.c 华为C语言题，字符串分割

13、13_inhex_outd.c 华为C语言题，进制转换

14、14_primefacter.c 华为C语言题，质数因子