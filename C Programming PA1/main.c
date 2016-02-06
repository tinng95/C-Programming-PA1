#include <stdio.h>
#include <stdlib.h>

//Property of Daniel and Tin

double calculateHealAmount(double *attackerMinPhysicalResistance, double *attackerMaxPhysicalResistance, double *attackerMinCritDamage, double *attackerMaxCritDamage, double *attackerCritChance, double *attackerAttack)
{
	double healAmount;
	double randomCrit;
	randomCrit = (double)((double)(rand() % 100 + 0) / (double)100);

	if (randomCrit <= *attackerCritChance)
	{
		healAmount = ((((double)*attackerAttack * 0.4)
			* ((double)(rand() % ((int)(*attackerMaxCritDamage - *attackerMinCritDamage) + (int)*attackerMinCritDamage)))
			* ((double)(rand() % (int)(*attackerMaxPhysicalResistance - *attackerMinPhysicalResistance) + (int)*attackerMinPhysicalResistance) + 100) / 100.00));
	}
	else
	{
		healAmount = ((((double)*attackerAttack * 0.4)
			* ((double)(rand() % (int)(*attackerMaxPhysicalResistance - *attackerMinPhysicalResistance) + (int)*attackerMinPhysicalResistance) + 100) / 100.00));
	}
	return healAmount;
};

double calculateDamageAmount(double *targetMinPhysicalResistance, double *targetMaxPhysicalResistance, double *attackerMinCritDamage, double *attackerMaxCritDamage, double *attackerCritChance, double *attackerAttack)
{
	double randomCrit;
	double damageDealt;
	randomCrit = (double)((double)(rand() % 100 + 0) / (double)100);

	if (randomCrit <= *attackerCritChance)
	{
		damageDealt = (double)((double)*attackerAttack
			* (double)(rand() % (int)(*attackerMaxCritDamage - *attackerMinCritDamage) + (int)*attackerMinCritDamage)
			* (1.00 - ((double)(rand() % (int)(*targetMaxPhysicalResistance - *targetMinPhysicalResistance) + (int)*targetMinPhysicalResistance) / 100.00)));
	}
	else
	{
		damageDealt = (double)((double)*attackerAttack
			* (1.00 - ((double)(rand() % (int)(*targetMaxPhysicalResistance - *targetMinPhysicalResistance) + (int)*targetMinPhysicalResistance) / 100.00)));
	}
	return damageDealt;
};

void createPlayerCharacter(int roleNumber, double *playerHealth, double *playerMaxHealth, double *playerAttack, double *playerMinPhysicalResistance, double *playerMaxPhysicalResistance, double *playerCritChance, double *playerMinCritDamage, double *playerMaxCritDamage)
{
	switch (roleNumber)
	{
	case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
		*playerHealth = 10000; //Set *playersHealth to 10000;
		*playerMaxHealth = 10000; //Set *playerMaxHealth to 10000;
		*playerAttack = 300; //Set *playerAttack to 300;
		*playerMaxPhysicalResistance = 80.00; //Set *playerMaxPhysicalResistance to 80%;
		*playerMinPhysicalResistance = 60.00; //Set *playerMinPhysicalResistance to 60%;
		*playerCritChance = 0.20; //Set *playerMaxCritChance to 0.20;
		*playerMaxCritDamage = 8.00; //Set *playerMaxCritDamage to 8.00;
		*playerMinCritDamage = 6.00; //Set *playerMinCritDamage to 6.00;
								  /*END of your solution*/
		break;
	case 2: //Mage: Low: health and resistance. Medium: crit damage and crit chance High: attack
			/*BEGINNING of your solution*/
		*playerHealth = 4000; //Set *playersHealth to 4000;
		*playerMaxHealth = 4000; //Set *playerMaxHealth to 4000;
		*playerAttack = 1000; //Set *playerAttack to 1000;
		*playerMaxPhysicalResistance = 40.00; //Set *playerMaxPhysicalResistance to 40.00%;
		*playerMinPhysicalResistance = 30.00; //Set *playerMinPhysicalResistance to 30.00%;
		*playerCritChance = 0.40; //Set *playerMaxCritChance to 0.40;
		*playerMaxCritDamage = 4.00; //Set *playerMaxCritDamage to 4.00;
		*playerMinCritDamage = 3.00; //Set *playerMinCritDamage to 3.00;
								  /*END of your solution*/
		break;
	case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
		   /*BEGINNING of your solution*/
		*playerHealth = 6000; //Set *playersHealth to 6000;
		*playerMaxHealth = 6000; //Set **playerMaxHealth to 6000;
		*playerAttack = 600; //Set *playerAttack to 600;
		*playerMaxPhysicalResistance = 50.00; //Set *playerMaxPhysicalResistance to 50.00%;
		*playerMinPhysicalResistance = 40.00; //Set *playerMinPhysicalResistance to 40.00%;
		*playerCritChance = 0.80; //Set *playerMaxCritChance to 0.80;
		*playerMaxCritDamage = 7.00; //Set *playerMaxCritDamage to 7.00;
		*playerMinCritDamage = 5.00; //Set *playerMinCritDamage to 5.00;
								  /*END of your solution*/
		break;
	}
};

