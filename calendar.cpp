#include <iostream>

bool isLeapYear(int cur_year)
{
    if (cur_year % 400 == 0)
    {return 1;}

    else if (cur_year % 4 == 0 && cur_year % 100 != 0)
    {return 1;}

    return 0;
}

int getWeekday(int cur_year, int cur_month, int cur_day)
{
    int last_nums = cur_year - (cur_year / 100 * 100);
    int year_code = (last_nums + (last_nums / 4)) % 7;
    int months_code[12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int century_code[7] = {4, 2, 0, 6, 4, 2, 0}; // 1700 - 2300 only
    int cur_century_c = cur_year / 100 - 17; // Getting the right array index for each century
//    bool (*pLeap) (cur_year); //!! Not necessary since the date is a parameter
//    pLeap = &isLeapYear;
//    if (cur_month == 2 && (*pLeap)(cur_year)) // If it's february and a leap year, add a day
//    {cur_day + 1;}
    int weekday = (year_code + months_code[cur_month-1] + century_code[cur_century_c] + cur_day) % 7;
    return weekday;
}

void getCalndr(int cur_year)
{
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::string weekdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
//    std::string f_weekday = weekdays[getWeekday(cur_year, 1, 1)];
    
    std::cout << "  -------------------------------" << std::endl;
    std::cout << "           Calendar - " << cur_year << std::endl;
    std::cout << "  -------------------------------" << std::endl << std::endl;
    int days;

    // The following section loops through each month to print the calendar
    for (int i = 0; i < 12; i++)
    {
//        bool (*pLeap) (cur_year);
//        pLeap = &isLeapYear; //TODO: Fix this
        if (i == 1 && isLeapYear(cur_year)) // If it's a february and a leap year, add a day
        {days = 29;}
        else
        {days = days_in_month[i];}

        std::cout << std::endl << "  --------------" << months[i] << "-------------" << std::endl;
        std::cout << "  Sun   Mon   Tue   Wed   Thu   Fri   Sat" << std::endl;

/*         switch (getWeekday(cur_year, 1, 1)) {  //TODO: Figure out a better way to do this...
        case 0:
            std::cout << "\t1";
            break;
        case 1:
            std::cout << "\t\t1";
            break;
        case 2:
            std::cout << "\t\t\t1";
            break;
        case 3:
            std::cout << "\t\t\t\t1";
            break;
        case 4:
            std::cout << "\t\t\t\t\t1";
            break;
        case 5:
            std::cout << "\t\t\t\t\t\t1";
            break;
        case 6:
            std::cout << "\t\t\t\t\t\t\t1";
            break;
        }
 */
        for (int v = 1; v <= 31; v++) //Loop for printing the month
        {
            if (i == 1 && v == 1) //The first day of January gets printed in the previous block
            {continue;} 

//            else if (v == days_in_month[i])
//            {break;}
            
            //int wd = getWeekday(cur_year, i, v); //TODO: Do this with a pointer
            int l = 0;
            while (l <= getWeekday(cur_year, 1, 1))
            {std::cout << "  "; l++;}

            std::cout << "  " << v;

            if (getWeekday(cur_year, i, v) == 6)
            {std::endl (std::cout);}
        }
    }
}

int main()
{
    getCalndr(2023);
    return 0;
}