/*PROJECT : STUDENT DATA MANAGEMENT SYSTEM*/

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

typedef struct record {
	char *name;
	int MIS;
	char *branch;
	int year;
	
}record;
typedef struct personal {
	char *name;
	int MISS;
	int mobile;
	char *email_Id;
}personal;
typedef struct list1 {
	struct node1 *head1, *tail1;
	int length1;
}list1;
typedef struct markss {
	int t1;
	int t2;
	int ESE;
	int total;
}markss;
typedef struct semester {
	int MIS;
	markss subj1;
	markss subj2;
	markss subj3;
	markss subj4;
}semester;
typedef struct node1 {
	struct node1 *next1, *prev1;
	semester s[8];
}node1;
typedef struct node {
	struct node *next, *prev;
	record d;
}node;
typedef struct node2 {
	struct node2 *next2, *prev2;
	personal f;
}node2;
typedef struct list {
	struct node *head, *tail;
	int length;
}list;
typedef struct list2 {
	struct node2 *head2, *tail2;
	int length2;
}list2;
void init(list *l);   /*initialise list of academic record of students*/
void init1(list1 *l1); /*initialise list of marks of studets*/
void init2(list2 *l2);  /*initialise list of personal record of students*/
void print_academic(list *l); /*display the list of academic records*/
void print2_personal(list2 *l2);  /*display the list of personal records*/
void Add_academic(list *l, char *name, int MIS, char *branch, int year, int pos, FILE *fp); /*add academic record before a particular record and write in file*/
void Add2_personal(list2 *l2, char *name, int MIS, int mobile, char *email_Id, int loc, FILE *fp2); /*add personal record before a particular record and write in file*/
record *delet_academic(list *l, int pos, FILE *fp, FILE *fp4);
personal *delet2_personal(list2 *l2, int loc, FILE *fp2, FILE *fp9);
record *search(list *l, int MIS);
personal *search2(list2 *l2, int MISS);
void Modify_academic(list *l, int MIS, char *name, char *branch, int year, FILE *fp, FILE *fp6);
void Modify2_personal(list2 *l2, int MISS, char *name, int mobile, char *email_Id, FILE *fp2, FILE *fp8);
void append_academic(list *l, char *name, int MIS, char *branch, int year, FILE *fp); /*add a academic record at the end of list and write in file*/
int length(list *l); /*find number of records in academic records list*/
int lenght1(list1 *l1); /*find number of students who appeared for exam*/
int length2(list2 *l2);  /*find number of records in personal records list*/
void creatingID(list *l, int MIS);
void academicfromfile(list *l, FILE *fp3, FILE *fp);  /*read academic record from file and add it*/
void personalfromfile(list2 *l2, FILE *fp10, FILE *fp2);  /*read personal records from file and add it*/
void T1Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int MI, int sem);  /*add T1 marks of student for a particular semester*/
void printT1(list1 *l1, int sem);
void T2Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem);   /*add T2 marks of student for a particular semester*/
void printT2(list1 *l1, int sem);
void ESEMarks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem);   /*add ESE marks of student for a particular semester*/
void printESE(list1 *l1, int sem);
void Total(list1 *l1, int MIS, int sem, FILE *fp1);  /*find total marks of student for a particular semester and write all marks in file*/
void printTOT(list1 *l1, int sem);
void link(list *l, list1 *l1, list2 *l2, int MIS, int sem);  /*display all details of a student of a semester*/
