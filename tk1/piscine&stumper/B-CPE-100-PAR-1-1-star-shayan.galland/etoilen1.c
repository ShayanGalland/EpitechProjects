/*
** EPITECH PROJECT, 2021
** etoiel1
** File description:
** 
*/
int etoile1(int x)
{
    int a = 3;
    int b = 3;

    while(a != 0){
        my_putchar(' ');
        a = a - 1;}
    my_putchar('*');
    my_putchar('$');
    my_putchar('\n');
    a = b;
    while(a != b){
        my_putchar('*');
        a = a - 1;}
    my_putchar(' ');
    while(a != b){
        my_putchar('*');
        a = a - 1;}
    my_putchar('$');
    my_putchar(' ');
    my_putchar('\n');
    my_putchar('*');
    a = b;
    while(a != 0){
	my_putchar(' ');
	a = a - 1;}
    my_putchar('*');
    my_putchar('$');
    my_putchar('\n');
       a = b;
    while(a != b){
	my_putchar('*');
	a = a - 1;}
    my_putchar(' ');
    while(a != b){
	my_putchar('*');
	a = a - 1;}
    my_putchar('\n');
	while(a != 0){
	my_putchar(' ');
	a = a - 1;}
    my_putchar('*');
    my_putchar('$');
    return(0);
}
