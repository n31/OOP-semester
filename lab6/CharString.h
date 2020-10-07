#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

char* setString() {
    rewind(stdin);
    char* str = (char*)malloc(1);
    int i = 1, c;
    while ((c = getchar()) != EOF && c != '\n') {
        i++;
        str = (char*)realloc(str, i);
        str[i - 2] = c;
        str[i - 1] = '\0';
    }
    return str;
}
