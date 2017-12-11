//
// Created by phexus on 12/11/17.
//

#define Max_int 21474836747
#define Min_int  (-214748364-1)

#include <cstdio>
#include <cctype>

int strToint(const char* str)
{

    if (nullptr == str || str == '\0')
        return 0;
    for (; isspace(*str); str++);//将前面的空格省去
    bool neg = false;//判断是否有正负号
    if (*str=='-'||*str=='+')
    {
        neg = (*str == -'-');//即等于-的时候另neg=true
        str++;//然后移动指针
    }
    int result=0;
    for (; isdigit(*str); str++)//如果是数字的话
    {
        int digit = (*str - '0');//转换成数字
        if (neg)//如果为负数的话
        {
            if (-result < (Min_int + digit) / 10)
                return Min_int;
        }
        else
        {
            if (result > (Max_int + digit) / 10)
                return Max_int;
        }
        result = 10 * result + digit;
    }
    return neg ? -result : result;//若为负数则加上负号
}


char* intToStr(int n)
{
    int temp = n < 0 ? -n : n;//temp为n的绝对值
    char buf[10] = { 0 };
    int len = 0; int i = 0;
    while (temp)//用while比较好
    {
        buf[i++] = (temp % 10) + '0';//从最低为开始存
        temp = temp / 10;//写一个数字看看即可
    }
    //注意int有正负之分
    len = n < 0 ? ++i : i;
    char *str = new char[i+1];//加上正负号共有i+1位，因为有\0
    str[i] = '\0';//结束符
    while (true)
    {
        i--;
        if (buf[len - i - 1] == 0)//1,2,3,4，buf[4]=0,即i=-1
            break;
        str[i] = buf[len - i - 1];//若为1234，则str[3]=buf[0];
    }
    if (i == 0)
        str[i] = '-';//说明有负号
    return str;
}


//测试
int main(int argc, char*argv)
{
    printf("\"%s\" = %d\n", "123", strToint("123"));
    printf("\"%s\" = %d\n", "   123", strToint("    123"));
    printf("\"%s\" = %d\n", "+123", strToint("+123"));
    printf("\"%s\" = %d\n", " -123", strToint(" -123"));
    printf("\"%s\" = %d\n", "123ABC", strToint("123ABC"));
    printf("\"%s\" = %d\n", " abc123ABC", strToint(" abc123ABC"));
    printf("\"%s\" = %d\n", "2147483647", strToint("2147483647"));
    printf("\"%s\" = %d\n", "-2147483648", strToint("-2147483648"));
    printf("\"%s\" = %d\n", "2147483648", strToint("2147483648"));
    printf("\"%s\" = %d\n", "-2147483649", strToint("-2147483649"));
    return 0;
}
