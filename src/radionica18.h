#pragma once
#include <helper.h>

void RobotLine::radionica18() {
    if (setup()){
        servo(140, 0);   // Raspon stupnjeva od 130 do 150
        servo(60, 1);   // Raspon stupnjeva od 0 - 90
        servo(40, 2);   // Raspon stupnjeva od 90 - 0
    }
    
    if (lineAny()){
        if (line(0) and line(8)){
            go(70, -70);
            delayMs(600);
        }
        else 
            lineFollow();
    }
    else
    {
        if (frontRight() < 200 and frontLeft() > 150)
        {
            if (front() < 130){
                go(-70, 70);
                delayMs(600);
            }
            if (frontRight() < 120){
                go(30, 70);   
            }
            else
                go(70, 30);
        }
        else
        {
            if (front() < 130){
                go(70, -70);
                delayMs(600);
            }
            if (frontLeft() < 120){
                go(70, 30);
            }
            else
                go(30, 70);    
        }
    }
}


/*
Ponavljanje pračenje linije, pračenje zida i korištenje servo motora. 
Naglasak na sljedećim naredbama: 
    --> go();
    --> delayMs();
    --> lineFollow();
    --> frontLeft();
    --> frontRight();
    --> front();
Cilj: Preći s pračenja linije na pračenje zida i nazad
*/
