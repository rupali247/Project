/*STUDENT DATA MANAGEMENT SYSTEM*/

/* This code has functions to add student's academic record, delete record, modify record and search record.The record is added, deleted, modified respectively from file also..This code also has functions to add, delete, modify a student's personal record.. The entries are entered manually. The code also has a function to add students' academic records from file directly.. It also has functions to add T1,T2 and ESE marks of four subjects of any semester of a student  and function to find total marks of a student for a particular semester*/

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
	char *address;      /*The address here is a simple character array.eg :Pune, Mumbai,etc*/
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

void init(list *l);       /* initialises list having academic record*/
void init1(list1 *l1);    /* initialises list containing marks of student*/
void init2(list2 *l2);	  /*initialises list having personal record*/
void print(list *l);
void print2(list2 *l2);
void Add(list *l, char *name, int MIS, char *branch, int year, int pos, FILE *fp);
void Add2(list2 *l2, char *name, int MIS, int mobile, char *address, int loc, FILE *fp2);
record *delet(list *l, int pos);
personal *delet2(list2 *l2, int loc);
record *search(list *l, int MIS);
personal *search2(list2 *l2, int MISS);
void Modify(list *l, int MIS, char *name, char *branch, int year);
void Modify2(list2 *l2, int MISS, char *name, int mobile, char *address);
void append(list *l, char *name, int MIS, char *branch, int year, FILE *fp);
int length(list *l);
int lenght1(list1 *l1);
int length2(list2 *l2);
void creatingID(list *l, int MIS); 
void insertfromfile(list *l, FILE *fp3);          /*adds academic record of students from file*/
void T1Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int MI, int sem);
void printT1(list1 *l1, int sem);
void T2Marks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem);
void printT2(list1 *l1, int sem);
void ESEMarks(list1 *l1, int MIS, int m1, int m2, int m3, int m4, int sem);
void printESE(list1 *l1, int sem);
void Total(list1 *l1, int MIS, int sem, FILE *fp1);
void printTOT(list1 *l1, int sem);
