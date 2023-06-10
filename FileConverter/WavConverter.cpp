//
// Created by fcors on 6/10/2023.
//
#include "WavConverter.h"

#include <QProcess>

WavConverter::WavConverter() = default;

void WavConverter::convertFile(std::string_view filename) {
    QProcess ffmpeg;
}
