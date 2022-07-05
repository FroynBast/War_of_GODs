# War_of_GODs
-Firstly code starts to work
-Then program defines global defined structs
-Program calls all funciton first to know eachone
-When it enters main funciton program define all soldiers and empty slots and get enter the grand_menu() which controls all program
-In the grand_menu() program gets an input from user which transfer program to the beforeWarSet(), War() funciton or to ends program it breaks the loop
-There is no control when program goes beforeWarSet() but user must select atleast 2 soldiers for the war so that program calls a funciton to control it which is controlsufficiency()
-controlsufficiency() function looks for is there atleast 2 soldiers in the user's slot and returns a number for enoughness 1 or there is not enough for war 0
  
  -In beforeWarSet() program takes an input from user to transfer program showSoldiers(),selecting(),releasing() or showSelected() funcions
	-Program gets in the showSoldiers() function when user enters 1 after that just shows soldiers names and then program want an input from user to show soldiers specificly , all of them or goes back
	-Program gets in the selecting() function when user enters 2 after that program wants a number for choosing slot and a number for the soldier when user enters correctly first program controls the 
  selected soldier in the selectedControl(siSoldier) funciton by passing users selected soldier number. when it takes 1 from this function, program calls selectingFunc(siSlot,siSoldier) by passing user's
  slot number and soldier number. Otherwise program gives errors which are wrong numbers or selected soldier warning.
		-In the selectedControl() function program compares soldiers in the slot unless all of them empty. in the if statement of if(strncmp(slot[i].name,s[Soldiernum-1].name,6)==0) it means that,
	if they are same comparison's result 0 so it enters this if statement. and break the loop with making equation of returning normal. Then return number.
		-In the selectingFunc() program makes equation of each structs by decreasing the entered values because program shows all soldiers and slots from 1 but in program they are starts from 0.
	-Program gets in the releasing() function which release soldier in the selected slot. When program gets an input for release the slot, it calls the releasingFunc(release-1) and transfers the input
  with decreasing it by 1 because program shows slot starts from 1 but slots starts in the memory of program from 0.
		-In the releasingFunc() program makes equation of empty in name and type and make equal damage and hitPoint 0.
	-Program calls the showSelected() function when user enters 4 after that program shows users.
	-when user enters 0 program goes back to the grand_menu()

  -In the War() function program generates random number with using time of the your pc as seed by srand(time(0)) function (this function in the <time.h> library) for choosing ai's soldier. When  program 
generate random cods, program passes them in the selectingAi(rand()%LIMIT,rand()%SOLDIER) by %4 and %10 this means first just can be 0 to 3 and other is 0 to 9 that what we just want. When it is completed,
program shows ai's soldiers and user's soldiers for takes an input from user and control it if it is not empty, program goes to aiSoldier(attackNum-1) function and passes selected soldiers address decreasing it
by one. Ai select the best enemy for that and then program calls the battleZone(attackNum-1,aiHitNum) function for making a battle just once. Then, program goes outingSoldier() function and looks for is there 
any killed soldier then program calls SoldierCheck() funciton to check ai and user's slots if atleast one of them are fully empty, war finishes and program returns the grand_menu().
	-In the selectingAi() program first compares the random number of soldier, is there any sameness in the other slots, if the soldier has already be choosen, program goes back for takes new random slot and
  soldier number. If there is any similarity program makes copies soldier in the ai slot
	-In the aiSoldier() function first program copies ai's soldiers damage which are equal or more than user's soldier and then in this equation of array program choose lowest one because game has a rule which
  is high damage low hp(hitPoint). Then, program looks which slot has equal damage with this selected number. If there is any, program choose highest damage soldier in the slot and returns the slot id.
	-In the battleZone() funciton both soldiers damage each other.
	-In the outingSoldier() if there is a soldier in the slot which has equal or less than 0 hitPoint, program calls releasingFunc(i) or releasingFuncAi(j) by passing the number of initial of for loop.
	-In the SoldierCheck() program looks the slots. If all slots of user empty (has 0 damage) program adds 1 to controlSlot if ai's slots are empty too, program adds 1 to controlAi, and returns a number which 
  are can be 0 1 2 or 3.
