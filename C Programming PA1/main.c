#include <stdio.h>
#include <stdlib.h>

void healCaculator(double playerCritChance, double playerCritDamage, double playerPhysicalResistance, int attack, int HP)
{
	double random;
	random = rand() % 100, 1;

	if (random <= playerCritChance) {
		attack = (int)(((double)attack * (playerCritDamage / 100)) * (playerPhysicalResistance / 100));
	}
	else {
		attack = (int)((double)attack *(playerPhysicalResistance / 100));
	}

	HP = HP + attack;
};

void attackCalculator(int attackerAttack, double attackerCritChance, double attackerCritDamage, int *targetHealth, double targetPhysicalResistance)
{
	double random;
	random = rand() % 100, 1;

	if (random <= attackerCritChance) {
		attackerAttack = (int)(((double)attackerAttack * (attackerCritDamage /100)) * (targetPhysicalResistance / 100));}
	else {
		attackerAttack = (int)((double)attackerAttack *(targetPhysicalResistance / 100));
	}

	*targetHealth -= attackerAttack;
};

void createPlayerCharacter(int *roleNumber, int *playerHealth, int *playerAttack, double *playerPhsycialResistance, double *playerCritChance, double *playerCritDamage)
{/*Please create the following:*/
	switch(*roleNumber)
{
		case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 10000; //Set *playersHealth to 10000
			*playerAttack = 300; //Set *playerAttack to 300;
			*playerPhsycialResistance = (rand() % 90 + 70) / 100; //Generate a random number inclusively between the range of 70 to 90 then divide by 100
			*playerCritChance = (rand() % 30 + 10) / 100; //Genearte a random number inclusively betwen the range of 10 to 30 then divide by 100
			*playerCritDamage = (rand() % 700 + 1000) / 100; // Generate a random number inclusively between the range of 700 to 1000 then divide by 100
			/*END of your solution*/
			break;
		case 2: //Mage: Low: health and resistance. Medium: crit damage and crit chance High: attack
			/*BEGINNING of your solution*/
			*playerHealth = 4000; //Set *playersHealth to 4000
			*playerAttack = 1000; //Set *playerAttack to 1000;
			*playerPhsycialResistance = (rand() % 40 + 20) / 100; //Generate a random number inclusively between the range of 20 to 40 then divide by 100
			*playerCritChance = (rand() % 50 + 20) / 100; //Genearte a random number inclusively betwen the range of 20 to 50 then divide by 100
			*playerCritDamage = (rand() % 500 + 200) / 100; // Generate a random number inclusively between the range of 200 to 500 then divide by 100
			/*END of your solution*/
			break;
		case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 6000; //Set *playersHealth to 6000
			*playerAttack = 600; //Set *playerAttack to 600;
			*playerPhsycialResistance = (rand() % 60 + 30) / 100; //Generate a random number inclusively between the range of 30 to 60 then divide by 100
			*playerCritChance = (rand() % 90 + 70) / 100; //Genearte a random number inclusively betwen the range of 70 to 90 then divide by 100
			*playerCritDamage = (rand() % 600 + 400) / 100; // Generate a random number inclusively between the range of 400 to 600 then divide by 100
			/*END of your solution*/
			break;
	}
};

void createBoss(int *bossHealth, int *bossAttack, double *bossPhsycialResistance, double *bossCritChance, double *bossCritDamage)
{
	*bossHealth = 50000;
	*bossAttack = 500;
	*bossPhsycialResistance = (rand() % 30 + 60) / 100;
	*bossCritChance = (rand() % 10 + 20) / 100;
	*bossCritDamage = (rand() % 100 + 250) / 100;
};
void introduction() {
	printf("Welcome to your Programming Assignment 1!\n");
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Silva.\n");
	printf("You can choose to be a WARRIOR, a MAGE or an Archer.\n ");
	printf("1. Warrior\n ");
	printf("2. Mage\n ");
	printf("3. Archer\n");
	printf("Please select your class with the coresponding numbers: ");
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
	double bosserCritChance;
	double bosserCritDamage;
	
	//FUNCTION
	introduction();
	getUserInput();
	createPlayerCharacter(getUserInput(), &playerHealth, &playerAttack, &playerPhysicalResistance, &playerCritChance, &playerCritDamage);
	attackCaculator(playerCritChance, playerCritDamage, playerPhysicalResistance, playerAttack, &playerHealth);

	return 0;
};