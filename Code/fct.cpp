#include<iostream>

using namespace std;

namespace Chrono {
    enum class Month { jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
    
    class Date {
        public: // public interface:
            class Bad_date { }; // exception class
            explicit Date(int dd ={}, Month mm ={}, int yy ={});   // {} means "pick a default"
            
            // nonmodifying functions for examining the Date:
            int day() const;
            Month month() const;
            int year() const;
            string string_rep() const;
            void char_rep(char s[], in max) const;

            // (modifying) functions for changing the Date:
            Date& add_year(int n);
            Date& add_month(int n);
            Date& add_day(int n);
        
        private:
            bool is_valid();
            int d, m, y;
    };

    bool is_date(int d, Month m, int y);        // true for valid date
    bool is_leapyear(int y);                    // true if y is a leap year
    
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    const Date& default_date();      // the default date
    
    ostream& operator<<(ostream& os, const Date& d);        // print d to os
    istream& operator>>(istream& is, Date& d);              // read Date from is into d
} //Chrono

Date::Date(int dd, Month mm, int yy)
    :d{dd}, m{mm}, y{yy}
{
    if(y==0) y = default_date().year();
    if(m==0) m = default_date().month();
    if(d==0) d = default_date().day();

    if(!is_valid()) throw Bad_date();

}