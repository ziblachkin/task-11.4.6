#include <stdio.h>
#include <stdilib.h>
#include <string.h>
//#

typedef struct{
	
	// [] or 2;
	
}LOWL;

char lowl_save(LOWL *list, char *filename){

	FILE *file = fopen(filename,"wb");

	if(file == 0){
		return LOWL_FILE_PROBLEM;
	}
	
	//LOWL_FILE_OK 

	//LOWL* lowl_load(char *filename);
	
}



