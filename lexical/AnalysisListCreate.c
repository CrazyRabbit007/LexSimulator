#include"AnalysisListCreate.h"

/*数据结构：链表，含头节点，每个节点为AnalysisNode，其中treeroot为一颗分析树，分析一类词法元素*/
AnalysisNodePtr AnalysisListCreate(char* lexString){
	char* lexicalDeclare = (char*)malloc(sizeof(char)*MAXLEXDECLEN);
	char* lexicalDef = (char*)malloc(sizeof(char)*MAXLEXDEFLEN);
	int lexicalDeclareLen = 0;
	int pos = 0;
	AnalysisNodePtr newAnalysisTree;
	AnalysisNodeBegin = (AnalysisNodePtr)malloc(sizeof(AnalysisNode));
	AnalysisNodeBegin->next = NULL;
	AnalysisNodeBegin->treeRoot = NULL;
	AnalysisNodeBegin->nodeName = "begin";
	while (LexStringSplit(lexString,&pos,lexicalDeclare,lexicalDef)==true){
		newAnalysisTree = (AnalysisNodePtr)malloc(sizeof(AnalysisNode));

		lexicalDeclareLen = StringLen(lexicalDeclare);
		newAnalysisTree->nodeName = (char*)malloc(sizeof(char)*lexicalDeclareLen);
		StringCopy(newAnalysisTree->nodeName, lexicalDeclare);

		newAnalysisTree->treeRoot = AnalysisTreeCreate(lexicalDef);

		//头插法，复杂分析树放在前，识别时从复杂部分开始；
		newAnalysisTree->next = AnalysisNodeBegin->next;
		AnalysisNodeBegin->next = newAnalysisTree;
	}
	return AnalysisNodeBegin;
}

bool LexStringSplit(char* lexString, int* pos, char* lexicalDeclare, char* lexicalDef){
	char* index = lexString + *pos;
	if (*index == '\0'){
		return false;
	}
	while (*index == ' '){
		index++;
		(*pos)++;
	}
	while (*index != ':'){
		*lexicalDeclare = *index;
		lexicalDeclare++;
		index++;
		(*pos)++;
	}
	*lexicalDeclare = '\0';
	index++;
	(*pos)++;
	while (*index == ' '){
		index++;
		(*pos)++;
	}
	while (*index!='\n'&&*index!='\0'){
		*lexicalDef = *index;
		lexicalDef++;
		index++;
		(*pos)++;
	}
	*lexicalDef = '\0';
	if (*index == '\0'){
		return true;
	}
	while (*index == ' '){
		index++;
		(*pos)++;
	}
	if (*index == '\n'){
		(*pos)++;
		return true;
	}
	return false;
}

//先序遍历分析树
void ShowTreeDetail(StatePtr analysisTreeIndex){
	if (analysisTreeIndex == NULL){
		return;
	}
	else{
		printf("%c ",analysisTreeIndex->value);
		ShowTreeDetail(analysisTreeIndex->left_val);
		ShowTreeDetail(analysisTreeIndex->right_val);
	}
}

void ShowListDetail(){
	AnalysisNodePtr analysisListIndex = AnalysisNodeBegin->next;
	while (analysisListIndex!=NULL){
		printf("%s:",analysisListIndex->nodeName);
		StatePtr analysisTreeIndex = analysisListIndex->treeRoot;
		ShowTreeDetail(analysisTreeIndex);
		printf("\n");
		analysisListIndex = analysisListIndex->next;
	}
}

