#include <stdio.h>
#include <stdlib.h>


void attackCaculator(double playerCritChance, double playerCritDamage,  double playerPhysicalResistance, int attack, int HP)
{
	double random;
	random = rand() % 100, 1;
	playerCritDamage = rand() % 500 + 100;
	playerCritChance = rand() % 100 + 1;
	playerPhysicalResistance = rand() % 80 + 20;

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
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Lord Evil./n");
	printf("You can choose to be a WARRIOR, a MAGE or an Archer./n");
	printf("Please select your class with the coresponding numbers:/n ");
	printf("1. Warrior/n ");
	printf("1. Mage/n ");
	printf("1. Archer/n ");
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
	introduction();
	attackCaculator(playerCritChance, playerCritDamage, playerPhysicalResistance, playerAttack, &playerHP);
	/*
	char name[50];
	int  ID;

	int health = 500;
	int attack= 40;
	
	double physicalResistance;
	//physicalResistance = rand() % 100, 1;
	double critChance;
	//critChance = rand() % 100 + 1;

	float critDamage;
	//critDamage = rand() % 500 + 100;
	
	double temp = (double)rand();

	printf("%lf", temp);
	*/
	return 0;
};