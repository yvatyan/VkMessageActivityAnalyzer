#ifndef VKSETTINGS_H
#define VKSETTINGS_H

#include <QUrl>
#include <QUrlQuery>

class Vk {
    private:
        static const QString auth_uri;
        static const QString redirect_uri;
        static const QString client_id;
        static const QString display;
        static const QString respons_type;
        static const QString scope;
        static const QString version;
    public:
        static const QUrlQuery OAuthUrlQuery() {
            QUrlQuery query;
            query.addQueryItem("redirect_uri", redirect_uri);
            query.addQueryItem("client_id", client_id);
            query.addQueryItem("display", display);
            query.addQueryItem("response_type", respons_type);
            query.addQueryItem("scope", scope);
            query.addQueryItem("v", version);

            return query;
        }
        static const QUrl OAuthUrl() {
            return QUrl(auth_uri + "/?" + OAuthUrlQuery().toString());
        }
};

const QString Vk::auth_uri = QString("https://oauth.vk.com/authorize");
const QString Vk::redirect_uri = QString("https://oauth.vk.com/blank.html");
const QString Vk::client_id = QString("5619378");
const QString Vk::display = QString("mobile");
const QString Vk::respons_type = QString("token");
const QString Vk::scope = QString("offline,messages");
const QString Vk::version = QString("5.59");

#endif // VKSETTINGS_H
