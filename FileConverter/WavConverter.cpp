//
// Created by fcors on 6/10/2023.
//
#include "WavConverter.h"


WavConverter::WavConverter(QObject *parent) : QObject(parent) {
    connect(this, &WavConverter::conversionFinished, this, &WavConverter::onConversionFinished);
}

WavConverter::~WavConverter() = default;

void WavConverter::convertFile(std::string_view filename) {
    QString inputFile(filename.data());

    QFileInfo inputInfo(inputFile);
    QString outputFile = m_conversionDir.path() + QDir::separator() + inputInfo.baseName() + ".wav";

    auto ffmpeg = std::make_unique<QProcess>();
    ffmpeg->setProgram("ffmpeg");
    ffmpeg->setArguments({"-i", inputFile, "-ac", "2", "-f", "wav", outputFile});
    connect(ffmpeg.get(), SIGNAL(finished), this, SIGNAL(conversionFinished));
    queueConversion(std::move(ffmpeg));
}

void WavConverter::queueConversion(std::unique_ptr<QProcess> process) {
    m_processes.emplace(std::move(process));
    if (m_processes.size() == 1) {
        const auto &ffmpeg = m_processes.front();
        ffmpeg->start();
        emit conversionStarted();
    }
}

void WavConverter::onConversionFinished() {
    m_processes.pop();
    if (!m_processes.empty()) {
        const auto &ffmpeg = m_processes.front();
        ffmpeg->start();
        emit conversionStarted();
    }
}
