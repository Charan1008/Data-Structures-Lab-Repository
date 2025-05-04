//solving palindrome , armstrong number , perfect number using pointers.
#include <cstdio>
#include <cstdlib>
#include <cmath>

//Function to calculate whether the number is a palindrome or not.

int palindrome(int* num) {
int* original = (int*)malloc(sizeof(int));
int* reversed = (int*)malloc(sizeof(int));
int* temp = (int*)malloc(sizeof(int));

*original = *num;
*reversed = 0;
*temp = *num;
while(*temp > 0) {
*reversed = *reversed * 10 + (*temp%10); //logic of the function.
*temp = *temp/10;
}
if(*original == *reversed) {
free(original);
free(reversed);
free(temp);
return 1;
}
else {
free(original);
free(reversed);
free(temp);
return 0;
}
}

//Function to calculate whether the number is a Armstrong number or not.
int armstrongNumber(int* num) {
int* original = (int*)malloc(sizeof(int));
int* digits = (int*)malloc(sizeof(int));
int* temp = (int*)malloc(sizeof(int));
int* sum = (int*)malloc(sizeof(int));

*original = *num;
*digits = 0;
*temp = *num;
*sum = 0;

while(*temp > 0) {
*digits = *digits + 1; //logic of the function.
*temp = *temp/10;
}
*temp = *num;
while(*temp > 0) {
*sum = *sum + (int)pow(*temp%10, *digits); //logic of the function.
*temp = *temp/10;
}
if(*original == *sum) {
free(original);
free(digits);
free(temp);
free(sum);
return 1;
}
else{
free(original);
free(digits);
free(temp);
free(sum);
return 0;
}
}

//Function to calculate whether the number is a Perfect Nujmber or not.
int perfectNumber(int* num) {
int* original = (int*)malloc(sizeof(int));
int* sum = (int*)malloc(sizeof(int));
int* i = (int*)malloc(sizeof(int));

*original = *num;
*sum = 0;

for(*i=1 ; *i <= *original/2 ; (*i)++) {
if(*original % *i == 0) {
*sum = *sum + *i; //logic of the function.
}
}
if(*original == *sum) {
free(original);
free(sum);
free(i);
return 1;
}
else {
free(original);
free(sum);
free(i);
return 0;
}
}

//Main Function.
int main() {

int* num = (int*)malloc(sizeof(int));
int* choice = (int*)malloc(sizeof(int));

do {
// Printing the menu........
printf("\n--------Menu--------\n");
printf("1. Palindrome Number.\n");
printf("2. Armstrong Number.\n");
printf("3. perfect Number.\n");
printf("4. Exit.\n");
//Entering the choice from the user.
printf("Enter the choice: ");
scanf("%d", &*choice);

if(*choice == 1 || *choice == 2 || *choice == 3) {
printf("Enter the number: ");
scanf("%d", num);
if(*num < 0) {
printf("Enter a positive number again.\n");
continue;
}
switch (*choice) {
case 1:
if(palindrome(num)==1) {
printf("The entered number %d is a palindrome.\n", *num); //if the number is able to satisfy the function it returns 1.
}
else {
printf("The entered number %d is not a palindrome.\n", *num); // if the number is not able to satisfy it returns 0.
}
break;

case 2:
if(armstrongNumber(num)==1) {
printf("The entered number %d is an Armstrong Number.\n", *num); //if the number is able to satisfy the function it returns 1.
}
else {
printf("The entered number %d is not an Armstrong Number.\n", *num); // if the number is not able to satisfy it returns 0.
}
break;

case 3:
if(perfectNumber(num)==1) {
printf("The entered number %d is a Perfect Number.\n", *num); //if the number is able to satisfy the function it returns 1.
}
else {
printf("The entered number %d is not a Perfect Number.\n", *num); // if the number is not able to satisfy it returns 0.
}
break;
}
}
else if(*choice != 4) {
printf("Invalid choice!!. Please select a number from (1-3)");
}
}
while (*choice != 4); // loop to ask the user again the menu to check his number.
printf("Exiting the program.\n");
free(num);
free(choice);

return 0;
}