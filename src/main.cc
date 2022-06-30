#include "mainwindow.h"

#include <QApplication>
#include "Poco/AutoPtr.h"
#include "Poco/Logger.h"
#include "Poco/SimpleFileChannel.h"
#include "Poco/FormattingChannel.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FileChannel.h"

using Poco::Logger;
using Poco::AutoPtr;
using Poco::SimpleFileChannel;
using Poco::FormattingChannel;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    AutoPtr<SimpleFileChannel> p = new SimpleFileChannel();
    p->setProperty("path", "simple.log");
    p->setProperty("flush", "false");
    p->setProperty("rotation", "1 M");

    AutoPtr<FormattingChannel> pfc = new FormattingChannel();
    pfc->setFormatter(new Poco::PatternFormatter("%L %Z %z %Y-%m-%d %H:%M:%S.%c %N[%P]:%s:%q:%t"));
    pfc->setChannel(p);

    Logger::root().setChannel(pfc);
    auto& l = Logger::get("tlogger");
    for (;;) {
        l.warning("wowwowwow");
        l.setLevel("none");
    }

    return a.exec();
}
