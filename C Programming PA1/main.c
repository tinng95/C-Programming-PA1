#include <stdio.h>
#include <stdlib.h>


void attackCaculator(double playerCritChance, double playerCritDamage,  double playerPhysicalResistance, int attack, int HP)
{
	double random;
	random = rand() % 100, 1;

	if (random <= playerCritChance) {
		attack = (int)(((double)attack * (playerCritDamage /100)) * (playerPhysicalResistance / 100));}
	else {
		attack = (int)((double)attack *(playerPhysicalResistance / 100));
	}

	HP = HP - attack;
};

void createPlayerCharacter(char *roleName, int *playerHealth, int *playerAttack, double *playerResistance, double *playerCritChance, double *playerCritDamage)
{
	switch(*roleName)
	{
		case 1:
			break;
	}
};

void introduction() {
	printf("Welcome to your Programming Assignment 1!/n");
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Silva./n");
	printf("You can choose to be a WARRIOR, a MAGE or an Archer./n");
	printf("Please select your class with the coresponding numbers:/n ");
	printf("1. Warrior/n ");
	printf("1. Mage/n ");
	printf("1. Archer/n ");
}

int getUserInput() {
	int number;
	scanf("%d", number);
	return number;
}

int main() {
	//Student Info
	char name[50];
	int ID;

	//CHARACTER 
	const char roleName1[10]= ('w','a','r','r','i','o','r');
	const char roleName2[10]= ('m','a','g','e');
	const char roleName3[10]= ('a','r','c','h','e','r'); 
	int playerHP;
	int playerAttack;

	//CHARACTER STATS
	double playerPhysicalResistance;
	double playerCritChance;
	double playerCritDamage;


	//BOSS STATS
	char bossName[10] = ('S', 'i', 'l', 'v', 'a', );


	//FUNCTION
	introduction();
	getUserInput();
	attackCaculator(playerCritChance, playerCritDamage, playerPhysicalResistance, playerAttack, &playerHP);

	return 0;
};