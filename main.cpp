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

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;
struct Mem
{
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise() 
    {
        for ( u32 i = 0; i < MAX_MEM; i++)
        {
            Data[i] = 0;
        }
    }

    // read 1 byte
    Byte operator[] ( u32 Address ) const
    {
        // assert here  is < MAX_MEM
        return Data[Address];
    }


    // write 1 byte
    Byte& operator[] ( u32 Address ) 
    {
        // assert here  is < MAX_MEM
        return Data[Address];
    }

};


struct CPU
{
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

    void Reset( Mem& memory )
    {
        PC = 0xFFFC;
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;
        memory.Initialise();
    }

    Byte FetchByte( u32 Cycles, Mem& memory )
    {
        Byte Data = memory[PC];
        PC++ ;
        Cycles--;
        return Data;
    }

    // opcode
    static constexpr Byte
        INS_LDA_IM = 0xA9;

    // Executes instructions 
    void Execute( u32 Cycles, Mem& memory )
    {
        while( Cycles > 0)
        {
            Byte Ins = FetchByte( Cycles, memory );
            switch ( Ins )
            {
            case INS_LDA_IM:
            {
                Byte Value = 
                FetchByte( Cycles, memory);
                A = Value;
                Z = (A == 0);
                N = (A & 0b10000000) > 0;
            } break;
            default:
            {
                printf("Instruction Not Handled %d", Ins);
            }break;
            }
        }
    }

};


int main()
{
    Mem mem;
    CPU cpu;
    cpu.Reset( mem );
    printf("CPU Reset~");
    mem[0xFFFC] = CPU::INS_LDA_IM;
    mem[0xFFFD] = 0x42;

    cpu.Execute( 2, mem );
    printf("CPU reset!");
    return 0; 
}