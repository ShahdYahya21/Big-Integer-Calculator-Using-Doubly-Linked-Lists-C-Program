//Shahd Yahya 1210249 section 3
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Doubly_Linked_List"

struct Node* Sum(struct Node* l1, struct Node* l2);
struct Node* Sub(struct Node* l1, struct Node* l2,int digitDiffrense);
int FindLargestNumberRegardlessOfTheSign(struct Node* l1, struct Node* l2, int numOfDigit1, int numOfDigit2);
struct Node* Mul(struct Node* l1,struct Node* l2);
struct Division Divide(struct Node* dividend, struct Node* divisor,int numOfDividendDigit,int numOfDivisorDigit);
int CountDigit(struct Node* l);
struct Node* additionSelection(struct Node* l1,struct Node* l2);
struct Node* subtractionSelection(struct Node* l1,struct Node* l2);
struct Node* multiplecationSelection(struct Node* l1,struct Node* l2);
struct Division divisionSelection(struct Node* l1,struct Node* l2);
void PrintListOnFile(struct Node* head);


int main() {
    FILE *ptr;
    ptr = fopen("/Users/shahdyahya/Desktop/Project 1/input.txt", "r"); //open the file

    if (ptr == NULL) {
        printf("Failed to open file");
        return 1;
    }

    char numbers[100][100];//save numbers in array of strings
    int count = 0;  // Number of strings
    while (count < 100 && fscanf(ptr, "%s", numbers[count]) == 1) { //read until the end of the file
        count++;
    }
    struct Node *array[1000]; // array of linked list
    for (int i = 0; i < count; i++) {
        array[i] = MakeEmpty(array[i]);
        if (numbers[i][0] == '-') array[i]->sign = '-'; // change the sign attribute in the linked list head to '-' if the number is negative
        else InsertAtLast(numbers[i][0] - '0', array[i]);
        for (int j = 1; numbers[i][j] != '\0'; j++) {
            InsertAtLast(numbers[i][j] - '0', array[i]);//move the number to the liked list
        }
    }

    fclose(ptr);
    struct Node *result = MakeEmpty(result);//to store the result
    struct Division divide; // to store the result of division
    printf("Welcome to my calculator\n");
    printf("select one operation:\n1)read the input file\n2)add\n3)subtract\n4)multiply\n5)divide\n6)print the results to an output file\n7)exit\n");
    int choice;
    scanf("%d", &choice);
    while (choice != 1 && choice != 7) { // to make sure that the user will choose 1 at first to see the numbers
        printf("choose 1 first\n");
        scanf("%d", &choice);
    }

    int num1, num2;
    bool start = false;
    int tmp = choice;// to know if I chose 5 the last time I chose a selection
    while (choice != 7) {
        if (start) scanf("%d", &choice);// to not scan a choice at the first time
        start = true;
        if (choice == 1) {
            printf("here is numbers you can do operation on them\n");
            for (int i = 0; i < count; i++) {//print the numbers to the users
                printf("%d) %s\n", i + 1, numbers[i]);
            }

        } else if (choice == 2) {
            bool valid = false; //to check if the numbers the user entered exist
            while (valid == false) {
                printf("choose 2 numbers\n");
                scanf("%d %d", &num1, &num2);
                if ((num1 - 1 < 0 || num1 - 1 > count) && (num2 - 1 < 0 || num2 - 1 > count)) {
                    printf("number 1 and 2 do not exist\n");
                    continue;

                } else if (num1 - 1 < 0 || num1 - 1 > count) {
                    printf("number 1 does not exist\n");
                    continue;

                } else if (num2 - 1 < 0 || num2 - 1 > count) {
                    printf("number 2 does not exist\n");
                    continue;
                }
                valid = true; //if the number exist we break the loop
            }
            result = additionSelection(array[num1 - 1], array[num2 - 1]);
            PrintList(result);

        } else if (choice == 3) {
            bool valid = false;
            while (valid == false) {
                printf("choose 2 numbers\n");
                scanf("%d %d", &num1, &num2);
                if ((num1 - 1 < 0 || num1 - 1 > count) && (num2 - 1 < 0 || num2 - 1 > count)) {
                    printf("number 1 and 2 do not exist\n");
                    continue;

                } else if (num1 - 1 < 0 || num1 - 1 > count) {
                    printf("number 1 does not exist\n");
                    continue;

                } else if (num2 - 1 < 0 || num2 - 1 > count) {
                    printf("number 2 does not exist\n");
                    continue;
                }
                valid = true;
            }
            result = subtractionSelection(array[num1 - 1], array[num2 - 1]);
            PrintList(result);

        } else if (choice == 4) {
            bool valid = false;
            while (valid == false) {
                printf("choose 2 numbers\n");
                scanf("%d %d", &num1, &num2);
                if ((num1 - 1 < 0 || num1 - 1 > count) && (num2 - 1 < 0 || num2 - 1 > count)) {
                    printf("number 1 and 2 do not exist\n");
                    continue;

                } else if (num1 - 1 < 0 || num1 - 1 > count) {
                    printf("number 1 does not exist\n");
                    continue;

                } else if (num2 - 1 < 0 || num2 - 1 > count) {
                    printf("number 2 does not exist\n");
                    continue;
                }
                valid = true;
            }
            result = multiplecationSelection(array[num1 - 1], array[num2 - 1]);
            PrintList(result);

        }
        else if (choice == 5) {
            bool valid = false;
            while (valid == false) {
                printf("choose 2 numbers\n");
                scanf("%d %d", &num1, &num2);
                if ((num1 - 1 < 0 || num1 - 1 > count) && (num2 - 1 < 0 || num2 - 1 > count)) {
                    printf("number 1 and 2 do not exist\n");
                    continue;

                } else if (num1 - 1 < 0 || num1 - 1 > count) {
                    printf("number 1 does not exist\n");
                    continue;

                } else if (num2 - 1 < 0 || num2 - 1 > count) {
                    printf("number 2 does not exist\n");
                    continue;
                }
                if(array[num2 - 1] -> next -> num == 0){
                    printf("you can not divide by zero\n");
                    continue;
                }
                valid = true;
            }
            divide = divisionSelection(array[num1 - 1], array[num2 - 1]);
            struct Node* s = MakeEmpty(s);
            InsertAtLast(0,s);
            printf("quotient: ");
            if(divide.quotient -> next) PrintList(divide.quotient);
            else PrintList(s);
            printf("remainder: ");
            if (divide.remainder-> next) PrintList(divide.remainder);
            else  PrintList(s);


        }
        else if (choice == 6) {
            if(tmp == 5){
                struct Node* s = MakeEmpty(s);
                InsertAtLast(0,s);
                if(divide.quotient -> next) PrintListOnFile(divide.quotient);
                else PrintListOnFile(s);
                if (divide.remainder-> next) PrintListOnFile(divide.remainder);
                else  PrintListOnFile(s);
            }
            else if (result->next == NULL) printf("theres is no value to print\n");
            else {
                PrintListOnFile(result);
            }

        }


        else if (choice == 7) {
            break;
        }
        else {
            printf("Invalid input\n");
        }
        tmp = choice;

    }

    printf("the program ended");


}




