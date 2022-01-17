#ifndef FUNC_H
#define FUNC_H

#include <string>

#include "wave.h"
#include "matrix.h"

Wave applyMatrixToWave(const Matrix& mat, const Wave& wave);

Wave addHiddenMsg(Wave& wave, const string &hiddenMsg, int cleMsg);

//Wave hideMessageLSB(const Wave& wave, const string& message);

#endif