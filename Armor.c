#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct armor
{
    char name[50];
    char armor_type[50]
    int armor_ac;
}armor;

armor* armor_opt(char name[50], int armor_ac)
{
    armor* p = (armor)malloc(sizeof(armor))
    if (p == NULL) 
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(p->name, name);
    strcpy(p->armor_type, armor_type);

    p->armor_ac = Armor_AC;

    return p;
}