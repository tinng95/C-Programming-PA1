#include <stdio.h>
#include <stdlib.h>

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
};

void introduction() {
	printf("Wellcome to our game!/n");

};



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