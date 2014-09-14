#include<stdio.h>

typedef enum stateType{
	State_ID = 256, State_AND = 257, State_OR = 258, State_ASTER = 259, State_BEGIN = 260
}StateType;

typedef struct state{
	StateType type;
	char value;
	struct state* left_val;
	struct state* right_val;
}State, *StatePtr;

//创建新状态节点
StatePtr NewStateNode(StateType type, char value);

//设置节点具体信息，上移或者重新构建
StatePtr SetNodeDetail(StatePtr node, StatePtr leftNode, StatePtr rightNode);