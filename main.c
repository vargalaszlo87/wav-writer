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
static wavHeader *pWAV;

int main()
{
    wavHeader WAV;
    pVAW = &WAV;

    strncpy(WAV.RIFF, "RIFF", 4);
    strncpy(WAV.WAVE, "WAVE", 4);
    strncpy(WAV.fmt, "fmt", 4);
    strncpy(WAV.data, "data", 4);

    WAV.chunkSize = 16;
    WAV.formatDataSize = 1;
    WAV.channelNumber = 1;
    WAV.sampleRate = 8000;
    WAV.bitsPerSample = 16;
    WAV.bytesPerSample = (WAV.bitsPerSample / 8) * WAV.channelNumber;
    WAV.bytesPerSecond = WAV.sampleRate * WAV.bytesPerSample;


    printf("Hello world!\n");
    return 0;
}
