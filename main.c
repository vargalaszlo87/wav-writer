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
    // riff
    char chunkID[4];
    int32_t chunkSize;
    char format[4];
    // fmt
    char subChunk1ID[4];
    int32_t subchunk1Size;
    int16_t audioFormat;
    int16_t numChannels;
    int32_t sampleRate;
    int32_t byteRate;
    int16_t blockAgain;
    int16_t bitsPerSample;
    // data
    char subchunk2ID[4];
    int32_t subchunk2Size;
} wavHeader;
static wavHeader *pWAV;

int main()
{
    #define DURATION 3

    wavHeader WAV;
    //pVAW = &WAV;

    // riff
    strncpy(WAV.chunkID, "RIFF", 4);
    strncpy(WAV.format, "WAVE", 4);
    // fmt
    strncpy(WAV.subChunk1ID, "fmt ", 4);
    WAV.subchunk1Size = 16;
    WAV.audioFormat = 1;
    WAV.numChannels = 1; // 1 -> mono
    WAV.sampleRate = 32000;
    WAV.blockAgain = WAV.numChannels * WAV.bitsPerSample / 8;
    WAV.byteRate = WAV.sampleRate * WAV.blockAgain;
    WAV.bitsPerSample = 16;
    // data
    strncpy(WAV.subchunk2ID, "data", 4);
    int bufferSize = WAV.sampleRate * DURATION;
    WAV.subchunk2Size = bufferSize * WAV.numChannels * WAV.bitsPerSample / 8;

    // end of riff
    WAV.chunkSize = 4 + (8 + WAV.subchunk1Size) + 8 + WAV.subchunk2Size;


    float *buffer = (float*)calloc(bufferSize, sizeof(float));

    for (int i = 0; i < bufferSize ; i++) {
        buffer[i] = (cos(( 2 * M_PI * 5000 * i) / WAV.sampleRate) * 1000);
    }

    FILE *fp = fopen("teszt.wav", "w");
    fwrite(&WAV, 1, sizeof(wavHeader), fp);
    fwrite(buffer, 2, bufferSize, fp);
    fclose(fp);

    printf("Hello world!\n");
    return 0;
}
