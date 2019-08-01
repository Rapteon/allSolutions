/*Program to check whether a file `input.txt` exists in the current directory or in the `./docs` directory; AUTHOR: rapteon; DATE: 1st August 2019*/
/*Problem Link: https://rosettacode.org/wiki/Check_that_file_exists */
#include<stdio.h>
#include<unistd.h>

int main(){
	//fp1 file pointer is used to check if the file exists in the current directory.
	//fp2 ile pointer is used to check if the file exists in the `docs` directory.
	FILE *fp1, *fp2;
	//changeDirReturn variable is used to store the value returned by int chdir(const char*)
	//chdir() returns 0 on successfully changing directories and it returns 1 if directory change was unsuccessful.
	int changeDirReturn;
	fp1 = fopen("input.txt", "r");
	//If the file pointer has NULL value, it means that the file isn't in the current directory.
	if(fp1 == NULL){
		changeDirReturn = chdir("./docs");
		if(changeDirReturn == 1)
			printf("Couldn't access ./docs\n");
		else{
			fp2 = fopen("input.txt", "r");
			if(fp2 == NULL)
				printf("File does not exist\n");
			else
				printf("File found in ./docs\n");
		}
	}
	else
		printf("File found in current directory\n");
}