void createBoss(double *bossHealth, double *bossAttack, double *bossMinPhysicalResistance, double *bossMaxPhysicalResistance, double *bossCritChance, double *bossMinCritDamage, double *bossMaxCritDamage)
{
	/*BEGINNING of your solution*/
	*bossHealth = 50000.00; //Set *bossHealth to 50000
	*bossAttack = (double)(rand() % 200 + 400); //Set *bossAttack to a randomized number in the range between 400 to 600 inclusively
	*bossMaxPhysicalResistance = 60.00; //Set *bossMaxPhysicalResistance to 60.00;
	*bossMinPhysicalResistance = 30.00; //Set *bossMinPhysicalResistance to 30.00;
	*bossCritChance = (double)((rand() % 10 + 20) / 100); //Set *bossCritChance to a randomized number in the range between 10 to 20 inclusively;
	*bossMaxCritDamage = 1.00; //Set *bossMaxCritDamage to 100.00;
	*bossMinCritDamage = 3.00; //Set *bossMinCritDamage to 300.00;
													/*END of your solution*/
};

void introduction() {
	printf("Welcome to your Programming Assignment 1!\n");
	printf("In this assigment, you will have to choose one of the 3 classesto defeat Silva.\n");
	printf("You can choose to be a WARRIOR, a MAGE or an Archer.\n ");
	printf("1. Warrior\n ");
	printf("2. Mage\n ");
	printf("3. Archer\n");
	printf("Please select your class with the coresponding numbers. ");
	printf("Selection: ");
}

int getUserInput(int numOfChoices) {
	int number;
	while (1 == 1) // Always true, C is stupid
	{
		scanf("%d", &number);
		for (int i = 1; i <= numOfChoices; i++) // Loops through the possible choices
		{
			if (number == i)
			{
				printf("\n");
				return i;
			}
		}
		//Error Message
		fseek(stdin, 0, SEEK_END); //Flush input buffer
		printf("<----------------------------------------------------------------------------->\n");
		printf("Invalid Input Error: Please enter a one of the number above!\n");

	}

	return number;
}

void applyHealAmount(double *targetHealth, double *targetMaxHealth, double healAmount)
{
	if (*targetHealth + healAmount > *targetMaxHealth)
	{
		*targetHealth = *targetMaxHealth;
	}
	else
	{
		*targetHealth += healAmount;
	}
}

//GAME ENGINE:

int processInput(int opCode)
{
	int temp;
	switch (opCode)
	{
	case 0: //Class Selection
		temp = getUserInput(3);
		if (temp == 1)
		{
			return 1;
		}
		else if (temp == 2)
		{
			return 2;
		}
		else if (temp == 3)
		{
			return 3;
		}
		break;
	case 1: //Action Selection
		temp = getUserInput(2);
		if (temp == 1)
		{
			return 2;
		}
		else if (temp == 2)
		{
			return 3;
		}
		break;
	}

}

