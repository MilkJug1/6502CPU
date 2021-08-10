#include <stdio.h>
#include <stdlib.h>
/*
=======================================
= Program made by: Michael Crawford
= Credits goes to Dave Poo on Youtube
= -for making that tutorial
= Date Created 08/09/2021 (August 9, 2021)
===========================================
*/



struct CPU
{
    using Byte = unsigned char;
    using Word = unsigned short;


    Word PC;    //program pointer
    Word SP;    // stack pointer


    Byte A, X, Y;   //registers 

    Byte C : 1; // status flag
    Byte Z : 1; // status flag
    Byte I : 1; // status flag
    Byte D : 1; // status flag
    Byte B : 1; // status flag
    Byte V : 1; // status flag
    Byte N : 1; // status flag

};


int main()
{
    CPU cpu;
}