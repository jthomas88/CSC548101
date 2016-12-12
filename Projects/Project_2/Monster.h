/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Monster.h
 * Author: rcc
 *
 * Created on December 12, 2016, 8:35 AM
 */

#ifndef MONSTER_H
#define MONSTER_H

#ifdef __cplusplus
extern "C" {
#endif

struct Monster{
        int    hpt;   //Max Health Points
        int    chp;   //Current health
        int    atk;   //Base Attack
        int    def;   //Base Defense
        int    spd;   //Base Speed
        int    mxp;   //Max EXP
        int    cxp;   //Current EXP
        int    lvl;   //Current Level
        string name;  //Monster Name
        string flvr;  //Monster Flavor Text
    };


#ifdef __cplusplus
}
#endif

#endif /* MONSTER_H */

