#ifndef VKMESSAGEANALYZERCORE_H
#define VKMESSAGEANALYZERCORE_H

#include "VkAccount.h"

class VkMessageAnalyzer;

class VkMessageAnalyzerCore : public QObject {
Q_OBJECT
    private:
        VkAccount user;
        VkMessageAnalyzer* mainApp;
        short threads;
        //DbGenerator database;

        void makeConnections();
        void log_in();
        void get_messages(short  threads = 1);
        void do_analysis();
        void show_results();
    public:
        VkMessageAnalyzerCore(VkMessageAnalyzer* main_class, short threads_count = 1);
    public slots:
        void LogInVk();
        void EnterToken();
        void LoadDatabase();
        void InformationIsCollected();
        void AnalysisIsDone();
};

#include "VkMessageAnalyzer.h"

#endif // VKMESSAGEANALYZERCORE_H
