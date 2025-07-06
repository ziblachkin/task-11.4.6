#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOWL_FILE_PROBLEM 1
#define LOWL_FILE_OK 0


typedef struct OWN{
	float data;
	struct OWN *next;
}OWN;

typedef struct{
	OWN *beg;
	OWN *cur;
}LOWL;





LOWL *lowl_create_empty(void);

LOWL *lowl_create_random(unsigned int size);

void lowl_destroy(LOWL *list);

void lowl_print(LOWL *list);

char lowl_cur_step_left(LOWL *list);

char lowl_cur_step_right(LOWL *list);


OWN *lowl_insert_left(LOWL* list, float val);

OWN *lowl_insert_right(LOWL* list, float val);


char lowl_delete(LOWL* list)

LOWL_OK
LOWL_FAIL
