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
		if (rightNode == NULL){	//直接上移
			node = leftNode;
		}
		else{	//右节点是运算符等重要节点，计算数据来自继承属性
			node = rightNode;
			node->left_val = leftNode;
		}
	}
	else{	//没有空间的节点，消除左递归的副作用，有些节点推出的都是非终结符
		if (rightNode == NULL){
			node->right_val = leftNode;
		}
		else{	//推出两个非终结符，以右边的终结符为主要
			rightNode->left_val = leftNode;
			node->right_val = rightNode;
		}
	}
	return node;
}