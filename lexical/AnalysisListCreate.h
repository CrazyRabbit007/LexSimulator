#include<stdio.h>
#include<stdlib.h>
#include"Defines.h"
#ifndef AnalysisNodeh
#define AnalysisNodeh
#include"AnalysisNode.h"
#endif
#include"AnalysisTreeCreate.h"
#include"StringMethod.h"

//�����ڵ�Ĺ����������ʷ��ļ��ַ���
AnalysisNodePtr AnalysisListCreate(char* lexString);

//�ʷ��ļ��ַ����ķָ�����ʷ��ļ��ַ�������ǰʶ��㣬�ʷ��������ʷ�����
bool LexStringSplit(char* lexString, int* pos, char* lexicalDeclare, char* lexicalDef);

//������������������
void ShowListDetail();