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

void init1(list1 *l1) {
	l1->head1 = l1->tail1 = NULL;
	l1->length1 = 0;
}

void init2(list2 *l2) {
	l2->head2 = l2->tail2 = NULL;
	l2->length2 = 0;
}

void print(list *l) {
	node *p;
	p = l->head;
	printf("NAME		MIS		BRANCH		YEAR\n");
	while(p != l->tail) {
		printf("%s		%d		%s		%d\n ", p->d.name, p->d.MIS, p->d.branch, p->d.year);
		p = p->next;
	}
	if(p) {
		if(p->next == NULL) {
			printf("%s		%d		%s		%d\n", p->d.name, p->d.MIS, p->d.branch, p->d.year);
		}
	}
}

void print2(list2 *l2) {
	node2 *p2;
	p2 = l2->head2;
	printf("NAME		MIS		MOBILENO		ADDRESS\n");
	while(p2 != l2->tail2) {
		printf("%s		%d		%d		%s\n ", p2->f.name, p2->f.MISS, p2->f.mobile, p2->f.address);
		p2 = p2->next2;
	}
	if(p2) {
		if(p2->next2 == NULL) {
			printf("%s		%d		%d		%s\n", p2->f.name, p2->f.MISS, p2->f.mobile, p2->f.address);
		}
	}
}

int length(list *l) {
	return l->length;
}

int length1(list1 *l1) {
	return l1->length1;
}

void append(list *l, char *name, int MIS, char *branch, int year, FILE *fp) {
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
		fwrite(&(tmp->d), sizeof(tmp->d), 1, fp);
		return;
	}
		p = l->tail;
		tmp->prev = p;
		tmp->next = NULL;
		p->next = tmp;
		l->tail = tmp;
		l->length++;
		fwrite(&(tmp->d), sizeof(tmp->d), 1, fp);
		return;
}
 
record *search(list *l, int MIS) {
	node *pp;
	record *ret;
	ret = (record*)malloc(sizeof(record));
	pp = l->head;
	if(l->head == NULL) {
		return NULL;
	}
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
			else {
				return NULL;
			}
		}
 	}
}

personal *search2(list2 *l2, int MISS) {
	node2 *pp2;
	personal *ret2;
	ret2 = (personal*)malloc(sizeof(personal));
	pp2 = l2->head2;
	if(l2->head2 == NULL) {
		return NULL;
	}
	while(pp2 != l2->tail2) {
		if (pp2->f.MISS == MISS) {
			ret2->MISS = pp2->f.MISS;
			ret2->name = pp2->f.name;
			ret2->address = pp2->f.address;
			ret2->mobile = pp2->f.mobile;
			return ret2;
		}
	pp2 = pp2->next2;
	}
	if(pp2) {
		if(pp2->next2 == NULL) {
			if(MISS == pp2->f.MISS) {
				ret2->MISS = pp2->f.MISS;
				ret2->name = pp2->f.name;
				ret2->address = pp2->f.address;
				ret2->mobile = pp2->f.mobile;
				return ret2;
				
			}
			else {
				return NULL;
			}
		}
 	}
}

void creatingID(list *l, int MIS) {
	node *pp;
	pp = l->head;
	if(l->head == NULL) {
		printf("LIST EMPTY\n");
		return;
	}
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
				printf("NO RECORD FOUND\n");
			}
		}	
 	}
}

void Modify(list *l, int MIS, char *name, char *branch, int year) {
	node *pp;
	pp = l->head;
	if(l->head == NULL) {
		printf("LIST EMPTY\n");
		return;
	}
	while(pp != l->tail) {
		if (pp->d.MIS == MIS) {
			pp->d.MIS = MIS;
			pp->d.year = year;
			strcpy(pp->d.name, name);
			strcpy(pp->d.branch, branch);
			return;
			
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
			else {
				printf("INVALID ENTRY\n");
			}
		}
 	}		
}

void Add(list *l, char *name, int MIS, char *branch, int pos, int year, FILE *fp) {
	node *p, *tmp;
	int j;
	tmp = (node *)malloc(sizeof(node));
	tmp->d.name = (char *)malloc(strlen(name) + 1);
	strcpy(tmp->d.name, name);
	tmp->d.branch = (char *)malloc(strlen(branch) + 1);
	strcpy(tmp->d.branch, branch);
	tmp->d.MIS = MIS;
	tmp->d.year = year;
	if(l->head == NULL ) {
		l->head = l->tail = tmp;
		l->length = 1;
		tmp->next = tmp->prev = NULL;
		fwrite(&(tmp->d), sizeof(tmp->d), 1, fp);
		return;
	}
	p = l->head;
	while(p->d.MIS != pos) {
		if(p == l->tail && p->d.MIS != pos) {
			printf("The MIS entered is not present in the list.\n");
			return;
		}
		p = p->next;
	}

	if(l->head == p) {
		tmp->next = p;
		tmp->prev = NULL;
		p->prev = tmp;
		l->head = tmp;
		(l->length)++;
		fwrite(&(tmp->d), sizeof(tmp->d), 1, fp);
		return;
	}
	tmp->next = p;
	tmp->prev = p->prev;
	p->prev->next = tmp;
	p->prev = tmp;
	(l->length)++;
	fwrite(&(tmp->d), sizeof(tmp->d), 1, fp);
}

