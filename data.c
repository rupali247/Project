#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "data.h"
void init(list *l) {
	l->head = l->tail = NULL;
	l->length = 0;
}

void print(list *l) {
	node *p;
	p = l->head;
	printf("NAME			MIS			BRANCH\n");
	while(p != l->tail) {
		printf("%s			%d			%s\n ", p->d.name, p->d.MIS, p->d.branch);
		p = p->next;
	}
	if(p) {
		if(p->next == NULL)
		printf("%s			%d			%s", p->d.name, p->d.MIS, p->d.branch);
	}
}

void Add(list *l, char *name, int MIS, char *branch, int pos) {
	node *p, *tmp;
	int j;
	if(pos < 0 || pos > l->length)		
		return;
	tmp = (node *)malloc(sizeof(node));
	tmp->d.name = (char *)malloc(strlen(name) + 1);
	strcpy(tmp->d.name, name);
	tmp->d.branch = (char *)malloc(strlen(branch) + 1);
	strcpy(tmp->d.branch, branch);
	tmp->d.MIS = MIS;
	if(l->head == NULL) {
		l->head = l->tail = tmp;
		l->length = 1;
		tmp->next = tmp->prev = NULL;
		return;
	}
	p = l->head;
	for(j = 0; j < pos - 1; j++) {
		p = p->next;
	}
	if(pos == 0) {
		tmp->next = p;
		tmp->prev = NULL;
		p->prev = tmp;
		l->head = tmp;
		(l->length)++;
		return;
	}
	if(pos == l->length) {
		tmp->prev = p;
		tmp->next = NULL;
		p->next = tmp;
		l->tail = tmp;
		(l->length)++;
		return;
	}
	tmp->next = p->next;
	tmp->prev = p;
	p->next->prev = tmp;
	p->next = tmp;
	(l->length)++;
}

int length(list *l) {
	return l->length;
}

record *delet(list *l, int pos) {
	node *p, *tmp;
	record *retval;
	int j;
	if(pos < 0 || pos > l->length)		
		return;
	if(l->head == NULL) {
		l->length = 0;
		return;
	}
	p = l->head;
	for(j = 0; j < pos; j++) {
		p = p->next;
	}
	if(pos == 0) {
		/*if(l->length == 1)
		{
			retval->name = p->d.name;
			retval->MIS = p->d.MIS;
			retval->branch = p->d.branch;
			free(p);
			l->head = NULL;
			l->tail = NULL;
			(l->length)--;
			return retval;
		}*/
		p = p->next;
		p->prev = NULL;
		tmp = l->head;
		l->head = p;
		retval->name = tmp->d.name;
		retval->MIS = tmp->d.MIS;
		retval->branch = tmp->d.branch;
		free(tmp);
		(l->length)--;
		return retval;
	}
	if(pos == (l->length - 1)) {
		p = p->prev;
		p->next = NULL;
		tmp = l->tail;
		l->tail = p;
		retval->name = tmp->d.name;
		retval->MIS = tmp->d.MIS;
		retval->branch = tmp->d.branch;
		free(tmp);
		(l->length)--;		
		return retval;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	retval->name = p->d.name;
	retval->MIS = p->d.MIS;
	retval->branch = p->d.branch;
	free(p);
	(l->length)--;
	return retval;
}

void append(list *l, char *name, int MIS, char *branch) {
	node *p, *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->d.name = (char *)malloc(strlen(name) + 1);
	strcpy(tmp->d.name, name);
	tmp->d.branch = (char *)malloc(strlen(branch) + 1);
	strcpy(tmp->d.branch, branch);
	tmp->d.MIS = MIS;
	if(l->head == NULL) {
		l->head = l->tail = tmp;
		tmp->prev = tmp->next = NULL;
		l->length++;
		return;
	}
		p = l->tail;
		tmp->prev = p;
		tmp->next = NULL;
		p->next = tmp;
		l->tail = tmp;
		l->length++;
		return;
}
 
record *search(list *l, int MIS) {
	node *pp;
	record *ret;
	pp = l->head;
	while(pp != l->tail) {
		if(MIS == pp->d.MIS) {
			ret->MIS = pp->d.MIS;
			ret->name = pp->d.name;
			ret->branch = pp->d.branch;
			return ret;
		}
	pp = pp->next;
	}
	if(pp) {
		if(pp->next == NULL) {
			if(MIS == pp->d.MIS) {
				ret->MIS = pp->d.MIS;
				ret->name = pp->d.name;
				ret->branch = pp->d.branch;
				return ret;
			
			}
		}
 	}
}

void creatingID(list *l, int MIS) {
	node *pp;
	record *ret;
	pp = l->head;
	while(pp != l->tail) {
		if(MIS == pp->d.MIS) {
			printf(".................................................................................\n..");
			printf("........................IDENTITY CARD.........................\n");
			printf("..................COLLEGE OF ENGINEERING PUNE......................\n");
			printf("NAME : %s\n MIS : %d\n BRANCH : %s\n", pp->d.name, pp->d.MIS, pp->d.branch);
			printf("....................................................................................\n");
		}
	pp = pp->next;
	}
	if(pp) {
		if(pp->next == NULL) {
			if(MIS == pp->d.MIS) {
				printf("..................................................................................\n");
				printf(".....................IDENTITY CARD.....................\n");
				printf("................COLLEGE OF ENGINEERING PUNE...............\n");
				printf("NAME : %s\n MIS : %d\n BRANCH : %s\n", pp->d.name, pp->d.MIS, pp->d.branch);
				printf("..................................................................................\n");		
			}
		}	
 	}
}

/*void InsertFromFile(list *l, char *fname) {
	
}*/
