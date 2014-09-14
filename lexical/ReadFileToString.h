#include<stdio.h>
#include<stdlib.h>
#include"Defines.h"

//从文件读取到字符串，参数文件名，返回字符串
char* ReadFileToString(char* filename);

//展示已读取到的字符
void ShowFileString(char* fileString);