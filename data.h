typedef struct record {
	char *name;
	int MIS;
	char *branch;
	
}record;
typedef struct node {
	struct node *next, *prev;
	record d;
}node;
typedef struct list {
	struct node *head, *tail;
	int length;
}list;
void init(list *l);
void print(list *l);
void Add(list *l, char *name, int MIS, char *branch, int pos);
record *delet(list *l, int pos);
record *search(list *l, int MIS);
void append(list *l, char *name, int MIS, char *branch);
int length(list *l);
void creatingID(list *l, int MIS);
/*void InsertFromFile(list *l, char *fname);*/

