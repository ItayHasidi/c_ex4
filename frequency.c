#include <stdio.h>
#include <stdlib.h>  
#include <stdlib.h>
#include <string.h>  
#include "trie.h" 
#define NUM_LETTERS ((int)26)

char myWord[256];
char *pMyWord = &(myWord[0]);
int counter = -1;

void printRec(char* str, struct node* head){
    char temp[1] = {head->letter};
    counter++;
    strcat(myWord, temp);
    if(head->count > 0){
        printf("%s %ld\n", myWord, head->count);
    }
    for (int i = 0; i < 26; i++)
    {
        if(head->children[i] != NULL){
            printRec(++str, head->children[i]);
        }
    }
    myWord[counter] = '\0';
    counter--;
    deleteFromTrie(head);
}

void printRecR(char* str, struct node* head){
     char temp[1] = {head->letter};
    counter++;
    strcat(myWord, temp);
    if(head->count > 0){
        printf("%s %ld\n", myWord, head->count);
    }
    for (int i = 0; i < 26; i++)
    {
        if(head->children[25-i] != NULL){
            printRecR(++str, head->children[25-i]);
        }
    }
    myWord[counter] = '\0';
    counter--;
    deleteFromTrie(head);
}

int main(int argc, char const *argv[])
{
    char word[256];
    bzero(word, 256);
    struct node* trie = mainTrie();
    // printf("%d\n",*argv[1]);
    for (int i = 0; i < 26; i++)
    {
        // printf("here %d\n",argc);
        if(argc > 1 && *argv[1] == 'r'){
            if(trie->children[25 - i] != NULL){
                bzero(myWord, 256);
                counter = -1;
                printRecR(&(word[0]), trie->children[25-i]);
            }
        }
        else{
            // printf("here\n");
            if(trie->children[i] != NULL){
                bzero(myWord, 256);
                counter = -1;
                printRec(&(word[0]), trie->children[i]); 
            }
        }
    }
    deleteFromTrie(trie);
    return 0;
}
