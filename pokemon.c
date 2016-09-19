#include<stdio.h>
#include<stdlib.h>

int getTwoSmall(int a,int b)
{
	if (a < b)
	return a;
	return b;
}

int getThreeSmall(int a,int b,int c)
{
	return a<b?(a<c?a:c):(b<c?b:c);
}

float calculateItem(int *item1, int *item2, int cost1, int cost2)
{
	int small = 0;
	small = getTwoSmall(*item1,*item2);
	*item1 = *item1 - small;
	*item2 = *item2 - small;
	return small * ((cost1 + cost2) - (cost1 + cost2) * 0.1);
}	

int main()
{ 
	int option=5,getnumber=0,noOfPikachu=0,noOfSquirtle=0,noOfCharmander=0;
	int pikachuPrice = 6, squirtlePrice = 5, charmanderPrice = 5;
	int small = 0;
	float totalAmount = 0;
	do{
		printf("Please select the option number :\n1.Pikachu\n2.Squirtle\n3.Charmander\n4.Proceed to Payment\n5.Exit\n\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1 : 	printf("Please enter the number of Pikachu you want : ");
						scanf("%d",&getnumber);
						noOfPikachu+=getnumber;
						break;
			case 2 : 	printf("Please enter the number of Squirtle you want : ");
						scanf("%d",&getnumber);
						noOfSquirtle+=getnumber;
						break;
			case 3 : 	printf("Please enter the number of Charmander you want : ");
						scanf("%d",&getnumber);
						noOfCharmander+=getnumber;
						break;
			case 4 : 	if(noOfPikachu < 0 || noOfSquirtle < 0 || noOfCharmander < 0)
						{
							printf("There is a negative number entry. Your total amount is $0. Thank You!! See you soon\n");
							exit(0);
						}else{
							printf("Total number of item selected : \n");
					        printf("Pikachu : %d 	Squirtle : %d 	Charmander : %d\n\n",noOfPikachu,noOfSquirtle,noOfCharmander);
						}
						break;
			case 5 : 	printf("Thank You!!!. See You Soon\n\n");
						break;
			default : 	printf("Please Select any option from 1 to 5\n");
		}
		if(option == 4)
			break;

	}while(option != 5);

	/*Case where all three types of Pokemon are not zero*/
	if(noOfPikachu != 0 && noOfSquirtle != 0 && noOfCharmander != 0)
	{
		small = getThreeSmall(noOfPikachu,noOfSquirtle,noOfCharmander);
		noOfPikachu = noOfPikachu - small;
		noOfSquirtle = noOfSquirtle - small;
		noOfCharmander = noOfCharmander - small;
		totalAmount = small * ((pikachuPrice + squirtlePrice + charmanderPrice) - (pikachuPrice + squirtlePrice + charmanderPrice) * 0.2);
	}
	/*Case where two types of Pokemon are not zero*/
	if(noOfPikachu == 0)
	{
		totalAmount = totalAmount + calculateItem(&noOfSquirtle,&noOfCharmander,squirtlePrice,charmanderPrice);

	}else if (noOfSquirtle == 0)
	{
		totalAmount = totalAmount + calculateItem(&noOfPikachu,&noOfCharmander,pikachuPrice,charmanderPrice);

	}else if (noOfCharmander == 0)
	{
		totalAmount = totalAmount + calculateItem(&noOfPikachu,&noOfSquirtle,pikachuPrice,squirtlePrice);
	}
	
	/*Calculating the final type of Pikachu if its non zero*/
	totalAmount = totalAmount + pikachuPrice * noOfPikachu + squirtlePrice * noOfSquirtle + charmanderPrice * noOfCharmander;

	printf("Total Amount is : $%.2f\n",totalAmount);

	return 0;

}