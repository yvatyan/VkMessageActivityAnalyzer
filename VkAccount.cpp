#include "VkAccount.h"
#include <QDebug>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QThreadPool>
#include "Utilities.h"
#include "ThreadTasks.h"

VkAccount::VkMessage VkAccount::format_message(const QString& rawMessage) {
    return VkMessage();
}
QString VkAccount::createMessagesSeqIncluded(int from, int to, QString delimiter) {
	QString seq("");
	int index = from;
	while(8) {
		seq += QString::number(index);
		if(to == index) {
			break;
		}
		seq += delimiter;
		index++;
	}
	return seq;
}
QString VkAccount::vkMethodUsersGet_getUserName(const QStringRef& jsonResponse) {
    Logger::instance() << Logger::DeveloperLevel << Logger::Empl << "Extracted json response:\n"
                       << jsonResponse.toString() << Logger::Endl;

    QJsonObject jsonObject = QJsonDocument::fromJson(jsonResponse.toUtf8()).object();
    QVariantMap jsonObjectMap = jsonObject.toVariantMap();
    QVariantList usersInfo = (*jsonObjectMap.find("response")).value<QVariantList>();   // assumed that response key's value is list
    QString userName;
    if(usersInfo.size() != 0) {
        QVariantMap userInfo(usersInfo[0].value<QVariantMap>());                        // assumed that list contains maps
        QString userFirstName = (*userInfo.find("first_name")).value<QString>();        // assumed that map values are QStrirngs
        QString userLastName = (*userInfo.find("last_name")).value<QString>();          // assumed that map values are QStrirngs
        userName = userFirstName + " " + userLastName;
    }
    return userName;
}
bool VkAccount::vkMethodMessagesGetById_validateMessageId(const QStringRef& jsonResponse) {
    QJsonObject jsonObject = QJsonDocument::fromJson(jsonResponse.toUtf8()).object();
    QVariantMap jsonObjectMap = jsonObject.toVariantMap();
    return static_cast<unsigned long long>(
                (*(*jsonObjectMap.find("response")).value<QVariantMap>().find("items")).value<QVariantList>().size()
           ) > 0;
}
QSharedPointer<VkAccount::VkMessagesBuffer> VkAccount::vkMethodMessagesGetById_parseRawMessages(const QStringRef& jsonResponse)  {
	
}

VkAccount::VkAccount()
    : generalConnection("api.vk.com", 443, 100)
{
    generalConnection.DoConnection();
}
int VkAccount::GetMessagesCount() {
    TcpSecureConnector localConnection("api.vk.com", 443, 100);
    localConnection.DoConnection();

    unsigned long long range = 1LL << 32;
    unsigned long long lastValidMessageId = 1LL << 32;
    bool messageValidStatus = false;
    while(range & ~1) {
        localConnection.MakeGETRequest(
                    "/method/messages.getById?access_token="+ access_token +
                    "&message_ids=" + QString::number(lastValidMessageId) +
                    "&v=5.60"
               );
        QString response(localConnection.ReadData());
        int fIndex = response.indexOf('{');
        int lIndex = response.lastIndexOf('}');
        messageValidStatus = vkMethodMessagesGetById_validateMessageId(QStringRef(&response, fIndex, lIndex - fIndex + 1));
        if(messageValidStatus) {
            lastValidMessageId += (range >>= 1);
        }
        else {
            lastValidMessageId -= (range >>= 1);
        }
    }
    if(!messageValidStatus) lastValidMessageId--;
    return lastValidMessageId;
}
QString VkAccount::GetUserName(const int id) {
    generalConnection.MakeGETRequest("/method/users.get?user_id=" + QString::number(id) + "&v=5.8");
    QString response(generalConnection.ReadData());
    Logger::instance() << Logger::DeveloperLevel << Logger::Empl << "\"User Name\" response:\n"
                       << response << Logger::Endl;
    int fIndex = response.indexOf('{');
    int lIndex = response.lastIndexOf('}');
    return  vkMethodUsersGet_getUserName(QStringRef(&response, fIndex, lIndex - fIndex + 1));
}
QString VkAccount::GetOwnerName() {
    generalConnection.MakeGETRequest("/method/users.get?access_token=" + access_token + "&v=5.8");
    QString response(generalConnection.ReadData());
    Logger::instance() << Logger::DeveloperLevel << Logger::Empl << "\"Owner Name\" response:\n"
                       << response << Logger::Endl;
    int fIndex = response.indexOf('{');
    int lIndex = response.lastIndexOf('}');
    return  vkMethodUsersGet_getUserName(QStringRef(&response, fIndex, lIndex - fIndex + 1));
}
QSharedPointer<VkAccount::VkMessagesBuffer> VkAccount::GetMessages(int fromId, int toId) {
    TcpSecureConnector localConnector("api.vk.com", 443, 100);
	QSharedPointer<VkMessagesBuffer> messagesLocalBuffer = QSharedPointer<VkMessagesBuffer>(new VkMessagesBuffer);
    int messagesIdsLimit = 90;
	int curIdBound = fromId;
	while(curIdBound <= toId) {
		QString messagesIdsSeq = createMessagesSeqIncluded(
                curIdBound,
                curIdBound + messagesIdsLimit > toId ? toId : curIdBound + messagesIdsLimit,
                ","
            );
		localConnector.MakeGETRequest("/method/messages.getById?message_ids=" + messagesIdsSeq + "&v=5.60");
		QString response(localConnection.ReadData());
		int fIndex = response.indexOf('{');
		int lIndex = response.lastIndexOf('}');
		/* add to local buffer*/ vkMethodMessagesGetById_parseRawMessages(QStringRef(&response, fIndex, lIndex - fIndex + 1));
		curIdBound += messagesIdsLimit;
	}
    return messagesLocalBuffer;
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

        ThreadTasks::NoArgsObjMethod<VkAccount, int>* getMessagesCountTask
                = new ThreadTasks::NoArgsObjMethod<VkAccount, int>(this, &VkAccount::GetMessagesCount);
        QThreadPool::globalInstance()->start(getMessagesCountTask);
    }
}
void VkAccount::SetAccessToken(const QString& accessToken) {
    access_token = accessToken;
}
