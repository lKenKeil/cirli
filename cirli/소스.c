#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 리스트의 머리 노드를 가리키는 포인터
Node* head = NULL;

// 리스트에 새로운 노드 추가 함수
void appendNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    }
    else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }

    printf("노드에 %d을(를) 추가했습니다.\n", value);
}

// 리스트의 처음 노드 삭제 함수
void deleteFirstNode() {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    Node* temp = head;
    head = head->next;
    current->next = head;
    free(temp);

    printf("처음 노드를 삭제했습니다.\n");
}

// 리스트의 마지막 노드 삭제 함수
void deleteLastNode() {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current->next != head) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        // 리스트에 노드가 하나만 있는 경우
        free(current);
        head = NULL;
    }
    else {
        previous->next = head;
        free(current);
    }

    printf("마지막 노드를 삭제했습니다.\n");
}

// 리스트 출력 함수
void printList() {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    Node* current = head;
    printf("리스트의 노드들: ");

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n메뉴\n");
        printf("(1) 숫자 입력 받아서 리스트 처음에 추가\n");
        printf("(2) 숫자 입력 받아서 리스트 마지막에 추가\n");
        printf("(3) 리스트 처음 노드 삭제\n");
        printf("(4) 리스트 마지막 노드 삭제\n");
        printf("(5) 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &value);
            appendNode(value);
            printList();
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
            scanf("%d", &value);
            appendNode(value);
            printList();
            break;
        case 3:
            deleteFirstNode();
            printList();
            break;
        case 4:
            deleteLastNode();
            printList();
            break;
        case 5:
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
