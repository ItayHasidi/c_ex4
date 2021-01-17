#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include "trie.h"
#define WORD 256
#define NUM_LETTERS ((int)26)
int count = 0;
int *pCount = &count;
char cha;
int flag = 1;
char word[WORD] = {0}; // 256 is the length of the word, possibly it's longer and needs to be changed.
// typedef struct node {
//     char letter;
//     long unsigned int count;
//     struct node* children[NUM_LETTERS];
// }
struct node nodeTrie; 

/**
 * Gets a pointer to the trie head and a word and inserts it to the trie.
 * if the word existed the func will add 1 to the counter of the word.
 */
void* addToTrie(struct node *parent, char *word){
    
    struct node *p = parent;
    for (int i = 0; i < count; i++){
        // printf("%c %c\n",*word, *(word + i) - 97);
        if(p->children[*(word + i) - 97] == NULL){// TODO check if the are really NULL
            // printf("%c %d\n",*word, *(word + i)-97);
            struct node *temp = (struct node*) malloc(sizeof(struct node));
            if(temp == NULL){
                printf("malloc error!\n");
                // return -1;
            } 
            temp->letter = *(word + i);
            temp->count = 0;
            // printf("letter: %c, count: %ld\n",temp->letter, temp->count);
            p->children[*(word + i) - 97] = temp;
            p = temp;
        }
        else{
            p = p->children[*(word + i) - 97];
        }
    }
    p->count++;
    // return 0;
}

/**
 * Deletes the node from the trie. 
 */
void deleteFromTrie(struct node* head){
    free(head);
}

/**
 * Gets a word from the standard input and returns it as a string.
 * Also changes all upper case words to lower case. 
 */
char* nextWord(){
    char c = getchar();
    
    char* pWord = &(word[0]);
    count = 0;
    // printf("here %c\n",c);
    while (c > 32)
    {
        if(c >= 65 && c <= 90){
            c += 32;
        }
        if(c >= 97 && c <= 122){
            *(pWord + count) = c;
            count++;
            // printf("%d\n",count);
        }
        
        c = getchar();
        // printf("here %c\n",c);
        if(c < 32 && c != 9 && c != 10){
            printf("error\n");
            flag = 0;
        }
    }
    // printf("exited\n");
    return pWord;
}

struct node* mainTrie()
{
    struct node *head = (struct node*) malloc(sizeof(struct node));
    if(head == NULL){
        printf("malloc error!\n");
        return NULL;
    } 
    head->letter;
    head->count = 0;
    // printf("enter words:\n");
    char *c = nextWord();
    // printf("%s\n",word);
    // printf("first word\n");
    while(count > 0){
        addToTrie(head, c);
        if(flag){
            bzero(word, WORD);
            c = nextWord();
            // printf("%s\n",word);
            // printf("%d\n",*pCount);
            // for (int i = 0; i < count; i++)
            // {
            //     printf("%c",*(c+i));
            // }
        }
        else{
            break;
        }
    }
    return head;
}

/**
 * Checks if the node has childern, if yes returns 0 else returns 1;
 */
int hasChildren(struct node* head){
    int res = 1;
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if(head->children[i] != NULL)
        {
            res = 0;
            break;
        }
        return res;
    }
    
}