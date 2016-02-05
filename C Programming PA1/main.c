#include <stdio.h>
#include <stdlib.h>

//Property of Daniel and Tin

double calculateHealAmount(double playerCritChance, double playerCritDamage, double playerPhysicalResistance, int attack, int HP)
{
	double healAmount;
	double random;
	random = rand() % 100 + 1;

	if (random <= playerCritChance) 
	{
		healAmount = (int)((((double)attack * 0.4) * (playerCritDamage)) * (playerPhysicalResistance + 1));
	}
	else 
	{
		healAmount = (int)(((double)attack * 0.4) *(playerPhysicalResistance + 1));
	}
	return healAmount;
};

double calculateDamageAmount(int attackerAttack, double attackerCritChance, double attackerCritDamage, double targetPhysicalResistance)
{
	double random;
	double damageDealt;
	random = (rand() % 100 + 1) / 100;

	if (random <= attackerCritChance) 
	{
		damageDealt = (int)(((double)attackerAttack * (attackerCritDamage)) * (targetPhysicalResistance));
	}
	else 
	{
		damageDealt = (int)((double)attackerAttack *(targetPhysicalResistance));
	}
	return damageDealt;
};

void createPlayerCharacter(int roleNumber, int *playerHealth, int *playerAttack, double *playerPhysicalResistance, double *playerCritChance, double *playerCritDamage)
{
	switch(roleNumber)
{
		case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 10000; //Set *playersHealth to 10000
			*playerAttack = 300; //Set *playerAttack to 300;
			*playerPhysicalResistance = 80 / 100; //Set *playerPhysicalResistance to 80 / 100;
			*playerCritChance = 20 / 100; //Set *playerCritChance to 20 / 100;
			*playerCritDamage = 800 / 100; //Set *playerCritDamage to 800 / 100;
			/*END of your solution*/
			break;
		case 2: //Mage: Low: health and resistance. Medium: crit damage and crit chance High: attack
			/*BEGINNING of your solution*/
			*playerHealth = 4000; //Set *playersHealth to 4000
			*playerAttack = 1000; //Set *playerAttack to 1000;
			*playerPhysicalResistance = 30 / 100; //Set *playerPhysicalResistance to 30 / 100;
			*playerCritChance = 40 / 100; //Set *playerCritChance to 40 / 100;
			*playerCritDamage = 400 / 100; //Set *playerCritDamage to 400 / 100;
			/*END of your solution*/
			break;
		case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 6000; //Set *playersHealth to 6000
			*playerAttack = 600; //Set *playerAttack to 600;
			*playerPhysicalResistance = 50 / 100; //Set *playerPhysicalResistance to 50 / 100;
			*playerCritChance = 80 / 100; //Set *playerCritChance to 80 / 100;
			*playerCritDamage = 600 / 100; //Set *playerCritDamage to 600 / 100;
			/*END of your solution*/
			break ;
	}
};

void createBoss(int *bossHP, int *bossAttack, double *bossPhysicalResistance, double *bossCritChance, double *bossCritDamage)
{
	/*BEGINNING of your solution*/
	*bossHP = 50000; //Set *bossHealth to 50000
	*bossAttack = (rand() % 600 + 400); //Set *bossAttack to a randomized number in the range between 400 to 600 inclusively
	*bossPhysicalResistance = (rand() % 60 + 30) / 100; //Set *bossPhysicalResistance to a randomized number in the range between 30 to 60 inclusively
	*bossCritChance = (rand() % 20 + 10) / 100; //Set *bossCritChance to a randomized number in the range between 10 to 20 inclusively
	*bossCritDamage = (rand() % 250 + 100) / 100; //Set *bossCritDamage to a randomized number in the range between 100 to 250 inclusively
	/*END of your solution*/
};

void introduction() {
	printf("Welcome to your Programming Assignment 1!\n");
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Silva.\n");
	printf("You can choose to be a WARRIOR, a MAGE or an ARCHER.\n ");
	printf("1. Warrior\n ");
	printf("2. Mage\n ");
	printf("3. Archer\n");
	printf("Please select your class with the coresponding numbers: ");
}

int playerMove() {
	int move;
	printf("1. Attack\n");
	printf("2. Heal\n");
	scanf("%d", &move);
	return move;
}


int getUserInput() {
	int number;
	scanf("%d", &number);
	return number;
}

int main() {
	//Student Info
	char name[50];
	int ID;

	//CHARACTER 
	const char roleName1[10] = { 'W','a','r','r','i','o','r' };
	const char roleName2[10] = { 'M','a','g','e' };
	const char roleName3[10] = { 'A','r','c','h','e','r' };
	int playerHealth;
	int playerAttack;

	//CHARACTER STATS
	double playerPhysicalResistance;
	double playerCritChance;
	double playerCritDamage;
	
	//BOSS STATS
	char bossName[10] = { 'S', 'i', 'l', 'v', 'a' };
	int bossHP;
	int bossAttack;
	double bossPhysicalResistance;
	double bossCritChance;
	double bossCritDamage;
	
	//FUNCTION
	introduction();
	createPlayerCharacter(getUserInput(), &playerHealth, &playerAttack, &playerPhysicalResistance, &playerCritChance, &playerCritDamage);
	createBoss(&bossHP, &bossAttack, &bossPhysicalResistance, &bossCritChance, &bossCritDamage);



	return 0;
};