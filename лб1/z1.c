/* 7. Сформировать массив, содержащий сведения о наличии билетов
на рейсы Аэрофлота. Структурный тип содержит поля: номер рейса,
пункт назначения, время вылета, время прибытия, количество свободных
мест в салоне.
Написать программу, выдающую следующую информацию:
• время вылета самолетов в город Х;
• * наличие свободных мест на рейс в город Х с временем отправлен-
ния Y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "date.h"

typedef struct ticket{
    int flight_number;//номер рейса
    char* destination; //пункт назначения
    Data departure_time;//время вылета
    Data arrival_time;//время прибытия
    int number_of_available_seats; //количество свободных мест в салоне
}ticket;


int main(){
    setlocale(LC_ALL, "Rus");
    struct ticket tickets[100];
    //struct address *adr = (struct address*) malloc(sizeof(struct address));


    return 0;
}
