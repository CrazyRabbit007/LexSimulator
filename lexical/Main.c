#include<stdio.h>
#include<stdlib.h>
#include"Defines.h"
#include"ReadFileToString.h"
#include"GetNextWord.h"
#include"AnalysisListCreate.h"

void main(){
	char *progFileName = PROGRAMFILENAME;
	char *lexFileName = LEXFILENAME;
	char *progFileString;
	char *lexString;
	int pos = 0;
	char* nextWord = (char*)malloc(sizeof(char)*MAXKEYWORDLEN);
	char* nextWordIndex = nextWord;
	
	progFileString = ReadFileToString(progFileName);
	ShowFileString(progFileString);

	lexString = ReadFileToString(lexFileName);
	ShowFileString(lexString);

	AnalysisListCreate(lexString);
	ShowListDetail();
	
	while (GetNextWord(progFileString, &pos, nextWord) == true){
		//regular translate,out;
		nextWordIndex = nextWord;
		while (*nextWordIndex != EOF){
			printf("%c", *nextWordIndex);
			nextWordIndex++;
		}
		printf("\n");
	}
	getchar();
}