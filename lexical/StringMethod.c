#include"StringMethod.h"

bool StringCmp(char* str1, char* str2){
	while (*str1 != '\0'&&*str2 != '\0'){
		if (*str1 != *str2){
			return false;
		}
		str1++;
		str2++;
	}
	if (*str1 != '\0'&&*str2 != '\0'){
		return false;
	}
	return true;
}

int IsLetter(char value){
	if ((value >= '0'&&value <= '9') || (value >= 'A'&&value <= 'Z') || (value >= 'a'&&value <= 'z'))
		return 1;
	else
		return 0;
}

int StringLen(char* str){
	int count = 0;
	char* strIndex = str;
	while (*strIndex != '\0'){
		count++;
		strIndex++;
	}
	return count;
}

void StringCopy(char* strTo, char* strFrom){
	char* strToIndex = strTo;
	char* strFromIndex = strFrom;
	while (*strFromIndex != '\0'){
		*strToIndex = *strFromIndex;
		strToIndex++;
		strFromIndex++;
	}
	*strToIndex = '\0';
}