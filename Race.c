#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct races
{
    char name[50];
    int r_STR, r_DEX, r_CON, r_WIS, r_INT, r_CHA;
}races;

// Function to create a new race
races* Race_opt(char name[50], int r_STR, int r_DEX, int r_CON, int r_WIS, int r_INT, int r_CHA) 
{
    // Allocate memory for a new race
    races* p = (races*)malloc(sizeof(races));
    // Check if malloc succeeded
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Copy the name into the race structure
    strcpy(p->name, name);

    // Initialize the race attributes
    p->r_STR = r_STR;
    p->r_DEX = r_DEX;
    p->r_CON = r_CON;
    p->r_WIS = r_WIS;
    p->r_INT = r_INT;
    p->r_CHA = r_CHA;

    return p;  // Return the pointer to the new race
}

//void get_r_STR(struct races* race_ab, int r_str)
//{
//    race_ab -> r_STR = r_str;
//}

//void get_r_DEX(struct races* race_ab, int r_dex)
//{
//    race_ab -> r_DEX = r_dex;
//}

//void get_r_CON(struct races* race_ab, int r_con)
//{
//    race_ab -> r_CON = r_con;
//}

//void get_r_WIS(struct races* race_ab, int r_wis)
//{
//    race_ab -> r_WIS = r_wis;
//}

//void get_r_INT(struct races* race_ab, int r_int)
//{
//    race_ab -> r_INT = r_int;
//}

//void get_r_CHA(struct races* race_ab, int r_cha)
//{
//    race_ab -> r_CHA = r_cha;
//}

void get_option_ab(struct races* race_ab,int ab_limit, int r_opt)
{
    char opt_ab[50];

    for (int i = 0; i < ab_limit; i++)
    {
        printf("choose an ability to increase: ");
        scanf("%s", &opt_ab);

        if (strcmp(opt_ab, "STR") == 0)
            race_ab->r_STR += r_opt;
        else if (strcmp(opt_ab, "DEX") == 0)
            race_ab->r_DEX += r_opt;
        else if (strcmp(opt_ab, "CON") == 0)
            race_ab->r_CON += r_opt;
        else if (strcmp(opt_ab, "WIS") == 0)
            race_ab->r_WIS += r_opt;
        else if (strcmp(opt_ab, "INT") == 0)
            race_ab->r_INT += r_opt;
        else if (strcmp(opt_ab, "CHA") == 0)
            race_ab->r_CHA += r_opt;
        else
            printf("Invalid choice!\n");

    }

}

void call_elf_r(struct races* elf)
{
    
        if (strcmp(elf->name, "elf") == 0)
        {
            elf->r_DEX += 2;
        }
        else if (strcmp(elf->name, "dark elf") == 0)
        {
            elf->r_CHA += 1;
        } 
}

void call_human_r(struct races* human)
{
    if (strcmp(human->name, "human") == 0)
    {
        human -> r_STR = 1;
        human -> r_DEX = 1;
        human -> r_CON = 1;
        human -> r_WIS = 1;
        human -> r_INT = 1;
        human -> r_CHA = 1;
    }
    else if (strcmp(human->name, "finding") == 0)
    {
        get_option_ab(human, 2, 1);
    }
}

void call_half_elf_r(struct races* half_elf)
{
    if(strcmp(half_elf->name, "half_elf") == 0)
    {
        get_option_ab(half_elf, 2, 1);
        half_elf->r_CHA += 2;
    }
}

int main()
{
    races elf = {"elf", 0, 0, 0, 0, 0, 0};
    races human = {"finding", 0, 0, 0, 0, 0, 0};
    races half_elf = {"half_elf", 0, 0, 0, 0, 0, 0};

    call_elf_r(&elf);
    printf("Elf stats: STR: %d, DEX: %d, CON: %d, WIS: %d, INT: %d, CHA: %d\n",
           elf.r_STR, elf.r_DEX, elf.r_CON, elf.r_WIS, elf.r_INT, elf.r_CHA);

    call_human_r(&human);
    printf("Human finding stats: STR: %d, DEX: %d, CON: %d, WIS: %d, INT: %d, CHA: %d\n",
           human.r_STR, human.r_DEX, human.r_CON, human.r_WIS, human.r_INT, human.r_CHA);

    call_half_elf_r(&half_elf);
    printf("half_elf finding stats: STR: %d, DEX: %d, CON: %d, WIS: %d, INT: %d, CHA: %d\n",
           half_elf.r_STR, half_elf.r_DEX, half_elf.r_CON, half_elf.r_WIS, half_elf.r_INT, half_elf.r_CHA);
    return 0;
}