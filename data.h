typedef struct record {
	char *name;
	int MIS;
	char *branch;
	int year;
	
}record;
typedef struct marks {
	int MIS;
	int sub1;
	int sub2;
	int sub3;
	int sub4;
	int total;
}marks;
typedef struct node {
	struct node *next, *prev;
	record d;
}node;
typedef struct nnode {
	struct nnode *nnext, *pprev;
	marks v;
}nnode;
typedef struct list {
	struct node *head, *tail;
	int length;
}list;
typedef struct listt {
	struct nnode *headd, *taill;
	int lengthh;
}listt;
void init(list *l);
void initt(listt *ll);
void print(list *l);
void printt(listt *ll);
void Add(list *l, char *name, int MIS, char *branch, int year, int pos);
record *delet(list *l, int pos);
record *search(list *l, int MIS);
void Modify(list *l, int MIS, char *name, char *branch, int year);
void append(list *l, char *name, int MIS, char *branch, int year);
int length(list *l);
int lengthh(listt *ll);
void creatingID(list *l, int MIS);
//void InsertFromFile(list *l, char *fname);
void totalmarks(listt *ll, list *l, int MIS, int sub1, int sub2, int sub3, int sub4, int poss);
//void sort(listt *ll);
