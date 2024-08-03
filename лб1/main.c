#include <stdio.h>
#include <string.h>
#include <locale.h>

struct ticket {
    int flightNumber;
    char destination[50];
    char departureTime[10];
    char arrivalTime[10];
    int availableSeats;
};

struct ticket tickets[] = {
        {101, "Москва", "12:00", "14:00", 50},
        {102, "Обнинск", "14:30", "16:30", 30},
        {103, "Обнинск", "12:00", "12:30", 20},
    };
int count = sizeof(tickets) / sizeof(tickets[0]);

int arrival_time(char* destination){
    // Вывод времени вылета самолетов в город Х
    printf("Время вылета в город %s:\n", destination);
    for (int i = 0; i < count; ++i) {
        if (strcmp(tickets[i].destination, destination) == 0) {
            printf("Рейс %d: %s\n", tickets[i].flightNumber, tickets[i].departureTime);
        }
    }

}

int available_seats(char* destination, char* departureTime){
    // Вывод наличия свободных мест на рейс в город Х с временем отправления Y
    printf("Наличие свободных мест на рейс в город %s с временем отправления %s:\n", destination, departureTime);
    for (int i = 0; i < count; ++i) {
        if (strcmp(tickets[i].destination, destination) == 0 &&
            strcmp(tickets[i].departureTime, departureTime) == 0) {
            printf("Рейс %d: Свободных мест - %d\n", tickets[i].flightNumber, tickets[i].availableSeats);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    arrival_time("Обнинск");
    available_seats("Обнинск", "12:00");

    return 0;
}
