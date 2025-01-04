// Julia Brand
// Due 9/10/24
// Calculates the cost for a bounce house rental

#include <stdio.h>

#define MIN1 58
#define MIN2 85
#define MIN3 100
#define MIN4 180

#define HR1 8
#define HR2 12
#define HR3 15
#define HR4 20

#define MAX1 80
#define MAX2 120
#define MAX3 150
#define MAX4 250

int main(void) 
{
  int bh; // bounce house number selection
  int days;
  int hours;
  int cost;
  int excess; // excess hours after minimum

  printf("Please select from four bounce houses: 1, 2, 3, and 4 \n");
  printf("Enter bounce house selection: ");
  scanf("%d", &bh);

  if (bh < 1 || bh > 4) 
  {
    printf("Invalid selection. Select from 1 to 4.");
  } 
  else 
  {
    printf("Enter days: ");
    scanf("%d", &days);

    printf("Enter hours: ");
    scanf("%d", &hours);

    if (hours < 0 || hours > 24) 
    {
      printf("Invalid hours.");
    } 
    else 
    { 
      if(bh == 1)
        {
          cost = 0;
          excess = hours - 3;

          if(days == 0) 
          {
            if(hours <= 3)
            {
              cost += MIN1;
            }
            else if(MIN1 + (excess * HR1) > MAX1) //hourly exceeds maximum
            {
              cost += MAX1;
            }
            else
            {
              cost += MIN1;
              cost += (excess * HR1);
            }
          }
          else //multiday rentals do not include the 3 hour fee
          {
            cost += days * MAX1;

            if(hours * HR1 > MAX1) //hourly exceeds maximum
            {
              cost += MAX1;
            }
            else
            {
              cost += hours * HR1;
            }
          }
          printf("Charge($): %d", cost);
        }
      else if (bh == 2) 
      {
        cost = 0;
        excess = hours - 3;

        if(days == 0)
        {
          if(hours <= 3)
          {
            cost += MIN2;
          }
          else if(MIN2 + (excess * HR2) > MAX2) //hourly exceeds maximum
          {
            cost += MAX2;
          }
          else
          {
            cost += MIN2;
            cost += (excess * HR2);
          }
        }
        else //multiday rentals do not include the 3 hour fee
        {
          cost += days * MAX2;

          if(hours * HR2 > MAX2) //hourly exceeds maximum
            {
              cost += MAX2;
            }
            else
            {
              cost += hours * HR2;
            }
        }
        printf("Charge($): %d", cost);
      }
      else if (bh == 3) 
      {
        cost = 0;
        excess = hours - 3;

        if(days == 0)
        {
          if(hours <= 3)
          {
            cost += MIN3;
          }
          else if(MIN3 + (excess * HR3) > MAX3) //hourly exceeds maximum
          {
            cost += MAX3;
          }
          else
          {
            cost += MIN3;
            cost += (excess * HR3);
          }
        }
        else //multiday rentals do not include the 3 hour fee
        {
          cost += days * MAX3;

          if(hours * HR3 > MAX3) //hourly exceeds maximum
            {
              cost += MAX3;
            }
            else
            {
              cost += hours * HR3;
            }
        }
        printf("Charge($): %d", cost);
    }
      else if (bh == 4) 
      {
        cost = 0;
        excess = hours - 3;

        if(days == 0)
        {
          if(hours <= 3)
          {
            cost += MIN4;
          }
          else if(MIN4 + (excess * HR4) > MAX4) //hourly exceeds maximum
          {
            cost += MAX4;
          }
          else
          {
            cost += MIN4;
            cost += (excess * HR4); 
          }
        }
        else //multiday rentals do not include the 3 hour fee
        {
          cost += days * MAX4;

          if(hours * HR4 > MAX4) //hourly exceeds maximum
            {
              cost += MAX4;
            }
            else
            {
              cost += hours * HR4;
            }
        }
        printf("Charge($): %d", cost);
      }
    }
  }
   return 0;
}