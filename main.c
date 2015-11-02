#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "data.h"
int printmenu() {
	int choice;
	printf("\n	......................STUDENT DATA MANAGEMENT.........................\n"\
	"\n		  1 : Add student's academic record\n"\
	"		  2 : Delete student's academic record\n"\
	"		  3 : Search a student's academic record\n"\
	"		  4 : Append a student's academic record to the list\n"\
	"		  5 : Find number of students in student's academic records list\n"\
	"		  6 : Creating Id\n"\
	"		  7 : Read student record from file and add it\n"\
	"		  8 : Modify a students's academic record\n"\
	"		  9 : number of students who appeared for final exam\n"\
	"		  10 : Add T1 marks of a student for a particular semester\n"\
	"		  11 : Add T2 marks of a student for a particular semester\n"\
	"		  12 : Add ESE marks of a student for a particular semester\n"\
	"		  13 : Add Total marks of a student for a particular semester\n"\
	"		  14 : Add student's personal record\n"\
	"		  15 : Delete student's personal record\n"\
	"		  16 : Search student's personal record\n"\
	"		  17 : Modify student's personal record\n"\
	"		  18 : display all details of the student\n"\
	"		  19 : Exit\n"\
	"	......................................................................\n");
	scanf("%d", &choice);
	return choice;
}
int main(int argc, char *argv[]) {
	int i, s;
	list q;
	list1 q1;
	list2 q2;
	record d;
	personal f;
	record *ptr, *pt;
	personal *ptr2, *pt2;
	FILE *fp;
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	FILE *fp4;
	FILE *fp6;
	FILE *fp8;
	FILE *fp9;
	fp = fopen("k.txt", "w+");
	fp1 = fopen("b.txt", "w+");
	fp2 = fopen("c.txt", "w+");
	fp3 = fopen("a.txt", "r");
	fp4 = fopen("d.txt", "w+");
	fp6 = fopen("n.txt", "w+");
	fp8 = fopen("w.txt", "w+");
	fp9 = fopen("s.txt", "w+");
	node2 *st2;
	init(&q);
	init1(&q1);
	init2(&q2);
	char a[48];
	char br[32];
	int m, posi, choice, roll, size, s1, s2, s3, s4, num, posii, yr, MIS;
	while(1) {
		choice = printmenu();
		switch(choice) {
			case 1 :
				printf("\nEnter the Name, MIS, Branch, Year of student and the MIS before which you wish to insert the record :\n");
				scanf(" %[^\n]%d%s%d%d", a, &m, br, &yr, &posi);
				Add(&q, a, m, br, posi, yr, fp);
				print(&q);
				break;
			case 2 :
				printf("Enter the MIS of the student record to be deleted :\n");
				scanf("%d", &posii);
				if(pt = delet(&q, posii,fp,fp4)) {
					printf("Name:%s\n MIS:%d\n Branch:%s\n Year :%d\n", pt->name, pt->MIS, pt->branch, pt->year);
				}
				else {
					printf("INVALID ENTRY\n");
				}
				print(&q);
				break;
			case 3 :
				printf("Enter the MIS of student :\n");
				scanf("%d", &roll);
				if(ptr = search(&q, roll)) {

					printf("\nName :%s\tMIS :%d\tBranch :%s\tYear :%d\n", ptr->name, ptr->MIS, ptr->branch, ptr->year);

				}
				else {

					printf("\nRECORD NOT FOUND\n");
				}
				print(&q);
				break;
			case 4 :
				printf("Enter the Name, MIS, Branch, Year of student :\n");
				scanf(" %[^\n]%d%s%d", a, &m, br, &yr);
				append(&q, a, m, br, yr, fp);
				print(&q);
				break;
			case 5 :
				size = length(&q);
				printf("no of student record(academic) : %d\n", size);
				break;
			case 6 :
				printf("Enter the MIS of student :\n");
				scanf("%d", &roll);
				creatingID(&q, roll);
				break;
			case 7 :
				insertfromfile(&q, fp3, fp);
				print(&q);
				break;
			case 8 :
				printf("Enter the Name, MIS, Branch and Year of student:\n");
				scanf(" %[^\n]%d%s%d", a, &m, br, &yr);
				Modify(&q, m, a, br, yr, fp, fp6);
				print(&q);
				break;
			case 9 :
				num = length1(&q1);
				printf("no of students who appeared for final exam : %d\n", num);
				break;
			case 10 :
				printf("Enter MIS, T1 marks of 4 subjects ,MIS before which you wish to enter the record and the semester :\n");
				scanf("%d%d%d%d%d%d%d",&roll,&s1,&s2,&s3,&s4,&m, &i);
				T1Marks(&q1,roll,s1,s2,s3,s4,m,i); 
				printT1(&q1, i);
				break;	
			case 11 :
				printf("Enter MIS and T2 marks of 4 subjects and the semester :\n");
				scanf("%d%d%d%d%d%d",&roll,&s1,&s2,&s3,&s4, &i);
				T2Marks(&q1,roll,s1,s2,s3,s4,i);
				printT2(&q1, i);
				break;
			case 12 :
				printf("Enter MIS and ESE marks of 4 subjects and the semester :\n");
				scanf("%d%d%d%d%d%d",&roll,&s1,&s2,&s3,&s4,&i);
				ESEMarks(&q1,roll,s1,s2,s3,s4,i);
				printESE(&q1, i);
				break;
			case 13 :
				printf("Enter the MIS and the semester :\n");
				scanf("%d%d", &MIS, &i);
				Total(&q1, MIS,i, fp1);
				printTOT(&q1, i);
				break;
			case 14 :
				printf("Enter the Name, MIS, Mobile no., Email Id of student and the MIS before which you wish to insert the record :\n");
				scanf(" %[^\n]%d%d%s%d", a, &m, &yr, br, &posi);
				Add2(&q2, a, m, yr, br, posi, fp2);
				print2(&q2);
				break;
			case 15 : 
				printf("Enter the MIS of the student record to be deleted :\n");
				scanf("%d", &posii);
				if(pt2 = delet2(&q2, posii,fp2, fp9)) {
					printf("Name:%s\n MIS:%d\n Mobile No:%d\n Email Id :%s\n", pt2->name, pt2->MISS, pt2->mobile, pt2->email_Id);
				}
				else {
					printf("INVALID ENTRY\n");
				}
				print2(&q2);
				break;
			case 16 :
				printf("Enter the MIS of student :\n");
				scanf("%d", &roll);
				if(ptr2 = search2(&q2, roll)) {

					printf("\nName :%s\tMIS :%d\tMobile No :%d\tEmail Id :%s\n", ptr2->name, ptr2->MISS, ptr2->mobile, ptr2->email_Id);
				}
				else {

					printf("\nRECORD NOT FOUND\n");
				}
				print2(&q2);
				break;	
			case 17 :
				printf("Enter the Name, MIS, Mobile no. and Email Id of student:\n");
				scanf(" %[^\n]%d%d%s", a, &m, &yr, br);
				Modify2(&q2, m, a, yr, br,fp2, fp8);
				print2(&q2);
				break;
			case 18 :
				printf("\nEnter the MIS of the student and the semester :\n");
				scanf("%d%d", &m, &s);
				link(&q, &q1, &q2, m, s);
				break;
			case 19 :
				fclose(fp);
				fclose(fp1);
				fclose(fp2);
				fclose(fp3);
				fclose(fp4);
				fclose(fp6);
				fclose(fp8);
				fclose(fp9);
				exit(1);
				break;
		}
	}
}
