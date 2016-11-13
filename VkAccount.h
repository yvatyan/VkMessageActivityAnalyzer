#ifndef VKACCOUNT_H
#define VKACCOUNT_H

#include <vector>

#include <QString>
#include <QSharedPointer>
#include <QUrl>

#include "TcpConnector.h"

class VkAccount : public QObject {
Q_OBJECT
    private:
        class VkMessage;

        QString access_token;
        TcpConnector generalConnection;

        VkMessage format_message(const QString& rawMessage);
    public:
        class VkMessage {

        };
        typedef std::vector<QSharedPointer<VkMessage> > VkMessagesBuffer;

        VkAccount();

        QSharedPointer<VkMessagesBuffer> GetMessages(int fromId, int toId);
        QString GetMessagesCount();
        QString GetUserName();
        void SetAccessToken(const QString& accessToken);
    public slots:
        void RetrieveAccessToken(QUrl url);
    signals:
        void logged();
};

#endif // VKACCOUNT_H
