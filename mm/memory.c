/*************************************************************************
	> File Name: memory.c
	> Author: Hermit
	> Mail: 1012hermit@gmail.com
	> Created Time: Sun 21 Nov 2021 05:01:44 AM PST
 ************************************************************************/

#include "memory.h"
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
#include "elf.h"


void init_memory()
{
    int i, j;
    unsigned long totalmem = 0;
    unsigned long count = 0;

    totalmem = START_ADDRESS - END_ADDRESS; 
    count = totalmem >> PAGE_SHIFT;
    printf("totalmem = %lu\t total 4K pages = %lu\n", totalmem, count);    

}
