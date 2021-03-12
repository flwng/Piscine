#include<unistd.h>
#include <stdio.h>

int condizioni[16];
int check_box[4][4];
int box[4][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

void    stampa(char c)
{
    write(1, &c, 1);
}

void    print_box(void)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            stampa(box[i][j] + '0');
            if (j != 3)
                stampa(' ');
            j++;
        }
        stampa('\n');
        i++;
    }
}

int     condizione_valida(char *controllo_condizioni)
{
    int i;

    i = 0;
    while(*controllo_condizioni != '\0')
    {
            if (*controllo_condizioni == ' ')
                controllo_condizioni++;
            else if (*controllo_condizioni >= '1' && *controllo_condizioni <= '4')
            {
                condizioni[i] = *controllo_condizioni - '0';
                controllo_condizioni++;
                i++;
            }
            else
                return (0);
    }
    return (i == 16);
}

int     riempio()
{
    int i;
    int j;

    i = 0;
    while (condizioni[i])
    {
        if (condizioni[i] == 1)
        {
            if (i >= 0 && i <= 3)
                box[0][i%4] = 4;
            else if (i >=4 && i <= 7)
                box[3][i%4] = 4;
            else if (i >= 8 && i <= 11)
                box[i%4][0] = 4;
            else if (i >= 12 && i <= 15)
                box[i%4][3] = 4;
        }
        i++;
    }

    i = 0;
    j = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            if (j == 0 && box[i][j] == 4)
            {
                box[i][1] = 1;
                box[i][2] = 2;
                box[i][3] = 3;
            }
            else if (j == 1 && box[i][j] == 4)
            {
                box[i][0] = 3;
                box[i][2] = 1;
                box[i][3] = 2;
            }
            else if (j == 2 && box[i][j] == 4)
            {
                box[i][0] = 2;
                box[i][1] = 3;
                box[i][3] = 1;
            }
            else if (j == 3 && box[i][j] == 4)
            {
                box[i][0] = 1;
                box[i][1] = 2;
                box[i][2] = 3;
            }
            j++;
        }
        i++;
    }


    print_box();
    return (1);
}

void    check_doppie(int arr[4][4])
{
    int prodotto;
    int val;
    int j;
    int i;

    i = 0;
    while (i < 4)
    {
        j = 0;
        prodotto = arr[i][0] * arr[i][1] * arr[i][2] * arr[i][3];
        val = 24 / (prodotto - 24);
        while (j < 4)
        {
            if (box[i][i] == box[i][j])
            {
                if (check_box[i][i] == 0)
                {
                    box[i][i] = val;
                    check_box[i][j] = 0;
                }
                else
                {
                    box[i][j] = val;
                    check_box[i][i] = 0;
                }
            }
            j++;
        }
        i++;
    }
}

void    swap(int n1, int n2, int c)
{
    int temp;
    int i;

    temp = 0;
    i = 0;
    while (i < c)
    {
        if ((n1 < n2) && (c < n2))
        {
            if ((n1 == 4) || (n2 == 4))
                continue ;
            temp = n1;
            n1 = n2;
            n2 = temp;
        }
    }
}

int     is_valid(int c)
{
    int i;
    int j;
    int count;
    int max_val;
    
    i = 0;
    j = 0;
    j = 0;
    count = 0;
    max_val = 0;
    while (j < 4)
    {
        if (box[i][j] > max_val)
        {
            count++;
            max_val = box[i][j];
        }
        j++;
    }
    return (c == count);
}

int     rush(void)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (++i < 5)
    {
        while (++j < 5)
        {
            check_box[i][j] = 0;
        }
    }
    return (riempio());
}

int		main(int argc, char *argv[])
{
	if (argc != 2 || !((condizione_valida(argv[1])) && (rush())))
		write(1, "Error\n", 6);
	return (0);
}
