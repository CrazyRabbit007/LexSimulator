#include<stdio.h>
#include"Defines.h"

//获取下一个识别词，返回词素，参数文件字符串，识别定位点
bool GetNextWord(char* fileString, int* pos, char* nextWord);