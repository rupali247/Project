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

void initt(listt *ll) {
	ll->headd = ll->taill = NULL;
	ll->lengthh = 0;
}

void print(list *l) {
	node *p;
	p = l->head;
	printf("NAME				MIS		BRANCH		YEAR\n");
	while(p != l->tail) {
		printf("%s		  %d		%s		%d\n ", p->d.name, p->d.MIS, p->d.branch, p->d.year);
		p = p->next;
	}
	if(p) {
		if(p->next == NULL)
		printf("%s		  %d		%s		%d\n", p->d.name, p->d.MIS, p->d.branch, p->d.year);
	}
}

void printt(listt *ll) {
	nnode *pp;
	pp = ll->headd;
	printf("MIS	SUB1	SUB2	SUB3	SUB4	TOTAl\n");
	while(pp != ll->taill) {
		printf("%d	%d	%d	%d	%d	%d\n ",pp->v.MIS,pp->v.sub1,pp->v.sub2,pp->v.sub3,pp->v.sub4,pp->v.total);
		pp = pp->nnext;
	}
	if(pp) {
		if(pp->nnext == NULL)
		printf("%d	%d	%d	%d	%d	%d\n ",pp->v.MIS,pp->v.sub1,pp->v.sub2,pp->v.sub3,pp->v.sub4,pp->v.total);
		
	}
}

void Add(list *l, char *name, int MIS, char *branch, int pos, int year) {
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
	tmp->d.year = year;
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

int lengthh(listt *ll) {
	return ll->lengthh;
}

record *delet(list *l, int pos) {
	node *p, *tmp;
	record *retval;
	retval = (record *)malloc(sizeof(record));
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
		if(l->length == 1)
		{
			retval->name = p->d.name;
			retval->MIS = p->d.MIS;
			retval->branch = p->d.branch;
			retval->year = p->d.year;
			l->head = NULL;
			l->tail = NULL;
			free(p);
			(l->length)--;
			return retval;
		}
		p = p->next;
		p->prev = NULL;
		tmp = l->head;
		l->head = p;
		retval->name = tmp->d.name;
		retval->MIS = tmp->d.MIS;
		retval->branch = tmp->d.branch;
		retval->year = tmp->d.year;
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
		retval->year = tmp->d.year;
		free(tmp);
		(l->length)--;		
		return retval;
	}	
	p->prev->next = p->next;
	p->next->prev = p->prev;
	retval->name = p->d.name;
	retval->MIS = p->d.MIS;
	retval->branch = p->d.branch;
	retval->year = p->d.year;
	free(p);
	(l->length)--;
	return retval;	
	
}

void append(list *l, char *name, int MIS, char *branch, int year) {
	node *p, *tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->d.name = (char *)malloc(strlen(name) + 1);
	strcpy(tmp->d.name, name);
	tmp->d.branch = (char *)malloc(strlen(branch) + 1);
	strcpy(tmp->d.branch, branch);
	tmp->d.MIS = MIS;
	tmp->d.year = year;
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
	ret = (record*)malloc(sizeof(record));
	pp = l->head;
	while(pp != l->tail) {
		if (pp->d.MIS == MIS) {
			ret->MIS = pp->d.MIS;
			ret->name = pp->d.name;
			ret->branch = pp->d.branch;
			ret->year = pp->d.year;
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
				ret->year = pp->d.year;
				return ret;
			
			}
			
		}
 	}
}

void creatingID(list *l, int MIS) {
	node *pp;
	pp = l->head;
	while(pp != l->tail) {
		if(MIS == pp->d.MIS) {
			printf(".................................................................................\n..");
			printf("........................IDENTITY CARD.........................\n");
			printf("..................COLLEGE OF ENGINEERING PUNE......................\n");
			printf("NAME : %s\n MIS : %d\n BRANCH : %s\n YEAR : %d\n", pp->d.name, pp->d.MIS, pp->d.branch, pp->d.year);
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
				printf("NAME :%s\n MIS : %d\n BRANCH : %s\n YEAR : %d\n", pp->d.name, pp->d.MIS, pp->d.branch, pp->d.year);
				printf("..................................................................................\n");		
			}
			else {
				printf("NO RECORD FOUND");
			}
		}	
 	}
}

void Modify(list *l, int MIS, char *name, char *branch, int year) {
	node *pp;
	pp = l->head;
	while(pp != l->tail) {
		if (pp->d.MIS == MIS) {
			pp->d.MIS = MIS;
			pp->d.year = year;
			strcpy(pp->d.name, name);
			strcpy(pp->d.branch, branch);
			
		}
	pp = pp->next;
	}
	if(pp) {
		if(pp->next == NULL) {
			if(MIS == pp->d.MIS) {
				pp->d.MIS = MIS;
				pp->d.year = year;
				strcpy(pp->d.name, name);
				strcpy(pp->d.branch, branch);
			}
			
		}
 	}		
}

void totalmarks(listt *ll, list *l, int MIS, int sub1, int sub2, int sub3, int sub4, int poss) {
	nnode *pp, *tmpp;
	int j;
	if(poss < 0 || poss > ll->lengthh)		
		return;
	tmpp = (nnode *)malloc(sizeof(nnode));
	tmpp->v.MIS = MIS;
	tmpp->v.sub1 = sub1;
	tmpp->v.sub2 = sub2;
	tmpp->v.sub3 = sub3;
	tmpp->v.sub4 = sub4;
	tmpp->v.total = sub1 +sub2 + sub3 + sub4;
	if(ll->headd == NULL) {
		ll->headd = ll->taill = tmpp;
		ll->lengthh = 1;
		l->length = 1;
		tmpp->nnext = tmpp->pprev = NULL;
		return;
	}
	pp = ll->headd;
	for(j = 0; j < poss - 1; j++) {
		pp = pp->nnext;
	}
	if(poss == 0) {
		tmpp->nnext = pp;
		tmpp->pprev = NULL;
		pp->pprev = tmpp;
		ll->headd = tmpp;
		(ll->lengthh)++;
		(l->length)++;
		return;
	}
	if(poss == ll->lengthh) {
		tmpp->pprev = pp;
		tmpp->nnext = NULL;
		pp->nnext = tmpp;
		ll->taill = tmpp;
		(ll->lengthh)++;
		(l->length)++;
		return;
	}
	tmpp->nnext = pp->nnext;
	tmpp->pprev = pp;
	pp->nnext->pprev = tmpp;
	pp->nnext = tmpp;
	(ll->lengthh)++;
	(l->length)++;
}



