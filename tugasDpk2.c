#include <stdio.h>
#include <stdlib.h>
int c[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

int main(){
    char p = 'X';
    int pilihan, menang = 0;

    for (int g = 0; g < 9 && menang == 0; g++) {
        for (int b = 0; b < 3; b++) {
            for (int k = 0; k < 3; k++) printf("%c   ", c[b][k]);
            printf("\n\n");
        }
        printf("Giliran %c, pilih kotak (1-9): ", p);
        scanf("%d", &pilihan);

        if (pilihan < 1 || pilihan > 9 || c[(pilihan - 1) / 3][(pilihan - 1) % 3] == 'X' || c[(pilihan - 1) / 3][(pilihan - 1) % 3] == 'O')
        {
            printf("Pilihan tidak valid!\n\n");
            g--;
        } else{
            c[(pilihan - 1) / 3][(pilihan - 1) % 3] = p;

            for (int i = 0; i < 3; i++)
                if ((c[i][0] == p && c[i][1] == p && c[i][2] == p) || (c[0][i] == p && c[1][i] == p && c[2][i] == p)) menang = 1;
            if ((c[0][0] == p && c[1][1] == p && c[2][2] == p) || (c[0][2] == p && c[1][1] == p && c[2][0] == p)) menang = 1;

            if (menang == 0 && p == 'X') p = 'O';
            else if (menang == 0) p = 'X';
        }
    }

    for (int b = 0; b < 3; b++){
        for (int k = 0; k < 3; k++) printf("%c   ", c[b][k]);
        printf("\n\n");
    } 
    if (menang == 1) printf("Pemain %c menang!\n", p);
    else printf("Seri!\n");

    return 0;
}
