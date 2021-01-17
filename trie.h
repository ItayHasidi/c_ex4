typedef struct node {
    char letter;
    long unsigned int count;
    struct node* children[26];
} node;
int addToTrie(struct node* parent, char *word);
int deleteFromTrie(struct node* head);
char* nextWord();
int hasChildren(struct node* head);
struct node* mainTrie();
