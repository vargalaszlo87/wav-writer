#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <string.h>

#ifndef M_PI
#define M_PI 3.1415926535
#endif // M_PI

typedef struct wav {
    char RIFF[4];
    int32_t fileSize;
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
    #define SAMPLE_RATE 8000

    wavHeader WAV;
    //pVAW = &WAV;

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

    const int duration = 10;
    const int bufferSize = WAV.sampleRate * duration;

    WAV.dataSize = bufferSize * WAV.sampleRate;
    WAV.fileSize = WAV.dataSize + sizeof(wavHeader);

    short int *buffer = (int*)calloc(bufferSize, sizeof(int));

    for (int i = 0; i < bufferSize ; i++) {
        buffer[i] = (short int)(sin(( 2 * M_PI * 440 * i) / WAV.sampleRate) * 1000);
    }

    FILE *fp = fopen("teszt.wav", "w");
    fwrite(&WAV, 1, sizeof(wavHeader), fp);
//    fwrite(buffer, 2, bufferSize, fp);
    fclose(fp);

    printf("Hello world!\n");
    return 0;
}
