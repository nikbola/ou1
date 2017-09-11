#include <stdio.h>
char assistant(double exrt, char option) /*Prints menu & scans for option input*/
{
  printf("\n1. Set exchange rate in SEK (current rate: %.2f)\n", exrt);
  printf("2. Read prices in the foreign currency\n");
  printf("3. End\n");
  printf("\nGive your choice (1 - 3): ");
  scanf("%s", &option);
  
  return option;
}

int main(void)
{
  double exrt = 1.00;
  printf("Your shopping assistant\n");
  char option = assistant(exrt, option);
  double pricesum = 0;
  double price = 0;
  
  while (option != '3')
    {
      if (option == '1') /*Asks for exchange rate if option input is equal to 1*/
	{
	  printf("\nGive exchange rate: ");
	  scanf("%lf", &exrt);
    
	  option = assistant(exrt, option);
	}
      else if (option == '2') /*Asks for price if option input is equal to 2*/
	{
	  printf("\nGive price (finish with < 0): ");
	  scanf("%lf", &price);
	  while (price >= 0)
	    {
	      if (price >= 0) /*Loops price input function as long as price is bigger than 0*/
		{
		  pricesum = pricesum + price;
		  printf("Give price (finish with < 0): ");
		  scanf("%lf", &price);
		}	
	    }
	  printf("\nSum in foreign currency: %.2lf\n", pricesum); /*Input smaller or equal to 0 ends the loop*/
	  printf("Sum in SEK: %.2lf\n", pricesum * exrt);
          option = assistant(exrt, option);
	}
      else if ((option != '1') && (option != '2')) /*If option input is neither 1, 2, or 3, the program restarts*/
        {
	  printf("\nNot a valid choice!\n");
	  option = assistant(exrt, option);
        }
    }

  printf("\nEnd of program!\n"); /*Ends program if option input is equal to 3*/
    
  return 0;
}

/*Niklas Bolin - dv17nbn*/
