#include"ContentAnalysis.h"

int stackHead = 0;
StatePtr stack[100] = { NULL };

//分析树节点遇到错误标志，用于*和|符号的回滚
int stateNodeErr = 0;
//表明在*内部，不会报错，可回滚
int isInASTER = 0;
//分析链表节点错误标志，需要指定下一颗分析树
int ListNodeErr = 0;

char* ContentRecognition(StatePtr state, char* input);

void ErrorValue(char errValue){
	printf("errorValue:%c", errValue);
	//exit(0);
}

bool ContentAnalysis(AnalysisNodePtr analysisListBegin, char* word, char* propertyName, char* propertyValue){
	AnalysisNodePtr analysisListIndex = analysisListBegin->next;
	char* lexResult = NULL;
	while (analysisListIndex != NULL){
		lexResult = ContentRecognition(analysisListIndex->treeRoot, word);
		if (ListNodeErr == 1){
			analysisListIndex = analysisListIndex->next;
			ListNodeErr = 0;
		}
		else{
			StringCopy(propertyName, analysisListIndex->nodeName);
			StringCopy(propertyValue, word);
			return true;
		}
	}
	return false;
}

//识别输入代码串，语法树已经生成，递归识别即可
char* ContentRecognition(StatePtr state, char* input){
	char* inputIndex = input;
	char* recString;
	char* oldRec;
	if (ListNodeErr == 1){
		return NULL;
	}
	else if (state->type == State_ID){
		if (*input == state->value){
			//printf("ContentRec:%c\n", *input);
			input++;
			return input;
		}
		else{
			stateNodeErr = 1;
			return NULL;
		}
	}
	else if (state->type == State_AND){
		recString = ContentRecognition(state->left_val, input);
		recString = ContentRecognition(state->right_val, recString);
		if (stateNodeErr == 1 && isInASTER == 0){
			printf("AND error");
			ListNodeErr = 1;
			stateNodeErr = 0;
			return NULL;
		}
		else if (stateNodeErr == 1 && isInASTER == 1){
			//*中发生错误，回滚
			stateNodeErr = 0;
			return input;
		}
		return recString;
	}
	else if (state->type == State_OR){
		recString = ContentRecognition(state->left_val, input);
		if (stateNodeErr == 1){
			stateNodeErr = 0;
			recString = ContentRecognition(state->right_val, input);
			if (stateNodeErr == 1 && isInASTER == 0){
				printf("OR error");
				ListNodeErr = 1;
				stateNodeErr = 0;
				return NULL;
			}
			else if (stateNodeErr == 1 && isInASTER == 1){
				//*中发生错误，回滚
				stateNodeErr = 0;
				return input;
			}
		}
		return recString;
	}
	else if (state->type == State_ASTER){
		isInASTER = 1;
		oldRec = input;
		for (; stateNodeErr == 0; oldRec = recString){
			if (*oldRec == '\0'){
				break;
			}
			recString = ContentRecognition(state->left_val, oldRec);
		}
		stateNodeErr = 0;
		isInASTER = 0;
		return oldRec;	//回滚
	}
	else{
		printf("error");
		exit(0);
	}
}