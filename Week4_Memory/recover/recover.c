#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error Input: The command line only accept one argument\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    if (card == NULL)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return 1;
    }

    uint8_t buffer[512];
    int jpeg_count = 0;
    FILE *outfile = NULL;
    char filename[8];

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            sprintf(filename, "%03i.jpg", jpeg_count);
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                fclose(card);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 1;
            }

            jpeg_count++;
        }
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, outfile);
        }

    }
    if (outfile != NULL)
    {
        fclose(outfile);
    }

    fclose(card);

    return 0;
}