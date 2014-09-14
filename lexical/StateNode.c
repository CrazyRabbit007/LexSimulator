#include"StateNode.h"

StatePtr NewStateNode(StateType type, char value){
	StatePtr newState = (StatePtr)malloc(sizeof(State));
	newState->type = type;
	newState->left_val = NULL;
	newState->right_val = NULL;
	newState->value = value;
	return newState;
}

StatePtr SetNodeDetail(StatePtr node, StatePtr leftNode, StatePtr rightNode){
	if (node == NULL){
		if (rightNode == NULL){	//ֱ������
			node = leftNode;
		}
		else{	//�ҽڵ������������Ҫ�ڵ㣬�����������Լ̳�����
			node = rightNode;
			node->left_val = leftNode;
		}
	}
	else{	//û�пռ�Ľڵ㣬������ݹ�ĸ����ã���Щ�ڵ��Ƴ��Ķ��Ƿ��ս��
		if (rightNode == NULL){
			node->right_val = leftNode;
		}
		else{	//�Ƴ��������ս�������ұߵ��ս��Ϊ��Ҫ
			rightNode->left_val = leftNode;
			node->right_val = rightNode;
		}
	}
	return node;
}