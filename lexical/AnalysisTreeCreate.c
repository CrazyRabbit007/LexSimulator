#include"AnalysisTreeCreate.h"

StatePtr AUnTS();
StatePtr APlusUnTS();
StatePtr BUnTS();
StatePtr BPlusUnTS();
StatePtr CUnTS();
StatePtr CPlusUnTS();
StatePtr DUnTS();

char* inputIndex = NULL;

void RecognitionError(){
	printf("RecognitionError");
	exit(0);
}

//子节点为分析链表中的节点{}，得到其treeroot节点
bool GetAnalysisNode(AnalysisNodePtr AnalysisNodeBegin){
	char* analysisNodeName = (char*)malloc(sizeof(char)*MAXLEXDECLEN);
	char* analysisNodeNameIndex = analysisNodeName;
	AnalysisNodePtr analysisNodeIndex = AnalysisNodeBegin->next;
	while (*inputIndex != '}'){
		*analysisNodeNameIndex = (*inputIndex++);
		analysisNodeNameIndex++;
	}
	inputIndex++;
	*analysisNodeNameIndex = '\0';
	while (analysisNodeIndex!=NULL){
		if (StringCmp(analysisNodeName, analysisNodeIndex->nodeName) == false){
			analysisNodeIndex = analysisNodeIndex->next;
		}
		else{
			return analysisNodeIndex->treeRoot;
		}
	}
	printf("no AnalysisNode in list\n");
	RecognitionError();
}

StatePtr AnalysisTreeCreate(char* lexicalDef){
	inputIndex = lexicalDef;
	if (*inputIndex != '\0'){
		return AUnTS();
	}
	return NULL;
}

//返回最简化的分析树；
StatePtr AUnTS(){
	StatePtr AState = NULL;
	StatePtr ALeftState;
	StatePtr ARightState;
	if (IsLetter(*inputIndex) || *inputIndex == '(' || *inputIndex == '{'){
		ALeftState = BUnTS();
		ARightState = APlusUnTS();
		AState = SetNodeDetail(AState, ALeftState, ARightState);
		return AState;
	}
	else{
		RecognitionError();
	}
}

StatePtr APlusUnTS(){
	StatePtr APState = NULL;
	StatePtr APLeftState;
	StatePtr APRightState;
	if (*inputIndex == '|'){
		APState = NewStateNode(State_OR, *inputIndex);
		printf("recognition | \n");
		inputIndex++;
		APLeftState = BUnTS();
		APRightState = APlusUnTS();
		APState = SetNodeDetail(APState, APLeftState, APRightState);
		return APState;
	}
	else if (*inputIndex == ')' || *inputIndex == '$'){
		//识别空
		return NULL;
	}
	else{
		RecognitionError();
	}
}

StatePtr BUnTS(){
	StatePtr BState = NULL;
	StatePtr BLeftState;
	StatePtr BRightState;
	if (IsLetter(*inputIndex) || *inputIndex == '(' || *inputIndex == '{'){
		BLeftState = CUnTS();
		BRightState = BPlusUnTS();
		BState = SetNodeDetail(BState, BLeftState, BRightState);
		return BState;
	}
	else{
		RecognitionError();
	}
}

StatePtr BPlusUnTS(){
	StatePtr BPState = NULL;
	StatePtr BPLeftState;
	StatePtr BPRightState;
	if (IsLetter(*inputIndex) || *inputIndex == '(' || *inputIndex == '{'){
		BPState = NewStateNode(State_AND, '.');
		printf("recognition . \n");
		BPLeftState = CUnTS();
		BPRightState = BPlusUnTS();
		BPState = SetNodeDetail(BPState, BPLeftState, BPRightState);
		return BPState;
	}
	else if (*inputIndex == '|' || *inputIndex == ')' || *inputIndex == '$'){
		//识别空
		return NULL;
	}
	else{
		RecognitionError();
	}
}

StatePtr CUnTS(){
	StatePtr CState = NULL;
	StatePtr CLeftState;
	StatePtr CRightState;
	if (IsLetter(*inputIndex) || *inputIndex == '(' || *inputIndex == '{'){
		CLeftState = DUnTS();
		CRightState = CPlusUnTS();
		CState = SetNodeDetail(CState, CLeftState, CRightState);
		return CState;
	}
	else{
		RecognitionError();
	}
}

StatePtr CPlusUnTS(){
	StatePtr CState = NULL;
	if (*inputIndex == '*'){
		CState = NewStateNode(State_ASTER, *inputIndex);
		printf("recognition * \n");
		inputIndex++;
		return CState;
	}
	else if (IsLetter(*inputIndex) || *inputIndex == '|' || *inputIndex == '(' || *inputIndex == ')' || *inputIndex == '$' || *inputIndex == '{'){
		//识别空
		return NULL;
	}
	else{
		RecognitionError();
	}
}

StatePtr DUnTS(){
	StatePtr DState = NULL;
	if (IsLetter(*inputIndex)){
		DState = NewStateNode(State_ID, *inputIndex);
		printf("recognition %c \n", *inputIndex);
		inputIndex++;
		return DState;
	}
	else if (*inputIndex == '('){
		printf("recognition ( \n");
		inputIndex++;
		DState = AUnTS();
		if (*inputIndex == ')'){
			printf("recognition ) \n");
			inputIndex++;
		}
		else{
			RecognitionError();
		}
		return DState;
	}
	else if (*inputIndex == '{'){
		inputIndex++;
		GetAnalysisNode(AnalysisNodeBegin);
	}
	else{
		RecognitionError();
	}
}