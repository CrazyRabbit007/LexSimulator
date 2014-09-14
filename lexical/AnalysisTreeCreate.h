#include<stdio.h>
#include<stdlib.h>
#ifndef StateNode
#define StateNode
#include"StateNode.h"
#endif
#ifndef AnalysisNodeh
#define AnalysisNodeh
#include"AnalysisNode.h"
#endif
#include"Defines.h"
#include"StringMethod.h"

//分析树链表头
AnalysisNodePtr AnalysisNodeBegin;

//根据词法单元的定义构造词法分析树；
StatePtr AnalysisTreeCreate(char* lexicalDef);