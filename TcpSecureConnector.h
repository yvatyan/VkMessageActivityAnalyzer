#ifndef TcpSecureConnector_H
#define TcpSecureConnector_H

#include <QSslSocket>

class TcpSecureConnector : public QObject {
    Q_OBJECT
    private:
        QString host;
        unsigned short port;
        QSslSocket socket;
        bool keepAlive;
        int keepAliveLimit;
        int keepAliveCounter;
        const unsigned int waitTillConnectionMsecs = 10000;

        TcpSecureConnector(){}
        TcpSecureConnector(const TcpSecureConnector& copy){}
        TcpSecureConnector& operator=(const TcpSecureConnector& copy){}

        QString connectionState() const;
        QString connectionError(QAbstractSocket::SocketError error) const;
        void reconnect();
    public:
        TcpSecureConnector(const QString& host, unsigned short  port);
        TcpSecureConnector(const QString& host, unsigned short port, int keepAliveLimit);

        void DoConnection();
        void CloseConnection();

        void MakeGETRequest(const QString& query);
        QByteArray ReadData();
public slots:
        void OnSslErrors(const QList<QSslError> &errors);
        void OnError(const QAbstractSocket::SocketError error);
        void OnConnectionClosed();
};

#endif // TcpSecureConnector_H
