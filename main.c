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
	/*"7 : Read student record from file\n"\*/
	"..............................................................\n");
	scanf("%d", &choice);
	return choice;
}
int main() {
	list q;
	record d;
	record *ptr, *pt;
	init(&q);
	char a[32];
	char br[16];
	int m, posi, choice, roll, size;
	while(1) {
		print(&q);
		choice = printmenu();
		switch(choice) {
			case 1 :
				scanf("%s %d %s %d", a, &m, br, &posi);
				Add(&q, a, m, br, posi);
				break;
			case 2 : 
				scanf("%d", &posi);
				pt = delet(&q, posi);
				printf("name:%s\n MIS:%d\n branch:%s\n", pt->name, pt->MIS, pt->branch);
				break;
			case 3 :
				scanf("%d", &roll);
				ptr = search(&q, roll);
				printf("%s %d %s\n", ptr->name, ptr->MIS, ptr->branch);
				break;
			case 4 :
				scanf("%s %d %s", a, &m, br);
				append(&q, a, m, br);
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
				InsertFromFile(&q, argv[1]);
				break;*/

				
		}
	}
}
