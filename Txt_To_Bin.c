#include<stdio.h>
#include<stdlib.h>
#include<string.h>
size_t readTxt(FILE *in, unsigned char *end, FILE *out){
	int n;
	size_t count = 0;
	unsigned char oneByte;

	if (end == NULL){
		//Read the file and transfer into hex unitl the end.
		while ((n = fscanf(in, "%hhx", &oneByte))){
			fwrite(&oneByte, sizeof(unsigned char), 1, out);
          	count++;
		}		
	}

	return count;
}
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
	
	//Call readTxt function and transfer into binary.
	size_t n = readTxt(fileIn, NULL, fileOut);
	
	rewind(fileIn);
	fclose(fileIn);
	fclose(fileOut);
	
	return 0;
}