struct Node* Sum(struct Node* l1, struct Node* l2){
    // Find the last nodes of l1 and l2
    struct Node* temp1 = FindLast(temp1,l1);
    struct Node* temp2 = FindLast(temp2,l2);

    // Create an empty list for the sum
    struct Node* sum = MakeEmpty(sum);
    int carry = 0;
    int s = 0;
    // Add corresponding digits from l1 and l2
    while(temp1 -> prev && temp2 -> prev){
        s = temp1 -> num + temp2 -> num + carry;
        Insert(s % 10 ,sum,sum);
        carry = s / 10;
        temp1 = temp1 -> prev;
        temp2 = temp2 -> prev;
    }
    // If there are remaining digits in l1 or l2, add them to the sum
    while(temp1 -> prev){
        s = temp1 -> num + carry;
        Insert(s % 10 ,sum,sum);
        temp1 = temp1 -> prev;
        carry /= 10;
    }
    while(temp2 -> prev){
        s = temp2 -> num + carry;
        Insert(s % 10,sum,sum);
        temp2 = temp2 -> prev;
        carry /= 10;
    }
    // If there is a carry remaining, add it to the sum
    if(carry){
        Insert(carry ,sum,sum);

    }
    return sum;

}

struct Node* Sub(struct Node* l1, struct Node* l2,int digitDiffrense) {
    // Add leading zeros to l2 to match the number of digits in l1
    while (digitDiffrense) {
        Insert(0, l2, l2);
        digitDiffrense--;
    }
    // Find the last nodes of l1 and l2
    struct Node* temp1 = FindLast(temp1,l1);
    struct Node* temp2 = FindLast(temp2,l2);

    // Create an empty list for the subtraction result
    struct Node* sub = MakeEmpty(sub);

    int s = 0;
    while(temp1 -> prev && temp2 -> prev){
        if(temp1 -> num >= temp2 -> num){
            s = temp1 -> num - temp2 -> num;
            Insert(s ,sub,sub);
        }

        else{
            temp1 -> prev -> num -= 1; // Borrow from the previous digit if necessary
            temp1 -> num += 10;
            s = temp1 -> num - temp2 -> num;
            Insert(s ,sub,sub);
        }
        temp1 = temp1 -> prev;
        temp2 = temp2 -> prev;

    }
    // Remove leading zeros from the subtraction result
    while(sub -> next -> next != NULL && sub -> next -> num == 0){
        sub = sub -> next;
    }

