#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// Stack implementation
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, char c) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = c;
}

char pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

bool isBracket(char c) {
    return (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}');
}

bool isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')')
        return true;
    if (opening == '[' && closing == ']')
        return true;
    if (opening == '{' && closing == '}')
        return true;
    return false;
}

bool hasFullBracket(const char* sentence) {
    Stack stack;
    initialize(&stack);

    int length = strlen(sentence);
    for (int i = 0; i < length; i++) {
        char currentChar = sentence[i];
        if (isBracket(currentChar)) {
            if (currentChar == '(' || currentChar == '[' || currentChar == '{') {
                push(&stack, currentChar);
            } else if (currentChar == ')' || currentChar == ']' || currentChar == '}') {
                if (stack.top == -1 || !isMatchingPair(pop(&stack), currentChar)) {
                    return false;
                }
            }
        }
    }

    return stack.top == -1;
}

int main() {
    const char* sentence = "This is a (sample) sentence.";
    if (hasFullBracket(sentence)) {
        printf("The sentence has a full bracket.\n");
    } else {
        printf("The sentence does not have a full bracket.\n");
    }

    return 0;
}
