#pragma once
#include <helper.h>

void RobotLine::radionica() {
    if (setup()){
        armOpen();
    }
    
    if (lineAny()){
        armClose();
        
        if (front() > 160 and front() < 200 and frontLeft() < 120 and frontRight() < 120){
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
        armOpen();
        
        if (frontLeft() < 200)
        {   
            if (front() < 130){
                go(70, -70);
                delayMs(600);
            }
            if (frontLeft() < 100){
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
            if (frontRight() < 100){
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
