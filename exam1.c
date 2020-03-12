#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define SIZE 20
int numberOfSides(void);
int numberOfRoles(void);
void rollingDice(int diceSize, int rolls, int sideArray[SIZE]);
void printDice(int sideArray[],int rolls);

int main(void)
{
	int sides, rolls;
	srand(time(NULL));
	int sideArray[SIZE] = {0};

	sides = numberOfSides();
	rolls = numberOfRoles();
	rollingDice(sides, rolls, sideArray);
	printDice(sideArray, rolls);
}

int numberOfSides(void)
{
	int userInput;
	printf("Enter the number of sides for your die: \n");
	scanf(" %d", &userInput);

	return userInput;
}

int numberOfRoles(void)
{
	int userInput = 21;
	while(userInput > 20)
	{
		printf("Enter the number of rolls: \n");
		scanf(" %d", &userInput);
	}
	return userInput;
}

void rollingDice(int diceSize, int rolls, int sideArray[])
{
	int i;

	for(i = 0; i < rolls; i++)
	{
		int randomNum = (rand()%(1 - diceSize + 1) + 1);
		sideArray[i] = randomNum;
	}
}

void printDice(int sideArray[], int rolls)
{
	int i;
	int counter = 1;
	printf("Number of times you rolled a: \n");

	for(i = 0; i < rolls; i++)
	{
		printf("%d = %d\n", counter, sideArray[i]);
		counter++;
	}
}

