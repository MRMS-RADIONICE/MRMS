#pragma once
#include <helper.h>

void RobotLine::radionica18() {
    if (setup()){
        servo(90, 0);   // Raspon stupnjeva od 0 do 90 do 140
        servo(40, 1);   // Raspon stupnjeva od 
        servo(60, 2);   // Raspon stupnjeva od 
    }
    
    if (lineAny()){
        lineFollow();
    }
    else
    {
        if (frontRight < 200 and frontLeft > 200)
        {
            rightWall();  
        }
        else
            leftWall();
    }
}

void rightWall(){
    if (front() < 100){
        go(70, -70);
        delayMs(600);
    }
    if (frontRight < 150){
        go(-70, 70);   
    }
    else
        go(70, -70);
}

void leftWall(){
    if (front() < 100){
        go(-70, 70);
        delayMs(600);
    }
    if (frontLeft < 150){
        go(70, -70);
    }
    else
        go(-70, 70);
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
