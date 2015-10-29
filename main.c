#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "data.h"
int printmenu() {
	int choice;
	printf("\n......................STUDENT RECORD.........................\n"\
	"\n1 : Add student record\n"\
	"2 : Delete student record\n"\
	"3 : Search a record\n"\
	"4 : Append a record to the list\n"\
	"5 : Find number of students in student records list\n"\
	"6 : Creating Id\n"\
	"7 : Read student record from file and add it\n"\
	"8 : Modify a record\n"\
	"9 : number of students who appeared for exam\n"\
	"10 : sort total\n"\
	"11 : T1 marks\n"\
	"12 : T2 marks\n"\
	"13 : ESE marks\n"\
	"14 : Total marks\n"\
	"15 : Add personal record\n"\
	"16 : Delete personal record\n"\
	"17 : Search personal record\n"\
	"18 : Modify personal record\n"\
	"19 : Exit\n"\
	"..............................................................\n");
	scanf("%d", &choice);
	return choice;
}
int main(int argc, char *argv[]) {
	int i;
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
	fp = fopen("k.txt", "w");
	fp1 = fopen("b.txt", "w");
	fp2 = fopen("c.txt", "w");
	fp3 = fopen("a.txt","r");
	node2 *st2;
	init(&q);
	init1(&q1);
	init2(&q2);
	char a[32];
	char br[16];
	int m, posi, choice, roll, size, s1, s2, s3, s4, num, posii;
	int yr, MIS;
	while(1) {
		choice = printmenu();
		switch(choice) {
			case 1 :
				printf("Enter the name, MIS, Branch, Year of student and the MIS before which you wish to insert the record :\n");
				scanf(" %[^\n]%d%s%d%d", a, &m, br, &yr, &posi);
				Add(&q, a, m, br, posi, yr, fp);
				print(&q);
				break;
			case 2 : 
				printf("Enter the MIS of the student record to be deleted :\n");
				scanf("%d", &posii);
				if(pt = delet(&q, posii)) {
					printf("name:%s\n MIS:%d\n branch:%s\n Year :%d\n", pt->name, pt->MIS, pt->branch, pt->year);
				}
				else {
					printf("RECORD LIST EMPTY\n");
				}
				print(&q);
				break;
			case 3 :
				printf("Enter the MIS of student :\n");
				scanf("%d", &roll);
				if(ptr = search(&q, roll)) {

					printf("\nname :%s\tMIS :%d\tbranch :%s\tYEAR :%d\n", ptr->name, ptr->MIS, ptr->branch, ptr->year);

				}
				else {

					printf("\nRECORD NOT FOUND\n");
				}
				print(&q);
				break;
			case 4 :
				printf("Enter the name, MIS, Branch, Year of student :\n");
				scanf(" %[^\n]%d%s%d", a, &m, br, &yr);
				append(&q, a, m, br, yr, fp);
				print(&q);
				break;
			case 5 :
				size = length(&q);
				printf("no of students : %d\n", size);
				break;
			case 6 :
				printf("Enter the MIS of student :\n");
				scanf("%d", &roll);
				creatingID(&q, roll);
				break;
			case 7 :
				insertfromfile(&q, fp3);
				print(&q);
				break;
			case 8 :
				printf("Enter the Name, MIS, Branch and Year of student:\n");
				scanf(" %[^\n]%d%s%d", a, &m, br, &yr);
				Modify(&q, m, a, br, yr);
				print(&q);
				break;
			case 9 :
				num = length1(&q1);
				printf("no of students who appeared for final exam : %d\n", num);
				break;
			//case 10 :
				//sort();
				//break;
			case 11 :
				printf("Enter MIS and T1 marks of 4 subjects ,MIS before which you wish to enter the record and the semester :\n");
				scanf("%d%d%d%d%d%d%d",&roll,&s1,&s2,&s3,&s4,&m, &i);
				T1Marks(&q1,roll,s1,s2,s3,s4,m,i);
				printT1(&q1, i);
				break;	
			case 12 :
				printf("Enter MIS and T2 marks of 4 subjects and the semester :\n");
				scanf("%d%d%d%d%d%d",&roll,&s1,&s2,&s3,&s4, &i);
				T2Marks(&q1,roll,s1,s2,s3,s4,i);
				printT2(&q1, i);
				break;
			case 13 :
				printf("Enter MIS and ESE marks of 4 subjects and the semester :\n");
				scanf("%d%d%d%d%d%d",&roll,&s1,&s2,&s3,&s4,&i);
				ESEMarks(&q1,roll,s1,s2,s3,s4,i);
				printESE(&q1, i);
				break;
			case 14 :
				printf("Enter the MIS and the semester :\n");
				scanf("%d%d", &MIS, &i);
				Total(&q1, MIS,i, fp1);
				printTOT(&q1, i);
				break;
			case 15 :
				printf("Enter the Name, MIS, Mobile no., Address of student and the MIS before which you wish to insert the record :\n");
				scanf(" %[^\n]%d%d%s%d", a, &m, &yr, br, &posi);
				Add2(&q2, a, m, yr, br, posi, fp2);
				print2(&q2);
				break;
			case 16 : 
				printf("Enter the MIS of the student record to be deleted :\n");
				scanf("%d", &posii);
				if(pt2 = delet2(&q2, posii)) {
					printf("name:%s\n MIS:%d\n mobile:%d\n address :%s\n", pt2->name, pt2->MISS, pt2->mobile, pt2->address);
				}
				else {
					printf("RECORD LIST EMPTY\n");
				}
				print2(&q2);
				break;
			case 17 :
				printf("Enter the MIS of student :\n");
				scanf("%d", &roll);
				if(ptr2 = search2(&q2, roll)) {

					printf("\nname :%s\tMIS :%d\tmobile :%d\taddress :%s\n", ptr2->name, ptr2->MISS, ptr2->mobile, ptr2->address);
				}
				else {

					printf("\nRECORD NOT FOUND\n");
				}
				print2(&q2);
				break;	
			case 18 :
				printf("Enter the Name, MIS, Mobile no. and Address of student:\n");
				scanf(" %[^\n]%d%d%s", a, &m, &yr, br);
				Modify2(&q2, m, a, yr, br);
				print2(&q2);
				break;
			case 19 :
				fclose(fp);
				fclose(fp1);
				fclose(fp2);
				fclose(fp3);
				exit(1);
				break;
		}
	}
}
