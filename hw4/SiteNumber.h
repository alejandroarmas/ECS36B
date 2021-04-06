#ifndef SITE_NUMBER
#define SITE_NUMBER

#include <string>

class SiteNumber {

    public:
        SiteNumber(const std::string& s) : site_num(s) {}
        bool operator()(const Runway * rptr) {
            return site_num != rptr->site_number();
        }
    private:
        const std::string site_num;
};

#endif