int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_print_comb(void) 
{
     char number1; 
     char number2; 
     char number3; 
     number1 = 48; 
     number2 = 49;
     number3 = 50;

     while(number1 + number2 + number3 <= 168)
     {
         while(number3 <= 57)
             (number2 <= number3);
         number3 = number3 + 1;
         }
         if(number2 <= 56)
         {
         else (number3 >= number2)
             number2 = number2 + 1;
         }
         
         my_putchar(number1);
         my_putchar(number2);
         my_putchar(number3);
         my_putchar(' ');
     }

     return(0); 
 } 

int main(void)
    
{
    my_print_comb();

    return(0);
}
