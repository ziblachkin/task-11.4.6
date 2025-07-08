#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOWL_FILE_PROBLEM 1
#define LOWL_FILE_OK 0
#define BOUNDARY_REACHED 1
#define LOWL_SUCCESS 0

//need load, posled 

typedef struct OWN{
	float data;
	struct OWN *next;
}OWN;

typedef struct{
	OWN *beg;
	OWN *cur;
}LOWL;





LOWL *lowl_create_empty(void){
	LOWL *list = malloc(sizeof(LOWL));
	
	if(list==0){//chanhe from adress to better check
		return LOWL_FILE_PROBLEM;
	}
	
	list->beg = 0;
	list->cur = 0;
	
	return list;
}


LOWL *lowl_create_random(unsigned int size){//make it write in, prob w insert
	
	LOWL *list = lowl_create_empty();
	
	int i = 0;
	
	if(list == 0){//uns
		return LOWL_FILE_PROBLEM;
	}
	//srand in main
	
	for(i = 0; i<size; i++){
		
	}
	
}

char lowl_save(LOWL *list, char *filename){
	
}

char lowl_cur_step_left(LOWL *list){
	OWN *tmp = list->beg;
	
	if(list == 0){
		return 	BOUNDARY_REACHED;//has put us then in dif. mb sw
	}
	
	while(tmp->next != list->cur){
		tmp = tmp->next;
	}
	
	if(tmp == 0){
		return 	BOUNDARY_REACHED;
	}
	list->cur = tmp;
	
	return LOWL_SUCCESS;
	
}

char lowl_cur_step_right(LOWL *list){
	
	if(list == 0){
		return 	BOUNDARY_REACHED;
	}
	
	list->cur = list->cur->next;
	
	return LOWL_SUCCESS;
	
}




void lowl_destroy(LOWL *list);

void lowl_print(LOWL *list);




OWN *lowl_insert_left(LOWL* list, float val);

OWN *lowl_insert_right(LOWL* list, float val);


char lowl_delete(LOWL* list)

LOWL_OK
LOWL_FAIL


int main(){
	
	
	srand(time(NULL));
	
	
}