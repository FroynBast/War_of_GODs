//      		FroynBast
//			Mechatronics Engineering 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// library for struct
#include <time.h>	// library to the generate seed for the random number
#define SOLDIER 10	// this is the game's soldier number
#define LIMIT 4		// this is the highest slot's number

typedef struct{
        char name[15];
        char type[14];
        int  damage;
        int  hitPoint;
}soldiers;

soldiers s[SOLDIER];	//global defined struct which is the games soldiers
soldiers slot[LIMIT];	//global defined struct of user's slot
soldiers ai[LIMIT];		//global defined struct of ai's slot

int aiSoldier(int selectedNum);
void selectingAi(int randomslot,int randomsoldier);
int SoldierCheck();
void battleZone(int slotSoldier,int aiSoldier);
void outingSoldier();
void WAR();
void selectingFunc(int slotnum,int soldiernum);
void releasingFunc(int Slotnum);
void releasingFuncAi(int Ainum);
int selectedControl(int Soldiernum);
void selecting();
void releasing();
void showSelected();
void showSoldiers();
void beforeWarSet();
int controlsufficiency();
void grand_menu();

int main(int argc, char *argv[])
{
	strcpy(s[0].name,"Kayra Khan    ");
	strcpy(s[1].name,"Umay Mother   ");
	strcpy(s[2].name,"Kizagan Tengri");
	strcpy(s[3].name,"Mergen Tengri ");
	strcpy(s[4].name,"Od Mother     ");
	strcpy(s[5].name,"Erlik Khan    ");
	strcpy(s[6].name,"Mr Ulgen      ");
	strcpy(s[7].name,"Yayik Khan    ");
	strcpy(s[8].name,"Archura Demon ");
	strcpy(s[9].name,"Dragon Bukrek ");
	strcpy(s[0].type,"Mage(Creator)");
	strcpy(s[1].type,"Archer       ");
	strcpy(s[2].type,"Warrior      ");
	strcpy(s[3].type,"Archer       ");
	strcpy(s[4].type,"Mage(Fire)   ");
	strcpy(s[5].type,"Assasin      ");
	strcpy(s[6].type,"Archer       ");
	strcpy(s[7].type,"Mage(Water)  ");
	strcpy(s[8].type,"Mage(Nature) ");
	strcpy(s[9].type,"Mage(Water)  ");
	s[0].damage=750;
	s[1].damage=425;
	s[2].damage=300;
	s[3].damage=450;
	s[4].damage=500;
	s[5].damage=550;
	s[6].damage=500;
	s[7].damage=500;
	s[8].damage=250;
	s[9].damage=450;
	s[0].hitPoint=1000;
	s[1].hitPoint=850;
	s[2].hitPoint=1300;
	s[3].hitPoint=650;
	s[4].hitPoint=700;
	s[5].hitPoint=600;
	s[6].hitPoint=700;
	s[7].hitPoint=750;
	s[8].hitPoint=1650;
	s[9].hitPoint=800;

	strcpy(slot[0].name,"Empty         ");
	strcpy(slot[1].name,"Empty         ");
	strcpy(slot[2].name,"Empty         ");
	strcpy(slot[3].name,"Empty         ");
	strcpy(slot[0].type,"Empty        ");
	strcpy(slot[1].type,"Empty        ");
	strcpy(slot[2].type,"Empty        ");
	strcpy(slot[3].type,"Empty        ");
	    
	slot[0].damage=0;
	slot[1].damage=0;
	slot[2].damage=0;
	slot[3].damage=0;
	slot[0].hitPoint=0;
	slot[1].hitPoint=0;
	slot[2].hitPoint=0;
	slot[3].hitPoint=0;

	//program goes to the menu wich will run entire code 
	grand_menu();
    
  system("PAUSE");	
  return 0;
}
void grand_menu()
{
   int userinput=3,control1=0;
   while(control1==0)//program runs until user enter 0
   {
    	printf("\n\n Please select an option to continue:\n 1) Before war set\n 2) Start the war\n 0) Quit\n Please make your choice:\n");
    	scanf("%d",&userinput);	//program gets the number which will choose the down menu
    	fflush(stdin);//clearing buffer if the user enters a char character or something else
    	switch(userinput)	//program compare which number has entered
    	{
    		case 1:	//if user enter 1 program does under of this case
    			beforeWarSet();	//program calls this function for before war set
    			break;	//program goes out from switch
    		case 0:	//if user enter 0 program does under this case
    			control1=1;	//program set control1 to goes out from while loop
    			break;	//program goes out from switch
    		case 2:	//if user enter 2 program does under this case
    			if(controlsufficiency()==1)	//user must choose 2 soldier before the war so that this function control is there enough soldier selected
    								   	//1 means that there is enough soldier for war
    			{
					WAR();//program calls war funciton
      				break;//program goes out from switch
      			}
      			else
      			{
		  			printf("You have to choose at least 2 soldiers!");//if there is not enough soldier(less than 2) program gives warning
		  			break;//program goes out from switch
				}
      		default://this controls other numbers insted case numbers to express what is wanted 
      			printf("You entered wrong number!\n");//after warning switch is over because of this is the last part of switch
     	}
   }
}
int controlsufficiency()//controls that is there enough soldier selected before the war 
{
	int control=0,i,num;
	for(i=0;i<LIMIT;i++)//control all selected slots for there is at least 2 soldier
		if(slot[i].damage!=0)//if there is soldier it means that its damage more than 0
			control+=1;//adds 1 for the number of soldier
	if(control>=2)//if soldier number bigger and equal 2 
		num=1;//num is control for the soldier number and 1 is correction for there is enough soldier
	else
		num=0;//0 means there is not enough soldier and gives warning to user for making choose him/her
	return num;//returning value of num to control soldier
}
void beforeWarSet()	//menu of before war set
{
    int user=5;		//this integer takes the enter of user
    while(user!=0)	//programs works until user enters 0 to goes back menu
    {
   		printf("\n ***Before war set*** \n\n ");	//menu emphasis
    	printf("Welcome to God's War!\nBe ready for War!\n 1) Show soldiers\n 2) Select your soldiers\n 3) Release a soldier\n 4) Show my army\n 0) Back\n");
    	scanf("%d",&user);	//takes user entered value
    	fflush(stdin);//clearing buffer if the user enters a char character or something else
    	switch(user)	//compares user chooses for making decision
    	{
      		case 1:
      		showSoldiers();	//to shows all soldiers of games calls funciton
      		break;	//goes out from switch
      		case 2:
      		selecting();	//calls function to select soldiers to user's slot
      		break;	//goes out from switch
      		case 3:
      		releasing();	//calls function to release user's selected soldiers
      		break;	//goes out from switch
      		case 4:
    		printf("\n\n***YOUR SOLDIERS***\n\n");
      		showSelected();	//calls function to show user's selected soldiers
      		break;	//goes out from switch
      		case 0:	//if user enter 0 program goes out to previous menu
      		break ;	//goes out from switch
      		default:	//looks for other entered values for giving errors to user
      		printf("You entered wrong number!\n");
    	}
   }
}
void showSoldiers()//shows all soldiers of games
{
    printf("\n ***Show Soldiers*** \n\n");
    int i1,j=0,input=12;
    for(i1 = 0;i1 < SOLDIER;i1++)//for express all soldier gives a loop to express all of them
    	printf("%2d) %s \n", i1+1 ,s[i1].name);//printf soldiers of ganes
    while(input!=0)//loop runs until user enters 0
    {
    	printf("\n 1-10) Select specific one of them to show features\n 11) Show all features\n 0) Back:\n");
    	scanf("%d",&input);//gets a decision from user 
    	fflush(stdin);//clearing buffer if the user enters a char character or something else
    	if(input==11)//show all soldiers with their features to the user if user enters 11
    	{
    		printf("ID|Name          | Type        | Damage| Hit Point\n");//separates soldiers names and features for understand easily
    		for(j=0;j<SOLDIER;j++)//SOLDIER is defined in program for 10 which is the number of soldiers
    			printf("%2d)%s|%s| %d   | %d     \n",j+1,s[j].name,s[j].type,s[j].damage,s[j].hitPoint);//prints soldiers one by one
		}
    	else if(input > 0 && input <11)//show a specific soldiers features of selected by user
    	{
    		printf("Name:%s\nType:%s\nDamage:%d\nHitpoint:%d\n",s[input-1].name,s[input-1].type,s[input-1].damage,s[input-1].hitPoint);
    		//program use -1 because soldiers id start from 1 intead 0 so that program must be decreas entered value by 1 to show true soldier
		}
    	else if(input==0)//if user enters 0 program goes out the loop of while returns back
    		printf("\n");
    	else//if user enters intead of all wanted number program gives an error message and takes a number again
    		printf("You haven't entered correctly!\n");   
    }    
}
void selecting()//user selects soldier for battle in this function
{
     int siSoldier=11,siSlot=5,i,i1,Compare;
     printf("\n ***Selection*** \n\n");
     
     while(siSlot!=0)//program works until user enters 0 in the part of choosing slot 
    {
     	printf("Your slot is;\n");
     	for(i=0;i<LIMIT;i++)//shows users soldiers in slot
     	{
    		printf("%d)Slot:%s %s %d %d \n",i+1,slot[i].name,slot[i].type,slot[i].damage,slot[i].hitPoint);
     	}
		printf(" 0-)Back\n 1-4)Choose slot you want to select\n");
		scanf("%d",&siSlot);//program takes a slot number for place a soldier
		fflush(stdin);//clearing buffer if the user enters a char character or something else
        if(siSlot > 0 && siSlot < 5)//program controls that does user enter correct slot number if it is correct does under this if statement
        {
        	printf("ID|Name          | Type        | Damage | Hit Point\n");//separates soldiers names and features for understand easily
    		for(i1=0;i1<SOLDIER;i1++)//for express all soldier gives a loop to express all of them
    			printf("%2d|%s|%s| %d    | %d       \n",i1+1,s[i1].name,s[i1].type,s[i1].damage,s[i1].hitPoint);//shows all soldiers of game
        	scanf("%d",&siSoldier);//porogram takes a number of soldier which is wanted to choose for selected slot
        	fflush(stdin);//clearing buffer if the user enters a char character or something else
        	if(siSoldier > 0 && siSoldier < 11)//program control that does user entered correct soldier number
			{
        		Compare=selectedControl(siSoldier);//program calls a function to control user doesnot choose same soldier in the slot
        		if(Compare==1)//if user enters different soldier number program goes to place it
        		{
        			selectingFunc(siSlot,siSoldier);//calls a function to select soldier in the slot of selected and the soldier of selected
        			printf("You have selected %d) Slot : %s%s %d %d\n",siSlot,slot[siSlot-1].name,slot[siSlot-1].type,slot[siSlot-1].damage,slot[siSlot-1].hitPoint);
        			//program shows the selected slot and soldier but calls soldier decreasing number of it by 1 because program start to show them from 1 instead 0
   				}
   				else//if user enters same number of selected soldier gives an error message
   					printf("You have choosen selected soldier!\n");
   			}
   			else//if user enters wrong number of soldier (not between 1-10) program gives an error message
   				printf("***You have entered wrong number!\n");
		}
		else//if user enters wrong number of slot(not between 1-4) program gives an error message
			printf("***You have entered wrong slot number!\n");
    }
}
int selectedControl(int Soldiernum)//controls the selected soldier for is it selected before in other slot
{
	int i;
	int comp_result;
	for(i=0;i<LIMIT;i++)//control 4 slot of user
		if(strncmp(slot[i].name,"Empty",4)!=0)//if there is a soldier in slot it means it has a damage value different from 0 program controls it
		{
			for(i=0;i<LIMIT;i++)//control 4 slot of user
			{
				if(strncmp(slot[i].name,s[Soldiernum-1].name,6)==0)//control slots with i but program need to decrease the given number because 
																   //program stars to show slots from 1 intead 0
																   //if they are same it means that their ascii codes number same so returns 0 and gets in the if statement
				{
					comp_result=0;//assign 0 in the value for to use it return
					break ;//break the loop of second for
				}
			}
			if(comp_result==0)//if they are same it means compare result is 0 and this statement works
				return 0;//returns 0 for shows there is a similarity one of slot
			else//if there is any sameness this statement works
				return 1;//return 1 for shows there is not a similartiy
		}
		else//if all is 0 it means user doesn't choose a soldier and it works directly(if any selected there can't be similarity)
			return 1;
}
void selectingFunc(int slotnum,int soldiernum)//select soldier which is selected in the selecting menu
{
	//program decrease selected number because program starts to show soldiers from 1 instead 0
	strcpy(slot[slotnum-1].name,s[soldiernum-1].name);
	strcpy(slot[slotnum-1].type,s[soldiernum-1].type);
	slot[slotnum-1].damage=s[soldiernum-1].damage;
	slot[slotnum-1].hitPoint=s[soldiernum-1].hitPoint;
}
void releasing()//release soldiers of selected
{
	int release,i;
	printf("\n***RELEASING SOLDIER***\n\n");
	while(release!=0)//until user enter 0 loop works
	{
		printf("Your soldiers are;\n");
		printf("   ID     | Name | Type  | Damage| Hit Point\n");//separates soldiers names and features for understand easily
    	for(i=0;i<LIMIT;i++)//limit is defined 4 which is the limit of soldiers select limit
     	{
    		printf("%d)Slot:%s|%s| %d    | %d       \n",i+1,slot[i].name,slot[i].type,slot[i].damage,slot[i].hitPoint);//shows slots of user
     	}
    	printf(" 1-4)To release slot\n 0)Back\n");
    	scanf("%d",&release);//getting a choosed value for making decisions
    	fflush(stdin);//clearing buffer if the user enters a char character or something else
    	if(release > 0 && release < 5)//if user enters between the number 1-4 program releases it by calling function 
			releasingFunc(release-1);//program sent value by decreasing it by 1 because slots soldiers start showing from 1 instead the actual number which is 0
		else if(release==0)//if user enters 0 program goes out if and while loop to previous menu
			break;
		else//if user enters wrong value program shows a warning message
			printf("**You have entered wrong slot number!");
	}
}
void releasingFuncAi(int Ainum)//release an ai soldier which is killed in the battle
{
	strcpy(ai[Ainum].name,"Empty         ");
	strcpy(ai[Ainum].type,"Empty        ");
	ai[Ainum].damage=0;
	ai[Ainum].hitPoint=0;
}
void releasingFunc(int Slotnum)//release an user soldier which is selected in releasing part or killed in the battle
{
	strcpy(slot[Slotnum].name,"Empty         ");
	strcpy(slot[Slotnum].type,"Empty        ");
	slot[Slotnum].damage=0;
	slot[Slotnum].hitPoint=0;
}
void showSelected()//shows soldiers in user slot
{
	int i;
	printf("\n Your army:\n");
	printf("ID|Name          | Type        | Damage | Hit Point\n");//separates soldiers names and features for understand easily
    for(i=0;i<LIMIT;i++)//limit is defined 4 which is the limit of soldiers select limit
    {
    	printf("%2d|%s|%s| %d    | %d       \n",i+1,slot[i].name,slot[i].type,slot[i].damage,slot[i].hitPoint);//shows slots of user
    }
}
void outingSoldier()//looks for which soldier died in the battle
{
	int i,j;
	for(i=0;i<LIMIT;i++)
		if(slot[i].hitPoint<=0)//looks all users soldiers
		releasingFunc(i);//release the soldier in slot because soldier is dead
	for(j=0;j<LIMIT;j++)
		if(ai[j].hitPoint<=0)//look all ai soldiers
		releasingFuncAi(j);//release the soldier in slot because soldier is dead
}
void battleZone(int slotSoldier,int aiSoldier)//battle zone which soldiers giving damage each other
{
	slot[slotSoldier].hitPoint-=ai[aiSoldier].damage;//ai's soldier giving damage to user's soldier
	ai[aiSoldier].hitPoint-=slot[slotSoldier].damage;//user's soldier giving damage to ai's soldier
}
void WAR()//user fights in here
{
	int i,Check=2,attackNum=5,aiHitNum;
	printf("\n\n***WAR***\n\n");
	srand(time(0));//this is the function of random number creation for choose random soldier for ai
	while(ai[0].damage==0 || ai[1].damage==0 || ai[2].damage==0 || ai[3].damage==0)//controls that ai chooses soldier for all slots
	{
		selectingAi(rand()%LIMIT,rand()%SOLDIER);//calls selecting part of ai and send random value by revised them 4 and 10
	}
	printf("Choose wisely to attack!\nCause you cannot know which enemy will attack to you!\n\n");
    while(Check==2)//2 means war is continuing and loop keeps works
    {
    	printf("\n\n--------------\n\n");
		printf("Your enemies!\n");
    	for(i=0;i<LIMIT;i++)//works 4 times to show ai soldiers
    	{
    		printf("%s|%s| %d    | %d       \n",ai[i].name,ai[i].type,ai[i].damage,ai[i].hitPoint);
    	}
    	showSelected();//calls the function which works for to show user's soldiers
    	scanf("%d",&attackNum);//takes a value that user want to attack
    	fflush(stdin);//clearing buffer if the user enters a char character or something else
    	if(slot[attackNum-1].damage==0)//program uses value decreasing it by one and control it if user enters empty slot gives a warning message
    		printf("You should choose a slot which is between 1-4 and not empty!\n");
    	else//program works if there is a soldier in slot
    	{
    		aiHitNum=aiSoldier(attackNum-1);//program calls a function that chooses a soldier in ai slot to fight user's selected soldier
			printf("\n   Your Soilder   *** Ai Soldier     \n--------------------------\n");
			printf("   %s ***  %s\n",slot[attackNum-1].name,ai[aiHitNum].name);
			printf("   %s  ***  %s\n",slot[attackNum-1].type,ai[aiHitNum].type);
			printf("   %d           ****  %d\n",slot[attackNum-1].damage,ai[aiHitNum].damage);
			printf("   %d          ****  %d\n",slot[attackNum-1].hitPoint,ai[aiHitNum].hitPoint);
			battleZone(attackNum-1,aiHitNum);//program calls a function for battle zone to attack ai and user soldier each other
			printf("\n   Your Soilder   *** Ai Soldier     \n--------------------------\n");
			printf("   %s ***  %s\n",slot[attackNum-1].name,ai[aiHitNum].name);
			printf("   %s  ***  %s\n",slot[attackNum-1].type,ai[aiHitNum].type);
			printf("   %d           ****  %d\n",slot[attackNum-1].damage,ai[aiHitNum].damage);
			printf("   %d          ****  %d\n",slot[attackNum-1].hitPoint,ai[aiHitNum].hitPoint);
			outingSoldier();//program calls a funtion to control if there is dead soldier in slots, releases it
			Check=SoldierCheck();//program calls a function to check if ai or users slots are fully empty one of them is win
		}
	}
	if(Check==0)// if users slots are empty users loose and taking a message
		printf("You loose the war!\nLife will over!\nPress a button to returning back!\n");
	else if(Check==1)// if ai slots are empty users win and taking a message
		printf("You win the war! Well done!\nYou save the life!\nPress a button to returning back!\n");
	else if(Check==3)// Both ai and users slots are empty nobody wins
		printf("Nobody wins the war! Both side died!\nPress a button to returning back!\n");
	getch();
}
int SoldierCheck()//control the slot both side is there any soldier to fight
{
	int controlSlot=0,controlAi=0,i;
	for(i=0;i<LIMIT;i++)
	{
		if(slot[i].hitPoint!=0)//controls user's slots are there any one has hit point
			controlSlot+=1;//increase control number by 1
		if(ai[i].hitPoint!=0)//controls ai's slots are there any one has hit point
			controlAi+=1;//increase control number by 1
	}
	if(controlSlot==0&&controlAi==0)//if both side's slots are empty returns 3
		return 3;
	else if(controlSlot==0)//if user's slots are empty returns 0
		return 0;
	else if(controlAi==0)//if ai's slots are empty returns 1
		return 1;
	else//otherwise returns 2 to continue war
		return 2;
}
void selectingAi(int randomslot,int randomsoldier)//ai selects soldier for slots both are randomly
{
	int i,compResult=1;
	for(i=0;i<LIMIT;i++)
		if(strncmp(ai[i].name,s[randomsoldier].name,15)==0)//this is looking for are there any similar soldier 
		{
			compResult=0;//if there is a similarity makes compare results 0
			break ;//breaks for loop and goes out side of loop
		}
	if(compResult!=0)//if there is a similarity program doesn't enter this statement. if there is any program gets in this statement
	{
		//program copies soldier in the ai slot
		strcpy(ai[randomslot].name,s[randomsoldier].name);
		strcpy(ai[randomslot].type,s[randomsoldier].type);
		ai[randomslot].damage=s[randomsoldier].damage;
		ai[randomslot].hitPoint=s[randomsoldier].hitPoint;
	}
}
int aiSoldier(int selectedNum)//this function choose a soldier from ai slot to fight against user
{
	int ranking[LIMIT];
	int i,j=0,queueConstant=0,aiNum=0;
	for(i=0;i<LIMIT;i++)
		if(ai[i].damage>=slot[selectedNum].damage)//if ai's soldiers has damage similar or more than the user's soldier program choose it and save it in ranking array
			ranking[j++]=ai[i].damage;
	queueConstant=ranking[0];//making equation for making qualification for the soldier which is the equal or high right after user's choosen soldier
	for(i=1;i<j;i++)
		if(queueConstant>ranking[i] && ranking[i]!=0)//making lowest value for the hit the user
			queueConstant=ranking[i];
	if(queueConstant!=0)//if it is 0 it chooses empty slot so that it couldn't be 0
		for(i=0;i<LIMIT;i++)
			if(queueConstant==ai[i].damage)//choosing which address in the lowest values soldier
			{
				aiNum=i;//equation for the lowest soldier address in struct
				return i;//returning back the lowest damage value's soldier address
			}
	for(i=1;i<LIMIT;i++)
		if(ai[i].damage>ai[aiNum].damage)	//if there is any soldier has more or equal damage with user's soldier
			aiNum=i; //program selects soldier which has highest damage 
	return aiNum;//returning back the highest damage value's soldier address
}
