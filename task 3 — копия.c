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
	
	FILE *file = fopen("list.check","wb");

	if(file == 0){
		return LOWL_FILE_PROBLEM;
	}
	
	while(tmp != 0){//list->current_element
		count ++;
		tmp = tmp->next;
	}
	
	if(fwrite(check_the_lowl, sizeof(char), 4, file) != 4){//L O W L
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	if(fwrite(&count, sizeof(int), 1, file) != 1){//check posledovatelnost: L O W L, int/count(1), then elements
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	tmp = list->first_element;
	while(tmp != 0){
		if(fwrite(&tmp->element,sizeof(float),1,file) != 1){//incompatible type of arg?? ok now
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
	int count = 0;
	char check_the_lowl_2[5] = {0};
	OWN *previous_element = 0; 
	LOWL *list = malloc(sizeof(LOWL));
	OWN *tmp = list->first_element;
	
	
	//list->first_element = malloc(sizeof(OWN));
	//list->current_element = malloc(sizeof(OWN));//
	
	FILE *file = fopen("list.check", "rb");
	
	if(file == 0){
		printf("here 1");
		fclose(file);
		return NULL;
	}
	
	if(fread(&check_the_lowl_2, sizeof(char), 4, file) != 4){//4 chars and writing it to ctl 2
		printf("here 2");
		fclose(file);
		return NULL;
	}
	
	if(strcmp(check_the_lowl_2, "LOWL") != 0){//check same name
		printf("here 3");
		fclose(file);
		return NULL;
	}
	
	if(list == 0){
		printf("here 3");
		fclose(file);
		return NULL;
	}
	
	
	if(list->first_element == 0){
		printf("here 4");
		free(list);
		fclose(file);
		return NULL;
	}
	
	printf("col 111 is going good\n");
	
	list->first_element = malloc(sizeof(OWN));
	
	while(fread(&tmp->element,sizeof(float),1,file) == 1){
		tmp->next = malloc(sizeof(OWN));
		if(tmp->next == previous_element){
			tmp = list->first_element;
			while(tmp != 0){
				tmp = tmp->next;
				free(tmp);
			}
			free(list);
		}
	}
	
	printf("col 128 going good\n");
	
	for(i = 0; i < count; i++){
		list->current_element = list->current_element->next;
	}
	
	printf("lowl_load b4 free and close went good\n");
	
	printf("after free is ok\n");
	
	fclose(file);
	printf("after close is ok\n");
	fflush(stdout);
		
	return list;
}

int main(){
	
	int count_2 = 0;
	LOWL *list = malloc(sizeof(LOWL));
 	
	if(list == 0){
 		return 1;
	}
	
	OWN *element_1 = malloc(sizeof(OWN));
	OWN *element_2 = malloc(sizeof(OWN));
	OWN *element_3 = malloc(sizeof(OWN));
 
 	element_1->element = 52.24;
 	element_2->element = 1.4;
 	element_3->element = 4.2;
 	
 	element_1->next = element_2;
 	element_2->next = element_3;
 	element_3->next = 0;
 	
 	
 	list->first_element = element_1;
 	list->current_element = element_3; 
 	
 	printf("b4 saving\n");
 	
 	if(lowl_save(list, "list.check") != 0){//here problem
 		return 1;
	}
 	
 	printf("had been saved\n");
 	
 	printf("going to load\n");
 	
 	LOWL *list_load = lowl_load("list.check");
    if(list_load == 0){
        return 1;
        printf("ERROR with loading");
    }
    
    printf("had been loaded");
    
//    if(&list_load == 0){// also don't write
//        return 1;
//        printf("ERROR with loading");
//    }
 	
 	OWN *tmp = list_load->first_element;
    while (tmp != NULL) {
    	count_2++;
        printf("element %d: %.2f\n",count_2, tmp->element);
        tmp = tmp->next;
    }
 	
}
// last time it showed 佌䱗 䉐㌳㾳晦䂆