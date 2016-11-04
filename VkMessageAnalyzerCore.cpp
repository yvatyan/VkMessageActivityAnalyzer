#include "VkMessageAnalyzerCore.h"
#include "VkSettings.h"
#include <QDebug>

void VkMessageAnalyzerCore::makeConnections() {
    QObject::connect(mainApp->UI_Items()->LogInButton(), SIGNAL(clicked()), SLOT(LogInVk()));
    QObject::connect(mainApp->UI_Items()->TokenButton(), SIGNAL(clicked()), SLOT(EnterToken()));
    QObject::connect(mainApp->UI_Items()->DatabaseButton(), SIGNAL(clicked()), SLOT(LoadDatabase()));
    QObject::connect(mainApp->UI_Items()->Browser(), SIGNAL(urlChanged(QUrl)), &user, SLOT(RetrieveAccessToken(QUrl)));
    QObject::connect(&user, SIGNAL(logged()), SLOT(EnterToken()));
}

void VkMessageAnalyzerCore::log_in() {
    mainApp->SwitchTab(0);
    mainApp->FollowUrl(Vk::OAuthUrl());
}

void VkMessageAnalyzerCore::get_messages(short  threads) {

}

void VkMessageAnalyzerCore::do_analysis() {

}

void VkMessageAnalyzerCore::show_results() {

}

VkMessageAnalyzerCore::VkMessageAnalyzerCore(VkMessageAnalyzer *main_class, short threads_count) {
    mainApp = main_class;
    threads = threads_count;
    makeConnections();
}

void VkMessageAnalyzerCore::LogInVk() {
    log_in();
    Logger::instance() << Logger::UserLevel
                       << "Retrieving access token ... " << Logger::Endl;
}

void VkMessageAnalyzerCore::EnterToken() {

}

void VkMessageAnalyzerCore::LoadDatabase() {

}

void VkMessageAnalyzerCore::InformationIsCollected() {

}

void VkMessageAnalyzerCore::AnalysisIsDone() {

}
