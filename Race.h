#ifndef Race_H
#define Race_H

#include <stdio.h>
#include <string.h>

typedef struct races
{
    char name[50];
    int r_STR, r_DEX, r_CON, r_WIS, r_INT, r_CHA;
}races;

void get_r_STR(struct races* race_ab, int r_str)
void get_r_DEX(struct races* race_ab, int r_dex)
void get_r_CON(struct races* race_ab, int r_con)
void get_r_WIS(struct races* race_ab, int r_wis)
void get_r_INT(struct races* race_ab, int r_int)
void get_r_CHA(struct races* race_ab, int r_cha)
void get_option_ab(struct races* race_ab,int ab_limit, int r_opt)
void call_elf_r(struct races* elf)
void call_human_r(struct races* human)

#endif