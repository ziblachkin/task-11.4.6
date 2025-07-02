#include <stdio.h>
#include <stdilib.h>
#include <string.h>

typedef struct OWN{
	
	float element;
	struct OWN *next;
	
}OWN;//step by step 

typedef struct{
	
	OWN *first_element;
	OWN *current_element;
	
}LOWL;

char lowl_save(LOWL *list, char *filename){

	FILE *file = fopen(filename,"wb");

	if(file == 0){
		return LOWL_FILE_PROBLEM;
	}
	
	//LOWL_FILE_OK 

	//LOWL* lowl_load(char *filename);
	
}



