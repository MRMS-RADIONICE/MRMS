#pragma once
#include <helper.h>

void RobotLine::radionica18() {
    if (setup()){
        servo(140, 0);   // Raspon stupnjeva od 130 do 150
        servo(80, 1);   // Raspon stupnjeva od 0 - 90
        servo(10, 2);   // Raspon stupnjeva od 90 - 0
    }
    
    if (lineAny()){  
        if (not line(0) and not line(1) and not line(2) and not line(3) and not line(4) and not line(5) and line(8) and not line(7) and not line(6)){
            stop();
            end();
        }      
        if (line(0) and line(8)){
            go(70, -70);
            delayMs(600);
        }
        else 
            lineFollow();
    }
    else
    {
        if (frontLeft() < 200)
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
        else if(frontRight() < 200)
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
            go(60, 60);
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
