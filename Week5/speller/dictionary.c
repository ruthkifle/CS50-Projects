// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;
int word_count = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_value = hash(word);
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function

    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // Open dictionarty file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Error while opening file\n");
        return false;
    }

    // Read strings from file one at a time
    char buffer[LENGTH];

    while (fscanf(dict, "%s", buffer) != EOF)
    {
        // Create a new node for each word
        node *nword = malloc(sizeof(node));

        // Hash word to obtain a hash value
        int hash_value = hash(buffer);

        // Insert node into hash table at the locationfread (1, 4, dict)
        strcpy(nword->word, buffer);
        nword->next = table[hash_value];
        table[hash_value] = nword;
        word_count++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        node *curser = table[i];

        while (curser != NULL)
        {
            curser = curser->next;
            free(temp);
            temp = curser;
        }
    }
    return true;
}
