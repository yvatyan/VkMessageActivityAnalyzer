#include "VkAccount.h"
#include <QDebug>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include "Utilities.h"

VkAccount::VkMessage VkAccount::format_message(const QString& rawMessage) {
    return VkMessage();
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
int VkAccount::vkMethodMessagesGet_getCount(const QStringRef& jsonResponse) {
    Logger::instance() << Logger::DeveloperLevel << Logger::Empl << "Extracted json response:\n"
                       << jsonResponse.toString() << Logger::Endl;

    QJsonObject jsonObject = QJsonDocument::fromJson(jsonResponse.toUtf8()).object();
    QVariantMap jsonObjectMap = jsonObject.toVariantMap();
    return static_cast<int>( // assumed that count value has type double in QVariantMap
                (*(*jsonObjectMap.find("response")).value<QVariantMap>().find("count")).value<double>()
           );
}

VkAccount::VkAccount()
    : generalConnection("api.vk.com", 443, 100)
{
    generalConnection.DoConnection();
}
int VkAccount::GetMessagesCount() {
    generalConnection.MakeGETRequest("/method/messages.get?access_token=" + access_token + "&count=0&v=5.60");
    QString response(generalConnection.ReadData());
    Logger::instance() << Logger::DeveloperLevel << Logger::Empl << "\"Messages count\" response:\n"
                       << response << Logger::Endl;
    int fIndex = response.indexOf('{');
    int lIndex = response.lastIndexOf('}');
    return  vkMethodMessagesGet_getCount(QStringRef(&response, fIndex, lIndex - fIndex + 1));
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
    }
}
void VkAccount::SetAccessToken(const QString& accessToken) {
    access_token = accessToken;
}
