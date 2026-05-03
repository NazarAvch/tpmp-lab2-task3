/**
 * @file group.c
 * @brief Реализация функций для работы со структурой GROUP
 * @author Ваше имя
 * @version 1.0
 */

#include "group.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputGroup(GROUP *g) {
    printf("Введите фамилию и инициалы: ");
    fflush(stdin);
    fgets(g->Name, MAX_NAME, stdin);
    /* Удаляем символ новой строки, если он есть */
    size_t len = strlen(g->Name);
    if (len > 0 && g->Name[len - 1] == '\n') {
        g->Name[len - 1] = '\0';
    }
    
    printf("Введите дату рождения (год месяц день через пробел): ");
    scanf("%d %d %d", &g->DAT.year, &g->DAT.month, &g->DAT.day);
    
    printf("Введите три оценки (через пробел): ");
    for (int i = 0; i < SUBJECTS_COUNT; i++) {
        scanf("%d", &g->SES[i]);
    }
    fflush(stdin);
}

void printGroup(const GROUP *g) {
    printf("%-30s | %04d-%02d-%02d | %d %d %d | Сумма: %d\n",
           g->Name,
           g->DAT.year, g->DAT.month, g->DAT.day,
           g->SES[0], g->SES[1], g->SES[2],
           getSESSum(g));
}

int getSESSum(const GROUP *g) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS_COUNT; i++) {
        sum += g->SES[i];
    }
    return sum;
}

int compareBySES(const void *a, const void *b) {
    const GROUP *groupA = (const GROUP *)a;
    const GROUP *groupB = (const GROUP *)b;
    int sumA = getSESSum(groupA);
    int sumB = getSESSum(groupB);
    return (sumA - sumB);
}

int calculateAge(const DATE *birth, const DATE *targetDate) {
    int age = targetDate->year - birth->year;
    
    /* Если день рождения ещё не наступил в этом году, уменьшаем возраст */
    if (targetDate->month < birth->month) {
        age--;
    } else if (targetDate->month == birth->month && targetDate->day < birth->day) {
        age--;
    }
    
    return age;
}

int isYoungerOrEqual20(const GROUP *g) {
    const DATE targetDate = {2010, 12, 1};  /* 01.12.2010 */
    int age = calculateAge(&g->DAT, &targetDate);
    return (age <= 20);
}
