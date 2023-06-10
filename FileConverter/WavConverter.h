//
// Created by fcors on 6/10/2023.
//
#pragma once

#include <QTemporaryDir>

class WavConverter {
public:
    WavConverter();

    void convertFile(std::string_view filename);

private:
    QTemporaryDir m_conversionDir;
};
