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
	"5 : Find number of students\n"\
	"6 : Creating Id\n"\
	"7 : Read student record from file\n"\
	"8 : Modify a record\n"\
	"9 : Find total marks\n"\
	"10 : Find number of students who appeared for exam\n"\
	"..............................................................\n");
	scanf("%d", &choice);
	return choice;
}
int main(int argc, char *argv[]) {
	list q;
	FILE *fp;
	listt qq;
	record d;
	marks v;
	record *ptr, *pt;
	init(&q);
	initt(&qq);
	char a[32];
	char br[16];
	int m, posi, choice, roll, size, s1, s2, s3, s4, num;
	int yr;
	while(1) {
		print(&q);
		choice = printmenu();
		switch(choice) {
			case 1 :
				scanf("%[^\n] %d %s %d %d", a, &m, br, &posi, &yr);
				Add(&q, a, m, br, yr, posi);
				break;
			case 2 : 
				scanf("%d", &posi);
				if(delet(&q, posi)) {
					pt = delet(&q, posi);
					printf("name:%s\n MIS:%d\n branch:%s\n Year :%d\n", pt->name, pt->MIS, pt->branch, pt->year);
				}
				else {
					printf("RECORD LIST EMPTY");
				}
				break;
			case 3 :
				scanf("%d", &roll);
				if(ptr = search(&q, roll)) {
					printf("\nname :%s\tMIS :%d\tbranch :%s\tYEAR :%d\n", ptr->name, ptr->MIS, ptr->branch, ptr->year);
				}
				else {
					printf("\nRECORD NOT FOUND\n");
				}
				break;
			case 4 :
				scanf("%[^\n] %d %s %d", a, &m, br, &yr);
				append(&q, a, m, br, yr);
				break;
			case 5 :
				size = length(&q);
				printf("no of students : %d\n", size);
				break;
			case 6 :
				scanf("%d", &roll);
				creatingID(&q, roll);
				break;
			/*case 7 :
				fp = fopen(argv[1], "r");
				scanf("%d", &posi);
				fscanf(fp, d.name, d.MIS, d.branch, d.year);
				Add(&q, d.name, d.MIS, d.branch, posi, d.year);
				break;*/
			case 8 :
				scanf("%[^\n] %d %s %d", a, &m, br, &yr);
				Modify(&q, m, a, br, yr);
				break;
			case 9 :
				scanf(" %d %d %d %d %d %d", &m, &s1, &s2, &s3, &s4, &posi);
				totalmarks(&qq, &q, m, s1, s2, s3, s4, posi);
				printt(&qq);
				break;
			case 10 :
				num = lengthh(&qq);
				printf("no of students who appeared foe exam : %d\n", num);
				break;
			/*case 11 :
				sort(&qq);
				printt(&qq);*/			
		}
	}
}
