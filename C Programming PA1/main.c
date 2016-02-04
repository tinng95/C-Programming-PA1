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

void introduction(int warriorHP, int mageHP, int archerHP, int warriorAttack, int mageAttack, int archerAttack) {
	printf("Welcome to your Programming Assignment 1!/n");
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Lord Evil./n");
	printf("You can choose to be a WARRIOR, a MAGE or an Archer varied by thier stats./n");
    printf("1. Warrior's HP: %d , Warrior's Attack: %d/n", warriorHP,warriorAttack);
	printf("2. Mage's HP: %d , Mage's Attack: %d/n", mageHP, mageAttack);
	printf("3. Archer's HP: %d , Archer's Attack: %d/n", archerHP, archerAttack);
	printf("Please select your class with one of the number above: ");
}



int main() {
	//Student Info
	char name[50];
	int ID;

	//CHARACTER 
	const char roleName1[10]= ('w','a','r','r','i','o','r');
	const char roleName2[10]= ('m','a','g','e');
	const char roleName3[10]= ('a','r','c','h','e','r'); 
	int warriorHP;
	int mageHP;
	int archerHP;

	int warriorAttack;
	int mageAttack;
	int archerAttack;

	//CHARACTER STATS
	double playerPhysicalResistance;
	double playerCritChance;
	double playerCritDamage;
	
	attackCaculator(playerCritChance, playerCritDamage, playerPhysicalResistance, warriorAttack, &warriorHP);
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