//
//  Prog2_firstFile.c
//  
//
//  Created by Arnye Mob on 14/02/2019.
//
#include <time.h>
#include <stdio.h>
#include "Prog2_firstFile.h"
#include <stdlib.h>
int get_random(int lower, int upper, int count)      /* random funkcia pre starovaci beh. */
{
    int i,num;
    for(i=0; i<count;i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
        return num;
    }
    /* daj mi random cislo bohati */
    return 0;
}
int get_speed(v_old)
{
    int v;

    if(v_old == 0)
    {
        v = get_random(350,450,1);
        return v;
    }
    else
    {
        v = v_old + get_random(-5,20,1);
        return v;
    }
    return 0;
}
void movement(v1,v2,d1,d2)
{
    /*int v1,d1,v2,d2,finish; */
    int finish;
    int obst,act_obst_range;   /* obstacle placement and active obstacle range */
    obst = 5000;
    act_obst_range = 250;
    finish = 40000;
    while(d1 < finish && d2 < finish)  /* bud dam || alebo && ako or/and */
    {
        if(d1%obst < act_obst_range)
        {
            v1 = 0;
            printf("The FIRST runner is down!\n");
        }
        if(d2%obst < act_obst_range)
        {
            v2 = 0;
            printf("The SECOND runner is down!\n");
        }
        v1 = get_speed(v1);
        v2 = get_speed(v2);
        d1 = d1 + v1;
        d2 = d2 + v2;
        printf("The FIRST runners stats: DISTANCE:");
        printf("%d",d1);
        printf(" SPEED: ");
        printf("%d",v1);
        
        printf("\n");
        
        printf("The SECOND runners stats: DISTANCE:");
        printf("%d",d2);
        printf(" SPEED: ");
        printf("%d",v2);
        
        printf("\n");printf("\n");
        
        if(d1>= finish)
        {
            printf("First Runner won!");
            break;
        }
        if(d2>= finish)
        {
            printf("Second Runner won!");
            break;
        }
    }
}

int main()
{
    srand(time(0));
    movement(0,0,0,0);
    return 0;
}
