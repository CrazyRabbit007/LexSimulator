#include<stdio.h>
#include<stdlib.h>
#include"Defines.h"
#ifndef AnalysisNodeh
#define AnalysisNodeh
#include"AnalysisNode.h"
#endif
#include"AnalysisTreeCreate.h"
#include"StringMethod.h"

//分析节点的构建，参数词法文件字符串
AnalysisNodePtr AnalysisListCreate(char* lexString);

//词法文件字符串的分割，参数词法文件字符串，当前识别点，词法声明，词法定义
bool LexStringSplit(char* lexString, int* pos, char* lexicalDeclare, char* lexicalDef);

//遍历分析树链表，先序
void ShowListDetail();