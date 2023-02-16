/** С использованием struct */
/** Гусятинер Л.Б. 13.02.2023 КМПО РАНХиГС */

/*typedef struct Man {
    char name[100];
    int year;
} Man;*/

#include <stdio.h>
#include <string.h>
int main() {
    /*Man v[1000] = {
        {"Абельтин", 2004},
        {"Бекин", 2004},
        {"Мельникова", 2004},
        {"Подгорнова", 2004},
        {"Рогов", 2005},
        {"Голубятников", 2005},
        {"Мажоров", 2005},
        {"Васильева", 2005},
        {"Гаврюшкин", 2005},
        {"Егорова", 2005},
        {"Зарубин", 2005},
        {"Ивлеева", 2005},
        {"Капитонов", 2005},
        {"Кациев", 2005},
        {"Лесникова", 2005},
        {"Отинов", 2005},
        {"Русланова", 2005},
        {"Сивунов", 2005},
        {"Сокольникова", 2005},
        {"Старцев", 2005},
        {"Суворов", 2005},
        {"Цветков", 2005},
        {"Шарапова", 2005},
        {"Шевлягина", 2005},
        {"Шевченко", 2005},
        {"Яманова", 2005},
        {"Савченко", 2006}
    }; */
    
    
    FILE *file;
    struct man {
        char name[100]; 
        int year; 
    };
    struct man pep[10];
    char i=0;
    
    
    char s[100];
    scanf("%s", s);
    file = fopen("fscanf.txt", "r");
 
    while (fscanf(file, "%s%d", 
        pep[i].name, &(pep[i].year)) != EOF) {
 
        //printf("%s %d\n", pep[i].name, 
                //pep[i].year); int a;
    
    int a;
    char s[100];
    int year = -1;
    int len = sizeof(pep) / sizeof(pep[0]);
    scanf("%s", s);
    for (int i = 0; i < len; ++i) {
        if (strcmp(pep[i].name, s) == 0) {
            year = pep[i].year;
            break;
        }
    }
    if (year == -1)
        printf("not in group\n");
    else {
        switch (year % 12) {
        case 0:
            printf("обезьяна\n\n");
            break;
        case 1:
            printf("Петух\n\n");
            break;
        case 2:
            printf("собака\n\n");
            break;
        case 3:
            printf("свинья\n\n");
            break;
        case 4:
            printf("крыса\n\n");
            break;
        case 5:
            printf("бык\n\n");
            break;
        case 6:
            printf("тигр\n\n");
            break;
        case 7:
            printf("кролик\n\n");
            break;
        case 8:
            printf("дракон\n\n");
            break;
        case 9:
            printf("змея\n\n");
            break;
        case 10:
            printf("лошадь\n\n");
            break;
        case 11:
            printf("коза\n\n");
            break;
        default:
            printf("Error\n\n");
            break;
        }
    }
        i++;
    }
        
    /*
    //a.exe<rrr.txt;
    int a;
    char s[100];
    int year = -1;
    int len = sizeof(v) / sizeof(v[0]);
    scanf("%s", s);
    for (int i = 0; i < len; ++i) {
        if (strcmp(v[i].name, s) == 0) {
            year = v[i].year;
            break;
        }
    }
    if (year == -1)
        printf("not in group\n");
    else {
        switch (year % 12) {
        case 0:
            printf("обезьяна\n\n");
            break;
        case 1:
            printf("Петух\n\n");
            break;
        case 2:
            printf("собака\n\n");
            break;
        case 3:
            printf("свинья\n\n");
            break;
        case 4:
            printf("крыса\n\n");
            break;
        case 5:
            printf("бык\n\n");
            break;
        case 6:
            printf("тигр\n\n");
            break;
        case 7:
            printf("кролик\n\n");
            break;
        case 8:
            printf("дракон\n\n");
            break;
        case 9:
            printf("змея\n\n");
            break;
        case 10:
            printf("лошадь\n\n");
            break;
        case 11:
            printf("коза\n\n");
            break;
        default:
            printf("Error\n\n");
            break;
        }
    }*/
    return 0;
}