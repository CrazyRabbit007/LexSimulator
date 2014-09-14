#include"GetNextWord.h"

void GetNext(char* fileString, int* pos, char* nextWord){
	char* index = fileString + *pos;
	while (*index == ' ' || *index == '\n'){
		index++;
		(*pos)++;
	}
	while (*index != ' ' && *index != '\n'){
		if (*index==EOF){
			break;
		}
		*(nextWord++) = *(index++);
		(*pos)++;
	}
	*(nextWord) = EOF;
}

bool GetNextWord(char* fileString, int* pos, char* nextWord){
	if (*pos>MAXKEYWORDLEN){
		//no error, just return;
		return false;
	}
	GetNext(fileString, pos, nextWord);
	if (*nextWord == EOF){
		return false;
	}
	return true;
}