#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define Nil INT_MIN

/* 
* Type Definition 
*/
typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair data[MAX];
    int totEl;
} HashMap;

/**
 * @brief Initialize HashMap
 * 
 */
void init(HashMap *h) {
    for (int i = 0; i < MAX; i++) {
        h->data[i].key = Nil;
        h->data[i].value = Nil;
    }

    h->totEl = 0;  
}

/**
 * @brief Hash function
 * 
 * @param x Key
 * @return int Hash value
 */
int hash(int x) {
    return x % MAX;
}

/**
 * @brief Get the length of the HashMap
 * 
 * @param h HashMap
 * @return int Length
 */
int length(HashMap *h) {
    return h->totEl;
}

/**
 * @brief Insert a new element in the HashMap
 * 
 * @param h HashMap
 * @param key Key
 * @param value Value
 */
void insert(HashMap *h, int key, int value) {

    int i = hash(key);
    while (h->data[i].key != Nil) {
        i = (i + 1) % MAX;
    }

    h->data[i].key = key;
    h->data[i].value = value;
    h->totEl++;
}

/**
 * @brief Delete an element in the HashMap
 *
 * @param h HashMap
 * @param key Key
 */
void delete(HashMap *h, int key)
{

    int i = hash(key);
    while (h->data[i].key != key && h->data[i].key != Nil)
    {
        i = (i + 1) % MAX;
    }

    h->data[i].key = Nil;
    h->data[i].value = Nil;
    h->totEl--;
}

/**
 * @brief Search an element in the HashMap
 * 
 * @param h HashMap
 * @param key Key
 * @return int Value
 */
int search(HashMap *h, int key) {
    int i = hash(key);

    while (h->data[i].key != hash(key) && h->data[i].key != Nil) {
        i = (i + 1) % MAX;
    }

    return h->data[i].value;
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    HashMap h;
    init(&h);

    int target;
    scanf("%d", &target);

    for (int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                insert(&h, i, arr[i]);
                insert(&h, j, arr[j]);

                printf("%d\n%d\n", i, j);
                break;
            }
        }
    }

    return 0;
}