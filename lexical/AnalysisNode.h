#include<stdio.h>
#ifndef StateNode
#define StateNode
#include"StateNode.h"
#endif

//分析树的节点，treeName定义的词法声明，treeRootNode生成的一颗分析树，next下一个低级别词法树
typedef struct analysisNode{
	char* nodeName;
	StatePtr treeRoot;
	struct analysisNode* next;
}AnalysisNode, *AnalysisNodePtr;

