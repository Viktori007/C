#include <stdio.h>
/*
2. С клавиатуры ввести строку, состоящую из нескольких слов, разделленных
одним пробелом. Для хранения строки использовать новый тип
данных TEXT, введенный с помощью typedef. Написать функцию
подсчета количества слов в строке.*/

typedef struct TEXT {
    char str[100];
} TEXT;

int Words(char * c)
{
    int i, flag, cnt;

    for (i = 0, flag = 0, cnt = 0; c[i] != '\0'; i++)
    {
        if (c[i] == ' ' || c[i] == ',' || c[i] == '.'|| c[i] == '-') flag = 0;
        else
        {
            if (flag == 0)
            {
                cnt++;
                flag = 1;
            }
        }
    }
    printf("Всего слов = %zu\n", cnt);
    return 0;
}


int main(){
    setlocale(LC_ALL, "Rus");
    TEXT str1;
    scanf("%s", str1[0]);
    Words(str1[0]);
}
