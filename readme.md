# Data Base
---
DataBase can store data in the form Date - event 
and supports the following operations:


For add event use: Add year-month-day event

For delete event use: Del event != "holiday"
or Del date < 2017-01-01 AND (event == "holiday" OR event == "sport event")

For find use: Find date < 2017-11-06

For find last event before date use: Last 2019-3-3

---
Check the С++17 is installed on the system. 
 ```
 git clone -b Pattern_Command https://github.com/ArkadyRudenko/Database_total_yellow_belt.git
 ```
 # Unix systems

 ### Run
 From the project root path just run:
 ```
 make
 ```
 

## Windows
Check the make is installed:
```
mingw32-make.exe
```
 ### Run
 From the project root path just run:
 ```
 mingw32-make.exe
 ```
 