    // Remove leading zeros from l2
    if(l2->next-> num == 0) {
        struct Node *temp3 = l2->next;

        while (temp3 && temp3->num == 0) {
            temp3 = temp3->next;

        }
        l2->next = temp3;
        temp3->prev = l2;

    }

    return sub;

}


int FindLargestNumberRegardlessOfTheSign(struct Node* l1, struct Node* l2, int numOfDigit1, int numOfDigit2){
    if(numOfDigit1 > numOfDigit2){  // Compare the number of digits in l1 and l2
        return 1;// l1 has more digits, so it is the largest number
    }

    if(numOfDigit1 < numOfDigit2){
        return 2;// l2 has more digits, so it is the largest number

    }
    //If they have equal digits compare corresponding digits from l1 and l2
    while(l1 -> next != NULL  && l1-> next -> num == l2 ->next -> num) {
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1 -> next == NULL) {
        return 1;
    }
    // Compare the next digits of l1 and l2 to determine the largest number
    return l1 -> next -> num >= l2 -> next -> num ? 1 : 2;

}

struct Node* Mul(struct Node* l1, struct Node* l2) {
    struct Node* result = MakeEmpty(result);// Initialize an empty list for the result
    struct Node* pointer1 = FindLast(pointer1,l1);// Find the last node of l1
    int count = 0;// count represents the number of zeros we need to add
    while(pointer1 -> prev){
        struct Node* temp1 = MakeEmpty(temp1);// Create an empty list to store the partial product
        int tmp = count;
        while (tmp--) {// Add leading zeros to the partial product based on the current position
            Insert(0, temp1, temp1);
        }
        struct Node* pointer2 = FindLast(pointer2,l2);

        int carry = 0;
        // Multiply the digits of l1 with each digit of l2
        while (pointer2 -> prev) {
            int product = pointer1->num * pointer2->num + carry;
            carry = product / 10;
            product %= 10;
            Insert(product, temp1, temp1);
            pointer2 = pointer2->prev;

        }
        // If there is a carry remaining, add it to the partial product
        if (carry > 0) {
            Insert(carry, temp1, temp1);
        }

        result = Sum(result, temp1);// Add the partial product to the result
        pointer1 = pointer1-> prev;
        count++;
    }
    return result;
}


struct Division Divide(struct Node* dividend, struct Node* divisor, int numOfDividendDigit, int numOfDivisorDigit) {
    struct Division divide;
    struct Node* tempdividend1 = MakeEmpty(tempdividend1);
    struct Node* tmp = dividend -> next;
    while(tmp){
        InsertAtLast(tmp -> num,tempdividend1);
        tmp = tmp -> next;
    }
    divide.quotient = MakeEmpty(divide.quotient);
    divide.remainder = MakeEmpty(divide.remainder);
    struct Node *tempDividend = MakeEmpty(tempDividend);
    struct Node *temp1 = tempdividend1->next; // move through the dividend
    struct Node *temp2 = tempDividend;   // points at the last node of tempDividend
    int countDigitOfTempDividend = 0;

    while (temp1 != NULL) {
        int numOfNeededZeros = -1;

        // edge case when we have a leading zero in divdened we add it to answer directly
        while(tempDividend -> next == NULL && temp1 != NULL && temp1 -> num == 0) {
            InsertAtLast(0, divide.quotient);
            tempdividend1 -> next = temp1 -> next;
            if(tempdividend1 -> next != NULL) {
                tempdividend1 -> next -> prev = tempdividend1;
            }
            temp1 = tempdividend1 -> next;
        }

        while (temp1 != NULL && FindLargestNumberRegardlessOfTheSign(tempDividend, divisor, countDigitOfTempDividend, numOfDivisorDigit) == 2) {
            temp2 -> next = temp1;
            temp1 -> prev = temp2;
            tempdividend1 -> next = temp1 -> next;
            temp1 -> next = NULL;
            if(tempdividend1 -> next != NULL) {
                tempdividend1 -> next -> prev = tempdividend1;
            }
            temp1 = tempdividend1 -> next;
            temp2 = temp2 -> next;
            countDigitOfTempDividend++;
            numOfNeededZeros++;
        }

        while(divide.quotient -> next != NULL && numOfNeededZeros-- > 0) {
            InsertAtLast(0, divide.quotient);
        }

        int count = 0;
        while (FindLargestNumberRegardlessOfTheSign(tempDividend, divisor, countDigitOfTempDividend, numOfDivisorDigit) == 1) {
            tempDividend = Sub(tempDividend, divisor, countDigitOfTempDividend - numOfDivisorDigit);
            countDigitOfTempDividend = CountDigit(tempDividend);
            count++;
        }

        if(tempDividend -> next != NULL){
            InsertAtLast(count, divide.quotient);
        }

        // we shouldn't represent 0 as head -> 0, it messes up the logic
        if(tempDividend -> next != NULL && tempDividend -> next -> num == 0) {
            tempDividend = MakeEmpty(tempDividend); // change (head -> 0 to head)
        }

        // we lose temp2 when we subtract tempDividend, we need to point at the last number
        temp2 = tempDividend;
        countDigitOfTempDividend = 0;
        while(temp2 -> next != NULL) {
            temp2 = temp2 -> next;
            countDigitOfTempDividend++;
        }
    }

