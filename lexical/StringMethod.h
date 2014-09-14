#include<stdio.h>
#include"Defines.h"

//比较两个字符串是否相等
bool StringCmp(char* str1, char* str2);

//判断是否为数字或字母
int IsLetter(char value);

//获取字符串长度
int StringLen(char* str);

//字符串拷贝
void StringCopy(char* strTo, char* strFrom);