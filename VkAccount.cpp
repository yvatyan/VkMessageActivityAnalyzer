#include "VkAccount.h"
#include <QDebug>
#include <QUrlQuery>

VkAccount::VkMessage VkAccount::format_message(const QString& rawMessage) {
    return VkMessage();
}
VkAccount::VkAccount() {
}
QSharedPointer<VkAccount::VkMessagesBuffer> VkAccount::GetMessages(int fromId, int toId) {
    return QSharedPointer<VkMessagesBuffer>(new VkMessagesBuffer);
}
void VkAccount::RetrieveAccessToken(QUrl url) {
    QUrlQuery query(url.url().section('#', -1));
    qDebug() << query.toString() << " ---------- " << url.toString();
    if (query.hasQueryItem("access_token")) {
        qDebug() << query.queryItemValue("access_token");
    }
}
void VkAccount::SetAccessToken(const QString& accessToken) {
    access_token = accessToken;
}
