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
 int get_ways(unsigned long p){
   int ways = 0;
   if(p < 10)
   {
     if(check_prime_number(p))
     {
       return 1;
     }
     return 0;
   }
    int count = 0;
    int length = get_length(p);
    while (count < length) {
      long n = remove_digit(count,p);
      if(check_prime_number(n))
      {
        int the_way = get_ways(n);
        ways += the_way;
      }
      count++;
    }
   return ways;
 }
 bool check_prime_number(unsigned long number)
 {
   long divison = 2;
   long primeNumber = number;

   while(primeNumber % divison != 0 && primeNumber != 1)
   {
       divison++;
   }
   if (primeNumber == divison)
   {
       return true;
   }
   return false;
 }
int get_length(unsigned long number)
{
  int count_length = 0;
  int shortend_number = 0;
  do{
    count_length++;
    shortend_number = number/pow(10,count_length);
  }while(shortend_number != 0);
  return count_length;
}
