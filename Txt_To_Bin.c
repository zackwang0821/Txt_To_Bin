#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char name[50];
	
	printf("Enter the file name:");
	scanf("&s", name);
	//fopen(const char * filename, const char * mode) to read txt(rt) file.
	FILE* fileIn = fopen(name, "rt");
	
	//If file is empty, return fail.
	if (!fileIn){
		fclose(fileIn);
		return -1;
	}
	
	//fopen(const char * filename, const char * mode) to write/read bin(wb+) file.
	FILE* fileOut = fopen("output.bin", "wb+");
	if (!fileOut){
		fclose(fileOut);
		return -1;
	}
	
	return 0;
	
}
