/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#pragma once
#ifndef vex
#define vex vex
/*----------------------------------Includes----------------------------------*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include "iostream"
#include "robot-config.h"
#include "v5.h"
#include "v5_vcs.h"
/*-------------------------------Namespaces-----------------------------------*/
using namespace vex;
using namespace std;
/*---------------------------------User Defined Macros------------------------*/
#define R_Normal 0
#define R_74000M 1
#define R_74000V 2
#define R_74000P 3
#define R_74000F 4
#define R_77921F 5
#define delay wait
#define Print Brain.Screen.printAt
#define abs(x) (((x) > 0) ? (x) : -(x))
// #define wait   vex::this_thread::sleep_for
#define ROBOT    R_74000V
#define marco_toSring(x) #x
//#define SimpleCompetitionControl SimpleCompetitionControl


/*---------------------Function/Compile Control Macros-----------------------*/


/*--Select robot models From Here--*/
#define bot_97917G r97917G
//#define bot_97917A r97917A



/*--When Some code are not fully tested , they won't be activated unless
you define the USING_BETA attribute.
Surround your code with "#ifdef USING_BETA" , "#endif" to make it a beta test.
Or,you can make a individual marco for every beta feature.                    */

/*        List of Functions Under testing:
*          auto_push.cpp -> push_goto_highest_according_to_enc()
*       handle_push.cpp->
 *             void handle_push(int key_push_out, int key_push_in, int slow_mode)
* 
*
*
*
*/
#define USING_BETA   USING_BETA



/*----------------------------------Global Variables--------------------------*/
extern vex::brain       Brain;
extern vex::controller  Controller;
extern vex::competition Competition;



/*--------------------------------Function prototypes-------------------------*/
void wait(int milsec);
void pre_auton(void);
void autonomous(void);
void usercontrol(void);

int sgn(double x);
void zero_blind(int &x, unsigned int threshold);
void max_limit(int &x, unsigned int bnd);

/*-----------------------------Compile Info Output--------------------------*/
#ifdef bot_97917A
#ifndef bot_97917G
#pragma message("Current Bot Module:97917A")
#endif
#endif

#ifdef bot_97917G
#ifndef bot_97917A
#pragma message("Current Bot Module:97917G")
#endif
#endif

#ifndef bot_97917A
#ifndef bot_97917G
#pragma message("Please define robot!")
#endif
#endif

#ifdef bot_97917A
#ifdef bot_97917G
#error Multiple Robot Configuration Definition Detected.Please check your definition in src/vex.h
#endif
#endif



#endif
