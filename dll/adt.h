struct listAdt{
  char val;
  struct listAdt *pre;
  struct listAdt *nxt;
};

struct listAdt* insertFront(struct listAdt *l,char c);
void insertEnd(struct listAdt *l,char c);
void insertMiddle(struct listAdt *l,char c,char d);
void display(struct listAdt *l);
void deleteItem(struct listAdt **l,char c);
int searchItem(struct listAdt *l,char c);
void isPalindrome(struct listAdt *h);
void sep(struct listAdt *h);
void swaps(struct listAdt *h,int k);