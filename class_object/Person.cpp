#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

struct DOB{
    u_char bd;
    u_char bm;
    u_int32_t by;
    DOB(u_char bd,u_char bm, uint32_t by):bd(bd),bm(bm),by(by){}
    DOB():bd(0),bm(0),by(0) {}

};
class Person {
    public:
    
    Person(string fN,DOB dob, string bL, string nl, string ppN,uint64_t mN, string cL);
    Person();
    void updatePassportNumber(string ppN) const;
    void updateMobileNumber(uint64_t ppN) const;
    void updateCurrentLocation(string cL) const;
    void getCurrentAge() const;
    friend ostream& operator<<(ostream& os, const Person& p1);
    
    private:
    
    string fullName;
    DOB dob;
    string birthLocation;
    string nationality;
    mutable string passportNumber;
    mutable uint64_t mobileNumber;
    mutable string currentLocation;
};

Person::Person(string fN,DOB dob, string bL, string nl, string ppN,uint64_t mN, string cL):
    fullName(fN),dob(dob.bd, dob.bm, dob.by),birthLocation(bL),nationality(nl),passportNumber(ppN),
    mobileNumber(mN),currentLocation(cL){
}
Person::Person(){
        fullName = string(NULL);
        birthLocation = string(NULL);
        dob = DOB();
        nationality = string(NULL);
        passportNumber = string(NULL);
        mobileNumber = 0;
        currentLocation = string(NULL);
}

void Person::getCurrentAge()const {

std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
/*  
    std::cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
*/
  uint32_t py = 1900 + now->tm_year;
  u_char pm = now->tm_mon;
  u_char pd = now->tm_mday;
  uint32_t by = dob.by;
  u_char bm = dob.bm;
  u_char bd = dob.bd;

  int d, m, y;
  int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
  
  y = py - dob.by;
  if (pm < dob.bm)
  {
    y--;
    m = 12 - (bm - pm);       
  }
  else
  {m = pm - bm;}
  if (pd < bd)
  {
    m--;
    d = md[pm - 1] - (bd - pd);
  }
  else
  {d = pd - bd;}
  cout << "your age is : \n";
  cout << y << " years " << m << " months " << d << " days." << endl;
}

void Person::updatePassportNumber(string ppN) const{
    passportNumber=ppN;
}

void Person::updateMobileNumber(uint64_t mN) const{
    mobileNumber=mN;
}

 void Person:: updateCurrentLocation(string cL) const {
   currentLocation = cL;
 }
ostream& operator<<(ostream& os, const Person& p1)
  {
    os << "Full Name:" << p1.fullName << std::endl << 
    " Birth Location :" << p1. birthLocation << std::endl <<
    " Nationality:" <<  p1. nationality <<  std::endl <<
    " Passport Number:" << p1. passportNumber << std::endl <<
    " Mobile Number:" << p1.mobileNumber << std::endl <<
    " Current Location:" << p1.currentLocation << std::endl;
    return os;
  }

 int main(int argc, char *argv[])
 {
    
    Person p1("ss",DOB(1,2,2010),"India","Indian","ABCD1234",8867473412,"India");
    cout << p1;
    p1.updateCurrentLocation("USA");
    cout << p1;
    p1.getCurrentAge();
 }