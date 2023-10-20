#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    char* data;
} Node;

Node* first = NULL;
Node* last = NULL;

void addNode(Node* newNode) {
    newNode->next = NULL;
    if (first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
}

void freeNodes() {
    while (first != NULL) {
        Node* temp = first;
        first = first->next;

        free(temp->data);
        free(temp);
    }
}

int main() {
    char inputBuffer[BUFSIZ];
    while (inputBuffer[0] != '.') {
        char* result = fgets(inputBuffer, BUFSIZ - 1, stdin);
        if (result == NULL) {
            perror("Error while reading string");
            exit(errno);
        }
        size_t length = strlen(inputBuffer);

        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            perror("Can't allocate memory\n");
            exit(ENOMEM);
        }

        newNode->data = malloc(length + 1);
        if (newNode->data == NULL) {
            perror("Can't allocate memory\n");
            exit(ENOMEM);
        }

        memcpy(newNode->data, inputBuffer, length + 1);

        addNode(newNode);
    }

    printf("\n");

    Node* current = first;
    while (current != NULL) {
        printf("%s", current->data);
        current = current->next;
    }

    freeNodes();

    return 0;
}
