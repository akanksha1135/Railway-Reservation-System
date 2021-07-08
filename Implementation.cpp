#include<bits/stdc++.h>
#include <cmath>
using namespace std;
//*************STATION CLASS****************//
class Station
{
 string name_;
 public:
 Station(string name_)
 {
     this->name_=name_;
 }
  Station(){}
  Station(const Station& s):name_(s.name_){}
  Station& operator=(const Station& s) {
  if (this != &s) {
  name_ = s.name_;}
  return *this;}

 string GetName()const
 {
     return(name_);
 }
};
class Passenger//empty class for passenger
{

};
//*********************DATE CLASS*************
char monthNames[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
class Date {
      enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
      typedef unsigned int UINT;
      UINT date_; Month month_; UINT year_;
public:
      Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m), year_(y){ }
      Date(){}
      Date(const Date& d) : date_(d.date_), month_(d.month_), year_(d.year_){ }
      Date& operator=(const Date& d)
      {
          date_ = d.date_; month_ = d.month_; year_ = d.year_;
          return *this;
      }
     void GetDate() const { cout << date_ << "/" << monthNames[month_ - 1] << "/" << year_; }
};
//*********************Railways Class***********************
class Railways
{
  map <string,map<string,int>> m;
  Railways()
  {
    //FOR MUMBAI
    m.insert(make_pair("Mumbai", map<string, int>()));
    m["Mumbai"].insert(make_pair("Delhi", 1447));
    m["Mumbai"].insert(make_pair("Banglore", 981));
    m["Mumbai"].insert(make_pair("Kolkata",2014));
    m["Mumbai"].insert(make_pair("Chennai", 1338));
    //FOR DELHI
    m.insert(make_pair("Delhi", map<string, int>()));
    m["Delhi"].insert(make_pair("Mumbai", 1447));
    m["Delhi"].insert(make_pair("Banglore", 2150));
    m["Delhi"].insert(make_pair("Kolkata", 1472));
    m["Delhi"].insert(make_pair("Chennai", 2180));
    //FOR BANGLORE
    m.insert(make_pair("Banglore", map<string, int>()));
    m["Banglore"].insert(make_pair("Mumbai", 981));
    m["Banglore"].insert(make_pair("Delhi", 2150));
    m["Banglore"].insert(make_pair("Kolkata",1871));
    m["Banglore"].insert(make_pair("Chennai", 350));
    //FOR  KOLKATA
    m.insert(make_pair("Kolkata", map<string, int>()));
    m["Kolkata"].insert(make_pair("Mumbai", 2014));
    m["Kolkata"].insert(make_pair("Delhi", 1472));
    m["Kolkata"].insert(make_pair("Banglore", 1871));
    m["Kolkata"].insert(make_pair("Chennai", 1659));
    //FOR CHENNAI
     m.insert(make_pair("Chennai", map<string, int>()));
    m["Chennai"].insert(make_pair("Mumbai", 1338));
    m["Chennai"].insert(make_pair("Delhi", 2180));
    m["Chennai"].insert(make_pair("Banglore", 30));
    m["Chennai"].insert(make_pair("Kolkata", 1659));

  }
  static Railways *IndianRailways;
  public:
      static const Railways& railways()
  {                                                          // Access the Railways

     if (!IndianRailways) IndianRailways = new Railways(); // Constructed for first call
     return *IndianRailways;                              // Reused from next time
  }
   int GetDistance(string toStation,string fromStation) const//function to get distance
  {
      return(m.at(toStation).at(fromStation));
  }
};
Railways *Railways::IndianRailways = 0;


//*************BookingClass******************
class BookingClass //ABSTRACT BASE CLASS
{
    protected:
    const string name_;
    float fareLoad_;  //May change from time to time
    const string mode_;//will not change in future
    const string AC;
    const int noTiers_;//Will not change in future
    const string luxury_; // may change in future
    public:
    BookingClass(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury) //constructor
    :name_(name),fareLoad_(fareLoad),mode_(mode),AC(ac),noTiers_(noTiers),luxury_(luxury){}

