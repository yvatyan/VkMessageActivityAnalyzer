#ifndef TCPCONNECTOR_H
#define TCPCONNECTOR_H

#include <QSslSocket>

class TcpConnector : public QObject {
    Q_OBJECT
    private:
        QString host;
        unsigned short port;
        QSslSocket socket;
        bool keepAlive;
        int keepAliveLimit;
        int keepAliveCounter;
        const unsigned int waitTillConnectionMsecs = 10000;

        TcpConnector(){}
        TcpConnector(const TcpConnector& copy){}
        TcpConnector& operator=(const TcpConnector& copy){}

        QString connectionState() const;
        QString connectionError(QAbstractSocket::SocketError error) const;
        void reconnect();
    public:
        TcpConnector(const QString& host, unsigned short  port);
        TcpConnector(const QString& host, unsigned short port, int keepAliveLimit);

        void DoConnection();
        void CloseConnection();

        void MakeGETRequest(const QString& query);
        QByteArray ReadData();
public slots:
        void OnSslErrors(const QList<QSslError> &errors);
        void OnError(const QAbstractSocket::SocketError error);
        void OnConnectionClosed();
};

#endif // TCPCONNECTOR_H
