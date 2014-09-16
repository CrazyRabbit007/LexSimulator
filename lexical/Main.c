#include<stdio.h>
#include<stdlib.h>
#include"Defines.h"
#include"ReadFileToString.h"
#include"GetNextWord.h"
#include"AnalysisListCreate.h"
#include"ContentAnalysis.h"

void main(){
	char *progFileName = PROGRAMFILENAME;
	char *lexFileName = LEXFILENAME;
	char *progFileString;
	char *lexString;
	int pos = 0;
	char* nextWord = (char*)malloc(sizeof(char)*MAXKEYWORDLEN);
	char* propertyName = (char*)malloc(sizeof(char)*MAXPROPNAMELEN);
	char* propertyValue = (char*)malloc(sizeof(char)*MAXPROPVALUELEN);
	
	progFileString = ReadFileToString(progFileName);
	ShowFileString(progFileString);

	lexString = ReadFileToString(lexFileName);
	ShowFileString(lexString);

	AnalysisListCreate(lexString);
	ShowListDetail();
	
	while (GetNextWord(progFileString, &pos, nextWord) == true){
		ContentAnalysis(AnalysisNodeBegin, nextWord, propertyName, propertyValue);
		printf("%s:",propertyName);
		printf(propertyValue);
		printf("\n");
	}
	getchar();
}