      virtual   float GetLoadFactor() const =0;
      virtual const  string GetName()const =0;
      virtual   bool IsSitting () const=0;
      virtual   bool IsAC() const=0;
      virtual   int GetNumberOfTiers()const=0;
      virtual   bool IsLuxury() const =0;


};
//BookingClass has two derived class - SEAT and BERTH
class Seat: public BookingClass
{
  public:
     static string mode;
     Seat(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :BookingClass(name,fareLoad,Seat::mode,ac,noTiers,luxury){}

};
class Berth: public BookingClass
{
  public:
     static string mode;
     Berth(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :BookingClass(name,fareLoad,Berth::mode,ac,noTiers,luxury){}

};
//SEAT HAS ONE DERIVED CLASS TIER0
class Tier0:public Seat
{
public:
    static int noTier;
     Tier0(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Seat(name,fareLoad,Seat::mode,ac,Tier0::noTier,luxury){}

};
//BERTH HAS TWO DERIVED CLASS TIER2 AND TIER3
class Tier3:public Berth
{
public:
    static int noTier;
     Tier3(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Berth(name,fareLoad,Berth::mode,ac,Tier3::noTier,luxury){}

};
class Tier2:public Berth
{
public:
    static int noTier;
     Tier2(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Berth(name,fareLoad,Berth::mode,ac,Tier2::noTier,luxury){}

};
//TIER0 HAS TWO DERIVED CLASSES ACCHAIR CAR AND SEONDSITTING
class ACChairCar:public Tier0{
    ACChairCar(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Tier0(name,fareLoad,Seat::mode,ac,Tier0::noTier,luxury){}
public:
    static const BookingClass* Type()
    {
        static const ACChairCar obj("AC Chair Car",1.25,Seat::mode,"Yes",Tier0::noTier,"No");
        return(&obj);
    }
        bool IsSitting () const{return(true);}
        int GetNumberOfTiers()const{return(0);}
        float GetLoadFactor() const {return(fareLoad_);}
        const string GetName()const {return(name_);}
     bool IsAC() const
        {
            if (AC=="Yes")
                return(true);
            else
                return(false);
        }
         bool IsLuxury() const
       {
           if(luxury_=="Yes")
            return(true);
           else
            return(false);
       }


};
class SecondSitting:public Tier0{
    SecondSitting(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Tier0(name,fareLoad,Seat::mode,ac,Tier0::noTier,luxury){}
public:
    static const BookingClass* Type()
    {
        static const SecondSitting obj("Second Sitting",0.5,Seat::mode,"No",Tier0::noTier,"No");
        return(&obj);
    }
        bool IsSitting () const{return(true);}
        int GetNumberOfTiers()const{return(0);};
        float GetLoadFactor() const {return(fareLoad_);}
        const string GetName()const {return(name_);}
     bool IsAC() const
        {
            if (AC=="Yes")
                return(true);
            else
                return(false);
        }
         bool IsLuxury() const
       {
           if(luxury_=="Yes")
            return(true);
           else
            return(false);
       }

};
class ACFirstClass:public Tier2{
    ACFirstClass(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Tier2(name,fareLoad,Berth::mode,ac,Tier2::noTier,luxury){}
public:
    static const BookingClass* Type()
    {
        static const ACFirstClass obj("AC First Class",3.0,Berth::mode,"Yes",Tier2::noTier,"Yes");
        return(&obj);
    }
        bool IsSitting () const{return(false);}
        int GetNumberOfTiers()const{return(2);}
        float GetLoadFactor() const {return(fareLoad_);}
        const string GetName()const {return(name_);}
     bool IsAC() const
        {
            if (AC=="Yes")
                return(true);
            else
                return(false);
        }
         bool IsLuxury() const
       {
           if(luxury_=="Yes")
            return(true);
           else
            return(false);
       }


};
class AC2Tier:public Tier2{
    AC2Tier(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Tier2(name,fareLoad,Berth::mode,ac,Tier2::noTier,luxury){}
public:
    static const BookingClass* Type()
    {
        static const AC2Tier obj("AC 2 Tier",2.0,Berth::mode,"Yes",Tier2::noTier,"No");
        return(&obj);
    }
        bool IsSitting () const{return(false);}
        int GetNumberOfTiers()const{return(2);}
        float GetLoadFactor() const {return(fareLoad_);}
        const string GetName()const {return(name_);}
     bool IsAC() const
        {
            if (AC=="Yes")
                return(true);
            else
                return(false);
        }
         bool IsLuxury() const
       {
           if(luxury_=="Yes")
            return(true);
           else
            return(false);
       }


};
class FirstClass:public Tier2{
    FirstClass(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Tier2(name,fareLoad,Berth::mode,ac,Tier2::noTier,luxury){}
public:
    static const BookingClass* Type()
    {
        static const FirstClass obj("First Class",2.0,Berth::mode,"No",Tier2::noTier,"Yes");
        return(&obj);
    }
        bool IsSitting () const{return(false);}
        int GetNumberOfTiers()const{return(2);}
        float GetLoadFactor() const {return(fareLoad_);}
        const string GetName()const {return(name_);}
     bool IsAC() const
        {
            if (AC=="Yes")
                return(true);
            else
                return(false);
        }
         bool IsLuxury() const
       {
           if(luxury_=="Yes")
            return(true);
           else
            return(false);
       }


};
class AC3Tier:public Tier3{
    AC3Tier(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Tier3(name,fareLoad,Berth::mode,ac,Tier3::noTier,luxury){}
public:
    static const BookingClass* Type()
    {
        static const AC3Tier obj("AC 3 Tier",1.75,Berth::mode,"Yes",Tier3::noTier,"No");
        return(&obj);
    }
        bool IsSitting () const{return(false);}
        int GetNumberOfTiers()const{return(3);}
        float GetLoadFactor() const {return(fareLoad_);}
        const string GetName()const {return(name_);}
     bool IsAC() const
        {
            if (AC=="Yes")
                return(true);
            else
                return(false);
        }
         bool IsLuxury() const
       {
           if(luxury_=="Yes")
            return(true);
           else
            return(false);
       }


};
class Sleeper:public Tier3{
     Sleeper(const string& name,float fareLoad,const string& mode,const string& ac,const int& noTiers,const string& luxury)
    :Tier3(name,fareLoad,Berth::mode,ac,Tier3::noTier,luxury){}
public:
    static const BookingClass* Type()
    {
        static const Sleeper obj("Sleeper",1.0,Berth::mode,"No",Tier3::noTier,"No");
        return(&obj);
    }
        bool IsSitting () const{return(false);}
        int GetNumberOfTiers()const{return(3);}
        float GetLoadFactor() const {return(fareLoad_);}
        const string GetName()const {return(name_);}
     bool IsAC() const
        {
            if (AC=="Yes")
                return(true);
            else
                return(false);
        }
         bool IsLuxury() const
       {
           if(luxury_=="Yes")
            return(true);
           else
            return(false);
       }


};
string Seat::mode = "Seat";
string Berth::mode = "Berth";
int Tier0::noTier=0;
int Tier3::noTier=3;
int Tier2::noTier=2;
class Booking
{
    Station toStation;
    Station fromStation;
    Date d;
    const  BookingClass* b;
    int fare_;
    static int PNR;
    static  double baseFare;
    static  double AC_Surcharge;
    static  double luxury_Tax;
public:
    Booking(Station from_,Station to_,Date d, const BookingClass* b,Passenger* p=NULL)
    {
        this->toStation=to_;
        this->fromStation=from_;
        this->d=d;
        this->b=b;
    }
  virtual  void ComputeFare()
    {
        float total=0;
        int dist= Railways::railways().GetDistance(fromStation.GetName(),toStation.GetName());
        total=dist*baseFare;
        total=total*(b->GetLoadFactor());
        if(b->IsAC())
            total=total+AC_Surcharge;
        if(b->IsLuxury())
            total=total+total*luxury_Tax;
            this->fare_=round(total);
    }
friend ostream& operator<<(ostream& os, const Booking& b);
};

ostream& operator<<(ostream& os, const Booking& b)
{
    os << "\nBOOKING SUCCEEDED: "<<endl;
    os<<"PNR Number = "<<b.PNR<<endl;
    b.PNR++;
    os<<"From Station = "<<b.fromStation.GetName()<<endl;
    os<<"To Station = "<<b.toStation.GetName()<<endl;
    os<<"Travel Date = ";
    b.d.GetDate();os<<endl;
    os<<"Travel Class = "<<b.b->GetName()<<endl;
    if(b.b->IsSitting())
        os<<"   :Mode = Sitting"<<endl;
    else
        os<<"   :Mode = Sleeping"<<endl;
    if(b.b->IsAC())
        os<<"  :Comfort = AC"<<endl;
    else
        os<<"  :Comfort =  Non-AC"<<endl;
    os<<"  :Bunks = "<<b.b->GetNumberOfTiers()<<endl;
    if(b.b->IsLuxury())
        os<<"  :Luxury = Yes"<<endl;
    else
        os<<"  :Luxury = No"<<endl;
    os<<"Fare = "<<b.fare_<<endl;
    return os;
}
int Booking::PNR = 1;
double Booking:: baseFare=0.50;
double Booking::AC_Surcharge=50.0;
double Booking::luxury_Tax=0.25;


void BookingApplication() {

Booking b1(Station("Mumbai"), Station("Delhi"), Date(15, 2, 2021), ACFirstClass::Type());b1.ComputeFare();
Booking b2(Station("Kolkata"), Station("Delhi"), Date(5, 3, 2021), AC2Tier::Type());b2.ComputeFare();
Booking b3(Station("Mumbai"), Station("Kolkata"), Date(17, 3, 2021), FirstClass::Type());b3.ComputeFare();
Booking b4(Station("Mumbai"), Station("Delhi"), Date(23, 3, 2021), AC3Tier::Type());b4.ComputeFare();
Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());b5.ComputeFare();
Booking b6(Station("Chennai"), Station("Kolkata"), Date(7, 5, 2021), Sleeper::Type());b6.ComputeFare();
Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 5, 2021), SecondSitting::Type());b7.ComputeFare();
Booking b8(Station("Delhi"), Station("Mumbai"), Date(22, 5, 2021), SecondSitting::Type());b8.ComputeFare();
// Output the bookings done where sBookings is the collection of bookings done
vector<Booking*> sBookings={&b1,&b2,&b3,&b4,&b5,&b6,&b7,&b8};
vector<Booking*>::iterator it;
for (it = sBookings.begin(); it <sBookings.end(); ++it) {
cout << *(*it);
}
return;
}

int main()
{
   BookingApplication();
   return 0;
}


