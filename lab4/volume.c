// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef uint8_t byte;
typedef int16_t tbyte;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    
    // TODO: Copy header from input file to output file
    
    byte header[HEADER_SIZE];
    
    fread(header, sizeof(byte), 44, input);
    
    fwrite(header, sizeof(byte), 44, output);
        
    // TODO: Read samples from input file and write updated data to output file

    tbyte buffer;
    
    while(fread(&buffer, sizeof(tbyte), 1, input))
    {
        buffer = buffer * factor;
        
        fwrite(&buffer, sizeof(tbyte), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
