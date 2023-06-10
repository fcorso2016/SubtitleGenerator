//
// Created by fcors on 6/10/2023.
//
#pragma once

#include <QTemporaryDir>
#include <QProcess>
#include <queue>

class WavConverter : public QObject {
    Q_OBJECT
public:
    explicit WavConverter(QObject *parent);
    ~WavConverter() override;

    void convertFile(std::string_view filename);

signals:
    void conversionStarted();
    void conversionFinished(int exitCode, QProcess::ExitStatus exitStatus);

private slots:
    void onConversionFinished();

private:
    void queueConversion(std::unique_ptr<QProcess> process);

    QTemporaryDir m_conversionDir;
    std::queue<std::unique_ptr<QProcess>> m_processes;
};
