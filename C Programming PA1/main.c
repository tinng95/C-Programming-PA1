#include <stdio.h>
#include <stdlib.h>

//Property of Daniel and Tin

double calculateHealAmount(double playerCritChance, double playerCritDamage, double playerPhysicalResistance, int attack)
{
	double healAmount;
	double random;
	random = rand() % 100 + 1;

	if (random <= playerCritChance) 
	{
		healAmount = ((((double)attack * 0.4) * (playerCritDamage)) * (playerPhysicalResistance + 1));
	}
	else 
	{
		healAmount = (((double)attack * 0.4) *(playerPhysicalResistance + 1));
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
		damageDealt = (double)(((double)attackerAttack * (attackerCritDamage)) * (targetPhysicalResistance));
	}
	else 
	{
		damageDealt = (double)((double)attackerAttack *(targetPhysicalResistance));
	}
	return damageDealt;
};

void createPlayerCharacter(int roleNumber, int *playerHealth, int *playerMaxHealth, int *playerAttack, double *playerPhysicalResistance, double *playerCritChance, double *playerCritDamage)
{
	switch(roleNumber)
{
		case 1: //Warrior: Low: attack, critChance. High: health, resistance, and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 10000; //Set *playersHealth to 10000;
			*playerMaxHealth = 10000; //Set *playerMaxHealth to 10000;
			*playerAttack = 300; //Set *playerAttack to 300;
			*playerPhysicalResistance = 0.80; //Set *playerPhysicalResistance to 0.80;
			*playerCritChance = 0.20; //Set *playerCritChance to 0.20;
			*playerCritDamage = 8.00; //Set *playerCritDamage to 8.00;
			/*END of your solution*/
			break;
		case 2: //Mage: Low: health and resistance. Medium: crit damage and crit chance High: attack
			/*BEGINNING of your solution*/
			*playerHealth = 4000; //Set *playersHealth to 4000;
			*playerMaxHealth = 4000; //Set *playerMaxHealth to 4000;
			*playerAttack = 1000; //Set *playerAttack to 1000;
			*playerPhysicalResistance = 0.30; //Set *playerPhysicalResistance to 0.30;
			*playerCritChance = 0.40; //Set *playerCritChance to 0.40;
			*playerCritDamage = 4.00; //Set *playerCritDamage to 4.00;
			/*END of your solution*/
			break;
		case 3://Archer: Medium: health, attack and resistance. High: crit chance and crit damage
			/*BEGINNING of your solution*/
			*playerHealth = 6000; //Set *playersHealth to 6000;
			*playerMaxHealth = 6000; //Set **playerMaxHealth to 6000;
			*playerAttack = 600; //Set *playerAttack to 600;
			*playerPhysicalResistance = 0.50; //Set *playerPhysicalResistance to0.50;
			*playerCritChance = 0.80; //Set *playerCritChance to 0.80;
			*playerCritDamage = 6.00; //Set *playerCritDamage to 6.00;
			/*END of your solution*/
			break ;
	}
};

