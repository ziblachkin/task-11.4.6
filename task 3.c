#include <stdio.h>
#include <stdlib.h>
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
	
	const char *check_the_lowl = "LOWL"; 
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
	
	if(fwrite(check_the_lowl, sizeof(char), 4, file) != 4){//L O W L
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	if(fwrite(count, sizeof(int), 1, file) != 1){//check posledovatelnost: L O W L, int/count(1), then elements
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	tmp = list->first_element;
	while(tmp != 0){
		if(fwrite(&tmp->element,sizeof(float),1,file) != 1){//incompatible type of arg?? 
			fclose(file);
			return LOWL_FILE_PROBLEM;
		}
		tmp = tmp->next;
	}
	
	fclose(file);
	return LOWL_FILE_OK; 
}



LOWL* lowl_load(char *filename){
	
	int i = 0;
	OWN *previous_element = 0;
	LOWL *list = malloc(sizeof(LOWL));
	OWN *tmp = list->first_element;
	char check_the_lowl_2[4];
	int count = 0;
	
	FILE *file = fopen(filename, "rb");
	
	if(file == 0){
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	if(fread(&check_the_lowl_2, sizeof(char), 4, file) != 4){//4 chars and writing it to ctl 2
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	if(strcmp(check_the_lowl_2, "LOWL") != 0){//check same name
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	if(list == 0){
		fclose(file);
		return LOWL_FILE_PROBLWM;
	}
	
	list->first_element = malloc(sizeof(OWN));//
	
	if(list->first_element == 0){
		free(list);
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	while(fread(&tmp->element,sizeof(float),1,file) == 1){
		tmp->next = malloc(sizeof(OWN));
		if(tmp->next == previous_element){
			tmp = list->first_element;
			while(tmp != 0){
				tmp = tmp->next;
				free(tmp);
			}
			free(list);
			fclose(file);
		}

	}
	
	
	for(i = 0; i < count; i++){
		list->current_element = list->current_element->next;
	}
	
	free(tmp);
	fclose(file);
	
	return list;
}

