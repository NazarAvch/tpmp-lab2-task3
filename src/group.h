#ifndef GROUP_H
#define GROUP_H

typedef struct {
    char Name[50];
    struct { int year, month, day; } DAT; // дата рождения
    int SES[3]; // успеваемость (3 оценки)
} GROUP;

// Функция ввода одной записи
void inputGroup(GROUP *g);
// Функция вывода записи
void printGroup(const GROUP *g);
// Сравнение по суммарному баллу (для qsort)
int compareBySES(const void *a, const void *b);
// Проверка возраста на 01.12.2010 (возраст <=20)
int isYoungerThan20(const GROUP *g);

#endif
