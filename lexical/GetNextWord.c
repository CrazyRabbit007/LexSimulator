#include"GetNextWord.h"

void GetNext(char* fileString, int* pos, char* nextWord){
	char* index = fileString + *pos;
	while (*index == ' ' || *index == '\n'){
		index++;
		(*pos)++;
	}
	while (*index != ' ' && *index != '\n'){
		if (*index=='\0'){
			break;
		}
		*(nextWord++) = *(index++);
		(*pos)++;
	}
	*(nextWord) = '\0';
}

bool GetNextWord(char* fileString, int* pos, char* nextWord){
	if (*pos>MAXKEYWORDLEN){
		//no error, just return;
		return false;
	}
	GetNext(fileString, pos, nextWord);
	if (*nextWord == '\0'){
		return false;
	}
	return true;
}