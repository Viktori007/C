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
        {101, "������", "12:00", "14:00", 50},
        {102, "�������", "14:30", "16:30", 30},
        {103, "�������", "12:00", "12:30", 20},
    };
int count = sizeof(tickets) / sizeof(tickets[0]);

int arrival_time(char* destination){
    // ����� ������� ������ ��������� � ����� �
    printf("����� ������ � ����� %s:\n", destination);
    for (int i = 0; i < count; ++i) {
        if (strcmp(tickets[i].destination, destination) == 0) {
            printf("���� %d: %s\n", tickets[i].flightNumber, tickets[i].departureTime);
        }
    }

}

int available_seats(char* destination, char* departureTime){
    // ����� ������� ��������� ���� �� ���� � ����� � � �������� ����������� Y
    printf("������� ��������� ���� �� ���� � ����� %s � �������� ����������� %s:\n", destination, departureTime);
    for (int i = 0; i < count; ++i) {
        if (strcmp(tickets[i].destination, destination) == 0 &&
            strcmp(tickets[i].departureTime, departureTime) == 0) {
            printf("���� %d: ��������� ���� - %d\n", tickets[i].flightNumber, tickets[i].availableSeats);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    arrival_time("�������");
    available_seats("�������", "12:00");

    return 0;
}
