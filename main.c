#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

typedef struct wav {
    char RIFF[4];
    int32_t FileSize;
    char WAVE[4];
    char fmt[4];
    int32_t chunkSize;
    int16_t formatDataSize;
    int16_t channelNumber;
    int32_t sampleRate;
    int16_t bytesPerSecond;
    int32_t bytesPerSample;
    int16_t bitsPerSample;
    char data[4];
    int32_t dataSize;
} wavHeader;
static wavHeader *pVAW;

int main()
{
    wavHeader VAW;
    pVAW = &VAW;

    strncpy(VAW.RIFF, "RIFF", 4);
    strncpy(VAW.WAVE, "WAVE", 4);
    strncpy(VAW.fmt, "fmt", 4);
    strncpy(VAW.data, "data", 4);

    VAW.chunkSize = 16;
    VAW.formatDataSize = 1;
    VAW.channelNumber = 1;
    VAW.



    printf("Hello world!\n");
    return 0;
}