void render(int opCode, double *renderArgument1, double *renderArgument2)
{
	switch (opCode)
	{
	case 0:
		introduction();
		break;
	case 1: //Display Player Menu
		printf("<--------------------------------------------------------->\n");
		printf("1. Attack\n");
		printf("2. Heal\n");
		printf("Selection: ");
		break;
	case 2:
		printf("<--------------------------------------------------------->\n");
		printf("You deal %d damage to the boss!\n", (int)*renderArgument1);
		break;
	case 3:
		printf("<--------------------------------------------------------->\n");
		printf("You heal %d health!\n", (int)*renderArgument1);
		break;
	case 4:
		printf("<--------------------------------------------------------->\n");
		printf("Boss deals %d damage to you!\n", (int)*renderArgument1);
		break;
	case 5:
		printf("Boss heals %d health!\n", (int)*renderArgument1);
		break;
	case 6:
		printf("<--------------------------------------------------------->\n");
		printf("Player's Health %d\n", (int)*renderArgument1);
		printf("Boss Health: %d\n", (int)*renderArgument2);
		break;
	case 7:
		printf("<--------------------------------------------------------->\n");
		printf("Congratulations! You Defeated the Boss!\n");
		break;
	case 8:
		printf("<--------------------------------------------------------->\n");
		printf("YOU DIED!!! Well at least you got the game running XD");
		break;
	}
}

int updateGame(int opCode, double *updateGameParameters[])
{

	/*
	0: playerHealth;
	1: playerMaxHealth;
	2: playerAttack;
	3: playerMaxPhysicalResistance
	4: playerMinPhysicalResistance;
	5: playerCritChance;
	6: playerMaxCritDamage;
	7: playerMinCritDamage;
	8: bossHealth;
	9: bossAttack;
	10: bossMaxPhysicalResistance;
	11: bossMinPhysicalResistance;
	12: bossCritChance;
	13: bossMaxCritDmg;
	14: bossMinCritDmg;
	*/
	//FUNCTION
	int renderOpCode = -1;
	double *renderArgument1 = NULL;
	double *renderArgument2 = NULL;
	renderArgument1 = malloc(sizeof(double));
	renderArgument2 = malloc(sizeof(double));

	switch (opCode)
	{
	case 0: //Create Warrrior CHECKED
		createPlayerCharacter(processInput(0), updateGameParameters[0], updateGameParameters[1], updateGameParameters[2], updateGameParameters[3], updateGameParameters[4], updateGameParameters[5], updateGameParameters[6], updateGameParameters[7]);
		break;
	case 1: //Create Boss CHECKED
		createBoss(updateGameParameters[8], updateGameParameters[9], updateGameParameters[10], updateGameParameters[11], updateGameParameters[12], updateGameParameters[13], updateGameParameters[14]);
		break;
	case 2: //Player Attacks
		*renderArgument1 = calculateDamageAmount(updateGameParameters[10], updateGameParameters[11], updateGameParameters[6], updateGameParameters[7], updateGameParameters[5], updateGameParameters[2]);
		*updateGameParameters[8] -= *renderArgument1; //Subtract damage from boss health
		renderArgument2 = updateGameParameters[8];
		render(2, renderArgument1, renderArgument2);
		if (*updateGameParameters[8] <= 0)
		{
			render(7, NULL, NULL);
			return 0;
			break;
		}
		render(6, updateGameParameters[0], updateGameParameters[6]);
		break;
	case 3: //Player Heals CHECKED
		*renderArgument1 = calculateHealAmount(updateGameParameters[3], updateGameParameters[4], updateGameParameters[6], updateGameParameters[7], updateGameParameters[5], updateGameParameters[2]);
		applyHealAmount(updateGameParameters[0], updateGameParameters[1], *renderArgument1);
		render(3, renderArgument1, NULL);
		render(6, updateGameParameters[0], updateGameParameters[8]);
		break;
	case 4: //Boss Attacks
		*renderArgument1 = calculateDamageAmount(updateGameParameters[3], updateGameParameters[4], updateGameParameters[13], updateGameParameters[14], updateGameParameters[12], updateGameParameters[9]);
		*updateGameParameters[0] -= *renderArgument1;
		render(4, renderArgument1, NULL);
		if (*updateGameParameters[0] <= 0)
		{
			render(8, NULL, NULL);
			return 0;
			break;
		}
		render(6, updateGameParameters[0], updateGameParameters[6]);
		break;
	case 5: // Boss Heals CHECKED
		*renderArgument1 = calculateHealAmount(updateGameParameters[10], updateGameParameters[11], updateGameParameters[13], updateGameParameters[14], updateGameParameters[12], updateGameParameters[9]);
		*renderArgument2 = 50000.0;
		applyHealAmount(updateGameParameters[8], renderArgument2, *renderArgument1);
		render(5, renderArgument1, NULL);
		break;
	}
	return 1;
}

