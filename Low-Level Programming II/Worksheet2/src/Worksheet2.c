/*
 ============================================================================
 Name        : Worksheet2.c
 Author      : Christine Pace
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// QUESTION 1
void Q1(){
	int num1;
	int num2;

	printf("Question 1 \n");
	printf("Enter first number: ");
	scanf("%i", &num1);
	printf("Enter second number: ");
	scanf("%i", &num2);

	printf("\nThe Sum is: %i \nThe Average is: %f \nThe Sum of the Squares of the numbers: %i", (num1 + num2), ((num1 + num2)/2.0), ((num1*num1)+(num2*num2)));

}


//QUESTION 2
typedef struct persondetail{
	char idcard[8];
	char name[30];
	char surname[30];
	int age;
}person;

void Q2(){
	person p;
	printf("\n\nQuestion 2\n");
	printf("ID Card:");
	scanf("%s", &p.idcard);
	printf("Name:");
	scanf("%s", &p.name);
	printf("Surname:");
	scanf("%s", &p.surname);
	printf("Age:");
	scanf("%i", &p.age);
	printf("\n\nID Card: %s \nName: %s \nSurname: %s \nAge: %i", p.idcard, p.name, p.surname, p.age);
}


// QUESTION 3
void Q3(){
	printf("\n\nQuestion 3\n");
	int numbers[10];
	int largestNum;

	for(int i = 0; i < 10; i++){
		printf("Enter a number: ");
		scanf("%i", &numbers[i]);

		if(i == 0){
			largestNum = numbers[i];
		}

		else if(numbers[i] > largestNum){
			largestNum = numbers[i];
		}
	}
	printf("\nThe largest number is %i", largestNum);
}


// QUESTION 4
void Q4(){
	printf("\n\nQuestion 4\n");
}


// QUESTION 5
void Q5(){
	printf("\n\nQuestion 5\n");

	int num;
	printf("Enter a number between 1 and 100: ");
	scanf("%i", &num);

	if(num > 0 && num < 101){
		printf("You've entered %i !", num);
	}
	else{
		printf("Only a number between 1 and 100 are accepted.");
	}
}


// QUESTION 6
void Q6(){
	printf("\n\nQuestion 6\n");

	int numSeconds;
	printf("Enter a number in seconds:");
	scanf("%i", &numSeconds);

	double toHours = numSeconds/3600.0;
	int hours = toHours;
	double toMinutes = (toHours - hours) * 60;
	int minutes = toMinutes;
	int seconds = (toMinutes - minutes) * 60;

	printf("HH:MM:SS  ->  %02i:%02i:%02i", hours, minutes, seconds);
}


// QUESTION 7
void Q7(int argc, char *argv[]){
	printf("\n\nQuestion 7\n");
	if(argv[1] > argv[2]){
		printf("The largest number is %s ", argv[1]);
	}
	else if(argv[1] < argv[2]){
		printf("The largest number is %s ", argv[2]);
	}
	else if(argv[1] == argv[2]){
		printf("The numbers are equal");
	}
	else{
		printf("Not a valid number.");
	}
}


// QUESTION 8
void Q8(int argc, char *argv[]){
	printf("\n\nQuestion 8\n");
	printf("The largest number is %s", (argv[1] > argv[2]) ? argv[1] : argv[2]);
}


// QUESTION 9
void Q9(){
	printf("\n\nQuestion 9\n");
	int r;
	srand(time(0));

	printf("Random NUmbers: \n");
	for (int i = 0; i < 5; i++){
		r = (rand () % 100) + 1;
		printf("%i \n", r);
	}
}


int main(int argc, char* argv[]) {

	//Q1();
	//Q2();
	//Q3();
	//Q4();
	//Q5();
	//Q6();
	Q7(argc, argv);
	Q8(argc, argv);
	//Q9();

	printf("\n\nComplete!");
	return EXIT_SUCCESS;
}
