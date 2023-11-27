# Dorms

## Managing Dormitories Digitally: 
As a part of my final project of the first semester, I created a program using C++ to regulate the day-to-day operations of college dorms digitally such as the move-in, move-out of residents, check-in, and check-out of visitors. My program is based on several assumptions about the residence hall and its rules which include:

          - There exists one bed in a room which means one resident in every room.
          - There are a total of 20 rooms in the residence hall.
          - Students can only become visitors in any residence hall across the campus.
          - For one resident, i.e. one room, no more than one visitor is allowed at a time.
          - An individual identifying as an opposite gender to that of the room’s resident is never
            allowed to check in as a visitor.
          - The check-in of a visitor of the same gender runs from 6 a.m. in the morning till midnight
            (before 12 a.m.). Thereafter, no visitor is allowed to enter the hall.
          - For a visitor who checks in the permitted time period, s/he must check out before 12 a.m.
            Otherwise, that will be considered a violation of housing rules.
          - Every student (resident + visitor) must have a unique Student ID.

In addition, my program handles erroneous inputs very well such as alphabetic Student IDs, mixed cases of persons' names, and invalid room numbers.
