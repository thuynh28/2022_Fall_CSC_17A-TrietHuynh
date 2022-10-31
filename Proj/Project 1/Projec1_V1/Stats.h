/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stats.h
 * Author: Triet
 *
 * Created on October 29, 2022, 12:45 AM
 */

#ifndef STATS_H
#define STATS_H
#include "Arry.h"
using namespace std;

struct Stats{
    int players;   //number of players
    string *names;   //players' names array
    int *sum;   //players' total attempts array
    Arry avg; //player's average attempts array
};

#endif /* STATS_H */

