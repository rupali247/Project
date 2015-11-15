/*****************************************************************************
 * Copyright (C) Rupali Rajendra More morerr14.comp@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
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
	printf("NAME				MIS	BRANCH		YEAR\n");
	while(p != l->tail) {
		printf("%s	%d	%s	%d\n ", p->d.name, p->d.MIS, p->d.branch, p->d.year);
		p = p->next;
	}
	if(p) {
		if(p->next == NULL) {
			printf("%s	%d	%s	%d\n", p->d.name, p->d.MIS, p->d.branch, p->d.year);
		}
	}
}

void print2(list2 *l2) {
	node2 *p2;
	p2 = l2->head2;
	printf("NAME				MIS		MOBILENO		EMAIL ID\n");
	while(p2 != l2->tail2) {
		printf("%s	%d		%d		%s\n ", p2->f.name, p2->f.MISS, p2->f.mobile, p2->f.email_Id);
		p2 = p2->next2;
	}
	if(p2) {
		if(p2->next2 == NULL) {
			printf("%s	%d		%d		%s\n", p2->f.name, p2->f.MISS, p2->f.mobile, p2->f.email_Id);
		}
	}
}

int length(list *l) {       /*returns number of student records*/
	return l->length;
}

int length1(list1 *l1) {   /*returns number of students who appeared for ESE exam*/
	return l1->length1;
}

void append_academic(list *l, char *name, int MIS, char *branch, int year, FILE *fp) { /*add academic record at the end of list and write in file*/
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
		fprintf(fp, "%s %d %s %d\n",tmp->d.name, tmp->d.MIS,tmp->d.branch, tmp->d.year);
		return;
	}
		p = l->tail;
		tmp->prev = p;
		tmp->next = NULL;
		p->next = tmp;
		l->tail = tmp;
		l->length++;
		fprintf(fp, "%s %d %s %d\n",tmp->d.name, tmp->d.MIS,tmp->d.branch, tmp->d.year);
		return;
}
 
record *search(list *l, int MIS) {          /*searches a record of student*/
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

personal *search2(list2 *l2, int MISS) {       /*searches a personal record of student*/
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
			ret2->email_Id = pp2->f.email_Id;
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
				ret2->email_Id = pp2->f.email_Id;
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
			printf("		.................................................................................\n..");
			printf("		........................IDENTITY CARD.........................\n");
			printf("		..................COLLEGE OF ENGINEERING PUNE......................\n");
			printf("		NAME : %s\n\t\t MIS : %d\n\t\t BRANCH : %s\n\t\t YEAR : %d\n", pp->d.name, pp->d.MIS, pp->d.branch, pp->d.year);
			printf("		....................................................................................\n");
			return;
		}
	pp = pp->next;
	}
	if(pp) {
		if(pp->next == NULL) {
			if(MIS == pp->d.MIS) {
				printf("		..................................................................................\n");
				printf("		.....................IDENTITY CARD.....................\n");
				printf("		................COLLEGE OF ENGINEERING PUNE...............\n");
				printf("		NAME :%s\n\t\t MIS : %d\n\t\t BRANCH : %s\n\t\t YEAR : %d\n", pp->d.name, pp->d.MIS, pp->d.branch, pp->d.year);
				printf("		..................................................................................\n");		
			}
			else {
				printf("NO RECORD FOUND\n");
			}
		}	
 	}
}

void Modify_academic(list *l, int MIS, char *name, char *branch, int year, FILE *fp, FILE *fp6) { /*modifies the academic record of a student*/             
	node *pp;
	int  n, i;
	char d[16];
	char c[16];
	char h[32];
	char b[16];
	int f1, f2;
	char buf[100];
	rewind(fp);
	while(fgets(buf, 100, fp) != 0 ) {  /*reads a line from first file*/
		sscanf(buf, "%s %s %s %d %s %d", d, c, b, &f1, h, &f2);
		if(f1 != MIS) {
			fprintf(fp6, "%s %s %s %d %s %d\n", d, c, b, f1, h, f2); /*data is written in second file(except the data to be modified)*/
		}
		else if(f1 == MIS)  {
			fprintf(fp6, "%s %d %s %d\n", name, MIS, branch, year); /*modified data is written in second file*/
		}		
	}
	remove("k.txt"); /*first file is removed*/  
	rename("n.txt","k.txt"); /*second file is renamed as first file*/
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

void Add_academic(list *l, char *name, int MIS, char *branch, int pos, int year, FILE *fp) {  /*add record before a particular MIS and write in file*/         
	node *p, *tmp;
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
		fprintf(fp, "%s %d %s %d\n",tmp->d.name, tmp->d.MIS,tmp->d.branch, tmp->d.year);
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
		fprintf(fp, "%s %d %s %d\n",tmp->d.name, tmp->d.MIS,tmp->d.branch, tmp->d.year);
		return;
	}
	tmp->next = p;
	tmp->prev = p->prev;
	p->prev->next = tmp;
	p->prev = tmp;
	(l->length)++;	
	fprintf(fp, "%s %d %s %d\n",tmp->d.name, tmp->d.MIS,tmp->d.branch, tmp->d.year);
}

