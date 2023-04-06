/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-edgar.maurel
** File description:
** my_getnbr.c
*/

int my_strlen(char *str);
int my_compute_power_rec(int nb, int p);

int str_to_int(char *str, int len, int neg)
{
    int res = 0;
    int pres = 0;

    for (int i = 0; i < len; i++) {
        pres = res;
        res -= (str[i] - 48) * my_compute_power_rec(10, len - i - 1);
        if (res > pres)
            return 0;
    }
    if (res == -2147483648 && neg == 1)
        return 0;
    return -res;
}

void change_neg(char c, int *is_on_number, int *neg)
{
    if (('9' < c || c < '0') && c != '-' && !*is_on_number && c != '+')
        *neg = 1;
    if (('0' <= c && c <= '9'))
        *is_on_number = 1;
    if (c == '-')
        *neg *= -1;
}

int my_getnbr(char *str)
{
    int is_on_number = 0;
    int len = my_strlen(str);
    int neg = 1;
    char res[len];
    int j = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (('9' < str[i] || str[i] < '0') && is_on_number)
            return neg * str_to_int(res, j, neg);
        change_neg(str[i], &is_on_number, &neg);
        if (is_on_number) {
            res[j] = str[i];
            j++;
        }
    }
    return neg * str_to_int(res, j, neg);
}