void createBoss(int *bossHealth, int *bossAttack, double *bossPhysicalResistance, double *bossCritChance, double *bossCritDamage)
{
	/*BEGINNING of your solution*/
	*bossHealth = 50000; //Set *bossHealth to 50000
	*bossAttack = (rand() % 600 + 400.0); //Set *bossAttack to a randomized number in the range between 400 to 600 inclusively
	*bossPhysicalResistance = (rand() % 60 + 30.0) / 100; //Set *bossPhysicalResistance to a randomized number in the range between 30 to 60 inclusively
	*bossCritChance = (rand() % 20 + 10.0) / 100; //Set *bossCritChance to a randomized number in the range between 10 to 20 inclusively
	*bossCritDamage = (rand() % 250 + 100.0) / 100; //Set *bossCritDamage to a randomized number in the range between 100 to 250 inclusively
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

int playerMove()
{

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

void applyHealAmount(int *targetHealth, int *targetMaxHealth, double healAmount)
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

void render(int opCode, double *renderArgument1, double *renderArgurment2)
{
	switch (opCode)
	{
	case 0:
		introduction();
		break;
	case 1: //Display Player Menu
		printf("1. Attack\n");
		printf("2. Heal\n");
		printf("Selection: ");
		break;
	case 2:
		printf("You heal %d\n", (int) *renderArgument1);
		printf("Player's Health %d\n", (int) *renderArgurment2);
		break;
	}
}

int processInput(int opCode) 
{
	int temp;
	switch (opCode)
	{
	case 0: //Class Selection
		return getUserInput(3); // 1: Warrior, 2: Mage, 3: Archer
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

void updateGame(int opCode)
{
	//CHARACTER 
	const char roleName1[10] = { 'W','a','r','r','i','o','r' };
	const char roleName2[10] = { 'M','a','g','e' };
	const char roleName3[10] = { 'A','r','c','h','e','r' };
	int playerHealth;
	int playerAttack;
	int playerMaxHealth;
	//CHARACTER STATS
	double playerPhysicalResistance;
	double playerCritChance;
	double playerCritDamage;


	//BOSS STATS
	char bossName[10] = { 'S', 'i', 'l', 'v', 'a' };
	int bossHealth;
	int bossAttack;
	double bossPhysicalResistance;
	double bossCritChance;
	double bossCritDamage;

	//FUNCTION
	int renderOpCode = -1;
	double *renderArgument1 = NULL;
	double *renderArgument2 = NULL;
	renderArgument1 = malloc(sizeof(double));
	renderArgument2 = malloc(sizeof(double));

	switch (opCode)
	{
	case 0: //Create Warrrior
		createPlayerCharacter(processInput(0), &playerHealth, &playerMaxHealth, &playerAttack, &playerPhysicalResistance, &playerCritChance, &playerCritDamage);
		break;
	case 1: //Create Boss
		createBoss(&bossHealth, &bossAttack, &bossPhysicalResistance, &bossCritChance, &bossCritDamage);
		break;
	case 2: //Player Attacks
		*renderArgument1 = calculateDamageAmount(playerAttack, playerCritChance, playerCritDamage, bossPhysicalResistance);
		renderOpCode = 1;
		break;
	case 3: //Player Heals
		*renderArgument1 = calculateHealAmount(playerCritChance, playerCritDamage, playerPhysicalResistance, playerAttack);
		applyHealAmount(&playerHealth, &playerMaxHealth, *renderArgument1);
		renderOpCode = 2;
		break;
	}
	render(renderOpCode, renderArgument1, renderArgument2);
}



int main() {
	//Student Info
	char name[50];
	int ID;


	


	render(0, NULL, NULL);
	updateGame(0);
	updateGame(1);
	



	while (1 == 1)
	{
		render(1, NULL, NULL);
		updateGame(processInput(1));
	}

	/*
	while (1 == 1) //Game Loop NEEDS TO BE REDEISN
	{
		while (bossHealth > 0) // Gameplay Loop
		{
			double printfBuffer;
			switch (playerMove())
			{
			case 1:
				printfBuffer = 
				bossHealth = bossHealth - printfBuffer;
				printf("You deal: %lf damage\n", printfBuffer);
				printf("Boss Health: %d\n", bossHealth);
				break;
			case 2:
				printfBuffer = calculateHealAmount(playerCritChance, playerCritDamage, playerPhysicalResistance, playerAttack);
				applyHealAmount(&playerHealth, &playerMaxHealth, printfBuffer);
				printf("You heal %d\n", printfBuffer);
				printf("Player's Health %d\n", playerHealth);
				break;
			}
			//Boss print statement
			printfBuffer = calculateDamageAmount(bossAttack, bossCritChance, bossCritDamage, bossPhysicalResistance);
			playerHealth = playerHealth - printfBuffer;
			printf("Boss attacked you!\n");
			printf("Boss deal %d to you\n", (int)printfBuffer);
			printf("Player's Health %d\n", playerHealth);

			if (playerHealth <= 0)
			{
				printf("<----------------------------------------------------------------------------->\n");
				printf("You Died!, but hey at least you got the game working. XD\n");
				break;
			}
			else if (bossHealth <= 0)
			{
				printf("<----------------------------------------------------------------------------->\n");
				printf("Congrationlation you beat the boss, now go back to writing code.\n");
				break;
			}
		}
	}*/
return 0;
};