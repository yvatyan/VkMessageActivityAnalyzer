#ifndef UTILITIES_H
#define UTILITIES_H

#include <QSize>
#include <QPoint>
#include <QColor>
#include <QPlainTextEdit>

struct WindowParameters {
    WindowParameters() {
        windowSize = QSize(-1, -1);
        windowUpperCorner = QPoint(-1, -1);
    }

    WindowParameters(QSize size, QPoint point) {
        windowSize = size;
        windowUpperCorner = point;
    }

    QSize windowSize;
    QPoint windowUpperCorner;
};

class BorderSize {
    private:
        short outer_width;
        short inner_width;
    public:
        BorderSize() {
            outer_width = 0;
            inner_width = 0;
        }
        BorderSize(short inner_w, short outer_w) {
            outer_width = outer_w;
            inner_width = inner_w;
        }
        BorderSize(const BorderSize& copy) {
            outer_width = copy.outer_width;
            inner_width = copy.inner_width;
        }
        short OuterWidth() const {
            return outer_width;
        }
        short InnerWidth() const {
            return inner_width;
        }
        short TotalWidth() const {
            return inner_width + outer_width;
        }
};

class WindowInfo {
    private:
        WindowParameters winInfo;
        WindowParameters dropDownInfo;
        WindowParameters fullDropDownInfo;
        bool appIsMaximized;
        bool appIsInFullScreen;

        WindowInfo() : winInfo(){
            appIsMaximized = false;
            appIsInFullScreen = false;
        }
        WindowInfo(const WindowInfo&) {}
        WindowInfo& operator=(const WindowInfo&) {}
    public:
        static WindowInfo& GetInstance() {
            static WindowInfo instance;
            return instance;
        }
        void Set(WindowParameters winParams) {
            winInfo = winParams;
        }
        void SetUpperCorner(QPoint point) {
            winInfo.windowUpperCorner = point;
        }
        void SetSize(QSize size) {
            winInfo.windowSize = size;
        }
        WindowParameters Get() const {
            return winInfo;
        }
        void SaveDropDown() {
            dropDownInfo = winInfo;
        }
        void SaveFullDropDown() {
            fullDropDownInfo = winInfo;
        }
        WindowParameters GetDropDown() const {
            return dropDownInfo;
        }
        WindowParameters GetFullDropDown() const {
            return fullDropDownInfo;
        }
        bool IsAppMaximized() const {
            return appIsMaximized;
        }
        bool IsAppInFullScreen() const {
            return appIsInFullScreen;
        }
        void SetAppMaximizedState(bool state) {
            appIsMaximized = state;
        }
        void SetAppFullScreenState(bool state) {
            appIsInFullScreen = state;
        }
};

class Logger {
    private:
        QPlainTextEdit* transcript;
        QString buffer;
        QString prefix;
        QColor defTextColor;
        QColor curColor;
        bool developerLogging;
        bool noDeveloper;

        Logger() {
            transcript = nullptr;
            prefix = "";
            buffer = "";
            developerLogging = true;
            noDeveloper = false;
        }
        Logger(const Logger&){}
        Logger& operator=(const Logger&){}

        void removeLastLine() {
            if(nullptr != transcript) {
                transcript->setFocus();
                QTextCursor storeCursorPos = transcript->textCursor();
                transcript->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
                transcript->moveCursor(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
                transcript->moveCursor(QTextCursor::End, QTextCursor::KeepAnchor);
                transcript->textCursor().removeSelectedText();
                transcript->textCursor().deletePreviousChar();
                transcript->setTextCursor(storeCursorPos);
            }
        }
        void flush() {
            if(nullptr != transcript) {
                transcript->appendHtml(QString("<pre>" + prefix + buffer + "</pre>"));
                buffer.clear();
            }
            else {
                buffer += "<br>";
            }
        }

    public:
        enum LoggerFlags {
            RestoreColor,
            RemoveLast,
            DeveloperLevel,
            UserLevel,
            Endl,
            Empl,
            Empl2,
            Empl3
        };
        static Logger& instance() {
            static Logger logger;
            return logger;
        }

        void SetLoggerWindow(QPlainTextEdit* textEdit) {
            transcript = textEdit;
        }
        void SetLoggerPrefix(const QString& pr) {
            prefix = pr;
        }
        void SetLoggerDefaultTextColor(const QColor& col) {
            defTextColor = col;
            curColor = defTextColor;
        }

        void DisableDeveloperLevelLogging() {
            noDeveloper = true;
        }
        void EnableDeveloperLevelLogging() {
            noDeveloper = false;
        }
        Logger& operator<<(const QString& text) {
            if(nullptr != transcript) {
                if(developerLogging && noDeveloper) {
                }
                else {
                    buffer += QString("<font color=" + curColor.name() + ">" + text + "</font>");
                }
            }
            return *this;
        }
        Logger& operator<<(const char* text) {
            return *this << QString(text);
        }
        Logger& operator<<(const QPoint& point) {
            return *this << QString("(" + QString::number(point.x()) + "," + QString::number(point.y()) + ")");
        }
        Logger& operator<<(const QSize& size) {
            return *this << QString("(" + QString::number(size.width()) + "x" + QString::number(size.height()) + ")");
        }
        Logger& operator<<(const QColor& textColor) {
            curColor = textColor;
            return *this;
        }
        Logger& operator<<(LoggerFlags flag) {
            switch(flag) {
                case RestoreColor   :   curColor = defTextColor; break;
                case RemoveLast     :   removeLastLine(); break;
                case DeveloperLevel :   developerLogging = true; break;
                case UserLevel      :   developerLogging = false; break;
                case Endl           :   flush(); break;
                case Empl           :   buffer += "<br>"; flush(); break;
                case Empl2          :   buffer += "<br><br>"; flush(); break;
                case Empl3          :   buffer += "<br><br><br>"; flush(); break;
            }

            return *this;
        }
};

#endif // UTILITIES_H
