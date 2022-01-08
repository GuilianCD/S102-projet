#ifndef WAVE_H
#define WAVE_H

#include <iostream>
#include <vector>

using namespace std;

class Wave
{
private:
	std::vector<short> waveform;

public:
	void write_wav(const std::string &filename) const;
	void read_wav(const std::string & filename);

};
///my abomination=============================================================================
class Matrix{
    private:
        vector<vector<double>>lilma;
    
    public:
        Matrix(vector<vector<double>>mat_);
        vector<vector<double>> get_matrix() const;
};

class Vecter{
    private:
        vector<double>vacma;
    
    public:
        Vecter(vector<double>vec_);
        vector<double> get_vec() const;
};
///end of my abomination=======================================================================


typedef struct WAV_HEADER
{
    /* RIFF Chunk Descriptor */
    uint8_t         RIFF[4];        // RIFF Header Magic header
    uint32_t        ChunkSize;      // RIFF Chunk Size
    uint8_t         WAVE[4];        // WAVE Header
    /* "fmt" sub-chunk */
    uint8_t         fmt[4];         // FMT header
    uint32_t        Subchunk1Size;  // Size of the fmt chunk
    uint16_t        AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
    uint16_t        NumOfChan;      // Number of channels 1=Mono 2=Sterio
    uint32_t        SamplesPerSec;  // Sampling Frequency in Hz
    uint32_t        bytesPerSec;    // bytes per second
    uint16_t        blockAlign;     // 2=16-bit mono, 4=16-bit stereo
    uint16_t        bitsPerSample;  // Number of bits per sample
    /* "data" sub-chunk */
    uint8_t         Subchunk2ID[4]; // "data"  string
    uint32_t        Subchunk2Size;  // Sampled data length
} wav_hdr;

const long samplesPerSecond = 44100;

#endif
