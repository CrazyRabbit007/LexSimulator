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

//����������ͷ
AnalysisNodePtr AnalysisNodeBegin;

//���ݴʷ���Ԫ�Ķ��幹��ʷ���������
StatePtr AnalysisTreeCreate(char* lexicalDef);