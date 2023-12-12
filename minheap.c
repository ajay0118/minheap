#include <stdio.h>

#define MAX_SIZE 100

struct MinHeap {
    int arr[MAX_SIZE];
    int size;
};

void initializeHeap(struct MinHeap *heap) {
    heap->size = 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap *heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->arr[index] < heap->arr[parent]) {
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(struct MinHeap *heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(struct MinHeap *heap, int value) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full! Cannot insert %d\n", value);
    } else {
        heap->arr[heap->size] = value;
        heapifyUp(heap, heap->size);
        heap->size++;
        printf("%d inserted into the heap\n", value);
    }
}

int extractMin(struct MinHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty! Cannot extract minimum\n");
        return -1; // Return an error value
    } else {
        int minValue = heap->arr[0];
        heap->arr[0] = heap->arr[heap->size - 1];
        heap->size--;
        heapifyDown(heap, 0);
        return minValue;
    }
}

void display(struct MinHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
    } else {
        printf("Heap elements: ");
        for (int i = 0; i < heap->size; ++i) {
            printf("%d ", heap->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct MinHeap minHeap;
    initializeHeap(&minHeap);

    int choice, value;

    do {
        printf("1. Insert\n");
        printf("2. Extract Min\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(&minHeap, value);
                break;
            case 2:
                value = extractMin(&minHeap);
                if (value != -1) {
                    printf("Extracted minimum value: %d\n", value);
                }
                break;
            case 3:
                display(&minHeap);
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

