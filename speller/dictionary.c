/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

#define SIZE 143091



/**
 * Loads dictionary into memory. Returns true if successful else false.
 */

// Create a node structure to enter data into hash table. 
struct node
{
    char word[LENGTH+1];
    struct node *next;
};

struct hash
{
    struct node *head;
    int count;
};

struct hash *hashTable = NULL;

struct node * createNode(char *word)
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        free(newnode);
        return false;
    }
    strcpy(newnode->word, word);
    newnode->next = NULL;
    return newnode;
}

unsigned long hash( const char *word)
{
    unsigned long hash = 5381;
    int c;
    while((c = *word++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

void insertToHash(char *word)
{
  
    int key = hash(word);
    key = abs(key);
    int hashIndex = key % SIZE;
    struct node *newnode = createNode(word);
    if(!hashTable[hashIndex].head)
    {
        hashTable[hashIndex].head = newnode;
        hashTable[hashIndex].count = 1;
        return;
    }
    newnode->next = (hashTable[hashIndex].head);
    hashTable[hashIndex].head = newnode;
    hashTable[hashIndex].count++;
    return;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    
    int key = hash(word);
    key = abs(key);
    int hashIndex = key % SIZE;
    while(hashTable[hashIndex].head != NULL)
    {
        if(strcasecmp(hashTable[hashIndex].head->word, word) == 0)
            return true;
        hashTable[hashIndex].head = hashTable[hashIndex].head->next;
    }
    return false;
}

bool load(const char *dictionary)
{
    // TODO
    
    printf("Starting load...\n");
    hashTable = (struct hash *) calloc(SIZE, sizeof(struct hash));
    FILE *inptr = fopen(dictionary, "r");
    char word[LENGTH+1];
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", dictionary);
        return false;
    }
    while(fscanf(inptr, "%s", word) != EOF)
    {
        insertToHash(word);
    }
    printf("Load function success...hopefully...\n");
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    int n = SIZE;
    return n;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    printf("Unloading dictionary...\n");
    for(int i = 0; i < SIZE; i++)
    {
        if(hashTable[i].count > 0)
        {
            while(hashTable[i].head != NULL)
            {
                struct node *temp = hashTable[i].head;
                hashTable[i].head = hashTable[i].head->next;
                hashTable[i].count--;
                free(temp);
            }
        }
    }
    printf("Unloading success...\n");
    return true;
}
