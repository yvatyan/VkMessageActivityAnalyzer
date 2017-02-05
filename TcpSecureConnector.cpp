#include "TcpSecureConnector.h"
#include "Utilities.h"

#include <QThread>

QString TcpSecureConnector::connectionState() const {
    switch(socket.state()) {
        case QAbstractSocket::UnconnectedState  :  return QString("The socket is not connected.");
        case QAbstractSocket::HostLookupState   :  return QString("The socket is performing a host name lookup.");
        case QAbstractSocket::ConnectingState   :  return QString("The socket has started establishing a connection.");
        case QAbstractSocket::ConnectedState    :  return QString("A connection is established.");
        case QAbstractSocket::BoundState        :  return QString("The socket is bound to an address and port.");
        case QAbstractSocket::ClosingState      :  return QString("The socket is about to close (data may still be waiting to be written).");
        case QAbstractSocket::ListeningState    :  return QString("Listening");
        default                                 :  return QString("Undefined state.");
    };
}
QString TcpSecureConnector::connectionError(QAbstractSocket::SocketError error) const {
    switch(error) {
        case QAbstractSocket::ConnectionRefusedError            : return QString("The connection was refused by the peer (or timed out).");
        case QAbstractSocket::RemoteHostClosedError             : return QString("The remote host closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent.");
        case QAbstractSocket::HostNotFoundError                 : return QString("The host address was not found.");
        case QAbstractSocket::SocketAccessError                 : return QString("The socket operation failed because the application lacked the required privileges.");
        case QAbstractSocket::SocketResourceError               : return QString("The local system ran out of resources (e.g., too many sockets).");
        case QAbstractSocket::SocketTimeoutError                : return QString("The socket operation timed out.");
        case QAbstractSocket::DatagramTooLargeError             : return QString("The datagram was larger than the operating system's limit (which can be as low as 8192 bytes).");
        case QAbstractSocket::NetworkError                      : return QString("An error occurred with the network (e.g., the network cable was accidentally plugged out).");
        case QAbstractSocket::AddressInUseError                 : return QString("The address specified to QAbstractSocket::bind() is already in use and was set to be exclusive.");
        case QAbstractSocket::SocketAddressNotAvailableError    : return QString("The address specified to QAbstractSocket::bind() does not belong to the host.");
        case QAbstractSocket::UnsupportedSocketOperationError   : return QString("The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support).");
        case QAbstractSocket::ProxyAuthenticationRequiredError  : return QString("The socket is using a proxy, and the proxy requires authentication.");
        case QAbstractSocket::SslHandshakeFailedError           : return QString("The SSL/TLS handshake failed, so the connection was closed (only used in QSslSocket)");
        case QAbstractSocket::UnfinishedSocketOperationError    : return QString("Used by QAbstractSocketEngine only, The last operation attempted has not finished yet (still in progress in the background).");
        case QAbstractSocket::ProxyConnectionRefusedError       : return QString("Could not contact the proxy server because the connection to that server was denied");
        case QAbstractSocket::ProxyConnectionClosedError        : return QString("The connection to the proxy server was closed unexpectedly (before the connection to the final peer was established)");
        case QAbstractSocket::ProxyConnectionTimeoutError       : return QString("The connection to the proxy server timed out or the proxy server stopped responding in the authentication phase.");
        case QAbstractSocket::ProxyNotFoundError                : return QString("The proxy address set with setProxy() (or the application proxy) was not found.");
        case QAbstractSocket::ProxyProtocolError                : return QString("The connection negotiation with the proxy server failed, because the response from the proxy server could not be understood.");
        case QAbstractSocket::OperationError                    : return QString("An operation was attempted while the socket was in a state that did not permit it.");
        case QAbstractSocket::SslInternalError                  : return QString("The SSL library being used reported an internal error. This is probably the result of a bad installation or misconfiguration of the library.");
        case QAbstractSocket::SslInvalidUserDataError           : return QString("Invalid data (certificate, key, cypher, etc.) was provided and its use resulted in an error in the SSL library.");
        case QAbstractSocket::TemporaryError                    : return QString("A temporary error occurred (e.g., operation would block and socket is non-blocking).");
        case QAbstractSocket::UnknownSocketError                : return QString("An unidentified error occurred.");
    }
}
void TcpSecureConnector::reconnect() {
    Logger::instance() << Logger::DeveloperLevel << "Reconnecting ...." << Logger::Endl;
    CloseConnection();
    DoConnection();
}
TcpSecureConnector::TcpSecureConnector(const QString& host, unsigned short  port)
                            : host(host)
                            , port(port)
                            , keepAlive(false)
{
}
TcpSecureConnector::TcpSecureConnector(const QString& host, unsigned short port, int keepAliveLimit)
                            : host(host)
                            , port(port)
                            , keepAlive(true)
                            , keepAliveLimit(keepAliveLimit)
{
//    typedef void (QSslSocket:: *sslErrorsSignal)(const QList<QSslError> &);
//    QObject::connect(&socket, static_cast<sslErrorsSignal>(&QSslSocket::sslErrors),
//            this, &TcpSecureConnector::OnSslErrors);
    QObject::connect(&socket, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(OnSslErrors(QList<QSslError>)));
    QObject::connect(&socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnError(QAbstractSocket::SocketError)));
}
void TcpSecureConnector::DoConnection() {
    socket.connectToHost(host, port);
    Logger::instance() << Logger::DeveloperLevel << "Connecting to " << host
                       << " on port " << QString::number(port) << "." << Logger::Endl;
    socket.waitForConnected(waitTillConnectionMsecs);
    if(QAbstractSocket::ConnectedState == socket.state()) {
        Logger::instance() << Logger::DeveloperLevel << "Connection "
                           << QColor(Qt::green) << "Done."
                           << Logger::RestoreColor << Logger::Endl;
        socket.startClientEncryption();
        socket.waitForEncrypted();
        if (socket.isEncrypted()) {
            Logger::instance() << Logger::DeveloperLevel << "Connection "
                               << QColor(Qt::blue) << "Encrypted."
                               << Logger::RestoreColor << Logger::Endl;
            if(keepAlive) {
                keepAliveCounter = keepAliveLimit;
            }
        }
        else {
            Logger::instance() << Logger::DeveloperLevel << "Connection "
                               << QColor(Qt::red) << "Failed to Encrypt."
                               << Logger::RestoreColor << Logger::Endl;
        }
        Logger::instance() << Logger::DeveloperLevel << Logger::Empl2 << "Support SSL:  " << QString::number(QSslSocket::supportsSsl())
                           << "\nLib Version Number: " << QString::number(QSslSocket::sslLibraryVersionNumber())
                           << "\nLib Version String: " << QSslSocket::sslLibraryVersionString()
                           << "\nLib Build Version Number: " << QString::number(QSslSocket::sslLibraryBuildVersionNumber())
                           << "\nLib Build Version String: " << QSslSocket::sslLibraryBuildVersionString() << Logger::Empl2;
    }
    else {
        Logger::instance() << Logger::DeveloperLevel << "Connection "
                           << QColor(Qt::red) << "Fail."
                           << Logger::RestoreColor << Logger::Endl;
    }
}
void TcpSecureConnector::CloseConnection() {
    socket.close();
}
void TcpSecureConnector::MakeGETRequest(const QString& query) {

    QThread::msleep(300);
    QString connectionType("closed");
    if(keepAlive) {
        connectionType = "keep-alive";
        keepAliveCounter --;
        if(0 == keepAliveCounter || QAbstractSocket::UnconnectedState == socket.state()) {
            reconnect();
        }
    }
    QString request = "GET " + query + " HTTP/1.1\r\n"\
                      "Host: api.vk.com\r\n"\
                      "Accept: */*\r\n"\
                      "Connection: " + connectionType + "\r\n\r\n";
    /*Logger::instance() << Logger::DeveloperLevel << Logger::Empl << "Doing GET request:\n" << request << Logger::Endl
                       << "Left to reconnect " << QString::number(keepAliveCounter) << Logger::Endl;*/
    socket.write(request.toStdString().c_str());
}
QByteArray TcpSecureConnector::ReadData() {
   // Logger::instance() << Logger::DeveloperLevel << "Reading data from socket ...." << Logger::Empl;
    socket.waitForReadyRead();
    QByteArray data = socket.read(socket.bytesAvailable());
/*    Logger::instance() << Logger::DeveloperLevel << "Data:\n"
                       << data.toStdString().c_str() << Logger::Empl2;
    Logger::instance() << Logger::DeveloperLevel << QString::number(data.size()) << " bytes have been read." << Logger::Endl;*/
    return data;
}

void TcpSecureConnector::OnSslErrors(const QList<QSslError> &errors) {

    Logger::instance() << Logger::DeveloperLevel << "Ssl Error: "
                       << QColor(Qt::red);
    for(int i = 0; i < errors.size(); ++i) {
        if(0 != i) {
            Logger::instance() << QString(' ', QString("Ssl Error: ").length());
        }
        Logger::instance() << errors[i].errorString();
        if(errors.size() - 1 != i) {
            Logger::instance() << "\n";
        }
    }
    Logger::instance() << Logger::RestoreColor << Logger::Endl;
}
void TcpSecureConnector::OnError(QAbstractSocket::SocketError error) {
    Logger::instance() << Logger::DeveloperLevel
                       << "Socket Error: "
                       << QColor(Qt::red) << connectionError(error)
                       << Logger::RestoreColor << Logger::Endl;
}
void TcpSecureConnector::OnConnectionClosed() {
    Logger::instance() << Logger::DeveloperLevel
                       << "Connection closed." << Logger::Endl;
}
