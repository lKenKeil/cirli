#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// ����Ʈ�� �Ӹ� ��带 ����Ű�� ������
Node* head = NULL;

// ����Ʈ�� ���ο� ��� �߰� �Լ�
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

    printf("��忡 %d��(��) �߰��߽��ϴ�.\n", value);
}

// ����Ʈ�� ó�� ��� ���� �Լ�
void deleteFirstNode() {
    if (head == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
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

    printf("ó�� ��带 �����߽��ϴ�.\n");
}

// ����Ʈ�� ������ ��� ���� �Լ�
void deleteLastNode() {
    if (head == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current->next != head) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        // ����Ʈ�� ��尡 �ϳ��� �ִ� ���
        free(current);
        head = NULL;
    }
    else {
        previous->next = head;
        free(current);
    }

    printf("������ ��带 �����߽��ϴ�.\n");
}

// ����Ʈ ��� �Լ�
void printList() {
    if (head == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }

    Node* current = head;
    printf("����Ʈ�� ����: ");

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n�޴�\n");
        printf("(1) ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
        printf("(2) ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
        printf("(3) ����Ʈ ó�� ��� ����\n");
        printf("(4) ����Ʈ ������ ��� ����\n");
        printf("(5) ����\n");
        printf("�޴� ����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf("%d", &value);
            appendNode(value);
            printList();
            break;
        case 2:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
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
            printf("�߸��� �����Դϴ�. �ٽ� �Է��ϼ���.\n");
        }
    }

    return 0;
}