    divide.remainder = tempDividend;

    return divide;
}



int CountDigit(struct Node* l){
    struct Node* temp = l -> next;
    int count = 0;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

struct Node* additionSelection(struct Node* l1,struct Node* l2) {//to handle the sign and to know which operation the perform
    int count1 = CountDigit(l1);
    int count2 = CountDigit(l2);
    int large = FindLargestNumberRegardlessOfTheSign(l1, l2, count1, count2);
    struct Node* s = MakeEmpty(s);
    if (l1->sign != '-' && l2->sign != '-') {
        s = Sum(l1, l2);
    }
    else if (l1->sign != '-' && l2->sign == '-') {
        if (large == 1) {
            s = Sub(l1, l2, count1 - count2);
        }
        else {
            s = Sub(l2, l1, count2 - count1);
            InsertChar('-', s, s);

        }
    }
    else if (l1->sign == '-' && l2->sign != '-') {
        if (large == 1) {
            s = Sub(l1, l2, count1 - count2);
            InsertChar('-', s, s);
        }
        else {
            s = Sub(l2, l1, count2 - count1);

        }
    }
    else if (l1->sign == '-' && l2->sign == '-') {
        s = Sum(l1, l2);
        InsertChar('-', s, s);
    }
    return s;
}
struct Node* subtractionSelection(struct Node* l1,struct Node* l2) { //to handle the sign and to know which operation the perform
    int count1 = CountDigit(l1);
    int count2 = CountDigit(l2);
    int large = FindLargestNumberRegardlessOfTheSign(l1, l2, count1, count2);
    struct Node *s = MakeEmpty(s);
    if (l1->sign != '-' && l2->sign != '-') {
        if (large == 1) {
            s = Sub(l1, l2, count1 - count2);
        }
        else {
            s = Sub(l2, l1, count2 - count1);
            InsertChar('-', s, s);
        }
    }
    else if (l1->sign != '-' && l2->sign == '-') {
        s = Sum(l1, l2);
    }
    else if (l1->sign == '-' && l2->sign != '-') {
        s = Sum(l2, l1);
        InsertChar('-', s, s);

    }
    else if (l1->sign == '-' && l2->sign == '-') {
        if (large == 1) {
            s = Sub(l1, l2, count1 - count2);
            InsertChar('-', s, s);
        }
        else {
            s = Sub(l2, l1, count2 - count1);
        }
    }
    return s;
}
struct Node* multiplecationSelection(struct Node* l1,struct Node* l2) { //To handle the sign
    struct Node *s = MakeEmpty(s);
    if ((l1->sign != '-' && l2->sign == '-') || (l1->sign == '-' && l2->sign != '-')) {
        s = Mul(l1, l2);
        InsertChar('-', s, s);
    }
    else {
        s = Mul(l1, l2);
    }
    return s;
}

struct Division divisionSelection(struct Node* l1,struct Node* l2) { //to handle the sign
    int count1 = CountDigit(l1);
    int count2 = CountDigit(l2);
    struct Division s;
    if ((l1->sign != '-' && l2->sign == '-') || (l1->sign == '-' && l2->sign != '-')) {
        s = Divide(l1, l2,count1,count2);
        InsertChar('-', s.quotient, s.quotient);

    }
    else
    {
        s = Divide(l1, l2,count1,count2);
    }
    return s;
}

void PrintListOnFile(struct Node* head) {//print the linked list on the file
    FILE* outputFile = fopen("output", "a");
    if (outputFile == NULL) {
        printf("Failed to open output file\n");
        return;
    }

    struct Node* P = head -> next;
    if (P != NULL && P->sign == '-') {
        fprintf(outputFile, "%c", P->sign);
        P = P->next;
    }

    while (P != NULL) {
        fprintf(outputFile, "%d", P->num);
        P = P->next;
    }

    fprintf(outputFile, "\n");
    fclose(outputFile);
}



