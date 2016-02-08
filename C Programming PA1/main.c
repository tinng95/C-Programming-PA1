#include "GameEngine.h"

int main() {
	//printf("%s", mysql_get_client_info());
	//Student Info
	char firstName[50];
	char lastName[50];
	int ID;

	//CHARACTER 
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
	double bossHealth;
	double bossAttack;
	double bossMaxPhysicalResistance;
	double bossMinPhysicalResistance;
	double bossCritChance;
	double bossMaxCritDamage;
	double bossMinCritDamage;




	//DO NOT TOUCH, YOU CAN LOOK, BUT CANNOT TOUCH
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

	userInput(&firstName, &lastName, &ID);

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