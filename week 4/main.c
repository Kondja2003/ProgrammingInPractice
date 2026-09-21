#include <stdio.h>
int main() {
  int registrationStatus;
  char supplierName[50];
  float budget;
  float supplierPrice;
  int documentsComplete;

  printf("TENDER EVALUATION\n");
  printf("------------------\n");

  printf("Enter supplier name: ");
  scanf("%45s", supplierName);

  printf("Enter budget: ");
  scanf("%f", &budget);

  printf("Enter supplier price: ");
  scanf("%f", &supplierPrice);

  printf("Is supplier registered? (1=Yes, 0=No): ");
  scanf("%d", &registrationStatus);

  printf("Are all documents complete? (1=Yes, 0=No): ");
  scanf("%d", &documentsComplete);

  if (registrationStatus == 1 && documentsComplete ==0)
  {
    printf("\nsupplier: %s\n", supplierName);
    printf("Status : Disqualified\n");

  } 
     if (supplierPrice > budget) 
    {
      printf("\nSupplier: %s\n", supplierName);
      printf("Status: Disqualified\n");
    }else
    {
      printf("\nSupplier: %s\n", supplierName);
      printf("Status: Qualified\n");
    }
    
  }