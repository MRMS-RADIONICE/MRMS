#pragma once
#include <helper.h>

void RobotLine::radionica() {
    static bool lopta; 
    if (setup()){
        lopta = false; 
        armOpen();
    }

    if (lopta == false){
        if(lineAny()){
            armClose();

            if (line(8) and line(4) and front() > 200){
                catchBall();
                lopta = true;
            }

            lineFollow();
        } 
        else{
            // Priprema robota za praćenje zida
            armOpen();

            wallFollowLeft();
            wallFollowRight();
        }
    }
    else{
        if(lineAny()){
            if (line(8) and line(0) and front() < 200){
                stop();
                armDrop();
                delayMs(100);
                end();
            }  
              lineFollow();
        }
        else{

            wallFollowLeftCarry();
            wallFollowRightCarry();
        }
    }
}

void RobotLine::wallFollowRight() {
    // Praćenje zida s desne strane
    if(frontRight() < 200)
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

void RobotLine::wallFollowLeft() {
    // Prioritet stavljen na praćenje zida s lijeve strane
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
}

void RobotLine::catchBall() {
    stop();
    delayMs(50);
    armCatchReady();
    go(40, 40);
    delayMs(2000);
    go(20, 20);
    delayMs(1000);
    armCatch();
    stop();
    delayMs(50);
    go(-40, -40);
    delayMs(1500);
    stop();
    delayMs(50);
    go(70, -70);
    delayMs(1300);
    stop();
    delayMs(50);
    go(70, 70);
    delayMs(500);
}

void RobotLine::wallFollowRightCarry() {
    // Praćenje zida s desne strane
    if(frontRight() < 200)
    {
        if (front() < 130){
            go(-70, 70);
            delayMs(600);
        }
        if (frontRight() < 160){
            go(30, 70);
        }
        else
            go(70, 30);    
    }
    else
        go(60, 60);
}

void RobotLine::wallFollowLeftCarry() {
    // Prioritet stavljen na praćenje zida s lijeve strane
    if (frontLeft() < 200)
    {   
        if (front() < 130){
            go(-70, 70);
            delayMs(600);
        }
        if (frontLeft() < 160){
            go(70, 30);   
        }
        else
            go(30, 70);
    }
}