record *delet(list *l, int pos) {
	node *p, *tmp;
	record *retval;
	retval = (record *)malloc(sizeof(record));
	int j;
	if(l->head == NULL) {
		l->length = 0;
		return;
	}
	p = l->head;
	while(p->d.MIS != pos) {
		if(p == l->tail && p->d.MIS != pos) {
			printf("INVALID ENTRY\n");
			return;
		}
		p = p->next;
	}
	if(p == l->head) {
		if(l->head == l->tail)
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
	else if(p = l->tail) {
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

void Modify2(list2 *l2, int MISS, char *name, int mobile, char *address) {
	node2 *pp2;
	pp2 = l2->head2;
	if(l2->head2 == NULL) {
		printf("LIST EMPTY\n");
		return;
	}
	while(pp2 != l2->tail2) {
		if (pp2->f.MISS == MISS) {
			pp2->f.MISS = MISS;
			pp2->f.mobile = mobile;
			strcpy(pp2->f.name, name);
			strcpy(pp2->f.address, address);
			return;
			
		}
	pp2 = pp2->next2;
	}
	if(pp2) {
		if(pp2->next2 == NULL) {
				if (pp2->f.MISS == MISS) {
				pp2->f.MISS = MISS;
				pp2->f.mobile = mobile;
				strcpy(pp2->f.name, name);
				strcpy(pp2->f.address, address);
				return;
			
			}
			else {
				printf("INVALID ENTRY\n");
			}
		}
 	}		
}

void Add2(list2 *l2, char *name, int MISS, int mobile, char *address, int loc, FILE *fp2) {
	node2 *p2, *tmp2;
	int j;
	tmp2 = (node2 *)malloc(sizeof(node2));
	tmp2->f.name = (char *)malloc(strlen(name) + 1);
	strcpy(tmp2->f.name, name);
	tmp2->f.address = (char *)malloc(strlen(address) + 1);
	strcpy(tmp2->f.address, address);
	tmp2->f.MISS = MISS;
	tmp2->f.mobile = mobile;
	if(l2->head2 == NULL ) {
		l2->head2 = l2->tail2 = tmp2;
		l2->length2 = 1;
		tmp2->next2 = tmp2->prev2 = NULL;
		fwrite(&(tmp2->f), sizeof(tmp2->f), 1, fp2);
		return;
	}
	p2 = l2->head2;
	while(p2->f.MISS != loc) {
		if(p2 == l2->tail2 && p2->f.MISS != loc) {
			printf("The MIS entered is not present in the list.\n");
			return;
		}
		p2 = p2->next2;
	}

	if(l2->head2 == p2) {
		tmp2->next2 = p2;
		tmp2->prev2 = NULL;
		p2->prev2 = tmp2;
		l2->head2 = tmp2;
		(l2->length2)++;
		fwrite(&(tmp2->f), sizeof(tmp2->f), 1, fp2);
		return;
	}
	tmp2->next2 = p2;
	tmp2->prev2 = p2->prev2;
	p2->prev2->next2 = tmp2;
	p2->prev2 = tmp2;
	(l2->length2)++;
	fwrite(&(tmp2->f), sizeof(tmp2->f), 1, fp2);
}

personal *delet2(list2 *l2, int loc) {
	node2 *p2, *tmp2;
	personal *retval2;
	retval2 = (personal *)malloc(sizeof(personal));
	int j;
	if(l2->head2 == NULL) {
		l2->length2 = 0;
		return;
	}
	p2 = l2->head2;
	while(p2->f.MISS != loc) {
		if(p2 == l2->tail2 && p2->f.MISS != loc) {
			printf("INVALID ENTRY\n");
			return;
		}
		p2 = p2->next2;
	}
	if(p2 == l2->head2) {
		if(l2->head2 == l2->tail2)
		{
			retval2->name = p2->f.name;
			retval2->MISS = p2->f.MISS;
			retval2->address = p2->f.address;
			retval2->mobile = p2->f.mobile;
			l2->head2 = NULL;
			l2->tail2 = NULL;
			free(p2);
			(l2->length2)--;
			return retval2;
		}
		p2 = p2->next2;
		p2->prev2 = NULL;
		tmp2 = l2->head2;
		l2->head2 = p2;
		retval2->name = p2->f.name;
		retval2->MISS = p2->f.MISS;
		retval2->address = p2->f.address;
		retval2->mobile = p2->f.mobile;
		free(tmp2);
		(l2->length2)--;
		return retval2;
	}
	else if(p2 = l2->tail2) {
		p2 = p2->prev2;
		p2->next2 = NULL;
		tmp2 = l2->tail2;
		l2->tail2 = p2;
		retval2->name = p2->f.name;
		retval2->MISS = p2->f.MISS;
		retval2->address = p2->f.address;
		retval2->mobile = p2->f.mobile;
		free(tmp2);
		(l2->length2)--;
		return retval2;
		
	}	
	p2->prev2->next2 = p2->next2;
	p2->next2->prev2 = p2->prev2;
	retval2->name = p2->f.name;
	retval2->MISS = p2->f.MISS;
	retval2->address = p2->f.address;
	retval2->mobile = p2->f.mobile;
	free(p2);
	(l2->length2)--;
	return retval2;	
	
}

void T1Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int MI, int sem) {
	node1 *p1, *tmp1;
	int j;
	tmp1 = (node1 *)malloc(sizeof(node1));
	tmp1->s[sem].MIS = MIS;
	tmp1->s[sem].subj1.t1 = m1;
	tmp1->s[sem].subj2.t1 = m2;
	tmp1->s[sem].subj3.t1 = m3;
	tmp1->s[sem].subj4.t1 = m4;
	if(l1->head1 == NULL ) {
		l1->head1 = l1->tail1 = tmp1;
		tmp1->next1 = tmp1->prev1 = NULL;
		return;
	}
	p1 = l1->head1;
	while(p1->s[sem].MIS != MI) {
		if(p1 == l1->tail1 && p1->s[sem].MIS != MI) {
			printf("The MIS entered is not present in the list\n");
			return;
		}
		p1 = p1->next1;
	}
	if(l1->head1 == p1) {
		tmp1->next1 = p1;
		tmp1->prev1 = NULL;
		p1->prev1 = tmp1;
		l1->head1 = tmp1;
		return;
	}
	tmp1->next1 = p1;
	tmp1->prev1 = p1->prev1;
	p1->prev1->next1 = tmp1;
	p1->prev1 = tmp1;
		
}

void printT1(list1 *l1, int sem) {
	node1 *p1;
	p1 = l1->head1;
	printf("SEMISTER : %d\n", sem);
	printf("MIS	T1SUB1	T1SUB2	T1SUB3	T1SUB4\n");
	while(p1 != l1->tail1) {
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.t1,p1->s[sem].subj2.t1,p1->s[sem].subj3.t1,p1->s[sem].subj4.t1);
		p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL)
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.t1,p1->s[sem].subj2.t1,p1->s[sem].subj3.t1,p1->s[sem].subj4.t1);
		
	}
}	

