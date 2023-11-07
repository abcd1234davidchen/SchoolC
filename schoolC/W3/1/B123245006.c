#include <stdio.h>
int main(void){
  //3.1
  int month,date;
  printf("Please enter the month:\n");
  scanf("%d",&month);

  if (month<=12&&month>=1){
    printf("Please enter the date:\n");
    scanf("%d",&date);
    switch (month){
      
      case 1:
      if (date<=31){
        //zodiac
        if (date>19){
          printf("%02d/%02d belongs to Aquarius.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Capricorn.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
      
      case 2:
      if (date<=29){
        //zodiac
        if (date>18){
          printf("%02d/%02d belongs to Pisces.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Aquarius.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    
      case 3:
      if (date<=31){
        //zodiac
        if (date>20){
          printf("%02d/%02d belongs to Aries.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Pisces.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    
      case 4:
      if (date<=30){
        //zodiac
        if (date>19){
          printf("%02d/%02d belongs to Taurus.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Aries.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    
      case 5:
      if (date<=31){
        //zodiac
        if (date>20){
          printf("%02d/%02d belongs to Gemini.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Taurus.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    
      case 6:
      if (date<=30){
        //zodiac
        if (date>20){
          printf("%02d/%02d belongs to Cancer.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Gemini.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    
      case 7:
      if (date<=31){
        //zodiac
        if (date>22){
          printf("%02d/%02d belongs to Leo.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Cancer.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
      
      case 8:
      if (date<=31){
        //zodiac
        if (date>22){
          printf("%02d/%02d belongs to Virgo.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Leo.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
      
      case 9:
      if (date<=30){
        //zodiac
        if (date>22){
          printf("%02d/%02d belongs to Libra.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Virgo.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
      
      case 10:
      if (date<=31){
        //zodiac
        if (date>22){
          printf("%02d/%02d belongs to Scorpio.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Libra.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    
      
      case 11:
      if (date<=30){
        //zodiac
        if (date>21){
          printf("%02d/%02d belongs to Sagittarius.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Scorpio.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    
      
      case 12:
      if (date<=31){
        //zodiac
        if (date>21){
          printf("%02d/%02d belongs to Capricorn.",month,date);
        }
        else{
          printf("%02d/%02d belongs to Sagittarius.",month,date);
        }
      }
      else{
        //error handling
        printf("Please enter correct date.");
      }
      break;
    }
  }
  else{
    printf("Please enter correct month.");
  }
  
return 0;
}
