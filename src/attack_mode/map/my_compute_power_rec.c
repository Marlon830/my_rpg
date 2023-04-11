/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** task04
*/

int my_compute_power_rec(int nb, int p)
{

    if (p == 0) {
        return 1;
    }

    if (nb == 0) {
        return 0;
    }

    if (p % 2 == 0) {
        return my_compute_power_rec(nb * nb, p / 2);
    }
    return nb * my_compute_power_rec(nb * nb, (p - 1) / 2);
}
