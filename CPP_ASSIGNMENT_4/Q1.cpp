#include <iostream>
using namespace std;
class Time{
int hours;
int minutes;
int seconds;
public : 
Time(){
hours=0;
minutes=0;
seconds=0;
}
Time(int hours,int minutes,int seconds)
{
    this->hours=hours;
    this->minutes=minutes;
    this->seconds=seconds;
}

int getHour()
{
    return this->hours;
}
int getMinute()
{
    return this->minutes;
}
int getSeconds()
{
    return this->seconds;
}
void printTime(){
    cout<<"The time is "<<hours<<" hours, "<<minutes<<" minutes, "<<seconds<<" seconds."<<endl;
}
void setHour(int hours)
{
    this->hours=hours;
}

void setMinutes(int minutes)
{
    this->minutes=minutes;
}

void setSeconds(int seconds)
{
    this->seconds=seconds;
}

};
int main(){
Time *timeArray[5];
cout<<"Please enter the time details 5 times :- "<<endl;
for(int i=0;i<5;i++)
{
    timeArray[i]=new Time();
    int hours;
    int minutes;
    int seconds;
    
    cout<<"Enter hours"<<endl;
    cin>>hours;
    timeArray[i]->setHour(hours);

    cout<<"Enter minutes"<<endl;
    cin>>minutes;
    timeArray[i]->setMinutes(minutes);
    
    cout<<"Enter seconds"<<endl;
    cin>>seconds;
    timeArray[i]->setSeconds(seconds);

    //timeArray[i]=new Time(hours,minutes,seconds);
}
for(int i=0;i<5;i++)
{
    timeArray[i]->printTime();
}
for(int i=0;i<5;i++)
{
    delete timeArray[i];
    timeArray[i]=NULL;
}
}