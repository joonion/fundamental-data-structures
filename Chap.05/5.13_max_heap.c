#include <stdio.h>
#include <stdlib.h>

#define MAX 2048

int heap[MAX];
int size;

void heap_init()
{
    size = 0;
}

void heap_push(int key)
{
    int i = ++size;
    while ((i != 1) && (key > heap[i / 2])) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = key;
}

int heap_pop()
{
    int key, temp, parent, child;
    key = heap[1];
    temp = heap[size--];
    parent = 1, child = 2;
    while (child <= size) {
        if (child < size && heap[child] < heap[child + 1]) 
            child++;
        if (temp >= heap[child])
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return key;
}

int main() 
{
    int i, j, n, *S;
    scanf("%d", &n);
    S = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &S[i]);
    heap_init();
    for (i = 0; i < n; i++) {
        heap_push(S[i]);
        printf("%d(%d):", S[i], size);
        for (j = 1; j <= size; j++)
            printf(" %d", heap[j]);
        printf("\n");
    }
}