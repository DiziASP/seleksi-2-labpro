#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 32

typedef struct Node
{
    int key;
    int value;
} Node;

typedef struct
{
    Node *hashMap[MAX_SIZE];
} HashMap;

HashMap *createHashMap()
{
    HashMap *hashMap = (HashMap *) malloc(sizeof(HashMap));
    for (int i = 0; i < MAX_SIZE; i++)
    {
        hashMap->hashMap[i] = NULL;
    }
    return hashMap;
}

int hash(int key)
{
    return key % MAX_SIZE;
}

void insert(HashMap *hashMap, int key, int value)
{
    int index = hash(key);
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    hashMap->hashMap[index] = node;
}

void remove(HashMap *hashMap, int key)
{
    int index = hash(key);
    if (hashMap->hashMap[index] != NULL)
    {
        hashMap->hashMap[index] = NULL;
    }
}

int getKey(HashMap *hashMap, int key)
{
    int index = hash(key);
    if (hashMap->hashMap[index] == NULL)
    {
        return -1;
    }
    return hashMap->hashMap[index]->value;
}

int getByValue(HashMap *hashMap, int value){
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (hashMap->hashMap[i] != NULL && hashMap->hashMap[i]->value == value)
        {
            return hashMap->hashMap[i]->key;
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);

    HashMap *hashMap = createHashMap();
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        insert(hashMap, i, arr[i]);
    }

    int target;
    scanf("%d", &target);

    for (int i = 0; i < n; i++)
    {
        int firstValue = getKey(hashMap, i);

        for(int j = i + 1; j < n; j++){
            int secondValue = getKey(hashMap, j);
            if(firstValue + secondValue == target){
                printf("%d\n%d\n", i, j);
                break;
            }
        }
    }

    return 0;
}