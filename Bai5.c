#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 5

// Cau truc de luu tru mot phan tu trong hang doi uu tien
typedef struct {
    int priority;
    char data[50];
} Element;

// Cau truc cua hang doi uu tien
typedef struct {
    Element elements[MAX];
    int size;
} PriorityQueue;

// Khoi tao hang doi uu tien rong
void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

// Kiem tra hang doi co rong khong
bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

// Them phan tu vao hang doi
void enqueue(PriorityQueue *pq, int priority, const char *data) {
    if (pq->size == MAX) {
        printf("Hang doi day. Khong the them phan tu: (%d, \"%s\")\n", priority, data);
        return;
    }

    // Them phan tu vao cuoi hang doi
    pq->elements[pq->size].priority = priority;
    strcpy(pq->elements[pq->size].data, data);
    pq->size++;

    // Sap xep lai hang doi theo thu tu uu tien giam dan
    for (int i = pq->size - 1; i > 0; i--) {
        if (pq->elements[i].priority < pq->elements[i - 1].priority) {
            // Hoan doi
            Element temp = pq->elements[i];
            pq->elements[i] = pq->elements[i - 1];
            pq->elements[i - 1] = temp;
        }
    }

    printf("Them phan tu (%d, \"%s\"): Hang doi khong rong\n", priority, data);
}

// Lay phan tu co uu tien cao nhat ra khoi hang doi
void dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong. Khong the lay phan tu.\n");
        return;
    }

    // Lay phan tu dau hang doi (uu tien cao nhat)
    Element highestPriorityElement = pq->elements[0];

    // Dich cac phan tu con lai len dau
    for (int i = 0; i < pq->size - 1; i++) {
        pq->elements[i] = pq->elements[i + 1];
    }
    pq->size--;

    printf("Lay ra phan tu: \"%s\" (uu tien %d)\n", highestPriorityElement.data, highestPriorityElement.priority);
}

// In trang thai hien tai cua hang doi
void printQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Hang doi rong.\n");
        return;
    }

    printf("Trang thai hien tai cua hang doi: \n");
    for (int i = 0; i < pq->size; i++) {
        printf("(%d, \"%s\") ", pq->elements[i].priority, pq->elements[i].data);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    int choice;
    do {
        printf("\n---------------------MENU-------------------\n");
        printf("1. Them phan tu vao hang doi\n");
        printf("2. In trang thai hang doi\n");
        printf("3. Lay phan tu uu tien cao nhat ra khoi hang doi\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int priority;
                char data[50];
                printf("Nhap uu tien: ");
                scanf("%d", &priority);
                printf("Nhap du lieu: ");
                scanf("%s", data);
                enqueue(&pq, priority, data);
                break;
            }
            case 2:
                printQueue(&pq);
                break;
            case 3:
                dequeue(&pq);
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}

