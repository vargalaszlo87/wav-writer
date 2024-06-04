#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#ifndef M_PI
#define M_PI 3.1415926535
#endif // M_PI

short int buff[8000 * 3] = {};

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
    WAV.sampleRate = 8000;
    WAV.bitsPerSample = 16;
    WAV.blockAgain = WAV.numChannels * WAV.bitsPerSample / 8;
    WAV.byteRate = WAV.sampleRate * WAV.blockAgain;

    // data
    strncpy(WAV.subchunk2ID, "data", 4);
    int bufferSize = WAV.sampleRate * DURATION;
    WAV.subchunk2Size = bufferSize * WAV.blockAgain;

    // end of riff
    WAV.chunkSize = WAV.subchunk2Size + sizeof(wavHeader);



    short int *buffer = (short int*)calloc(bufferSize, sizeof(short int));
    for (int i = 0; i < bufferSize ; i++) {
        buffer[i] = (short int)((cos(2 * M_PI * (float)440.00 * i) / WAV.sampleRate) * 1000);
    }

    FILE *fp = fopen("teszt.wav", "w");
    fwrite(&WAV, 1, sizeof(wavHeader), fp);
    fwrite(buffer, 2, bufferSize, fp);


    printf("Make it!\n");
    return 0;


}