void T2Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem) {
	node1 *p1;
	p1 = l1->head1;
	if(l1->head1 == NULL) {
		printf("LIST EMPTY\n");
		return;
	}
	while(p1 != l1->tail1) {
		if (p1->s[sem].MIS == MIS) {
			p1->s[sem].subj1.t2 =  m1;
			p1->s[sem].subj2.t2 = m2;
			p1->s[sem].subj3.t2 =  m3;
			p1->s[sem].subj4.t2 =  m4;
			return;
		}
	p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL) {
			if (p1->s[sem].MIS == MIS) {
				p1->s[sem].subj1.t2 =  m1;
				p1->s[sem].subj2.t2 = m2;
				p1->s[sem].subj3.t2 =  m3;
				p1->s[sem].subj4.t2 =  m4;
				return;
			}
			else {
				printf("INVALID ENTRY\n");
			}
		}
 	}	
}

void printT2(list1 *l1, int sem) {
	node1 *p1;
	p1 = l1->head1;
	printf("SEMISTER : %d\n", sem);
	printf("MIS	T2UB1	T2SUB2	T2SUB3	T2SUB4\n");
	while(p1 != l1->tail1) {
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.t2,p1->s[sem].subj2.t2,p1->s[sem].subj3.t2,p1->s[sem].subj4.t2);
		p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL)
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.t2,p1->s[sem].subj2.t2,p1->s[sem].subj3.t2,p1->s[sem].subj4.t2);
		
	}
}	

void ESEMarks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem) {
	node1 *p1;
	p1 = l1->head1;
	if(l1->head1 == NULL) {
		printf("LIST EMPTY\n");
		return;
	}
	while(p1 != l1->tail1) {
		if (p1->s[sem].MIS == MIS) {
			p1->s[sem].subj1.ESE =  m1;
			p1->s[sem].subj2.ESE = m2;
			p1->s[sem].subj3.ESE =  m3;
			p1->s[sem].subj4.ESE =  m4;
			return;
		}
	p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL) {
			if(MIS == p1->s[sem].MIS) {
				p1->s[sem].subj1.ESE =  m1;
				p1->s[sem].subj2.ESE = m2;
				p1->s[sem].subj3.ESE =  m3;
				p1->s[sem].subj4.ESE =  m4;
			}
			else {
				printf("INVALID ENTRY\n");
			}
			
		}
 	}				
}