record *delet_academic(list *l, int pos, FILE *fp, FILE *fp4) {                 /*deletes a record*/
	node *p, *tmp;
	record *retval;
	rewind(fp);
	char d[16];
	char c[16];
	char b[16];
	char h[32];
	int f1, f2;
	char buf[100];
	while(fgets(buf, 100, fp) != 0 ) {  /*reads a line from first file*/
		sscanf(buf, "%s %s %s %d %s %d", d, c, b, &f1, h, &f2);
		if(f1 != pos) {
			fprintf(fp4, "%s %s %s %d %s %d\n", d, c, b, f1, h, f2); /*all records except the one to be deleted are written in second file*/
		}	
	}
	remove("k.txt"); /*first file is removed*/
	rename("d.txt","k.txt");  /*second file is renamed as first file*/
	retval = (record *)malloc(sizeof(record));
	if(l->head == NULL) {
		l->length = 0;
		return NULL;
	}
	p = l->head;
	while(p->d.MIS != pos) {
		if(p == l->tail && p->d.MIS != pos) {
			printf("INVALID ENTRY\n");
			return NULL;
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
	else if(p == l->tail) {
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

void Modify2_personal(list2 *l2, int MISS, char *name, int mobile, char *email_Id, FILE *fp2, FILE *fp8) {
	node2 *pp2;
	char d[16];
	char c[16];
	char b[16];
	char h[32];
	int f1, f2;
	char buf[100];
	rewind(fp2);
	while(fgets(buf, 100, fp2) != 0 ) {  /*reads a line from first file*/
		sscanf(buf, "%s %s %s %d %s %d", d, c, b, &f1, h, &f2);
		if(f1 != MISS) {
			fprintf(fp8, "%s %s %s %d %s %d\n", d, c, b, f1, h, f2); /*data is written in second file(except one to be modified)*/
		}
		else if(f1 == MISS)  {
			fprintf(fp8, "%s %d %s %d\n", name, MISS, email_Id, mobile); /*modified data os written in second file*/
		}
				
	}
	remove("c.txt"); /*first file is removed*/
	rename("w.txt","c.txt"); /*second file renamed as first file*/
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
			strcpy(pp2->f.email_Id, email_Id);
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
				strcpy(pp2->f.email_Id, email_Id);
				return;
			}
			else {
				printf("INVALID ENTRY\n");
			}
		}
 	}		
}

void Add2_personal(list2 *l2, char *name, int MISS, int mobile, char *email_Id, int loc, FILE *fp2) {  /*add personal record before a particular MIS and write in file*/ 
	node2 *p2, *tmp2;
	int j;
	tmp2 = (node2 *)malloc(sizeof(node2));
	tmp2->f.name = (char *)malloc(strlen(name) + 1);
	strcpy(tmp2->f.name, name);
	tmp2->f.email_Id = (char *)malloc(strlen(email_Id) + 1);
	strcpy(tmp2->f.email_Id, email_Id);
	tmp2->f.MISS = MISS;
	tmp2->f.mobile = mobile;
	if(l2->head2 == NULL ) {
		l2->head2 = l2->tail2 = tmp2;
		l2->length2 = 1;
		tmp2->next2 = tmp2->prev2 = NULL;
		fprintf(fp2, "%s %d %s %d\n",tmp2->f.name, tmp2->f.MISS,tmp2->f.email_Id, tmp2->f.mobile);
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
		fprintf(fp2, "%s %d %s %d\n",tmp2->f.name, tmp2->f.MISS,tmp2->f.email_Id, tmp2->f.mobile);
		return;
	}
	tmp2->next2 = p2;
	tmp2->prev2 = p2->prev2;
	p2->prev2->next2 = tmp2;
	p2->prev2 = tmp2;
	(l2->length2)++;
	fprintf(fp2, "%s %d %s %d\n",tmp2->f.name, tmp2->f.MISS,tmp2->f.email_Id, tmp2->f.mobile);
}

personal *delet2_personal(list2 *l2, int loc, FILE *fp2, FILE *fp9) {
	node2 *p2, *tmp2;
	personal *retval2;
	rewind(fp2);
	char d[16];
	char c[16];
	char b[16];
	char h[32];
	int f1, f2;
	char buf[100];
	while(fgets(buf, 100, fp2) != 0 ) {  /*reads a line from first file*/
		sscanf(buf, "%s %s %s %d %s %d", d, c, b, &f1, h, &f2); 
		if(f1 != loc) {
			fprintf(fp9, "%s %s %s %d %s %d\n", d, c, b, f1, h, f2);  /*all records except the one to be modified are written in second file*/
		}	
	}
	remove("c.txt"); /*remove first file*/
	rename("s.txt","c.txt");/*rename second file as first file*/
	retval2 = (personal *)malloc(sizeof(personal));
	int j;
	if(l2->head2 == NULL) {
		l2->length2 = 0;
		return NULL;
	}
	p2 = l2->head2;
	while(p2->f.MISS != loc) {
		if(p2 == l2->tail2 && p2->f.MISS != loc) {
			return NULL;
		}
		p2 = p2->next2;
	}
	if(p2 == l2->head2) {
		if(l2->head2 == l2->tail2)
		{
			retval2->name = p2->f.name;
			retval2->MISS = p2->f.MISS;
			retval2->email_Id = p2->f.email_Id;
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
		retval2->name = tmp2->f.name;
		retval2->MISS = tmp2->f.MISS;
		retval2->email_Id = tmp2->f.email_Id;
		retval2->mobile = tmp2->f.mobile;
		free(tmp2);
		(l2->length2)--;
		return retval2;
	}
	else if(p2 == l2->tail2) {
		p2 = p2->prev2;
		p2->next2 = NULL;
		tmp2 = l2->tail2;
		l2->tail2 = p2;
		retval2->name = p2->f.name;
		retval2->MISS = p2->f.MISS;
		retval2->email_Id = p2->f.email_Id;
		retval2->mobile = p2->f.mobile;
		free(tmp2);
		(l2->length2)--;
		return retval2;
	}	
	p2->prev2->next2 = p2->next2;
	p2->next2->prev2 = p2->prev2;
	retval2->name = p2->f.name;
	retval2->MISS = p2->f.MISS;
	retval2->email_Id = p2->f.email_Id;
	retval2->mobile = p2->f.mobile;
	free(p2);
	(l2->length2)--;
	return retval2;	
}

void T1Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int MI, int sem) {    /*adds T1 marks of a student for a particular semester*/
	node1 *p1, *p11, *tmp1;
	int j, i;
	p1 = l1->head1;
	p11 = l1->head1;
	if(l1->head1 != NULL) {
		while(p11) {
			for(i = 0; i < 8; i++) {
				if(p11->s[i].MIS == MIS) {
					p11->s[sem].MIS = MIS;
					p11->s[sem].subj1.t1 = m1;
					p11->s[sem].subj2.t1 = m2;
					p11->s[sem].subj3.t1 = m3;
					p11->s[sem].subj4.t1 = m4;
					return;	
 				}
			}
			p11 = p11->next1;
		}
	}
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

void printT1(list1 *l1, int sem) {                /*prints T1 marks of a student*/
	node1 *p1;
	p1 = l1->head1;
	printf("semester : %d\n", sem);
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

void T2Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem) {    /*adds T2 marks of a student for a particular semester*/
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

void printT2(list1 *l1, int sem) {            /*prints T2 marks of a student*/
	node1 *p1;
	p1 = l1->head1;
	printf("semester : %d\n", sem);
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

void ESEMarks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem) {       /*adds ESE marks of a student for a particular semester*/ 
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

void printESE(list1 *l1, int sem) {         /*prints ESE marks of a student*/
	node1 *p1;
	p1 = l1->head1;
	printf("semester :%d\n", sem);
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

void Total(list1 *l1, int MIS, int sem, FILE *fp1) {        /*adds total marks of a student for a particular semester and write all marks in file*/ 
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
			fprintf(fp1, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p1->s[sem].MIS, sem, p1->s[sem].subj1.t1, p1->s[sem].subj1.t2 , p1->s[sem].subj1.ESE, p1->s[sem].subj1.total, p1->s[sem].subj2.t1 , p1->s[sem].subj2.t2 , p1->s[sem].subj2.ESE, p1->s[sem].subj2.total,p1->s[sem].subj3.t1 , p1->s[sem].subj3.t2 , p1->s[sem].subj3.ESE, p1->s[sem].subj3.total, p1->s[sem].subj4.t1 , p1->s[sem].subj4.t2 , p1->s[sem].subj4.ESE, p1->s[sem].subj4.total );
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
				fprintf(fp1, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p1->s[sem].MIS, sem, p1->s[sem].subj1.t1, p1->s[sem].subj1.t2 , p1->s[sem].subj1.ESE, p1->s[sem].subj1.total, p1->s[sem].subj2.t1 , p1->s[sem].subj2.t2 , p1->s[sem].subj2.ESE, p1->s[sem].subj2.total,p1->s[sem].subj3.t1 , p1->s[sem].subj3.t2 , p1->s[sem].subj3.ESE, p1->s[sem].subj3.total, p1->s[sem].subj4.t1 , p1->s[sem].subj4.t2 , p1->s[sem].subj4.ESE, p1->s[sem].subj4.total );
			}
			else {
				printf("INVALID ENTRY\n");
			}
		}
 	}
}

void printTOT(list1 *l1, int sem) {      /*prints TOTAl marks of a student*/
	node1 *p1;
	p1 = l1->head1;
	printf("semester : %d\n", sem);
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


void academicfromfile(list *l, FILE *fp3, FILE *fp) {    /*reads student records from list and add it*/
	char f[16];
	char m[16];
	char s[16];
	char h[16];
	char spc[] = " ";
	
	int f1, f2;
	node *p, *tmp;
	int j;
	char buf[100];
	if(fp3 == NULL) {
		printf("file not opened\n");
	}
	while(fgets(buf, 100, fp3) != 0 ) {            /*reads a line from a file*/
		char str[60] = ""; 		
		sscanf(buf, "%s%s%s%d%s%d", f, m, s, &f1, h, &f2);
		strcat(str, f);
		strcat(str, spc);
		strcat(str, m);
		strcat(str, spc);
		strcat(str, s);
		tmp = (node *)malloc(sizeof(node));
		tmp->d.name = (char *)malloc(strlen(str) + 1);
		strcpy(tmp->d.name, str);
		tmp->d.branch = (char *)malloc(strlen(h) + 1);
		strcpy(tmp->d.branch, h);
		tmp->d.MIS = f1;
		tmp->d.year = f2;
		if(l->head == NULL) {
			l->head = l->tail = tmp;
			tmp->prev = tmp->next = NULL;
			l->length++;
			fprintf(fp, "%s %d %s %d\n",tmp->d.name, tmp->d.MIS,tmp->d.branch, tmp->d.year);
			continue;
		}
		p = l->tail;
		tmp->prev = p;
		tmp->next = NULL;
		p->next = tmp;
		l->tail = tmp;
		l->length++;
		fprintf(fp, "%s %d %s %d\n",tmp->d.name, tmp->d.MIS,tmp->d.branch, tmp->d.year);
		continue;
	}
}

void personalfromfile(list2 *l2, FILE *fp10, FILE *fp2) {    /*reads student records from list and add it*/
	char f[16];
	char m[16];
	char s[16];
	char h[32];
	char spc[] = " ";
	
	int f1, f2;
	node2 *p2, *tmp2;
	int j;
	char buff[100];
	if(fp10 == NULL) {
		printf("file not opened\n");
	}
	while(fgets(buff, 100, fp10) != 0 ) {            /*reads a line from a file*/
		char str[60] = ""; 		
		sscanf(buff, "%s%s%s%d%s%d", f, m, s, &f1, h, &f2);
		strcat(str, f);
		strcat(str, spc);
		strcat(str, m);
		strcat(str, spc);
		strcat(str, s);
		tmp2 = (node2 *)malloc(sizeof(node2));
		tmp2->f.name = (char *)malloc(strlen(str) + 1);
		strcpy(tmp2->f.name, str);
		tmp2->f.email_Id = (char *)malloc(strlen(h) + 1);
		strcpy(tmp2->f.email_Id, h);
		tmp2->f.MISS = f1;
		tmp2->f.mobile = f2;
		if(l2->head2 == NULL) {
			l2->head2 = l2->tail2 = tmp2;
			tmp2->prev2 = tmp2->next2 = NULL;
			l2->length2++;
			fprintf(fp2, "%s %d %s %d\n",tmp2->f.name, tmp2->f.MISS,tmp2->f.email_Id, tmp2->f.mobile);
			continue;
		}
		p2 = l2->tail2;
		tmp2->prev2 = p2;
		tmp2->next2 = NULL;
		p2->next2 = tmp2;
		l2->tail2 = tmp2;
		l2->length2++;
		fprintf(fp2, "%s %d %s %d\n",tmp2->f.name, tmp2->f.MISS,tmp2->f.email_Id, tmp2->f.mobile);
		continue;
	}
}

void link(list *l, list1 *l1, list2 *l2, int MIS, int sem) { /*displays all the details of a particular student for a particular semester*/
	node *pp;
	node2 *pp2;
	node1 *p1;
	pp = l->head;
	printf("MIS : %d\n", MIS);
	while(pp != l->tail) {
		if (pp->d.MIS == MIS) {
			printf("\nName : %s\tMIS : %d\tBranch : %s\tYear : %d\n", pp->d.name, pp->d.MIS, pp->d.branch, pp->d.year);
		}
	pp = pp->next;
	}
	if(pp) {
		if(pp->next == NULL) {
			if(MIS == pp->d.MIS) {
				printf("\nName : %s\tMIS : %d\tBranch : %s\tYear : %d\n", pp->d.name, pp->d.MIS, pp->d.branch, pp->d.year);	
			}
		}
 	}
	pp2 = l2->head2;
	while(pp2 != l2->tail2) {
		if (pp2->f.MISS == MIS) {
			printf("\nName : %s\tMIS : %d\tEmail Id : %s\tMobile : %d\n", pp2->f.name, pp2->f.MISS, pp2->f.email_Id, pp2->f.mobile);
		}
	pp2 = pp2->next2;
	}
	if(pp2) {
		if(pp2->next2 == NULL) {
			if(MIS == pp2->f.MISS) {
				printf("\nName : %s\tMIS : %d\tEmail Id : %s\tMobile : %d\n", pp2->f.name, pp2->f.MISS, pp2->f.email_Id, pp2->f.mobile);	
			}		
		}
 	}
	p1 = l1->head1;
	while(p1 != l1->tail1) {
		if (p1->s[sem].MIS == MIS) {
			printf("\nMIS: %d\nT1sub1: %d T2sub1: %d ESEsub1: %d Totalsub1: %d\nT1sub2: %d T2sub2: %d ESEsub2: %d Totalsub2: %d\nT1sub3: %d T2sub3: %d ESEsub3: %d Totalsub3: %d\nT1sub4: %d T2sub4: %d ESEsub4: %d Totalsub4: %d\n", p1->s[sem].MIS, p1->s[sem].subj1.t1, p1->s[sem].subj1.t2 , p1->s[sem].subj1.ESE, p1->s[sem].subj1.total, p1->s[sem].subj2.t1 , p1->s[sem].subj2.t2 , p1->s[sem].subj2.ESE, p1->s[sem].subj2.total,p1->s[sem].subj3.t1 , p1->s[sem].subj3.t2 , p1->s[sem].subj3.ESE, p1->s[sem].subj3.total, p1->s[sem].subj4.t1 , p1->s[sem].subj4.t2 , p1->s[sem].subj4.ESE, p1->s[sem].subj4.total );
		}
	p1 = p1->next1;
	}
	if(p1) {
		if(p1->next1 == NULL) {
			if(MIS == p1->s[sem].MIS) {
				printf("\nMIS: %d\nT1sub1: %d T2sub1: %d ESEsub1: %d Totalsub1: %d\nT1sub2: %d T2sub2: %d ESEsub2: %d Totalsub2: %d\nT1sub3: %d T2sub3: %d ESEsub3: %d Totalsub3: %d\nT1sub4: %d T2sub4: %d ESEsub4: %d Totalsub4: %d\n", p1->s[sem].MIS, p1->s[sem].subj1.t1, p1->s[sem].subj1.t2 , p1->s[sem].subj1.ESE, p1->s[sem].subj1.total, p1->s[sem].subj2.t1 , p1->s[sem].subj2.t2 , p1->s[sem].subj2.ESE, p1->s[sem].subj2.total,p1->s[sem].subj3.t1 , p1->s[sem].subj3.t2 , p1->s[sem].subj3.ESE, p1->s[sem].subj3.total, p1->s[sem].subj4.t1 , p1->s[sem].subj4.t2 , p1->s[sem].subj4.ESE, p1->s[sem].subj4.total );
			}	
		}
 	}
}
