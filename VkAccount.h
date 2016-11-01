#ifndef VKACCOUNT_H
#define VKACCOUNT_H

#include <vector>

#include <QString>
#include <QSharedPointer>
#include <QUrl>

class VkAccount : public QObject {
Q_OBJECT
    private:
        class VkMessage;

        QString access_token;

        VkMessage format_message(const QString& rawMessage);
    public:
        class VkMessage {

        };
        typedef std::vector<QSharedPointer<VkMessage> > VkMessagesBuffer;

        VkAccount();

        QSharedPointer<VkMessagesBuffer> GetMessages(int fromId, int toId);
        void SetAccessToken(const QString& accessToken);
    public slots:
        void RetrieveAccessToken(QUrl url);
    signals:
        void logged();
};

#endif // VKACCOUNT_H
