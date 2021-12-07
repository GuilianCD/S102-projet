#include <fstream>
#include <vector>

#include "wave.h"

// sup

// Ceci est utile

using namespace std;


void Wave::write_wav(const string & filename) const
{
	const char riffTag[4] = {'R','I','F','F'};         // "RIFF"
	const char waveTag[4] = {'W','A','V','E'};         // "WAVE"
	const char fmtTag[4] = {'f','m','t',' '};          // "fmt ", start of format data
	const char dataTag[4] = {'d','a','t','a'};         // "data", start of sound data
	const int32_t fmtLength = 16;       // Size of fmt subchunk
	const int16_t audioFormat = 1;     // Audio compression format
	const int16_t numChannels = 1;     // Number of audio channels
	const int32_t sampleRate = 44100;      // Samples of audio per second
	const int16_t bitsPerSample = 16;  // Bits  for one sample
	const int16_t blockAlign = bitsPerSample/8;      // Bytes for one sample
	const int32_t byteRate = sampleRate * blockAlign;       // Bytes per second

	int32_t dataLength = waveform.size() * sizeof(short); // Size of sound data
	int32_t riffLength = dataLength + sizeof(wav_hdr); // Size of RIFF header

	ofstream os(filename, ios::out | ios::binary);

	os.write(&riffTag[0], sizeof(riffTag));
	os.write(reinterpret_cast<char*>(&riffLength), sizeof(riffLength));;
	os.write(&waveTag[0], sizeof(waveTag));
	os.write(&fmtTag[0], sizeof(fmtTag));
	os.write((char*) &fmtLength, sizeof(fmtLength));
	os.write((char*) &audioFormat, sizeof(audioFormat));
	os.write((char*) &numChannels, sizeof(numChannels));
	os.write((char*) &sampleRate, sizeof(sampleRate));
	os.write((char*) &byteRate, sizeof(byteRate));
	os.write((char*) &blockAlign, sizeof(blockAlign));
	os.write((char*) &bitsPerSample, sizeof(bitsPerSample));
	os.write(&dataTag[0], sizeof(dataTag));
	os.write((char*) &dataLength, sizeof(dataLength));

	for(size_t k = 0; k < waveform.size(); ++k)
	{
		os.write(reinterpret_cast<char*>(const_cast<short*>(&(waveform.data()[k]))), sizeof(short));
	}
}

void Wave::read_wav(const string & filename)
{
	vector<short> read_waveform;

	// open file
	ifstream is(filename, ios::in | ios::binary);
	if (!is.is_open())
	{
		cerr << "Unable to open file " << filename << endl;
		return;
	}

	// read the header
	wav_hdr header;
	is.read((char*)&header, sizeof(wav_hdr));

	// verify parameters
	if(header.AudioFormat != 1)
	{
		cerr << "Only uncompressed PCM files are supported." << endl;
		return;
	}

	if(header.NumOfChan != 1)
	{
		cerr << "Only mono files are supported." << endl;
		return;
	}

	if(header.bitsPerSample != 16)
	{
		cerr << "Only 16-bit files are supported." << endl;
		return;
	}

	// read the data
	for(size_t k = 0; k < header.Subchunk2Size/sizeof(short); ++k)
	{
		char sample_raw[sizeof(short)];
		is.read(sample_raw, sizeof(short));
		short sample = *reinterpret_cast<short*>(sample_raw);
		read_waveform.push_back(sample);
	}

	waveform = read_waveform;
}
