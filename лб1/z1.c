/* 7. ������������ ������, ���������� �������� � ������� �������
�� ����� ���������. ����������� ��� �������� ����: ����� �����,
����� ����������, ����� ������, ����� ��������, ���������� ���������
���� � ������.
�������� ���������, �������� ��������� ����������:
� ����� ������ ��������� � ����� �;
� * ������� ��������� ���� �� ���� � ����� � � �������� ���������-
��� Y.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "date.h"

typedef struct ticket{
    int flight_number;//����� �����
    char* destination; //����� ����������
    Data departure_time;//����� ������
    Data arrival_time;//����� ��������
    int number_of_available_seats; //���������� ��������� ���� � ������
}ticket;


int main(){
    setlocale(LC_ALL, "Rus");
    struct ticket tickets[100];
    //struct address *adr = (struct address*) malloc(sizeof(struct address));


    return 0;
}