int AI(double *updateGameParameters[])
{
	if (*updateGameParameters[8] > 15000)
	{
		return 4; // attack
	}
	else
	{
		return 5;
	}
}

int main() {
	//Student Info
	char name[50];
	int ID;

	//CHARACTER 
	//const char roleName1[10] = { 'W','a','r','r','i','o','r' };
	//const char roleName2[10] = { 'M','a','g','e' };
	//const char roleName3[10] = { 'A','r','c','h','e','r' };
	double playerHealth;
	double playerAttack;
	double playerMaxHealth;
	//CHARACTER STATS
	double playerMaxPhysicalResistance;
	double playerMinPhysicalResistance;
	double playerCritChance;
	double playerMaxCritDamage;
	double playerMinCritDamage;


	//BOSS STATS
	char bossName[10] = { 'S', 'i', 'l', 'v', 'a' };
	double bossHealth;
	double bossAttack;
	double bossMaxPhysicalResistance;
	double bossMinPhysicalResistance;
	double bossCritChance;
	double bossMaxCritDamage;
	double bossMinCritDamage;

	double *updateGameParameters[15];

	int isGameRunning = 1;

	updateGameParameters[0] = &playerHealth;
	updateGameParameters[1] = &playerMaxHealth;
	updateGameParameters[2] = &playerAttack;
	updateGameParameters[3] = &playerMinPhysicalResistance;
	updateGameParameters[4] = &playerMaxPhysicalResistance;
	updateGameParameters[5] = &playerCritChance;
	updateGameParameters[6] = &playerMinCritDamage;
	updateGameParameters[7] = &playerMaxCritDamage;


	updateGameParameters[8] = &bossHealth;
	updateGameParameters[9]  = &bossAttack;
	updateGameParameters[10] = &bossMinPhysicalResistance;
	updateGameParameters[11] = &bossMaxPhysicalResistance;
	updateGameParameters[12] = &bossCritChance;
	updateGameParameters[13] = &bossMinCritDamage;
	updateGameParameters[14] = &bossMaxCritDamage;

	/*
	0: playerHealth;
	1: playerMaxHealth;
	2: playerAttack;
	3: playerMaxPhysicalResistance;
	4: playerMinPhysicalResistance;
	5: playerCritChance;
	6: playerMaxCritDamage;
	7: playerMinCritDamage;
	8: bossHealth;
	9: bossAttack;
	10: bossMaxPhysicalResistance;
	11: bossMinPhysicalResistance;
	12: bossCritChance;
	13: bossMaxCritDmg;
	14: bossMinCritDmg;
	*/

	render(0, NULL, NULL);
	updateGame(0, updateGameParameters);
	updateGame(1, updateGameParameters);
	while (isGameRunning == 1)
	{
		render(1, NULL, NULL);
		isGameRunning = updateGame(processInput(1), updateGameParameters);
		if (isGameRunning != 1)
		{
			break;
		}
		isGameRunning = updateGame(AI(updateGameParameters), updateGameParameters);
	}
	getchar();
	return 0;
};