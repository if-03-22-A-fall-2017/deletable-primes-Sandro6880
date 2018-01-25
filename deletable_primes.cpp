/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
 #include "deletable_primes.h"
 #include <math.h>
 unsigned long remove_digit(int index, unsigned long n)
 {
   int divisor = pow(10,index+1);
   int multiplikator = pow(10,index);
   long result = n/divisor;
   result *= multiplikator;
   result += n % multiplikator;
   return result;
 }
 int index = 0;
 int get_ways(unsigned long p){

   int number = 0;
   if(p == 2||p== 3||p==5||p==7)
   {
     return ++number;
   }else{
     p = remove_digit(index,p);
     number += get_ways(p);
   }

   return number;
 }
