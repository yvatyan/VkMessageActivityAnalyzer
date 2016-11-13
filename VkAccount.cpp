#include "VkAccount.h"
#include <QDebug>
#include <QUrlQuery>
#include "Utilities.h"

VkAccount::VkMessage VkAccount::format_message(const QString& rawMessage) {
    return VkMessage();
}
VkAccount::VkAccount()
    : generalConnection("api.vk.com", 443, 100)
{
    generalConnection.DoConnection();
}
QString VkAccount::GetMessagesCount() {
    return "";
}
QString VkAccount::GetUserName() {
    generalConnection.MakeGETRequest("/method/users.get?access_token=" + access_token + "&v=5.8");
    return QString();
}
QSharedPointer<VkAccount::VkMessagesBuffer> VkAccount::GetMessages(int fromId, int toId) {
    return QSharedPointer<VkMessagesBuffer>(new VkMessagesBuffer);
}
void VkAccount::RetrieveAccessToken(QUrl url) {
    QUrlQuery query(url.url().section('#', -1));
    if (query.hasQueryItem("access_token")) {
        Logger::instance() << Logger::UserLevel << "Retrieving access token ... "
                           << QColor(Qt::green) << " Done"
                           << Logger::RestoreColor << Logger::Endl;
        Logger::instance() << Logger::DeveloperLevel << "Access token: "
                           << QColor(Qt::blue) << query.queryItemValue("access_token")
                           << Logger::RestoreColor << Logger::Endl;
        SetAccessToken(query.queryItemValue("access_token"));
        GetUserName();
    }
}
void VkAccount::SetAccessToken(const QString& accessToken) {
    access_token = accessToken;
}
