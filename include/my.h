/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my_printf
*/
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>

#ifndef MY_H
#define MY_H

typedef struct mysh_s mysh_t;

struct mysh_s
{
    char *stk;
    struct mysh_s *next;
};

void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(const char *str, ...);
void print_str(va_list ap);
void print_nbr(va_list ap);
void print_char(va_list ap);
void print_binary(va_list ap);
void print_hexa_up(va_list ap);
void print_octal(va_list ap);
void print_hexa_low(va_list ap);
void print_unsigned_decimal(va_list ap);
void print_pointeur(va_list ap);
char *decimal_to_other_base_unsigned(char *base, unsigned int n);
char *decimal_to_other_base_long(char *base, unsigned long int n);
void print_non_printable(va_list ap);
int sep_cmp(const char *str, int i, const char *sep);
void start_sep(const char *str, int *i, const char *sep);
int count_nbr_words(const char *str, const char *sep);
int len_word(const char *str, int *i, const char *sep);
void string_to_array(char **array, const char *str, const char *sep);
char **my_str_to_word_array(const char *str, const char *sep);
int malloc_match(char **array, char *str, int index);
int word_before_match(char **array, char *str, int index);
int my_isprintable(char c, char *array);
char *my_strdup(char const *src);
void swap_int_elem(int *array, int index1, int index2);
void swap_char_elem(char *array, int index1, int index2);
void sort_array(int *int_array, char *array);
char *concat_strings(char *dest, char const *src);
char *print_bit_antman(unsigned char value, char *str);
void my_cd(const char *path, char **env);
char *concat_strings(char *dest, char const *src);
void sig_catch(int sig);
char **my_read(void);

typedef struct char_list_s
{
    char *str;
    struct char_list_s *next;
} char_list;

void my_setenv(char_list **array_env, char **array);
void char_list_push_back(char_list **list, char *value);
char_list *create_array(char **env);
void print_list(char_list *data);
void my_unsetenv(char_list **array_env, char **array);
void step4(char_list *arr_env, char **env);
void do_exec(char *func, char_list *arr_env, char **array, char **env);
char **change_env(char_list *array_env);
char *exec_path(char_list *a_e, char *str);
void setenv_unsetenv(char **array, char_list *arr_env, char **env);

void process_cd(char_list **list, char **array);
void process_cd2(char_list **list);
void change_dir(char *path, char_list **list);
int push_array_elem(char_list **arr, char *str);
void put_endler(char const *s);
int list_empty(char_list **arr);
char_list *list_init(char_list *element);
void list_free(char_list **arr);
int supp_array_elem(char_list **arr, char *arg);
char *my_strjoin(char const *s1, char const *s2);
void my_free(char **as);
int error(int value, char *bad_cmd, char *bad_flag);
int check_old_pwd(char_list **list);
char *go_old_pwd(char_list **list);
char *go_home(char_list **list);
void process_tild(char_list **list, char *tmp);
char *new_malloc(size_t size);
char *sub_str(char const *s, unsigned int start, size_t len);
int acces(char *path);
void go_path(char_list **list, char **tab);
void add_old_pwd(char_list **list);
int my_str_isalpha_sh(char const *str);
char **temparray(char **array, int *i);
int temp(char *func, char **array, char **env);

typedef struct print_s
{
    char c;
    void (*ptr)(va_list);
} print_t;

typedef struct array_s
{
    bool first;
    int size;
    int *data;
} array_t;

typedef struct pipe_s
{
    char *fun;
    char **array;
    char **env;
} pipe_t;

// pipe //
#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);
int detect_pipe(char_list *arr_env, char *fun, char **array, char **env);

#endif