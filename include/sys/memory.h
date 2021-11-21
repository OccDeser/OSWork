/*************************************************************************
	> File Name: memory.h
	> Author: Hermit
	> Mail: 1012hermit@gmail.com
	> Created Time: Sun 21 Nov 2021 04:22:36 AM PST
 ************************************************************************/

#ifndef _MEMORY_H
#define _MEMORY_H

// the start address of user space
#define PAGE_OFFSET 0
#define PAGE_SHIFT  12
#define PAGE_SIZE   (1UL << PAGE_SHIFT)
#define PAGE_MASK   (~ (PAGE_SIZE - 1))

#define Virt_To_Phy(addr)   ((unsigned long)(addr) - PAGE_OFFSET)
#define Phy_To_Virt(addr)   ((unsigned long *)((unsigned long)(addr) + PAGE_OFFSET))

#define START_ADDRESS       0x100000    // 10M
#define END_ADDRESS         0x2000000   // 32M

struct global_memory_descriptor 
{
    unsigned long *     bits_map;
    unsigned long       bits_size;
    unsigned long       bits_length;

    unsigned long       start_code, end_code, end_data, end_brk;

    unsigned long       pages_count;
    
    unsigned long       end_of_struct;
};

struct page 
{
    struct global_memory_descriptor *gmd_struct;
    unsigned long   PHY_address;
    unsigned long   attribute;

    unsigned long   reference_count;

    // it should be used in NRU (if I have time to make it come true:))
    unsigned long age;
};

void init_memory();



#endif
