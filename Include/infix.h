#ifndef INFIX_H
#define INFIX_H

int set_flag(char ch);

void infix_postfix_conversion(char *arr, char *buff);

void infix_postfix_evaluation(char *buff);

void infix_prefix_conversion(char *arr, char*buff);

void infix_prefix_evaluation(char *buff);

int partition(int *arr, int low, int high);

void quick_sort(int *arr, int low, int high);

int partition_dec(int *arr, int low, int high);

void quick_sort_dec(int *arr, int low, int high);

#endif
