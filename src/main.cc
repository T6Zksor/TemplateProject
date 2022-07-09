#include "mainwindow.h"

#include <QApplication>
#include <QTimer>
#include <memory>

#include "Poco/ActiveDispatcher.h"
#include "Poco/ActiveMethod.h"
#include "Poco/FunctionDelegate.h"

struct AsyncParam {
    std::function<void()> request;
    std::function<void()> response;
};

class MainExecutor {
   public:
    void exec(AsyncParam param) {
        // any thread
        QTimer* timer = new QTimer();
        timer->moveToThread(qApp->thread());
        timer->setSingleShot(true);
        QObject::connect(timer, &QTimer::timeout, [=]() {
            // main thread
            Sleep(500);
            std::cout << "wow";
            timer->deleteLater();
        });
        QMetaObject::invokeMethod(timer, "start", Qt::QueuedConnection, Q_ARG(int, 0));

        // https://stackoverflow.com/questions/21646467/how-to-execute-a-functor-or-a-lambda-in-a-given-thread-in-qt-gcd-style
        QMetaObject::invokeMethod(qApp, []() {
            Sleep(500);
            std::cout << "wow";
        });
    }
};

class AsyncExecutor : public std::enable_shared_from_this<AsyncExecutor> {
   private:
    AsyncExecutor() : exec(this, &AsyncExecutor::execImpl) {}

   public:
    ~AsyncExecutor() {}
    static std::shared_ptr<AsyncExecutor> create() {
        return std::shared_ptr<AsyncExecutor>(new AsyncExecutor());
    }

    Poco::ActiveMethod<void, AsyncParam, AsyncExecutor> exec;

   private:
    void execImpl(const AsyncParam& p) {
        Sleep(500);
        std::cout << "wow";
        std::cout << m_val;

        MainExecutor e;
        e.exec({});
    }

    int m_val = 42;
};

void foo() {
    AsyncParam p;

    auto ae = AsyncExecutor::create();
    ae->exec(p);
}

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    foo();

    return a.exec();
}
