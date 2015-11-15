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
int printmenu() {
	int choice;
	printf("\n	......................STUDENT DATA MANAGEMENT.........................\n"\
	"\n		   1 : Add student's academic record\n"\
	"		   2 : Delete student's academic record\n"\
	"		   3 : Search a student's academic record\n"\
	"		   4 : Append a student's academic record to the list\n"\
	"		   5 : Find number of students in student's academic records list\n"\
	"		   6 : Create Id\n"\
	"		   7 : Read student's academic record from file and add it\n"\
	"		   8 : Modify a students's academic record\n"\
	"		   9 : Find number of students who appeared for exam\n"\
	"		   10 : Add T1 marks of a student for a particular semester\n"\
	"		   11 : Add T2 marks of a student for a particular semester\n"\
	"		   12 : Add ESE marks of a student for a particular semester\n"\
	"		   13 : Find Total marks of a student for a particular semester\n"\
	"		   14 : Add student's personal record\n"\
	"		   15 : Delete student's personal record\n"\
	"		   16 : Search student's personal record\n"\
	"		   17 : Modify student's personal record\n"\
	"		   18 : display all details of the student for a particular semester\n"\
	"		   19 : Read student's personal record from file and add it\n"\
	"		   20 : Exit\n"\
	"	...........................................................................\n");
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
	FILE *fp, *fp1, *fp2, *fp3, *fp4, *fp6, *fp8, *fp9, *fp10;
	fp1 = fopen("b.txt", "a+");
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
				printf("\nEnter the Name, MIS, Branch, Year of student and the MIS before which you wish to insert the record :\n");  /*if it is the first record 'posi' can be anything*/
				scanf(" %[^\n]%d%s%d%d", a, &m, br, &yr, &posi);
				fp = fopen("k.txt", "a+");
				Add_academic(&q, a, m, br, posi, yr, fp);
				fclose(fp);
				print(&q);
				break;
			case 2 :
				printf("Enter the MIS of the student record to be deleted :\n");
				scanf("%d", &posii);
				fp = fopen("k.txt", "a+");
				fp4 = fopen("d.txt", "w+");
				if(pt = delet_academic(&q, posii,fp,fp4)) {
					printf("Name:%s\n MIS:%d\n Branch:%s\n Year :%d\n", pt->name, pt->MIS, pt->branch, pt->year);
				}
				else {
					printf("INVALID ENTRY\n");
				}
				print(&q);
				fclose(fp);
				fclose(fp4);
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
				break;
			case 4 :
				printf("Enter the Name, MIS, Branch, Year of student :\n");
				scanf(" %[^\n]%d%s%d", a, &m, br, &yr);
				fp = fopen("k.txt", "a+");
				append_academic(&q, a, m, br, yr, fp);
				print(&q);
				fclose(fp);
				break;
			case 5 :
				size = length(&q);
				printf("Number of student records(academic) : %d\n", size);
				break;
			case 6 :
				printf("Enter the MIS of student :\n");
				scanf("%d", &roll);
				creatingID(&q, roll);
				break;
			case 7 :
				fp = fopen("k.txt", "a+");
				fp3 = fopen("a.txt", "r");
				academicfromfile(&q, fp3, fp);
				print(&q);
				fclose(fp);
				fclose(fp3);
				break;
			case 8 :
				printf("Enter the Name, MIS, Branch and Year of student:\n");
				scanf(" %[^\n]%d%s%d", a, &m, br, &yr);  /*MIS should be same*/
				fp = fopen("k.txt", "a+");
				fp6 = fopen("n.txt", "w+");
				Modify_academic(&q, m, a, br, yr, fp, fp6); 
				print(&q);
				fclose(fp);
				fclose(fp6);
				break;
			case 9 :
				num = length1(&q1);
				printf("No of students who appeared for final exam : %d\n", num);
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
				printf("Enter the Name, MIS, Mobile no., Email Id of student and the MIS before which you wish to insert the record :\n");  /*if it is the first record, posi can be anything*/
				scanf(" %[^\n]%d%d%s%d", a, &m, &yr, br, &posi);
				fp2 = fopen("c.txt", "a+");
				Add2_personal(&q2, a, m, yr, br, posi, fp2);
				print2(&q2);
				fclose(fp2);
				break;
			case 15 : 
				printf("Enter the MIS of the student record to be deleted :\n");
				scanf("%d", &posii);
				fp2 = fopen("c.txt", "a+");
				fp9 = fopen("s.txt", "w+");
				if(pt2 = delet2_personal(&q2, posii,fp2, fp9)) {
					printf("Name:%s\n MIS:%d\n Mobile No:%d\n Email Id :%s\n", pt2->name, pt2->MISS, pt2->mobile, pt2->email_Id);
				}
				else {
					printf("INVALID ENTRY\n");
				}
				print2(&q2);
				fclose(fp2);
				fclose(fp9);
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
				break;	
			case 17 :
				printf("Enter the Name, MIS, Mobile no. and Email Id of student:\n");
				scanf(" %[^\n]%d%d%s", a, &m, &yr, br);  /*MIS should be same*/
				fp8 = fopen("w.txt", "w+");
				fp2 = fopen("c.txt", "a+");
				Modify2_personal(&q2, m, a, yr, br,fp2, fp8);
				print2(&q2);
				fclose(fp2);
				fclose(fp8);
				break;
			case 18 :
				printf("\nEnter the MIS of the student and the semester :\n");
				scanf("%d%d", &m, &s);
				link(&q, &q1, &q2, m, s);
				break;
			case 19 :
				fp2 = fopen("c.txt", "a+");
				fp10 = fopen("p.txt", "r");
				personalfromfile(&q2, fp10, fp2);
				print2(&q2);
				fclose(fp2);
				fclose(fp10);
				break;
			case 20 :
				fclose(fp1);
				exit(1);
				break;
		}
	}
}
