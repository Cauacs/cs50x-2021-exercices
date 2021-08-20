#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc !=2)
    {
        printf("Usage ./recover.c file");
        return 2;
    }

    FILE* card = fopen(argv[1], "r");
    if(card == NULL)
    {
        printf("Cant open the file");
        return 3;
    }

    BYTE buffer[512];
    int ct = 0;

    char *filename = malloc(8);

    FILE* jpg;

    while(fread(buffer, sizeof(BYTE), 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(ct == 0)
            {
                sprintf(filename,"%03i.jpg", ct);

                jpg = fopen(filename, "w");

                if(jpg == NULL)
                    return 1;

                fwrite(buffer, sizeof(BYTE), 512, jpg);

                ct++;
            }
            else
            {
                fclose(jpg);

                sprintf(filename, "%03i.jpg", ct);

                jpg = fopen(filename, "w");

                if(jpg == NULL)
                    return 1;

                fwrite(buffer, sizeof(BYTE), 512, jpg);

                ct++;
            }

        }

        else
        {
            if(ct != 0)
                fwrite(buffer, sizeof(BYTE), 512, jpg);
        }
    }

    free(filename);
    fclose(jpg);
    fclose(card);
}