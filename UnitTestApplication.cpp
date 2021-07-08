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
  Station(const Station& s):name_(s.name_){cout<<"copy";}
  Station& operator=(const Station& s) {
  if (this != &s) {
  name_ = s.name_;}
  return *this;}

 string GetName()const
 {
     return(name_);
 }
 static void UnitTesting();
};
void Station::UnitTesting()
{
    cout<<"TESTING CLASS STATION"<<endl;
    //***********test cases for constructor
    Station s1("Mumbai");
    Station s2("Delhi");
    Station s3=s2; //implementing copy constructor

    if(s1.name_!="Mumbai")
        cout<<"Station Consturction Error on  Station s1(Mumbai)"<<endl;
    else
        cout<<" object Station s1(Mumbai) created"<<endl;
    if(s2.name_!=s3.name_)
        cout<<"Station Consturction Error on copy constructor Station s2=s3"<<endl;//checking for copy constructor
    else
        cout<<"Station s3=s2 is working "<<endl;
    //*********test cases for assignment operator

    s2=s1;
    if(s2.name_!=s1.name_)
         cout<<"Station Assignment Error on s2=s1"<<endl;
    else
         cout<<"Assignment operator station s3=s2 is working "<<endl;

     //*********test cases for GetName()*************

     if(s1.name_!=s1.GetName())
        cout<<"Station GetName() error on s1.name_"<<endl;
     else
        cout<<"Station s1.GetName()="<<s1.GetName()<<endl;

}
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
     void GetDate() const {
         if(date_>31 || date_<1 || month_<1 || month_>12 || year_<1)
            cout<<"Invalid Date"<<endl;
         else
         cout<<date_ << "/" <<monthNames[month_ - 1] << "/" <<year_<<endl;
          }
     static void UnitTesting();
};
void Date::UnitTesting()
{
  cout<<"\n\nTESTING CLASS DATE\n"<<endl;
    //***********test cases for constructor**************
    Date d1(1,1,21);
    Date d2(2,5,20);
    Date d3(32,5,11);
    Date d4=d1; //implementing copy constructor

    if(d1.date_!=1 || d1.month_!=1 ||d1.year_!=21)
        cout<<"Date Consturction Error on  Date d1(1,1,21)"<<endl;
    else
        cout<<" object Date d1(1,1,21) created"<<endl;
   if(d3.date_!=32 || d3.month_!=5 || d3.year_!=20)
        cout<<"Date Consturction Error on  Date d3(32,5,11)"<<endl;
    else
        cout<<" object Date d3(32,5,11) created"<<endl;

    if(d4.date_!=d1.date_ || d4.year_!= d1.year_ || d4.month_!=d1.month_)
        cout<<"Date Consturction Error on copy constructor Date d4=d1"<<endl;//checking for copy constructor
    else
        cout<<"Station d4=d1 is working "<<endl;
    //*********test cases for assignment operator

    d2=d1;
    if(d2.date_!=d1.date_ || d2.month_!=d1.month_ ||d2.year_!=d1.month_)
         cout<<"Date Assignment Error on d2=d1"<<endl;
    else
         cout<<"Assignment operator Date d2=d1 is working "<<endl;

     //*********test cases for GetDate()*************

        cout<<"d1.GetDate() called"<<endl;
        cout<<"Date d1.GetDate()=";
        d1.GetDate();
        cout<<"d3.GetDate() called"<<endl;
        cout<<"Date d3.GetDate()=";
        d3.GetDate();


}
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
  static void UnitTesting();
};
Railways *Railways::IndianRailways = 0;
void Railways::UnitTesting()
{
    cout<<"\n\nTESTING CLASS RAILWAYS"<<endl;
   Railways r = Railways::railways();
   cout<<"Instance Created"<<endl;
   if(r.GetDistance("Delhi","Mumbai")!=1447)
    cout<<"Error in making Railways class and getting Distance r.GetDistance(Delhi,Mumbai)"<<endl;
   else
    cout<<"r.GetDistance(Delhi,Mumbai) = "<<r.GetDistance("Delhi","Mumbai")<<endl;
}
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
    static void UnitTesting();

};
void ACChairCar::UnitTesting()
{
    cout<<"\n\nTESTING CLASS ACCHAIR"<<endl;
   ACChairCar obj("AC Chair Car",1.25,Seat::mode,"Yes",Tier0::noTier,"No");

   if(obj.GetLoadFactor()!=1.25)
    cout<<"Error in ACChairCar::GetLoadFactor()"<<endl;
   else
    cout<<" ACChairCar::GetLoadFactor() works correctly"<<endl;

    if(obj.GetName()!="AC Chair Car")
    cout<<"Error in ACChairCar::GetName()"<<endl;
   else
    cout<<" ACChairCar::GetName() works correctly"<<endl;

   if(obj.GetNumberOfTiers()!=0)
    cout<<"Error in ACChairCar::GetNumberofTiers()"<<endl;
   else
    cout<<" ACChairCar::GetNumberOfTiers() works correctly"<<endl;

   if(obj.IsAC()!=true)
    cout<<"Error in ACChairCar::IsAC()"<<endl;
   else
    cout<<" ACChairCar::IsAC() works correctly"<<endl;

   if(obj.IsSitting()!=true)
    cout<<"Error in ACChairCar::IsSitting()"<<endl;
   else
    cout<<" ACChairCar::IsSitting() works correctly"<<endl;
   if(obj.IsLuxury()!=false)
      cout<<"Error in ACChairCar::IsLuxury()"<<endl;
   else
    cout<<" ACChairCar::IsLuxury() works correctly"<<endl;

}
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
  static void UnitTesting();
};
void SecondSitting::UnitTesting()
{
    cout<<"\n\nTESTING CLASS SECONDSITTING"<<endl;
    SecondSitting obj("Second Sitting",0.5,Seat::mode,"No",Tier0::noTier,"No");

   if(obj.GetLoadFactor()!=0.5)
    cout<<"Error in SecondSitting::GetLoadFactor()"<<endl;
   else
    cout<<" SecondSitting::GetLoadFactor() works correctly"<<endl;

    if(obj.GetName()!="Second Sitting")
    cout<<"Error in SecondSitting::GetName()"<<endl;
   else
    cout<<" SecondSitting::GetName() works correctly"<<endl;

   if(obj.GetNumberOfTiers()!=0)
    cout<<"Error in SecondSitting::GetNumberofTiers()"<<endl;
   else
    cout<<" SecondSitting::GetNumberOfTiers() works correctly"<<endl;

   if(obj.IsAC()!=false)
    cout<<"Error in SecondSitting::IsAC()"<<endl;
   else
    cout<<" SecondSitting::IsAC() works correctly"<<endl;

   if(obj.IsSitting()!=true)
    cout<<"Error SecondSitting::IsSitting()"<<endl;
   else
    cout<<" SecondSitting::IsSitting() works correctly"<<endl;
   if(obj.IsLuxury()!=false)
      cout<<"Error in SecondSitting::IsLuxury()"<<endl;
   else
    cout<<" SecondSitting::IsLuxury() works correctly"<<endl;

}
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
static void UnitTesting();

};
void ACFirstClass::UnitTesting()
{
    cout<<"\n\nTESTING CLASS ACFIRSTCLASS"<<endl;
    ACFirstClass obj("AC First Class",3.0,Berth::mode,"Yes",Tier2::noTier,"Yes");

   if(obj.GetLoadFactor()!=3)
    cout<<"Error in ACFirstClass::GetLoadFactor()"<<endl;
   else
    cout<<" ACFirstClass::GetLoadFactor() works correctly"<<endl;

    if(obj.GetName()!="AC First Class")
    cout<<"Error in ACFirstClass::GetName()"<<endl;
   else
    cout<<" ACFirstClass::GetName() works correctly"<<endl;

   if(obj.GetNumberOfTiers()!=2)
    cout<<"Error in ACFirstClass::GetNumberofTiers()"<<endl;
   else
    cout<<" ACFirstClass::GetNumberOfTiers() works correctly"<<endl;

   if(obj.IsAC()!=true)
    cout<<"Error in ACFirstClass::IsAC()"<<endl;
   else
    cout<<" ACFirstClass::IsAC() works correctly"<<endl;

   if(obj.IsSitting()!=false)
    cout<<"Error ACFirstClass::IsSitting()"<<endl;
   else
    cout<<" ACFirstClass::IsSitting() works correctly"<<endl;
   if(obj.IsLuxury()!=true)
      cout<<"Error in ACFirstClass::IsLuxury()"<<endl;
   else
    cout<<" ACFirstClass::IsLuxury() works correctly"<<endl;

}
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
static void UnitTesting();

};
void AC2Tier::UnitTesting()
{
    cout<<"\n\nTESTING CLASS AC2TIER"<<endl;
     AC2Tier obj("AC 2 Tier",2.0,Berth::mode,"Yes",Tier2::noTier,"No");

   if(obj.GetLoadFactor()!=2.0)
    cout<<"Error in AC2Tier::GetLoadFactor()"<<endl;
   else
    cout<<" AC2Tier::GetLoadFactor() works correctly"<<endl;

    if(obj.GetName()!="AC 2 Tier")
    cout<<"Error in AC2Tier::GetName()"<<endl;
   else
    cout<<" AC2Tier::GetName() works correctly"<<endl;

   if(obj.GetNumberOfTiers()!=2)
    cout<<"Error inAC2Tier::GetNumberofTiers()"<<endl;
   else
    cout<<" AC2Tier::GetNumberOfTiers() works correctly"<<endl;

   if(obj.IsAC()!=true)
    cout<<"Error in AC2Tier::IsAC()"<<endl;
   else
    cout<<" AC2Tier::IsAC() works correctly"<<endl;

   if(obj.IsSitting()!=false)
    cout<<"Error AC2Tier::IsSitting()"<<endl;
   else
    cout<<" AC2Tier::IsSitting() works correctly"<<endl;
   if(obj.IsLuxury()!=false)
      cout<<"Error in AC2Tier::IsLuxury()"<<endl;
   else
    cout<<" AC2Tier::IsLuxury() works correctly"<<endl;

}
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
static void UnitTesting();

};
void FirstClass::UnitTesting()
{
    cout<<"\n\nTESTING CLASS FirstClass"<<endl;
     FirstClass obj("First Class",2.0,Berth::mode,"No",Tier2::noTier,"Yes");

   if(obj.GetLoadFactor()!=2.0)
    cout<<"Error in FirstClass::GetLoadFactor()"<<endl;
   else
    cout<<" FirstClass::GetLoadFactor() works correctly"<<endl;

    if(obj.GetName()!="First Class")
    cout<<"Error in FirstClass::GetName()"<<endl;
   else
    cout<<" FirstClass::GetName() works correctly"<<endl;

   if(obj.GetNumberOfTiers()!=2)
    cout<<"Error in FirstClass::GetNumberofTiers()"<<endl;
   else
    cout<<" FirstClass::GetNumberOfTiers() works correctly"<<endl;

   if(obj.IsAC()!=false)
    cout<<"Error in FirstClass::IsAC()"<<endl;
   else
    cout<<" FirstClass::IsAC() works correctly"<<endl;

   if(obj.IsSitting()!=false)
    cout<<"Error FirstClass::IsSitting()"<<endl;
   else
    cout<<" FirstClass::IsSitting() works correctly"<<endl;
   if(obj.IsLuxury()!=true)
      cout<<"Error in FirstClass::IsLuxury()"<<endl;
   else
    cout<<" FirstClass::IsLuxury() works correctly"<<endl;

}
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
static void UnitTesting();

};
void AC3Tier::UnitTesting()
{
    cout<<"\n\nTESTING CLASS AC3Tier"<<endl;
    AC3Tier obj("AC 3 Tier",1.75,Berth::mode,"Yes",Tier3::noTier,"No");

   if(obj.GetLoadFactor()!=1.75)
    cout<<"Error in AC3Tier::GetLoadFactor()"<<endl;
   else
    cout<<" AC3Tier::GetLoadFactor() works correctly"<<endl;

    if(obj.GetName()!="AC 3 Tier")
    cout<<"Error in AC3Tier::GetName()"<<endl;
   else
    cout<<" AC3Tier::GetName() works correctly"<<endl;

   if(obj.GetNumberOfTiers()!=3)
    cout<<"Error in AC3Tier::GetNumberofTiers()"<<endl;
   else
    cout<<"AC3Tier::GetNumberOfTiers() works correctly"<<endl;

   if(obj.IsAC()!=true)
    cout<<"Error in AC3Tier::IsAC()"<<endl;
   else
    cout<<" AC3Tier::IsAC() works correctly"<<endl;

   if(obj.IsSitting()!=false)
    cout<<"Error AC3Tier::IsSitting()"<<endl;
   else
    cout<<" AC3Tier::IsSitting() works correctly"<<endl;
   if(obj.IsLuxury()!=false)
      cout<<"Error in AC3Tier::IsLuxury()"<<endl;
   else
    cout<<" AC3Tier::IsLuxury() works correctly"<<endl;

}
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
static void UnitTesting();

};
void Sleeper ::UnitTesting()
{
    cout<<"\n\nTESTING CLASS Sleeper "<<endl;
    Sleeper obj("Sleeper",1.0,Berth::mode,"No",Tier3::noTier,"No");

   if(obj.GetLoadFactor()!=1.0)
    cout<<"Error in Sleeper ::GetLoadFactor()"<<endl;
   else
    cout<<" Sleeper ::GetLoadFactor() works correctly"<<endl;

    if(obj.GetName()!="Sleeper")
    cout<<"Error in Sleeper ::GetName()"<<endl;
   else
    cout<<" Sleeper ::GetName() works correctly"<<endl;

   if(obj.GetNumberOfTiers()!=3)
    cout<<"Error in Sleeper ::GetNumberofTiers()"<<endl;
   else
    cout<<"Sleeper ::GetNumberOfTiers() works correctly"<<endl;

   if(obj.IsAC()!=false)
    cout<<"Error in Sleeper ::IsAC()"<<endl;
   else
    cout<<" Sleeper ::IsAC() works correctly"<<endl;

   if(obj.IsSitting()!=false)
    cout<<"Error Sleeper ::IsSitting()"<<endl;
   else
    cout<<" Sleeper ::IsSitting() works correctly"<<endl;
   if(obj.IsLuxury()!=false)
      cout<<"Error in Sleeper ::IsLuxury()"<<endl;
   else
    cout<<" Sleeper ::IsLuxury() works correctly"<<endl;

}
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
    Booking(Station from_,Station to_,Date d, const BookingClass* b)
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
static void UnitTesting();
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
void Booking::UnitTesting()
{
    cout<<"\n\n CHECKING FOR CLASS BOOKING"<<endl;
Booking b1(Station("Mumbai"), Station("Banglore"), Date(3, 12, 2019), ACFirstClass::Type());b1.ComputeFare();
if(b1.fare_!=1902)
    cout<<"Error in Booking::ComputeFare()"<<endl;
Booking b2(Station("Kolkata"), Station("Mumbai"), Date(4, 1, 2019), AC2Tier::Type());b2.ComputeFare();
if(b2.fare_!=2064)
    cout<<"Error in Booking::ComputeFare()"<<endl;
Booking b3(Station("Delhi"), Station("Mumbai"), Date(5, 2, 2020), FirstClass::Type());b3.ComputeFare();
if(b3.fare_!=1809)
    cout<<"Error in Booking::ComputeFare()"<<endl;
Booking b4(Station("Mumbai"), Station("Delhi"), Date(26, 3, 2020), AC3Tier::Type());b4.ComputeFare();
if(b4.fare_!=1316)
    cout<<"Error in Booking::ComputeFare()"<<endl;
Booking b5(Station("Chennai"), Station("Delhi"), Date(25, 4, 2021), ACChairCar::Type());b5.ComputeFare();
if(b5.fare_!=1413)
    cout<<"Error in Booking::ComputeFare()"<<endl;
Booking b6(Station("Delhi"), Station("Chennai"), Date(26, 5, 2021), Sleeper::Type());b6.ComputeFare();
if(b6.fare_!=1090)
    cout<<"Error in Booking::ComputeFare()"<<endl;
Booking b7(Station("Mumbai"), Station("Delhi"), Date(19, 7, 2021), SecondSitting::Type());b7.ComputeFare();
if(b1.fare_!=362)
    cout<<"Error in Booking::ComputeFare()"<<endl;
vector<Booking*> sBookings={&b1,&b2,&b3,&b4,&b5,&b6,&b7};
vector<Booking*>::iterator it;
for (it = sBookings.begin(); it <sBookings.end(); ++it) {
cout << *(*it);
}
return;

}
int main()
{
    Station::UnitTesting();
    Date::UnitTesting();
    Railways::UnitTesting();
    ACChairCar::UnitTesting();
    SecondSitting::UnitTesting();
    ACFirstClass::UnitTesting();
    AC2Tier::UnitTesting();
    FirstClass::UnitTesting();
    AC3Tier::UnitTesting();
    Sleeper ::UnitTesting();
    Booking::UnitTesting();
}
