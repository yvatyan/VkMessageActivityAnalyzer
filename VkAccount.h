#ifndef VKACCOUNT_H
#define VKACCOUNT_H

#include <vector>

#include <QString>
#include <QSharedPointer>
#include <QUrl>

#include "TcpSecureConnector.h"

class VkAccount : public QObject {
Q_OBJECT
    private:
        class VkMessage;

        QString access_token;
        TcpSecureConnector generalConnection;

        VkMessage format_message(const QString& rawMessage);
        QString vkMethodUsersGet_getUserName(const QStringRef& jsonResponse);
        int     vkMethodMessagesGet_getCount(const QStringRef& jsonResponse);
    public:
        class VkMessage {

        };
        typedef std::vector<QSharedPointer<VkMessage> > VkMessagesBuffer;

        VkAccount();

        QSharedPointer<VkMessagesBuffer> GetMessages(int fromId, int toId);
        int GetMessagesCount();
        QString GetUserName(const int id);
        QString GetOwnerName();
        void SetAccessToken(const QString& accessToken);
    public slots:
        void RetrieveAccessToken(QUrl url);
    signals:
        void logged();
};

#endif // VKACCOUNT_H
