/**
 * @file main.c
 * @brief Главная программа для работы со структурой GROUP
 * @author Ваше имя
 * @version 1.0
 * 
 * Программа выполняет:
 * 1. Ввод 10 структур GROUP с клавиатуры
 * 2. Вывод записей, упорядоченных по возрастанию суммы оценок (SES)
 * 3. Вывод списка студентов младше или равных 20 лет на 01.12.2010
 */

#include "group.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

int main(void) {
    GROUP students[MAX_STUDENTS];
    int i;
    int foundYoung = 0;
    
    printf("========================================\n");
    printf("Ввод данных о студентах (всего %d)\n", MAX_STUDENTS);
    printf("========================================\n\n");
    
    /* Ввод данных */
    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("--- Студент №%d ---\n", i + 1);
        inputGroup(&students[i]);
        printf("\n");
    }
    
    /* Сортировка по возрастанию суммы оценок */
    qsort(students, MAX_STUDENTS, sizeof(GROUP), compareBySES);
    
    /* Вывод отсортированного списка */
    printf("\n========================================\n");
    printf("Список студентов, упорядоченный по возрастанию суммы оценок\n");
    printf("========================================\n");
    printf("%-30s | %-12s | %-10s | %s\n", 
           "Фамилия и инициалы", "Дата рождения", "Оценки", "Сумма");
    printf("---------------------------------------------------------\n");
    for (i = 0; i < MAX_STUDENTS; i++) {
        printGroup(&students[i]);
    }
    
    /* Вывод студентов младше или равных 20 лет на 01.12.2010 */
    printf("\n========================================\n");
    printf("Студенты, возраст которых на 01.12.2010 не превышает 20 лет\n");
    printf("========================================\n");
    
    for (i = 0; i < MAX_STUDENTS; i++) {
        if (isYoungerOrEqual20(&students[i])) {
            printf("%-30s (дата рождения: %04d-%02d-%02d)\n",
                   students[i].Name,
                   students[i].DAT.year,
                   students[i].DAT.month,
                   students[i].DAT.day);
            foundYoung = 1;
        }
    }
    
    if (!foundYoung) {
        printf("Студенты, возраст которых на 01.12.2010 не превышает 20 лет, не найдены.\n");
    }
    
    printf("\n========================================\n");
    printf("Программа завершена.\n");
    
    return 0;
}
