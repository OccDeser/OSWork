
#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "keyboard.h"
#include "proto.h"

PUBLIC int sys_getcr3(void){
    int ret;

    __asm__ volatile (
        "mov %%cr3, %[ret]"
        : [ret] "=r" (ret)
    );


    return ret;
}

PUBLIC void sys_putcr3(unsigned int pdb_addr){
    __asm__ volatile (
        "mov %[pdb_addr], %%cr3"
        :
        : [pdb_addr] "r" (pdb_addr)
    );

    return ;
}