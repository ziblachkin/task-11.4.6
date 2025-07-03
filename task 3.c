#include <stdio.h>
#include <stdilib.h>
#include <string.h>
#define LOWL_FILE_PROBLEM 1
#define LOWL_FILE_OK 0

typedef struct OWN{
	
	float element;
	struct OWN *next;
	
}OWN;//step by step 

typedef struct{
	
	OWN *first_element;
	OWN *current_element;
	
}LOWL;

char lowl_save(LOWL *list, char *filename){

	int count = 0;
	OWN *tmp = list->first_element;
	
	FILE *file = fopen(filename,"wb");

	if(file == 0){
		return LOWL_FILE_PROBLEM;
	}
	
	while(tmp != list->current_element){
		count ++;
		tmp = tmp->next;
	}
	
	//LOWL_FILE_OK 

	//LOWL* lowl_load(char *filename);
	
}



