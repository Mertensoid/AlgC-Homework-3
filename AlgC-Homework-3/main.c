//
//  main.c
//  AlgC-Homework-3
//
//  Created by admin on 10.07.2022.
//

#include <stdio.h>
#define MaxN 15

void solution1();
void solution2();
void solution3();
void solution4();
//void solution5();
void menu();

int main(int argc, const char * argv[]) {
    menu();
    return 0;
}

void menu() {
    int solutionNumber;
    printf("Choose solution (1..3):\n");
    scanf("%d", &solutionNumber);
    switch (solutionNumber) {
        case 1:
            solution1();
            break;
        case 2:
            solution2();
            break;
        case 3:
            solution3();
            break;
        case 4:
            solution4();
            break;
//        case 5:
//            solution5();
//            break;
        default:
            printf("Wrong solution number!");
            break;
    }
}

void printArr(int *array) {
    printf("Sorted array: ");
    for (int i = 0; i < MaxN; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int bubble(int *array) {
    int count = 0;
    for (int i = 0; i < MaxN; i++) {
        for (int j = 0; j < MaxN - 1; j++) {
            count++;
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                count++;
            }
        }
    }
    return count;
}

int lessOperationsBubble(int *array) {
    int count = 0;
    int n = MaxN;
    count++;
    for (int i = 1; i < MaxN; i++) {
        for (int j = 0; j < n - 1; j++) {
            count++;
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                count++;
            }
        }
        count++;
        n--;
    }
    return count;
}

void solution1() {
    printf("Solution 1:\n");
    
    int a[15] = {5, 19, 3, 16, 34, 35, 21, 345, 34, 12, 5, 6, 4, 3, 67};
    printf("Operations - %d\n", bubble(a));
    printArr(a);
    int b[15] = {5, 19, 3, 16, 34, 35, 21, 345, 34, 12, 5, 6, 4, 3, 67};
    printf("Operations - %d\n", lessOperationsBubble(b));
    printArr(b);
}

int shaker(int *array) {
    int count = 0;
    for (int i = 0; i < MaxN/2; i++) {
        for (int j = 0; j < MaxN - 1; j++) {
            count++;
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
                count++;
            }
        }
        for (int j = MaxN - 1; j >= 0; j--) {
            count++;
            if (array[j] < array[j-1]) {
                swap(&array[j], &array[j-1]);
                count++;
            }
        }
    }
    return count;
}

void solution2() {
    printf("Solution 2:\n");
    
    int a[15] = {5, 19, 3, 16, 34, 35, 21, 345, 34, 12, 5, 6, 4, 3, 67};
    printf("Operations - %d\n", shaker(a));
    printArr(a);
}

int binarySearch(int *a) {
    int value;
    printf("Input value to serach: \n");
    scanf("%d", &value);
    
    int left = 0;
    int right = MaxN - 1;
    int middle = left + (right - left) / 2;
    while (left <= right && a[middle] != value) {
        if (a[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
        middle = left + (right - left) / 2;
    }
    if (a[middle] == value) {
        return middle;
    } else {
        return -1;
    }
}


void solution3() {
    printf("Solution 3:\n");
    
    int a[15] = {1, 3, 4, 5, 7, 10, 12, 16, 19, 21, 32, 34, 35, 67, 345};
    int result = binarySearch(a);
    printf("Result: %d\n", result);
}

int choiseSort(int *a) {
    int count = 0;
    int j = 0;
    count++;
    int jmin;
    for (int i = 0; i < MaxN; i++) {
        jmin = i;
        count++;
        for (j = i + 1; j < MaxN; j++) {
            count++;
            if (a[j] < a[jmin]) {
                jmin = j;
                count++;
            }
        }
        count++;
        swap(&a[i], &a[jmin]);
    }
    return count;
}

int insertionSort(int *a) {
    int count = 0;
    for (int i = 0; i < MaxN; i++) {
        count++;
        int currentNum = a[i];
        count++;
        int currentPos = i;
        count++; // проверка условия1 цикла while
        count++; // проверка условия2 цикла while
        count++; // логическое И цикла while
        while (currentPos > 0 && a[currentPos-1] > currentNum) {
            count++;
            swap(&a[currentPos], &a[currentPos-1]);
            count++;
            currentPos--;
        }
    }
    return count;
}

void solution4() {
    printf("Solution 4: \n");
    printf("\n");
    
    printf("1. Bubble sort.\n");
    int bubbleDifficulty = MaxN * MaxN;
    printf("Estimated number of operations: %d\n", bubbleDifficulty);
    solution1();
    printf("\n");
    
    printf("2. Shaker sort.\n");
    int shakerDifficulty = MaxN * MaxN;
    printf("Estimated number of operations: %d\n", shakerDifficulty);
    solution2();
    printf("\n");
    
    printf("3. Choise sort.\n");
    int choiseDifficulty = MaxN * MaxN;
    printf("Estimated number of operations: %d\n", choiseDifficulty);
    int a[15] = {5, 19, 3, 16, 34, 35, 21, 345, 34, 12, 5, 6, 4, 3, 67};
    printf("Operations - %d\n", choiseSort(a));
    printArr(a);
    printf("\n");
    
    printf("4. Insertion sort.\n");
    int insertionDifficulty = MaxN * MaxN;
    printf("Estimated number of operations: %d\n", insertionDifficulty);
    int b[15] = {5, 19, 3, 16, 34, 35, 21, 345, 34, 12, 5, 6, 4, 3, 67};
    printf("Operations - %d\n", insertionSort(b));
    printArr(a);
}
