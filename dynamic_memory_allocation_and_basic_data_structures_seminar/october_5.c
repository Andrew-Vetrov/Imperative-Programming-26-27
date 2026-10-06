#include <stdio.h>
#include <stdlib.h>

#define TYPE int // используем для обобщения типа

// во всех функциях нет проверки на возможное отсутствие свободной памяти при аллокации,
// а также на валидность передаваемого внутрь функций указателя на структуру данных



// не реализованы функции вставки и удаления элемента из произвольной позиции в векторе
typedef struct
{
    TYPE* arr;
    int size, cap;
} vector;

typedef struct
{
    int* arr;
    int next, last;
} queue;

typedef struct
{
    TYPE* arr;
    int size;
} stack;

vector* init_vector(int capacity)
{
    vector* result = (vector*)malloc(sizeof(vector));

    result->size = 0;
    result->cap = capacity;
    result->arr = (TYPE*)malloc(result->cap * sizeof(TYPE));

    return result;
}


void push_back(vector* vec, TYPE elem)
{
    if (vec->size == vec->cap)
    {
        vec->cap *= 2;
        vec->arr = (TYPE*)realloc(vec->arr, vec->cap * sizeof(TYPE));
    }

    vec->arr[vec->size++] = elem;
}


// нет проверки на валидность значения индекса
TYPE get_elem(vector* vec, int index)
{
    return vec->arr[index];
}

TYPE pop_vector(vector* vec)
{
    return vec->arr[--vec->size];
}

void destroy_vector(vector* vec)
{
    free(vec->arr);
    free(vec);
}

queue* init_queue(int capacity)
{
    queue* result = (queue*)malloc(sizeof(queue));

    result->next = 0;
    result->last = 0;
    result->arr = (TYPE*)malloc(capacity * sizeof(TYPE));

    return result;
}

// нет проверки на то, что в очереди находится максимум элементов
void enqueue(queue* q, TYPE elem)
{
    q->arr[q->last++] = elem;
}

// нет проверки на пустую очередь
TYPE dequeue(queue* q)
{
    return q->arr[q->next++];
}

int get_queue_size(queue* q)
{
    return q->last - q->next;
}

void destroy_queue(queue* q)
{
    free(q->arr);
    free(q);
}

stack* init_stack(int capacity)
{
    stack* result = (stack*)malloc(sizeof(stack));

    result->size = 0;
    result->arr = (TYPE*)malloc(capacity * sizeof(TYPE));

    return result;
}

// нет проверки на то, что в стеке находится максимум элементов
void push_stack(stack* st, TYPE elem)
{
    st->arr[st->size++] = elem;
}

// нет проверки на пустой стек
TYPE pop_stack(stack* st)
{
    return st->arr[--st->size];
}

void destroy_stack(stack* st)
{
    free(st->arr);
    free(st);
}

int main()
{
    vector* vec = init_vector(2);
    for (int i = 0; i < 10; i++)
        push_back(vec, i);

    for (int i = 0; i < 10; i++)
        printf("%d ", pop_vector(vec));
    printf("\n");

    destroy_vector(vec);

    return 0;
}
