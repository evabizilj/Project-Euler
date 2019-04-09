/*
Counting Sundays

You are given the following information, but you may prefer 
to do some research for yourself.
1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, 
but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the 
twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>

int main()
{
    int day = 1;
    int month = 0;
    int sunday = 0;

    for (int year = 1901; year <= 2000; year++) 
        for (int month = 1; month <= 12; month++)
        {
            if ((day + 1) % 7 == 0)
                sunday++;
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                for (int i = 1; i <= 31; i++)
                    day++;
            else if (month == 2)
            {
                if ((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))
                    for (int i = 1; i <= 29; i++)
                        day++;
                else
                    for (int i = 1; i <= 28; i++)
                        day++;
            }
            else
                for (int i = 1; i <= 30; i++)
                    day++;
        }
    printf("Answer is: %d\n", sunday);
    return 0;
}