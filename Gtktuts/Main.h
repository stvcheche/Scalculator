/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Main.h
 * Author: Jacob
 *
 * Created on April 9, 2021, 8:28 PM
 */
#include <gtk/gtk.h> 

#ifndef MAIN_H
#define MAIN_H

GtkWidget* retVbox();
void freemainMem();

typedef struct BtnInp {
         GtkWidget *btn;
         GtkWidget *inp;
         int index;

         struct BtnInp *next;

} BtnInp;

typedef struct Dvarsecs {
         char *fstvals;
         char *operands;
         char *secndval;
         char *mresult;
         char *predisx;

} Dvarsecs;

BtnInp* addVars(GtkWidget*, GtkWidget*, int, BtnInp*);
void show_stacka(BtnInp *heada);
BtnInp* gtIndex(BtnInp*, int);

void memrelease(BtnInp*);
char* gtSecndnum(const char *wsplit, int strt, int end);
void createTbl();

void insertData();
char* currTime();
void insertData(const gchar*);

void gtCount(int*);
char* gtData(int);
void clearTbl();

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */

