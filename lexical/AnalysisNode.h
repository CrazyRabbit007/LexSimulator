#include<stdio.h>
#ifndef StateNode
#define StateNode
#include"StateNode.h"
#endif

//�������Ľڵ㣬treeName����Ĵʷ�������treeRootNode���ɵ�һ�ŷ�������next��һ���ͼ���ʷ���
typedef struct analysisNode{
	char* nodeName;
	StatePtr treeRoot;
	struct analysisNode* next;
}AnalysisNode, *AnalysisNodePtr;

