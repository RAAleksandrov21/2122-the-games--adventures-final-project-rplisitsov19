#include <iostream>
#include <limits>
#include <stdlib.h>
#include <string>
using namespace std;

string preRow[3] = { "  __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __",
					 " |                                                                                         |",
					 " |__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __|" };
//(text row preset) cout << "|     |\n";

struct weapon
{
	weapon(int dmg, string name)
	{
		weapon::dmg = dmg;
		weapon::name = name;
	}
	int dmg;
	string name;
}stick(5, "Stick"), sword(15, "Cutting edge Sword"), spear(10, "Spaghetti Spear"), shield(7, "Salvaged Shield");;

struct enemy
{
	enemy(int hp, string name)
	{		
		enemy::hp = hp;
		enemy::name = name;
	}
	int hp;
	string name;
	string wpn;
	int dmg;
}wolf(10, "Saber Wolf"), vent(20, "Vent"), muson(25, "Muson"), prez(30, "The President");

void setEnemyWpn()
{
	wolf.wpn = sword.name;
	wolf.dmg = sword.dmg;
	vent.wpn = spear.name;
	vent.dmg = spear.dmg;
	muson.wpn = shield.name;
	muson.dmg = shield.dmg;
	prez.wpn = "Nanomachines";
	prez.dmg = 6;
}

void next()
{
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	system("CLS");
}

string playerStats(int hp, string wpn, int dmg, int row) //hp = health points, wpnNum = weapon number
{
	string hpText(1, char(hp) + 48);
	string dmgText(1, char(dmg) + 48);
	string space1, space2; //dmg = damage, space1 = empty space for first row
	int sp1Len = 19, sp2Len = 10; //sp1Len = amount of spaces for first

	if (wpn == "Cutting edge Sword")
	{
		sp1Len += 14;
		sp2Len += 14;
	}
	else if (wpn == "Spaghetti Spear")
	{
		sp1Len += 11;
		sp2Len += 11;
	}
	else if (wpn == "Salvaged Shield")
	{
		sp1Len += 10;
		sp2Len += 10;
	}

	switch (row)
	{
	case 1:
		for (int i = 0; i < sp1Len; i++)
		{
			space1 += ' ';
		}
		return " | Dev" + space1 + "|";
		break;
	case 2:	
		if (hp > 9)
		{
			sp2Len--;
			string hp1(1, char(hp % 10) + 48), hp2(1, char(floor(hp / 10) + 48));
			hpText = hp2 + hp1;
		}
		for (int i = 0; i < sp2Len; i++)
		{
			space2 += ' ';
		}
		return " |  Health: " + hpText + "HP"+ space2 + "|";
		break;
	case 3:
		if (dmg > 9)
		{
			string dmg1(1, char(dmg % 10) + 48), dmg2(1, char(floor(dmg / 10) + 48));
			dmgText = dmg2 + dmg1;
		}
		return " |  Weapon: " + wpn + " - " + dmgText + "DMG |";
		break;
	}
}
string enemyStats(int hp, string name, int dmg, int row)
{
	string hpText(1, char(hp) + 48);
	string dmgText(1, char(dmg) + 48);
	string space1, space2;
	int sp1Len = 2, sp2Len = 1;

	if (name == "Saber Wolf")
	{
		sp1Len += 2;
	}
	else if (name == "Vent")
	{
		sp1Len += 8;
	}
	else if (name == "Muson")
	{
		sp1Len += 7;
	}

	if (dmg > 9)
	{
		sp1Len++;
		sp2Len++;
	}

	switch (row)
	{
	case 1:
		for (int i = 0; i < sp1Len; i++)
		{
			space1 += ' ';
		}
		return "| " + name + space1 + " |";
		break;
	case 2:
		if (hp > 9)
		{
			sp2Len--;
			string hp1(1, char(hp % 10) + 48), hp2(1, char(floor(hp / 10) + 48));
			hpText = hp2 + hp1;
		}
		for (int i = 0; i < sp2Len; i++)
		{
			space2 += ' ';
		}
		return "|   Health: " + hpText + "HP" + space2 + " |";
		break;
	case 3:
		if (dmg > 9)
		{
			string dmg1(1, char(dmg % 10) + 48), dmg2(1, char(floor(dmg / 10) + 48));
			dmgText = dmg2 + dmg1;
		}
		return "|   Attack: " + dmgText + "DMG" + " |";
		break;
	}
}
string preRowFunc(int row, int len, char c, bool side)
{
	string line = "";
	for (int i = 0; i < len; i++)
	{
		line += c;
	}

	if (row == 0)
	{
		line = " " + line + " ";
	}
	else
	{
		line = "|" + line + "|";
	}

	if (side)
	{
		return " " + line;
	}
	else
	{
		return line;
	}
}
void stats(int playerHp, int wpnDmg, string wpnName, int enemyhp, string enemyName, int enemyDmg)
{
	int rowLen1 = size(playerStats(playerHp, wpnName, wpnDmg, 3));
	int rowLen2 = size(enemyStats(enemyhp, enemyName, enemyDmg, 3));
	int gapSpace = size(preRow[1]) - (rowLen1 + rowLen2);
	rowLen1 -= 3;
	rowLen2 -= 2;
	string gap = "";
	for (int i = 0; i < gapSpace; i++)
	{
		gap += ' ';
	}

	cout << preRowFunc(0, rowLen1, '_', 1) << gap << preRowFunc(0, rowLen2, '_', 0) << endl;
	cout << preRowFunc(1, rowLen1, ' ', 1) << gap << preRowFunc(1, rowLen2, ' ', 0) << endl;
	cout << playerStats(playerHp, wpnName, wpnDmg, 1) << gap << enemyStats(enemyhp, enemyName, enemyDmg, 1) << endl;
	cout << playerStats(playerHp, wpnName, wpnDmg, 2) << gap << enemyStats(enemyhp, enemyName, enemyDmg, 2) << endl;
	cout << playerStats(playerHp, wpnName, wpnDmg, 3) << gap << enemyStats(enemyhp, enemyName, enemyDmg, 3) << endl;
	cout << preRowFunc(2, rowLen1, '_', 1) << gap << preRowFunc(2, rowLen2, '_', 0) << endl;
}

void text(int act, int turn)
{
	cout << preRow[0] << endl << preRow[1] << endl;
	switch (act)
	{
	case 0:
		cout << " |  Dev: *yawns* Where am I? It's so dark in here. Hey I can see what I'm saying as text.  |\n";
		cout << " |     Why is it in this font? This is very weird. The last thing I remember is...         |\n";
		cout << " |     *scratces head* falling asleep in front of my computer screen. I must've gotten     |\n";
		cout << " |     tired after all that programming. And what is this thing stuck on my belt?          |\n";
		cout << " |                          CONGRATULATIONS! YOU FOUND A 'Stick'!                          |\n";
		cout << " |  Dev: Wait a minute. That's like the first weapon in the game I'm making. And the name  |\n";
		cout << " |     infront of everything I say is 'Dev'. Is that short for 'Developer'? Am I in my     |\n";
		cout << " |     own game!? Does that mean I will have to fight against...                           |\n";
		break;
	case 1:
		switch (turn)
		{
		case 1:
			break;
		}
	}
	cout << preRow[2] << endl;
}

int checkHp(int player, int enemyhp)
{
	if (enemyhp <= 0)
	{
		return 1;
	}
	else if (player <= 0)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void attack(bool state)
{
	
}