#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOWL_FILE_PROBLEM 1
#define LOWL_FILE_OK 0
#define LOWL_FILE_FAIL 1//needed fail
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
		return 0;
	}
	
	list->beg = 0;
	list->cur = 0;
	
	return list;
}

OWN *lowl_insert_left(LOWL* list, float val){
	
	OWN *tmp = list->beg
	OWN *linked_list = malloc(sizeof(OWN));
	
	if(linked_list == 0){
		return 0;// pointer return a fail
	}
	
	if(list == 0){
		return 0;// pointer return a fail
	}
	
	linked_list->data = val;
	
	if(list->beg == 0){
		list->beg = linked_list;
		list->cur = linked_list;
		return linked_list;
	}
	
	if(list->cur == 0){
		list->beg = linked_list;
		list->cur = linked_list;
		return linked_list;
	}
	
	while(tmp->next != list->cur){
		tmp = tmp->next;
	}
	
	if(tmp == 0){
		free(linked_list);//after that probl cuz 4 now it's 0
		return 0;
	}
	
	tmp->next = linked_list;
	linked_list->next = list->cur;//linked l smth, up ans
	list->cur = linked_list;
	
	return linked_list;
	
}

OWN *lowl_insert_right(LOWL* list, float val){
	
	OWN *linked_list = malloc(sizeof(OWN));
	
	linked_list->data = val;
	
	if(linked_list == 0){
		return 0;
	}
	
	if(list == 0){
		return 0;
	}
	
	if(list->beg == 0){
		list->beg = linked_list;
		list->cur = linked_list;
		
		return linked_list;
	}
	
	if(list->cur == 0){
		free(linked_list);
		return 0;
	
	}
	
	linked_list->next = list->cur->next;
	
	list->cur->next = linked_list;
	list->cur = linked_list;
	
	return linked_list;
	
}

LOWL *lowl_create_random(unsigned int size){//make it write in, prob w insert//if free right
	
	LOWL *list = lowl_create_empty();
	
	float val = 0;
	int i = 0;
	
	if(list == 0){//uns
		return LOWL_FILE_PROBLEM;
	}
	//srand in main
	
	for(i = 0; i<size; i++){
		val = (float)(rand() % 2000) / 10.0 - 100.0;
		if(lowl_insert_right(list, val) == 0){
			free(list);
			return 0;
		}
	}
	
	return list;
	
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




void lowl_destroy(LOWL *list){
	
	OWN *tmp = list->beg;
	
	if(list == 0){
		return 0;
	}
	
	while(tmp != 0){
		OWN *next = tmp->next;
		free(tmp);
		tmp = next;
	}
	
	free(list);
	
}

void lowl_print(LOWL *list){
	
	OWN *tmp = list->beg;
	
	if(list == 0){
		return 0;
	}
	
	while(tmp != 0){
		printf("%.2f \n", tmp->data);
		tmp = tmp->next;
	}
	
}

char lowl_delete(LOWL* list){
	
	OWN *delete_data = list->cur;
	
	if(list == 0){
		return 0;
	}
	
	if(list->cur == list->beg){
		list->beg = list->cur->next;
		free()
	}
	
}

char lowl_save(LOWL *list, char *filename){
	
	const char *check_the_lowl = "LOWL";
	int count = 0;
	
	OWN *tmp = list->beg;
	FILE *file = fopen("list.check","wb");
	
	if(file == 0){
		return LOWL_FILE_PROBLEM;
	}
	
	if(fwrite(check_the_lowl, sizeof(char), 4, file) != 4){//L O W L
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}
	
	if(tmp != 0){
		while(tmp != list->cur){
			count++;
			tmp = tmp->next;
		}
	}
	
	if(fwrite(&count, sizeof(int), 1, file) != 1){//check posledovatelnost: L O W L, int/count(1), then elements
		fclose(file);
		return LOWL_FILE_PROBLEM;
	}	
	
	tmp = list->beg;
	
	while(tmp != 0){
		if(fwrite(tmp->data, sizeof(float), 1, file) != 1){
			fclose(file);
			return LOWL_FILE_PROBLEM;
		}
		tmp = tmp->next;
	}
	
	fclose(file);
	return LOWL_FILE_OK;
	
}

LOWL* lowl_load(char *filename){
	
}

int main(){
	
	
	srand(time(NULL));
	
	
}