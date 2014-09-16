#include"ContentAnalysis.h"

int stackHead = 0;
StatePtr stack[100] = { NULL };

//�������ڵ����������־������*��|���ŵĻع�
int stateNodeErr = 0;
//������*�ڲ������ᱨ���ɻع�
int isInASTER = 0;
//��������ڵ�����־����Ҫָ����һ�ŷ�����
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

//ʶ��������봮���﷨���Ѿ����ɣ��ݹ�ʶ�𼴿�
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
			//*�з������󣬻ع�
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
				//*�з������󣬻ع�
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
		return oldRec;	//�ع�
	}
	else{
		printf("error");
		exit(0);
	}
}