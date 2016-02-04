#include <stdio.h>
#include <stdlib.h>

/*
double attackCaculator(float critChance, double critDamage, double attack, float physicalResistance) 
{
	double random;
	random = rand() % 100, 1;

	if (random <= critChance) {
		attack = (attack * ((critDamage/100)+1)) * (physicalResistance / 100);}
		//attack is INT, CritDamage is Float, physicalResistance is DOUBLE
	else {
		attack = attack *(physicalResistance / 100);
	}
	return attack;
};*/


void createPlayerCharacter(int *roleNumber, int *playerHealth, int *playerAttack, double *playerResistance, double *playerCritChance, double *playerCritDamage)
{/*Please create the following:*/
	switch(*roleNumber)
	{
		case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 10000; //Set *playersHealth to 10000
			*playerAttack = 300; //Set *playerAttack to 300;
			*playerResistance = rand() % 90 + 70; //Generate a random number inclusively between the range of 70 to 90
			*playerCritChance = rand() % 30 + 10; //Genearte a random number inclusively betwen the range of 10 to 30
			*playerCritDamage = rand() % 700 + 1000; // Generate a random number inclusively between the range of 700 to 1000
			/*END of your solution*/
			break;
		case 2: //Mage: Low: health and resistance. Medium: crit damage. High: crit chance and attack
			/*BEGINNING of your solution*/
			*playerHealth = 4000; //Set *playersHealth to 4000
			*playerAttack = 1000; //Set *playerAttack to 1000;
			*playerResistance = rand() % 40 + 20; //Generate a random number inclusively between the range of 20 to 40
			*playerCritChance = rand() % 90 + 50; //Genearte a random number inclusively betwen the range of 50 to 90
			*playerCritDamage = rand() % 200 + 300; // Generate a random number inclusively between the range of 200 to 300
			/*END of your solution*/
			break;
		case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 6000; //Set *playersHealth to 6000
			*playerAttack = 600; //Set *playerAttack to 600;
			*playerResistance = rand() % 60 + 30; //Generate a random number inclusively between the range of 30 to 60
			*playerCritChance = rand() % 90 + 70; //Genearte a random number inclusively betwen the range of 70 to 90
			*playerCritDamage = rand() % 600 + 400; // Generate a random number inclusively between the range of 400 to 600
			/*END of your solution*/
			break;
	}
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

	//CHARACTER STATS
	double playerPhysicalResistance;
	double playerCritChance;
	double playerCritDamage;
	
	
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