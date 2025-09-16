#include <stdio.h>
#include <string.h>

#define MAX 100

int main(int argc, char *argv[])
{
    // Dichiarazione delle variabili
    char stringa[MAX], copia[MAX];
    int scelta, i;

    printf("Inserisci una stringa (max 100 caratteri): ");
    fgets(stringa, MAX, stdin);

    do
    {
        printf("1. Controlla che contenga solo lettere\n");
        printf("2. Conta l'occorrenza di una lettera nella stringa\n");
        printf("3. Crea due ulteriori stringhe che contengano 1 le lettere di posizione pari e 2 le lettere di posizione dispari\n");
        printf("4. Verifica se la stringa contiene doppie\n");
        printf("5. Esci\n");
        printf("Inserisci la scelta: ");
        scanf("%d", &scelta);

        switch (scelta)
        {
        case 1:

            printf("Controlla che contenga solo lettere\n"); // gli spazi sono considerati caratteri validi
            {
                int solo_lettere = 1;
                for (i = 0; stringa[i] != '\0' && stringa[i] != '\n'; i++)
                {
                    if (!((stringa[i] >= 'A' && stringa[i] <= 'Z') || (stringa[i] >= 'a' && stringa[i] <= 'z') || stringa[i] == ' '))
                    {
                        solo_lettere = 0;
                        break;
                    }
                }
                if (solo_lettere)
                    printf("La stringa contiene solo lettere e spazi\n");
                else
                    printf("La stringa contiene caratteri NON alfabetici\n");
            }
            break;

        case 2:
            printf("Conta l'occorrenza di una lettera nella stringa\n");
            char lettera;
            int cont = 0;
            printf("Inserisci la lettera da cercare: ");
            scanf(" %c", &lettera);
            for (i = 0; stringa[i] != '\0' && stringa[i] != '\n'; i++)
            {
                if (stringa[i] == lettera)
                    cont++;
            }
            if (cont > 0)
                printf("La lettera '%c' compare %d volte nella stringa\n", lettera, cont);
            else
                printf("La lettera '%c' non compare nella stringa\n", lettera);
            break;

        case 3:
            printf("Crea due ulteriori stringhe che contengano 1 le lettere di posizione pari e 2 le lettere di posizione dispari\n");
            char pari[MAX], dispari[MAX];
            int j = 0, k = 0;
            for (i = 0; stringa[i] != '\0' && stringa[i] != '\n'; i++)
            {
                if (i % 2 == 0)
                {
                    pari[j++] = stringa[i];
                }
                else
                {
                    dispari[k++] = stringa[i];
                }
            }
            pari[j] = '\0';
            dispari[k] = '\0';
            printf("Stringa con lettere in posizione pari: %s\n", pari);
            printf("Stringa con lettere in posizione dispari: %s\n", dispari);
            break;

        case 4:
            printf("Verifica se la stringa contiene doppie\n");
            {
                int doppie = 0;
                for (i = 0; stringa[i] != '\0' && stringa[i] != '\n'; i++)
                {
                    if (stringa[i] == stringa[i + 1])
                    {
                        doppie = 1;
                        break;
                    }
                }
                if (doppie)
                    printf("La stringa contiene doppie\n");
                else
                    printf("La stringa NON contiene doppie\n");
            }
            break;

        case 5:
            printf("Uscita dal programma\n");
            break;

        default:
            break;
        }

        printf("\n");
    } while (scelta != 5 && scelta > 0 && scelta < 6);

    return 0;
}