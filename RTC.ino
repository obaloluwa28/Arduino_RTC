// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
String Day, Month, Year, NameDay, Date, Hour, Min, Sec, Timee;
int Hourr;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
void setup () {

//#ifndef ESP8266
//  while (!Serial); // for Leonardo/Micro/Zero
//#endif

  Serial.begin(9600);

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2019, 10, 26, 23, 33, 0));
  }
  //rtc.adjust(DateTime(2020, 2, 29, 11, 27, 0));
}

void loop () {
    DateTime now = rtc.now();
    
//    Serial.print(now.year(), DEC);
//    Serial.print('/');
//    Serial.print(now.month(), DEC);
//    Serial.print('/');
//    Serial.print(now.day(), DEC);
//    Serial.print(" (");
//    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
//    Serial.print(") ");
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.print(':');
//    Serial.print(now.second(), DEC);
//    Serial.println();
//    Serial.println();

      Day = (now.day());
      Month = (now.month());
      Year = (now.year());
      NameDay = daysOfTheWeek[now.dayOfTheWeek()];
      Hourr = (now.hour());
      Min = (now.minute());
      Sec = (now.second());

      //Date = Day + "/" + Month + "/" + Year + "  (" + NameDay + ")  " + Hour + ":" + Min + ":" + Sec;
      
      if (Hourr > 12)
      {
        Hour = String (Hourr - 12);
        Timee = Hour + ":" + Min + ":" + Sec + " PM";
      }

      if (Hourr == 12)
      {
        Hour = String (Hourr);
        Timee = Hour + ":" + Min + ":" + Sec + " PM";
      }

      if (Hourr < 12)
      {
        Hour = String (Hourr);
        Timee = Hour + ":" + Min + ":" + Sec + " AM";
      }
      
      Date = Day + "/" + Month + "/" + Year + "  (" + NameDay + ")  " + Timee;
      Serial.print(Date);
      Serial.println();
      Serial.println();
      delay(1000);
}