void printESE(list1 *l1, int sem) {
	node1 *p1;
	p1 = l1->head1;
	printf("SEMISTER :%d\n", sem);
	printf("MIS	ESEUB1	ESESUB2	ESESUB3	ESESUB4\n");
	while(p1 != l1->tail1) {
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.ESE,p1->s[sem].subj2.ESE,p1->s[sem].subj3.ESE,p1->s[sem].subj4.ESE);
		p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL)
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.ESE,p1->s[sem].subj2.ESE,p1->s[sem].subj3.ESE,p1->s[sem].subj4.ESE);
		
	}
}	

void Total(list1 *l1, int MIS, int sem, FILE *fp1) {
	node1 *p1;
	p1 = l1->head1;
	if(l1->head1 == NULL) {
		printf("LIST EMPTY\n");
		return;
	}
	while(p1 != l1->tail1) {
		if (p1->s[sem].MIS == MIS) {
			p1->s[sem].subj1.total =  p1->s[sem].subj1.t1 + p1->s[sem].subj1.t2 + p1->s[sem].subj1.ESE;
			p1->s[sem].subj2.total =  p1->s[sem].subj2.t1 + p1->s[sem].subj2.t2 + p1->s[sem].subj2.ESE;
			p1->s[sem].subj3.total =  p1->s[sem].subj3.t1 + p1->s[sem].subj3.t2 + p1->s[sem].subj3.ESE;
			p1->s[sem].subj4.total =  p1->s[sem].subj4.t1 + p1->s[sem].subj4.t2 + p1->s[sem].subj4.ESE;
			(l1->length1)++;
			fwrite(&(p1->s[sem]), sizeof(p1->s[sem]), 1 , fp1);
			return;
			
		}
	p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL) {
			if(MIS == p1->s[sem].MIS) {
				p1->s[sem].subj1.total =  p1->s[sem].subj1.t1 + p1->s[sem].subj1.t2 + p1->s[sem].subj1.ESE;
				p1->s[sem].subj2.total =  p1->s[sem].subj2.t1 + p1->s[sem].subj2.t2 + p1->s[sem].subj2.ESE;
				p1->s[sem].subj3.total =  p1->s[sem].subj3.t1 + p1->s[sem].subj3.t2 + p1->s[sem].subj3.ESE;
				p1->s[sem].subj4.total =  p1->s[sem].subj4.t1 + p1->s[sem].subj4.t2 + p1->s[sem].subj4.ESE;
				(l1->length1)++;
				fwrite(&(p1->s[sem]), sizeof(p1->s[sem]), 1 , fp1);
			}
			else {
				printf("INVALID ENTRY\n");
			}
		}
 	}
}

void printTOT(list1 *l1, int sem) {
	node1 *p1;
	p1 = l1->head1;
	printf("SEMISTER : %d\n", sem);
	printf("MIS	TSUB1	TSUB2	TSUB3	TSUB4\n");
	while(p1 != l1->tail1) {
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.total,p1->s[sem].subj2.total,p1->s[sem].subj3.total,p1->s[sem].subj4.total);
		p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL) {
		printf("%d	%d	%d	%d	%d\n ",p1->s[sem].MIS,p1->s[sem].subj1.total,p1->s[sem].subj2.total,p1->s[sem].subj3.total,p1->s[sem].subj4.total);
		}
		
	}
}	


void insertfromfile(list *l, FILE *fp3) {
	char d[10];
	char n[10];
	char h[16];
	int f1, f2;
	node *p, *tmp;
	int j;
	char buf[60];
	if(fp3 == NULL) {
		printf("file not opened\n");
	}
	while(fgets(buf, 60, fp3) != 0 ) {
		sscanf(buf, "%s%s%d%s%d", d, n, &f1, h, &f2);
		strcat(d,n);	
		tmp = (node *)malloc(sizeof(node));
		tmp->d.name = (char *)malloc(strlen(d) + 1);
		strcpy(tmp->d.name, d);
		tmp->d.branch = (char *)malloc(strlen(h) + 1);
		strcpy(tmp->d.branch, h);
		tmp->d.MIS = f1;
		tmp->d.year = f2;
		if(l->head == NULL) {
			l->head = l->tail = tmp;
			tmp->prev = tmp->next = NULL;
			l->length++;
			continue;
		}
		p = l->tail;
		tmp->prev = p;
		tmp->next = NULL;
		p->next = tmp;
		l->tail = tmp;
		l->length++;
		continue;
	}	
}
