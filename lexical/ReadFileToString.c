#include"ReadFileToString.h"

char* ReadFileToString(char* filename){
	FILE *fp;
	char *fileString;
	char *index;
	int fileLength;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("cant open file:%s", filename);
		exit(0);
	}
	fseek(fp, 0, SEEK_END);
	fileLength = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	fileString = (char*)malloc(sizeof(char)*fileLength);

	index = fileString;
	while (!feof(fp))
		*(index++) = fgetc(fp);
	*(index) = EOF;
	index = fileString;
	
	fclose(fp);
	return fileString;
}

void ShowFileString(char* fileString){
	char *index;
	index = fileString;
	while ((*index) != EOF)
	{
		printf("%c", *index);
		index++;
	}
	printf("\n");
}